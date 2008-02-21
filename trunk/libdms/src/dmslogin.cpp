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

#include <base64.h>

#include <dmslogin.h>
#include <libdms.h>

#include <QtCore>
#include <QtGui>

DMSLogin *dmslogin = NULL;
DMSLogin::DMSLogin( LibDMS *dms, QDialog *parent ) : QDialog( parent )
{
	setupUi( this );
	dmslogin = this;

	_dms = dms;

	connect( btnLogin, SIGNAL( clicked() ), this, SLOT( login() ) );
	connect( btnCancel, SIGNAL( clicked() ), this, SLOT( abort() ) );

	QDesktopWidget *desktop = qApp->desktop();
	const QRect rect = desktop->availableGeometry( desktop->primaryScreen() );
	int left = ( rect.width() - width() ) / 2;
	int top = ( rect.height() - height() ) / 2;
	setGeometry( left, top, width(), height() );
	setModal( true );

	_dms->clearErrorMessage();
}

DMSLogin::~DMSLogin()
{
	dmslogin = NULL;
}

void DMSLogin::closeEvent( QCloseEvent *e )
{
	dmslogin = NULL;
	e->accept();
}

void DMSLogin::login()
{
	if ( _dms != NULL )
	{
		if ( lineEditUserName->text().isEmpty() )
		{
			QMessageBox::critical( this, tr( "DMS" ), tr( "You must enter a valid user name." ) );
			return;
		}

		if ( lineEditUserPassword->text().isEmpty() )
		{
			QMessageBox::critical( this, tr( "DMS" ), tr( "Passwordfield can not be empty." ) );
			return;
		}

		QString uid = _dms->getUserId( lineEditUserName->text() );

		QString upwd = Base64::encode( QVariant( lineEditUserPassword->text() ).toByteArray() );

		if ( !_dms->login( uid, upwd ) )
		{
			QMessageBox::critical( this, tr( "DMS" ), tr( "No user was found." ) );
			upwd.clear();
			return;
		}

		upwd.clear();

		_dms->loggedUser = lineEditUserName->text();

		dmslogin = NULL;

		QDialog::accept();
	}
}

void DMSLogin::abort()
{
	dmslogin = NULL;
	QDialog::reject();
}
