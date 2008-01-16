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

#include <base64.h>

#include <XMLPreferences.h>

#include <dmsdocument.h>
#include <dmsgroup.h>
#include <dmslogin.h>
#include <dmsmssqlconnection.h>
#include <dmsmysqlconnection.h>
#include <dmspreview.h>
#include <dmsuser.h>
#include <dmsworksheet.h>

#include <libdms.h>

#include <QtCore>
#include <QtGui>
#include <QtSql>

namespace asaal
{
	LibDMS::LibDMS( QObject *parent ) : QObject( parent )
	{
		p_obj = parent;

		username = QString( "" );
		userpasswd = QString( "" );
		errorMessage = QString( "" );

		userId = QString( "" );
		docId = QString( "" );

		sqlDriver.clear();
	}

	bool LibDMS::login( const QString &userId, const QString &userPwd )
	{
		QSqlQuery queryLoginUser( m_qsqld );
		QSqlQuery queryLoginUserUpdate( m_qsqld );
		QString sqlLoginUserQuery = QString( "" );
		sqlLoginUserQuery = "SELECT USERPASSWD FROM USERS WHERE UID = '" + userId + "'";
		queryLoginUser.exec( sqlLoginUserQuery );

		sqlLoginUserQuery.clear();

		if( queryLoginUser.isActive() )
		{
			while( queryLoginUser.next() )
			{
				if( queryLoginUser.value( 0 ).toString() == userPwd )
				{
					queryLoginUserUpdate.exec( "UPDATE USERS SET LOGGEDIN = 1 WHERE UID = '" + userId + "'" );
					if( queryLoginUserUpdate.isActive() )
						return true;

					return true;
				}
				else
				{
					errorMessage = tr( "User password is not correct." );
					logingSqlSession( userId, errorMessage, ERROR );
					return false;
				}
			}
		}
		else
		{
			errorMessage = queryLoginUser.lastError().text();
			logingSqlSession( userId, errorMessage, ERROR );
			return false;
		}

		return false;
	}

	bool LibDMS::logout( const QString &userId )
	{
		QSqlQuery queryUserLoggedOn( m_qsqld );
		QSqlQuery queryUserLoggedOut( m_qsqld );
		QString sqlUserLoggedOnQuery = QString( "" );
		sqlUserLoggedOnQuery = "SELECT LOGGEDIN FROM USERS WHERE UID = '" + userId + "'";
		
		queryUserLoggedOn.exec( sqlUserLoggedOnQuery );
		if( queryUserLoggedOn.isActive() )
			while( queryUserLoggedOn.next() )
				if( queryUserLoggedOn.value( 0 ).toString() == "1" )
				{
					queryUserLoggedOut.exec( "UPDATE USERS SET LOGGEDIN = 0 WHERE UID = '" + userId + "'" );
					if( queryUserLoggedOut.isActive() )
						return true;

					return true;
				}

		return false;
	}

	bool LibDMS::isConnectionAvailabel( const QString &userId )
	{
		QSqlQuery queryUserLoggedOn( m_qsqld );
		QString sqlUserLoggedOnQuery = QString( "" );
		sqlUserLoggedOnQuery = "SELECT LOGGEDIN FROM USERS WHERE UID = '" + userId + "'";
		
		queryUserLoggedOn.exec( sqlUserLoggedOnQuery );
		if( queryUserLoggedOn.isActive() )
		{
			while( queryUserLoggedOn.next() )
				if( queryUserLoggedOn.value( 0 ).toString() == "1" )
					return true;
		}
		
		return false;
	}

	bool LibDMS::closeConnection()
	{
		if( m_qsqld.isOpen() )
		{
			m_qsqld.close();
			return true;
		}

		return false;
	}

	QStringList LibDMS::getSqlDriver()
	{
		sqlDriver = QSqlDatabase::drivers();

		// we are use only QMYSQL at this time
		for( int i = 0; i < sqlDriver.size(); i++ )
		{
			if( sqlDriver.value( i ) == "QMYSQL3" )
				sqlDriver.removeAt( i );
			else if( sqlDriver.value( i ) == "QODBC" )
				sqlDriver.removeAt( i );
			else if( sqlDriver.value( i ) == "QODBC3" )
				sqlDriver.removeAt( i );
			else if( sqlDriver.value( i ) == "QSQLITE" )
				sqlDriver.removeAt( i );
		}

		return sqlDriver;
	}

