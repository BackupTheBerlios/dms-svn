/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
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

#ifndef DMSSCANNER_H
#define DMSSCANNER_H

#include <QtCore>
#include <QtGui>

#ifdef Q_OS_WIN32
#else
#include <sane_widget.h>
#endif

#include <libdms.h>

class DMSScanner;
extern DMSScanner *dmsscanner;

/*!
* @author Alexander Saal <alex.saal@gmx.de>
* @sa http://chmaster.freeforge.net
* @date 2008/02/21
* @version 0.1.0.1
* @since 0.1.0.1
*/
class DMSScanner : public QWidget
{
		Q_OBJECT

		Q_CLASSINFO( "Author", "Alexander Saal" )
		Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
		Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

	public:
		DMSScanner( QWidget *parent = 0L );
		~DMSScanner();

		/*!
		 * Get the external instance of @sa DMSScanner
		 */
		static DMSScanner *dmsdocument_instance() {	return dmsscanner; }

	private slots:
		void initScan();
		void scanStart();
		void scanEnd();
		void scanFailed();
		void imageReady();

		void showErrorMsg( const QString &error );

	private:
		QString documentarchive;
		LibDMS *_dms;

#ifdef Q_OS_WIN32
#else
		QProgressDialog *m_progressDialog;
		SaneWidget *m_sanew;
#endif
};


#endif // DMSSCANNER_H
