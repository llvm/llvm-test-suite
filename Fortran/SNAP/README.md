SNAP: SN (Discrete Ordinates) Application Proxy
===============================================

llvm-test-suite
-----------
This repository was modified to serve as a Fortran regression test in the llvm-test-suite

Documents that describe the code base can be found in the original repository's
[docs](https://github.com/lanl/SNAP/tree/main/docs) repository.


Description
-----------

SNAP serves as a proxy application to model the performance of a modern discrete ordinates neutral particle transport application. SNAP may be considered an update to [Sweep3D](http://www.ccs3.lanl.gov/PAL/software.shtml), intended for hybrid computing architectures. It is modeled off the Los Alamos National Laboratory code PARTISN. PARTISN solves the linear Boltzmann transport equation (TE), a governing equation for determining the number of neutral particles (e.g., neutrons and gamma rays) in a multi-dimensional phase space. SNAP itself is not a particle transport application; SNAP incorporates no actual physics in its available data, nor does it use numerical operators specifically designed for particle transport. Rather, SNAP mimics the computational workload, memory requirements, and communication patterns of PARTISN. The equation it solves has been composed to use the same number of operations, use the same data layout, and load elements of the arrays in approximately the same order. Although the equation SNAP solves looks similar to the TE, it has no real world relevance.

The solution to the time-dependent TE is a "flux" function of seven independent variables: three spatial (3-D spatial mesh), two angular (set of discrete ordinates, directions in which particles travel), one energy (particle speeds binned into "groups"), and one temporal. PARTISN, and therefore SNAP, uses domain decomposition over these dimensions to coherently distribute the data and the tasks associated with solving the equation. The parallelization strategy is expected to be the most efficient compromise between computing resources and the iterative strategy necessary to converge the flux.

The iterative strategy is comprised of a set of two nested loops. These nested loops are performed for each step of a time-dependent calculation, wherein any particular time step requires information from the preceding one. No parallelization is performed over the temporal domain. However, for time-dependent calculations two copies of the unknown flux must be stored, each copy an array of the six remaining dimensions. The outer iterative loop involves solving for the flux over the energy domain with updated information about coupling among the energy groups. Typical calculations require tens to hundreds of groups, making the energy domain suitable for threading with the node's (or nodes') provided accelerator. The inner loop involves sweeping across the entire spatial mesh along each discrete direction of the angular domain. The spatial mesh may be immensely large. Therefore, SNAP spatially decomposes the problem across nodes and communicates needed information according to the KBA method. KBA is a transport-specific application of general parallel wavefront methods. Nested threads, spawned by the energy group threads, are available to use in one of two ways. Per one approach, nested threads may be used to further parallelize the work to sweep different energy groups assigned to a main-level thread. This option is still experimental and has only been implemented to work in the case of using a single MPI process. Alternatively, nested threads are used to perform "mini KBA" sweeps by concurrently operating on cells lying on the same diagonal of spatial sub-domains already decomposed across the distributed memory architecture (i.e., different MPI ranks). Lastly, although KBA efficiency is improved by pipelining operations according to the angle, current chipsets operate best with vectorized operations. During a mesh sweep, SNAP operations are vectorized over angles to take advantage of the modern hardware.

SNAP should be tested with problem sizes that accurately reflect the types of calculations PARTISN frequently handles. The spatial domain shall be decomposed to 2,000--4,000 cells per node (MPI rank). Each node will own all the energy groups and angles for that group of cells; typical calculations feature 10--100 energy groups and as few as 100 to as many as 2,000 angles. Moreover, sufficient memory must be provided to store two full copies of the solution vector for time-dependent calculations. The preceding parameters assume current trends in available per core memory. Significant advances or detriments affecting this assumption shall require reconsideration of appropriate parameters per compute node.

Compilation
-----------

SNAP has been written to the Fortran 90/95 standard primarily. The retrieval of command line arguments, which contain file names, is handled with a standard Fortran 2003 intrinsic subroutine. It has been successfully built with, but not necessarily limited to, gfortran and ifort. Moreover, the code has been built with the profiling tool [Byfl](https://github.com/losalamos/byfl). The accompanying Makefile provides sample build options for gfortran and ifort. The build system depends on the availability of MPI. Both example builds assume the usage of mpif90 from an MPI installation. Builds may be selected by switching the COMPILER option in the Makefile or choosing one with the "make COMPILER=[]" command. The builds also assume the availability of OpenMP. Compiling SNAP without MPI or OpenMP will require modification to the source code to remove related subroutine calls and directives.

MPI implementations typically suggest using a "wrapper" compiler to compile the code. SNAP has been built and tested with OpenMPI and MPICH. OpenMPI allows one to set the underlying Fortran compiler with the environment variable OMPI_FC, where the variable is set to the (path and) compiler of choice, e.g., ifort, gfortran, etc.

The makefile currently is set up for several build options using different MPI wrappers and Fortran compilers. One example uses:

    FORTRAN = mpif90
    COMPILER = ifort

and testing has been performed with

    OMPI_FC = [path]/ifort

Fortran compilation flags can be set according to the underlying compiler. The current flags are set for the ifort compiler and using OpenMP for parallel threading.

    TARGET = isnap
    FFLAGS = -03 -[q]openmp -align array32byte -fp-model fast -fp-speculation fast -xHost
    FFLAG2 =

where `FFLAG2` is reserved for additional flags that may need applied differently, depending on the compiler. To make SNAP with these default settings, simply type

    make

on the command line within the SNAP directory.

A debugging version of SNAP can be built by typing

    make OPT=no

on the command line. The unoptimized, debugging version of SNAP features bounds checking, back-tracing an error, and the necessary debug compiler flags. With ifort, these flags appear as:

    FFLAGS = -O0 -[q]openmp -g -check bounds -traceback -warn unused
    FFLAG2 =

The values for these compilation variables have been modified for various Fortran compilers and the Makefile provides details of what has been used previously. These lines are commented out for clarity at this time and to ensure that changes to the build system are made carefully before attempting to rebuild with a different compiler.

The SNAP directory can be cleaned up of its module and object files if the user desires with:

    make clean

This removes all the `*.mod` and `*.o` files, as well as `*.bc` files from Byfl builds. Moreover, it will enforce complete recompilation of all files upon the next instance of `make` or `make OPT=no`. Currently, there is no separate directory for the compilation files of separate optimized and unoptimized builds. The user must do a `make clean` before building the code if the previous build used the opposite command.

Pre-processing has been added for the inclusion/exclusion of MPI and OpenMP. To build without MPI, OpenMP, or both, use the command lines, respectively:

    make MPI=no
    make OPENMP=no
    MAKE MPI=no OPENMP=no

Default make settings will build with MPI and OpenMP included. These options are further available with unpotimized settings, OPT=no.

Lastly, a line count report is generated with:

    make count

The line count report excludes blank lines and comments. It counts the number of code lines in all `*.f90` files and sums the results. The information is printed to the the `Lines` file.

Usage
-----

When SNAP is built with MPI, to execute SNAP, use the following command:

    mpirun -n [#] [path]/snap [infile] [outfile]

This command will automatically run with the number of threads specified by the input file, which is used to set the number of OpenMP threads, overwriting any environment variable to set the number of threads. Testing has shown that to ensure proper concurrency of work, the above command can be modified to

    mpirun -cpus-per-proc [#threads] -np [#procs] [path]/snap [infile] [outfile]

The command line is read for the input/output file names. If one of the names is missing, the code will not execute. Moreover, the output file overwrites any pre-existing files of the same name.

The specific command to invoke a run with MPI and the corresponding options may be dependent on the specific machine used to execute. Most notably, the "aprun" command is used on Cray systems.

Sample Input
------------

The following is a sample input of a SNAP job. Several other examples are provided as part of the small set of regression testing. For more information about the valid range of values and descriptions of the input variables, please see the user manual.

    ! Input from namelist
    &invar
      npey=2
      npez=2
      ichunk=2
      nthreads=2
      nnested=1
      ndimen=3
      nx=6
      lx=0.6
      ny=6
      ly=0.6
      nz=6
      lz=0.6
      nmom=1
      nang=10
      ng=4
      epsi=1.0E-4
      iitm=5
      oitm=30
      timedep=0
      tf=1.0
      nsteps=1
      mat_opt=0
      src_opt=0
      scatp=0
      it_det=0
      fluxp=0
      fixup=1
      soloutp=1
      kplane=0
      popout=0
      swp_typ=0
    /

Sample Output
-------------

The following is the corresponding output to the above case. A brief outline of the output file contents is version and run time information, echo of input (or default) values of the namelist variables, echo of relevant parameters after setup, iteration monitor, mid-plane flux output, and the timing summary. Warning and error messages may be printed throughout the output file to alert the user to some problem with the execution. Unlike errors, warnings do not cause program termination.

     SNAP: SN (Discrete Ordinates) Application Proxy
     Version Number..  1.05
     Version Date..  02-19-2015
     Ran on  2-20-2015 at time 10:53:26
    
    ********************************************************************************
    
              keyword Input Echo - Values from input or
    
    default
    ********************************************************************************
    
      NML=invar
         npey=     2
         npez=     2
         ichunk=     2
         nthreads=     2
         nnested=   1
         ndimen=  3
         nx=     6
         ny=     6
         nz=     6
         lx=  6.0000E-01
         ly=  6.0000E-01
         lz=  6.0000E-01
         nmom=   1
         nang=   10
         ng=    4
         mat_opt=  0
         src_opt=  0
         scatp=  0
         epsi=  1.0000E-04
         iitm=   5
         oitm=   30
         timedep=  0
         tf=  1.0000E+00
         nsteps=     1
         swp_typ=  0
         it_det=  0
         soloutp=  1
         kplane=    0
         popout=  0
         fluxp=  0
         fixup=  1
    
    ********************************************************************************
    
              keyword Calculation Run-time Parameters Echo
    ********************************************************************************
    
      Geometry
        ndimen = 3
        nx =     6
        ny =     6
        nz =     6
        lx =  6.0000E-01
        ly =  6.0000E-01
        lz =  6.0000E-01
        dx =  1.0000E-01
        dy =  1.0000E-01
        dz =  1.0000E-01
    
      Sn
        nmom = 1
        nang =   10
        noct = 8
    
        w =  1.2500E-02   ... uniform weights
    
              mu              eta               xi
         5.00000000E-02   9.50000000E-01   3.08220700E-01
         1.50000000E-01   8.50000000E-01   5.04975247E-01
         2.50000000E-01   7.50000000E-01   6.12372436E-01
         3.50000000E-01   6.50000000E-01   6.74536878E-01
         4.50000000E-01   5.50000000E-01   7.03562364E-01
         5.50000000E-01   4.50000000E-01   7.03562364E-01
         6.50000000E-01   3.50000000E-01   6.74536878E-01
         7.50000000E-01   2.50000000E-01   6.12372436E-01
         8.50000000E-01   1.50000000E-01   5.04975247E-01
         9.50000000E-01   5.00000000E-02   3.08220700E-01
    
      Material Map
        mat_opt = 0   -->   nmat = 1
        Base material (default for every cell) = 1
    
      Source Map
        src_opt = 0
        Source strength per cell (where applied) = 1.0
        Source map:
            Starting cell: (     1,     1,     1 )
            Ending cell:   (     6,     6,     6 )
    
      Pseudo Cross Sections Data
        ng =   4
    
        Material 1
        Group         Total         Absorption      Scattering
           1       1.000000E+00    5.000000E-01    5.000000E-01
           2       1.010000E+00    5.050000E-01    5.050000E-01
           3       1.020000E+00    5.100000E-01    5.100000E-01
           4       1.030000E+00    5.150000E-01    5.150000E-01
    
      Solution Control Parameters
        epsi =  1.0000E-04
        iitm =   5
        oitm =   30
        timedep = 0
        swp_typ = 0
        it_det = 0
        soloutp = 1
        kplane =    0
        popout = 0
        fluxp = 0
        fixup = 1
    
    
      Parallelization Parameters
        npey =     2
        npez =     2
        nthreads =    2
    
          Thread Support Level
               0 - MPI_THREAD_SINGLE
               1 - MPI_THREAD_FUNNELED
               2 - MPI_THREAD_SERIALIZED
               3 - MPI_THREAD_MULTIPLE
        thread_level =  0
    
        .FALSE. nested threading
          nnested =    1
    
        Parallel Computational Efficiency = 0.8889
    
    ********************************************************************************
    
              keyword Iteration Monitor
    ********************************************************************************
      Outer
        1    Dfmxo= 3.5528E-01    No. Inners=   17
        2    Dfmxo= 1.7376E-01    No. Inners=   14
        3    Dfmxo= 8.6338E-03    No. Inners=    9
    
      No. Outers=   3    No. Inners=   40
    
    ********************************************************************************
    
              keyword Scalar Flux Solution
    ********************************************************************************
    
     ***********************************
      Group=   1   Z Mid-Plane=    4
     ***********************************
    
         y    x    1      x    2      x    3      x    4      x    5      x    6
         6  1.8403E-01  2.3461E-01  2.4743E-01  2.4743E-01  2.3461E-01  1.8403E-01
         5  2.3461E-01  2.9818E-01  3.1572E-01  3.1572E-01  2.9818E-01  2.3461E-01
         4  2.4743E-01  3.1572E-01  3.3604E-01  3.3604E-01  3.1572E-01  2.4743E-01
         3  2.4743E-01  3.1572E-01  3.3604E-01  3.3604E-01  3.1572E-01  2.4743E-01
         2  2.3461E-01  2.9818E-01  3.1572E-01  3.1572E-01  2.9818E-01  2.3461E-01
         1  1.8403E-01  2.3461E-01  2.4743E-01  2.4743E-01  2.3461E-01  1.8403E-01
    
    ********************************************************************************
    
    
     ***********************************
      Group=   2   Z Mid-Plane=    4
     ***********************************
    
     y    x    1      x    2      x    3      x    4      x    5      x    6
     6  1.8434E-01  2.3510E-01  2.4797E-01  2.4797E-01  2.3510E-01  1.8434E-01
     5  2.3510E-01  2.9891E-01  3.1654E-01  3.1654E-01  2.9891E-01  2.3510E-01
     4  2.4797E-01  3.1654E-01  3.3697E-01  3.3697E-01  3.1654E-01  2.4797E-01
     3  2.4797E-01  3.1654E-01  3.3697E-01  3.3697E-01  3.1654E-01  2.4797E-01
     2  2.3510E-01  2.9891E-01  3.1654E-01  3.1654E-01  2.9891E-01  2.3510E-01
     1  1.8434E-01  2.3510E-01  2.4797E-01  2.4797E-01  2.3510E-01  1.8434E-01
    
    ********************************************************************************
    
    
     ***********************************
      Group=   3   Z Mid-Plane=    4
     ***********************************
    
         y    x    1      x    2      x    3      x    4      x    5      x    6
         6  1.8990E-01  2.4282E-01  2.5648E-01  2.5648E-01  2.4282E-01  1.8990E-01
         5  2.4282E-01  3.0956E-01  3.2828E-01  3.2828E-01  3.0956E-01  2.4282E-01
         4  2.5648E-01  3.2828E-01  3.4996E-01  3.4996E-01  3.2828E-01  2.5648E-01
         3  2.5648E-01  3.2828E-01  3.4996E-01  3.4996E-01  3.2828E-01  2.5648E-01
         2  2.4282E-01  3.0956E-01  3.2828E-01  3.2828E-01  3.0956E-01  2.4282E-01
         1  1.8990E-01  2.4282E-01  2.5648E-01  2.5648E-01  2.4282E-01  1.8990E-01
    
    ********************************************************************************
    
    
     ***********************************
      Group=   4   Z Mid-Plane=    4
     ***********************************
    
         y    x    1      x    2      x    3      x    4      x    5      x    6
         6  2.2018E-01  2.8475E-01  3.0277E-01  3.0277E-01  2.8475E-01  2.2018E-01
         5  2.8475E-01  3.6725E-01  3.9202E-01  3.9202E-01  3.6725E-01  2.8475E-01
         4  3.0277E-01  3.9202E-01  4.2062E-01  4.2062E-01  3.9202E-01  3.0277E-01
         3  3.0277E-01  3.9202E-01  4.2062E-01  4.2062E-01  3.9202E-01  3.0277E-01
         2  2.8475E-01  3.6725E-01  3.9202E-01  3.9202E-01  3.6725E-01  2.8475E-01
         1  2.2018E-01  2.8475E-01  3.0277E-01  3.0277E-01  2.8475E-01  2.2018E-01
    
    ********************************************************************************
    
              keyword Timing Summary
    ********************************************************************************
    
      Code Section                          Time (seconds)
     **************                        ****************
        Parallel Setup                       9.7394E-04
        Input                                4.7112E-04
        Setup                                7.1216E-04
        Solve                                7.6568E-03
           Parameter Setup                   2.8968E-04
           Outer Source                      3.0041E-05
           Inner Iterations                  7.0901E-03
              Inner Source                   5.4121E-05
              Transport Sweeps               6.6264E-03
              Inner Misc Ops                 4.0960E-04
           Solution Misc Ops                 2.4700E-04
        Output                               6.4492E-04
      Total Execution time                   3.4652E-02
    
      Grind Time (nanoseconds)         1.1078E+01
    
    ********************************************************************************
    

Additional outputs in the form of `slgg` and `flux` files are available when requested according to the `scatp` and `fluxp` input variables, respectively.

License
-------

Los Alamos National Security, LLC owns the copyright to "SNAP: SN (Discrete Ordinates) Application Proxy, Version 1.x (C13087)". The license is BSD with standard clauses regarding indicating modifications before future redistribution:

Copyright (c) 2013, Los Alamos National Security, LLC
All rights reserved.

Copyright 2013. Los Alamos National Security, LLC. This software was produced under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National Laboratory (LANL), which is operated by Los Alamos National Security, LLC for the U.S. Department of Energy. The U.S. Government has rights to use, reproduce, and distribute this software. NEITHER THE GOVERNMENT NOR LOS ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE. If software is modified to produce derivative works, such modified software should be clearly marked, so as not to confuse it with the version available from LANL.

Additionally, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Los Alamos National Security, LLC, Los Alamos National Laboratory, LANL, the U.S. Government, nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY LOS ALAMOS NATIONAL SECURITY, LLC AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LOS ALAMOS NATIONAL SECURITY, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


Classification
--------------

SNAP is Unclassified and contains no Unclassified Controlled Nuclear Information. It has been assigned Los Alamos Computer Code number LA-CC-13-016.

Authors
-------

Joe Zerr, rzerr _ at _ lanl.gov

Randal Baker, rsb _ at _ lanl.gov

Additional Contacts
-------------------

Mike Lang, mlang _ at _ lanl.gov

Josip Loncaric, josip _ at _ lanl.gov

Last Modification to this Readme
--------------------------------
    
03/03/2016

