.. _compilation:

Compilation
===========

.. _linux_compilation:

Linux
`````

Every think is managed by root Makefile. 

* So first generate the config.inc file.

.. code-block:: sh

  make

* Edit the configuration file **config.inc** 

.. code-block:: sh

  COMPILE_CORE=1
  COMPILE_SIMULATOR=1
  COMPILE_SPS_IMAGE=1
  COMPILE_ESPIA=0
  COMPILE_FRELON=0
  COMPILE_MAXIPIX=0
  COMPILE_PILATUS=0
  COMPILE_CBF_SAVING=0
  export COMPILE_CORE COMPILE_SPS_IMAGE COMPILE_SIMULATOR \
         COMPILE_ESPIA COMPILE_FRELON COMPILE_MAXIPIX COMPILE_PILATUS \
         COMPILE_CBF_SAVING

* Configure all module and stuff (don't need if you just want C++ libraries)

.. code-block:: sh

  make config

* Finally compile all C++ libraries

.. code-block:: sh

  make

* If you need Python modules

.. code-block:: sh

  make -C sip -j3

**That's all folks ;)**

Windows
```````
Visual studio lima project is configured up to now to run on Windows XP, It's not optimised for new threading of Windows Vista or 7. If you want to optimise, you have to remove on all projects, the precompilation directive _WIN32_WINNT=0x0502 (mean Windows XP SP2).

*Compilation Steps:*

* On this platform there is not automatic build.
  You have to build all C/C++ libraries by your own with Visual Studio.
  Visual Studio projects are under :

  - third-party/Processlib/build/msvc/9.0/libprocesslib
  
  - build/msvc/9.0/LimaCore

  - camera/*NAME_OF_THE_CAMERA*/msvc/9.0/Lib*NAME_OF_THE_CAMERA*

  Open projects one by one and compile them in that order.

* Then use the python script called **windowsSipCompilation.py** to configure and compile Python Modules.

  - Module configuration:

    .. code-block:: sh

      python windowsSipCompilation.py --config


  - Then the compilation:

    .. code-block:: sh

      python windowsSipCompilation.py



**Warning** As Lima libraries are threaded, you can't mixed Release and Debug.
You **MUST** have to compile all libraries with the same mode.

**Warning** For those who make a Hardware Interface for Lima, you have to add the precompile directive _WIN32_WINNT=0x0502 to your Visual Studio project if your project use some threads.
