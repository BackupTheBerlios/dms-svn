package de.asaal.jdmsystem;

import com.trolltech.qt.core.QCoreApplication;
import com.trolltech.qt.core.QPoint;
import com.trolltech.qt.core.QRect;
import com.trolltech.qt.core.QSize;
import com.trolltech.qt.core.Qt.ContextMenuPolicy;
import com.trolltech.qt.gui.QAction;
import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QCloseEvent;
import com.trolltech.qt.gui.QDesktopWidget;
import com.trolltech.qt.gui.QMainWindow;
import com.trolltech.qt.gui.QMenu;
import com.trolltech.qt.gui.QPixmap;
import com.trolltech.qt.gui.QToolBar;
import com.trolltech.qt.gui.QWidget;
import com.trolltech.qt.gui.QWorkspace;

import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.iface.IMainWindow;
import de.asaal.jdmsystem.core.ui.ExceptionLogBase;
import de.asaal.jdmsystem.core.ui.UserBase;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> JDMSystemLibrary.java<br>
 * <b>Desc:</b> This main window represent all function to interact with
 * databases and more.<br>
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
public class JDMSystemBase extends QMainWindow implements IMainWindow
{
  private static JDMSystemBase    systemBase                  = null;
  private static JDMSystemLibrary systemLibrary               = null;
  private ExceptionLogBase        exceptionLogBase            = null;
  private UserBase                userBase                    = null;

  private QWorkspace              workspace                   = null;

  private QToolBar                mnuToolBar                  = null;

  private QAction                 acToolBarLogout             = null;
  private QAction                 acToolBarLogin              = null;
  private QAction                 acToolBarCreadEditGroups    = null;
  private QAction                 acToolBarCreadEditDoucmnets = null;
  private QAction                 acToolBarSearch             = null;
  private QAction                 acToolBarCreadEditUsers     = null;
  private QAction                 acToolBarWorkSheet          = null;

  private QAction                 acLogout                    = null;
  private QAction                 acLogin                     = null;
  private QAction                 acPreference                = null;
  private QAction                 acCreadEditGroups           = null;
  private QAction                 acCreadEditDoucmnets        = null;
  private QAction                 acSearch                    = null;
  private QAction                 acCreadEditUsers            = null;
  private QAction                 acWorkSheet                 = null;
  private QAction                 acErrorLog                  = null;
  private QAction                 acClose                     = null;

  public JDMSystemBase( QWidget parent, JDMSystemLibrary library )
  {
    super( parent );

    systemBase = this;
    systemLibrary = library;

    systemBase.setMinimumSize( new QSize( 800, 600 ) );

    QDesktopWidget desktop = QApplication.desktop();
    final QRect rect = desktop.availableGeometry( desktop.primaryScreen() );
    int left = ( rect.width() - systemBase.width() ) / 2;
    int top = ( rect.height() - systemBase.height() ) / 2;
    systemBase.setGeometry( left, top, systemBase.width(), systemBase.height() );

    createMenus();

    workspace = new QWorkspace( systemBase );
    setCentralWidget( workspace );

    setContextMenuPolicy( ContextMenuPolicy.CustomContextMenu );
    customContextMenuRequested.connect( this, "customContextMenuRequested( QPoint )" );
  }

  public static JDMSystemLibrary systemLibraryInstance()
  {
    return systemLibrary;
  }

  public static JDMSystemBase systemBase()
  {
    return systemBase;
  }

  @Override
  public void closeWidget()
  {
    QApplication.exit( 0 );
    QCoreApplication.exit( 0 );
  }

  @Override
  public void createActions()
  {
    try
    {
    }
    catch( Exception e )
    {
    }
  }

  @Override
  public void creatEditDocuments()
  {

  }

  @Override
  public void creatEditGroups()
  {

  }

  @Override
  public void createEditUsers()
  {
    try
    {
      userBase = UserBase.userBaseInstance();
      if( userBase == null )
      {
        userBase = new UserBase();
        workspace.addWindow( userBase.widget() );
      }

      userBase.reloadUsers();
      userBase.show();
    }
    catch( Exception e )
    {
    }
  }

