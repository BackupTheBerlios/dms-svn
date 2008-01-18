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

#include <dmsmysqlconnection.h>

#include <base64.h>
#include <XMLPreferences.h>

#include <QtCore>
#include <QtGui>
#include <QtSql>

namespace asaal
{
	DMSMySqlConnection *dmsmysqlconnection = NULL;
	DMSMySqlConnection::DMSMySqlConnection( QDialog *parent ) : QDialog( parent )
	{
		setupUi( this );
		dmsmysqlconnection = this;

		connect( btnCheckConnection, SIGNAL( clicked() ), this, SLOT( check() ) );
		connect( btnOk, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

		btnOk->setEnabled( false );

		QDesktopWidget *desktop = qApp->desktop();
		const QRect rect = desktop->availableGeometry( desktop->primaryScreen() );
		int left = ( rect.width() - width() ) / 2;
		int top = ( rect.height() - height() ) / 2;
		setGeometry( left, top, width(), height() );
		setModal( true );

		connected = false;
	}

	DMSMySqlConnection::~DMSMySqlConnection()
	{
		dmsmysqlconnection = NULL;
	}

	void DMSMySqlConnection::closeEvent( QCloseEvent *e )
	{
		dmsmysqlconnection = NULL;
		e->accept();
	}

	void DMSMySqlConnection::check()
	{
		int port = spinBoxPort->value();
		QString host = lineEditoHost->text();
		QString user = lineEditUser->text();
		QString upwd = lineEditPassword->text();

		QSqlDatabase qsqld = QSqlDatabase::addDatabase( "QMYSQL", "available_db" );
		qsqld.setUserName( user );
		qsqld.setPassword( upwd );
		qsqld.setHostName( host );
		qsqld.setPort( port );

		if( qsqld.open() )
		{
			QSqlQuery queryDatabases( "SHOW DATABASES;", qsqld );
			if(queryDatabases.isActive())
			{
				while(queryDatabases.next())
				{					
					QSqlQuery queryDms( "SELECT USERNAME FROM " + queryDatabases.value( 0 ).toString() + ".USERS", qsqld );
					
					if( queryDms.isActive() )
					{
						comboBoxDatabase->addItem( queryDatabases.value( 0 ).toString() );
					}
				}	
			}
		}
		else
		{
			QSqlError qsqlErr = qsqld.lastError();			
			QMessageBox::critical( this, tr( "Error..."), tr("Unable to connect to server!") + "\n\n" + qsqlErr.text() );

			qsqld.close();
			QSqlDatabase::removeDatabase ( "available_db" );

			connected = false;

			return;
		}

		QSqlDatabase::removeDatabase ( "available_db" );

		connected = true;
		
		btnOk->setEnabled( true );
	}

	void DMSMySqlConnection::closeWidget()
	{
		if( connected )
		{
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
			dbsettings.setString( "MySqlConnection", "HostName", lineEditoHost->text() );
			dbsettings.setInt( "MySqlConnection", "Port", spinBoxPort->value() );
			dbsettings.save( file );

			QDialog::accept();
		}
		else
			QDialog::reject();
	}
}
