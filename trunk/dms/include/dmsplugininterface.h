/*
*   Copyright (C) 2007 by Alexander Saal <alex.saal@gmx.de>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __DMS_PLUGININTERFACE_H__
#define __DMS_PLUGININTERFACE_H__

#include <QtPlugin>

// QtCore Classes

class QAction;
class QDialog;
class QString;
class QPixmap;
class QWidget;


/**
 * @author Alexander Saal <alex.saal@gmx.de>
 * @date 2008/01/14
 * @version 0.1.0
 * @since 0.1.0
 */

class DMSPluginInterface {
	
	Q_CLASSINFO( "Author", "Alexander Saal" )
	Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
	Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

	public:
		/**
		 * Konstrukor DMSPluginInterface
		 */
		virtual ~DMSPluginInterface() {}

		/**
		 * Rückgabe des Pluginicons
		 *
		 * @return	QPixmap
		 *
		 * @code
		 * QPixmap icon() {
		 *	return QPixmap();
		 * }
		 * @endcode
		 */
		virtual QPixmap icon() const = 0;

		/**
		 * Rückgabe des Pluginnamens
		 *
		 * @return	Pluginname
		 *
		 * @code
		 * QString Pluginname() {
		 *	return "Mein erstes Plugin";
		 * }
		 * @endcode
		 */
		virtual QString pluginName() const = 0;

		/**
		 * Rückgabe der Pluginversion
		 *
		 * @return	Plugin version
		 *
		 * @code
		 * QString pluginVersion() {
		 *	return "0.1.1.0";
		 * }
		 * @endcode
		 */
		virtual QString pluginVersion() const = 0;

		/**
		 * Rückgabe der QAction
		 *
		 * @return	QAction
		 *
		 * @code
		 * QAction action() {
		 *	return new QAction();
		 * }
		 * @endcode
		 */
		virtual QAction *action() const = 0;

		/**
		 * Rückgabe der Pluginversion
		 *
		 * @return	Plugin version
		 *
		 * @code
		 * QString pluginVersion() {
		 *	return "0.1.1.0";
		 * }
		 * @endcode
		 */
		virtual QDialog *dialog() const = 0;

		/**
		 * Rückgabe des QWidgets
		 *
		 * @return	QWidget
		 *
		 * @code
		 * QWidget widget() {
		 *	return new QWidget();
		 * }
		 * @endcode
		 */
		virtual QWidget *widget() const = 0;
};

Q_DECLARE_INTERFACE( DMSPluginInterface, "dms.DMSPluginInterface/0.1.0" )

#endif // __DMS_PLUGININTERFACE_H__