  @Override
  public void createMenus()
  {
    try
    {
      QMenu mnuFile = menuBar().addMenu( tr( "&File" ) );
      acClose = mnuFile.addAction( tr( "&Close" ) );
      acClose.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/delete_16.png" ) );
      acClose.setStatusTip( tr( "Close application ..." ) );
      acClose.triggered.connect( this, "closeWidget()" );

      QMenu mnuDatabase = menuBar().addMenu( tr( "Data&base" ) );
      acLogout = mnuDatabase.addAction( tr( "L&ogout" ) );
      acLogout.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/paste_16.png" ) );
      acLogout.setStatusTip( tr( "Close session ..." ) );
      acLogout.triggered.connect( this, "logout()" );

      acLogin = mnuDatabase.addAction( tr( "&Login" ) );
      acLogin.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/paste_16.png" ) );
      acLogin.setStatusTip( tr( "Open session ..." ) );
      acLogin.triggered.connect( this, "login()" );

      mnuDatabase.addSeparator();

      acCreadEditGroups = mnuDatabase.addAction( tr( "New / Edit &Groups" ) );
      acCreadEditGroups.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/group_16.png" ) );
      acCreadEditGroups.setStatusTip( tr( "Create or edit groups ..." ) );
      acCreadEditGroups.triggered.connect( this, "creatEditGroups()" );

      acCreadEditDoucmnets = mnuDatabase.addAction( tr( "New / Edit &Documents" ) );
      acCreadEditDoucmnets.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/documents_16.png" ) );
      acCreadEditDoucmnets.setStatusTip( tr( "Create or edit documnets ..." ) );
      acCreadEditDoucmnets.triggered.connect( this, "creatEditDocuments()" );

      acCreadEditUsers = mnuDatabase.addAction( tr( "New / Edit &Users" ) );
      acCreadEditUsers.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/user_16.png" ) );
      acCreadEditUsers.setStatusTip( tr( "Create or edit users ..." ) );
      acCreadEditUsers.triggered.connect( this, "createEditUsers()" );

      mnuDatabase.addSeparator();

      acSearch = mnuDatabase.addAction( tr( "&Search documents" ) );
      acSearch.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/search_16.png" ) );
      acSearch.setStatusTip( tr( "Search documents ..." ) );
      acSearch.triggered.connect( this, "openSearch()" );

      acPreference = mnuDatabase.addAction( tr( "&Preference" ) );
      acPreference.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/preference_16.png" ) );
      acPreference.setStatusTip( tr( "Set preferences ..." ) );
      acPreference.triggered.connect( this, "openPreference()" );

      QMenu mnuView = menuBar().addMenu( tr( "&Views" ) );
      acWorkSheet = mnuView.addAction( tr( "&Open Worksheet" ) );
      acWorkSheet.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/home_16.png" ) );
      acWorkSheet.setStatusTip( tr( "Open worksheet ..." ) );
      acWorkSheet.triggered.connect( this, "openWorkSheet()" );

      QMenu mnuLog = menuBar().addMenu( tr( "&Log" ) );
      acErrorLog = mnuLog.addAction( tr( "Open &Log" ) );
      acErrorLog.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/trash_16.png" ) );
      acErrorLog.setStatusTip( tr( "Open log window ..." ) );
      acErrorLog.triggered.connect( this, "openLog()" );

      // Toolbar
      mnuToolBar = new QToolBar( tr( "Maintoolbar" ), this );
      mnuToolBar.setIconSize( new QSize( 24, 24 ) );

      acToolBarLogout = mnuToolBar.addAction( tr( "L&ogout" ) );
      acToolBarLogout.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/paste_16.png" ) );
      acToolBarLogout.setStatusTip( tr( "Close session ..." ) );
      acToolBarLogout.triggered.connect( this, "logout()" );

      acToolBarLogin = mnuToolBar.addAction( tr( "&Login" ) );
      acToolBarLogin.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/paste_16.png" ) );
      acToolBarLogin.setStatusTip( tr( "Open session ..." ) );
      acToolBarLogin.triggered.connect( this, "login()" );

      mnuToolBar.addSeparator();

      acToolBarCreadEditGroups = mnuToolBar.addAction( tr( "New / Edit &Groups" ) );
      acToolBarCreadEditGroups.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/group_16.png" ) );
      acToolBarCreadEditGroups.setStatusTip( tr( "Create or edit groups ..." ) );
      acToolBarCreadEditGroups.triggered.connect( this, "creatEditGroups()" );

      acToolBarCreadEditDoucmnets = mnuToolBar.addAction( tr( "New / Edit &Documents" ) );
      acToolBarCreadEditDoucmnets.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/documents_16.png" ) );
      acToolBarCreadEditDoucmnets.setStatusTip( tr( "Create or edit documnets ..." ) );
      acToolBarCreadEditDoucmnets.triggered.connect( this, "creatEditDocuments()" );

      acToolBarSearch = mnuToolBar.addAction( tr( "&Search documents" ) );
      acToolBarSearch.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/search_16.png" ) );
      acToolBarSearch.setStatusTip( tr( "Search documents ..." ) );
      acToolBarSearch.triggered.connect( this, "openSearch()" );

      acToolBarCreadEditUsers = mnuToolBar.addAction( tr( "New / Edit &Users" ) );
      acToolBarCreadEditUsers.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/user_16.png" ) );
      acToolBarCreadEditUsers.setStatusTip( tr( "Create or edit users ..." ) );
      acToolBarCreadEditUsers.triggered.connect( this, "createEditUsers()" );

      acToolBarWorkSheet = mnuToolBar.addAction( tr( "&Open Worksheet" ) );
      acToolBarWorkSheet.setIcon( new QPixmap( "classpath:de/asaal/jdmsystem/resource/images/menu/16/home_16.png" ) );
      acToolBarWorkSheet.setStatusTip( tr( "Open worksheet ..." ) );
      acToolBarWorkSheet.triggered.connect( this, "openWorkSheet()" );

      addToolBar( mnuToolBar );
      statusBar().show();
    }
    catch( Exception e )
    {
    }
  }

  @Override
  public void createPluginMenu()
  {

  }

  @Override
  public void deactivateMenus( boolean deactivate )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  @Override
  public void login()
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  @Override
  public void logout()
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  @Override
  public void openLog()
  {
    try
    {
      exceptionLogBase = ExceptionLogBase.exceptionLogBaseInstance();
      if( exceptionLogBase == null )
      {
        exceptionLogBase = new ExceptionLogBase();
        workspace.addWindow( exceptionLogBase.widget() );
      }
      exceptionLogBase.reloadExceptions();
      exceptionLogBase.show();
    }
    catch( Exception e )
    {
    }
  }

  @Override
  public void openPreference()
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  @Override
  public void openSearch()
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  @Override
  public void openWorkSheet()
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  protected void customContextMenuRequested( QPoint point )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  @Override
  protected void closeEvent( QCloseEvent closeEvent )
  {
    super.closeEvent( closeEvent );
  }
}
