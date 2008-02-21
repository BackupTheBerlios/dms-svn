/***************************************************************************
 *   Copyright (C) 2007-2008 by Alexander Saal                             *
 *   alex.saal@gmx.de                                                      *
 *                                                                         *
 *   File: ${filename}.${extension}                                        *
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

#include <dmsmailaction.h>

#include <QtCore>
#include <QtGui>

DMSMailAction::DMSMailAction( const QString &acText, QObject *parent  ) : QAction( acText, parent )
{
	_mailaddress = QString( "" );
	_subject = QString( "" );
	_message = QString( "" );
	_attachment = QString( "" );
}

QString DMSMailAction::getMailAddress()
{
	return _mailaddress;
}

QString DMSMailAction::getSubject()
{
	return _subject;
}

QString DMSMailAction::getMessage()
{
	return _message;
}

QString DMSMailAction::getAttachment()
{
	return _attachment;
}

void DMSMailAction::setMailAdress( const QString &mailaddress )
{
	_mailaddress = mailaddress;
}

void DMSMailAction::setSubject( const QString &subject )
{
	_subject = subject;
}

void DMSMailAction::setMessage( const QString &message )
{
	_message = message;
}

void DMSMailAction::setAttachment( const QString &attachment )
{
	_attachment = attachment;
}
