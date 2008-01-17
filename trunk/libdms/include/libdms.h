/***************************************************************************
*   Copyright (C) 2007 by Alexander Saal                                  *
*   alex.saal@gmx.de                                                      *
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
			* For internal user enumaration
			*
			* @param ERROR
			* @param WARNING
			* @param INFO
			*/
			enum logInfo
			{
				ERROR = 1,
				WARNING = 2,
				INFO = 3
			};
			Q_DECLARE_FLAGS( LogInfo, logInfo )

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
			* @param userId The user id
			*
			* @return <a href="http://doc.trolltech.com/4.3/qmap.html#QMap">QMap</a><DocId, Documents> with all users
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
			* Show the document preview widget
			*
			* @param ws The Workspace to add this widget
			*/
			void showDmsDocumentPreview( QWorkspace *ws );

			/*!
			* Show MySQL Server Connection Assistant
			*/
			void showDmsMySqlConnection();
			
			/*!
			* Show MS SQL Server 2005 / MS Access Connection Assistant
			*/
			void showDmsMsSqlConnection();

			/*!
			* Show the group widget
			*
			* @param ws The Workspace to add this widget
			*/
			void showGroup( QWorkspace *ws );

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
			* Clear error message ...
			*/
			void clearErrorMessage() { errorMessage = QString( "" ); }

		private slots:
			/*!
			 * Log all operation for the actually session
			 *
			 * @param sessionMessage The message to log
			 */
			void logingSqlSession( const QString &userId, const QString &sessionMessage, LogInfo info );

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

			QObject *p_obj;

			QSqlDatabase m_qsqld;
			QSqlRecord m_qsqlr;
			QSqlError m_qsqle;

			QMap<QString, QString> userList;
			QMap<QString, QString> groupList;
			QMap<QString, QString> documentList;

	};

	Q_DECLARE_OPERATORS_FOR_FLAGS( LibDMS::LogInfo )
}

#endif // LIBDMS_H
