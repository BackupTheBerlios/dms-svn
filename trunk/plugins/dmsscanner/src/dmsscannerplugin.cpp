/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmsscannerplugin.cpp                                            *
 *   Desc:                                                                 *
 *                                                                         *
 *   This file is part of DMS - Documnet Management System - Pluginsystem  *
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

#include <QtGui>
#include <QtCore>

#include "dmsscanner.h"
#include "dmsscannerplugin.h"

QPixmap DMSScannerPlugin::icon() const
{
	return QPixmap( ":/docscanner.png" );
}

QString DMSScannerPlugin::pluginName() const
{

	return QString( tr( "Scan documents" ) );
}

QString DMSScannerPlugin::pluginVersion() const
{

	return QString( "0.1.0.1" );
}

QAction *DMSScannerPlugin::action()
{
	QAction *actScan = new QAction( this );
	actScan->setText( pluginName() );
	actScan->setIcon( QIcon( ":/scanimages/images/scanimages/eye.png" ) );
	connect( actScan, SIGNAL( triggered() ), this, SLOT( showWidget() ) );

	return actScan;
}

QDialog *DMSScannerPlugin::dialog() const
{
	return NULL;
}

QWidget *DMSScannerPlugin::widget() const
{

	if ( !dmsscanner )
	{
		dmsscanner = new DMSScanner();
	}
	else
	{
		return dmsscanner;
	}

	return dmsscanner;
}

void DMSScannerPlugin::showWidget()
{
	widget()->show();
}

Q_EXPORT_PLUGIN2( dmsscannerplugin, DMSScannerPlugin )
