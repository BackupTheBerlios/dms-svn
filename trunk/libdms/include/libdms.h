/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: libdms.h                                                        *
 *   Desc: ${description}                                                  *
 *                                                                         *
 *   This file is part of DMS - Documnet Management System                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef LIBDMS_H
#define LIBDMS_H

#include <dllexport.h>

#include <QtCore>
#include <QtGui>
#include <QtSql>

class EXPORT_ASAAL LibDMS;

#ifdef Q_OS_WIN32
	extern EXPORT_ASAAL LibDMS *libdms;
#else
	extern LibDMS *libdms;
#endif

/*!
* @author Alexander Saal <alex.saal@gmx.de>
* @sa http://chmaster.freeforge.net
* @date 2007/11/30 
* @version 0.1.0.1
* @since 0.1.0.1
*/

class EXPORT_ASAAL LibDMS : public QObject
{
		Q_OBJECT

		Q_CLASSINFO( "Author", "Alexander Saal" )
		Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
		Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

	public:
    /**
     * \brief User information
     * 
     * @date 2009/01/24 
     * @version 0.1.0.1
     * @since 0.1.0.1
     */ 
    struct UserInfo {

      /**
       * User ID
       */ 
      QString userId;
      
      /**
       * User name
       */ 
      QString userName;
      
      /**
       * User password (decrypted)
       */ 
      QString userPwd;

      /**
       * Last name from user
       */ 
      QString lastName;
      
      /**
       * First name from user
       */ 
      QString firstName;
      
      /**
       * User updated?
       */ 
      bool update;
    };

    /**
    * \brief Document information
    * 
    * @date 2009/01/24 
    * @version 0.1.0.1
    * @since 0.1.0.1
    */ 
    struct DocumentInfo {

      /**
       * Document ID
       */
      QString docId;

      /**
       * Group ID
       */
      QString groupId;

      /**
       * User ID
       */
      QString userId;

      /**
       * Document name
       */
      QString docName;

      /**
       * Document path
       */
      QString docPath;

      /**
       * Document updated?
       */
      QString update;

      /**
       * Document checked out?
       */
      QString checkedOut;
    };

    /**
    * \brief Group information
    * 
    * @date 2009/01/24 
    * @version 0.1.0.1
    * @since 0.1.0.1
    */
    struct GroupInfo {
      /**
       * Group ID
       */ 
      QString groupId;

      /**
       * Group name
       */ 
      QString groupName;

      /**
       * Group description
       */ 
      QString groupDescription;

      /**
       * Group updated?
       */ 
      bool update;
    };

		/*!
		* Columns in the database
		*
		* @param ALL
		* @param DOCUMENTS
		* @param GROUPS
		* @param SETTINGS
		* @param USERS
		* @param USERSDATA
		*/
		enum tableColumns
		{
			ALL = 0,
			DOCUMENTS = 1,
			GROUPS = 2,
			SETTINGS = 3,
			USERS = 4,
			USERSDATA = 5
		};
		Q_DECLARE_FLAGS( TableColumns, tableColumns )

		/*!
		* Default constructor
		*
		* @param ws @see <a href="http://doc.trolltech.com/4.4/qworkspace.html#QWorkspace">QWorkspace</a> (default is NULL)
		* @param parent <a href="http://doc.trolltech.com/4.4/qobject.html#QObject">QObject</a> (default is NULL)		
		*/
		LibDMS( QWorkspace *ws = 0, QObject *parent = 0 );
		
		/*
		 * \breif De-Constructor
	 	 */
		inline virtual ~LibDMS() { libdms = NULL; }
		
		/**
		 * Return the instance of dms library
		 * This is needed if you create a plug in for DMS
		 */
		static LibDMS *libdms_instcance() {	return libdms; }
		
		/**
		 * Returns the @see <a href="http://doc.trolltech.com/4.4/qworkspace.html#QWorkspace">QWorkspace</a>
		 */
		QWorkspace *workspace() { return _ws; }

		/*!
		* Login user
		*
		* @param userId The user id
		* @param userPwd The user password
		*
		* @return true if login successfully otherwise false
		*/
		bool login( const QString &userId, const QString &userPwd );

		/*!
		* Logout user
		*
		* @param userId The user id
		*
		* @return true if login successfully otherwise false
		*/
		bool logout( const QString &userId );

		/*!
		* Check if user connected
		*
		* @param userId The user id
		*/
		bool isConnectionAvailabel( const QString &userId );

		/*!
		* Close database connection
		*
		* @return true if connection closed
		*/
		bool closeConnection();

