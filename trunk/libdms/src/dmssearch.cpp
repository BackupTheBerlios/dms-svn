/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmssearch.cpp                                                   *
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

#include <dmssearch.h>

#include <libdms.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	DMSSearch *dmssearch = NULL;
	DMSSearch::DMSSearch( LibDMS *dms, QWidget *parent ) : QWidget( parent )
	{
		setupUi( this );
		dmssearch = this;

		_dms = dms;

		connect( btnSearch, SIGNAL( clicked() ), this, SLOT( search() ) );
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

		_dms->clearErrorMessage();
		loadSearchPreferences();
	}

	DMSSearch::~DMSSearch()
	{
		dmssearch = NULL;
	}

	void DMSSearch::closeEvent( QCloseEvent *e )
	{
		dmssearch = NULL;
		e->accept();
	}

	void DMSSearch::search()
	{
		treeWidgetSearchDocument->clear();
		
		QString searchword = lineEditSearchWord->text();
		QString searchgroup = comboBoxSearchGroup->currentText();
		QString searchuser = comboBoxSearchUser->currentText();
		searchuser = searchuser.split( "," ).value( 1 ).trimmed() + ", " + searchuser.split( "," ).value( 0 ).trimmed();
		bool exactMatch = checkBoxSearchExactly->isChecked();

		progressBarSearch->setMaximum( documents.size() );

		int progress = 0;
		QMap<QString, QString>::const_iterator docIt = documents.begin();

		while ( docIt != documents.end() )
		{
			qApp->processEvents();

			QString uname = docIt.value().split( "#" ).value( 0 );
			QString gname = docIt.value().split( "#" ).value( 1 );
			QString docname = docIt.value().split( "#" ).value( 2 );
			QString docpath = docIt.value().split( "#" ).value( 3 );
			QString updated = docIt.value().split( "#" ).value( 4 );
			QString checkedout = docIt.value().split( "#" ).value( 5 );

			if ( uname == searchuser && gname == searchgroup )
			{
				if ( !exactMatch )
				{
					if ( docname.toLower().contains( searchword.toLower() ) ||
					        docpath.toLower().contains( searchword.toLower() ) ||
					        docpath.toLower().contains( searchword.toLower() ) ||
					        updated.toLower().contains( searchword.toLower() ) ||
					        checkedout.toLower().contains( searchword.toLower() ) )
					{
						docItem = new QTreeWidgetItem( treeWidgetSearchDocument );
						docItem->setText( 0, docname );
						docItem->setText( 1, updated );
					}
				}
				else
				{
					if ( docname.toLower() == searchword.toLower() ||
					        docpath.toLower() == searchword.toLower() ||
					        docpath.toLower() == searchword.toLower() ||
					        updated.toLower() == searchword.toLower() ||
					        checkedout.toLower() == searchword.toLower() )
					{
						docItem = new QTreeWidgetItem( treeWidgetSearchDocument );
						docItem->setText( 0, docname );
						docItem->setText( 1, updated );
					}
				}
			}

			if ( uname == searchuser && searchgroup == "*" )
			{

			}

			if ( gname == searchgroup && searchuser == "*" )
			{

			}

			if ( searchuser == "*" && searchgroup == "*" && (searchword == "*" || searchword.isEmpty() || searchword.isNull()) )
			{
				docItem = new QTreeWidgetItem( treeWidgetSearchDocument );
				docItem->setText( 0, docname );
				docItem->setText( 1, updated );
			}

			if ( searchuser == "*" )
			{

			}

			if ( searchgroup == "*" )
			{

			}


			progress++;

			progressBarSearch->setValue( progress );

			++docIt;
		}


		searchword = QString( "" );

		searchgroup = QString( "" );
		searchuser = QString( "" );
		exactMatch = false;
		progressBarSearch->setValue( 0 );
	}

	void DMSSearch::loadSearchPreferences()
	{
		documents.clear();
		columns.clear();
		groups.clear();

		documents = _dms->geDocuments();
		users = _dms->geUsers();
		groups = _dms->getGroups();

		QMap<QString, QString>::const_iterator userIt = users.begin();
		comboBoxSearchUser->clear();
		comboBoxSearchUser->addItem( "*" );

		while ( userIt != users.end() )
		{
			qApp->processEvents();

			QString uname = userIt.value().split( "#" ).value( 2 );
			uname += ", " + userIt.value().split( "#" ).value( 3 );
			comboBoxSearchUser->addItem( uname );

			++userIt;
		}

		QMap<QString, QString>::const_iterator groupIt = groups.begin();

		comboBoxSearchGroup->clear();
		comboBoxSearchGroup->addItem( "*" );

		while ( groupIt != groups.end() )
		{
			qApp->processEvents();

			QString gname = groupIt.value().split( "#" ).value( 0 );
			comboBoxSearchGroup->addItem( gname );

			++groupIt;
		}
	}

	void DMSSearch::showErrorMsg( const QString &error )
	{
		QMessageBox::critical( this, tr( "DMS - User" ), error );
	}

	void DMSSearch::closeWidget()
	{
		close();
	}
}