	QStringList LibDMS::getSqlDatabases()
	{
		QSqlQuery queryDatabaseList( m_qsqld );
		QString sqlDatabaseListQuery = QString( "" );
		sqlDatabaseListQuery = "SELECT SHEMA_NAME FROM INFORMATION_SHEMA.SHEMATA;";
		queryDatabaseList.exec( sqlDatabaseListQuery );

		sqlDatabases.clear();

		if( queryDatabaseList.isActive() )
			while( queryDatabaseList.next() )
				sqlDatabases.append( queryDatabaseList.value( 0 ).toString() );
		else
		{
			errorMessage = queryDatabaseList.lastError().text();
			return sqlDatabases;
		}

		return sqlDatabases;
	}

	QMap<QString, QString> LibDMS::geUsers()
	{
		userList.clear();

		QSqlQuery queryUserList( m_qsqld );

		QString sqlUserListQuery = QString( "" );		
		sqlUserListQuery = "SELECT U.UID, U.USERNAME, U.USERPASSWD, UD.FNAME, UD.LNAME FROM USERS U INNER JOIN USERSDATA UD ON U.UID = UD.UID;";

		queryUserList.exec( sqlUserListQuery );
		if( queryUserList.isActive() )
		{
			while( queryUserList.next() )
			{
				// sql query information about the user data
				QString uid = queryUserList.value( 0 ).toString();
				QString uname = queryUserList.value( 1 ).toString();
				QString upwd = queryUserList.value( 2 ).toString();
				QString fname = queryUserList.value( 3 ).toString();
				QString lname = queryUserList.value( 4 ).toString();
				
				QString udata = uname + "#" + upwd + "#" + fname + "#" + lname;

				userList.insert( uid, udata );
			}
		}
		else
		{
			errorMessage = queryUserList.lastError().text();
			return userList;
		}

		return userList;
	}

	QString LibDMS::getUserId( const QString &user )
	{
		if( user.isNull() || user.isEmpty() )
		{
			errorMessage = tr( "Please enter valid user name." );
			return userId;
		}

		QSqlQuery queryUserId( m_qsqld );
		QString sqlUserIdQuery = QString( "" );
		sqlUserIdQuery = "SELECT UID FROM USERS WHERE USERNAME = '" + user + "'";
		queryUserId.exec( sqlUserIdQuery );

		if( queryUserId.isActive() )
			while( queryUserId.next() )
				userId = queryUserId.value( 0 ).toString();
		else
		{
			errorMessage = queryUserId.lastError().text();
			return userId;
		}

		return userId;
	}

	QMap<QString, QString> LibDMS::geDocuments( const QString &userId )
	{
		documentList.clear();

		QSqlQuery queryGroup( m_qsqld );
		QString sqlGroupQuery = QString( "" );
		QString gname = QString( "" );

		QSqlQuery queryUser( m_qsqld );
		QString sqlUserQuery = QString( "" );
		QString uname = QString( "" );

		QSqlQuery queryDocList( m_qsqld );
		QString sqlDocQuery = QString( "" );
		sqlDocQuery = "SELECT DID, UID, GID, DOCNAME, DOCPATH, UPDATED, CHECKEDOUT FROM DOCUMENTS WHERE UID = '" + userId + "'";
		queryDocList.exec( sqlDocQuery );

		if( queryDocList.isActive() )
		{
			while( queryDocList.next() )
			{
				// sql statement for get user name
				sqlGroupQuery = "SELECT LNAME, FNAME FROM USERSDATA WHERE UID = '" + userId + "'";
				queryUser.exec( sqlGroupQuery );
				if( queryUser.isActive() )
					while( queryUser.next() )
						uname = queryUser.value( 0 ).toString() + ", " + queryUser.value( 1 ).toString();
				else
				{
					errorMessage = queryGroup.lastError().text();
					return documentList;
				}

				// sql statement for get group name
				sqlGroupQuery = "SELECT GROUPNAME FROM GROUPS WHERE GID = '" + queryDocList.value( 2 ).toString() + "'";
				queryGroup.exec( sqlGroupQuery );
				if( queryGroup.isActive() )
					while( queryGroup.next() )
						gname = queryGroup.value( 0 ).toString();
				else
				{
					errorMessage = queryGroup.lastError().text();
					return documentList;
				}


				// sql query information about the document
				QString did = queryDocList.value( 0 ).toString();
				QString uid = uname;
				QString gid = gname;
				QString docname = queryDocList.value( 3 ).toString();
				QString docpath = queryDocList.value( 4 ).toString();
				QString updated = queryDocList.value( 5 ).toString();
				QString checkedout = queryDocList.value( 6 ).toString();

				QString document = uid + "#" + gid + "#" + docname + "#"  + docpath + "#"  + updated + "#" + checkedout;

				documentList.insert( did, document );
			}
		}
		else
			errorMessage = queryDocList.lastError().text();

		return documentList;
	}

