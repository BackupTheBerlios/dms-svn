/***************************************************************************
*   Copyright (C) 2007-2008 by Alexander Saal                             *
*   alex.saal@gmx.de                                                      *
*                                                                         *
*   File: ${filename}.${extension}                                        *
*   Desc: ${description}                                                  *
*                                                                         *
*   This file is part of DMS - Documnet Management System                 *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/

#include <dmsworksheet.h>

#include <libdms.h>
#include <dmsmailaction.h>
#include <dmsdocument.h>

#include <QtCore>
#include <QtGui>

DMSWorkSheet *dmsworksheet = NULL;
DMSWorkSheet::DMSWorkSheet( LibDMS *dms, QWorkspace *ws, QWidget *parent ) : QWidget( parent )
{
	setupUi( this );
	dmsworksheet = this;

	_dms = dms;
	_ws = ws;

	acSendMail = NULL;

	connect( treeWidgetWorkSheet, SIGNAL( customContextMenuRequested( QPoint ) ), this, SLOT( treeWidgetWorkSheetMenu( QPoint ) ) );
	connect( treeWidgetWorkSheet, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetWorkSheetItem( QTreeWidgetItem *, int ) ) );

	setAcceptDrops( true );
	treeWidgetWorkSheet->setAcceptDrops( true );

	createMenuAction();

	_dms->clearErrorMessage();
	
	loadDocuments();
}

DMSWorkSheet::~DMSWorkSheet()
{
	dmsworksheet = NULL;
}


void DMSWorkSheet::dragEnterEvent( QDragEnterEvent *event )
{
	event->acceptProposedAction();
}

void DMSWorkSheet::dragMoveEvent( QDragMoveEvent *event )
{
	event->acceptProposedAction();
}

void DMSWorkSheet::dropEvent( QDropEvent *event )
{
	QString filePath = event->mimeData()->text();
	QByteArray fileName = event->mimeData()->data( "text/uri-list" );

	if ( filePath.isNull() || filePath.isEmpty() )
		filePath = QString( fileName.data() ).trimmed();

#ifdef Q_OS_WIN32
	if ( filePath.startsWith( "file:///" ) )
		filePath = filePath.replace( "file:///", "" ).trimmed();

#else
	if ( filePath.startsWith( "file://" ) )
		filePath = filePath.replace( "file://", "" ).trimmed();

#endif

	QFileInfo fi( filePath.trimmed() );

	if ( fi.isDir() )
	{
		QMessageBox::critical( this, tr( "DMS - Worksheet" ), tr( "Directory is not supported by drag & drop action." ) );
		return;
	}

	if ( !dmsdocument )
	{
		dmsdocument = new DMSDocument( _dms, _ws );
		dmsdocument->lineEditDocumentName->setText( fi.fileName().split( "." ).value( 0 ) );
		dmsdocument->lineEditDocumentPath->setText( fi.filePath() );
		_ws->addWindow( dmsdocument );
		dmsdocument->show();
	}
	else
	{
		dmsdocument->lineEditDocumentName->setText( fi.fileName().split( "." ).value( 0 ) );
		dmsdocument->lineEditDocumentPath->setText( fi.filePath() );
		dmsdocument->setFocus( Qt::ActiveWindowFocusReason );
	}
}

void DMSWorkSheet::mousePressEvent( QMouseEvent *event )
{
	event->ignore();
}

void DMSWorkSheet::closeEvent( QCloseEvent *e )
{

	QList<QWidget *> it( _ws->findChildren<QWidget *>( this->objectName() ) );

	for ( int a = 0; a < it.size(); ++a )
	{
		QWidget *widget = it.value ( a );
		qDebug() << widget->pos();
	}

	int _x = this->x();

	int _y = this->y();
	int _width = this->width();
	int _height = this->height();

	_dms->insertApplicationSettings( objectName(), "Geometry", "Position", QString( "%1" ).arg( _x ) + ";" + QString( "%1" ).arg( _y ) );

	dmsworksheet = NULL;
	e->accept();
}

void DMSWorkSheet::loadDocuments()
{
	treeWidgetWorkSheet->clear();

	documents = _dms->geDocuments( _dms->getUserId( _dms->loggedUser ) );

	QMap< QString, QString>::const_iterator docIt = documents.begin();

	while ( docIt != documents.end() )
	{
		qApp->processEvents();

		QString uname = docIt.value().split( "#" ).value( 0 );
		QString gname = docIt.value().split( "#" ).value( 1 );
		QString docname = docIt.value().split( "#" ).value( 2 );
		QString docpath = docIt.value().split( "#" ).value( 3 );
		QString updated = docIt.value().split( "#" ).value( 4 );
		QString checkedout = docIt.value().split( "#" ).value( 5 );

		docItem = new QTreeWidgetItem( getGroupItem( gname ) );
		docItem->setText( 0, docname );
		docItem->setText( 1, docpath );
		docItem->setText( 2, updated );

		if ( checkedout == "0" )
			docItem->setIcon( 3, QIcon( QString::fromUtf8( ":/picture/16/images/16x16/folder-closed_16.png" ) ) );
		else if ( checkedout == "1" )
			docItem->setIcon( 3, QIcon( QString::fromUtf8( ":/picture/16/images/16x16/folder-open_16.png" ) ) );

		++docIt;
	}
}

void DMSWorkSheet::newDocument()
{
	_dms->showDmsDocument( _ws );
}

void DMSWorkSheet::openDocument()
{
	docItem = treeWidgetWorkSheet->currentItem();

	if ( docItem == NULL )
	{
		showErrorMsg( tr( "No document was selected." ) );
		return;
	}

	QString userid = _dms->getUserId( _dms->getUserId( _dms->loggedUser ) );

	QString docid = _dms->getDocId( userid, docItem->text( 0 ) );
	_dms->openDocument( docid );
}

void DMSWorkSheet::deleteDocument()
{
	docItem = treeWidgetWorkSheet->currentItem();

	if ( docItem == NULL )
	{
		showErrorMsg( tr( "No document was selected." ) );
		return;
	}

	QString userid = _dms->getUserId( _dms->getUserId( _dms->loggedUser ) );

	QString docid = _dms->getDocId( userid, docItem->text( 0 ) );

	QFile docfile ( docItem->text( 1 ) );

	QString question = QString( "" );
	question += tr( "Would you like delete the document from database and/or harddisk?\n" );
	question += tr( "If you click 'Document from database' only the link from database and\n" );
	question += tr( "the document from list will removed." );

	switch ( QMessageBox::information ( this, tr( "DMS" ), question, tr( "Document from database" ), tr( "Document from harddisk" ), tr( "Cancel" ), 0, 2 ) )
	{

		case 0:               // Link, List && Harddisk

			if ( docfile.exists() )
				docfile.remove();

			_dms->deleteDocument( docid, userid );

			delete docItem;

			break;

		case 1:               // Link, List && Document from harddisk
			_dms->deleteDocument( docid, userid );

			delete docItem;

			break;

		case 2:               // Cancel clicked or Escape pressed
			return;
	}
}

void DMSWorkSheet::printDocument()
{
	docItem = treeWidgetWorkSheet->currentItem();

	if ( docItem == NULL )
	{
		showErrorMsg( tr( "No document was selected." ) );
		return;
	}

#ifdef Q_OS_WIN32
	QMessageBox::information( this, tr( "DMS - Worksheet" ), tr( "Print document is not implemented yet!" ) );

#else
	QMessageBox::information( this, tr( "DMS - Worksheet" ), tr( "Print document is not implemented yet!" ) );

#endif
}

void DMSWorkSheet::createMenuAction()
{
	mnuMail = new QMenu( tr( "Send document via eMail" ), this );
	mnuMail->setIcon( QIcon ( QString::fromUtf8 ( ":/picture/16/images/16x16/mail_16.png" ) ) );

	acNewDoc = new QAction( tr( "New document" ), this );
	acNewDoc->setIcon( QIcon ( QString::fromUtf8 ( ":/picture/16/images/16x16/documents_16.png" ) ) );
	connect( acNewDoc, SIGNAL( triggered() ), this, SLOT( newDocument() ) );

	acOpenDoc = new QAction( tr( "Open document" ), this );
	acOpenDoc->setIcon( QIcon ( QString::fromUtf8 ( ":/picture/16/images/16x16/folder-open_16.png" ) ) );
	connect( acOpenDoc, SIGNAL( triggered() ), this, SLOT( openDocument() ) );

	acDeleteDoc = new QAction( tr( "Delete document" ), this );
	acDeleteDoc->setIcon( QIcon ( QString::fromUtf8 ( ":/picture/16/images/16x16/trash_16.png" ) ) );
	connect( acDeleteDoc, SIGNAL( triggered() ), this, SLOT( deleteDocument() ) );

	acPrintDoc = new QAction( tr( "Print document" ), this );
	acPrintDoc->setIcon( QIcon ( QString::fromUtf8 ( ":/picture/16/images/16x16/print_16.png" ) ) );
	connect( acPrintDoc, SIGNAL( triggered() ), this, SLOT( printDocument() ) );
}

void DMSWorkSheet::sendMail()
{
	DMSMailAction *mail = qobject_cast<DMSMailAction*>( sender() );
	_dms->sendMail( mail->getMailAddress(), mail->getSubject(), mail->getAttachment(), mail->getMessage() );
}

void DMSWorkSheet::treeWidgetWorkSheetItem( QTreeWidgetItem *item, int column )
{
}

void DMSWorkSheet::treeWidgetWorkSheetMenu( QPoint point )
{
	docItem = treeWidgetWorkSheet->currentItem();

	QMenu menu( this );
	QMouseEvent *mevent = new QMouseEvent( QEvent::MouseButtonPress, point, Qt::RightButton, Qt::RightButton, Qt::NoModifier );

	if ( acSendMail != NULL )
		delete acSendMail;

	menu.clear();

	mnuMail->clear();

	if ( docItem == NULL )
	{
		menu.addAction( acNewDoc );
	}
	else
	{
		menu.addAction( acNewDoc );

		QMap< QString, QString> appFiles = _dms->getApplicationSettings( "UiPreferenceBase", "File associations" );

		if ( appFiles.size() >= 1 )
			acOpenDoc->setEnabled( true );
		else
			acOpenDoc->setEnabled( false );

		menu.addAction( acOpenDoc );

		QMap<QString, QString> mails = _dms->getApplicationSettings( "UiPreferenceBase", "Mails" );

		if ( mails.size() >= 1 )
		{
			QMap<QString, QString>::const_iterator mailIt = mails.begin();

			while ( mailIt != mails.end() )
			{
				qApp->processEvents();

				if ( mailIt.value().isNull() || mailIt.value().isEmpty() )
					acSendMail = new DMSMailAction( mailIt.key(), this );
				else
					acSendMail = new DMSMailAction( mailIt.value(), this );

				acSendMail->setMailAdress( mailIt.key() );

				acSendMail->setSubject( docItem->text( 0 ) );

				acSendMail->setMessage( mailIt.value() );

				acSendMail->setAttachment( docItem->text( 1 ) );

				acSendMail->setIcon( QIcon ( QString::fromUtf8 ( ":/picture/16/images/16x16/mail_letter_16.png" ) ) );

				connect( acSendMail, SIGNAL( triggered() ), this, SLOT( sendMail() ) );

				mnuMail->addAction( acSendMail );

				++mailIt;
			}

			menu.addMenu( mnuMail );
		}

		menu.addAction( acDeleteDoc );

		menu.addAction( acPrintDoc );
	}

	menu.exec( mevent->globalPos() );
}

void DMSWorkSheet::showErrorMsg( const QString &error )
{
	QMessageBox::critical( this, tr( "DMS - Worksheet" ), error );
}

QTreeWidgetItem *DMSWorkSheet::getGroupItem( const QString &groupname )
{
	for ( int a = 0; a < treeWidgetWorkSheet->topLevelItemCount(); a++ )
	{
		qApp->processEvents();

		QTreeWidgetItem *_item = treeWidgetWorkSheet->topLevelItem( a );

		if ( _item->text( 0 ) == groupname )
			return _item;
	}

	groupItem = new QTreeWidgetItem( treeWidgetWorkSheet );

	groupItem->setText( 0, groupname );

	QFont font;
	font.setBold( true );
	font.setStyleHint( QFont::System );

	groupItem->setFont( 0, font );
	groupItem->setBackgroundColor( 0, QColor( Qt::lightGray ) );
	groupItem->setBackgroundColor( 1, QColor( Qt::lightGray ) );
	groupItem->setBackgroundColor( 2, QColor( Qt::lightGray ) );
	groupItem->setBackgroundColor( 3, QColor( Qt::lightGray ) );

	return groupItem;
}

void DMSWorkSheet::closeWidget()
{
	close();
}

bool DMSWorkSheet::isDocumentAvailabel( const QString &docname )
{
	for ( int a = 0; a < treeWidgetWorkSheet->topLevelItemCount(); a++ )
	{
		qApp->processEvents();

		QTreeWidgetItem *_item = treeWidgetWorkSheet->topLevelItem( a );

		if ( _item->childCount() >= 1 )
		{
			for ( int b = 0; _item->childCount(); b++ )
			{
				qApp->processEvents();

				if ( _item->child( b ) != NULL )
				{
					if ( _item->child( b )->text( 0 ) == docname )
						return true;
				}
				else
					return false;
			}
		}
	}

	return false;
}
