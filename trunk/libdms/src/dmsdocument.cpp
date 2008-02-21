/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmsdocument.h                                                   *
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

#include <dmsdocument.h>
#include <dmsgroup.h>
#include <dmsuser.h>
#include <dmsworksheet.h>

#include <libdms.h>

#ifdef Q_OS_WIN32
#else
#include <sane_widget.h>
#endif

#include <QtCore>
#include <QtGui>

namespace asaal
{
	DMSDocument *dmsdocument = NULL;
	DMSDocument::DMSDocument( LibDMS *dms, QWorkspace *ws, QWidget *parent ) : QWidget( parent )
	{
		setupUi( this );
		dmsdocument = this;

		_dms = dms;
		_ws = ws;

		connect( treeWidgetDocument, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetDocumentItem( QTreeWidgetItem *, int ) ) );

		connect( btnUser, SIGNAL( clicked() ), this, SLOT( newUser() ) );
		connect( btnGroup, SIGNAL( clicked() ), this, SLOT( newGroup() ) );
		connect( btnDocId, SIGNAL( clicked() ), this, SLOT( newDocumentId() ) );
		connect( btnAddDocument, SIGNAL( clicked() ), this, SLOT( addDocument() ) );
		connect( btnUpdateDocument, SIGNAL( clicked() ), this, SLOT( updateDocument() ) );
		connect( btnDeleteDocument, SIGNAL( clicked() ), this, SLOT( deleteDocument() ) );
		connect( btnSelectDocument, SIGNAL( clicked() ), this, SLOT( selectDocument() ) );
		connect( btnOk, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

		loadUser();
		loadGroups();
		loadDocuments();

		newDocumentId();

		_dms->clearErrorMessage();
	}

	DMSDocument::~DMSDocument()
	{
		dmsdocument = NULL;
	}

	void DMSDocument::closeEvent( QCloseEvent *e )
	{
		dmsdocument = NULL;
		e->accept();
	}

	void DMSDocument::addDocument()
	{
		if ( comboBoxUser->currentText().isNull() || comboBoxUser->currentText().isEmpty() )
		{
			showErrorMsg( tr( "Please select a user." ) );
			return;
		}

		if ( comboBoxGroup->currentText().isNull() || comboBoxGroup->currentText().isEmpty() )
		{
			showErrorMsg( tr( "Please select a group." ) );
			return;
		}

		QString userid = QString( "" );

		QMap< QString, QString>::const_iterator userIt = users.begin();

		while ( userIt != users.end() )
		{
			qApp->processEvents();

			QString fname = userIt.value().split( "#" ).value( 2 );
			QString nname = userIt.value().split( "#" ).value( 3 );

			QString completename = nname + ", " +  fname;

			if ( completename == comboBoxUser->currentText() )
			{
				userid = userIt.key();
				break;
			}

			++userIt;
		}

		QString docid = lineEditDocumentId->text();

		QString docname = lineEditDocumentName->text();
		QString docpath = lineEditDocumentPath->text();

		if ( docname.isNull() || docname.isEmpty() )
		{
			showErrorMsg( tr( "Please enter document name." ) );
			lineEditDocumentName->setFocus();
			lineEditDocumentName->setSelection( 0, lineEditDocumentName->text().length() );
			return;
		}
		
		if ( docpath.isNull() || docpath.isEmpty() )
		{
			showErrorMsg( tr( "Please select a document." ) );
			lineEditDocumentPath->setFocus();
			lineEditDocumentPath->setSelection( 0, lineEditDocumentPath->text().length() );
			return;
		}

		// add document to the list
		docItem = new QTreeWidgetItem( treeWidgetDocument );
		docItem->setText( 0, comboBoxUser->currentText() );
		docItem->setText( 1, docname );
		docItem->setText( 2, comboBoxGroup->currentText() );
		docItem->setText( 3, docpath );

		QString groupid = _dms->getGroupId( comboBoxGroup->currentText() );

		_dms->insertDocument( docid, userid, groupid, docname, docpath );

		if ( !_dms->getErrorMessage().isEmpty() )
			showErrorMsg( _dms->getErrorMessage() );

		_dms->clearErrorMessage();

		lineEditDocumentName->setText( "" );
		lineEditDocumentPath->setText( "" );

		newDocumentId();

		if ( dmsworksheet )
			dmsworksheet->loadDocuments();
	}

