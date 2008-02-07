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
TEMPLATE = app
DESTDIR = ../bin
DEPENDPATH += include src ui ../resource ../libdms/include ../libdms/src ../libdms/ui
INCLUDEPATH += include ui ../libdms/include ../libdms/ui
RESOURCES += ../resource/dms.qrc
CONFIG += debug thread warn_on qt
QT += sql xml

# Project Translation
TRANSLATIONS += ../resource/translation/dms_ger.ts

# Project Misc files
DISTFILES += ../resource/misc/CHANGELOG
DISTFILES += ../resource/misc/COPYING
DISTFILES += ../resource/misc/INSTALL
DISTFILES += ../resource/misc/README
DISTFILES += ../resource/misc/TODO

# Project Header
HEADERS += include/dms.h
HEADERS += include/dmsplugininterface.h

# Project Source
SOURCES += src/dms.cpp
SOURCES += src/main.cpp

# Linux settings
unix {
    TARGET = dms
    #QMAKE_POST_LINK = strip -s ../bin/dms
    TARGETDEPS += ../bin/libdms.a
    LIBS += ../bin/libdms.a
    RCC_DIR = ../build/dms/unix/rcc
    MOC_DIR += ../build/dms/unix/moc
    OBJECTS_DIR += ../build/dms/unix/obj
}

# Windows settings
win32 {
    TARGET = dms
    CONFIG += debug thread warn_on qt embed_manifest_exe
    LIBS += -llibdms -L../bin
    RC_FILE = dms.rc

    RCC_DIR = ../build/dms/win/rcc
    MOC_DIR += ../build/dms/win/moc
    OBJECTS_DIR += ../build/dms/win/obj
    UI_DIR += ../build/dms/win/ui
}

