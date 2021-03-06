/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmspreferences.h                                                *
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

#ifndef DMSPREFERENCE_H
#define DMSPREFERENCE_H

#include <QtCore>
#include <QtGui>

#include <dllexport.h>
#include <ui_preference.h>

#include <dmsplugininterface.h>
#include <libdms.h>

class EXPORT_ASAAL DMSPreference;

#ifdef Q_OS_WIN32
	extern EXPORT_ASAAL DMSPreference *dmspreference;
#else
	extern DMSPreference *dmspreference;
#endif

/*!
* @author Alexander Saal <alex.saal@gmx.de>
* @sa http://chmaster.freeforge.net
* @date 2008/01/20
* @version 0.1.0.0
* @since 0.1.0.0
*/

class EXPORT_ASAAL DMSPreference : public QWidget, public Ui::UiPreferenceBase
{
		Q_OBJECT

		Q_CLASSINFO( "Author", "Alexander Saal" )
		Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
		Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

	public:
		DMSPreference( LibDMS *dms, QWidget *parent = 0L );
		~DMSPreference();

		/*! Get the external instance of @sa DMSPreference */
		static DMSPreference *dmspreference_instance() { return dmspreference; }

	private slots:
		void chooseApplication();
		void chooseDocumentArchive();

		void addApplication();
		void updateApplication();
		void removeApplication();

		void addMailAddress();
		void updateMailAddress();
		void removeMailAddress();

		void treeWidgetApplicationPrefItem( QTreeWidgetItem *, int );
		void treeWidgetMailAddressPrefItem( QTreeWidgetItem *, int );

		void showErrorMsg( const QString &error );

		void savePreferences();

		void loadPreferences();
		void loadPluginPreferences();
		void loadPluginConfigWidget( const QString & );

		void checkConnection();
		void resetDocumentCounter();
		void closeWidget();

	private:
		LibDMS *_dms;
		DMSPluginInterface *dpi;
		QList< DMSPluginInterface * > plugins;

		QTreeWidgetItem *appItem;

	protected:
		void closeEvent( QCloseEvent *e );

};

#endif // DMSPREFERENCE_H
