package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.JDMSystemBase;
import de.asaal.jdmsystem.core.JDMSystemLibrary;
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

  private QWidget                 exceptionLogBase = null;
  private JDMSystemLibrary        systemLibrary    = null;

  private static ExceptionLogBase instance         = null;

  public ExceptionLogBase()
  {
    super();

    systemLibrary = JDMSystemBase.systemLibraryInstance();
    instance = this;

    exceptionLogBase = new QWidget();
    setupUi( exceptionLogBase );

    initialConnections();
    realoadExceptions();
  }

  @Override
  public void initialConnections()
  {
    try
    {
      btnOk.clicked.connect( this, "close()" );
      btnCancel.clicked.connect( this, "close()" );
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
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

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
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
    }
  }

  private void realoadExceptions()
  {
    try
    {

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

}