	QString LibDMS::getDocId( const QString &userId, const QString &docname  )
	{
		QSqlQuery queryDocId( m_qsqld );
		QString sqlDocIdQuery = QString( "" );
		sqlDocIdQuery = "SELECT DID FROM DOCUMENTS WHERE UID = '" + userId + "' AND DOCNAME = '" + docname + "'";
		queryDocId.exec( sqlDocIdQuery );

		if( queryDocId.isActive() )
			while( queryDocId.next() )
				docId = queryDocId.value( 0 ).toString();
		else
			errorMessage = queryDocId.lastError().text();


		return docId;
	}

	QMap<QString, QString> LibDMS::getGroups()
	{
		groupList.clear();

		QString sqlGroupQuery = QString( "" );
		sqlGroupQuery = "SELECT GID, GROUPNAME, GROUPDESCRIPTION FROM GROUPS;";

		QSqlQuery queryGroup( m_qsqld );
		queryGroup.exec( sqlGroupQuery );

		if( queryGroup.isActive() )
			while( queryGroup.next() )
			{
				groupId = queryGroup.value( 0 ).toString();
				QString gname = queryGroup.value( 1 ).toString();
				QString gdescription = queryGroup.value( 2 ).toString();
				QString groups = gname + "#" + gdescription;

				groupList.insert( groupId, groups );
			}
		else
			errorMessage = queryGroup.lastError().text();

		return groupList;
	}
	
	QString LibDMS::getGroupId( const QString &groupname )
	{		
		QString sqlGroupIdQuery = QString( "" );
		sqlGroupIdQuery = "SELECT GID FROM GROUPS WHERE GROUPNAME = '" + groupname + "'";

		QSqlQuery queryGroupId( m_qsqld );
		queryGroupId.exec( sqlGroupIdQuery );

		if( queryGroupId.isActive() )
			while( queryGroupId.next() )
				groupId = queryGroupId.value( 0 ).toString();
		else
			errorMessage = queryGroupId.lastError().text();

		return groupId;
	}

	void LibDMS::insertUser( const QString &userId, const QString &username, const QString &userpwd, const QString &vname, const QString &nname )
	{
		if( isUserAvailabel( userId, username ) )
		{			
			errorMessage = tr( "You can not insert the same user." );
			logingSqlSession( userId, errorMessage, ERROR );
			return;
		}

		QString sqlInsertUserQuery = QString( "" );
		sqlInsertUserQuery += "INSERT INTO USERS (\n";
		sqlInsertUserQuery += "\tUID,\n";
		sqlInsertUserQuery += "\tUSERNAME,\n";
		sqlInsertUserQuery += "\tUSERPASSWD,\n";
		sqlInsertUserQuery += "\tCREATED,\n";
		sqlInsertUserQuery += "\tUPDATED\n";
		sqlInsertUserQuery += ") VALUES (\n";
		sqlInsertUserQuery += "\t'" + userId + "',\n";
		sqlInsertUserQuery += "\t'" + username + "',\n";
		sqlInsertUserQuery += "\t'" + userpwd + "',\n";
		sqlInsertUserQuery += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "',\n";
		sqlInsertUserQuery += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
		sqlInsertUserQuery += ")\n";

		QSqlQuery queryInsertUser( m_qsqld );
		queryInsertUser.exec( sqlInsertUserQuery );

		if( !queryInsertUser.isActive() )
		{
			errorMessage = queryInsertUser.lastError().text();
			logingSqlSession( userId, errorMessage, ERROR );
			sqlInsertUserQuery.clear();
			return;
		}

		QString sqlInsertUserDataQuery = QString( "" );
		sqlInsertUserDataQuery += "INSERT INTO USERSDATA (\n";
		sqlInsertUserDataQuery += "\tUDID,\n";
		sqlInsertUserDataQuery += "\tUID,\n";
		sqlInsertUserDataQuery += "\tFNAME,\n";
		sqlInsertUserDataQuery += "\tLNAME,\n";
		sqlInsertUserDataQuery += "\tCREATED,\n";
		sqlInsertUserDataQuery += "\tUPDATED\n";
		sqlInsertUserDataQuery += ") VALUES (\n";
		sqlInsertUserDataQuery += "\t'" + QUuid::createUuid().toString().replace( "-", "" ).replace( "{", "" ).replace( "}", "" ) + "',\n";
		sqlInsertUserDataQuery += "\t'" + userId + "',\n";
		sqlInsertUserDataQuery += "\t'" + vname + "',\n";
		sqlInsertUserDataQuery += "\t'" + nname + "',\n";
		sqlInsertUserDataQuery += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "',\n";
		sqlInsertUserDataQuery += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
		sqlInsertUserDataQuery += ")\n";

		QSqlQuery queryInsertUserData( m_qsqld );
		queryInsertUserData.exec( sqlInsertUserDataQuery );
		if( !queryInsertUserData.isActive() )
		{
			errorMessage = queryInsertUserData.lastError().text();
			logingSqlSession( userId, errorMessage, ERROR );
			sqlInsertUserDataQuery.clear();
			return;
		}

		sqlInsertUserQuery.clear();
		sqlInsertUserDataQuery.clear();
	}

