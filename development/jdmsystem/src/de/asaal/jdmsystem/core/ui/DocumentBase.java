package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.gui.*;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> DocumentBase.java<br>
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
public class DocumentBase extends QWidget
{
  private UiDocumentBase ui = new UiDocumentBase();

  /**
   * 
   */
  public DocumentBase()
  {
    ui.setupUi( this );
    initialConnections();
  }

  /**
   * @param parent
   */
  public DocumentBase( QWidget parent )
  {
    super( parent );
    ui.setupUi( this );
    initialConnections();
  }

  /**
   * Initialize connection
   */
  private void initialConnections()
  {
    try
    {

    }
    catch( Exception ex )
    {
      ex.printStackTrace();
    }
  }
}
