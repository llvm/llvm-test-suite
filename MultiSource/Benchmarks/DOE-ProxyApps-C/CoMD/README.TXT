**************************************************************************
LLVM Test-suite Note:
**************************************************************************
Beyond this paragraph is the original READMD.TXT from the src-mpi
directory.  A Makefile and CMakeLists.txt have been created for
integration into the LLVM test-suite.  The test-suite builds a serial
version of the code with hardware configuration and timing output
replaced.
**************************************************************************

This is CoMD version 1.1
========================

To contact the developers of CoMD send email to exmatex-comd@llnl.gov.

CoMD is a reference implementation of typical classical molecular
dynamics algorithms and workloads.  It is created and maintained by
The Exascale Co-Design Center for Materials in Extreme Environments
(ExMatEx).  http://codesign.lanl.gov/projects/exmatex.  The
code is intended to serve as a vehicle for co-design by allowing
others to extend and/or reimplement it as needed to test performance of 
new architectures, programming models, etc.

The current version of CoMD is available from:

https://github.com/exmatex/CoMD


Obtaining Documentation
=======================

CoMD documentation is produced by doxygen (www.doxygen.org).  
In order to generate the call graphs, you will also need graphviz 
installed. Alternatively, you can set 

HAVE_DOT = NO 

in the file 'Doxyfile' in the source directory. 

To build the documentation, navigate to the source directory 
(src-mpi) and run the command:

$ doxygen

To read the documenation, point a browser at 'html/index.html'.  
If you are unable to run doxygen on your local system you can download a
pre-built html directory from

XXXXXXXXXXXXXXXXXXXXXXX

Or, point your browser at

XXXXXXXXXXXXXXXXXXXXXX


Building CoMD
=============

CoMD is written with portability in mind and should compile using
practically any compiler that implements the C99 standard.  You will
need to create a Makefile by copying the sample provided with the
distribution (Makefile.vanilla).

$ cp Makefile.vanilla Makefile

and use the make command to build the code

$ make

The sample Makefile will compile the code on many platforms.  See
comments in Makefile.vanilla for information about specifying the name
of the C compiler and/or additional compiler switches that might be
necessary for your platform.


What's New
==========

For information about what has changed in this version of CoMD, please
consult the html documentation.

