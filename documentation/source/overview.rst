Overview 
--------
General description of the library architecture

Objectives
```````````

The main objective of the library is to provide a common interface to control image-based detectors. This interface might then be used by a taco or tango server to allow integration in spec, or be used directly in a client program like test programs. Integration of new detectors should be as simple as possible which means that the library musst provides all pure software operations (hardware independent operations). Each detector will then benefit from all these operations automatically.

Architecture
````````````
The library will consist of three main layers (see figure):

* **control layer:** this layer will provide a common API to control the image acquisition for all supported detectors. By control, we mean common commands to start/stop acquisition as well as common parameters to setup the acquisition (exposure time, triggering mode, …) This layer will also contains the pure software operations which are independant of the physical controller. These functionnalities will then be available for all supported detectors. Example of such software operations are : file saving, beam position calculations, integral counters...

* **hardware layer:** this layer is the only one communicating with the controller. Each time a new detector will be integrated in LIMA, its hardware layer will have to be coded. As some controller already manages an image buffering system, the image buffering is part of this hardware layer. For those controllers which might not support image buffering, a software image buffer will be provided. This layer provides a standard API for communications with the control layer.

* **detector configuration layer:** each detector has its internal configuration settings which might be very different from one to the other. This layer will provide a way to configure all these detector specific parameters. Each detector supported by LIMA will have a specific configuration layer. Communication to the controller is done through the hardware layer interface. Typical cases: maxipix dacs settings, frelon gain settings, ... These configuration parameters will not include the control parameters already supported by the common control layer. 

.. image:: Lima_architecture_figure.jpg

