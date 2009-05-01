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
  if( documents.size() <= 0 || documents.isEmpty() )
    return;

	treeWidgetSearchDocument->clear();

	QString searchword = lineEditSearchWord->text();
	QString searchgroup = comboBoxSearchGroup->currentText();
	QString searchuser = comboBoxSearchUser->currentText();
	searchuser = searchuser.split( "," ).value( 1 ).trimmed() + ", " + searchuser.split( "," ).value( 0 ).trimmed();
	bool exactMatch = checkBoxSearchExactly->isChecked();

	progressBarSearch->setMaximum( documents.size() );

	int progress = 0;
  foreach( LibDMS::DocumentInfo *docInfo, documents )
	{
		qApp->processEvents();

		QString uname = docInfo->userId;
		QString gname = docInfo->groupId;
		QString docname = docInfo->docName;
		QString docpath = docInfo->docPath;
		QString updated = docInfo->update;
		QString checkedout = docInfo->checkedOut;

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

		if ( searchuser == "*" && searchgroup == "*" && ( searchword == "*" || searchword.isEmpty() || searchword.isNull() ) )
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

	comboBoxSearchUser->clear();
	comboBoxSearchUser->addItem( "*" );

  foreach( LibDMS::UserInfo *user, users ) {

    qApp->processEvents();

    comboBoxSearchUser->addItem( user->lastName + ", " + user->firstName );
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
