package de.asaal.jdmsystem.core.dto;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * File: UserDataDTO.java<br>
 * Desc: ${description}<br>
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
public class UserDataDTO
{
  private String userDataId = null;
  private String fkUserId   = null;
  private String firstName  = null;
  private String lastName   = null;
  private String streetName = null;
  private String streetNr   = null;
  private String city       = null;
  private String zipCode    = null;
  private String country    = null;
  private String created    = null;
  private String updated    = null;

  public UserDataDTO()
  {}

  /**
   * @return the userDataId
   */
  public String getUserDataId()
  {
    return userDataId;
  }

  /**
   * @param userDataId
   *          the userDataId to set
   */
  public void setUserDataId( String userDataId )
  {
    this.userDataId = userDataId;
  }

  /**
   * @return the fkUserId
   */
  public String getFkUserId()
  {
    return fkUserId;
  }

  /**
   * @param fkUserId
   *          the fkUserId to set
   */
  public void setFkUserId( String fkUserId )
  {
    this.fkUserId = fkUserId;
  }

  /**
   * @return the firstName
   */
  public String getFirstName()
  {
    return firstName;
  }

  /**
   * @param firstName
   *          the firstName to set
   */
  public void setFirstName( String firstName )
  {
    this.firstName = firstName;
  }

  /**
   * @return the lastName
   */
  public String getLastName()
  {
    return lastName;
  }

  /**
   * @param lastName
   *          the lastName to set
   */
  public void setLastName( String lastName )
  {
    this.lastName = lastName;
  }

  /**
   * @return the streetName
   */
  public String getStreetName()
  {
    return streetName;
  }

  /**
   * @param streetName
   *          the streetName to set
   */
  public void setStreetName( String streetName )
  {
    this.streetName = streetName;
  }

  /**
   * @return the streetNr
   */
  public String getStreetNr()
  {
    return streetNr;
  }

  /**
   * @param streetNr
   *          the streetNr to set
   */
  public void setStreetNr( String streetNr )
  {
    this.streetNr = streetNr;
  }

  /**
   * @return the city
   */
  public String getCity()
  {
    return city;
  }

  /**
   * @param city
   *          the city to set
   */
  public void setCity( String city )
  {
    this.city = city;
  }

  /**
   * @return the zipCode
   */
  public String getZipCode()
  {
    return zipCode;
  }

  /**
   * @param zipCode
   *          the zipCode to set
   */
  public void setZipCode( String zipCode )
  {
    this.zipCode = zipCode;
  }

  /**
   * @return the country
   */
  public String getCountry()
  {
    return country;
  }

  /**
   * @param country
   *          the country to set
   */
  public void setCountry( String country )
  {
    this.country = country;
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
