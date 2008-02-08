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

namespace asaal
{
	/*!
	* @author Alexander Saal <alex.saal@gmx.de>
	* @sa http://chmaster.freeforge.net
	* @date 2007/11/30
	* @version 0.1.0.0
	* @since 0.1.0.0
	*/

	class EXPORT_ASAAL LibDMS : public QObject
	{
			Q_OBJECT

			Q_CLASSINFO( "Author", "Alexander Saal" )
			Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
			Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

		public:

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
			* @param parent <a href="http://doc.trolltech.com/4.3/qobject.html#QObject">QObject</a> (default is NULL)
			*/
			LibDMS( QObject *parent = 0 );
			inline virtual ~LibDMS() {}

			/*!
			* Login user
			*
			* @param userId The user id
			* @param userPwd The user password
			*
			* @return true if login seccesfull otherwise false
			*/
			bool login( const QString &userId, const QString &userPwd );

			/*!
			* Logout user
			*
			* @param userId The user id
			*
			* @return true if login seccesfull otherwise false
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
			* Get the qt4 sql driver
			*
			* @return <a href="http://doc.trolltech.com/4.3/qstringlist.html#QStringList">QStringList</a> with qt4 sql driver
			*/
			QStringList getSqlDriver();

			/*!
			* Get the sql databases
			*
			* @return <a href="http://doc.trolltech.com/4.3/qstringlist.html#QStringList">QStringList</a> with sql databases
			*/
			QStringList getSqlDatabases();

			/*!
			* Get the table columns from database
			*
			* @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><TableName, Columns>
			*/
			QMap<QString, QStringList> getTabelColumns( TableColumns tablecolumns );

			/*!
			* The logged user
			*
			*/
			QString loggedUser;

			/*!
			* Get the user from database
			*
			* @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><UserId, UserName> with all users
			*/
			QMap<QString, QString> geUsers();

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
			* @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><DocId, Documents> with all users
			*/
			QMap<QString, QString> geDocuments();

			/*!
			* Get documents from database
			*
			* @param userId The user id
			*
			* @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><DocId, Documents>
			*/
			QMap<QString, QString> geDocuments( const QString &userId );

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
			* @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><GroupId, Group> with all groups
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
			 * @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><App, AppExt> with all application settings
			 */
			QMap<QString, QString> getApplicationSettings( const QString &widgetname, const QString &section );

			/*!
			* Get the error message, if exist.
			*
			* @return <a href="http://doc.trolltech.com/4.3/qstring.html#QString">QString</a> with error message
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
			* @param userId The user id
			* @param username The user name
			*/
			void deleteUser( const QString &userId, const QString &username );

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
			 * @param value  The <a href="http://doc.trolltech.com/4.3/qvariant.html#QVariant">QVariant</a> as value of application settings (optional)
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
			* We are use your mail client on you system.
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
			void clearErrorMessage()
			{
				errorMessage = QString( "" );
			}

		private slots:
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

			QMap<QString, QString> userList;
			QMap<QString, QString> groupList;
			QMap<QString, QString> documentList;
			QMap<QString, QString> appSettList;
			QMap<QString, QStringList> tableColumnList;

	};

	Q_DECLARE_OPERATORS_FOR_FLAGS( LibDMS::TableColumns )
}

#endif // LIBDMS_H
