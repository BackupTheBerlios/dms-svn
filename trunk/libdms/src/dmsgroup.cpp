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

#include <dmsgroup.h>

#include <libdms.h>
#include <XMLPreferences.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	DMSGroup *dmsgroup = NULL;
	DMSGroup::DMSGroup( LibDMS *dms, QWidget *parent ) : QWidget( parent )
	{
		setupUi( this );
		dmsgroup = this;

		_dms = dms;

		connect( treeWidgetGroup, SIGNAL( itemClicked( QTreeWidgetItem *, int ) ), this, SLOT( treeWidgetGroupItem( QTreeWidgetItem *, int ) ) );

		connect( btGroupId, SIGNAL( clicked() ), this, SLOT( newGroupId() ) );
		connect( btnAddGroup, SIGNAL( clicked() ), this, SLOT( addGroup() ) );
		connect( btnUpdateGroup, SIGNAL( clicked() ), this, SLOT( updateGroup() ) );
		connect( btnDeleteGroup, SIGNAL( clicked() ), this, SLOT( deleteGroup() ) );
		connect( btnOk, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );
		connect( btnCancel, SIGNAL( clicked() ), this, SLOT( closeWidget() ) );

		loadGroups();
		newGroupId();

		_dms->clearErrorMessage();
	}

	DMSGroup::~DMSGroup()
	{
		dmsgroup = NULL;
		groupItem = NULL;
	}

	void DMSGroup::closeEvent( QCloseEvent *e )
	{
		QString file = QDir::homePath();

		QDir pref( file + "/.dms/settings" );
		if( !pref.exists() )
			pref.mkpath( file + "/.dms/settings" );

		file.append ( "/.dms/settings/" + objectName() + ".xml" );

		XMLPreferences widgetSettings( objectName() );
		widgetSettings.setVersion( "1.0" );
		widgetSettings.setRect( objectName(), this->rect() );
		widgetSettings.save( file );

		dmsgroup = NULL;
		groupItem = NULL;
		e->accept();
	}

	void DMSGroup::addGroup()
	{
		QString gname = lineEditGroupName->text();
		QString gdescription = lineEditGroupDescription->text();

		if( (!gname.isNull() || !gname.isEmpty()) && gname.size() >= 1 )
		{
			// check if user in the list exists
			for( int a = 0; a < treeWidgetGroup->topLevelItemCount(); a++ )
			{
				groupItem = treeWidgetGroup->topLevelItem( a );
				if( groupItem->text( 0 ) == gname )
				{
					showErrorMsg( tr( "You can not add the same group." ) );
					return;
				}
			}

			groupItem = new QTreeWidgetItem( treeWidgetGroup );
			groupItem->setText( 0, gname );
			groupItem->setText( 1, gdescription );

			_dms->insertGroup( lineEditGroupId->text(), gname, gdescription );

			if( !_dms->getErrorMessage().isEmpty() )
				showErrorMsg( _dms->getErrorMessage() );

			_dms->clearErrorMessage();

			groupItem->setSelected( false );

			lineEditGroupName->setText( "" );
			lineEditGroupDescription->setText( "" );
		}
		else
		{
			showErrorMsg( tr( "Please enter a group name." ) );
			lineEditGroupName->setFocus();
			lineEditGroupName->setSelection( 0, lineEditGroupName->text().length() );
			return;
		}

		newGroupId();
	}

	void DMSGroup::updateGroup()
	{
		QString gname = lineEditGroupName->text();
		if( (gname.isEmpty() || gname.isNull())  && gname.size() <= 0  )
		{
			showErrorMsg( tr( "Please enter a group name." ) );
			lineEditGroupName->setFocus();
			return;
		}

		groupItem = treeWidgetGroup->currentItem();
		if( groupItem == NULL )
		{
			showErrorMsg( tr( "No group was selected." ) );
			return;
		}

		groupItem->setText( 0, lineEditGroupName->text() );
		groupItem->setText( 1, lineEditGroupDescription->text() );

		_dms->updateGroup( lineEditGroupId->text(), lineEditGroupName->text(), lineEditGroupDescription->text() );

		if( !_dms->getErrorMessage().isEmpty() )
			showErrorMsg( _dms->getErrorMessage() );

		_dms->clearErrorMessage();

		groupItem->setSelected( false );

		lineEditGroupName->setText( "" );
		lineEditGroupDescription->setText( "" );

		newGroupId();
	}

	void DMSGroup::deleteGroup()
	{
		groupItem = treeWidgetGroup->currentItem();
		if( groupItem == NULL )
		{
			showErrorMsg( tr( "No group was selected." ) );
			return;
		}

		QString groupId = _dms->getGroupId( groupItem->text( 0 ) );
		_dms->deleteGroup( groupId );

		if( !_dms->getErrorMessage().isEmpty() )
			showErrorMsg( _dms->getErrorMessage() );
		else
			delete groupItem;

		_dms->clearErrorMessage();

		lineEditGroupName->setText( "" );
		lineEditGroupDescription->setText( "" );
	
		newGroupId();

	}

	void DMSGroup::newGroupId()
	{
		lineEditGroupId->setText( QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) );
	}

	void DMSGroup::loadGroups()
	{
		QMap<QString, QString> groups = _dms->getGroups();

		if( groups.size() <= 0 )
			return;

		QMap<QString, QString>::const_iterator g_it = groups.begin();
		while( g_it != groups.end() )
		{
			qApp->processEvents();
			
			QString gname = g_it.value().split("#").value(0);
			QString gdescription = g_it.value().split("#").value(1);

			groupItem = new QTreeWidgetItem( treeWidgetGroup );
			groupItem->setText( 0, gname );
			groupItem->setText( 1, gdescription );

			++g_it;
		}
	}

	void DMSGroup::treeWidgetGroupItem( QTreeWidgetItem *item, int column)
	{
		QString gname = item->text( 0 );
		QString gdescription = item->text( 1 );

		QString groupId = _dms->getGroupId( gname );
		lineEditGroupId->setText( groupId );
		lineEditGroupName->setText( gname );
		lineEditGroupDescription->setText( gdescription );
	}

	void DMSGroup::showErrorMsg( const QString &error )
	{		
		QMessageBox::critical( this, tr( "DMS - Group"), error );
	}

	void DMSGroup::closeWidget()
	{
		close();
	}
}
