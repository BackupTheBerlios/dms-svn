package de.asaal.jdmsystem.core;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.UUID;

import sun.misc.BASE64Decoder;
import sun.misc.BASE64Encoder;

import com.ibatis.common.resources.Resources;
import com.ibatis.sqlmap.client.SqlMapClient;
import com.ibatis.sqlmap.client.SqlMapClientBuilder;
import com.ibatis.sqlmap.client.SqlMapException;
import com.trolltech.qt.core.QDateTime;
import com.trolltech.qt.core.Qt.DateFormat;

import de.asaal.jdmsystem.core.dto.DatabaseDTO;
import de.asaal.jdmsystem.core.dto.DocumentDTO;
import de.asaal.jdmsystem.core.dto.ExceptionStackDTO;
import de.asaal.jdmsystem.core.dto.GroupDTO;
import de.asaal.jdmsystem.core.dto.UserDTO;
import de.asaal.jdmsystem.core.dto.UserDataDTO;
import de.asaal.jdmsystem.core.iface.IJDMSystem;

/**
 * Copyright (C) 2009 Alexander Saal<br>
 * alex.saal@gmx.de<br>
 * <br>
 * <b>File:</b> JDMSystemLibrary.java<br>
 * <b>Desc:</b> This class represent all global function from interface to
 * interact with database.<br>
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
public class JDMSystemLibrary implements IJDMSystem
{
  private SqlMapClient              sqlMapper     = null;

  private List< ExceptionStackDTO > exceptionDTOs = null;

  private DocumentDTO               documentDTO   = null;
  private List< DocumentDTO >       documentDTOs  = null;

  private GroupDTO                  groupDTO      = null;
  private List< GroupDTO >          groupDTOs     = null;

  private UserDTO                   userDTO       = null;
  private UserDataDTO               userDataDTO   = null;
  private List< UserDTO >           userDTOs      = null;

  private static String             userName      = null;
  private static String             userPassword  = null;
  private static String             userHost      = null;
  private static int                userPort      = 3306;
  private static String             userDatabase  = null;

  /**
   * @param parent
   */
  public JDMSystemLibrary()
  {
    super();

    initialDriver();
    initalVariables();
  }

  @Override
  public String createDocument( DocumentDTO documentDTO )
  {

    return null;
  }

  @Override
  public String createGroup( GroupDTO groupDTO )
  {

    return null;
  }

  @Override
  public String createUser( UserDTO userDTO )
  {
    String userId = "";
    try
    {
      if( sqlMapper != null )
      {
        userDTO.setUserId( createUserId() );
        userDTO.setUserPwd( encodeUserPwd( userDTO.getUserPwd() ) );
        userDTO.setCreated( getCurrentDate() );
        userDTO.setUpdated( getCurrentDate() );

        sqlMapper.insert( "createUser", userDTO );

        userId = userDTO.getUserId();
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
    }

    return userId;
  }

  @Override
  public String createUserData( UserDataDTO userDataDTO )
  {
    String userDataId = "";
    try
    {
      if( sqlMapper != null )
      {
        if( userDataDTO != null )
        {
          userDataDTO.setUserDataId( createUserId() );
          userDataDTO.setCreated( getCurrentDate() );
          userDataDTO.setUpdated( getCurrentDate() );

          sqlMapper.insert( "createUserData", userDataDTO );

          userDataId = userDataDTO.getUserDataId();
        }
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
    }

    return userDataId;
  }

  @Override
  public boolean deleteDocument( DocumentDTO documentDTO )
  {

    return false;
  }

  @Override
  public boolean deleteGroup( GroupDTO groupDTO )
  {

    return false;
  }

  @Override
  public boolean deleteUser( UserDTO userDTO )
  {
    boolean deleted = false;
    try
    {
      if( sqlMapper != null )
      {
        if( userDTO != null )
        {
          sqlMapper.delete( "deleteUserData", userDTO );
          sqlMapper.delete( "deleteUser", userDTO );

          deleted = true;
        }
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );

      deleted = false;
    }

    return deleted;
  }

  @Override
  public List< DocumentDTO > geDocuments( String userId )
  {

    return null;
  }

  @Override
  public String getDocId( String userId, String docName )
  {

    return null;
  }

  @Override
  public List< DocumentDTO > getDocuments()
  {

    return null;
  }

  @Override
  public String getGroupId( String groupName )
  {

    return null;
  }

  @Override
  public List< GroupDTO > getGroups()
  {

    return null;
  }

  @Override
  public String getUserId( UserDTO userDTO )
  {
    String uid = null;
    try
    {
      if( sqlMapper != null )
      {
        uid = (String)sqlMapper.queryForObject( "selectUserByName", userDTO.getUserName() );
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
    }

    return uid;
  }

  @Override
  public List< UserDTO > getUsers()
  {
    try
    {
      if( sqlMapper != null )
      {
        userDTOs = sqlMapper.queryForList( "selectAllUsers" );
        for( UserDTO userDTO : userDTOs )
        {
          if( userDTO.getUserName().equalsIgnoreCase( "administrator" ) )
          {
            userDTOs.remove( userDTO );
          }
        }
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
    }

    return userDTOs;
  }

  @Override
  public boolean isConnectionAvailabel( UserDTO userDTO )
  {
    return false;
  }

  @Override
  public String isConnectionAvailabel( String dbUser, String dbUserPwd, String host, String port, String database )
  {
    String connectionValid = null;
    try
    {
      if( dbUser == null || dbUser.isEmpty() )
      {
        dbUser = "root";
      }

      if( database == null || database.isEmpty() )
      {
        database = "mysql";
      }

      Class.forName( "com.mysql.jdbc.Driver" ).newInstance();

      Statement stmt = null;
      Connection conn = DriverManager.getConnection( "jdbc:mysql://" + host + ":" + port + "/" + database + "?user=" + dbUser + "&password=" + dbUserPwd );
      if( conn != null )
      {
        connectionValid = "";
        conn = null;
      }
    }
    catch( Exception ex )
    {
      createExceptions( ex, null );
      connectionValid = ex.getMessage();
    }

    return connectionValid;
  }

  @Override
  public boolean login( UserDTO userDTO )
  {
    boolean logedIn = false;

    try
    {
      if( sqlMapper != null )
      {
        int rows = sqlMapper.update( "updateUserLogin", userDTO );
        if( rows >= 1 )
        {
          logedIn = true;
        }
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
      logedIn = false;
    }

    return logedIn;
  }

  @Override
  public boolean logout( UserDTO userDTO )
  {
    boolean logedOut = false;

    try
    {
      if( sqlMapper != null )
      {
        int rows = sqlMapper.update( "updateUserLogin", userDTO );
        if( rows >= 1 )
        {
          logedOut = true;
        }
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
      logedOut = false;
    }

    return logedOut;
  }

  @Override
  public boolean updateDocument( DocumentDTO documentDTO )
  {

    return false;
  }

  @Override
  public boolean updateGroup( GroupDTO groupDTO )
  {

    return false;
  }

  @Override
  public boolean updateUser( UserDTO userDTO, UserDataDTO userDataDTO )
  {
    boolean updated = false;
    try
    {
      if( sqlMapper != null )
      {
        if( userDTO != null )
        {
          userDataDTO.setUpdated( getCurrentDate() );
          sqlMapper.update( "updateUserData", userDataDTO );

          userDTO.setUserPwd( encodeUserPwd( userDTO.getUserPwd() ) );
          userDTO.setUpdated( getCurrentDate() );
          sqlMapper.update( "updateUser", userDTO );

          updated = true;
        }
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );

      updated = false;
    }

    return updated;
  }

  /**
   * Create exceptions into database
   * 
   * @param exception
   *          The {@link Exception}
   */
  @Override
  public void createExceptions( Exception exception, SQLException sqlException )
  {
    ExceptionStackDTO stackDTO = null;
    for( StackTraceElement element : exception.getStackTrace() )
    {
      stackDTO = new ExceptionStackDTO();
      stackDTO.setSqlId( createUserId() );

      if( sqlException != null )
      {
        stackDTO.setSqlMessage( sqlException.getMessage() );
        stackDTO.setSqlState( sqlException.getSQLState() );
        stackDTO.setSqlVendorCode( String.valueOf( sqlException.getErrorCode() ) );
      }

      stackDTO.setClassName( element.getClassName() );
      stackDTO.setCreated( getCurrentDate() );
      stackDTO.setFileName( element.getFileName() );
      stackDTO.setHashCode( String.valueOf( element.hashCode() ) );
      stackDTO.setIsNativeMethode( String.valueOf( element.isNativeMethod() ) );
      stackDTO.setLineNumber( String.valueOf( element.getLineNumber() ) );
      stackDTO.setMessage( exception.getMessage() );
      stackDTO.setMethodeName( element.getMethodName() );

      try
      {
        if( sqlMapper != null )
        {
          sqlMapper.insert( "createException", stackDTO );
        }
      }
      catch( SQLException e )
      {
        System.err.println( "Message: " + e.getMessage() );
        System.err.println( "SQL State: " + e.getSQLState() );
        System.err.println( "Vendorcode: " + e.getErrorCode() );
      }
    }
  }

  @Override
  public List< ExceptionStackDTO > getExceptions()
  {
    try
    {
      if( sqlMapper != null )
      {

        return (List< ExceptionStackDTO >)sqlMapper.queryForList( "selectExceptions" );
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
    }

    return exceptionDTOs;
  }

  /**
   * @param username
   *          the username to set
   */
  public static void setUsername( String username )
  {
    userName = username;
  }

  /**
   * @param password
   *          the password to set
   */
  public static void setPassword( String password )
  {
    userPassword = password;
  }

  /**
   * @param host
   *          the host to set
   */
  public static void setHost( String host )
  {
    userHost = host;
  }

  /**
   * @param port
   *          the port to set
   */
  public static void setPort( int port )
  {
    userPort = port;
  }

  /**
   * @param database
   *          the database to set
   */
  public static void setDatabase( String database )
  {
    userDatabase = database;
  }

  /**
   * Initialize internal variables
   */
  private void initalVariables()
  {
    try
    {
      documentDTOs = new ArrayList< DocumentDTO >();
      groupDTOs = new ArrayList< GroupDTO >();
      userDTOs = new ArrayList< UserDTO >();
    }
    catch( Exception ex )
    {
      createExceptions( ex, null );
    }
  }

  /**
   * Initialize internal SQL driver
   */
  private void initialDriver()
  {
    Properties properties = null;
    FileInputStream inputStream = null;
    FileOutputStream outputStream = null;

    try
    {
      properties = new Properties();

      if( new File( "properties/mysql.properties" ).exists() )
      {
        inputStream = new FileInputStream( "properties/mysql.properties" );
        properties.load( inputStream );
      }
      else
      {
        outputStream = new FileOutputStream( "properties/mysql.properties", false );
        {
          properties.setProperty( "mysql_driver", "com.mysql.jdbc.Driver" );
          properties.setProperty( "mysql_url", "jdbc:mysql://" + getHost() + ":" + getPort() + "/mysql" );
          properties.setProperty( "mysql_host", getHost() );
          properties.setProperty( "mysql_port", String.valueOf( getPort() ) );
          properties.setProperty( "mysql_username", getUsername() );
          properties.setProperty( "mysql_password", encodeUserPwd( getPassword() ) );
          properties.store( outputStream, "MySQL Server Settings" );
        }
        outputStream.flush();
        outputStream.close();
        outputStream = null;
      }

      createDatabase( properties );

      String url = properties.getProperty( "mysql_url" );
      url = url.replace( getPort() + "/mysql", getPort() + "/dms" );
      properties.setProperty( "mysql_url", url );

      properties.setProperty( "mysql_password", decodeUserPwd( properties.getProperty( "mysql_password" ) ) );

      Reader reader = Resources.getResourceAsReader( "de/asaal/jdmsystem/core/properties/ibatis/ibatis.xml" );
      sqlMapper = SqlMapClientBuilder.buildSqlMapClient( reader, properties );
      reader.close();

      if( inputStream != null )
      {
        inputStream.close();
        inputStream = null;
      }

      properties = null;
      setPassword( null );
    }
    catch( Exception ex )
    {
      createExceptions( ex, null );
    }
  }

  /**
   * Create new database if this not exists
   */
  private void createDatabase( final Properties properties )
  {
    try
    {
      Class.forName( "com.mysql.jdbc.Driver" ).newInstance();

      Statement stmt = null;
      Connection conn = DriverManager.getConnection( properties.getProperty( "mysql_url" ) + "?user=" + properties.getProperty( "mysql_username" ) + "&password=" + decodeUserPwd( properties.getProperty( "mysql_password" ) ) );
      stmt = conn.createStatement();
      try
      {
        ResultSet result = stmt.executeQuery( "SELECT USERNAME FROM DMS.USERS" );
        result.close();
        result = null;
      }
      catch( SQLException ex )
      {
        BufferedReader in = new BufferedReader( new FileReader( "properties/mysql_dms.sql" ) );
        String zeile = null;
        while( ( zeile = in.readLine() ) != null )
        {
          try
          {
            stmt = conn.createStatement();
            stmt.execute( zeile );
            stmt.close();
            stmt = null;
          }
          catch( SQLException e )
          {
            System.out.println( "SQLException: " + e.getMessage() );
            System.out.println( "SQLState: " + e.getSQLState() );
            System.out.println( "VendorError: " + e.getErrorCode() );
          }
        }

        stmt = conn.createStatement();
        stmt.execute( "GRANT ALL PRIVILEGES ON `dms`.* TO '" + properties.getProperty( "mysql_username" ) + "'@'" + getHost() + "' WITH GRANT OPTION" );

        stmt.close();
        stmt = null;

        if( in != null )
        {
          in.close();
          in = null;
        }
      }

      if( conn != null && !conn.isClosed() )
      {
        conn.close();
        conn = null;
      }

      if( stmt != null && !stmt.isClosed() )
      {
        stmt.close();
        stmt = null;
      }
    }
    catch( SQLException ex )
    {
      createExceptions( ex, ex );
    }
    catch( InstantiationException ex )
    {
      createExceptions( ex, null );
    }
    catch( IllegalAccessException ex )
    {
      createExceptions( ex, null );
    }
    catch( ClassNotFoundException ex )
    {
      createExceptions( ex, null );
    }
    catch( IOException ex )
    {
      createExceptions( ex, null );
    }
  }

  /**
   * Returns the current date with time as string
   */
  private String getCurrentDate()
  {
    return QDateTime.currentDateTime().toString( DateFormat.ISODate );
  }

  /**
   * Returns new user id
   */
  private String createUserId()
  {
    String userId = UUID.randomUUID().toString();
    userId = userId.replaceAll( "_", "" );
    userId = userId.replaceAll( "-", "" );
    userId = userId.replaceAll( "\\{", "" );
    userId = userId.replaceAll( "\\}", "" );

    return userId;
  }

  /**
   * Returns the encoded password
   * 
   * @param username
   *          The user name
   */
  private String encodeUserPwd( String encodedPassword )
  {
    String userPwd = null;

    try
    {
      userPwd = new BASE64Encoder().encode( encodedPassword.getBytes( "UTF-16" ) );
      return userPwd;
    }
    catch( UnsupportedEncodingException e )
    {
      e.printStackTrace();
    }

    return userPwd;

  }

  /**
   * Returns the decoded password
   * 
   * @param encodedPassword
   *          The encoded password
   */
  public static String decodeUserPwd( String encodedPassword )
  {
    String decodedPassword = null;

    try
    {
      decodedPassword = new String( new BASE64Decoder().decodeBuffer( encodedPassword ), "UTF-16" );
      return decodedPassword;
    }
    catch( IOException e )
    {
      e.printStackTrace();
    }

    return decodedPassword;
  }

  /**
   * @return the username
   */
  private String getUsername()
  {
    return userName;
  }

  /**
   * @return the password
   */
  private String getPassword()
  {
    return userPassword;
  }

  /**
   * @return the host
   */
  private String getHost()
  {
    return userHost;
  }

  /**
   * @return the port
   */
  private int getPort()
  {
    return userPort;
  }

  /**
   * @return the database
   */
  private String getDatabase()
  {
    return userDatabase;
  }

  @Override
  public List< DatabaseDTO > getDatabases()
  {
    List< DatabaseDTO > databases = null;

    try
    {
      if( sqlMapper != null )
      {
        databases = sqlMapper.queryForList( "selectDatabase" );
      }
    }
    catch( Exception ex )
    {
      createExceptions( ex, null );
      ex.printStackTrace();
    }

    return databases;
  }
}
