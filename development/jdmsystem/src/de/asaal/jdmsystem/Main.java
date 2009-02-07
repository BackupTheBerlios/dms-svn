package de.asaal.jdmsystem;

import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QMainWindow;
import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.ui.UserBase;


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
    QApplication.initialize( args );

    JDMSystemLibrary.setHost( "localhost" );
    JDMSystemLibrary.setPort( 3306 );
    JDMSystemLibrary.setDatabase( "mysql" );
    JDMSystemLibrary.setUsername( "root" );
    JDMSystemLibrary.setPassword( "Ms!//9pSicher!Code" );

    JDMSystemLibrary library = new JDMSystemLibrary();
    JDMSystemBase base = new JDMSystemBase( null, library );
    base.showMaximized();

    UserBase userBase = new UserBase();
    userBase.show();
    // UserDTO userDTO = new UserDTO();
    // userDTO.setUserName( "asaal" );
    // userDTO.setUserPwd( "Ms!//9pSicher!CodeMasterOfUniverse" );
    // String userId = library.createUser( userDTO );
    //    
    // UserDataDTO userDataDTO = new UserDataDTO();
    // userDataDTO.setFkUserId( userId );
    // userDataDTO.setFirstName( "Alexander" );
    // userDataDTO.setLastName( "Saal" );
    // userDataDTO.setCity( "Landshut" );
    // userDataDTO.setCountry( "Bayern" );
    // userDataDTO.setStreetName( "Ahornweg" );
    // userDataDTO.setStreetNr( "16" );
    // userDataDTO.setZipCode( "84032" );
    // String userDataId = library.createUserData( userDataDTO );
    //    
    // userDataDTO.setZipCode( "84032" );
    // boolean ok = library.updateUser( userDTO, userDataDTO );
    //    
    // System.out.println(userDataId);

    QApplication.exec();
  }
}
