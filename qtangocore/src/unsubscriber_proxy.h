/***************************************************************************
*   Copyright (C) 2008 by Giacomo Strangolino	   *
*   giacomo.strangolino@elettra.trieste.it   *
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

/* $Id: unsubscriber_proxy.h,v 1.2 2008-09-03 10:16:57 giacomo Exp $ */


#ifndef UNSUBSCRIBER_PROXY_H
#define UNSUBSCRIBER_PROXY_H

#include <QObject>
#include <QString>

#include "taction.h"


class UnsubscriberProxy
{
	public:
		UnsubscriberProxy(QString s, 
			RefreshMode m,
      			int period = 1000 );
		
		void unsubscribe();
		
	private:
		QString d_source;
		int d_period;
		RefreshMode d_desiredMode;
	
};


#endif
