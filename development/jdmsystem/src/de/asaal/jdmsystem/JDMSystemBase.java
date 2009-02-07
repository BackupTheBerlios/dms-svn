package de.asaal.jdmsystem;

import com.trolltech.qt.gui.QAction;
import com.trolltech.qt.gui.QMainWindow;
import com.trolltech.qt.gui.QMenu;
import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.core.JDMSystemLibrary;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> JDMSystemLibrary.java<br>
 * <b>Desc:</b> This class represent all global function from interface to
 * interact with database.<br>
 * <br>
 * This file is part of DMS - Document Management System<br>
 * <br>
 * This program is free software; you can redistribute it and/or modify<br>
 * it under the terms of the GNU General Public License as published by<br>
 * the Free Software Foundation; either version 2 of the License, or<br>
 * (at your option) any later version.<br>
 * <br>
 * This program is distributed in the hope that it will be useful,<br>
 * but WITHOUT ANY WARRANTY; without even the implied warranty of<br>
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the<br>
 * GNU General Public License for more details.<br>
 * <br>
 * You should have received a copy of the GNU General Public License<br>
 * along with this program; if not, write to the<br>
 * Free Software Foundation, Inc.,<br>
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.<br>
 */
public class JDMSystemBase extends QMainWindow
{
  private QMenu                   fileMenu;
  private QAction                 exitAct;
  private static JDMSystemLibrary libraryInstance = null;

  public JDMSystemBase( QWidget parent, JDMSystemLibrary library )
  {
    super( parent );
    createActions();
    createMenus();

    libraryInstance = library;
  }

  public static JDMSystemLibrary systemLibraryInstance()
  {
    return libraryInstance;
  }

  private void createActions()
  {
    exitAct = new QAction( tr( "E&xit" ), this );
    exitAct.setShortcut( tr( "Ctrl+Q" ) );
    exitAct.setStatusTip( tr( "Exit the application" ) );
    exitAct.triggered.connect( this, "close()" );
  }

  private void createMenus()
  {
    fileMenu = menuBar().addMenu( tr( "&File" ) );
    fileMenu.addAction( exitAct );
  }
}