	void LibDMS::updateUser( const QString &userId, const QString &username, const QString &userpwd, const QString &vname, const QString &nname )
	{
		if( isUserAvailabel( userId, username ) )
		{
			QString sqlUpdateUserQuery = QString( "" );
			sqlUpdateUserQuery += "UPDATE USERS\n";
			sqlUpdateUserQuery += "\tSET USERNAME = '" + username + "',\n";
			sqlUpdateUserQuery += "\tUSERPASSWD = '" + userpwd + "',\n";
			sqlUpdateUserQuery += "\tUPDATED = '" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
			sqlUpdateUserQuery += "WHERE UID = '" + userId + "'";

			QSqlQuery queryUpdateUser( m_qsqld );
			queryUpdateUser.exec( sqlUpdateUserQuery );
			if( !queryUpdateUser.isActive() )
			{
				errorMessage = queryUpdateUser.lastError().text();
				logingSqlSession( userId, errorMessage, ERROR );
				sqlUpdateUserQuery.clear();
				return;
			}

			QString sqlUpdateUserDataQuery = QString( "" );
			sqlUpdateUserDataQuery += "UPDATE USERSDATA\n";
			sqlUpdateUserDataQuery += "\tSET FNAME = '" + vname + "',\n";
			sqlUpdateUserDataQuery += "\tLNAME = '" + nname + "',\n";
			sqlUpdateUserDataQuery += "\tUPDATED = '" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
			sqlUpdateUserDataQuery += "WHERE UID = '" + userId + "'";

			QSqlQuery queryUpdateUserData( m_qsqld );
			queryUpdateUserData.exec( sqlUpdateUserDataQuery );
			if( !queryUpdateUserData.isActive() )
			{
				errorMessage = queryUpdateUserData.lastError().text();
				logingSqlSession( userId, errorMessage, ERROR );
				sqlUpdateUserDataQuery.clear();
				return;
			}
		}
		else
		{
			errorMessage = tr( "You can not update a user if he is not exists!" );
			logingSqlSession( userId, errorMessage, ERROR );
			return;
		}
	}

	void LibDMS::deleteUser( const QString &userId, const QString &username  )
	{
		if( isUserAvailabel( userId, username ) )
		{
			QString sqlDeleteUserDataQuery = QString( "" );
			sqlDeleteUserDataQuery += "DELETE FROM USERSDATA WHERE UID = '" + userId + "'";

			QSqlQuery queryDeleteUserData( m_qsqld );
			queryDeleteUserData.exec( sqlDeleteUserDataQuery );
			if( !queryDeleteUserData.isActive() )
			{
				errorMessage = queryDeleteUserData.lastError().text();
				logingSqlSession( userId, errorMessage, ERROR );
				sqlDeleteUserDataQuery.clear();
				return;			
			}

			QString sqlDeleteUserQuery = QString( "" );
			sqlDeleteUserQuery += "DELETE FROM USERS WHERE UID = '" + userId + "'";

			QSqlQuery queryDeleteUser( m_qsqld );
			queryDeleteUser.exec( sqlDeleteUserQuery );
			if( !queryDeleteUser.isActive() )
			{
				errorMessage = queryDeleteUser.lastError().text();
				logingSqlSession( userId, errorMessage, ERROR );
				sqlDeleteUserQuery.clear();
				return;
			}

		}
		else
		{
			errorMessage = tr( "You can't delete a user if he not exists!" );
			logingSqlSession( userId, errorMessage, ERROR );
			return;
		}
	}

