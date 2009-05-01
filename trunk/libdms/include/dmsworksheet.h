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

#ifndef DMSWORKSHEET_H
#define DMSWORKSHEET_H

#include <dllexport.h>

#include <ui_worksheet.h>

#include <libdms.h>
#include <dmsmailaction.h>

#include <QtCore>
#include <QtGui>

class QDragEnterEvent;

class QDropEvent;

class EXPORT_ASAAL DMSWorkSheet;

#ifdef Q_OS_WIN32
extern EXPORT_ASAAL DMSWorkSheet *dmsworksheet;
#else
extern DMSWorkSheet *dmsworksheet;
#endif

/*!
* @author Alexander Saal <alex.saal@gmx.de>
* @sa http://chmaster.freeforge.net
* @date 2007/12/04
* @version 0.1.0.0
* @since 0.1.0.0
*/

class EXPORT_ASAAL DMSWorkSheet : public QWidget, public Ui::UiWorkSheetBase
{

		Q_OBJECT

		Q_CLASSINFO( "Author", "Alexander Saal" )
		Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
		Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

	public:
		DMSWorkSheet( LibDMS *dms, QWorkspace *ws, QWidget *parent = 0L );
		~DMSWorkSheet();

		static DMSWorkSheet *dmsworksheet_instance()
		{
			return dmsworksheet;
		}

	public slots:
		void loadDocuments();

	private slots:
		void newDocument();
		void openDocument();
		void deleteDocument();
		void printDocument();
		void sendMail();

		void createMenuAction();

		void treeWidgetWorkSheetItem( QTreeWidgetItem *, int );
		void treeWidgetWorkSheetMenu( QPoint );
		void showErrorMsg( const QString &error );

		QTreeWidgetItem *getGroupItem( const QString &groupname );

		void closeWidget();

	private:
		bool isDocumentAvailabel( const QString &docname );

		LibDMS *_dms;
		QWorkspace *_ws;

    QList< LibDMS::DocumentInfo* > documents;

		QTreeWidgetItem *docItem;
		QTreeWidgetItem *groupItem;

		QMenu *mnuMail;

		QAction *acNewDoc;
		QAction *acOpenDoc;
		DMSMailAction *acSendMail;
		QAction *acDeleteDoc;
		QAction *acPrintDoc;

	protected:
		void dragEnterEvent( QDragEnterEvent *event );
		void dragMoveEvent( QDragMoveEvent *event );
		void dropEvent( QDropEvent *event );
		void mousePressEvent( QMouseEvent *event );

		void closeEvent( QCloseEvent *e );

};


#endif // DMSWORKSHEET_H
