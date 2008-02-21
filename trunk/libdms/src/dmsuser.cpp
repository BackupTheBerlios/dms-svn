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

#include <dmsuser.h>

#include <libdms.h>
#include <XMLPreferences.h>

#include <base64.h>

#include <QtCore>
#include <QtGui>

DMSUser *dmsuser = NULL;
DMSUser::DMSUser( LibDMS *dms, QWidget *parent ) : QWidget( parent )
{
	setupUi( this );
	dmsuser = this;

	_dms = dms;

	connect( treeWidgetUser, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetUserItem( QTreeWidgetItem *, int ) ) );

	connect( btnUserId, SIGNAL( clicked() ), this, SLOT( newUserId() ) );
	connect( btnAddUser, SIGNAL( clicked() ), this, SLOT( addUser() ) );
	connect( btnUpdateUser, SIGNAL( clicked() ), this, SLOT( updateUser() ) );
	connect( btnDeleteUser, SIGNAL( clicked() ), this, SLOT( deleteUser() ) );
	connect( btnOk, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );
	connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

	lineEditUserId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );

	loadUser();

	_dms->clearErrorMessage();
}

DMSUser::~DMSUser()
{
	dmsuser = NULL;
}

void DMSUser::closeEvent( QCloseEvent *e )
{
	QString file = QDir::homePath();

	QDir pref( file + "/.dms/settings" );

	if ( !pref.exists() )
		pref.mkpath( file + "/.dms/settings" );

	file.append ( "/.dms/settings/" + objectName() + ".xml" );

	XMLPreferences widgetSettings( objectName() );

	widgetSettings.setVersion( "1.0" );

	widgetSettings.setRect( objectName(), this->rect() );

	widgetSettings.save( file );

	dmsuser = NULL;

	e->accept();
}

void DMSUser::addUser()
{
	QString fname = lineEditUserFirstName->text();
	QString lname = lineEditUserLastName->text();
	QString username = lineEditUserName->text();
	QString userpwd = lineEditUserPassword->text();
	QString userpwd_confirm = lineEditUserPasswordConfirm->text();

	if ( fname.isNull() || fname.isEmpty() )
	{
		showErrorMsg( tr( "Please enter first name for this user." ) );
		lineEditUserFirstName->setFocus();
		lineEditUserFirstName->setSelection( 0, lineEditUserFirstName->text().length() );
		return;
	}
	else if ( lname.isNull() || lname.isEmpty() )
	{
		showErrorMsg( tr( "Please enter last name for this user." ) );
		lineEditUserLastName->setFocus();
		lineEditUserLastName->setSelection( 0, lineEditUserLastName->text().length() );
		return;
	}
	else if ( username.isNull() || username.isEmpty() )
	{
		showErrorMsg( tr( "Please enter user name." ) );
		lineEditUserName->setFocus();
		lineEditUserName->setSelection( 0, lineEditUserName->text().length() );
		return;
	}
	else if ( userpwd != userpwd_confirm )
	{
		showErrorMsg( tr( "The password for this user is not correct." ) );
		lineEditUserPasswordConfirm->setFocus();
		lineEditUserPasswordConfirm->setSelection( 0, lineEditUserPasswordConfirm->text().length() );
		return;
	}

	// check if user in the list exists
	for ( int a = 0; a < treeWidgetUser->topLevelItemCount(); a++ )
	{
		userItem = treeWidgetUser->topLevelItem( a );

		if ( userItem->text( 0 ) == username )
		{
			showErrorMsg( tr( "You can not add the same user." ) );
			return;
		}
	}

	QString pwd;

	if ( !userpwd.isEmpty() )
	{
		// check is password length >= 6
		if ( ( userpwd.length() >= 6 ) && ( userpwd_confirm.length() >= 6 ) )
		{
			// encode password
			pwd = Base64::encode( QVariant( userpwd ).toByteArray() );

			// insert user with decoded password
			_dms->insertUser( lineEditUserId->text(), username, pwd, fname, lname );
		}
		else if ( ( userpwd.length() < 6 ) || ( userpwd_confirm.length() < 6 ) )
		{
			showErrorMsg( tr( "The password for this user is to short, min. 6 character." ) );
			lineEditUserPasswordConfirm->setFocus();
			lineEditUserPasswordConfirm->setSelection( 0, lineEditUserPasswordConfirm->text().length() );
			return;
		}
	}
	else
		_dms->insertUser( lineEditUserId->text(), username, "", fname, lname );

	if ( !_dms->getErrorMessage().isEmpty() )
	{
		showErrorMsg( _dms->getErrorMessage() );

		// clear decoded password
		pwd.clear();
		return;
	}

	// add user to the list
	userItem = new QTreeWidgetItem( treeWidgetUser );

	userItem->setText( 0, username );

	userItem->setText( 1, pwd );

	userItem->setText( 2, fname );

	userItem->setText( 3, lname );

	// clear decoded password
	pwd.clear();

	// clear all relevant datas
	fname = "";

	lname = "";

	username = "";

	userpwd = "";

	userpwd_confirm = "";

	lineEditUserFirstName->setText( "" );

	lineEditUserLastName->setText( "" );

	lineEditUserName->setText( "" );

	lineEditUserPassword->setText( "" );

	lineEditUserPasswordConfirm->setText( "" );

	// create new user id
	lineEditUserId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );
}

