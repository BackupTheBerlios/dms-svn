package de.asaal.jdmsystem.core.dto;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * File: DocumentDTO.java<br>
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
public class DocumentDTO extends UserDTO
{
  private String docId      = null;
  private String fkUserId   = null;
  private String fkGroupId  = null;
  private String docName    = null;
  private String docPath    = null;
  private String created    = null;
  private String updated     = null;
  private String checkedOut = null;

  /**
   * 
   */
  public DocumentDTO()
  {}

  public String getDocId()
  {
    return docId;
  }

  public void setDocId( String docId )
  {
    this.docId = docId;
  }

  public String getFkUserId()
  {
    return fkUserId;
  }

  public void setFkUserId( String fkUserId )
  {
    this.fkUserId = fkUserId;
  }

  public String getFkGroupId()
  {
    return fkGroupId;
  }

  public void setFkGroupId( String fkGroupId )
  {
    this.fkGroupId = fkGroupId;
  }

  public String getDocName()
  {
    return docName;
  }

  public void setDocName( String docName )
  {
    this.docName = docName;
  }

  public String getDocPath()
  {
    return docPath;
  }

  public void setDocPath( String docPath )
  {
    this.docPath = docPath;
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

  public String getCheckedOut()
  {
    return checkedOut;
  }

  public void setCheckedOut( String checkedOut )
  {
    this.checkedOut = checkedOut;
  }
}