	void LibDMS::insertDocument( const QString &docId, const QString &userId, const QString &groupId, const QString &docname, const QString &docpath )
	{
		QString sqlInsertDocument = QString( "" );
		sqlInsertDocument += "INSERT INTO DOCUMENTS (\n";
		sqlInsertDocument += "\tDID,\n";
		sqlInsertDocument += "\tUID,\n";
		sqlInsertDocument += "\tGID,\n";
		sqlInsertDocument += "\tDOCNAME,\n";
		sqlInsertDocument += "\tDOCPATH,\n";
		sqlInsertDocument += "\tCHECKEDOUT,\n";
		sqlInsertDocument += "\tCREATED,\n";
		sqlInsertDocument += "\tUPDATED\n";
		sqlInsertDocument += ") VALUES (\n";
		sqlInsertDocument += "\t'" + docId + "',\n";
		sqlInsertDocument += "\t'" + userId + "',\n";
		sqlInsertDocument += "\t'" + groupId + "',\n";
		sqlInsertDocument += "\t'" + docname + "',\n";
		sqlInsertDocument += "\t'" + docpath + "',\n";
		sqlInsertDocument += "\t0,\n";
		sqlInsertDocument += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "',\n";
		sqlInsertDocument += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
		sqlInsertDocument += ")\n";

		QSqlQuery queryInsertDocument( m_qsqld );
		queryInsertDocument.exec( sqlInsertDocument );
		if( !queryInsertDocument.isActive() )
		{
			errorMessage = queryInsertDocument.lastError().text();
			sqlInsertDocument.clear();
			return;
		}

		sqlInsertDocument.clear();
	}

	void LibDMS::updateDocument( const QString &docId, const QString &userId, const QString &groupId, const QString &docname, const QString &docpath )
	{
		QString sqlUpdateDocumentQuery = QString( "" );
		sqlUpdateDocumentQuery += "UPDATE DOCUMENTS\n";
		sqlUpdateDocumentQuery += "\tSET UID = '" + userId + "',\n";
		sqlUpdateDocumentQuery += "\tGID = '" + groupId + "',\n";
		sqlUpdateDocumentQuery += "\tDOCNAME = '" + docname + "',\n";		
		sqlUpdateDocumentQuery += "\tDOCPATH = '" + docpath + "',\n";
		sqlUpdateDocumentQuery += "\tUPDATED = '" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
		sqlUpdateDocumentQuery += "WHERE DID = '" + docId + "'";

		QSqlQuery queryUpdateDocument( m_qsqld );
		queryUpdateDocument.exec( sqlUpdateDocumentQuery );
		if( !queryUpdateDocument.isActive() )
		{
			errorMessage = queryUpdateDocument.lastError().text();
			sqlUpdateDocumentQuery.clear();
			return;
		}

		sqlUpdateDocumentQuery.clear();
	}

	void LibDMS::deleteDocument( const QString &docId, const QString &userId )
	{
		QString sqlDeleteDocumentQuery = QString( "" );
		sqlDeleteDocumentQuery += "DELETE FROM DOCUMENTS WHERE DID = '" + docId + "' AND UID = '" + userId + "'";

		QSqlQuery queryDeleteDocumentQuery( m_qsqld );
		queryDeleteDocumentQuery.exec( sqlDeleteDocumentQuery );
		if( !queryDeleteDocumentQuery.isActive() )
		{
			errorMessage = queryDeleteDocumentQuery.lastError().text();
			sqlDeleteDocumentQuery.clear();
			return;			
		}

		sqlDeleteDocumentQuery.clear();
	}

	void LibDMS::openDocument( const QString &docId )
	{
		QString sqlOpenDocument = QString( "" );
		sqlOpenDocument = "SELECT DOCPATH FROM DOCUMENTS WHERE DID = '" + docId + "'";

		QSqlQuery queryOpenDocument( m_qsqld );
		queryOpenDocument.exec( sqlOpenDocument );
		if( queryOpenDocument.isActive() )
		{
			while( queryOpenDocument.next() )
			{
				QFile openFile( queryOpenDocument.value( 0 ).toString() );
				if( !openFile.open( QIODevice::Text | QIODevice::ReadWrite ) )
				{
					errorMessage = tr( "Can not open file %1" ).arg( queryOpenDocument.value( 0 ).toString() );
					sqlOpenDocument.clear();
					return;
				}

				#ifdef Q_OS_WIN32
					
				#else
				#endif

			}
		}
		else
		{
			errorMessage = queryOpenDocument.lastError().text();
			sqlOpenDocument.clear();
			return;
		}

		sqlOpenDocument.clear();

	}

