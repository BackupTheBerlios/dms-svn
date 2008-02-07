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

#ifndef DMSLOGIN_H
#define DMSLOGIN_H

#include <dllexport.h>

#include <ui_login.h>

#include <libdms.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{

	class EXPORT_ASAAL DMSLogin;

#ifdef Q_OS_WIN32
	extern EXPORT_ASAAL DMSLogin *dmslogin;
#else
	extern DMSLogin *dmslogin;
#endif

	/*!
	* @author Alexander Saal <alex.saal@gmx.de>
	* @sa http://chmaster.freeforge.net
	* @date 2007/11/30
	* @version 0.1.0.0
	* @since 0.1.0.0
	*/

	class EXPORT_ASAAL DMSLogin : public QDialog, public Ui::UiLoginBase
	{

			Q_OBJECT

			Q_CLASSINFO( "Author", "Alexander Saal" )
			Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
			Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

		public:
			DMSLogin( LibDMS *dms, QDialog *parent = 0L );
			~DMSLogin();

			/*!
			 * Get the external instance of @sa DMSLogin
			 */
			static DMSLogin *dmslogin_instance()
			{
				return dmslogin;
			}

		private slots:
			void login();
			void abort();

		private:
			LibDMS *_dms;

		protected:
			void closeEvent( QCloseEvent *e );

	};
}

#endif // DMSLOGIN_H
