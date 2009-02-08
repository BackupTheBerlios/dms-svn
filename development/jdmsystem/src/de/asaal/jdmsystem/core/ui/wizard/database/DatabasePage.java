package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.QSignalEmitter;
import com.trolltech.qt.core.QObject;
import com.trolltech.qt.gui.QRadioButton;
import com.trolltech.qt.gui.QWizardPage;

import de.asaal.jdmsystem.core.ui.wizard.DatabaseWizard;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> DatabasePage.java<br>
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
public class DatabasePage extends QWizardPage
{
  private static DatabasePage instance   = null;
  private UiDatabasePage      uiInstance = null;

  private DatabasePage()
  {
    super();

    setTitle( tr( "Database" ) );
    setSubTitle( tr( "Select as first a opion and then mak your settings. You must set a host, port and a user. Password are optional." ) );

    uiInstance = new UiDatabasePage();
    uiInstance.setupUi( this );
    instance = this;

    initialConnections();
    registerFields();
  }

  private void initialConnections()
  {
    try
    {
      uiInstance.rbtnNewDatabase.toggled.connect( this, "databaseOptionChanged( boolean )" );
      uiInstance.rbtnChooseDatabase.toggled.connect( this, "databaseOptionChanged( boolean )" );
    }
    catch( Exception e )
    {
      // TODO: handle exception
    }

  }

  private void registerFields()
  {
    try
    {
      registerField( "dbNew", uiInstance.rbtnNewDatabase );
      registerField( "dbChoose", uiInstance.rbtnChooseDatabase );
      registerField( "dbHost*", uiInstance.lineEditHost );
      registerField( "dbPort", uiInstance.spinBoxPort );
      registerField( "dbUser*", uiInstance.lineEditUser );
      registerField( "dbUserPassword", uiInstance.lineEditPassword );
    }
    catch( Exception ex )
    {
    }
  }

  protected void databaseOptionChanged( boolean checked )
  {
    try
    {
      QRadioButton rbtn = (QRadioButton)QObject.signalSender();
      if(rbtn.equals( uiInstance.rbtnNewDatabase ) )
      {
      }
      else if(rbtn.equals( uiInstance.rbtnChooseDatabase ) )
      {
      }
    }
    catch( Exception e )
    {
      // TODO: handle exception
    }
  }
  
  public String fieldWidgetValue( String fieldName )
  {
    try
    {
      if( fieldName != null && !fieldName.isEmpty() )
      {
        if( fieldName.equalsIgnoreCase( "database" ) )
        {
          return uiInstance.comboBoxDatabase.currentText();
        }
      }

      return null;
    }
    catch( Exception ex )
    {
      return null;
    }
  }

  public static DatabasePage databasePage()
  {
    if( instance != null )
    {
      return instance;
    }
    else
    {
      instance = new DatabasePage();
      return instance;
    }
  }

  @Override
  public int nextId()
  {
    return DatabaseWizard.PAGE_FINISH;
  }
}
