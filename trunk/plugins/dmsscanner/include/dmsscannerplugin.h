/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: dmsscannerplugin.h                                              *
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

#ifndef DMSSCANNERPLUGIN_H
#define DMSSCANNERPLUGIN_H

#include <QtCore>
#include <QtGui>

#include <dmsplugininterface.h>

class DMSPluginInterface;
class DMSScannerPlugin : public QObject, public DMSPluginInterface
{
	Q_OBJECT
	Q_INTERFACES( DMSPluginInterface )

	public:
		QPixmap icon() const;
		QString pluginName() const;
		QString pluginVersion() const;
		QAction *action();
		QDialog *dialog() const;
		QWidget *widget() const;
		QWidget *config() const;

	private slots:
		void showWidget();
};

#endif //DMSSCANNERPLUGIN_H
