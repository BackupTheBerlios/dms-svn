package de.asaal.jdmsystem.core.xml;

import java.util.ArrayList;
import java.util.Hashtable;

import com.trolltech.qt.core.QByteArray;
import com.trolltech.qt.core.QFile;
import com.trolltech.qt.core.QIODevice;
import com.trolltech.qt.core.QObject;
import com.trolltech.qt.core.QPoint;
import com.trolltech.qt.core.QSize;
import com.trolltech.qt.core.QIODevice.OpenModeFlag;
import com.trolltech.qt.gui.QColor;
import com.trolltech.qt.xml.QDomDocument;
import com.trolltech.qt.xml.QDomElement;
import com.trolltech.qt.xml.QDomNode;
import com.trolltech.qt.xml.QDomNodeList;
import com.trolltech.qt.xml.QDomDocument.Result;

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
  // TODO XmlSetting variable
  private static XmlSettings xmlSettings        = null;

  // TODO Private setting informations variables
  private String             configurationFile  = null;
  private String             applicationName    = null;
  private String             applicationVersion = null;
  private String             applicationAuthor  = null;
  private String             authorMail         = null;

  // TODO Private default setting variables
  private String             stringValue        = null;
  private ArrayList          arrayValue         = null;
  private Hashtable          hashTableValue     = null;
  private QSize              sizeValue          = null;
  private QPoint             pointValue         = null;
  private QColor             colorValue         = null;
  private char[]             charValue          = null;
  private byte[]             byteValue          = null;
  private Boolean            boolValue          = false;
  private Integer            integerValue       = 0;
  private Double             doubleValue        = 0.0;
  private Float              floatValue         = 0.00f;

  // TODO Private write/read elements variables
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
  private XmlSettings( QObject parent )
  {
    xmlSettings = this;

    element = new QDomElement();
    subElement = new QDomElement();
    node = new QDomNode();
    subNode = new QDomNode();
  }

  /**
   * Returns new instance of {@link XmlSettings} or available instance.
   * 
   * @param parent
   *          Parent {@link QObject}
   */
  public static XmlSettings xmlSettings( QObject parent )
  {
    if( xmlSettings == null )
    {
      xmlSettings = new XmlSettings( parent );
    }

    return xmlSettings;
  }

  // TODO Getter/Setter methods
  /**
   * Returns configuration file
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
   * Returns application name
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
   * Returns application version
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
   * Returns application author
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

  // TODO Getter/Setter for values

  /**
   * Set the {@link String} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          String value
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
   * Set the {@link ArrayList} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          ArrayList value
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
   * Set the {@link Hashtable} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          Hashtable value
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
   * Set the {@link QSize} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          QSize value
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
   * Set the {@link QPoint} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          QPoint value
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
   * Set the {@link QColor} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          QColor value
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
   * Set the char[] (array) value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          char[] (array) value
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
   * Set the byte[] (array) value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          byte[] (array) value
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
   * Set the {@link Boolean} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          Boolean value
   */
  public void setValue( String section, String key, Boolean value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Set the {@link Integer} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          Integer value
   */
  public void setValue( String section, String key, Integer value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Set the {@link Double} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          Double value
   */
  public void setValue( String section, String key, Double value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Set the {@link Float} value to <strong>section</strong> and
   * <strong>key</strong>.<br>
   * <br>
   * 
   * @param section
   *          Section for this value
   * @param key
   *          Key for value
   * @param value
   *          Float value
   */
  public void setValue( String section, String key, Float value )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Returns a {@link String} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default String value if value on section and key not found
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
   * Returns a {@link ArrayList} value from selected <strong>section</strong>
   * and selected <strong>key</strong>. If section and/or key not available
   * returns a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default ArrayList value if value on section and key not found
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
   * Returns a {@link Hashtable} value from selected <strong>section</strong>
   * and selected <strong>key</strong>. If section and/or key not available
   * returns a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default Hashtable value if value on section and key not found
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
   * Returns a {@link QSize} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default QSize value if value on section and key not found
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
   * Returns a {@link QPoint} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default QPoint value if value on section and key not found
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
   * Returns a {@link QColor} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default QColor value if value on section and key not found
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
   * Returns a char[] (array) value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default char[] (array) value if value on section and key not found
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
   * Returns a byte[] (array) value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default byte[] (array) value if value on section and key not found
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
   * Returns a {@link Boolean} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default Boolean value if value on section and key not found
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
   * Returns a {@link Integer} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default Integer value if value on section and key not found
   */
  public void value( String section, String key, Integer defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Returns a {@link Double} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default Double value if value on section and key not found
   */
  public void value( String section, String key, Double defValue )
  {
    try
    {

    }
    catch( Exception ex )
    {
    }
  }

  /**
   * Returns a {@link Float} value from selected <strong>section</strong> and
   * selected <strong>key</strong>. If section and/or key not available returns
   * a default value.<br>
   * <br>
   * 
   * @param section
   *          Section where is the value
   * @param key
   *          Key for determine the value
   * @param defValue
   *          Default Float value if value on section and key not found
   */
  public void value( String section, String key, Float defValue )
  {
    try
    {
    }
    catch( Exception ex )
    {
    }
  }

  // TODO Public/Private function
  /**
   * Read XML configuration file
   */
  public boolean read()
  {
    try
    {
      QFile xmlFile = read( configurationFile() );
      if( xmlFile != null )
      {
        readDocument = new QDomDocument();
        Result result = readDocument.setContent( xmlFile );

        xmlFile.close();
        xmlFile.dispose();
        xmlFile = null;

        return result.success;
      }
    }
    catch( Exception ex )
    {
      ex.printStackTrace();
    }

    return false;
  }

  /**
   * Write XML configuration file
   */
  public boolean write()
  {
    try
    {
      writeDocument = new QDomDocument();
      write( new QFile( configurationFile(), this ) );
      return true;
    }
    catch( Exception ex )
    {
      ex.printStackTrace();
      return false;
    }
  }

  /**
   * Write XML to selected file
   * 
   * @param file
   *          {@link QFile} for writing the XML structure
   */
  private boolean write( QFile file )
  {
    try
    {
      finalizeObjects();
      return true;
    }
    catch( Exception ex )
    {
      ex.printStackTrace();
      return false;
    }
  }

  /**
   * Read selected XML file
   * 
   * @param file
   *          {@link String} for reading XML file
   */
  private QFile read( String xmlFile )
  {
    try
    {
      if( !QFile.exists( xmlFile ) )
      {
        return null;
      }

      QFile file = new QFile( xmlFile, this );
      file.open( new QIODevice.OpenMode( OpenModeFlag.ReadOnly ) );

      finalizeObjects();

      return file;
    }
    catch( Exception ex )
    {
      ex.printStackTrace();
      return null;
    }
  }

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
