/***************************************************************************
 *   Copyright (C) 2007 by Alexander Saal                                  *
 *   alex.saal@gmx.de                                                      *
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
#include <XMLPreferences.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	DMSWorkSheet *dmsworksheet = NULL;
	DMSWorkSheet::DMSWorkSheet( LibDMS *dms, QWorkspace *ws, QWidget *parent ) : QWidget( parent )
	{
		setupUi( this );
		dmsworksheet = this;

		_dms = dms;
		_ws = ws;

		connect( treeWidgetWorkSheet, SIGNAL( customContextMenuRequested( QPoint ) ), this, SLOT( treeWidgetWorkSheetMenu( QPoint ) ) );
		connect( treeWidgetWorkSheet, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetWorkSheetItem( QTreeWidgetItem *, int ) ) );		

		createMenuAction();
		loadDocuments();

	}

	DMSWorkSheet::~DMSWorkSheet()
	{
		dmsworksheet = NULL;
	}

	void DMSWorkSheet::closeEvent( QCloseEvent *e )
	{
		QString file = QDir::homePath();

		QDir pref( file + "/.dms/settings" );
		if( !pref.exists() )
			pref.mkpath( file + "/.dms/settings" );

		file.append ( "/.dms/settings/" + objectName() + ".xml" );

		XMLPreferences widgetSettings( objectName() );
		widgetSettings.setVersion( "1.0" );
		widgetSettings.setPoint( objectName(), this->pos() );
		widgetSettings.save( file );

		dmsworksheet = NULL;
		e->accept();
	}

	void DMSWorkSheet::loadDocuments()
	{
		documents = _dms->geDocuments( _dms->getUserId( _dms->loggedUser ) );

		QMap< QString, QString>::const_iterator docIt = documents.begin();
		while( docIt != documents.end() )
		{
			qApp->processEvents();

			QString uname = docIt.value().split( "#" ).value(0);
			QString gname = docIt.value().split( "#" ).value(1);
			QString docname = docIt.value().split( "#" ).value(2);			
			QString docpath = docIt.value().split( "#" ).value(3);
			QString updated = docIt.value().split( "#" ).value(4);
			QString checkedout = docIt.value().split( "#" ).value(5);

			docItem = new QTreeWidgetItem( getGroupItem( gname ) );
			docItem->setText(0, docname );
			docItem->setText(1, docpath );
			docItem->setText(2, updated );		

			if( checkedout == "0" )
				docItem->setIcon(3, QIcon( QString::fromUtf8( ":/picture/16/images/16x16/folder-closed_16.png" ) ) );
			else if( checkedout == "1" )
				docItem->setIcon(3, QIcon( QString::fromUtf8( ":/picture/16/images/16x16/folder-open_16.png" ) ) );
			

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

		if( docItem == NULL )
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

		if( docItem == NULL )
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

		if( docItem == NULL )
		{
			showErrorMsg( tr( "No document was selected." ) );
			return;
		}

		QPrinter printer( QPrinter::HighResolution );
		printer.setOutputFormat( QPrinter::NativeFormat );
		printer.setPageSize( QPrinter::A4 );
		printer.setFullPage( true );
		printer.setDocName( docItem->text(0) );
		

		QPrintDialog *qpd = new QPrintDialog( &printer, this );
		qpd->setWindowTitle( tr( "Print: " ) + docItem->text(0) );
		if( qpd->exec() == QDialog::Accepted )
		{
			// code here for print document
		}
	}

	void DMSWorkSheet::createMenuAction()
	{
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

	void DMSWorkSheet::treeWidgetWorkSheetItem( QTreeWidgetItem *item, int column )
	{
	}

	void DMSWorkSheet::treeWidgetWorkSheetMenu( QPoint point )
	{		
		docItem = treeWidgetWorkSheet->currentItem();

		QMenu menu( this );
		QMouseEvent *mevent = new QMouseEvent( QEvent::MouseButtonPress, point, Qt::RightButton, Qt::RightButton, Qt::NoModifier );

		menu.clear();

		if( docItem == NULL )
		{
			menu.addAction( acNewDoc );
		}
		else
		{
			menu.addAction( acNewDoc );
			menu.addAction( acOpenDoc );
			menu.addAction( acDeleteDoc );
			menu.addAction( acPrintDoc );
		}

		menu.exec( mevent->globalPos() );
	}

	void DMSWorkSheet::showErrorMsg( const QString &error )
	{
		QMessageBox::critical( this, tr( "DMS - Worksheet"), error );
	}

	QTreeWidgetItem *DMSWorkSheet::getGroupItem( const QString &groupname )
	{
		for( int a = 0; a < treeWidgetWorkSheet->topLevelItemCount(); a++ ) {
			QTreeWidgetItem *_item = treeWidgetWorkSheet->topLevelItem( a );
			
			if( _item->text(0) == groupname )
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

	bool DMSWorkSheet::isGroupAvailabel( const QString &groupname )
	{
		for( int a = 0; a < treeWidgetWorkSheet->topLevelItemCount(); a++ ) {
			QTreeWidgetItem *_item = treeWidgetWorkSheet->topLevelItem( a );
			
			if( _item->text(0) == groupname )
				return true;
			else
				return false;
		}

		return false;
	}
}
