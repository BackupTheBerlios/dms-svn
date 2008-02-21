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
DESTDIR = ../bin
DEPENDPATH += include src ui base64 xmlpref ../resource
INCLUDEPATH += include ui base64 xmlpref
RESOURCES += ../resource/dms.qrc
CONFIG += debug thread warn_on qt
QT += sql xml

# Project Translation
TRANSLATIONS	+= ../resource/translation/libdms_ger.ts

# Project Misc files
DISTFILES += ../resource/misc/CHANGELOG
DISTFILES += ../resource/misc/COPYING
DISTFILES += ../resource/misc/INSTALL
DISTFILES += ../resource/misc/README
DISTFILES += ../resource/misc/TODO

# Project Ui files
FORMS	+= ui/database.ui
FORMS	+= ui/document.ui
FORMS	+= ui/group.ui
FORMS	+= ui/login.ui
FORMS	+= ui/mysqlconnection.ui
FORMS	+= ui/preference.ui
FORMS	+= ui/search.ui
FORMS	+= ui/user.ui
FORMS	+= ui/worksheet.ui

# Project Header
HEADERS	+= base64/base64.h
HEADERS	+= include/dllexport.h
HEADERS	+= include/dmsdatabase.h
HEADERS	+= include/dmsdocument.h
HEADERS	+= include/dmsgroup.h
HEADERS	+= include/dmslogin.h
HEADERS	+= include/dmsmailaction.h
HEADERS	+= include/dmsmysqlconnection.h
HEADERS	+= include/dmspreference.h
HEADERS	+= include/dmssearch.h
HEADERS	+= include/dmsuser.h
HEADERS	+= include/dmsworksheet.h
HEADERS	+= include/libdms.h
HEADERS	+= xmlpref/XMLPreferences.h
HEADERS	+= xmlpref/XMLWriter.h

# Project Source
SOURCES	+= base64/base64.cpp
SOURCES	+= src/dmsdatabase.cpp
SOURCES	+= src/dmsdocument.cpp
SOURCES	+= src/dmsgroup.cpp
SOURCES	+= src/dmslogin.cpp
SOURCES	+= src/dmsmailaction.cpp
SOURCES	+= src/dmsmysqlconnection.cpp
SOURCES	+= src/dmspreference.cpp
SOURCES	+= src/dmssearch.cpp
SOURCES	+= src/dmsuser.cpp
SOURCES	+= src/dmsworksheet.cpp
SOURCES	+= src/libdms.cpp
SOURCES	+= xmlpref/XMLPreferences.cpp
SOURCES	+= xmlpref/XMLWriter.cpp

# Unix/Linux settings
unix {
	TARGET	= dms
	CONFIG += debug thread warn_on qt staticlib
	RCC_DIR	= ../build/libdms/unix/rcc
	MOC_DIR	+= ../build/libdms/unix/moc
	OBJECTS_DIR += ../build/libdms/unix/obj
	UI_DIR	+= ../build/libdms/unix/ui
}

# Windows settings
win32 {
	RCC_DIR	= ../build/libdms/win/rcc
	MOC_DIR	+= ../build/libdms/win/moc
	OBJECTS_DIR += ../build/libdms/win/obj
	UI_DIR	+= ../build/libdms/win/ui

	TARGET	= libdms
	CONFIG	+= debug thread warn_on qt dll embed_manifest_dll
	DEFINES += ASAAL_MAKEDLL
	DEFINES += WINDOWS
	RC_FILE	= libdms.rc
}