/*
 *  Copyright (c) 2011-2012, Los Alamos National Security, LLC.
 *  All rights Reserved.
 *
 *  Copyright 2011-2012. Los Alamos National Security, LLC. This software was produced 
 *  under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
 *  Laboratory (LANL), which is operated by Los Alamos National Security, LLC 
 *  for the U.S. Department of Energy. The U.S. Government has rights to use, 
 *  reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS 
 *  ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR 
 *  ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified
 *  to produce derivative works, such modified software should be clearly marked,
 *  so as not to confuse it with the version available from LANL.
 *
 *  Additionally, redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Los Alamos National Security, LLC, Los Alamos 
 *       National Laboratory, LANL, the U.S. Government, nor the names of its 
 *       contributors may be used to endorse or promote products derived from 
 *       this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE LOS ALAMOS NATIONAL SECURITY, LLC AND 
 *  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
 *  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LOS ALAMOS NATIONAL
 *  SECURITY, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *  
 *  CLAMR -- LA-CC-11-094
 *  This research code is being developed as part of the 
 *  2011 X Division Summer Workshop for the express purpose
 *  of a collaborative code for development of ideas in
 *  the implementation of AMR codes for Exascale platforms
 *  
 *  AMR implementation of the Wave code previously developed
 *  as a demonstration code for regular grids on Exascale platforms
 *  as part of the Supercomputing Challenge and Los Alamos 
 *  National Laboratory
 *  
 *  Authors: Bob Robey       XCP-2   brobey@lanl.gov
 *           Neal Davis              davis68@lanl.gov, davis68@illinois.edu
 *           David Nicholaeff        dnic@lanl.gov, mtrxknight@aol.com
 *           Dennis Trujillo         dptrujillo@lanl.gov, dptru10@gmail.com
 * 
 *  
 *  This file and the associated header is based on a file from the capablanca
 *  project available under the MIT open-source license.  As author of that code,
 *  I, Neal Davis, permit repurposing and redistribution for CLAMR under the New
 *  BSD License used above.
 *      http://code.google.com/p/capablanca/
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "state.h"
#include "partition.h"
#include "mesh.h"
#include "hash.h"
#include "crux.h"
//#include "graphics/display.h"
#include "graphics.h"

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <limits.h>

#define OUTPUT_INTERVAL 100
#define COARSE_GRID_RES 128
#define MAX_TIME_STEP 3000

using namespace std;

//  Global variables.
char progName[12];      //  Program name.
char progVers[8];       //  Program version.

//  External global variables.
extern bool verbose,
            localStencil,
            outline,
            face_based,
            dynamic_load_balance_on,
            h5_spoutput,
            neighbor_remap,
            restart;
extern int  outputInterval,
            crux_type,
            enhanced_precision_sum,
            tmax,
            levmx,
            nx,
            ny,
            niter,
            measure_type,
            lttrace_on,
            do_quo_setup,
            calc_neighbor_type,
	    choose_hash_method,
            initial_order,
            graphic_outputInterval,
            graphics_type,
            checkpoint_outputInterval,
            num_of_rollback_states,
            cycle_reorder;
extern float
            mem_opt_factor;
extern double
            upper_mass_diff_percentage;

extern char* restart_file;

void outputHelp()
{   cout << "CLAMR is an experimental adaptive mesh refinement code for the GPU." << endl
         #ifdef PACKAGE_VERSION 
         << "Version is " << PACKAGE_VERSION << endl << endl 
         #endif
         << "Usage:  " << progName << " [options]..." << endl
         << "  -b <B>            Number of rollback images, disk or in memory (default 2);" << endl
         << "  -c <C>            Checkpoint to disk at interval specified;" << endl
         << "  -C <C>            Checkpoint to memory at interval specified;" << endl
         << "  -d                turn on LTTRACE;" << endl
         << "  -D                turn on dynamic load balancing using LTTRACE;" << endl
         << "  -e <E>            force hash_method, ie linear, quadratic..." <<endl          
         << "      \"perfect\"" << endl
         << "      \"linear\"" << endl
         << "      \"quadratic\"" << endl
         << "      \"prime_jump\"" << endl
         << "  -f                face-based finite difference;" << endl
         << "  -g <g>            specify I step between saving graphics information for post processing;" << endl
         << "  -G <G>            specify graphics file type for post processing;" << endl
         << "      \"bmp\"" << endl
         << "      \"gif\"" << endl
         << "      \"jpeg\"" << endl
         << "      \"mpeg\"" << endl
         << "      \"pdf\"" << endl
         << "      \"png\"" << endl
         << "      \"svg\"" << endl
         << "      \"data\"" << endl
         << "  -h                display this help message;" << endl
         << "  -i <I>            specify I steps between output files;" << endl
         << "  -l <l>            max number of levels;" << endl
         << "  -M <M>            memory optimization factor 1.0 <= M <=100.0 (default 1.0 -- represents 1/20 perfect hash);" << endl
         << "  -m <m>            specify partition measure type;" << endl
         << "      \"with_duplicates\"" << endl
         << "      \"without_duplicates\"" << endl
         << "  -N <n>            specify calc neighbor type;" << endl
         << "      \"hash_table\"" << endl
         << "      \"kdtree\"" << endl
         << "  -n <N>            specify coarse grid resolution of NxN;" << endl
         << "  -o                turn off outlines;" << endl
         << "  -P <P>            specify initial order P;" << endl
         << "      \"original_order\"" << endl
         << "      \"hilbert_sort\"" << endl
         << "      \"hilbert_partition\"" << endl
         << "      \"z_order\"" << endl
         << "  -p <p>            specify ordering P every cycle;" << endl
         << "      \"original_order\"" << endl
         << "      \"hilbert_sort\"" << endl
         << "      \"hilbert_partition\"" << endl
         << "      \"local_hilbert\"" << endl
         << "      \"local_fixed\"" << endl
         << "      \"z_order\"" << endl
         << "  -q                turn on quo;" << endl
         << "  -r                regular sum instead of enhanced precision sum (Kahan sum);" << endl
         << "  -R                restart simulation from the backup file specified;" << endl
         << "  -s <s>            specify space-filling curve method S;" << endl
         << "  -S                write out double precision data as single precision;" << endl
         << "  -T                execute with TVD;" << endl
         << "  -t <t>            specify T time steps to run;" << endl
         << "  -u                allowed percentage of difference between total mass between iterations." << endl
         << "                    the default value for this parameter is 2.6e-13;" << endl
         << "  -V                use verbose output;" << endl
         << "  -v                display version information." << endl
         << "  -z                force recalculation of neighbors." << endl; }

void outputVersion()
{   cout << progName << " " << progVers << endl; }

/*  parseInput(const int argc, char** argv)
 *  
 *  Interpret the command line input.
 */
