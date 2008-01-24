﻿/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   This MySQL Script is part of DMS - Document Magament System           *
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
#
CREATE DATABASE IF NOT EXISTS `DMS`;
USE `DMS`;
#
CREATE TABLE IF NOT EXISTS `USERS`
(
  `UID` NVARCHAR(50) NOT NULL,
  `USERNAME` NVARCHAR(45) NOT NULL,
  `USERPASSWD` NVARCHAR(255),
  `LOGGEDIN` INT NOT NULL DEFAULT 0,
  `CREATED` DATETIME NOT NULL,
  `UPDATED` DATETIME,
  PRIMARY KEY `USERS_P_KEY`( `UID` ),
  INDEX `INDEX_UID` ( `UID` )
);
#
CREATE TABLE IF NOT EXISTS `GROUPS`
(
  `GID` NVARCHAR(50) NOT NULL,
  `GROUPNAME` NVARCHAR(100) NOT NULL,
  `GROUPDESCRIPTION` NVARCHAR(255),
  `CREATED` DATETIME NOT NULL,
  `UPDATED` DATETIME,
  PRIMARY KEY `GROUP_P_KEY`( `GID` ),
  INDEX `INDEX_DID` ( `GID` )
);
#
CREATE TABLE IF NOT EXISTS `DOCUMENTS`
(
  `DID` NVARCHAR(50) NOT NULL,
  `UID` NVARCHAR(50) NOT NULL,
  `GID` NVARCHAR(50) NOT NULL,
  `DOCNAME` NVARCHAR(255) NOT NULL,  
  `DOCPATH` NVARCHAR(255) NOT NULL,
  `CHECKEDOUT` INT NOT NULL DEFAULT 0,
  `CREATED` DATETIME NOT NULL,
  `UPDATED` DATETIME,
  PRIMARY KEY `DOC_P_KEY`( `DID` ),
  FOREIGN KEY `DOC_F_KEY_UID`( `UID` ) REFERENCES `USERS`( `UID` ),
  FOREIGN KEY `DOC_F_KEY_GID`( `GID` ) REFERENCES `GROUPS`( `GID` ),
  INDEX `INDEX_DID` ( `DID` )
);
#
CREATE TABLE IF NOT EXISTS `USERSDATA`
(
  `UDID` NVARCHAR(50) NOT NULL,
  `UID` NVARCHAR(50) NOT NULL,
  `FNAME` NVARCHAR(45) NOT NULL,
  `LNAME` NVARCHAR(45) NOT NULL,
  `STREETNAME` NVARCHAR(100),
  `STREETNR` NVARCHAR(10),
  `CITY` NVARCHAR(50),
  `ZIPCODE` NVARCHAR(50),
  `COUNTRY` NVARCHAR(255),
  `CREATED` DATETIME NOT NULL,
  `UPDATED` DATETIME,
  PRIMARY KEY `USERDATA_P_KEY`( `UDID` ),
  FOREIGN KEY `USERDATA_F_KEY`( `UID` ) REFERENCES `USERS`( `UID` ),
  INDEX `INDEX_UDID` ( `UDID` )
);
#
CREATE TABLE IF NOT EXISTS `SETTINGS`
(
  `ID` INTEGER NOT NULL AUTO_INCREMENT,
  `SETT_WIDGET_NAME` NVARCHAR(50) NOT NULL,
  `SETT_SECTION` VARCHAR(256) NOT NULL,
  `SETT_KEY` VARCHAR(256) NOT NULL,
  `SETT_VALUE` VARCHAR(256),
  `CREATED` DATETIME NOT NULL,
  `UPDATED` DATETIME,
  PRIMARY KEY `SETTINGS_P_KEY`( `ID` ),
  INDEX `INDEX_UDID` ( `ID` )
);
#
LOCK TABLES `USERS` WRITE;
INSERT INTO `USERS`
(
  `UID`,
  `USERNAME`,
  `USERPASSWD`,
  `CREATED`,
  `UPDATED`
) VALUES (
  'a677c4e4d9e04deaa40abd3e21a8cd47',
  'Administrator',
  'YWRtaW5pc3RyYXRvcg==', -- administrator, change it after first login
  CURRENT_DATE,
  CURRENT_DATE
);
UNLOCK TABLES;
#
LOCK TABLES `GROUPS` WRITE;
INSERT INTO `GROUPS`
(
  `GID`,
  `GROUPNAME`,
  `GROUPDESCRIPTION`,
  `CREATED`,
  `UPDATED`
) VALUES (
  'b6d80cef14084a5b95643ea010484855',
  'Default',
  'Default group for all documents.',
  CURRENT_DATE,
  CURRENT_DATE
);
UNLOCK TABLES;