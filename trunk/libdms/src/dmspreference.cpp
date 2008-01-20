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

		connect( btnAdd, SIGNAL( clicked() ), this, SLOT( addApplication() ) );
		connect( btnUpdate, SIGNAL( clicked() ), this, SLOT( updateApplication() ) );
		connect( btnRemove, SIGNAL( clicked() ), this, SLOT( removeApplication() ) );
		connect( btnOk, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );		
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );
	}

	DMSPreference::~DMSPreference()
	{
		dmspreference = NULL;
	}

	void DMSPreference::addApplication()
	{
	}

	void DMSPreference::updateApplication()
	{
	}

	void DMSPreference::removeApplication()
	{
	}

	void DMSPreference::treeWidgetApplicationPrefItem( QTreeWidgetItem *item, int column )
	{
	}

	void DMSUser::showErrorMsg( const QString &error )
	{
		QMessageBox::critical( this, tr( "DMS - Preference"), error );
	}

	void DMSUser::closeWidget()
	{
		close();
	}
}
