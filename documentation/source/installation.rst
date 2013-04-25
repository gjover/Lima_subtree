.. _installation:

Installation
============

.. _linux_installation:

Linux
`````
Installation on Linux is pretty easy because it's manage by Makefile.
But those Makefile can only be used if you have compile everything including Python modules. Otherwise It'll failed.
See :ref:`linux_compilation` compilation

.. code-block:: sh

  make install

you can specify the destination path with this variable **INSTALL_DIR**

By the way, this command only install C++ libraries and Python module, :ref:`tango_installation` is an other step.

.. _windows_installation:

Windows
```````
On this platform we tried to automatized the installation but It's wasn't strait forward. The only simple way we found is with Python script.
So the script is called **windowsInstall.py**

The script can install  C/C++ library provided by company, C++ Lima libraries, Python modules and Tango device servers.
It's don't managed dependencies (At least for now). So you have to know what you should install.

:command: windowsInstall.py

  :option: -h, --help

    show help message and exit

  :option: --install_dir=INSTALL_DIR

    install directory path

  :option: --add=MODULE_LIST

    Add a module to install

  :option: --set=MODULE_SET_LIST

    Set the module list to install, do not read config.inc file

  :option: --available-modules

    List all possible modules to install
  
  :option: --all

    install all possible module

.. _tango_installation:

Tango device server
```````````````````

As Tango server is provied as python script, you just have to copy the application/tango directory where you want.

- **camera directory:** contained all camera Tango device specifics so remove all none need script
- **plugins directory:** contained all plugins device server like:

  - Roi counters
  - Mask...
- **scripts directory:** contained a script use at ESRF to start Lima device server (can also be removed)