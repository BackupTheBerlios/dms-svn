package de.asaal.jdmsystem.core.dto;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * File: UserDTO.java<br>
 * Desc: ${description}<br>
 * <br>
 * This file is part of DMS - Documnet Management System<br>
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
public class UserDTO extends UserDataDTO
{
  private String userId   = null;
  private String userName = null;
  private String userPwd  = null;
  private String loggedIn = null;
  private String created  = null;
  private String updated  = null;

  /**
   * 
   */
  public UserDTO()
  {}

  /**
   * @return the userId
   */
  public String getUserId()
  {
    return userId;
  }

  /**
   * @param userId
   *          the userId to set
   */
  public void setUserId( String userId )
  {
    this.userId = userId;
  }

  /**
   * @return the userName
   */
  public String getUserName()
  {
    return userName;
  }

  /**
   * @param userName
   *          the userName to set
   */
  public void setUserName( String userName )
  {
    this.userName = userName;
  }

  /**
   * @return the userPwd
   */
  public String getUserPwd()
  {
    return userPwd;
  }

  /**
   * @param userPwd
   *          the userPwd to set
   */
  public void setUserPwd( String userPwd )
  {
    this.userPwd = userPwd;
  }

  /**
   * @return the loggedIn
   */
  public String getLoggedIn()
  {
    return loggedIn;
  }

  /**
   * @param loggedIn
   *          the loggedIn to set
   */
  public void setLoggedIn( String loggedIn )
  {
    this.loggedIn = loggedIn;
  }

  /**
   * @return the created
   */
  public String getCreated()
  {
    return created;
  }

  /**
   * @param created
   *          the created to set
   */
  public void setCreated( String created )
  {
    this.created = created;
  }

  /**
   * @return the updated
   */
  public String getUpdated()
  {
    return updated;
  }

  /**
   * @param updated
   *          the updated to set
   */
  public void setUpdated( String updated )
  {
    this.updated = updated;
  }

}
