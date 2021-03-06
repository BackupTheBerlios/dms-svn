package de.asaal.jdmsystem;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QMainWindow;
import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.ui.wizard.DatabaseWizard;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> Main.java<br>
 * <b>Desc:</b> This main class calls the {@link QMainWindow}<br>
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
public class Main extends QWidget
{
  public static void main( String[] args )
  {
    try
    {
      QApplication.initialize( args );

      Properties properties = new Properties();
      FileInputStream inputStream = null;
      DatabaseWizard databaseWizard = null;
      JDMSystemLibrary systemLibrary = null;
      JDMSystemBase systemBase = null;

      if( new File( "properties/mysql.properties" ).exists() )
      {
        inputStream = new FileInputStream( "properties/mysql.properties" );
        properties.load( inputStream );

        JDMSystemLibrary.setHost( properties.getProperty( "mysql_host", "localhost" ) );
        JDMSystemLibrary.setPort( Integer.parseInt( properties.getProperty( "mysql_port", "3306" ) ) );
        JDMSystemLibrary.setDatabase( "mysql" );
        JDMSystemLibrary.setUsername( properties.getProperty( "mysql_username", "root" ) );
        JDMSystemLibrary.setPassword( JDMSystemLibrary.decodeUserPwd( properties.getProperty( "mysql_password", "" ) ) );

        systemLibrary = new JDMSystemLibrary();
        properties = null;
      }
      else
      {
        databaseWizard = DatabaseWizard.databaseWizard();
        if( databaseWizard.exec() == 1 )
        {
          systemLibrary = databaseWizard.systemLibrary();
        }
        else
        {
          System.exit( -1 );
        }
      }

      systemBase = new JDMSystemBase( null, systemLibrary );
      systemBase.showMaximized();

      QApplication.exec();
    }
    catch( FileNotFoundException ex )
    {
      ex.printStackTrace();
      QApplication.exit( -1 );
    }
    catch( IOException ex )
    {
      ex.printStackTrace();
      QApplication.exit( -1 );
    }
  }
}
