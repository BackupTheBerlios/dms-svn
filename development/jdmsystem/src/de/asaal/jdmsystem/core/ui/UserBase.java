package de.asaal.jdmsystem.core.ui;

import java.util.List;

import com.trolltech.qt.core.QRect;
import com.trolltech.qt.core.Qt.ItemDataRole;
import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QDesktopWidget;
import com.trolltech.qt.gui.QMessageBox;
import com.trolltech.qt.gui.QTreeWidget;
import com.trolltech.qt.gui.QTreeWidgetItem;
import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.JDMSystemBase;
import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.dto.UserDTO;
import de.asaal.jdmsystem.core.dto.UserDataDTO;
import de.asaal.jdmsystem.core.iface.IUserBase;
import de.asaal.jdmsystem.core.iface.IWidget;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> UserBase.java<br>
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
public class UserBase extends UiUserBase implements IUserBase, IWidget
{
  private QWidget          userBase      = null;
  private JDMSystemLibrary systemLibrary = null;
  private static UserBase  instance      = null;
  private String           userId        = null;
  private UserDTO          userDTO       = null;
  private List< UserDTO >  userDTOs      = null;
  private UserDataDTO      userDataDTO   = null;

  public UserBase()
  {
    super();

    try
    {
      userBase = new QWidget();
      setupUi( userBase );

      QDesktopWidget desktop = QApplication.desktop();
      final QRect rect = desktop.availableGeometry( desktop.primaryScreen() );
      int left = ( rect.width() - userBase.width() ) / 2;
      int top = ( rect.height() - userBase.height() ) / 2;
      userBase.setGeometry( left, top, userBase.width(), userBase.height() );

      instance = this;
      systemLibrary = JDMSystemLibrary.systemLibraryInstance();

      initialConnections();
      reloadUsers();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  /**
   * Returns the internal {@link QWidget} with all visual components
   */
  public QWidget widget()
  {
    return userBase;
  }

  @Override
  public void initialConnections()
  {
    try
    {
      treeWidgetUser.itemClicked.connect( this, "treeWidgetItemClicked( QTreeWidgetItem, Integer )" );
      btnAdvanceUser.clicked.connect( this, "advanceUser()" );
      btnAddUser.clicked.connect( this, "addUser()" );
      btnUpdateUser.clicked.connect( this, "updateUser()" );
      btnDeleteUser.clicked.connect( this, "deleteUser()" );
      btnOk.clicked.connect( this, "close()" );
      btnCancel.clicked.connect( this, "close()" );
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void show()
  {
    userBase.show();
  }

  @Override
  public void addUser()
  {
    try
    {
      if( lineEditUserName.text().isEmpty() || lineEditUserName.text() == null )
      {
        QMessageBox.critical( userBase, QApplication.translate( userBase.objectName(), "User" ), QApplication.translate( userBase.objectName(), "User name can not be blank!" ) );
        return;
      }

      userDTO = new UserDTO();
      userDTO.setUserName( lineEditUserName.text() );
      userDTO.setUserPwd( lineEditUserPassword.text() );
      systemLibrary.createUser( userDTO );

      reloadUsers();
      clearFileds();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void advanceUser()
  {
    try
    {
      if( getUserId() != null && !getUserId().isEmpty() )
      {
        AdvancedUserBase advancedUserBase = new AdvancedUserBase();
        advancedUserBase.setUserId( getUserId() );
        if( advancedUserBase.exec() == 1 )
        {
          userDataDTO = advancedUserBase.getUserDataDTO();
          if( userDataDTO != null )
          {
            systemLibrary.createUserData( userDataDTO );
            reloadUsers();
            clearFileds();

            advancedUserBase = null;
          }
        }
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void deleteUser()
  {
    try
    {
      if( userId != null && !userId.isEmpty() )
      {
        for( UserDTO userDTO : userDTOs )
        {
          QApplication.processEvents();

          if( userDTO.getUserId().equalsIgnoreCase( userId ) )
          {
            systemLibrary.deleteUser( userDTO );
            reloadUsers();
            clearFileds();
            return;
          }
        }
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void updateUser()
  {
    try
    {
      if( userId != null && !userId.isEmpty() )
      {
        for( UserDTO userDTO : userDTOs )
        {
          QApplication.processEvents();

          if( userDTO.getUserId().equalsIgnoreCase( userId ) )
          {
            if( !lineEditUserName.text().isEmpty() )
            {
              userDTO.setUserName( lineEditUserName.text() );
            }

            if( !lineEditUserPassword.text().isEmpty() )
            {
              userDTO.setUserPwd( lineEditUserPassword.text() );
            }

            systemLibrary.deleteUser( userDTO );
            reloadUsers();
            clearFileds();
            break;
          }
        }
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void close()
  {
    userBase.close();
  }

  /**
   * Returns the instance of {@link UserBase}
   */
  public static UserBase userBaseInstance()
  {
    return instance;
  }

  /**
   * Reload users from database
   */
  public void reloadUsers()
  {
    try
    {
      treeWidgetUser.clear();

      if( userDTOs != null )
      {
        userDTOs.clear();
      }

      userDTOs = systemLibrary.getUsers();
      if( userDTOs == null || userDTOs.size() <= 0 )
      {
        return;
      }

      for( UserDTO userDTO : userDTOs )
      {
        QApplication.processEvents();

        QTreeWidgetItem item = new QTreeWidgetItem( treeWidgetUser );
        item.setText( 0, userDTO.getUserName() );
        item.setData( 0, ItemDataRole.UserRole, userDTO );
        item.setText( 1, userDTO.getFirstName() );
        item.setText( 2, userDTO.getLastName() );
        item.setText( 3, userDTO.getCreated() );
        item.setText( 4, userDTO.getUpdated() );
      }
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  /**
   * Called from {@link QTreeWidget} if you click on an item
   * 
   * @param item
   *          The {@link QTreeWidgetItem}
   * @param column
   *          The column was clicked
   */
  protected void treeWidgetItemClicked( QTreeWidgetItem item, Integer column )
  {
    try
    {
      userId = null;
      userId = ( (UserDTO)item.data( 0, ItemDataRole.UserRole ) ).getUserId();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  /**
   * Clear text fields
   */
  private void clearFileds()
  {
    try
    {
      userId = null;
      lineEditUserName.setText( "" );
      lineEditUserPassword.setText( "" );
      lineEditUserPasswordConfirm.setText( "" );
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }
  
  /**
   * Returns the internal user id
   */
  private String getUserId()
  {
    return userId;
  }
}
