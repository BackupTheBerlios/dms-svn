/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmspreferences.cpp                                              *
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

#include <dmsplugininterface.h>
#include <dmsmysqlconnection.h>
#include <dmspreference.h>

#include <libdms.h>
#include <base64.h>
#include <XMLPreferences.h>

#include <QtCore>
#include <QtGui>
#include <QtSql>

DMSPreference *dmspreference = NULL;
DMSPreference::DMSPreference( LibDMS *dms, QWidget *parent ) : QWidget( parent )
{
	setupUi( this );
	dmspreference = this;

	_dms = dms;	

	connect( treeWidgetApplicationPref, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetApplicationPrefItem( QTreeWidgetItem *, int ) ) );
	connect( treeWidgetMailAddressPref, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetMailAddressPrefItem( QTreeWidgetItem *, int ) ) );
	connect( comboBoxPlugins, SIGNAL( currentIndexChanged( const QString & ) ), this, SLOT( loadPluginConfigWidget( const QString & ) ) );
	

	connect( btnAddApplication, SIGNAL( clicked() ), this, SLOT( addApplication() ) );
	connect( btnUpdateApplication, SIGNAL( clicked() ), this, SLOT( updateApplication() ) );
	connect( btnRemoveApplication, SIGNAL( clicked() ), this, SLOT( removeApplication() ) );

	connect( btnAddMailAddress, SIGNAL( clicked() ), this, SLOT( addMailAddress() ) );
	connect( btnUpdateMailAddress, SIGNAL( clicked() ), this, SLOT( updateMailAddress() ) );
	connect( btnRemoveMailAddress, SIGNAL( clicked() ), this, SLOT( removeMailAddress() ) );

	connect( btnSelectDocumentArchive, SIGNAL( clicked() ), this, SLOT( chooseDocumentArchive() ) );
	connect( btnResetDocumentCounter, SIGNAL( clicked() ), this, SLOT( resetDocumentCounter() ) );

	connect( btnCheck, SIGNAL( clicked() ), this, SLOT( checkConnection() ) );
	connect( btnSelectApplication, SIGNAL( clicked() ), this, SLOT( chooseApplication() ) );
	connect( btnApply, SIGNAL( clicked() ), this, SLOT( savePreferences() ) );
	connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

	loadPreferences();
	loadPluginPreferences();

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

	if ( application.isNull() || application.isEmpty() )
		return;

	lineEditApplication->setText( application );
}

void DMSPreference::chooseDocumentArchive()
{
	QString documentarchive = QFileDialog::getExistingDirectory( this, tr ( "Open document archive" ), QDir::homePath(), QFileDialog::DontUseNativeDialog | QFileDialog::ShowDirsOnly );

	if ( documentarchive.isNull() || documentarchive.isEmpty() )
		return;

	lineEditDocumentArchive->setText( documentarchive );
}

