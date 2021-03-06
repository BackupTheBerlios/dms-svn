--/***************************************************************************
-- *   Copyright (C) 2008 by Alexander Saal                                  *
-- *   alex.saal@gmx.de                                                      *
-- *                                                                         *
-- *   This MS SQL Script is part of DMS - Document Magament System          *
-- *                                                                         *
-- *   This program is free software; you can redistribute it and/or modify  *
-- *   it under the terms of the GNU General Public License as published by  *
-- *   the Free Software Foundation; either version 2 of the License, or     *
-- *   (at your option) any later version.                                   *
-- *                                                                         *
-- *   This program is distributed in the hope that it will be useful,       *
-- *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
-- *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
-- *   GNU General Public License for more details.                          *
-- *                                                                         *
-- *   You should have received a copy of the GNU General Public License     *
-- *   along with this program; if not, write to the                         *
-- *   Free Software Foundation, Inc.,                                       *
-- *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
-- ***************************************************************************/

USE [MASTER]


USE [DMS]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[GROUPS]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[GROUPS](
	[GID] [nvarchar](50) NOT NULL,
	[GROUPNAME] [nvarchar](100) NOT NULL,
	[GROUPDESCRIPTION] [nvarchar](255) NULL,
	[CREATED] [datetime] NOT NULL,
	[UPDATED] [datetime] NULL,
 CONSTRAINT [PK_GROUPS] PRIMARY KEY CLUSTERED 
(
	[GID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[USERS]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[USERS](
	[UID] [nvarchar](50) NOT NULL,
	[USERNAME] [nvarchar](45) NOT NULL,
	[USERPASSWD] [nvarchar](255) NULL,
	[LOGGEDIN] [smallint] NULL,
	[CREATED] [datetime] NULL,
	[UPDATED] [datetime] NULL,
 CONSTRAINT [PK_USERS] PRIMARY KEY CLUSTERED 
(
	[UID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[DOCUMENTS]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[DOCUMENTS](
	[DID] [nvarchar](50) NOT NULL,
	[UID] [nvarchar](50) NOT NULL,
	[GID] [nvarchar](50) NOT NULL,
	[DOCNAME] [nvarchar](255) NOT NULL,
	[DOCPATH] [nvarchar](255) NULL,
	[CHECKEDOUT] [smallint] NOT NULL,
	[CREATED] [datetime] NOT NULL,
	[UPDATED] [datetime] NULL,
 CONSTRAINT [PK_DOCUMENTS] PRIMARY KEY CLUSTERED 
(
	[DID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
END
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
IF NOT EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID(N'[dbo].[USERSDATA]') AND type in (N'U'))
BEGIN
CREATE TABLE [dbo].[USERSDATA](
	[UDID] [nvarchar](50) NOT NULL,
	[UID] [nvarchar](50) NOT NULL,
	[FNAME] [nvarchar](45) NOT NULL,
	[LNAME] [nvarchar](45) NOT NULL,
	[STREETNAME] [nvarchar](100) NULL,
	[CITY] [nvarchar](50) NULL,
	[ZIPCODE] [nvarchar](50) NULL,
	[COUNTRY] [nvarchar](50) NULL,
	[CREATED] [datetime] NOT NULL,
	[UPDATED] [datetime] NULL,
 CONSTRAINT [PK_USERSDATA] PRIMARY KEY CLUSTERED 
(
	[UDID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
END
GO
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_DOCUMENTS_DOCUMENTS]') AND parent_object_id = OBJECT_ID(N'[dbo].[DOCUMENTS]'))
ALTER TABLE [dbo].[DOCUMENTS]  WITH CHECK ADD  CONSTRAINT [FK_DOCUMENTS_DOCUMENTS] FOREIGN KEY([UID])
REFERENCES [dbo].[USERS] ([UID])
GO
ALTER TABLE [dbo].[DOCUMENTS] CHECK CONSTRAINT [FK_DOCUMENTS_DOCUMENTS]
GO
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_DOCUMENTS_GROUPS]') AND parent_object_id = OBJECT_ID(N'[dbo].[DOCUMENTS]'))
ALTER TABLE [dbo].[DOCUMENTS]  WITH CHECK ADD  CONSTRAINT [FK_DOCUMENTS_GROUPS] FOREIGN KEY([GID])
REFERENCES [dbo].[GROUPS] ([GID])
GO
ALTER TABLE [dbo].[DOCUMENTS] CHECK CONSTRAINT [FK_DOCUMENTS_GROUPS]
GO
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_USERS_USERS]') AND parent_object_id = OBJECT_ID(N'[dbo].[USERS]'))
ALTER TABLE [dbo].[USERS]  WITH CHECK ADD  CONSTRAINT [FK_USERS_USERS] FOREIGN KEY([UID])
REFERENCES [dbo].[USERS] ([UID])
GO
ALTER TABLE [dbo].[USERS] CHECK CONSTRAINT [FK_USERS_USERS]
GO
IF NOT EXISTS (SELECT * FROM sys.foreign_keys WHERE object_id = OBJECT_ID(N'[dbo].[FK_USERSDATA_USERS]') AND parent_object_id = OBJECT_ID(N'[dbo].[USERSDATA]'))
ALTER TABLE [dbo].[USERSDATA]  WITH CHECK ADD  CONSTRAINT [FK_USERSDATA_USERS] FOREIGN KEY([UID])
REFERENCES [dbo].[USERS] ([UID])
GO
ALTER TABLE [dbo].[USERSDATA] CHECK CONSTRAINT [FK_USERSDATA_USERS]
GO

INSERT INTO USERS
(
  UID,
  USERNAME,
  USERPASSWD,
  CREATED,
  UPDATED
) VALUES (
  'a677c4e4d9e04deaa40abd3e21a8cd47',
  'Administrator',
  'YWRtaW5pc3RyYXRvcg==', -- administrator, change it after first login
  GETDATE(),
  GETDATE()
)
GO

INSERT INTO GROUPS
(
  GID,
  GROUPNAME,
  GROUPDESCRIPTION,
  CREATED,
  UPDATED
) VALUES (
  'b6d80cef14084a5b95643ea010484855',
  'Default',
  'Default group for all documents.',
  GETDATE(),
  GETDATE()
)
GO