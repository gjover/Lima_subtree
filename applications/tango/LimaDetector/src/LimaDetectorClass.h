//=============================================================================
//
// file :         LimaDetectorClass.h
//
// description :  Include for the LimaDetectorClass root class.
//                This class is the singleton class for
//                the LimaDetector device class.
//                It contains all properties and methods which the 
//                LimaDetector requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _LimaDetectorCLASS_H
#define _LimaDetectorCLASS_H
#ifdef WIN32
#include <tango.h>
#endif
#include <LimaDetector.h>

#ifndef WIN32
#include <tango.h>
#endif

namespace LimaDetector_ns
{//=====================================
//	Define classes for attributes
//=====================================
class flipYAttrib: public Tango::Attr
{
public:
	flipYAttrib():Attr("flipY", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~flipYAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_flipY(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_flipY(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_flipY_allowed(ty);}
};

class flipXAttrib: public Tango::Attr
{
public:
	flipXAttrib():Attr("flipX", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~flipXAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_flipX(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_flipX(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_flipX_allowed(ty);}
};

class fileGenerationAttrib: public Tango::Attr
{
public:
	fileGenerationAttrib():Attr("fileGeneration", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~fileGenerationAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_fileGeneration(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_fileGeneration(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_fileGeneration_allowed(ty);}
};

class currentFrameAttrib: public Tango::Attr
{
public:
	currentFrameAttrib():Attr("currentFrame", Tango::DEV_ULONG, Tango::READ) {};
	~currentFrameAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_currentFrame(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_currentFrame_allowed(ty);}
};

class nbFramesAttrib: public Tango::Attr
{
public:
	nbFramesAttrib():Attr("nbFrames", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~nbFramesAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_nbFrames(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_nbFrames(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_nbFrames_allowed(ty);}
};

class binningVAttrib: public Tango::Attr
{
public:
	binningVAttrib():Attr("binningV", Tango::DEV_USHORT, Tango::READ) {};
	~binningVAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_binningV(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_binningV_allowed(ty);}
};

class binningHAttrib: public Tango::Attr
{
public:
	binningHAttrib():Attr("binningH", Tango::DEV_USHORT, Tango::READ) {};
	~binningHAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_binningH(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_binningH_allowed(ty);}
};

class heightAttrib: public Tango::Attr
{
public:
	heightAttrib():Attr("height", Tango::DEV_USHORT, Tango::READ) {};
	~heightAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_height(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_height_allowed(ty);}
};

class widthAttrib: public Tango::Attr
{
public:
	widthAttrib():Attr("width", Tango::DEV_USHORT, Tango::READ) {};
	~widthAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_width(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_width_allowed(ty);}
};

class yAttrib: public Tango::Attr
{
public:
	yAttrib():Attr("y", Tango::DEV_USHORT, Tango::READ) {};
	~yAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_y(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_y_allowed(ty);}
};

class xAttrib: public Tango::Attr
{
public:
	xAttrib():Attr("x", Tango::DEV_USHORT, Tango::READ) {};
	~xAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_x(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_x_allowed(ty);}
};

class exposureAccTimeAttrib: public Tango::Attr
{
public:
	exposureAccTimeAttrib():Attr("exposureAccTime", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~exposureAccTimeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_exposureAccTime(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_exposureAccTime(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_exposureAccTime_allowed(ty);}
};

class exposureTimeAttrib: public Tango::Attr
{
public:
	exposureTimeAttrib():Attr("exposureTime", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~exposureTimeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_exposureTime(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_exposureTime(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_exposureTime_allowed(ty);}
};

class acquisitionModeAttrib: public Tango::Attr
{
public:
	acquisitionModeAttrib():Attr("acquisitionMode", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~acquisitionModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_acquisitionMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_acquisitionMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_acquisitionMode_allowed(ty);}
};

class triggerModeAttrib: public Tango::Attr
{
public:
	triggerModeAttrib():Attr("triggerMode", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~triggerModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_triggerMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<LimaDetector *>(dev))->write_triggerMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_triggerMode_allowed(ty);}
};

class depthAttrib: public Tango::Attr
{
public:
	depthAttrib():Attr("depth", Tango::DEV_USHORT, Tango::READ) {};
	~depthAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_depth(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_depth_allowed(ty);}
};

class sensorHeightAttrib: public Tango::Attr
{
public:
	sensorHeightAttrib():Attr("sensorHeight", Tango::DEV_USHORT, Tango::READ) {};
	~sensorHeightAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_sensorHeight(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_sensorHeight_allowed(ty);}
};

class sensorWidthAttrib: public Tango::Attr
{
public:
	sensorWidthAttrib():Attr("sensorWidth", Tango::DEV_USHORT, Tango::READ) {};
	~sensorWidthAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_sensorWidth(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_sensorWidth_allowed(ty);}
};

class detectorModelAttrib: public Tango::Attr
{
public:
	detectorModelAttrib():Attr("detectorModel", Tango::DEV_STRING, Tango::READ) {};
	~detectorModelAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_detectorModel(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_detectorModel_allowed(ty);}
};

class detectorTypeAttrib: public Tango::Attr
{
public:
	detectorTypeAttrib():Attr("detectorType", Tango::DEV_STRING, Tango::READ) {};
	~detectorTypeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_detectorType(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_detectorType_allowed(ty);}
};

class detectorDescriptionAttrib: public Tango::Attr
{
public:
	detectorDescriptionAttrib():Attr("detectorDescription", Tango::DEV_STRING, Tango::READ) {};
	~detectorDescriptionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<LimaDetector *>(dev))->read_detectorDescription(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<LimaDetector *>(dev))->is_detectorDescription_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class GetAttributeAvailableValuesCmd : public Tango::Command
{
public:
	GetAttributeAvailableValuesCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetAttributeAvailableValuesCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetAttributeAvailableValuesCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_GetAttributeAvailableValues_allowed(any);}
};



class ResetROICmd : public Tango::Command
{
public:
	ResetROICmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ResetROICmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ResetROICmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_ResetROI_allowed(any);}
};



class SetBinningCmd : public Tango::Command
{
public:
	SetBinningCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetBinningCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetBinningCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_SetBinning_allowed(any);}
};



class SetROICmd : public Tango::Command
{
public:
	SetROICmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetROICmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetROICmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_SetROI_allowed(any);}
};



class StopCmd : public Tango::Command
{
public:
	StopCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_Stop_allowed(any);}
};



class StartCmd : public Tango::Command
{
public:
	StartCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StartCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StartCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_Start_allowed(any);}
};



class SnapCmd : public Tango::Command
{
public:
	SnapCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SnapCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SnapCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<LimaDetector *>(dev))->is_Snap_allowed(any);}
};



//
// The LimaDetectorClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	LimaDetectorClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static LimaDetectorClass *init(const char *);
	static LimaDetectorClass *instance();
	~LimaDetectorClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	LimaDetectorClass(string &);
	static LimaDetectorClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace LimaDetector_ns

#endif // _LIMADETECTORCLASS_H
