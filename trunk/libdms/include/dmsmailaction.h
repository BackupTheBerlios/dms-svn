/***************************************************************************
 *   Copyright (C) 2008 by Alexander Saal                                  *
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

#ifndef DMSMAILACTION_H
#define DMSMAILACTION_H

#include <dllexport.h>

#include <QtCore>
#include <QtGui>

namespace asaal
{
	/*!
	* @author Alexander Saal <alex.saal@gmx.de>
	* @sa http://chmaster.freeforge.net
	* @date 2008/01/30
	* @version 0.1.0.0
	* @since 0.1.0.0
	*/

	class EXPORT_ASAAL DMSMailAction : public QAction
	{

			Q_OBJECT

			Q_CLASSINFO( "Author", "Alexander Saal" )
			Q_CLASSINFO( "EMAIL", "alex.saal@gmx.de" )
			Q_CLASSINFO( "URL", "http://chmaster.freeforge.net" )

		public:
			DMSMailAction( const QString &acText, QObject *parent );
			inline virtual ~DMSMailAction() {}

			/*!
			 * Get the subject for this eMail
			 */
			QString getSubject();

			/*!
			 * Get the message for this eMail
			 */
			QString getMessage();

			/*!
			 * Get the attachment for this eMail
			 */
			QString getAttachment();

		public slots:

			/*!
			 * Set the subject for this eMail
			 *
			 * @param subject The subject
			 */
			void setSubject( const QString &subject );

			/*!
			 * Set the message for this eMail
			 *
			 * @param message The message
			 */
			void setMessage( const QString &message );

			/*!
			 * Set the attachment for this eMail
			 *
			 * @param attachment The attachment
			 */
			void setAttachment( const QString &attachment = QString( "" ) );

		private:
			QString _subject;
			QString _message;
			QString _attachment;

	};
}

#endif // DMSMAILACTION_H
