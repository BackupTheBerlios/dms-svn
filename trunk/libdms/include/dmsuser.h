/***************************************************************************
 *   Copyright (C) 2007 by Alexander Saal                                  *
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

#ifndef DMSUSER_H
#define DMSUSER_H

#include <dllexport.h>

#include <ui_user.h>

#include <libdms.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	class EXPORT_ASAAL DMSUser;

	#ifdef Q_OS_WIN32
		extern EXPORT_ASAAL DMSUser *dmsuser;
	#else
		extern DMSUser *dmsuser;
	#endif

	/*!
	* @author Alexander Saal <alex.saal@gmx.de>
	* @sa http://chmaster.freeforge.net
	* @date 2007/11/30
	* @version 0.1.0.0
	* @since 0.1.0.0
	*/
	class EXPORT_ASAAL DMSUser : public QWidget, public Ui::UiNewEditUserBase {

		Q_OBJECT

		Q_CLASSINFO("Author", "Alexander Saal")
		Q_CLASSINFO("EMAIL", "alex.saal@gmx.de")
		Q_CLASSINFO("URL", "http://chmaster.freeforge.net")

		public:
			DMSUser( LibDMS *dms, QWidget *parent = 0L );
			~DMSUser();

			/*!
			 * Get the external instance of @sa DMSDocument
			 */
			static DMSUser *dmsuser_instance() { return dmsuser; }

		private slots:
			void addUser();
			void updateUser();
			void deleteUser();
			void newUserId();

			void loadUser();

			void treeWidgetUserItem( QTreeWidgetItem *, int );
			void showErrorMsg( const QString &error );

			void closeWidget();

		private:
			LibDMS *_dms;

			QTreeWidgetItem *userItem;

		protected:
			void closeEvent( QCloseEvent *e );

	};
}

#endif // DMSUSER_H