void DMSPreference::addApplication()
{
	QString appname = lineEditApplication->text();
	QString appextensions = comboBoxFileExtensions->currentText();

	if ( appname.isNull() || appname.isEmpty() )
	{
		showErrorMsg( tr( "You must select a application!" ) );
		return;
	}

	if ( appextensions.isNull() || appextensions.isEmpty() )
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

	if ( appItem == NULL )
	{
		showErrorMsg( tr( "No item was selected!" ) );
		return;
	}

	if ( lineEditApplication->text().isNull() || lineEditApplication->text().isEmpty() )
	{
		showErrorMsg( tr( "You must select a application!" ) );
		return;
	}

	if ( comboBoxFileExtensions->currentText().isNull() || comboBoxFileExtensions->currentText().isEmpty() )
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

	if ( appItem == NULL )
	{
		showErrorMsg( tr( "No item was selected!" ) );
		return;
	}

	switch ( QMessageBox::question( this, tr( "DMS - Preference" ), tr( "Would you delete this item?" ), QMessageBox::Yes | QMessageBox::No ) )
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

	if ( mailaddress.isNull() || mailaddress.isEmpty() )
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

	if ( appItem == NULL )
	{
		showErrorMsg( tr( "No item was selected!" ) );
		return;
	}

	if ( lineEditMailAddress->text().isNull() || lineEditMailAddress->text().isEmpty() )
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

	if ( appItem == NULL )
	{
		showErrorMsg( tr( "No item was selected!" ) );
		return;
	}

	switch ( QMessageBox::question( this, tr( "DMS - Preference" ), tr( "Would you delete this item?" ), QMessageBox::Yes | QMessageBox::No ) )
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
	// TODO Save general settings
	if ( lineEditDocumentArchive->text().isEmpty() )
	{
		showErrorMsg( tr( "You must enter a valid document archive!" ) );
		return;
	}

	_dms->insertApplicationSettings( objectName(), "General", "Documentarchive", lineEditDocumentArchive->text() );
	_dms->insertApplicationSettings( objectName(), "General", "Language", comboBoxLanguage->currentText() );

	if ( rbtnImageAsBlob->isChecked() )
	{
		_dms->insertApplicationSettings( objectName(), "General", "Scanoption", "blob" );
	}
	else if ( rbtnImageAsFile->isChecked() )
	{
		_dms->insertApplicationSettings( objectName(), "General", "Scanoption", "file" );
	}

	_dms->insertApplicationSettings( objectName(), "General", "ImageFormat", comboBoxImageFormat->currentText() );
	_dms->insertApplicationSettings( objectName(), "General", "DocCounter", QString( "%1" ).arg( spinBoxDocumentCounter->value() ) );


	// TODO Save database settings

	if ( lineEditHost->text().isEmpty() )
	{
		showErrorMsg( tr( "You must enter a valid host or ip address!" ) );
		return;
	}

	if ( spinBoxPort->value() <= 0 )
	{
		showErrorMsg( tr( "You must enter a valid port number!" ) );
		return;
	}

	if ( lineEditUser->text().isEmpty() )
	{
		showErrorMsg( tr( "You must enter a valid user name!" ) );
		return;
	}

	if ( comboBoxDatabase->currentText().isEmpty() || comboBoxDatabase->currentIndex() == -1 )
	{
		showErrorMsg( tr( "You must select a valid database!" ) );
		return;
	}

	QString file = QDir::homePath();

	QDir pref( file + "/.dms/connection" );

	if ( !pref.exists() )
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

	// TODO Save application and this file-exstansion settings
	for ( int i = 0; i < treeWidgetApplicationPref->topLevelItemCount(); i++ )
	{
		qApp->processEvents();

		appItem = treeWidgetApplicationPref->topLevelItem( i );

		QString itemApp = appItem->text( 0 );
		QString itemAppExt = appItem->text( 1 );
		_dms->insertApplicationSettings( objectName(), "File associations", itemApp, itemAppExt );
	}

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
	// TODO Load general settings
	lineEditDocumentArchive->setText( _dms->getApplicationSettings( objectName(), "General", "Documentarchive" ).toString() );

	int language = comboBoxLanguage->findText( _dms->getApplicationSettings( objectName(), "General", "Language", "English" ).toString() );
	comboBoxLanguage->setCurrentIndex( language );

	groupBoxScanOption->setEnabled( true );

	QString imgoption = _dms->getApplicationSettings( objectName(), "General", "Scanoption", "file" ).toString();
	if ( imgoption == "blob" )
	{
		rbtnImageAsBlob->setChecked( true );
	}
	else if ( imgoption == "file" )
	{
		rbtnImageAsFile->setChecked( true );
	}

	int imageformat = comboBoxImageFormat->findText( _dms->getApplicationSettings( objectName(), "General", "ImageFormat", "PNG" ).toString() );
	comboBoxImageFormat->setCurrentIndex( imageformat );

	spinBoxDocumentCounter->setValue( _dms->getApplicationSettings( objectName(), "General", "DocCounter", "1" ).toInt() );

	// TODO Load application and this file-exstansion settings
	QMap< QString, QString> appFiles = _dms->getApplicationSettings( objectName(), "File associations" );

	QMap< QString, QString>::const_iterator appIt = appFiles.begin();

	while ( appIt != appFiles.end() )
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

	while ( mailIt != mails.end() )
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

void DMSPreference::loadPluginPreferences()
{
	plugins.clear();

	comboBoxPlugins->clear();
	comboBoxPlugins->addItem( "" );

	QDir pluginsDir = QDir( QApplication::applicationDirPath() );
	pluginsDir.cd( ".dms" );
	pluginsDir.cd( "plugins" );

	// iterate over the plugin directory and load plugins if necessary ...
	foreach( QString fileName, pluginsDir.entryList( QDir::Files ) )
	{
		qApp->processEvents();

		if ( fileName.split( "." ).value( 1 ).toLower()  == "dll" || fileName.split( "." ).value( 1 ).toLower() == "so" )
		{
			QPluginLoader loader( pluginsDir.absoluteFilePath( fileName ) );
			QObject *plug = loader.instance();

			if ( plug != NULL )
			{
				dpi = qobject_cast<DMSPluginInterface *> ( plug );
				if ( dpi )
				{
					comboBoxPlugins->addItem( dpi->pluginName() );
					plugins.append( dpi );
				}
			}
		}
	}
}

void DMSPreference::loadPluginConfigWidget( const QString &text )
{
	if ( text.isNull() || text.isEmpty() )
		return;						

	if ( plugins.count() >= 1 )
	{
		for( int i = 0; i < plugins.count(); i++ )
		{
			qApp->processEvents();

			dpi = plugins.at( i );
			if ( dpi )
			{
				if ( dpi->pluginName() == text )
				{
					QWidget *configwidget = dpi->config();
					if ( configwidget )
					{
						if( (configwidget->height() <= 551) && (configwidget->width() <= 284) )
						{
							stackedWidgetPluginPreference->removeWidget( configwidget );

							QGridLayout *gridLayout = new QGridLayout( pagePlugin );
							gridLayout->addWidget( configwidget, 0, 0, 1, 1 );
							return;
						}
					}
					else
					{
						QGridLayout *gridLayout = new QGridLayout( pagePlugin );
						QLabel *lblPluginInfo = new QLabel( tr( "<b><h3>This plugin has no configuration widget.</h3></b>" ), pagePlugin );
						lblPluginInfo->setAlignment ( Qt::AlignCenter );
						gridLayout->addWidget( lblPluginInfo, 0, 0, 1, 1 );
						return;						
					}
				}
			}
		}
	}
}

void DMSPreference::checkConnection()
{
	comboBoxDatabase->clear();

	QSqlQuery queryDatabases( "SHOW DATABASES;" );

	if ( queryDatabases.isActive() )
	{
		while ( queryDatabases.next() )
		{
			qApp->processEvents();

			QSqlQuery queryDms( "SELECT USERNAME FROM " + queryDatabases.value( 0 ).toString() + ".USERS" );

			if ( queryDms.isActive() )
			{
				comboBoxDatabase->addItem( queryDatabases.value( 0 ).toString() );

				QSqlDatabase::removeDatabase ( "available_db" );
				return;
			}
		}
	}
}

void DMSPreference::resetDocumentCounter()
{
	switch ( QMessageBox::question( this, tr( "DMS - Preference" ), tr( "Are you sure you would reset the document counter?" ), QMessageBox::Yes | QMessageBox::No ) )
	{
		case QMessageBox::Yes:
			spinBoxDocumentCounter->setValue( 1 );
			break;

		case QMessageBox::No:
			return;

		default:
			return;
	}
}

void DMSPreference::closeWidget()
{
	close();
}
