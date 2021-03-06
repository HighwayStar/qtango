static const char *RcsId = "$Id: ClassFactory.cpp,v 1.1 2009-12-07 08:32:28 giacomo Exp $";
//+=============================================================================
//
// file :        ClassFactory.cpp
//
// description : C++ source for the class_factory method of the DServer
//               device class. This method is responsible for the creation of
//               all class singleton for a device server. It is called
//               at device server startup
//
// project :     TANGO Device Server
//
// $Author: giacomo $
//
// $Revision: 1.1 $
// $Date: 2009-12-07 08:32:28 $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source: /home/cvsadm/cvsroot/utils/qtango/qtango/test/LightTestServer/ClassFactory.cpp,v $
// $Log: ClassFactory.cpp,v $
// Revision 1.1  2009-12-07 08:32:28  giacomo
// LightTest server.
// read README
//
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>
#include <LightTestClass.h>

/**
 *	Create LightTestClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{

	add_class(LightTest_ns::LightTestClass::init("LightTest"));

}
