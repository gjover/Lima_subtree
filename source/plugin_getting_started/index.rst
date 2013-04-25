
--------------------------------
Camera plugin developer guide
--------------------------------



Introduction
============
LIMA: Library for IMage Acquisition is a C++ framework for the control of 2D detectors. LIMA currently supports different detectors:

Working:

* Basler: Ace, Scout, Pilot
* Pilatus
* ADSC
* Andor
* Prosilica
* Xpad
* Frelon
* Maxipix
* Mythen
* Ueye
* Roper scientific (princeton)
* PhotonicScience
* PerkinElmer
* PCO (Edge)

Work in progress:

* Andor3 (with sdk V3)
* MarCCD (SX 165)

Planned:

* Aviex
* Quantum
* Eiger
* Xtrip


In order to control/command a new detector using LIMA, a new camera plug-in must be created.

Architecture
============

Library structure
------------------

The library structure divided into two main layers: control, containing the common control and processing code, and hardware, implementing the detector-specific part.
The control layer provides the library interface to the high level application. User requests to configure and control the acquisition are gathered by the control layer,
so the hardware layer functionality is limited to the generation the image frames in a best-effort basis. The control layer is responsible of: 
i) adapting the received image geometry if it does not match the user requests, and ii) execute the frame processing chain.

Understanding the generic Interface
------------------------------------

The Hardware Layer defines the interface between the Control Layer and the controller library. It provides the minimal functionality needed for the Control Layer to
satisfy the user requests. 
The main class in the Hardware Layer is the HwInterface, providing the interface to the Control Layer. In order to provide a flexible and evolvable interface,
the configuration of this layer is implemented as a set of features (capabilities) that may or may not be implemented by the hardware. 
The capabilities can be grouped in three categories: 

1. Standard: includes the synchronization parameters (exposure time, ext. trigger, etc), the detector informations (Detector model, Max size, etc..) is considered standard and must be implemented for all detectors. 
2. Extended\*: optional common features like image transformations (binning, RoI, flip), advanced acquisition modes (kinetics, frame transfer), and extended mechanisms (camera serial line)
3. Specific\*: these are detector-specific features that can not be treated in a generic interface

Hardware Interface << HwInterface>>
-----------------------------------

As an interface to the Control Layer, this class exports the capabilities provided by the hardware: 
* getCapList() 
It also contains the high level commands to control the acquisition: 

* prepare() 
* start() 
* stop() 
* getStatus() 
* getNbAcquiredFrames() 
* getStartTimeStamp() 

The getStatus() function should return the following information: 

=============== ============
Parameters       Description
=============== ============
AcqStatus        Global acquisition status: Ready/Running/Fault
DetStatus        Compound bit flags specifying the current detector status: 
                   * Fault 
                   * WaitForTrigger 
                   * ShutterOpen 
                   * Exposure 
                   * ShutterClose 
                   * ChargeShift 
                   * Readout
DetStatusMask    A mask specifying the detector status bits that are supported by the hardware
=============== ============


.. figure:: hw_interface.jpg
   
   Figure 1.
   
Standard Capabilities
----------------------

These capabilities are mandatory for all the detectors. They define the minimum functionality necessary for image acquisition. 

Detector Information <<HwDetInfoCtrlObj>>
``````````````````````````````````````````````

This capability returns static information about the detector and the current image dimension. 

=============== ======================================================================================================
Parameters       Description
=============== ======================================================================================================
MaxImageSize     Maximum size of the image
DefImageType     Default data type of image (ushort, ulong, ...)
CurrImageSize    Current maximum size of the image, excluding binning and RoI. This is a read-only parameter
CurrImageType    Data type of image (ushort, ulong, ...)
PixelSize        Physical size of pixels (in micrometre)
DetectorType     Type of the detector (Frelon, Maxipix, ...)
DetectorModel    Model of the detector
=============== ======================================================================================================

Synchronization << HwSyncCtrlObj >> 
``````````````````````````````````````````````

This capability return/set acquisition parameters.


================ ======================================================================================================
Parameters       Description
================ ======================================================================================================
AcqNbFrames      Number of frames to acquire. This defines an acquisition sequence. If set to 0, endless acquisition

