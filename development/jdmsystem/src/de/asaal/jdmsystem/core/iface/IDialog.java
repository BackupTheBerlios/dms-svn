package de.asaal.jdmsystem.core.iface;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> IDialog.java<br>
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
public interface IDialog
{
  /**
   * Shows the {@link QDialog} as a modal dialog and return the
   * {@link QDialog.DialogCode}.
   */
  public int exec();

  /**
   * Hides the modal dialog and sets the {@link QDialog.DialogCode} to Rejected.
   */
  public void reject();

  /**
   * Hides the modal dialog and sets the {@link QDialog.DialogCode} to Accepted.
   */
  public void accept();

  /**
   * Initialize connections
   */
  public void initialConnections();
}