void DMSUser::updateUser()
{
	userItem = treeWidgetUser->currentItem();

	if ( userItem == NULL )
	{
		showErrorMsg( tr( "No user was selected." ) );
		return;
	}

	userItem->setText( 0, lineEditUserName->text() );

	userItem->setText( 2, lineEditUserFirstName->text() );
	userItem->setText( 3, lineEditUserLastName->text() );

	QString pwd = "";

	if ( !lineEditUserPassword->text().isNull() || lineEditUserPassword->text().isEmpty() )
	{
		pwd = Base64::encode( QVariant( lineEditUserPassword->text() ).toByteArray() );

		userItem->setText( 1, pwd );
	}

	_dms->updateUser( lineEditUserId->text(), lineEditUserName->text(), pwd, lineEditUserFirstName->text(), lineEditUserLastName->text() );

	pwd.clear();
	lineEditUserFirstName->setText( "" );
	lineEditUserLastName->setText( "" );
	lineEditUserName->setText( "" );
	lineEditUserPassword->setText( "" );
	lineEditUserPasswordConfirm->setText( "" );

	lineEditUserId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );
}

void DMSUser::deleteUser()
{
	userItem = treeWidgetUser->currentItem();

	if ( userItem == NULL )
	{
		showErrorMsg( tr( "No user was selected." ) );
		return;
	}

	QString userId = _dms->getUserId( userItem->text( 0 ) );

	_dms->deleteUser( userId, userItem->text( 0 ) );

	lineEditUserFirstName->setText( "" );
	lineEditUserLastName->setText( "" );
	lineEditUserName->setText( "" );
	lineEditUserPassword->setText( "" );
	lineEditUserPasswordConfirm->setText( "" );

	lineEditUserId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );

	delete userItem;
}

void DMSUser::newUserId()
{
	lineEditUserId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );
}

void DMSUser::loadUser()
{
	QMap<QString, QString> users = _dms->geUsers();

	if ( users.size() <= 0 )
		return;

	QMap<QString, QString>::const_iterator u_it = users.begin();

	while ( u_it != users.end() )
	{
		qApp->processEvents();

		QString uname = u_it.value().split( "#" ).value( 0 );
		QString upwd = u_it.value().split( "#" ).value( 1 );
		QString fname = u_it.value().split( "#" ).value( 2 );
		QString lname = u_it.value().split( "#" ).value( 3 );

		userItem = new QTreeWidgetItem( treeWidgetUser );
		userItem->setText( 0, uname );
		userItem->setText( 1, upwd );
		userItem->setText( 2, fname );
		userItem->setText( 3, lname );

		++u_it;
	}
}

void DMSUser::treeWidgetUserItem( QTreeWidgetItem *item, int column )
{
	QString username = item->text( 0 );
	QString userpwd = item->text( 1 );
	QString userpwd_confirm = userpwd;
	QString fname = item->text( 2 );
	QString lname = item->text( 3 );

	QString userId = _dms->getUserId( username );
	lineEditUserId->setText( userId );
	lineEditUserFirstName->setText( fname );
	lineEditUserLastName->setText( lname );
	lineEditUserName->setText( username );
	lineEditUserPassword->setText( userpwd );
	lineEditUserPasswordConfirm->setText( userpwd_confirm );
}

void DMSUser::showErrorMsg( const QString &error )
{
	QMessageBox::critical( this, tr( "DMS - User" ), error );
}

void DMSUser::closeWidget()
{
	close();
}
