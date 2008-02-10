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
		QString searchword = lineEditSearchWord->text();
		QString searchgroup = comboBoxSearchGroup->currentText();
		QString searchcolumn = comboBoxSearchColumn->currentText();
		QString searchuser = comboBoxSearchUser->currentText();
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

			// TODO add code here for search documents in the list and display it in the QTreeWidget
			
			

			progress++;
			progressBarSearch->setValue( progress );

			++docIt;
		}


		searchword = QString( "" );

		searchgroup = QString( "" );
		searchcolumn = QString( "" );
		searchuser = QString( "" );
		exactMatch = false;
	}

	void DMSSearch::loadSearchPreferences()
	{
		tabelColumns.clear();
		documents.clear();
		columns.clear();
		groups.clear();

		documents = _dms->geDocuments();
		users = _dms->geUsers();
		groups = _dms->getGroups();
		tabelColumns = _dms->getTabelColumns( LibDMS::DOCUMENTS );

		if ( tabelColumns.size() <= 0 )
		{
			if ( !_dms->getErrorMessage().isNull() || !_dms->getErrorMessage().isEmpty() )
			{
				showErrorMsg( _dms->getErrorMessage() );
				_dms->clearErrorMessage();
				return;
			}

			showErrorMsg( tr( "No columns was found!" ) );

			return;
		}

		QMap<QString, QString>::const_iterator userIt = users.begin();

		while ( userIt != users.end() )
		{
			qApp->processEvents();

			QString uname = userIt.value().split( "#" ).value( 2 );
			uname += ", " + userIt.value().split( "#" ).value( 3 );
			comboBoxSearchUser->addItem( uname );

			++userIt;
		}

		QMap<QString, QString>::const_iterator groupIt = groups.begin();

		while ( groupIt != groups.end() )
		{
			qApp->processEvents();

			QString gname = groupIt.value().split( "#" ).value( 0 );
			comboBoxSearchGroup->addItem( gname );

			++groupIt;
		}

		QMap<QString, QStringList>::const_iterator colIt = tabelColumns.begin();

		while ( colIt != tabelColumns.end() )
		{
			qApp->processEvents();

			columns = QStringList( colIt.value() );

			for ( int i = 0; i < columns.size(); i++ )
			{
				qApp->processEvents();

				QString column = columns.value( i );
				comboBoxSearchColumn->addItem( column );
			}

			++colIt;
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
