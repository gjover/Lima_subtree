.. Lima documentation master file, created by
   sphinx-quickstart on Fri Feb 18 10:19:02 2011.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

====
LImA
====
LImA ( **L** ibrary for **Im** age **A** cquisition) is a project for the unified control of 2D detectors. The aim is to clearly separate hardware specific code from common software configuration and features, like setting standard acquisition parameters (exposure time, external trigger), file saving and image processing.

Overview
--------

.. toctree::
  :maxdepth: 3

  introduction

Getting started
===============

.. toctree::
  :maxdepth: 3

  getit
  compilation
  installation

Supported Cameras
=================

.. toctree::
  :maxdepth: 2

  cameras

Future cameras
========================

.. toctree::
   :maxdepth: 1

   future_cameras

Applications
=======================

.. toctree::
  :maxdepth: 3

  applications/tango/doc/index

Camera plugin developer guide
===================================

.. toctree::
  :maxdepth: 3

  plugin_getting_started/index
   
LImA specification
==================

The first LIMA project specification has been written after the previous brain storming sessions. It is composed by the following main topic

.. toctree::
  :maxdepth: 1

  overview
  control_specification
  hardware_specification

`Class documentation`_
======================

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

.. _Class documentation: doxygen/html/index.html