		/*!
		* Get the Qt4 SQL Driver
		*
		* @return <a href="http://doc.trolltech.com/4.4/qstringlist.html#QStringList">QStringList</a> with qt4 sql driver
		*/
		QStringList getSqlDriver();

		/*!
		* Get the SQL Databases
		*
		* @return <a href="http://doc.trolltech.com/4.4/qstringlist.html#QStringList">QStringList</a> with sql databases
		*/
		QStringList getSqlDatabases();

		/*!
		* Get the table columns from database
		*
		* @return <a href="http://doc.trolltech.com/4.4/qmap.html#QMap">QMap</a><TableName, Columns>
		*/
		QMap<QString, QStringList> getTabelColumns( TableColumns tablecolumns );

		/*!
		* The logged user. This variables are set if you login into DMS
		*
		* @return The user are logged in
		*		
		* @code
		* QString userid = libdms->getUserId( libdms->loggedUser );
		* QMap<QString, QString> userdocuments = libdms->geDocuments( userid );
		* @endcode
		*/
		QString loggedUser;

		/*!
		* Get the user from database
		*
		* @return <a href="http://doc.trolltech.com/4.4/qmap.html#QMap">QMap</a><UserId, UserName> with all users
		*/
		QList< UserInfo* > geUsers();

		/*!
		* Get the user id
		*
		* @return User id for the given user name (login name)
		*/
		QString getUserId( const QString &user );

		/*!
		* Get all documents from database
		*
		*
		* @return <a href="http://doc.trolltech.com/4.4/qmap.html#QMap">QMap</a><DocId, Documents> with all users
		*/
		QList< DocumentInfo* > geDocuments();

		/*!
		* Get documents from database
		*
		* @param userId The user id
		*
		* @return <a href="http://doc.trolltech.com/4.4/qmap.html#QMap">QMap</a><DocId, Documents>
		*/
		QList< DocumentInfo* > geDocuments( const QString &userId );

		/*!
		* Get the document id
		*
		* @param userId The user id
		* @param docname The document name
		* @return The id from document
		*/
		QString getDocId( const QString &userId, const QString &docname );

		/*!
		* Get the groups from database
		*
		* @return <a href="http://doc.trolltech.com/4.4/qmap.html#QMap">QMap</a><GroupId, Group> with all groups
		*/
		QMap<QString, QString> getGroups();

		/*!
		* Get the group id
		*
		* @return Group id for the given group name
		*/
		QString getGroupId( const QString &groupname );

		/*!
		 * Get the application settings
		 *
		 * @param widgetname The widget name
		 * @param section The section for application settings
		 * @param key The key for determine the value
		 * @param defaultValue The default value of settings
		 */
		QVariant getApplicationSettings( const QString &widgetname, const QString &section, const QString &key, const QVariant &defaultValue = QVariant() );

		/*!
		 * Get the application settings
		 *
		 * @param widgetname The widget name
		 * @param section The section for application settings
		 *
		 * @return <a href="http://doc.trolltech.com/4.4/qmap.html#QMap">QMap</a><App, AppExt> with all application settings
		 */
		QMap<QString, QString> getApplicationSettings( const QString &widgetname, const QString &section );

		/*!
		* Get the error message, if exist.
		*
		* @return <a href="http://doc.trolltech.com/4.4/qstring.html#QString">QString</a> with error message
		*/
		QString getErrorMessage()
		{
			return errorMessage;
		}

	public slots:
		/*!
		* Create/Insert user
		*
		* @param userId The user id
		* @param userpwd The user password
		* @param username The user name for login
		* @param vname The name of user like: Max
		* @param nname The name of user like: Mustermann
		*/
		void insertUser( const QString &userId, const QString &username, const QString &userpwd, const QString &vname, const QString &nname );

		/*!
		* Update user
		*
		* @param userId The user id
		* @param username The user name
		* @param userpwd The user password
		* @param vname The name of user like: Max
		* @param nname The name of user like: Mustermann
		*/
		void updateUser( const QString &userId, const QString &username, const QString &userpwd, const QString &vname, const QString &nname );

    /*!
    * Delete user
    *
    * @param userInfo TThe @see UserInfo
    */
    void deleteUser( const UserInfo &userInfo );

		/*!
		* Create/Insert document
		*
		* @param docId The document id
		* @param userId The user id
		* @param groupId The group id
		* @param docname The name of document
		* @param docpath The path of document
		*/
		void insertDocument( const QString &docId, const QString &userId, const QString &groupId, const QString &docname, const QString &docpath );

