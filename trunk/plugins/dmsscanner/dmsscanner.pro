#/***************************************************************************
# *   Copyright (C) 2008 by Alexander Saal                                  *
# *   alex.saal@gmx.de                                                      *
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
# *   This program is distributed in the hope that it will be useful,       *
# *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
# *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
# *   GNU General Public License for more details.                          *
# *                                                                         *
# *   You should have received a copy of the GNU General Public License     *
# *   along with this program; if not, write to the                         *
# *   Free Software Foundation, Inc.,                                       *
# *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
# ***************************************************************************/

# Qt 4 Settings
TEMPLATE = lib
DESTDIR = ../../bin/plugins

DEPENDPATH += include
DEPENDPATH += sanewidget
DEPENDPATH += src
DEPENDPATH += ../../resource
DEPENDPATH += ../../dms/include

INCLUDEPATH += include
INCLUDEPATH += sanewidget
INCLUDEPATH += src
INCLUDEPATH += ../../resource
INCLUDEPATH += ../../dms/include

RESOURCES += ../../resource/dms.qrc

CONFIG += debug thread warn_on qt plugin
QT += sql xml

# Project Header
HEADERS	+= ../../dms/include/dmsplugininterface.h
HEADERS	+= include/dmsscanner.h
HEADERS	+= include/dmsscannerplugin.h

# Project Source
SOURCES	+= src/dmsscanner.cpp
SOURCES	+= src/dmsscannerplugin.cpp

# Unix/Linux settings
unix {
	TARGET	= dmsscannerplugin
	RCC_DIR	= ../../build/dmsscannerplugin/unix/rcc
	MOC_DIR	+= ../../build/dmsscannerplugin/unix/moc
	OBJECTS_DIR += ../../build/dmsscannerplugin/unix/obj
	LIBS += -L/usr/lib -lsane

	SOURCES	+= sanewidget/gamma_disp.cpp
	SOURCES	+= sanewidget/labeled_checkbox.cpp
	SOURCES	+= sanewidget/labeled_combo.cpp
	SOURCES	+= sanewidget/labeled_entry.cpp
	SOURCES	+= sanewidget/labeled_fslider.cpp
	SOURCES	+= sanewidget/labeled_gamma.cpp
	SOURCES	+= sanewidget/labeled_separator.cpp
	SOURCES	+= sanewidget/labeled_slider.cpp
	SOURCES	+= sanewidget/preview_area.cpp
	SOURCES	+= sanewidget/preview_image.cpp
	SOURCES	+= sanewidget/radio_select.cpp
	SOURCES	+= sanewidget/sane_option.cpp
	SOURCES	+= sanewidget/sane_widget.cpp

	HEADERS	+= sanewidget/gamma_disp.h
	HEADERS	+= sanewidget/labeled_checkbox.h
	HEADERS	+= sanewidget/labeled_combo.h
	HEADERS	+= sanewidget/labeled_entry.h
	HEADERS	+= sanewidget/labeled_fslider.h
	HEADERS	+= sanewidget/labeled_gamma.h
	HEADERS	+= sanewidget/labeled_separator.h
	HEADERS	+= sanewidget/labeled_slider.h
	HEADERS	+= sanewidget/preview_area.h
	HEADERS	+= sanewidget/preview_image.h
	HEADERS	+= sanewidget/radio_select.h
	HEADERS	+= sanewidget/sane_option.h
	HEADERS	+= sanewidget/sane_widget.h
}

# Windows settings
win32 {
	RCC_DIR	= ../../build/dmsscannerplugin/win/rcc
	MOC_DIR	+= ../../build/dmsscannerplugin/win/moc
	OBJECTS_DIR += ../../build/dmsscannerplugin/win/obj

	TARGET	= libdmsscannerplugin
	LIBS += -llibdms -L../bin	
	CONFIG	+= debug thread warn_on qt dll plugin embed_manifest_dll
	RC_FILE	= libdmsscanner.rc
} 