	void DMSDocument::updateDocument()
	{
		docItem = treeWidgetDocument->currentItem();

		if ( docItem == NULL )
		{
			showErrorMsg( tr( "No document was selected." ) );
			return;
		}

		QString username = comboBoxUser->currentText();
		QString docname = lineEditDocumentName->text();
		QString groupname = comboBoxGroup->currentText();
		QString docpath = lineEditDocumentPath->text();

		if ( username.isNull() || username.isEmpty() )
		{
			showErrorMsg( tr( "Please select a user." ) );
			comboBoxUser->setFocus();
			return;
		}

		if ( docname.isNull() || docname.isEmpty() )
		{
			showErrorMsg( tr( "Please enter document name." ) );
			lineEditDocumentName->setFocus();
			lineEditDocumentName->setSelection( 0, lineEditDocumentName->text().length() );
			return;
		}
		else
			if ( groupname.isNull() || groupname.isEmpty() )
			{
				showErrorMsg( tr( "Please select a group." ) );
				comboBoxGroup->setFocus();
				return;
			}
			else
				if ( docpath.isNull() || docpath.isEmpty() )
				{
					showErrorMsg( tr( "Please select a document path." ) );
					lineEditDocumentPath->setFocus();
					lineEditDocumentPath->setSelection( 0, lineEditDocumentPath->text().length() );
					return;
				}

		docItem->setText( 0, username );

		docItem->setText( 1, docname );
		docItem->setText( 2, groupname );
		docItem->setText( 3, docpath );

		QString groupid = _dms->getGroupId( groupname );
		QString userid = _dms->getUserId( username );
		_dms->updateDocument( lineEditDocumentId->text(), userid, groupid, docname, docpath );

		if ( !_dms->getErrorMessage().isEmpty() )
			showErrorMsg( _dms->getErrorMessage() );

		_dms->clearErrorMessage();

		lineEditDocumentName->setText( "" );

		lineEditDocumentPath->setText( "" );

		newDocumentId();

		if ( dmsworksheet )
			dmsworksheet->loadDocuments();
	}

	void DMSDocument::deleteDocument()
	{
		docItem = treeWidgetDocument->currentItem();

		if ( docItem == NULL )
		{
			showErrorMsg( tr( "No document was selected." ) );
			return;
		}

		QString userid = _dms->getUserId( docItem->text( 0 ) );

		QString docid = _dms->getDocId( userid, docItem->text( 1 ) );
		_dms->deleteDocument( docid, userid );

		if ( !_dms->getErrorMessage().isEmpty() )
			showErrorMsg( _dms->getErrorMessage() );
		else
			delete docItem;

		_dms->clearErrorMessage();

		lineEditDocumentName->setText( "" );

		lineEditDocumentPath->setText( "" );

		newDocumentId();

		if ( dmsworksheet )
			dmsworksheet->loadDocuments();
	}

	void DMSDocument::selectDocument()
	{
		QString document = QFileDialog::getOpenFileName ( this, tr ( "Open document file" ), QDir::homePath(), tr ( "All files (*.*)" ) );

		if ( document.isEmpty() )
			return ;

		lineEditDocumentPath->setText( document );

		if ( lineEditDocumentName->text().isNull() || lineEditDocumentName->text().isEmpty() || lineEditDocumentName->text().length() <= 0 )
		{
			QFileInfo docInfo( document );
			lineEditDocumentName->setText( docInfo.fileName() );
		}
	}

