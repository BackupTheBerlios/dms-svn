package de.asaal.jdmsystem.core.dto;

import com.trolltech.qt.core.QObject;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * File: GroupDTO.java<br>
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
public class GroupDTO extends QObject
{
  private String groupId          = null;
  private String groupName        = null;
  private String groupDescription = null;
  private String created          = null;
  private String updated          = null;

  /**
   * 
   */
  public GroupDTO()
  {}

  public String getGroupId()
  {
    return groupId;
  }

  public void setGroupId( String groupId )
  {
    this.groupId = groupId;
  }

  public String getGroupName()
  {
    return groupName;
  }

  public void setGroupName( String groupName )
  {
    this.groupName = groupName;
  }

  public String getGroupDescription()
  {
    return groupDescription;
  }

  public void setGroupDescription( String groupDescription )
  {
    this.groupDescription = groupDescription;
  }

  public String getCreated()
  {
    return created;
  }

  public void setCreated( String created )
  {
    this.created = created;
  }

  public String getUpdated()
  {
    return updated;
  }

  public void setUpdated( String updated )
  {
    this.updated = updated;
  }
}
