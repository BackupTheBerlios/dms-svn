package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.core.QRect;
import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QDesktopWidget;
import com.trolltech.qt.gui.QDialog;

import de.asaal.jdmsystem.core.dto.UserDataDTO;
import de.asaal.jdmsystem.core.iface.IDialog;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> AdvancedUserBase.java<br>
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
public class AdvancedUserBase extends UiAdvancedUserBase implements IDialog
{
  private QDialog     advancedUserBase = null;
  private UserDataDTO userDataDTO      = null;
  private String      userId           = null;

  /**
   * Constructor of {@link AdvancedUserBase}
   */
  public AdvancedUserBase()
  {
    super();

    try
    {
      advancedUserBase = new QDialog();
      setupUi( advancedUserBase );

      QDesktopWidget desktop = QApplication.desktop();
      final QRect rect = desktop.availableGeometry( desktop.primaryScreen() );
      int left = ( rect.width() - advancedUserBase.width() ) / 2;
      int top = ( rect.height() - advancedUserBase.height() ) / 2;
      advancedUserBase.setGeometry( left, top, advancedUserBase.width(), advancedUserBase.height() );

      initialConnections();
    }
    catch( Exception ex )
    {
      ex.printStackTrace();
    }
  }

  @Override
  public void initialConnections()
  {
    try
    {
      btnOk.clicked.connect( this, "accept()" );
      btnCancel.clicked.connect( this, "reject()" );
    }
    catch( Exception ex )
    {
      ex.printStackTrace();
    }
  }

  @Override
  public int exec()
  {
    return advancedUserBase.exec();
  }

  @Override
  public void accept()
  {
    if( userDataDTO == null )
    {
      userDataDTO = new UserDataDTO();
    }

    userDataDTO.setFkUserId( getUserId() );
    userDataDTO.setFirstName( lineEditFirstName.text() );
    userDataDTO.setLastName( lineEditLastName.text() );
    userDataDTO.setCity( lineEditCity.text() );
    userDataDTO.setCountry( lineEditCountry.text() );
    userDataDTO.setStreetName( lineEditStreetName.text() );
    userDataDTO.setStreetNr( lineEditStreetNumber.text() );
    userDataDTO.setZipCode( lineEditPostalCode.text() );

    advancedUserBase.accept();
  }

  @Override
  public void reject()
  {
    userDataDTO = null;
    userId = null;
    advancedUserBase.reject();
  }

  /**
   * Set the internal user id
   */
  public void setUserId( String userId )
  {
    this.userId = userId;
  }

  /**
   * Set advanced {@link UserDataDTO}
   * 
   * @param userDataDTO
   *          The {@link UserDataDTO}
   */
  public void setUserDataDTO( UserDataDTO userDataDTO )
  {
    this.userDataDTO = userDataDTO;
    setUserId( userDataDTO.getFkUserId() );

    lineEditFirstName.setText( userDataDTO.getFirstName() );
    lineEditLastName.setText( userDataDTO.getLastName() );
    lineEditCity.setText( userDataDTO.getCity() );
    lineEditCountry.setText( userDataDTO.getCountry() );
    lineEditStreetName.setText( userDataDTO.getStreetName() );
    lineEditStreetNumber.setText( userDataDTO.getStreetNr() );
    lineEditPostalCode.setText( userDataDTO.getZipCode() );
  }

  /**
   * Returns the advanced user data
   */
  public UserDataDTO getUserDataDTO()
  {
    return userDataDTO;
  }

  /**
   * Returns the internal user id
   */
  private String getUserId()
  {
    return userId;
  }
}
