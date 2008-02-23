/*
QTwain interface class set
Copyright (C) 2002-2003         Stephan Stapel
                                stephan.stapel@web.de

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QDebug>

#include "dib.h"
#include "qtwaininterface.h"





QTwainInterface::QTwainInterface(QWidget* parent)
{
	m_bEmitPixmaps = false;
	setParent(parent);	
} // !QTwainInterface()



QTwainInterface::~QTwainInterface()
{
	setParent(0);
} // !~QTwainInterface()



void QTwainInterface::setParent(QWidget* parent)
{	
	m_pParent = parent;
	if (parent)
	{
		if (!onSetParent())
		{
			/**
			 * @todo print error message
			 */
		}
	}
} // !setParent()



QPixmap QTwainInterface::convertToPixmap(CDIB* pDib, unsigned int nWidth, unsigned int nHeight)
{	
	if (!pDib)
		return QPixmap( 0, 0 );

	unsigned int nUseWidth  = nWidth;
	unsigned int nUseHeight = nHeight;

	if (nUseWidth == 0)
		nUseWidth = pDib->Width();

	if (nUseHeight == 0)
		nUseHeight = pDib->Height();

	QPixmap* retval = new QPixmap( nUseWidth, nUseHeight );
	pDib->BitBlt( retval->getDC(), 0, 0, nUseWidth, nUseHeight, 0, 0 );

	QPixmap _retval;
	_retval = retval->copy( 0, 0, retval->width(), retval->height() );

	return _retval;
} // !convertToPixmap()



QImage QTwainInterface::convertToImage(CDIB* pDib, unsigned int nWidth, unsigned int nHeight)
{	
	if (!pDib)
		return QImage( 0, 0 );

	unsigned int nUseWidth  = nWidth;
	unsigned int nUseHeight = nHeight;

	if (nUseWidth == 0)
		nUseWidth = pDib->Width();
	if (nUseHeight == 0)
		nUseHeight = pDib->Height();	

	//QPixmap pixmap(pDib->Width(), pDib->Height(), 32, QPixmap::MemoryOptim);
	//pDib->BitBlt(pixmap.handle(), 
	//	         0, 0, 
	//			 pDib->Width(), pDib->Height(),
	//			 0, 0);

	//QImage* retval = new QImage( pixmap.convertToImage().smoothScale(nUseWidth, nUseHeight) );
	QImage *image = new QImage( nUseWidth, nUseHeight, QImage::Format_RGB32 );
	pDib->BitBlt( image->getDC(), 0, 0, pDib->Width(), pDib->Height(), 0, 0);

	QImage retval = image->convertToFormat( QImage::Format_RGB32 );

	return retval;
} // !convertToImage()



CDIB* QTwainInterface::convertToDib(QPixmap* pPixmap, unsigned int nWidth, unsigned int nHeight)
{	
	CDIB* pRetval = new CDIB();

	/**
	 * @todo implement this function
	 */

	return pRetval;
} // !convertToDib()



bool QTwainInterface::onSetParent()
{
	// nothing in the base class
	return true;
} // !onSetParent()
