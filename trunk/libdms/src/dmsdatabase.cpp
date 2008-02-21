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

#include <dmsdatabase.h>

#include <QtCore>
#include <QtGui>

DMSDatabase *dmsdatabase = NULL;
DMSDatabase::DMSDatabase( QDialog *parent ) : QDialog( parent )
{
	setupUi( this );
	dmsdatabase = this;

	connect( btnSelect, SIGNAL( clicked() ), this, SLOT( selectDatabase() ) );
	connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

	QDesktopWidget *desktop = qApp->desktop();
	const QRect rect = desktop->availableGeometry( desktop->primaryScreen() );
	int left = ( rect.width() - width() ) / 2;
	int top = ( rect.height() - height() ) / 2;
	setGeometry( left, top, width(), height() );
	setModal( true );
}

DMSDatabase::~DMSDatabase()
{
	dmsdatabase = NULL;
}

void DMSDatabase::closeEvent( QCloseEvent *e )
{
	dmsdatabase = NULL;
	e->accept();
}

void DMSDatabase::selectDatabase()
{
	QDialog::accept();
}

void DMSDatabase::closeWidget()
{
	QDialog::reject();
}
