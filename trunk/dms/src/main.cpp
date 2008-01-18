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

#include "dms.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>

using namespace asaal;

int main( int argc, char **argv )
{
	QApplication app( argc, argv );
	QCoreApplication::addLibraryPath( QCoreApplication::applicationDirPath() );

	QTranslator dmsTranslator;
	QTranslator libDmsTranslator;
	QString dmsTrFile = QString( "" );
	dmsTrFile = ":/misc/translation/dms_ger.qm";

	dmsTranslator.load ( dmsTrFile );
	app.installTranslator ( &dmsTranslator );

	QString libDmsTrFile = QString( "" );
	libDmsTrFile = ":/misc/translation/libdms_ger.qm";

	libDmsTranslator.load ( libDmsTrFile );
	app.installTranslator ( &libDmsTranslator );

	QFile f( QString( ":/misc/misc/default.qss" ) );
	if( !f.open( QIODevice::ReadOnly | QIODevice::Text ) )
	{
		DMSystem *dms = new DMSystem( app );
		dms->show();

		app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
		return app.exec();
	}

	QString defStayle = f.readAll();
	f.close();

	app.setStyleSheet( defStayle );

	DMSystem *dms = new DMSystem( app );
	dms->show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}