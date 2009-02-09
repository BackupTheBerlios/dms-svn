package de.asaal.jdmsystem.core.iface;

import java.sql.SQLException;
import java.util.List;

import de.asaal.jdmsystem.core.dto.DatabaseDTO;
import de.asaal.jdmsystem.core.dto.DocumentDTO;
import de.asaal.jdmsystem.core.dto.ExceptionStackDTO;
import de.asaal.jdmsystem.core.dto.GroupDTO;
import de.asaal.jdmsystem.core.dto.UserDTO;
import de.asaal.jdmsystem.core.dto.UserDataDTO;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> IJDMSystem.java<br>
 * <b>Desc:</b> This class represent all global <strong>interface</strong>
 * function to interact with database.<br>
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
public interface IJDMSystem
{
  // TODO: Users
  // ############################################################################
  /**
   * Create new user and return the user id
   * 
   * @param userDTO
   *          The {@link UserDTO} with all data
   */
  public String createUser( UserDTO userDTO );

  /**
   * Create new user specified data and return the user data id
   * 
   * @param userDataDTO
   *          The {@link UserDataDTO}
   */
  public String createUserData( UserDataDTO userDataDTO );

  /**
   * Returns the user id
   * 
   * @param userDTO
   *          The {@link UserDTO}
   */
  public String getUserId( UserDTO userDTO );

  /**
   * Returns all user from DMS database
   */
  public List< UserDTO > getUsers();

  /**
   * Update user and return true was user successfully updated
   * 
   * @param userDTO
   *          The {@link UserDTO}
   * @param userDataDTO
   *          The {@link UserDataDTO}
   */
  public boolean updateUser( UserDTO userDTO, UserDataDTO userDataDTO );

  /**
   * Delete user from DMS database and return true was user deleted
   * 
   * @param userDTO
   *          The {@link UserDTO}
   */
  public boolean deleteUser( UserDTO userDTO );

  // TODO: Documents
  // ###########################################################################
  /**
   * @param documentDTO
   * @return
   */
  public String createDocument( DocumentDTO documentDTO );

  /**
   * @param userId
   * @param docName
   * @return
   */
  public String getDocId( String userId, String docName );

  /**
   * @return
   */
  public List< DocumentDTO > getDocuments();

  /**
   * @param userId
   * @return
   */
  public List< DocumentDTO > geDocuments( String userId );

  /**
   * @param documentDTO
   * @return
   */
  public boolean updateDocument( DocumentDTO documentDTO );

  /**
   * @param documentDTO
   * @return
   */
  public boolean deleteDocument( DocumentDTO documentDTO );

  // TODO: Groups
  // ###############################################################################
  /**
   * @param groupDTO
   * @return
   */
  public String createGroup( GroupDTO groupDTO );

  /**
   * @param groupName
   * @return
   */
  public String getGroupId( String groupName );

  /**
   * @return
   */
  public List< GroupDTO > getGroups();

  /**
   * @param groupDTO
   * @return
   */
  public boolean updateGroup( GroupDTO groupDTO );

  /**
   * @param groupDTO
   * @return
   */
  public boolean deleteGroup( GroupDTO groupDTO );

  // TODO: Miscellaneous
  // ########################################################################

  /**
   * Returns the databases on MySQL Server
   */
  public List< DatabaseDTO > getDatabases();

  /**
   * @param userDTO
   * @return
   */
  public boolean login( UserDTO userDTO );

  /**
   * @param userDTO
   * @return
   */
  public boolean logout( UserDTO userDTO );

  /**
   * @param userDTO
   * @return
   */
  public boolean isConnectionAvailabel( UserDTO userDTO );

  /**
   * Returns a message if connection available
   * 
   * @param dbUser
   *          The database user (default is "root")
   * @param dbUserPwd
   *          The database user password
   * @param host
   *          The database host
   * @param port
   *          The database port
   * @param database
   *          The database name (default is "mysql")
   */
  public String isConnectionAvailabel( String dbUser, String dbUserPwd, String host, String port, String database );

  /**
   * @param exception
   * @param sqlException
   */
  public void createExceptions( Exception exception, SQLException sqlException );

  /**
   * @return
   */
  public List< ExceptionStackDTO > getExceptions();
}
