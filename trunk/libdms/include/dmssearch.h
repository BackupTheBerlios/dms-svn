/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmssearch.h                                                     *
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

#ifndef DMSSEARCH_H
#define DMSSEARCH_H

#include <dllexport.h>

#include <ui_search.h>

#include <libdms.h>

#include <QtCore>
#include <QtGui>

class EXPORT_ASAAL DMSSearch;

#ifdef Q_OS_WIN32
extern EXPORT_ASAAL DMSSearch *dmssearch;
#else
extern DMSSearch *dmssearch;
#endif

/*!
* @author Alexander Saal <alex.saal@gmx.de>
* @sa http://chmaster.freeforge.net
* @date 2008/02/08
* @version 0.1.0.0
* @since 0.1.0.0
*/

class EXPORT_ASAAL DMSSearch : public QWidget, public Ui::UiSearchBase
{

		Q_OBJECT

		Q_CLASSINFO( "Author", "Alexander Saal" )
		Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
		Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

	public:
		DMSSearch( LibDMS *dms, QWidget *parent = 0L );
		~DMSSearch();

		/*!
		 * Get the external instance of @sa DMSSearch
		 */
		static DMSSearch *dmsserach_instance()
		{
			return dmssearch;
		}

	private slots:
		void search();
		void loadSearchPreferences();

		void showErrorMsg( const QString &error );

		void closeWidget();

	private:
		LibDMS *_dms;

		QMap<QString, QString> documents;
    QList< LibDMS::UserInfo * > users;
		QMap<QString, QString> groups;
		QStringList columns;

		QTreeWidgetItem *docItem;

	protected:
		void closeEvent( QCloseEvent *e );

};

#endif // DMSSEARCH_H