	void LibDMS::insertGroup( const QString &groupId, const QString &groupname, const QString &groupdescription )
	{
		QString sqlInsertGroupQuery = QString( "" );
		sqlInsertGroupQuery += "INSERT INTO GROUPS (\n";
		sqlInsertGroupQuery += "\tGID,\n";
		sqlInsertGroupQuery += "\tGROUPNAME,\n";
		sqlInsertGroupQuery += "\tGROUPDESCRIPTION,\n";
		sqlInsertGroupQuery += "\tCREATED,\n";
		sqlInsertGroupQuery += "\tUPDATED\n";
		sqlInsertGroupQuery += ") VALUES (\n";
		sqlInsertGroupQuery += "\t'" + groupId + "',\n";
		sqlInsertGroupQuery += "\t'" + groupname + "',\n";
		sqlInsertGroupQuery += "\t'" + groupdescription + "',\n";
		sqlInsertGroupQuery += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "',\n";
		sqlInsertGroupQuery += "\t'" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
		sqlInsertGroupQuery += ")\n";

		QSqlQuery queryInsertGroup( m_qsqld );
		queryInsertGroup.exec( sqlInsertGroupQuery );
		if( !queryInsertGroup.isActive() )
		{
			errorMessage = queryInsertGroup.lastError().text();
			sqlInsertGroupQuery.clear();
			return;
		}

		sqlInsertGroupQuery.clear();
	}

	void LibDMS::updateGroup( const QString &groupId, const QString &groupname, const QString &groupdescription )
	{
		QString sqlUpdateGroupQuery = QString( "" );
		sqlUpdateGroupQuery += "UPDATE GROUPS\n";
		sqlUpdateGroupQuery += "\tSET GROUPNAME = '" + groupname + "',\n";
		sqlUpdateGroupQuery += "\tGROUPDESCRIPTION = '" + groupdescription + "',\n";
		sqlUpdateGroupQuery += "\tUPDATED = '" + QDateTime::currentDateTime().toString( Qt::ISODate ) + "'\n";
		sqlUpdateGroupQuery += "WHERE GID = '" + groupId + "'";

		QSqlQuery queryUpdateGroup( m_qsqld );
		queryUpdateGroup.exec( sqlUpdateGroupQuery );
		if( !queryUpdateGroup.isActive() )
		{
			errorMessage = queryUpdateGroup.lastError().text();
			sqlUpdateGroupQuery.clear();
			return;
		}

		sqlUpdateGroupQuery.clear();
	}

	void LibDMS::deleteGroup( const QString &groupId )
	{
		QString sqlReferenceCheck = QString( "" );
		sqlReferenceCheck += "SELECT COUNT(`GID`) AS GID FROM DOCUMENTS WHERE GID = '" + groupId + "'";

		QSqlQuery queryReferenceCheck( m_qsqld );
		queryReferenceCheck.exec( sqlReferenceCheck );
		if( queryReferenceCheck.isActive() )
		{
			while( queryReferenceCheck.next() )
			{
				if( queryReferenceCheck.value( 0 ).toInt() >= 1 )
				{
					errorMessage = tr( "You can not delete this group. This group is in use." );
					sqlReferenceCheck.clear();
					return;
				}
			}
		}
		
		sqlReferenceCheck.clear();

		QString sqlDeleteGroupQuery = QString( "" );
		sqlDeleteGroupQuery += "DELETE FROM GROUPS WHERE GID = '" + groupId + "'";

		QSqlQuery queryDeleteGroupQuery( m_qsqld );
		queryDeleteGroupQuery.exec( sqlDeleteGroupQuery );
		if( !queryDeleteGroupQuery.isActive() )
		{
			errorMessage = queryDeleteGroupQuery.lastError().text();
			sqlDeleteGroupQuery.clear();
			return;			
		}

		sqlDeleteGroupQuery.clear();
	}

