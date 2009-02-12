package de.asaal.jdmsystem.core.xml;

import java.util.ArrayList;
import java.util.Hashtable;

import com.trolltech.qt.core.QByteArray;
import com.trolltech.qt.core.QFile;
import com.trolltech.qt.core.QObject;
import com.trolltech.qt.core.QPoint;
import com.trolltech.qt.core.QSize;
import com.trolltech.qt.gui.QColor;
import com.trolltech.qt.xml.QDomDocument;
import com.trolltech.qt.xml.QDomElement;
import com.trolltech.qt.xml.QDomNode;
import com.trolltech.qt.xml.QDomNodeList;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> XmlSettings.java<br>
 * <b>Desc:</b> Store your application settings into a single XML file.<br>
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
@SuppressWarnings( { "unused", "unchecked" } )
public class XmlSettings extends QObject
{
  // ############################## XmlSetting variable
  private static XmlSettings xmlSettings        = null;

  // ############################## Setting informations
  private String             configurationFile  = null;
  private String             applicationName    = null;
  private String             applicationVersion = null;
  private String             applicationAuthor  = null;
  private String             authorMail         = null;

  // ############################## Default setting values
  private String             stringValue        = null;
  private ArrayList          arrayValue         = null;
  private Hashtable          hashTableValue     = null;
  private QSize              sizeValue          = null;
  private QPoint             pointValue         = null;
  private QColor             colorValue         = null;
  private char[]             charValue          = null;
  private byte[]             byteValue          = null;
  private boolean            boolValue          = false;
  private int                integerValue       = 0;
  private double             doubleValue        = 0.0;
  private float              floatValue         = 0.00f;

  // ############################## Write/Read elements
  private QDomDocument       readDocument       = null;
  private QDomDocument       writeDocument      = null;
  private QDomElement        element            = null;
  private QDomElement        subElement         = null;
  private QDomNode           node               = null;
  private QDomNode           subNode            = null;
  private QDomNodeList       nodeList           = null;
  private String             lastError          = null;

  /**
   * Private constructor of {@link XmlSettings}
   */
  private XmlSettings()
  {
    xmlSettings = this;

    readDocument = new QDomDocument();
    writeDocument = new QDomDocument();

    element = new QDomElement();
    subElement = new QDomElement();
    node = new QDomNode();
    subNode = new QDomNode();
  }

  /**
   * Returns new instance of {@link XmlSettings} or available instance.
   */
  public static XmlSettings xmlSettings()
  {
    if( xmlSettings == null )
    {
      xmlSettings = new XmlSettings();
    }

    return xmlSettings;
  }

  // ############################## Getter/Setter methods: START
  /**
   * Get configuration file
   */
  public String configurationFile()
  {
    return configurationFile;
  }

  /**
   * Set configuration file
   */
  public void setConfigurationFile( String configurationFile )
  {
    this.configurationFile = configurationFile;
  }

  /**
   * Get application name
   */
  public String applicationName()
  {
    return applicationName;
  }

  /**
   * Set application name
   */
  public void setApplicationName( String applicationName )
  {
    this.applicationName = applicationName;
  }

  /**
   * Get application version
   */
  public String applicationVersion()
  {
    return applicationVersion;
  }

  /**
   * 
   */
  public void setApplicationVersion( String applicationVersion )
  {
    this.applicationVersion = applicationVersion;
  }

  /**
   * Get application author
   */
  public String applicationAuthor()
  {
    return applicationAuthor;
  }

  /**
   * Set the application author
   */
  public void setApplicationAuthor( String applicationAuthor )
  {
    this.applicationAuthor = applicationAuthor;
  }

  // ############################## Getter/Setter methods: END

  // ############################## Getter/Setter for values: START
  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, String value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, ArrayList value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, Hashtable value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, QSize value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, QPoint value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, QColor value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, char[] value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, byte[] value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, boolean value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, int value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, double value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param value
   */
  public void setValue( String section, String key, float value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, String defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, ArrayList defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, Hashtable defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, QSize defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, QPoint defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, QColor defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, char[] defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, byte[] defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, boolean defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, int defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, double defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param section
   * @param key
   * @param defValue
   */
  public void value( String section, String key, float defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  // ############################## Getter/Setter for values: END

  // ############################## Public/Private function: START
  /**
   * Write configuration file
   */
  public void write()
  {
    try
    {
      write( new QFile( configurationFile(), this ) );
    }
    catch( Exception ex )
    {
    }
  }

  /**
   * @param file
   */
  private void write( QFile file )
  {
    try
    {
      finalizeObjects();
    }
    catch( Exception ex )
    {
    }
  }

  // ############################## Public/Private function: END

  /**
   * Runs the finalization methods of any objects pending finalization. Calling<br>
   * this method suggests that the Java virtual machine expend effort toward<br>
   * running the finalize methods of objects that have been found to be<br>
   * discarded but whose finalize methods have not yet been run. When<br>
   * control returns from the method call, the virtual machine has made a best<br>
   * effort to complete all outstanding finalizations.<br>
   */
  protected void finalizeObjects()
  {
    configurationFile = null;
    applicationName = null;
    applicationVersion = null;
    applicationAuthor = null;
    authorMail = null;

    stringValue = null;
    arrayValue = null;
    hashTableValue = null;
    sizeValue = null;
    pointValue = null;
    colorValue = null;
    charValue = null;
    byteValue = null;
    boolValue = false;
    integerValue = 0;
    doubleValue = 0.0;
    floatValue = 0.00f;

    lastError = null;

    Runtime.getRuntime().runFinalization();
    Runtime.getRuntime().gc();
  }
}
