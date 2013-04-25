GetIt
-----

As Lima is not packaged,the only way for now is to retreived it from the git_ repository.

**Command to get all sources:**

.. code-block:: bash 

  seb@pcbliss01:~/$ git clone --recursive git://github.com/esrf-bliss/Lima.git

**Commands for a minimum chekout to get all source needed for a particular camera:**

.. code-block:: bash

  seb@pcbliss01:~/$ git clone git://github.com/esrf-bliss/Lima.git
  seb@pcbliss01:~/$ cd Lima
  seb@pcbliss01:~/Lima$ git submodule init third-party/Processlib third-party/Sps
  seb@pcbliss01:~/Lima$ git submodule init camera/CAMERA_YOU_WANT_TO_COMPILE
  seb@pcbliss01:~/Lima$ git submodule update

  

Particular version
``````````````````
On all version of LImA is tagged. So you can retreive a particular version.

This command provide the tag list:

.. code-block:: bash

  seb@pcbliss01:~/Lima$ git tag -l
  core-1.0.10
  core-1.0.11
  core-1.0.12
  core-1.0.13
  core-1.0.9
  espia-1.0.4
  espia-1.0.5
  ....
  taco-camera-frelon-1.0.5
  tango-camera-frelon-1.0.0
  tango-camera-maxipix-1.0.2
  tango-camera-maxipix-1.0.4
  tango-camera-pilatus-1.0.2
  tango-common-1.0.2
  tango-common-1.0.3
  tango-common-1.0.4
  tango-common-1.0.5
  tango-common-1.0.6

Let's say that you want the version 1.0.11 of Lima core with this command, you'll getit:

.. code-block:: bash

  seb@pcbliss01:~/Lima$ git checkout core-1.0.11
  seb@pcbliss01:~/Lima$ git submodule init
  seb@pcbliss01:~/Lima$ git submodule update







.. _git: http://git-scm.com/
