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

#include <dmsmysqlconnection.h>
#include <dmspreference.h>

#include <libdms.h>
#include <base64.h>
#include <XMLPreferences.h>

#include <QtCore>
#include <QtGui>
#include <QtSql>

namespace asaal
{
	DMSPreference *dmspreference = NULL;
	DMSPreference::DMSPreference( LibDMS *dms, QWidget *parent ) : QWidget( parent )
	{
		setupUi( this );
		dmspreference = this;

		_dms = dms;

		connect( treeWidgetApplicationPref, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetApplicationPrefItem( QTreeWidgetItem *, int ) ) );
		connect( treeWidgetMailAddressPref, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetMailAddressPrefItem( QTreeWidgetItem *, int ) ) );
		

		connect( btnAddApplication, SIGNAL( clicked() ), this, SLOT( addApplication() ) );		
		connect( btnUpdateApplication, SIGNAL( clicked() ), this, SLOT( updateApplication() ) );
		connect( btnRemoveApplication, SIGNAL( clicked() ), this, SLOT( removeApplication() ) );

		connect( btnAddMailAddress, SIGNAL( clicked() ), this, SLOT( addMailAddress() ) );		
		connect( btnUpdateMailAddress, SIGNAL( clicked() ), this, SLOT( updateMailAddress() ) );
		connect( btnRemoveMailAddress, SIGNAL( clicked() ), this, SLOT( removeMailAddress() ) );	

		connect( btnCheck, SIGNAL( clicked() ), this, SLOT( checkConnection() ) );
		connect( btnSelectApplication, SIGNAL( clicked() ), this, SLOT( chooseApplication() ) );
		connect( btnApply, SIGNAL( clicked() ), this, SLOT( savePreferences() ) );
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

		loadPreferences();

		_dms->clearErrorMessage();
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

	void DMSPreference::addMailAddress()
	{
		QString maildescription = lineEditMailAddressDescription->text();
		QString mailaddress = lineEditMailAddress->text();		
		
		if( mailaddress.isNull() || mailaddress.isEmpty() )
		{
			showErrorMsg( tr( "You must enter a email address!" ) );
			return;
		}
		
		appItem = new QTreeWidgetItem( treeWidgetMailAddressPref );
		appItem->setText( 0, maildescription );
		appItem->setText( 1, mailaddress );

		lineEditMailAddress->setText( "" );
		lineEditMailAddressDescription->setText( "" );
	}

	void DMSPreference::updateMailAddress()
	{
		appItem = treeWidgetMailAddressPref->currentItem();
		if( appItem == NULL )
		{
			showErrorMsg( tr( "No item was selected!" ) );
			return;
		}
		
		if( lineEditMailAddress->text().isNull() || lineEditMailAddress->text().isEmpty() )
		{
			showErrorMsg( tr( "You must enter a email address!" ) );
			return;
		}
		
		appItem->setText( 0, lineEditMailAddressDescription->text() );
		appItem->setText( 1, lineEditMailAddress->text() );
	}

	void DMSPreference::removeMailAddress()
	{

		appItem = treeWidgetMailAddressPref->currentItem();

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

	void DMSPreference::treeWidgetMailAddressPrefItem( QTreeWidgetItem *item, int column )
	{
		if ( item == NULL )
			return;
		
		lineEditMailAddressDescription->setText( item->text( 0 ) );
		lineEditMailAddress->setText( item->text( 1 ) );
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
			qApp->processEvents();

			appItem = treeWidgetApplicationPref->topLevelItem( i );

			QString itemApp = appItem->text( 0 );
			QString itemAppExt = appItem->text( 1 );
			_dms->insertApplicationSettings( objectName(), "File associations", itemApp, itemAppExt );
		}
		
		// TODO Save database settings		
		if( lineEditHost->text().isEmpty() )
		{
			showErrorMsg( tr( "You must enter a valid host or ip address!" ) );
			return;
		}

		if( spinBoxPort->value() <= 0 )
		{
			showErrorMsg( tr( "You must enter a valid port number!" ) );
			return;
		}

		if( lineEditUser->text().isEmpty() )
		{
			showErrorMsg( tr( "You must enter a valid user name!" ) );
			return;
		}

		if( comboBoxDatabase->currentText().isEmpty() || comboBoxDatabase->currentIndex() == -1 )
		{
			showErrorMsg( tr( "You must select a valid database!" ) );
			return;
		}

		QString file = QDir::homePath();

		QDir pref( file + "/.dms/connection" );
		if( !pref.exists() )
			pref.mkpath( file + "/.dms/connection" );

		file.append ( "/.dms/connection/mysql.xml" );

		XMLPreferences dbsettings( "DMSMySqlConnection", "" );
		dbsettings.setVersion( "0.1.0.0" );
		dbsettings.setString( "MySqlConnection", "UserName", lineEditUser->text() );
		dbsettings.setString( "MySqlConnection", "Password", Base64::encode( QVariant( lineEditPassword->text() ).toByteArray() ) );
		dbsettings.setString( "MySqlConnection", "Database", comboBoxDatabase->currentText() );
		dbsettings.setString( "MySqlConnection", "HostName", lineEditHost->text() );
		dbsettings.setInt( "MySqlConnection", "Port", spinBoxPort->value() );
		dbsettings.save( file );

		// TODO Save eMail settings
		for ( int i = 0; i < treeWidgetMailAddressPref->topLevelItemCount(); i++ )
		{
			qApp->processEvents();

			appItem = treeWidgetMailAddressPref->topLevelItem( i );

			QString itemMailDescription = appItem->text( 0 );
			QString itemMail = appItem->text( 1 );

			_dms->insertApplicationSettings( objectName(), "Mails", itemMail, itemMailDescription );
		}

		// TODO Save plugin settings
		// nothing to do at this time ...

		// TODO Save skin settings
		// nothing to do at this time ...
		
		// at the end, we are close the widget
		closeWidget();
	}

	void DMSPreference::loadPreferences()
	{
		// TODO Load widget geometry (location on screen only (center))
		move( geometry().center().x() / 2, geometry().center().y() / 2 );

		// TODO Load application and this file-exstansion settings
		QMap< QString, QString> appFiles = _dms->getApplicationSettings( objectName(), "File associations" );
		QMap< QString, QString>::const_iterator appIt = appFiles.begin();

		while( appIt != appFiles.end() )
		{
			qApp->processEvents();

			appItem = new QTreeWidgetItem( treeWidgetApplicationPref );
			appItem->setText( 0, appIt.key() );
			appItem->setText( 1, appIt.value() );
			
			++appIt;
		}
		
		// TODO Load email settings
		QMap<QString, QString> mails = _dms->getApplicationSettings( objectName(), "Mails" );
		QMap<QString, QString>::const_iterator mailIt = mails.begin();
		while( mailIt != mails.end() )
		{
			qApp->processEvents();

			appItem = new QTreeWidgetItem( treeWidgetMailAddressPref );
			appItem->setText( 0, mailIt.value() );
			appItem->setText( 1, mailIt.key() );			

			++mailIt;
		}


		// TODO Load database settings
		QString file = QDir::homePath();
		file.append ( "/.dms/connection/mysql.xml" );

		XMLPreferences dbsettings( "DMSMySqlConnection", "" );
		dbsettings.setVersion( "0.1.0.0" );
		dbsettings.load( file );

		QString user = dbsettings.getString( "MySqlConnection", "UserName" );
		QString upwd = QVariant( Base64::decode( dbsettings.getString( "MySqlConnection", "Password" ) ) ).toString();
		QString host = dbsettings.getString( "MySqlConnection", "HostName" );
		QString db = dbsettings.getString( "MySqlConnection", "Database" );
		int port =  dbsettings.getInt( "MySqlConnection", "Port" );
		
	
		lineEditUser->setText( user );
		lineEditPassword->setText( upwd );
		lineEditHost->setText( host );
		spinBoxPort->setValue( port );
		comboBoxDatabase->addItem( db );

		upwd.clear();
		user.clear();
		host.clear();
		port = 0;

		// TODO Load plugin settings
		// nothing to do at this time ...

		// TODO Load skin settings
		// nothing to do at this time ...
	}

	void DMSPreference::checkConnection()
	{
		comboBoxDatabase->clear();

		QSqlQuery queryDatabases( "SHOW DATABASES;" );
		if(queryDatabases.isActive())
		{
			while(queryDatabases.next())
			{					
				QSqlQuery queryDms( "SELECT USERNAME FROM " + queryDatabases.value( 0 ).toString() + ".USERS" );
					
				if( queryDms.isActive() )
				{
					comboBoxDatabase->addItem( queryDatabases.value( 0 ).toString() );
						
					QSqlDatabase::removeDatabase ( "available_db" );
					return;
				}
			}	
		}
	}

	void DMSPreference::closeWidget()
	{
		close();
	}
}
