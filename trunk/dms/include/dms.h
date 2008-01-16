/***************************************************************************
 *   Copyright (C) 2007 by Alexander Saal                                  *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dllexport.h                                                     *
 *   Desc: export/import function for external call                        *
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

#ifndef DMS_H
#define DMS_H

#include <libdms.h>

#include <QtCore>
#include <QtGui>

namespace asaal 
{
	class DMSystem : public QMainWindow
	{
		Q_OBJECT

		public:
			DMSystem( const QApplication &app, QMainWindow *parent = 0L );
			~DMSystem();

			QWorkspace *ws;

		private slots:
			void login();
			void logout();

			void closeWidget();

			void creatEditGroups();
			void creatEditDocuments();
			void createEditUsers();
			void openWorkSheet();

			void createMenus();
			void createPluginMenu();
			void deactivateMenus( bool deactivate );

		protected:
			void closeEvent( QCloseEvent *e );

	private:
			int actionCount;
			QToolBar *mnuToolBar;
			QMenu	*mnuPlugin;

			QAction *acToolBarLogout,
					*acToolBarLogin,
					*acToolBarCreadEditGroups,
					*acToolBarCreadEditDoucmnets,
					*acToolBarCreadEditUsers,
					*acToolBarWorkSheet;

			QAction *acLogout,
					*acLogin,
					*acCreadEditGroups,
					*acCreadEditDoucmnets,
					*acCreadEditUsers,
					*acWorkSheet,
					*acClose;
			
			QList<QAction*> actionList;

			LibDMS *ldms;
	};
}

#endif // DAOCMT_H