	void LibDMS::showDmsDocument( QWorkspace *ws )
	{
		if( !dmsdocument ) {
			dmsdocument = new DMSDocument( this );
			ws->addWindow( dmsdocument );
			dmsdocument->show();
		} else {			
			dmsdocument->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	void LibDMS::showDmsDocumentPreview( QWorkspace *ws )
	{
		if( !dmspreview ) {
			dmspreview = new DMSPreview( this );
			ws->addWindow( dmspreview );
			dmspreview->show();
		} else {			
			dmspreview->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	void LibDMS::showDmsMySqlConnection()
	{
		QString file = QDir::homePath();
		file.append ( "/.dms/connection/mysql.xml" );

		if( QFile::exists( file ) )
		{
			if( !m_qsqld.isOpen() )
			{
				XMLPreferences dbsettings( "DMSMySqlConnection", "" );
				dbsettings.setVersion( "0.1.0.0" );
				dbsettings.load( file );

				QString user = dbsettings.getString( "MySqlConnection", "UserName" );
				QString upwd = QVariant( Base64::decode( dbsettings.getString( "MySqlConnection", "Password" ) ) ).toString();
				QString host = dbsettings.getString( "MySqlConnection", "HostName" );
				int port =  dbsettings.getInt( "MySqlConnection", "Port" );
				QString database = dbsettings.getString( "MySqlConnection", "Database" );

				m_qsqld = QSqlDatabase::addDatabase( "QMYSQL" );
				m_qsqld.setDatabaseName( database );
				m_qsqld.setUserName( user );
				m_qsqld.setPassword( upwd );
				m_qsqld.setHostName( host );
				m_qsqld.setPort( port );

				upwd.clear();
				if( m_qsqld.open() )
				{
					if( !dmslogin ) {
						dmslogin = new DMSLogin( this );
						dmslogin->exec();
					} else {			
						dmslogin->setFocus( Qt::ActiveWindowFocusReason );
					}
				}
			}
			else
			{
				if( !dmslogin ) {
					dmslogin = new DMSLogin( this );
					dmslogin->exec();

				} else {			
					dmslogin->setFocus( Qt::ActiveWindowFocusReason );
				}
			}
		}
		else
		{
			if( !dmsmysqlconnection ) {
				dmsmysqlconnection = new DMSMySqlConnection();
				if( dmsmysqlconnection->exec() == QDialog::Accepted )
				{
					XMLPreferences dbsettings( "DMSMySqlConnection", "" );
					dbsettings.setVersion( "0.1.0.0" );
					dbsettings.load( file );

					QString user = dbsettings.getString( "MySqlConnection", "UserName" );
					QString upwd = QVariant( Base64::decode( dbsettings.getString( "MySqlConnection", "Password" ) ) ).toString();
					QString host = dbsettings.getString( "MySqlConnection", "HostName" );
					int port =  dbsettings.getInt( "MySqlConnection", "Port" );
					QString database = dbsettings.getString( "MySqlConnection", "Database" );

					m_qsqld = QSqlDatabase::addDatabase( "QMYSQL" );
					m_qsqld.setDatabaseName( database );
					m_qsqld.setUserName( user );
					m_qsqld.setPassword( upwd );
					m_qsqld.setHostName( host );
					m_qsqld.setPort( port );

					upwd.clear();

					if( m_qsqld.open() )
					{
						if( !dmslogin ) {
							dmslogin = new DMSLogin( this );
							dmslogin->exec();
						} else {			
							dmslogin->setFocus( Qt::ActiveWindowFocusReason );
						}
					}
				}
			} else {			
				dmsmysqlconnection->setFocus( Qt::ActiveWindowFocusReason );
			}
		}
	}

	void LibDMS::showDmsMsSqlConnection()
	{
		QString file = QDir::homePath();
		file.append ( "/.dms/connection/mssql.xml" );
		
		if( QFile::exists( file ) )
		{
			if( !m_qsqld.isOpen() )
			{
				XMLPreferences dbsettings( "DMSMSSqlConnection", "" );
				dbsettings.setVersion( "0.1.0.0" );
				dbsettings.load( file );

				QString user = dbsettings.getString( "MSSqlConnection", "UserName" );
				QString upwd = QVariant( Base64::decode( dbsettings.getString( "MSSqlConnection", "Password" ) ) ).toString();
				QString host = dbsettings.getString( "MSSqlConnection", "HostName" );
				QString database = dbsettings.getString( "MSSqlConnection", "Database" );

				m_qsqld = QSqlDatabase::addDatabase( "QODBC" );
				m_qsqld.setDatabaseName("DRIVER={SQL Native Client};Server=" + host + ";Trusted_Connection=no;Integrated Security=True;Database=" + database + ";Uid=" + user + ";Pwd=" + upwd + ";");
				m_qsqld.setUserName(user);
				m_qsqld.setPassword(upwd);
				m_qsqld.setHostName(host);

				upwd.clear();


				if( m_qsqld.open() )
				{
					if( !dmslogin ) {
						dmslogin = new DMSLogin( this );
						dmslogin->exec();
					} else {			
						dmslogin->setFocus( Qt::ActiveWindowFocusReason );
					}
				}
			}
			else
			{
				if( !dmslogin ) {
					dmslogin = new DMSLogin( this );
					dmslogin->exec();

				} else {			
					dmslogin->setFocus( Qt::ActiveWindowFocusReason );
				}
			}
		}
		else
		{
			if( !dmsmssqlconnection ) {
				dmsmssqlconnection = new DMSMSSqlConnection();
				if( dmsmssqlconnection->exec() == QDialog::Accepted )
				{
					XMLPreferences dbsettings( "DMSMySqlConnection", "" );
					dbsettings.setVersion( "0.1.0.0" );
					dbsettings.load( file );

					QString user = dbsettings.getString( "DMSMSSqlConnection", "UserName" );
					QString upwd = QVariant( Base64::decode( dbsettings.getString( "DMSMSSqlConnection", "Password" ) ) ).toString();
					QString host = dbsettings.getString( "DMSMSSqlConnection", "HostName" );
					QString database = dbsettings.getString( "DMSMSSqlConnection", "Database" );

					m_qsqld = QSqlDatabase::addDatabase( "QODBC" );

					upwd.clear();

					if( m_qsqld.open() )
					{
						if( !dmslogin ) {
							dmslogin = new DMSLogin( this );
							dmslogin->exec();
						} else {			
							dmslogin->setFocus( Qt::ActiveWindowFocusReason );
						}
					}
				}
			} else {			
				dmsmssqlconnection->setFocus( Qt::ActiveWindowFocusReason );
			}
		}
		
	}

	void LibDMS::showGroup( QWorkspace *ws )
	{
		if( !dmsgroup ) {
			dmsgroup = new DMSGroup( this );
			ws->addWindow( dmsgroup );
			dmsgroup->show();
		} else {			
			dmsgroup->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	void LibDMS::showDmsUser( QWorkspace *ws )
	{
		if( !dmsuser ) {
			dmsuser = new DMSUser( this, ws );
			ws->addWindow( dmsuser );
			dmsuser->show();
		} else {			
			dmsuser->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	void LibDMS::showDmsWorkSheet( QWorkspace *ws )
	{
		if( !dmsworksheet ) {
			dmsworksheet = new DMSWorkSheet( this );
			ws->addWindow( dmsworksheet );
			dmsworksheet->show();
		} else {			
			dmsworksheet->setFocus( Qt::ActiveWindowFocusReason );
		}
	}

	bool LibDMS::isUserAvailabel( const QString &userId, const QString &username )
	{
		QString sqlIsUserAvailableQuery = QString( "" );
		sqlIsUserAvailableQuery = "SELECT UID FROM USERS WHERE USERNAME = '" + username + "' AND UID = '" + userId + "'";

		QSqlQuery queryIsUserAvailabel( m_qsqld );
		queryIsUserAvailabel.exec( sqlIsUserAvailableQuery );

		if( queryIsUserAvailabel.isActive() )
			while( queryIsUserAvailabel.next() )
				if( !queryIsUserAvailabel.value( 0 ).toString().isNull() || !queryIsUserAvailabel.value( 0 ).toString().isEmpty() )
					return true;

		sqlIsUserAvailableQuery.clear();

		return false;
	}

	void LibDMS::logingSqlSession( const QString &userId, const QString &sessionMessage, LogInfo info )
	{
		QString file = QDir::homePath();
		file.append( "/.dms/log_" + QDateTime::currentDateTime().toString( Qt::ISODate ).replace( ".", "" ) + ".xml" );

		QFile logfile( file );
		if( !logfile.open( QIODevice::Append | QIODevice::WriteOnly ) )
		{
			QMessageBox::critical( 0, tr( "DMS - Logging" ), tr( "Can't open file: \n\n %1" ).arg( file ) );
			return;
		}

		QTextStream log( &logfile );
		log << "<session>\n";
		log << "\t<user uid=\"" << userId << "\">\n";
		
		switch( info )
		{
			case ERROR:
				log << "\t<message type=\"ERROR""\">\n";
				log << "\t\t\t" << sessionMessage << "\n";
				log << "\t</message>\n";
				break;
			case WARNING:
				log << "\t<message type=\"WARNING""\">\n";
				log << "\t\t\t" << sessionMessage << "\n";
				log << "\t</message>\n";
				break;
			case INFO:
				log << "\t<message type=\"INFO""\">\n";
				log << "\t\t\t" << sessionMessage << "\n";
				log << "\t</message>\n";
				break;
		}

		log << "\t</user>\n";
		log << "</session>\n";

		log.flush();
		logfile.close();		
	}
}