		/*!
		* Update document
		*
		* @param docId The document id
		* @param userId The user id
		* @param groupId The group id
		* @param docname The name of document
		* @param docpath The path of document
		*/
		void updateDocument( const QString &docId, const QString &userId, const QString &groupId, const QString &docname, const QString &docpath );

		/*!
		* Delete document
		*
		* @param docId The document id
		* @param userId The user id
		*/
		void deleteDocument( const QString &docId, const QString &userId );

		/*!
		* Check out document
		*
		* @param docId The document id
		*/
		void openDocument( const QString &docId );

		/*!
		* Insert group
		*
		* @param groupId The group id
		* @param groupname The group name
		* @param groupdescription The group description (can be empty)
		*/
		void insertGroup( const QString &groupId, const QString &groupname, const QString &groupdescription = QString( "" ) );

		/*!
		* Update group
		*
		* @param groupId The group id
		* @param groupname The group name
		* @param groupdescription The group description (can be empty)
		*/
		void updateGroup( const QString &groupId, const QString &groupname, const QString &groupdescription = QString( "" ) );

		/*!
		* Delete group
		*
		* @param groupId The group id
		*/
		void deleteGroup( const QString &groupId );

		/*!
		 * Insert settings for the dms application
		 *
		 * @param widgetname The widgetname
		 * @param section The section for application settings
		 * @param key The key for determine the value
		 * @param value  The value of application settings (optional)
		 */
		void insertApplicationSettings( const QString &widgetname, const QString &section, const QString &key, const QString &value = QString() );

		/*!
		 * Show the preference widget
		 */
		void showDmsPreference( QWorkspace *ws );

		/*!
		* Show the database selection dialog
		*/
		void showDmsDatabaseSelection();

		/*!
		* Show the document widget
		*
		* @param ws The Workspace to add this widget
		*/
		void showDmsDocument( QWorkspace *ws );

		/*!
		* Show the search widget
		*
		* @param ws The Workspace to add this widget
		*/
		void showDmsSearch( QWorkspace *ws );

		/*!
		* Show MySQL Server Connection Assistant
		*/
		void showDmsMySqlConnection();

		/*!
		* Show the group widget
		*
		* @param ws The Workspace to add this widget
		*/
		void showDmsGroup( QWorkspace *ws );

		/*!
		* Show the user widget
		*
		* @param ws The Workspace to add this widget
		*/
		void showDmsUser( QWorkspace *ws );

		/*!
		* Show the work sheet widget
		*
		* @param ws The Workspace to add this widget
		*/
		void showDmsWorkSheet( QWorkspace *ws );

		/*!
		* Send email (a simple solution, not the best but is enough)
		* The e-Mail client on your system is used.
		*
		* @param email The e-Mail address
		* @param subject The subject for this e-Mail (optional)
		* @param attachment The attachment for this e-Mail (optional)
		* @param message The message for this e-Mail (optional)
		*/
		void sendMail( const QString &email, const QString &subject = QString( "" ), const QString &attachment = QString( "" ), const QString &message = QString( "" ) );

		/*!
		 * Clear error message ...
		 */
		void clearErrorMessage() { errorMessage = QString( "" ); }

  private slots:
    /*!
     * Delete user
     *
     * @param userId The user id
     * @param username The user name
     */
    void deleteUser( const QString &userId, const QString &username );

		/*!
		 * Process was closed
		 */
		void processFinish( int, QProcess::ExitStatus );

		/*!
		 * Process called a error
		 */
		void processError( QProcess::ProcessError );

	private:
		// Check is user in database avalaibel
		bool isUserAvailabel( const QString &userId, const QString &username );

		// Local variables
		QWorkspace *_ws;

		QString userId;
		QString groupId;
		QString docId;

		QString username;
		QString userpasswd;
		QString errorMessage;

		QStringList sqlDriver;
		QStringList sqlDatabases;
		QStringList sqlColumns;

		QObject *p_obj;

		QSqlDatabase m_qsqld;
		QSqlRecord m_qsqlr;
		QSqlError m_qsqle;

    UserInfo *userInfo;
		QList< UserInfo* > userList;
		QMap<QString, QString> groupList;
    //QMap<QString, QString> documentList;
    DocumentInfo *m_documentInfo;
    QList< DocumentInfo * > m_documentList;
		QMap<QString, QString> appSettList;
		QMap<QString, QStringList> tableColumnList;

};

Q_DECLARE_OPERATORS_FOR_FLAGS( LibDMS::TableColumns )

#endif // LIBDMS_H
