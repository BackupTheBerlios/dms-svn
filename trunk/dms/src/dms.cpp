/***************************************************************************
*   Copyright (C) 2007 by Alexander Saal                                  *
*   alex.saal@gmx.de                                                      *
*                                                                         *
*   File: dllexport.h                                                     *
*   Desc: export/import function for external call                        *
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

#include "dms.h"

#include <libdms.h>
#include <dmsplugininterface.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	DMSystem::DMSystem( const QApplication &app, QMainWindow *parent ) : QMainWindow( parent )
	{
		setWindowTitle( tr( "DMS - Doucmnet Management System" ) );

		ws = new QWorkspace( this );
		setCentralWidget( ws );

		QDesktopWidget *desktop = qApp->desktop();
		const QRect rect = desktop->availableGeometry( desktop->primaryScreen() );
		int left = ( rect.width() - width() ) / 2;
		int top = ( rect.height() - height() ) / 2;
		
		int height = this->height();
		int width = this->width();
		
		setGeometry( left, top, width, height );

		statusBar()->show();

		ldms = new LibDMS();

		createMenus();
		acLogout->setEnabled( false );

		login();
		
		actionCount = 0;

		createPluginMenu();		
	}

	DMSystem::~DMSystem()
	{}

	void DMSystem::closeEvent( QCloseEvent *e )
	{
		logout();
		ldms->closeConnection();
		e->accept();
	}

	void DMSystem::login()
	{
#ifdef Q_OS_WIN32
		
		QSettings *msSqlServerSettings = new QSettings( "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Microsoft SQL Server\\90\\Machines", QSettings::NativeFormat );
		QString origMachineName = msSqlServerSettings->value( "OriginalMachineName", QString( "" ) ).toString();
		delete msSqlServerSettings;

		QSettings *mySqlServerSettings = new QSettings( "HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.1", QSettings::NativeFormat );
		QString mySqlVersion = mySqlServerSettings->value( "Version", QString( "" ) ).toString();
		delete mySqlServerSettings;

		QSettings *accessSqlServerSettings = new QSettings( "HKEY_CURRENT_USER\\Software\\Microsoft\\Office\\11.0\\Access", QSettings::NativeFormat );
		QString accessName = accessSqlServerSettings->value( "AccessName", QString( "" ) ).toString();
		delete accessSqlServerSettings;

		QString file = QDir::homePath();
		file.append ( "/.dms/connection/mysql.xml" );
		if( QFile::exists( file ) )
		{
			ldms->showDmsMySqlConnection();
			goto LABEL_DISPLAY;
		}

		file.clear();
		file = QDir::homePath();
		file.append( "/.dms/connection/mssql.xml" );
		if( QFile::exists( file ) )
		{
			ldms->showDmsMsSqlConnection();
			goto LABEL_DISPLAY;
		}
			
		if( !origMachineName.isEmpty() && !mySqlVersion.isEmpty() && !accessName.isEmpty() )
		{
			ldms->showDmsDatabaseSelection();
		}
		else if( !origMachineName.isEmpty() && mySqlVersion.isEmpty() && accessName.isEmpty() )
		{
			ldms->showDmsMsSqlConnection();
		}
		else if( origMachineName.isEmpty() && !mySqlVersion.isEmpty() && accessName.isEmpty() )
		{
			ldms->showDmsMySqlConnection();
		}
		else if( origMachineName.isEmpty() && mySqlVersion.isEmpty() && !accessName.isEmpty() )
		{
			//code here to connect to the access database
		}
		else if( origMachineName.isEmpty() && mySqlVersion.isEmpty() && accessName.isEmpty() )
		{
			// code here to display a message (database not found) or use sqlite
		}
#else
		// TODO code her for using MySQL and SQLite3
		ldms->showDmsMySqlConnection();
#endif
LABEL_DISPLAY:
		if ( ldms->isConnectionAvailabel( ldms->getUserId( ldms->loggedUser ) ) )
		{
			deactivateMenus( true );
			acToolBarLogout->setEnabled( true );
			acToolBarLogin->setEnabled( false );
			acLogout->setEnabled( true );
			acLogin->setEnabled( false );
		}
		else
		{
			deactivateMenus( false );
			acToolBarLogout->setEnabled( false );
			acToolBarLogin->setEnabled( true );
			acLogout->setEnabled( false );
			acLogin->setEnabled( true );
		}
	}

	void DMSystem::logout()
	{
		if ( ldms->logout( ldms->getUserId( ldms->loggedUser ) ) )
		{
			deactivateMenus( false );
			acToolBarLogout->setEnabled( false );
			acToolBarLogin->setEnabled( true );
			acLogout->setEnabled( false );
			acLogin->setEnabled( true );
		}

		acToolBarLogout->setEnabled( false );

		acToolBarLogin->setEnabled( true );
		acLogout->setEnabled( false );
		acLogin->setEnabled( true );
	}

	void DMSystem::closeWidget()
	{
		logout();
		ldms->closeConnection();
		qApp->quit();
	}

	void DMSystem::creatEditGroups()
	{
		ldms->showGroup( ws );
	}

	void DMSystem::creatEditDocuments()
	{
		ldms->showDmsDocument( ws );
	}

	void DMSystem::createEditUsers()
	{
		ldms->showDmsUser( ws );
	}

	void DMSystem::openPreference()
	{
		ldms->showDmsPreference( ws );
	}

	void DMSystem::openWorkSheet()
	{
		ldms->showDmsWorkSheet( ws );
	}

	void DMSystem::createMenus()
	{
		// Menu
		QMenu *mnuFile = menuBar()->addMenu( tr( "&File" ) );
		acClose = mnuFile->addAction( tr( "&Close" ) );
		acClose->setIcon( QPixmap( ":/picture/16/images/16x16/delete_16.png" ) );
		acClose->setStatusTip( tr( "Close application ..." ) );
		connect( acClose, SIGNAL( triggered() ), this, SLOT( closeWidget() ) );

		QMenu *mnuDatabase = menuBar()->addMenu( tr( "Data&base" ) );
		acLogout = mnuDatabase->addAction( tr( "L&ogout" ) );
		acLogout->setIcon( QPixmap( ":/picture/16/images/16x16/paste_16.png" ) );
		acLogout->setStatusTip( tr( "Close session ..." ) );
		connect( acLogout, SIGNAL( triggered() ), this, SLOT( logout() ) );

		acLogin = mnuDatabase->addAction( tr( "&Login" ) );
		acLogin->setIcon( QPixmap( ":/picture/16/images/16x16/paste_16.png" ) );
		acLogin->setStatusTip( tr( "Open session ..." ) );
		connect( acLogin, SIGNAL( triggered() ), this, SLOT( login() ) );

		mnuDatabase->addSeparator();

		acCreadEditGroups = mnuDatabase->addAction( tr( "New / Edit &Groups" ) );
		acCreadEditGroups->setIcon( QPixmap( ":/picture/16/images/16x16/group_16.png" ) );
		acCreadEditGroups->setStatusTip( tr( "Create or edit groups ..." ) );
		connect( acCreadEditGroups, SIGNAL( triggered() ), this, SLOT( creatEditGroups() ) );

		acCreadEditDoucmnets = mnuDatabase->addAction( tr( "New / Edit &Documents" ) );
		acCreadEditDoucmnets->setIcon( QPixmap( ":/picture/16/images/16x16/documents_16.png" ) );
		acCreadEditDoucmnets->setStatusTip( tr( "Create or edit documnets ..." ) );
		connect( acCreadEditDoucmnets, SIGNAL( triggered() ), this, SLOT( creatEditDocuments() ) );

		acCreadEditUsers = mnuDatabase->addAction( tr( "New / Edit &Users" ) );
		acCreadEditUsers->setIcon( QPixmap( ":/picture/16/images/16x16/user_16.png" ) );
		acCreadEditUsers->setStatusTip( tr( "Create or edit users ..." ) );
		connect( acCreadEditUsers, SIGNAL( triggered() ), this, SLOT( createEditUsers() ) );

		mnuDatabase->addSeparator();

		acPreference = mnuDatabase->addAction( tr( "&Preference" ) );
		acPreference->setIcon( QPixmap( ":/picture/16/images/16x16/preference_16.png" ) );
		acPreference->setStatusTip( tr( "Set preferences ..." ) );
		connect( acPreference, SIGNAL( triggered() ), this, SLOT( openPreference() ) );


		QMenu *mnuView = menuBar()->addMenu( tr( "&Views" ) );
		acWorkSheet = mnuView -> addAction( tr( "&Open Worksheet" ) );
		acWorkSheet->setIcon( QPixmap( ":/picture/16/images/16x16/home_16.png" ) );
		acWorkSheet->setStatusTip( tr( "Open worksheet ..." ) );
		connect( acWorkSheet, SIGNAL( triggered() ), this, SLOT( openWorkSheet() ) );

		// Toolbar
		mnuToolBar = new QToolBar( tr( "Maintoolbar" ), this );
		mnuToolBar->setIconSize( QSize( 24, 24 ) );

		acToolBarLogout = mnuToolBar->addAction( tr( "L&ogout" ) );
		acToolBarLogout->setIcon( QPixmap( ":/picture/16/images/16x16/paste_16.png" ) );
		acToolBarLogout->setStatusTip( tr( "Close session ..." ) );
		connect( acToolBarLogout, SIGNAL( triggered() ), this, SLOT( logout() ) );

		acToolBarLogin = mnuToolBar->addAction( tr( "&Login" ) );
		acToolBarLogin->setIcon( QPixmap( ":/picture/16/images/16x16/paste_16.png" ) );
		acToolBarLogin->setStatusTip( tr( "Open session ..." ) );
		connect( acToolBarLogin, SIGNAL( triggered() ), this, SLOT( login() ) );

		mnuToolBar->addSeparator();

		acToolBarCreadEditGroups = mnuToolBar->addAction( tr( "New / Edit &Groups" ) );
		acToolBarCreadEditGroups->setIcon( QPixmap( ":/picture/16/images/16x16/group_16.png" ) );
		acToolBarCreadEditGroups->setStatusTip( tr( "Create or edit groups ..." ) );
		connect( acToolBarCreadEditGroups, SIGNAL( triggered() ), this, SLOT( creatEditGroups() ) );

		acToolBarCreadEditDoucmnets = mnuToolBar->addAction( tr( "New / Edit &Documents" ) );
		acToolBarCreadEditDoucmnets->setIcon( QPixmap( ":/picture/16/images/16x16/documents_16.png" ) );
		acToolBarCreadEditDoucmnets->setStatusTip( tr( "Create or edit documnets ..." ) );
		connect( acToolBarCreadEditDoucmnets, SIGNAL( triggered() ), this, SLOT( creatEditDocuments() ) );

		acToolBarCreadEditUsers = mnuToolBar->addAction( tr( "New / Edit &Users" ) );
		acToolBarCreadEditUsers->setIcon( QPixmap( ":/picture/16/images/16x16/user_16.png" ) );
		acToolBarCreadEditUsers->setStatusTip( tr( "Create or edit users ..." ) );
		connect( acToolBarCreadEditUsers, SIGNAL( triggered() ), this, SLOT( createEditUsers() ) );


		acToolBarWorkSheet = mnuToolBar->addAction( tr( "&Open Worksheet" ) );
		acToolBarWorkSheet->setIcon( QPixmap( ":/picture/16/images/16x16/home_16.png" ) );
		acToolBarWorkSheet->setStatusTip( tr( "Open worksheet ..." ) );
		connect( acToolBarWorkSheet, SIGNAL( triggered() ), this, SLOT( openWorkSheet() ) );

		addToolBar( mnuToolBar );
	}

	void DMSystem::createPluginMenu()
	{
		actionList.clear();

		QDir pluginsDir = QDir( QDir::homePath() );
		pluginsDir.cd ( ".dms" );
		pluginsDir.cd ( "plugins" );

		if( pluginsDir.entryList( QDir::Files ).size() >= 1 )
			mnuPlugin = menuBar()->addMenu( tr( "&Plugin" ) );
		else
			return;

		foreach( QString fileName, pluginsDir.entryList( QDir::Files ) )
		{
			if ( fileName.split ( "." ).value ( 1 ).toLower()  == "dll" || fileName.split ( "." ).value ( 1 ).toLower() == "so" )
			{
				QPluginLoader loader( pluginsDir.absoluteFilePath ( fileName ) );
				QObject *plug = loader.instance();

				if ( plug != NULL )
				{
					DMSPluginInterface *dpi = qobject_cast<DMSPluginInterface *> ( plug );
					if ( dpi )
					{
						actionList.insert( actionCount, dpi->action() );
						actionCount += 1;
					}					
				}
			}
		}

		if( actionList.size() >= 1 )
			mnuPlugin->addActions( actionList );
	}

	void DMSystem::deactivateMenus( bool deactivate )
	{
		acCreadEditGroups->setEnabled( deactivate );
		acCreadEditDoucmnets->setEnabled( deactivate );
		acCreadEditUsers->setEnabled( deactivate );
		acWorkSheet->setEnabled( deactivate );

		acToolBarCreadEditGroups->setEnabled( deactivate );
		acToolBarCreadEditDoucmnets->setEnabled( deactivate );
		acToolBarCreadEditUsers->setEnabled( deactivate );
		acToolBarWorkSheet->setEnabled( deactivate );
	}
}
