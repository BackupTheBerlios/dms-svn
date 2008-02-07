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

#ifndef DMSDOCUMENT_H
#define DMSDOCUMENT_H

#include <dllexport.h>

#include <ui_document.h>

#include <libdms.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{

	class EXPORT_ASAAL DMSDocument;

#ifdef Q_OS_WIN32
	extern EXPORT_ASAAL DMSDocument *dmsdocument;
#else
	extern DMSDocument *dmsdocument;
#endif

	/*!
	* @author Alexander Saal <alex.saal@gmx.de>
	* @sa http://chmaster.freeforge.net
	* @date 2007/11/30
	* @version 0.1.0.0
	* @since 0.1.0.0
	*/

	class EXPORT_ASAAL DMSDocument : public QWidget, public Ui::UiNewEditDocumentBase
	{

			Q_OBJECT

			Q_CLASSINFO( "Author", "Alexander Saal" )
			Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
			Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

		public:
			DMSDocument( LibDMS *dms, QWidget *parent = 0L );
			~DMSDocument();

			/*!
			 * Get the external instance of @sa DMSDocument
			 */
			static DMSDocument *dmsdocument_instance()
			{
				return dmsdocument;
			}

		private slots:
			void addDocument();
			void updateDocument();
			void deleteDocument();
			void selectDocument();
			void newDocumentId();

			void loadUser();
			void loadGroups();
			void loadDocuments();

			void treeWidgetDocumentItem( QTreeWidgetItem *, int );
			void showErrorMsg( const QString &error );

			void closeWidget();

		private:
			LibDMS *_dms;

			QMap<QString, QString> users;
			QMap<QString, QString> groups;
			QMap<QString, QString> documents;

			QTreeWidgetItem *docItem;

		protected:
			void closeEvent( QCloseEvent *e );

	};
}

#endif // DMSLOGIN_H
