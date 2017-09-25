static const char *RcsId = "$Id $";
//+=============================================================================
//
// file :        main.cpp
//
// description : C++ source for a TANGO device server main.
//               The main rule is to initialise (and create) the Tango
//               system and to create the DServerClass singleton.
//               The main should be the same for every Tango device server.
//
// project :     TANGO Device Server
//
// $Author: giacomo $
//
// $Revision: 1.1 $ $
// $Date: 2009-12-07 08:32:28 $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source: /home/cvsadm/cvsroot/utils/qtango/qtango/test/LightTestServer/main.cpp,v $
// $Log: main.cpp,v $
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


int main(int argc,char *argv[])
{

	Tango::Util *tg;
	try
	{
		// Initialise the device server
		//----------------------------------------
		tg = Tango::Util::init(argc,argv);

		// Create the device server singleton 
		//	which will create everything
		//----------------------------------------
		tg->server_init(false);

		// Run the endless loop
		//----------------------------------------
		cout << "Ready to accept request" << endl;
		tg->server_run();
	}
	catch (bad_alloc)
	{
		cout << "Can't allocate memory to store device object !!!" << endl;
		cout << "Exiting" << endl;
	}
	catch (CORBA::Exception &e)
	{
		Tango::Except::print_exception(e);
		
		cout << "Received a CORBA_Exception" << endl;
		cout << "Exiting" << endl;
	}
	tg->server_cleanup();
	return(0);
}