void parseInput(const int argc, char** argv)
{   strcpy(progName, "clamr");
    #ifdef PACKAGE_VERSION
    strcpy(progVers, PACKAGE_VERSION);
   #endif
    
    //  Set variables to defaults, which may be overridden by CLI.
    verbose                 = false;
    localStencil            = true;
    outline                 = true;
#ifdef HAVE_LTTRACE
    lttrace_on              = 0;
#endif
#ifdef HAVE_QUO
    do_quo_setup            = 0;
#endif
    dynamic_load_balance_on = false;
    crux_type               = CRUX_NONE;
    face_based              = false;
    restart                 = false;
    restart_file            = NULL;
    outputInterval          = OUTPUT_INTERVAL;
    nx                      = COARSE_GRID_RES;
    ny                      = COARSE_GRID_RES;
    niter                   = MAX_TIME_STEP;
    neighbor_remap          = true;
    //measure_type            = CSTARVALUE;
    measure_type            = NO_PARTITION_MEASURE;
    calc_neighbor_type      = HASH_TABLE;
    choose_hash_method      = METHOD_UNSET;
    initial_order           = HILBERT_SORT;
    cycle_reorder           = ORIGINAL_ORDER;
    graphic_outputInterval  = INT_MAX;
    graphics_type           = GRAPHICS_NONE;
    checkpoint_outputInterval = INT_MAX;
    num_of_rollback_states  = 2;
    levmx                   = 1;
    mem_opt_factor          = 1.0;
    upper_mass_diff_percentage = -1.0;
    enhanced_precision_sum  = SUM_KAHAN;
    
    char   *val;
    if (argc > 1)
    {   int i = 1;
        val = strtok(argv[i++], " ,.-");
        while (val != NULL){
            switch (val[0]){
               case 'b':     //  Number of rollback images, disk or in memory (default 2)
                    sprintf(val,"0");
                    if (i < argc) val = strtok(argv[i++], " ,");
                    if(atoi(val) < 1){
                        printf("backup number must be at least 1, setting to default value 2\n");
                    }
                    else{
                        num_of_rollback_states = atoi(val);
                    }
                    break;
                case 'c':   //  Checkpoint to disk at interval specified
                    val = strtok(argv[i++], " ,.-");
                    checkpoint_outputInterval = atoi(val);
                    crux_type = CRUX_DISK;
                    break;

                case 'C':   //  Checkpoint to memory at interval specified
                    val = strtok(argv[i++], " ,.-");
                    checkpoint_outputInterval = atoi(val);
                    crux_type = CRUX_IN_MEMORY;
                    break;

                case 'd':   //  Turn on lttrace.
                            //  This is provided as a separate option to measure
                            //  the overhead of having lttrace on.
#ifdef HAVE_LTTRACE
                    lttrace_on = 1;
#endif
                    break;

                case 'D':   //  Turn on dynamic load balancing.
                            //  This forces on lttrace.
#ifdef HAVE_LTTRACE
                    lttrace_on = true;
                    dynamic_load_balance_on = true;
#endif
                    break;

                case 'e':   //  hash method specified.
                    val = strtok(argv[i++], " ,");
                    if (! strcmp(val,"perfect") ) {
                       choose_hash_method = PERFECT_HASH;
                    } else if (! strcmp(val,"linear") ) {
                       choose_hash_method = LINEAR;
                    } else if (! strcmp(val,"quadratic") ) {
                       choose_hash_method = QUADRATIC;
                    } else if (! strcmp(val,"prime_jump") ) {
                       choose_hash_method = PRIME_JUMP;
                    }
                    break;

                case 'f':   // Use face-based finite difference
                    face_based = true;
                    break;
                
                case 'g':   //  Save graphics data to files during simulation.
                    val = strtok(argv[i++], " ,.-");
                    graphic_outputInterval = atoi(val);
                    if (graphics_type == GRAPHICS_NONE) graphics_type = GRAPHICS_DATA;
                    break;

                case 'G':   //  Graphics data file type.
                    val = strtok(argv[i++], " ,.-");
                    if (! strcmp(val,"none") ) {
                       graphics_type = GRAPHICS_NONE;
                       graphic_outputInterval  = INT_MAX;
                    } else if (! strcmp(val,"data") ) {
                       graphics_type = GRAPHICS_DATA;
#ifdef HAVE_MAGICKWAND
                    } else if (! strcmp(val,"bmp") ) {
                       graphics_type = GRAPHICS_BMP;
                    } else if (! strcmp(val,"gif") ) {
                       graphics_type = GRAPHICS_GIF;
                    } else if (! strcmp(val,"jpeg") ) {
                       graphics_type = GRAPHICS_JPEG;
                    } else if (! strcmp(val,"mpeg") ) {
                       graphics_type = GRAPHICS_MPEG;
                    } else if (! strcmp(val,"pdf") ) {
                       graphics_type = GRAPHICS_PDF;
                    } else if (! strcmp(val,"png") ) {
                       graphics_type = GRAPHICS_PNG;
                    } else if (! strcmp(val,"svg") ) {
                       graphics_type = GRAPHICS_SVG;
#endif
                    } else {
                       printf("Unrecognized option for graphics file type %s\n",val);
                       exit(-1);
                    }
                    break;

                case 'h':   //  Output help.
                    outputHelp();
                    cout.flush();
                    exit(EXIT_SUCCESS);
                    break;
                    
                case 'i':   //  Output interval specified.
                    val = strtok(argv[i++], " ,.-");
                    outputInterval = atoi(val);
                    break;
                    
                case 'l':   //  max level specified.
                    val = strtok(argv[i++], " ,");
                    levmx = atoi(val);
                    break;
                    
                case 'M':   //  memory optimization factor
                    val = strtok(argv[i++], " ,");
                    mem_opt_factor = atof(val);
                    break;
                    
                case 'm':   //  partition measure specified.
                    val = strtok(argv[i++], " ,");
                    if (! strcmp(val,"no_partition_measure") ) {
                       measure_type = NO_PARTITION_MEASURE;
                    } else if (! strcmp(val,"with_duplicates") ) {
                       measure_type = WITH_DUPLICATES;
                    } else if (! strcmp(val,"without_duplicates") ) {
                       measure_type = WITHOUT_DUPLICATES;
                    } else if (! strcmp(val,"cvalue") ) {
                       measure_type = CVALUE;
                    } else if (! strcmp(val,"cstarvalue") ) {
                       measure_type = CSTARVALUE;
                    }
                    break;
                    
                case 'N':   //  calc neighbor type specified.
                    val = strtok(argv[i++], " ,");
                    if (! strcmp(val,"hash_table") ) {
                       calc_neighbor_type = HASH_TABLE;
                    } else if (! strcmp(val,"kdtree") ) {
                       calc_neighbor_type = KDTREE;
                    }
                    break;
                    
                case 'n':   //  Domain grid resolution specified.
                    val = strtok(argv[i++], " ,");
                    nx = atoi(val);
                    ny = nx;
                    break;
                    
                case 'o':   //  Turn off outlines on mesh drawing.
                    outline = false;
                    break;
                    
                case 'P':   //  Initial order specified.
                    val = strtok(argv[i++], " ,");
                    if (! strcmp(val,"original_order") ) {
                       initial_order = ORIGINAL_ORDER;
                    } else if (! strcmp(val,"hilbert_sort") ) {
                       initial_order = HILBERT_SORT;
                    } else if (! strcmp(val,"hilbert_partition") ) {
                       initial_order = HILBERT_PARTITION;
                    } else if (! strcmp(val,"z_order") ) {
                       initial_order = ZORDER;
                    }
                    break;
                    
                case 'p':   //  Initial order specified.
                    val = strtok(argv[i++], " ,");
                    if (! strcmp(val,"original_order") ) {
                       cycle_reorder = ORIGINAL_ORDER;
                       localStencil = false;
                    } else if (! strcmp(val,"hilbert_sort") ) {
                       cycle_reorder = HILBERT_SORT;
                       localStencil = false;
                    } else if (! strcmp(val,"hilbert_partition") ) {
                       cycle_reorder = HILBERT_PARTITION;
                       localStencil = false;
                    } else if (! strcmp(val,"local_hilbert") ) {
                       cycle_reorder = ORIGINAL_ORDER;
                       localStencil = true;
                    } else if (! strcmp(val,"local_fixed") ) {
                       cycle_reorder = ORIGINAL_ORDER;
                       localStencil = false;
                    } else if (! strcmp(val,"z_order") ) {
                       cycle_reorder = ZORDER;
                       localStencil = false;
                    }
                    break;
   
                case 'q':   //  turn on quo package.
#ifdef HAVE_QUO
                    do_quo_setup = 1;
#endif
                    break;
                    
                case 'r':   //  Regular sum instead of enhanced precision sum.
                    val = strtok(argv[i++], " ,");
                    if (! strcmp(val,"regular_sum") ) {
                       enhanced_precision_sum = SUM_REGULAR;
                    } else if (! strcmp(val,"kahan_sum") ) {
                       enhanced_precision_sum = SUM_KAHAN;
                    } else {
                       printf("Error with sum argument %s\n",val);
                       exit(0);
                    }
                    break;

                case 'R':  //  Restart application from last checkpoint
                    restart = true;
                    restart_file = strtok(argv[i++], " ,");

#ifndef HDF5_FF
                    struct stat stat_descriptor;
                    if (stat(restart_file,&stat_descriptor) == -1){
                       printf("Error -- restart file %s does not exist\n",restart_file);
                       exit(0);
                    }
#endif
                    break;

                case 's':   //  Space-filling curve method specified (default HILBERT_SORT).
                //  Add different problem setups such as sloped wave in x, y and diagonal directions to help check algorithm
                    //  HILBERT_SORT
                    break;
                    
                case 'T':   //  TVD inclusion specified.
                    break;
                    
                case 't':   //  Number of time steps specified.
                    val = strtok(argv[i++], " ,.-");
                    niter = atoi(val);
                    break;

                case 'u':   //  Allowed percentage of difference in mass per iteration
                    val = strtok(argv[i++], " ,");
                    upper_mass_diff_percentage = atof(val);
                    break;
                    
                case 'V':   //  Verbose output desired.
                    verbose = true;
                    break;
                    
                case 'v':   //  Version.
                    outputVersion();
                    cout.flush();
                    exit(EXIT_SUCCESS);
                    break;

                case 'z':  // Neighbor remap -- default is true, -z sets to false
                    neighbor_remap = false;
                    break;
                    
                default:    //  Unknown parameter encountered.
                    cout << "⚠ Unknown input parameter " << val << endl;
                    outputHelp();
                    cout.flush();
                    exit(EXIT_FAILURE);
                    break; }
            
            val = strtok(argv[i++], " ,.-");
        }
     }

/*
    if(upper_mass_diff_percentage < 0){
             upper_mass_diff_percentage = 1.0e-12;
    }
*/
}