	void DMSDocument::newDocumentId()
	{
		lineEditDocumentId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );
	}


	void DMSDocument::scanDocument()
	{
#ifdef Q_OS_WIN32
#else
		QApplication::setOverrideCursor( Qt::WaitCursor );
		qApp->processEvents();

		m_progressDialog = NULL;
		QString device( "" );

		// Scanning dialog
		m_scanWidget = new QWidget();

		QVBoxLayout *vlayout = new QVBoxLayout( m_scanWidget );
		QHBoxLayout *hlayout = new QHBoxLayout;

		QFrame *separator = new QFrame( m_scanWidget );
		separator->setFrameShape( QFrame::HLine );
		separator->setFrameShadow( QFrame::Sunken );

		m_sanew = new SaneWidget( m_scanWidget );

		if ( m_sanew->openDevice( device ) == false )
		{
			QApplication::restoreOverrideCursor();

			QString dev = m_sanew->selectDevice( NULL );

			if ( m_sanew->openDevice( dev ) == false )
			{
				if ( m_scanWidget != NULL )
				{
					m_scanWidget = NULL;
				}

				if ( m_sanew != NULL )
				{
					m_sanew = NULL;
				}

				return;
			}

			m_scanWidget->setWindowTitle( tr( "Scan document on [ %1 ]" ).arg( dev ) );
		}


		connect( m_sanew, SIGNAL( scanStart() ), this, SLOT( scanStart() ) );

		connect( m_sanew, SIGNAL( scanFaild() ), this, SLOT( scanFailed() ) );
		connect( m_sanew, SIGNAL( scanDone() ), this, SLOT( scanEnd() ) );
		connect( m_sanew, SIGNAL( imageReady() ), this, SLOT( imageReady() ) );

		m_sanew->setIconColorMode( QIcon( ":/scanimages/images/scanimages/color.png" ) );
		m_sanew->setIconGrayMode( QIcon( ":/scanimages/images/scanimages/gray.png" ) );
		m_sanew->setIconBWMode( QIcon( ":/scanimages/images/scanimages/black_white.png" ) );
		m_sanew->setIconPreview( QIcon( ":/scanimages/images/scanimages/eye.png" ) );
		m_sanew->setIconFinal( QIcon( ":/scanimages/images/scanimages/filesave.png" ) );
		m_sanew->setIconZoomIn( QIcon( ":/scanimages/images/scanimages/viewmag+.png" ) );
		m_sanew->setIconZoomOut( QIcon( ":/scanimages/images/scanimages/viewmag-.png" ) );
		m_sanew->setIconZoomSel( QIcon( ":/scanimages/images/scanimages/viewmagfit.png" ) );
		m_sanew->setIconZoomFit( QIcon( ":/scanimages/images/scanimages/view_fit_window.png" ) );

		vlayout->setMargin( 2 );
		vlayout->setSpacing( 2 );
		vlayout->addWidget( m_sanew );
		vlayout->addWidget( separator );
		vlayout->addLayout( hlayout );

		_ws->addWindow( m_scanWidget );
		m_scanWidget->show();

		QApplication::restoreOverrideCursor();
#endif
	}

	void DMSDocument::scanStart()
	{
#ifdef Q_OS_WIN32
#else
		QApplication::setOverrideCursor( Qt::WaitCursor );

		if ( m_progressDialog == NULL )
		{
			m_progressDialog = new QProgressDialog( NULL );
		}

		m_progressDialog->setWindowTitle( tr( "Scanning document ..." ) );

		m_progressDialog->setCancelButtonText( tr( "Cancel" ) );
		m_progressDialog->setMaximum( PROGRESS_MAX );
		m_progressDialog->setMinimum( PROGRESS_MIN );

		if ( m_sanew )
		{
			connect( m_progressDialog, SIGNAL( canceled() ), m_sanew, SLOT( scanCancel() ) );
			connect( m_sanew, SIGNAL( scanProgress( int ) ), m_progressDialog, SLOT( setValue( int ) ) );
		}

		m_progressDialog->show();

		QApplication::restoreOverrideCursor();
#endif
	}

	void DMSDocument::scanEnd()
	{
#ifdef Q_OS_WIN32
#else

		if ( m_progressDialog != NULL )
		{
			delete( m_progressDialog );
			m_progressDialog = NULL;
		}

#endif
	}

	void DMSDocument::scanFailed()
	{
#ifdef Q_OS_WIN32
#else

		if ( m_progressDialog != NULL )
		{
			delete( m_progressDialog );
			m_progressDialog = NULL;
		}

		QMessageBox mb( "SaneWidget",

						"Scanning failed!\n",
						QMessageBox::Critical,
						QMessageBox::Ok | QMessageBox::Default,
						QMessageBox::NoButton,
						QMessageBox::NoButton );
		mb.exec();
#endif
	}

	void DMSDocument::imageReady()
	{
#ifdef Q_OS_WIN32
#else
		qApp->processEvents();

		bool ok;
		QString imagename = QInputDialog::getText( this, tr( "New image name" ), tr( "Enter a valid Imagename!\n\nImagename:" ), QLineEdit::Normal, "Image", &ok );

		if ( !ok && ( imagename.isEmpty() || imagename.isNull() ) )
			return;

		QApplication::setOverrideCursor( Qt::WaitCursor );

		QPixmap pix = QPixmap::fromImage( *( m_sanew->getFinalImage() ) );

		if ( !pix.isNull() )
		{
			qApp->processEvents();

			m_scanWidget->close();

			QString documentarchive = _dms->getApplicationSettings( "UiPreferenceBase", "General", "Documentarchive", QVariant( QDir::homePath() ) ).toString();

			if ( documentarchive.isNull() || documentarchive.isEmpty() )
			{
				QApplication::restoreOverrideCursor();

				documentarchive = QDir::homePath() + QDir::separator() + ".dms" + QDir::separator() + "documents";
				showErrorMsg( tr( "No document archive was set, use default.\n\nArchive: %1" ).arg( documentarchive ) );

				QApplication::setOverrideCursor( Qt::WaitCursor );
			}

			documentarchive += imagename + ".png";
			pix.save( documentarchive, "PNG" );

			QFileInfo fi( documentarchive );

			lineEditDocumentName->setText( fi.fileName().split( "." ).value( 0 ) );
			lineEditDocumentPath->setText( documentarchive );
		}

		m_sanew = NULL;
		m_scanWidget = NULL;
		
		QApplication::restoreOverrideCursor();
#endif
	}

	void DMSDocument::newUser()
	{
		if ( !dmsuser )
		{
			dmsuser = new DMSUser( _dms );
			_ws->addWindow( dmsuser );
			dmsuser->show();
		}
		else
		{
			dmsuser->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	void DMSDocument::newGroup()
	{
		if ( !dmsgroup )
		{
			dmsgroup = new DMSGroup( _dms );
			_ws->addWindow( dmsgroup );
			dmsgroup->show();
		}
		else
		{
			dmsgroup->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	void DMSDocument::treeWidgetDocumentItem( QTreeWidgetItem *item, int column )
	{
		QString username = item->text( 0 );
		QString docname = item->text( 1 );
		QString docpath = item->text( 3 );

		QString userid = _dms->getUserId( username );
		QString docid = _dms->getDocId( userid, docItem->text( 1 ) );

		lineEditDocumentId->setText( docid );
		lineEditDocumentName->setText( docname );
		lineEditDocumentPath->setText( docpath );

		int groupIndex = comboBoxGroup->findText( item->text( 2 ), Qt::MatchExactly );

		if ( groupIndex >= 0 )
			comboBoxGroup->setCurrentIndex( groupIndex );
	}

	void DMSDocument::showErrorMsg( const QString &error )
	{
		QMessageBox::critical( this, tr( "DMS - Document" ), error );
	}

	void DMSDocument::loadUser()
	{
		comboBoxUser->clear();

		users = _dms->geUsers();

		QMap< QString, QString>::const_iterator userIt = users.begin();

		while ( userIt != users.end() )
		{
			qApp->processEvents();
			QString fname = userIt.value().split( "#" ).value( 2 );
			QString nname = userIt.value().split( "#" ).value( 3 );

			comboBoxUser->addItem( nname + ", " +  fname );
			++userIt;
		}
	}

	void DMSDocument::loadGroups()
	{
		comboBoxGroup->clear();

		groups = _dms->getGroups();

		QMap< QString, QString>::const_iterator groupIt = groups.begin();

		while ( groupIt != groups.end() )
		{
			qApp->processEvents();
			QString gname = groupIt.value().split( "#" ).value( 0 );

			comboBoxGroup->addItem( gname );
			++groupIt;
		}
	}

	void DMSDocument::loadDocuments()
	{
		treeWidgetDocument->clear();

		documents = _dms->geDocuments( _dms->getUserId( _dms->loggedUser ) );

		QMap< QString, QString>::const_iterator docIt = documents.begin();

		while ( docIt != documents.end() )
		{
			qApp->processEvents();

			QString uname = docIt.value().split( "#" ).value( 0 );
			QString docname = docIt.value().split( "#" ).value( 2 );
			QString gname = docIt.value().split( "#" ).value( 1 );
			QString docpath = docIt.value().split( "#" ).value( 3 );

			docItem = new QTreeWidgetItem( treeWidgetDocument );
			docItem->setText( 0, uname );
			docItem->setText( 1, docname );
			docItem->setText( 2, gname );
			docItem->setText( 3, docpath );

			++docIt;
		}
	}

	void DMSDocument::closeWidget()
	{
		close();
	}
}
