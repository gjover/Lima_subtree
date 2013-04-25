############################################################################
# This file is part of LImA, a Library for Image Acquisition
#
# Copyright (C) : 2009-2011
# European Synchrotron Radiation Facility
# BP 220, Grenoble 38043
# FRANCE
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
############################################################################

import itertools
import weakref
import PyTango
import sys
import numpy
import processlib
from Lima import Core
from Utils import getDataFromFile,BasePostProcess

#==================================================================
#   RoiCounter Class Description:
#
#
#==================================================================


class RoiCounterDeviceServer(BasePostProcess) :

#--------- Add you global variables here --------------------------
    ROI_COUNTER_TASK_NAME = "RoiCounterTask"
#------------------------------------------------------------------
#    Device constructor
#------------------------------------------------------------------
    def __init__(self,cl, name):
	self.__roiCounterMgr = None
                
	BasePostProcess.__init__(self,cl,name)
	RoiCounterDeviceServer.init_device(self)

    def set_state(self,state) :
	if(state == PyTango.DevState.OFF) :
	    if(self.__roiCounterMgr) :
		self.__roiCounterMgr = None
		ctControl = _control_ref()
		extOpt = ctControl.externalOperation()
		extOpt.delOp(self.ROI_COUNTER_TASK_NAME)
	elif(state == PyTango.DevState.ON) :
	    if not self.__roiCounterMgr:
                ctControl = _control_ref()
                extOpt = ctControl.externalOperation()
                self.__roiCounterMgr = extOpt.addOp(Core.ROICOUNTERS,self.ROI_COUNTER_TASK_NAME,
                                                    self._runLevel)
            self.__roiCounterMgr.clearCounterStatus()
            
	PyTango.Device_4Impl.set_state(self,state)

#------------------------------------------------------------------
#    Read BufferSize attribute
#------------------------------------------------------------------
    def read_BufferSize(self, attr):
	value_read = self.__roiCounterMgr.getBufferSize()
	attr.set_value(value_read)


#------------------------------------------------------------------
#    Write BufferSize attribute
#------------------------------------------------------------------
    def write_BufferSize(self, attr):
	data = attr.get_write_value()
        self.__roiCounterMgr.setBufferSize(data)


#------------------------------------------------------------------
#    Read CounterStatus attribute
#------------------------------------------------------------------
    def read_CounterStatus(self, attr):
	value_read = self.__roiCounterMgr.getCounterStatus()
	attr.set_value(value_read)


#==================================================================
#
#    RoiCounter command methods
#
#==================================================================
    def add(self,argin):
        if not len(argin) % 4:
            self.__roiCounterMgr.add(self.__get_roi_list_from_argin(argin))
        else:
            raise AttributeError('should be a roi vector as follow [x0,y0,width0,height0,x1,y1,width1,heigh1,...')
    
    def set(self,argin):
        if not len(argin) % 4:
            self.__roiCounterMgr.set(self.__get_roi_list_from_argin(argin))
        else:
            raise AttributeError('should be a roi vector as follow [x0,y0,width0,height0,x1,y1,width1,heigh1,...')

    
    def get(self):
        returnList = []
        for roi in self.__roiCounterMgr.get():
            p = roi.getTopLeft()
            s = roi.getSize()
            returnList.extend((p.x,p.y,s.getWidth(),s.getHeight()))
        return returnList

    def clearAllRoi(self):
        self.__roiCounterMgr.clearAllRoi()

    def setMaskFile(self,argin) :
        mask = getDataFromFile(*argin)
        self.__roiCounterMgr.setMask(mask)
    
    def readCounters(self,argin) :
        roiResultCounterList = self.__roiCounterMgr.readCounters(argin)
        if roiResultCounterList:
            minListSize = len(roiResultCounterList[0][1])
            for roiId,resultList in roiResultCounterList:
                if minListSize > len(resultList):
                    minListSize = len(resultList)

            
            if minListSize :
                returnArray = numpy.zeros(minListSize * len(roiResultCounterList) * 6 + 1,dtype = numpy.double)
                returnArray[0] = float(minListSize)
                indexArray = 1
                for roiId,resultList in roiResultCounterList:
                    for result in resultList[:minListSize] :
                        returnArray[indexArray:indexArray+6] = (float(result.frameNumber),
                                                                result.sum,
                                                                result.average,
                                                                result.std,
                                                                result.minValue,
                                                                result.maxValue)
                        indexArray += 6
                return returnArray
        return numpy.array([0],dtype = numpy.double)

    def __get_roi_list_from_argin(self,argin) :
        rois = []
        for x,y,w,h in itertools.izip(itertools.islice(argin,0,len(argin),4),
                                      itertools.islice(argin,1,len(argin),4),
                                      itertools.islice(argin,2,len(argin),4),
                                      itertools.islice(argin,3,len(argin),4)) :
            roi = Core.Roi(x,y,w,h)
            rois.append(roi)
        return rois
#==================================================================
#
#    RoiCounterClass class definition
#
#==================================================================
class RoiCounterDeviceServerClass(PyTango.DeviceClass):

    #	 Class Properties
    class_property_list = {
	}


    #	 Device Properties
    device_property_list = {
	}


    #	 Command definitions
    cmd_list = {
        'add':
        [[PyTango.DevVarLongArray,"roi vector [x0,y0,width0,height0,x1,y1,width1,heigh1,...]"],
         [PyTango.DevVoid,""]],
        'set':
        [[PyTango.DevVarLongArray,"roi vector [x0,y0,width0,height0,x1,y1,width1,heigh1,...]"],
	[PyTango.DevVoid,""]],
        'get':
        [[PyTango.DevVoid,""],
        [PyTango.DevVarLongArray,"roi vector [x0,y0,width0,height0,x1,y1,width1,heigh1,...]"]],
        'clearAllRoi':
        [[PyTango.DevVoid,""],
         [PyTango.DevVoid,""]],
        'setMaskFile':
        [[PyTango.DevVarStringArray,"Full path of mask file"],
         [PyTango.DevVoid,""]],
        'readCounters':
        [[PyTango.DevLong,"from which frame"],
         [PyTango.DevVarDoubleArray,"number of result for each roi,frame number 0,sum 0,average 0,std 0,min 0,max 0,frame number 1,sum 1,average 1,std 1,min 1,max 1..."]],
	'Start':
	[[PyTango.DevVoid,""],
	 [PyTango.DevVoid,""]],
	'Stop':
	[[PyTango.DevVoid,""],
	 [PyTango.DevVoid,""]],
	}


    #	 Attribute definitions
    attr_list = {
	'BufferSize':
	    [[PyTango.DevLong,
	    PyTango.SCALAR,
	    PyTango.READ_WRITE]],
	'CounterStatus':
	    [[PyTango.DevLong,
	    PyTango.SCALAR,
	    PyTango.READ]],
	'RunLevel':
	    [[PyTango.DevLong,
	    PyTango.SCALAR,
	    PyTango.READ_WRITE]],
	}


#------------------------------------------------------------------
#    RoiCounterDeviceServerClass Constructor
#------------------------------------------------------------------
    def __init__(self, name):
	PyTango.DeviceClass.__init__(self, name)
	self.set_type(name);



_control_ref = None
def set_control_ref(control_class_ref) :
    global _control_ref
    _control_ref= control_class_ref

def get_tango_specific_class_n_device() :
   return RoiCounterDeviceServerClass,RoiCounterDeviceServer
