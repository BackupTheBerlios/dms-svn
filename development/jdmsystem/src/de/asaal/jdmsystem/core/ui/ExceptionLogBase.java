package de.asaal.jdmsystem.core.ui;

import java.util.List;

import com.trolltech.qt.core.Qt.ItemDataRole;
import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QTreeWidgetItem;
import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.JDMSystemBase;
import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.dto.ExceptionStackDTO;
import de.asaal.jdmsystem.core.iface.IWidget;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> ExceptionLogBase.java<br>
 * <b>Desc:</b> <br>
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
public class ExceptionLogBase extends UiExceptionLogBase implements IWidget
{

  private QWidget                   exceptionLogBase = null;
  private List< ExceptionStackDTO > exceptions       = null;
  private JDMSystemLibrary          systemLibrary    = null;

  private static ExceptionLogBase   instance         = null;

  private String                    searchFor        = null;

  public ExceptionLogBase()
  {
    super();

    systemLibrary = JDMSystemBase.systemLibraryInstance();
    instance = this;

    exceptionLogBase = new QWidget();
    setupUi( exceptionLogBase );

    initialConnections();
    reloadExceptions();
  }

  @Override
  public void initialConnections()
  {
    try
    {
      labelDate.setEnabled( false );
      dateEditFirst.setEnabled( false );
      dateEditSecond.setEnabled( false );

      btnOk.clicked.connect( this, "close()" );
      btnReload.clicked.connect( this, "search()" );
      treeWidgetExceptions.itemClicked.connect( this, "treeWidgetItemClicked( QTreeWidgetItem, Integer )" );
      comboBoxGroupBy.currentStringChanged.connect( this, "currentStringChanged( String )" );
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }

  @Override
  public void close()
  {
    try
    {
      exceptionLogBase.close();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }

  @Override
  public void show()
  {
    try
    {
      exceptionLogBase.show();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }

  /**
   * Returns a instance {@link ExceptionLogBase}
   */
  public static ExceptionLogBase exceptionLogBaseInstance()
  {
    return instance;
  }

  /**
   * Returns the internal {@link QWidget} with all visual components
   */
  public QWidget widget()
  {
    return exceptionLogBase;
  }

  protected void search()
  {
    try
    {
      if( searchFor != null && !searchFor.isEmpty() )
      {
        if( searchFor.equalsIgnoreCase( "all" ) )
        {

        }
        else
        {

        }
      }

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }

  protected void sendMail()
  {
    try
    {

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }

  /**
   * Reloads the exception from database
   */
  protected void reloadExceptions()
  {
    try
    {
      if( systemLibrary != null )
      {
        if( exceptions != null )
        {
          exceptions.clear();
        }

        exceptions = systemLibrary.getExceptions();
        treeWidgetExceptions.clear();

        for( ExceptionStackDTO exceptionStackDTO : exceptions )
        {
          QApplication.processEvents();

          QTreeWidgetItem exceptionItem = new QTreeWidgetItem( treeWidgetExceptions );
          exceptionItem.setData( 0, ItemDataRole.UserRole, exceptionStackDTO.getSqlId() );
          exceptionItem.setText( 0, exceptionStackDTO.getSqlState() );
          exceptionItem.setText( 1, exceptionStackDTO.getSqlVendorCode() );
          exceptionItem.setText( 2, exceptionStackDTO.getClassName() );
          exceptionItem.setText( 3, exceptionStackDTO.getFileName() );
          exceptionItem.setText( 4, exceptionStackDTO.getLineNumber() );
          exceptionItem.setText( 5, exceptionStackDTO.getMethodeName() );
          exceptionItem.setText( 6, exceptionStackDTO.getCreated() );
        }
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  /**
   * This signal is called if you click on item in {@link QTreeWidget}
   * 
   * @param item
   *          The item it was clicked
   * @param column
   *          The column of item
   */
  protected void treeWidgetItemClicked( QTreeWidgetItem item, Integer column )
  {
    try
    {
      Object sqlId = item.data( 0, ItemDataRole.UserRole );
      if( exceptions != null && exceptions.size() >= 1 )
      {
        for( ExceptionStackDTO exceptionStackDTO : exceptions )
        {
          if( exceptionStackDTO.getSqlId().equalsIgnoreCase( sqlId.toString() ) )
          {
            textBrowserSqlMessage.setText( "" );
            textBrowserMessage.setText( "" );
            textBrowserSqlMessage.setText( exceptionStackDTO.getSqlMessage() );
            textBrowserMessage.setText( exceptionStackDTO.getMessage() );
          }
        }
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }

  /**
   * This signal is called if you change {@link String} on {@link QComboBox}
   * 
   * @param text
   *          The changed text from combobox
   */
  protected void currentStringChanged( String text )
  {
    try
    {
      if( text != null && !text.isEmpty() )
      {
        searchFor = text;

        if( searchFor.equalsIgnoreCase( "created" ) )
        {
          labelDate.setEnabled( true );
          dateEditFirst.setEnabled( true );
          dateEditSecond.setEnabled( true );
        }
        else
        {
          labelDate.setEnabled( false );
          dateEditFirst.setEnabled( false );
          dateEditSecond.setEnabled( false );
        }
      }
      else
      {
        searchFor = "All";
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
      reloadExceptions();
    }
  }
}
