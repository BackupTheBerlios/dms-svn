/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
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

#include <dmsmysqlconnection.h>
#include <dmspreference.h>

#include <libdms.h>
#include <XMLPreferences.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	DMSPreference *dmspreference = NULL;
	DMSPreference::DMSPreference( LibDMS *dms, QWidget *parent ) : QWidget( parent )
	{
		setupUi( this );
		dmspreference = this;

		_dms = dms;

		connect( treeWidgetApplicationPref, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetApplicationPrefItem( QTreeWidgetItem *, int ) ) );
		connect( comboBoxSqlScript, SIGNAL( currentIndexChanged( int ) ), this, SLOT( comboBoxSqlScriptCurrentIndexChanged( int ) ) );

		connect( btnAdd, SIGNAL( clicked() ), this, SLOT( addApplication() ) );		
		connect( btnUpdate, SIGNAL( clicked() ), this, SLOT( updateApplication() ) );
		connect( btnRemove, SIGNAL( clicked() ), this, SLOT( removeApplication() ) );		
		connect( btnCheckMySQLConnection, SIGNAL( clicked() ), this, SLOT( checkMySqlConnection() ) );
		connect( btnCheckMsSQLConnection, SIGNAL( clicked() ), this, SLOT( checkMsSqlConnection() ) );
		connect( btnExecuteSqlScript, SIGNAL( clicked() ), this, SLOT( executeSqlScript() ) );
		connect( btnSelectApplication, SIGNAL( clicked() ), this, SLOT( chooseApplication() ) );
		connect( btnApply, SIGNAL( clicked() ), this, SLOT( savePreferences() ) );
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

		loadPreferences();
	}

	DMSPreference::~DMSPreference()
	{
		dmspreference = NULL;
	}

	void DMSPreference::closeEvent( QCloseEvent *e )
	{
		dmspreference = NULL;
		e->accept();
	}

	void DMSPreference::chooseApplication()
	{
		QString application = QFileDialog::getOpenFileName( this, tr ( "Open application" ), QDir::rootPath(), tr( "All files (*)" ) );
		if( application.isNull() || application.isEmpty() )
			return;
		
		lineEditApplication->setText( application );	
	}

	void DMSPreference::addApplication()
	{
		QString appname = lineEditApplication->text();
		QString appextensions = comboBoxFileExtensions->currentText();
		
		if( appname.isNull() || appname.isEmpty() )
		{
			showErrorMsg( tr( "You must select a application!" ) );
			return;
		}
		
		if( appextensions.isNull() || appextensions.isEmpty() )
		{
			showErrorMsg( tr( "You must enter a application suffix!" ) );
			return;
		}
		
		appItem = new QTreeWidgetItem( treeWidgetApplicationPref );
		appItem->setText( 0, appname );
		appItem->setText( 1, appextensions );

		lineEditApplication->setText( "" );
		comboBoxFileExtensions->setCurrentIndex( 0 );
	}

	void DMSPreference::updateApplication()
	{
		appItem = treeWidgetApplicationPref->currentItem();
		if( appItem == NULL )
		{
			showErrorMsg( tr( "No item was selected!" ) );
			return;
		}
		
		if( lineEditApplication->text().isNull() || lineEditApplication->text().isEmpty() )
		{
			showErrorMsg( tr( "You must select a application!" ) );
			return;
		}
		
		if( comboBoxFileExtensions->currentText().isNull() || comboBoxFileExtensions->currentText().isEmpty() )
		{
			showErrorMsg( tr( "You must enter a application suffix!" ) );
			return;
		}
		
		appItem->setText( 0, lineEditApplication->text() );
		appItem->setText( 1, comboBoxFileExtensions->currentText() );
	}

	void DMSPreference::removeApplication()
	{
		appItem = treeWidgetApplicationPref->currentItem();

		if( appItem == NULL )
		{
			showErrorMsg( tr( "No item was selected!" ) );
			return;
		}
		
		switch( QMessageBox::question( this, tr( "DMS - Preference" ), tr( "Would you delete this item?" ), QMessageBox::Yes | QMessageBox::No ) )
		{
			case QMessageBox::Yes:
				delete appItem;
				break;
			case QMessageBox::No:
				return;
			default:
				return;
		}
	}

	void DMSPreference::treeWidgetApplicationPrefItem( QTreeWidgetItem *item, int column )
	{
		if ( item == NULL )
			return;
		
		lineEditApplication->setText( item->text( 0 ) );

		int idx = comboBoxFileExtensions->findText( item->text( 1 ), Qt::MatchExactly );
		comboBoxFileExtensions->setCurrentIndex( idx );
	}

	void DMSPreference::comboBoxSqlScriptCurrentIndexChanged( int index )
	{
		QString sqlScript = QString( "" );

		switch ( index )
		{

			case 0: // My SQL Server 5.1 Script
				sqlScript = QString( ":/database/sql/mysql.sql" );
				break;

			case 1: // MS SQL Server 2005 Script
				sqlScript = QString( ":/database/sql/mssql.sql" );
				break;

			case 2: // SQLite Script
				sqlScript = QString( ":/" );
				break;
		}

		QFile sqlFile( sqlScript );

		if ( !sqlFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
		{
			textBrowserSqlScript->setText( tr( "<center><b>Can not read sql script.</b></center>" ) );
			return;
		}
		
		QString sql = sqlFile.readAll();
		textBrowserSqlScript->setText( sql );

		sqlFile.close();
	}

	void DMSPreference::showErrorMsg( const QString &error )
	{
		QMessageBox::critical( this, tr( "DMS - Preference" ), error );
	}

	void DMSPreference::savePreferences()
	{
		// TODO Save application and this file-exstansion settings
		for ( int i = 0; i < treeWidgetApplicationPref->topLevelItemCount(); i++ )
		{
			appItem = treeWidgetApplicationPref->topLevelItem( i );

			QString itemApp = appItem->text( 0 );
			QString itemAppExt = appItem->text( 1 );
			_dms->insertApplicationSettings( objectName(), "File associations", itemApp, itemAppExt );
		}

		// TODO Save plugin settings

		// TODO Save skin settings

		// TODO Save database settings
	}

	void DMSPreference::loadPreferences()
	{
		// TODO Load widget geometry (location on screen only (center))
		move( geometry().center().x() / 2, geometry().center().y() / 2 );

		// TODO Load database settings

		// TODO Load application and this file-exstansion settings

		// TODO Load plugin settings

		// TODO Load skin settings
	}

	void DMSPreference::checkMySqlConnection()
	{
	}

	void DMSPreference::checkMsSqlConnection()
	{
	}

	void DMSPreference::executeSqlScript()
	{
	}

	void DMSPreference::closeWidget()
	{
		close();
	}
}
