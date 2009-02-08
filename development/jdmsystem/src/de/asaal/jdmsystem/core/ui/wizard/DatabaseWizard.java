package de.asaal.jdmsystem.core.ui.wizard;

import com.trolltech.qt.gui.QWidget;
import com.trolltech.qt.gui.QWizard;

import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.ui.wizard.database.DatabasePage;
import de.asaal.jdmsystem.core.ui.wizard.standard.FinishPage;
import de.asaal.jdmsystem.core.ui.wizard.standard.WelcomePage;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> DatabaseWizard.java<br>
 * <b>Desc:</b><br>
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
public class DatabaseWizard extends QWizard
{
  private static DatabaseWizard databaseWizard = null;
  private WelcomePage           welcomePage    = null;
  private DatabasePage          databasePage   = null;
  private FinishPage            finishPage     = null;
  private JDMSystemLibrary      systemLibrary  = null;

  /**
   * Display welcome page
   */
  public static int             PAGE_WELCOME   = 0;

  /**
   * Display database selection page
   */
  public static int             PAGE_DATABASE  = 1;

  /**
   * Display finish page
   */
  public static int             PAGE_FINISH    = 2;

  private DatabaseWizard( QWidget parent )
  {
    super( parent );

    databaseWizard = this;
    registerPages();
  }

  private void registerPages()
  {
    try
    {
      welcomePage = WelcomePage.welcomePage();
      databasePage = DatabasePage.databasePage();
      finishPage = FinishPage.finishPage();

      setPage( PAGE_WELCOME, welcomePage );
      setPage( PAGE_DATABASE, databasePage );
      setPage( PAGE_FINISH, finishPage );
      setStartId( PAGE_WELCOME );
    }
    catch( Exception ex )
    {
    }
  }

  @Override
  public void accept()
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Return instance of {@link DatabaseWizard}. If instance null it create new
   * instance otherwise it returns available instance.
   */
  public static DatabaseWizard databaseWizard()
  {
    if( databaseWizard != null )
    {
      return databaseWizard;
    }
    else
    {
      databaseWizard = new DatabaseWizard( null );
      return databaseWizard;
    }
  }

  public void setSystemLibrary( JDMSystemLibrary systemLibrary )
  {
    this.systemLibrary = systemLibrary;
  }
}
