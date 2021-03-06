static const char *ClassId    = "$Id: LightTestClass.cpp,v 1.2 2010-01-28 08:38:47 giacomo Exp $";
static const char *TagName    = "$Name: release_5_4_0 $";
static const char *CvsPath    = "$Source: /home/cvsadm/cvsroot/utils/qtango/qtango/test/LightTestServer/LightTestClass.cpp,v $";
static const char *SvnPath    = "$HeadURL: $";
static const char *HttpServer = "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        LightTestClass.cpp
//
// description : C++ source for the LightTestClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the LightTest once per process.
//
// project :     TANGO Device Server
//
// $Author: giacomo $
//
// $Revision: 1.2 $
//
// $Log: LightTestClass.cpp,v $
// Revision 1.2  2010-01-28 08:38:47  giacomo
// TPushButton intercetta dragLeaveEvent per chiamare setDown(false) durante il drag.
// TestLight ha qualche comando in piu`
//
// Revision 1.1  2009/12/07 08:32:28  giacomo
// LightTest server.
// read README
//
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>

#include <LightTest.h>
#include <LightTestClass.h>


//+----------------------------------------------------------------------------
/**
 *	Create LightTestClass singleton and return it in a C function for Python usage
 */
//+----------------------------------------------------------------------------
extern "C" {
#ifdef WIN32

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_LightTest_class(const char *name) {
		return LightTest_ns::LightTestClass::init(name);
	}
}


namespace LightTest_ns
{
//+----------------------------------------------------------------------------
//
// method : 		AValueClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *AValueClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "AValueClass::execute(): arrived" << endl;

	return insert((static_cast<LightTest *>(device))->avalue());
}

//+----------------------------------------------------------------------------
//
// method : 		MultiplyByTenClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *MultiplyByTenClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "MultiplyByTenClass::execute(): arrived" << endl;

	Tango::DevDouble	argin;
	extract(in_any, argin);

	return insert((static_cast<LightTest *>(device))->multiply_by_ten(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		OnClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *OnClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "OnClass::execute(): arrived" << endl;

	((static_cast<LightTest *>(device))->on());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		OffCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *OffCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "OffCmd::execute(): arrived" << endl;

	((static_cast<LightTest *>(device))->off());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		SineWaveCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *SineWaveCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "SineWaveCmd::execute(): arrived" << endl;

	const Tango::DevVarShortArray	*argin;
	extract(in_any, argin);

	return insert((static_cast<LightTest *>(device))->sine_wave(argin));
}





//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
LightTestClass *LightTestClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::LightTestClass(string &s)
// 
// description : 	constructor for the LightTestClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
LightTestClass::LightTestClass(string &s):DeviceClass(s)
{

	cout2 << "Entering LightTestClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();
	
	cout2 << "Leaving LightTestClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::~LightTestClass()
// 
// description : 	destructor for the LightTestClass
//
//-----------------------------------------------------------------------------
LightTestClass::~LightTestClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
LightTestClass *LightTestClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new LightTestClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

LightTestClass *LightTestClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void LightTestClass::command_factory()
{
	command_list.push_back(new SineWaveCmd("SineWave",
		Tango::DEVVAR_SHORTARRAY, Tango::DEVVAR_DOUBLEARRAY,
		"0:max abs value of the sine wave amplitude. 1:number of points",
		"The sine wave",
		Tango::OPERATOR));
	command_list.push_back(new OffCmd("Off",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new OnClass("On",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new MultiplyByTenClass("MultiplyByTen",
		Tango::DEV_DOUBLE, Tango::DEV_DOUBLE,
		"Any double value",
		"the argin multiplied by 10",
		Tango::OPERATOR));
	command_list.push_back(new AValueClass("AValue",
		Tango::DEV_VOID, Tango::DEV_DOUBLE,
		"",
		"a random value",
		Tango::OPERATOR));

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum LightTestClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum LightTestClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum LightTestClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void LightTestClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new LightTest(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//	Method: LightTestClass::attribute_factory(vector<Tango::Attr *> &att_list)
//-----------------------------------------------------------------------------
void LightTestClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	//	Attribute : Double_scalar
	Double_scalarAttrib	*double_scalar = new Double_scalarAttrib();
	att_list.push_back(double_scalar);

	//	Attribute : Short_scalar
	Short_scalarAttrib	*short_scalar = new Short_scalarAttrib();
	att_list.push_back(short_scalar);

	//	End of Automatic code generation
	//-------------------------------------------------------------
}

//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void LightTestClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	LightTestClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void LightTestClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "Timeout";
	prop_desc = "If this property contains the name of an attribute, that attribute will\ngive a timeout when read.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "DoNotUpdate";
	prop_desc = "If the property contains the name of an attribute, that attribute will\nnot be updated on read, generating an exception on the client.";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		LightTestClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void LightTestClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("LightTest");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("A very lightweight tango test device, with a couple of attributes which");
	str_desc.push_back("return a random value whose module is less than their write value.");
	str_desc.push_back("If their write value is 0, then the value returned is between -255 and 255");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs or svn location
	string	filename(classname);
	filename += "Class.cpp";
	
	// Create a string with the class ID to
	// get the string into the binary
	string	class_id(ClassId);
	
	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}
	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_4Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace
