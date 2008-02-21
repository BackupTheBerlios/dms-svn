/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmsscanner.h                                                    *
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

#include <dmsscanner.h>

#include <libdms.h>

#ifdef Q_OS_WIN32
#else
	#include <sane_widget.h>
#endif

#include <QtCore>
#include <QtGui>

DMSScanner *dmsscanner = NULL;
DMSScanner::DMSScanner( QWidget *parent ) : QWidget( parent )
{
	dmsscanner = this;
	
	_dms = LibDMS::libdms_instcance();

	initScan();
}

DMSScanner::~DMSScanner()
{
	dmsscanner = NULL;
}

void DMSScanner::initScan()
{
#ifdef Q_OS_WIN32
#else
	QApplication::setOverrideCursor( Qt::WaitCursor );
	qApp->processEvents();

	m_progressDialog = NULL;
	QString device( "" );

	// Scanning dialog
	QVBoxLayout *vlayout = new QVBoxLayout( dmsscanner );
	QHBoxLayout *hlayout = new QHBoxLayout;

	QFrame *separator = new QFrame( dmsscanner );
	separator->setFrameShape( QFrame::HLine );
	separator->setFrameShadow( QFrame::Sunken );

	m_sanew = new SaneWidget( dmsscanner );

	if ( m_sanew->openDevice( device ) == false )
	{
		QApplication::restoreOverrideCursor();

		QString dev = m_sanew->selectDevice( NULL );

		if ( m_sanew->openDevice( dev ) == false )
		{
			if ( dmsscanner != NULL )
			{
				dmsscanner = NULL;
				dmsscanner->close();
			}

			if ( m_sanew != NULL )
			{
				m_sanew = NULL;
				dmsscanner->close();
			}

			return;
		}

		this->setWindowTitle( tr( "Scan document on [ %1 ]" ).arg( dev ) );
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

	dmsscanner->show();

	QApplication::restoreOverrideCursor();
#endif
}

void DMSScanner::scanStart()
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

void DMSScanner::scanEnd()
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

void DMSScanner::scanFailed()
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

void DMSScanner::imageReady()
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

		dmsscanner->close();
		
		documentarchive = _dms->getApplicationSettings( "UiPreferenceBase", "General", "Documentarchive" ).toString();

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
	}

	m_sanew = NULL;
	dmsscanner = NULL;
		
	QApplication::restoreOverrideCursor();
	
	close();
#endif
}

void DMSScanner::showErrorMsg( const QString &error )
{
	QMessageBox::critical( this, tr( "DMS - Scannerplugin" ), error );
}
