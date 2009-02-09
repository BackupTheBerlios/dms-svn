package de.asaal.jdmsystem.core.ui.wizard.database;

import java.util.List;

import com.trolltech.qt.core.QObject;
import com.trolltech.qt.core.Qt.CursorShape;
import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QCursor;
import com.trolltech.qt.gui.QMessageBox;
import com.trolltech.qt.gui.QRadioButton;
import com.trolltech.qt.gui.QWizardPage;

import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.dto.DatabaseDTO;
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
  private static DatabasePage instance      = null;
  private UiDatabasePage      uiInstance    = null;
  private JDMSystemLibrary    systemLibrary = null;

  private DatabasePage()
  {
    super();

    setTitle( tr( "Database connection" ) );

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
      uiInstance.btnRefreshDatabases.clicked.connect( this, "refreshDatabases()" );
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      ex.printStackTrace();
    }

  }

  @Override
  public boolean validatePage()
  {
    QApplication.setOverrideCursor( new QCursor( CursorShape.WaitCursor ) );

    boolean valid = false;
    String errorMessage = null;
    try
    {
      systemLibrary = DatabaseWizard.databaseWizard().systemLibrary();

      if( uiInstance.rbtnChooseDatabase.isChecked() )
      {
        errorMessage = systemLibrary.isConnectionAvailabel( uiInstance.lineEditUser.text(), uiInstance.lineEditPassword.text(), uiInstance.lineEditHost.text(), String.valueOf( uiInstance.spinBoxPort.value() ), uiInstance.comboBoxDatabase.currentText() );
      }
      else if( uiInstance.rbtnNewDatabase.isChecked() )
      {
        errorMessage = systemLibrary.isConnectionAvailabel( uiInstance.lineEditUser.text(), uiInstance.lineEditPassword.text(), uiInstance.lineEditHost.text(), String.valueOf( uiInstance.spinBoxPort.value() ), null );
      }

      if( errorMessage != null && !errorMessage.isEmpty() )
      {
        QApplication.restoreOverrideCursor();

        QMessageBox.critical( this, title(), errorMessage );
        valid = false;
      }
      else
      {
        valid = true;
      }

      QApplication.restoreOverrideCursor();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      ex.printStackTrace();

      valid = false;

      QApplication.restoreOverrideCursor();
    }

    return valid;
  }

  private void registerFields()
  {
    try
    {
      registerField( "dbNew", uiInstance.rbtnNewDatabase );
      registerField( "dbChoose", uiInstance.rbtnChooseDatabase );
      registerField( "dbHost", uiInstance.lineEditHost );
      registerField( "dbPort", uiInstance.spinBoxPort );
      registerField( "dbUser", uiInstance.lineEditUser );
      registerField( "dbUserPassword", uiInstance.lineEditPassword );
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      ex.printStackTrace();
    }
  }

  protected void databaseOptionChanged( boolean checked )
  {
    try
    {
      QRadioButton rbtn = (QRadioButton)QObject.signalSender();
      if( rbtn.equals( uiInstance.rbtnNewDatabase ) )
      {
        uiInstance.labelDatabase.setEnabled( false );
        uiInstance.comboBoxDatabase.setEnabled( false );
        uiInstance.btnRefreshDatabases.setEnabled( false );
      }
      else if( rbtn.equals( uiInstance.rbtnChooseDatabase ) )
      {
        uiInstance.labelDatabase.setEnabled( true );
        uiInstance.comboBoxDatabase.setEnabled( true );
        uiInstance.btnRefreshDatabases.setEnabled( true );
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      ex.printStackTrace();
    }
  }

  protected void refreshDatabases()
  {
    try
    {
      if( validatePage() )
      {
        if( systemLibrary != null )
        {
          uiInstance.comboBoxDatabase.clear();
          List< DatabaseDTO > databases = systemLibrary.getDatabases();
          for( DatabaseDTO databaseDTO : databases )
          {
            uiInstance.comboBoxDatabase.addItem( databaseDTO.getDbDatabases() );
          }
        }
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      ex.printStackTrace();
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
      systemLibrary.createExceptions( ex, null );
      ex.printStackTrace();

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