AcqExposureTime  Frame exposure time                                                                        
LatencyTime      Latency time between frames
AcqFrameMode     Acquisition frame mode:
                   * Single: default standard mode
                   * Accumulation: one frame is an accumulation of multiple frames 
                   * Concatenation: one frame is a concatenation of several frames
AccNbFrames      in case of AcqFraeMode==Accumulation only:
                 sets the number of accumulated sub-frames. This automatically update AccExposureTime. 
AccExposureTime  in case of AcqFrameMode==Accumulation only:
                 sets the exposure time for each sub-frame. This automatically update NbAccFrames.
ConcatNbFrames   in case of AcqFrameMode==Concatenation only
                 sets the number of concatenated sub-frame to define one ready frame. The total number of frame to 
                 acquire is still set by AcqNbFrames
TriggerMode      Triggering mode:
                   * Internal: software triggering 
                   * ExtStart: one external signal to start the whole sequence acquisition (one or more frames per 
                     sequence) 
                   * MultExtStart: one external signal for each frame in the acquisition sequence 
                   * Gate: controls start and stop of each frame 
                   * ExtStartStop: one start signal to start acquisition of one frame and one signal to stop it
ShutterMode      External Shutter mode: 
                   * Manual 
                   * AutoPerFrame: shutter automatically open and close for each frame 
                   * AutoPerSequence: shutter automatically open at the beginning of a sequence and close at the end
ShutterOpenTime  Opening time of the shutter
ShutterCloseTime Closing time of the shutter
ReadoutTime      Read-Only frame readout time
FrameRate        Read-Only frame rate in Hz
================ ======================================================================================================

Buffer Management << HwBufferCtrlObj >>
``````````````````````````````````````````````

This block controls the image memory buffer allocation and management. They are used: 
* As temporary frame storage before saving, allowing disk/network speed fluctuations. 
* To permanently hold images that can be read by the user after the acquisition is finished. 

These buffer functionalities may be implemented by the hardware layer (kernel driver in the case of the Espia). 
If not, an auxiliary buffer manager class will be provided to facilitate (and unify) its software implementation. 
The buffer management parameters are: 

=============== ======================================================================================================
Parameters       Description
=============== ======================================================================================================
NbBuffers        Number of image buffers in memory.
NbConcatFrames   The number of concatenated frames per buffer.
NbAccFrames      The number of detector frames to accumulate into a single buffer.
MaxNbBuffers     This Read-Only parameter indicates the maximum number of buffers that can be allocated, 
                 given the size of the frame and the number of (concatenated) frames per buffer.
BufferMode       Buffer filling mode (linear or circular)
=============== ======================================================================================================

The buffer manager must also provide the following methods: 
* getBufferPtr(int buffer_nb) 
* getFramePtr(int acq_frame_nb) 
* getFrameTimeStamp(int acq_frame_nb) 

Frame callback
``````````````````````````````````````````````

The hardware must provide callbacks after each acquired frame. The callback function should receive the following information: 

=============== ======================================================================================================
Parameters       Description
=============== ======================================================================================================
AcqFrameNb       Index of the frame since the start of the acquisition
FramePtr         Pointer to the frame memory
FrameDim         Structure holding the width, height and type of the frame
TimeStamp        Time (in sec.) since the start of the acquisition
=============== ======================================================================================================

The frame callbacks are implemented by means of an auxiliary class (FrameCallback), which will be used by the Control Layer.
From the Hardware Layer point of view, the standard capability control object must implement two functions: 

* setFrameCallbackActive(bool cb_active) 
* frameReady(<callback_frame_info>) 


Development of a new camera plug-in
======================================

For each new type of detector **detectorname**, a camera plug-in must be created and added to Lima.
The integration of **detectorname** plug-in in Lima is done in several stages:

Add source files of the plug-in to the Lima project
----------------------------------------------------

The source files of each plug-in are located under Lima/camera directory as shown in Figure 2

.. figure:: dir_structure.png
   
   Figure 2.
   
Filenames
------------

To maintain homogeneity between the different plug-ins, each plug-in must have at minimum the following files:
DetectorNameCamera.cpp 	(to put in the subdirectory src/)
DetectorNameCamera.h 	(to put in the subdirectory include/)

DetectorNameInterface.cpp 	(to put in the subdirectory src/)
DetectorNameInterface.h 	(to put in the subdirectory include/)

Additionally, there could be others files depending of the camera capabilities. Here is the nomenclature to follow:

For Sync capability: (trigger types\.\.\.)

DetectorNameSyncCtrlObj.cpp 	(to put in the subdirectory \src)
DetectorNameSyncCtrlObj.h 		(to put in the subdirectory \include)

For Det Info capability: (image size, pixel size\.\.\.)

DetectorNameDetInfoCtrlObj.cpp 	(to put in the subdirectory \src)
DetectorNameDetInfoCtrlObj.h 	(to put in the subdirectory \include)

For Roi capability:

DetectorNameRoiCtrlObj.cpp 		(to put in the subdirectory \src)
DetectorNameRoiCtrlObj.h 		(to put in the subdirectory \include)

For Binning capability:

DetectorNameBinCtrlObj.cpp 		(to put in the subdirectory \src)
DetectorNameBinCtrlObj.h 		(to put in the subdirectory \include)


Of course, there can also be other files source for specific cases.

Class names
------------

Again, to maintain homogeneity, it is recommended to follow this nomenclature for the class names:

* **DetectorName**::Camera

* **DetectorName**::Interface

* **DetectorName**::SyncCtrlObj

* **DetectorName**::DetInfoCtrlObj
 
As an example, one can look at the Prosilica plugin for a real implementation or at the simulator plugin for a implementation model.

Use the Interface:  client side
--------------------------------

In order to communicate with the underlying detector hardware, the lima client must instantiate the main object of the framework Lima: CtControl.
To be instantiated, the CtControl requires an interface inherited from common HwInterface.
This interface requires the Camera object that encapsulates dependency with detector and its API driver.

For instance if you are using the python binding for the Prosilica camera, a client application initialization should do:

.. code-block:: python

   from Lima import Prosilica as ProsilicaAcq
   from Lima import Core

   my_prosilica_ip_address = 192.168.1.2
   # we need the camera object first
   camera = Prosilica.camera(my_prosilica_ip_address)

   # create the HwInterface which needs the camera as unique parameter
   camera_interface =  ProsilicaAcq.Interface(camera)

   # Now create the CtControl and passed to Lima the new HwInterface
   Control = Core.CtControl(camera_interface)

The camera is now under control and it can be used  to acquire images !
First get the sub-objects for the parameter setting of the detector, acquisition, saving and more if necessary.

.. code-block:: python

   acq = control.acquisition()
   saving = control.saving()

   acq.setAcqExpoTime(0.1)
   acq.setAcqNbFrames(10)

   pars=saving.getParameters()
   pars.directory='/buffer/test_lima'
   pars.prefix='test1_'
   pars.suffix='.edf'
   pars.fileFormat=Core.CtSaving.EDF
   pars.savingMode=Core.CtSaving.AutoFrame
   saving.setParameters(pars)
   
   # pass parameters to camera hw interface
   control.prepareAcq()
   
   # start the acquisition
   control.startAcq()


*NB*:
Camera object is only used to enhance the separation between the generic interface and the API driver of the detector. It is similar to a proxy.

The camera class is also supposed to provide an access to the specific configuration of the detector. For instance if your detector has a threshold setting or a built-in background correction available you should implement these features in the Camera class. The HwInterface will not know about the specific configuration and a client application should explicitly implement the configuration. A good example is the Andor camera, where there are few extra features  like the temperature set-point (set/getTemperatureST()) or the cooler control (set/getCooler(bool)).

With the Andor camera one can set the cooling as:

.. code-block:: python
 
   camera.setTemperatureSP(-50)
   camera.setCooler(True)

   current_temp = Camera.getTemperature()


The Lima project code provides some client application based on TANGO protocol for the remote access.
One can find a python implementation under applications/tango and a C++ version in applications/tango/LimaDetector.
The python server has been developed at ESRF and being used on lot of beamlines and the C++ server is the SOLEIL version which is also used on beamlines.

The python server interface has a documentation available at lima.blissgarden.org (applications/tango/doc/index.html).


.. figure:: client_interface.png
