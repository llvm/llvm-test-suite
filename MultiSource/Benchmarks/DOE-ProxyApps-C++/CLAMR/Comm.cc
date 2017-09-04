/* Copyright 2015.  Los Alamos National Security, LLC. This material was produced
 * under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
 * Laboratory (LANL), which is operated by Los Alamos National Security, LLC
 * for the U.S. Department of Energy. The U.S. Government has rights to use,
 * reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS
 * ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR
 * ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified
 * to produce derivative works, such modified software should be clearly marked,
 * so as not to confuse it with the version available from LANL.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 *
 * Under this license, it is required to include a reference to this work. We
 * request that each derivative work contain a reference to LANL Copyright
 * Disclosure C15076/LA-CC-15-054 so that this work's impact can be roughly
 * measured.
 *
 * This is LANL Copyright Disclosure C15076/LA-CC-15-054
 */

/*
 *  PowerParser is a general purpose input file parser for software applications.
 *
 *  Authors: Chuck Wingate   XCP-2   caw@lanl.gov
 *           Robert Robey    XCP-2   brobey@lanl.gov
 */

#include <cstdlib>
#include <assert.h>
#include "Comm.hh"

namespace PP {


// ===========================================================================
// Constructor
// ===========================================================================
Comm::Comm()
{
    npes = 1;
    mype = 0;
    iope = 0;

#ifdef HAVE_MPI
    int argc = 1;
    char **argv = NULL;

    int init_check;
    MPI_Initialized(&init_check);
    //printf("DEBUG -- mpi initialized %d\n",init_check);

    init_flag = 0;
    if (! init_check) {
       // Only way for init_flag to be true is here; must be false otherwise
       init_flag = 1;
       MPI_Init(&argc, &argv);
    }
    //printf("DEBUG -- comm constructor -- init_flag %d\n",init_flag);

    MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    MPI_Comm_size(MPI_COMM_WORLD, &npes );
    MPI_Comm_rank(MPI_COMM_WORLD, &mype );
#endif
}

// ===========================================================================
// Destructor
// ===========================================================================
Comm::~Comm()
{
   //printf("DEBUG -- comm destructor -- init_flag %d\n",init_flag);
#ifdef HAVE_MPI
   if (init_flag) {
      init_flag = 0;
      MPI_Finalize();
   }
#endif
}

// ===========================================================================
// Broadcast
// ===========================================================================
void Comm::broadcast(char *buffer, int count)
{
   // To suppress compiler warnings of unused parameters
   assert(buffer == buffer);
   assert(count == count);

   if (npes == 1) return;
#ifdef HAVE_MPI
   MPI_Bcast(buffer, count, MPI_CHAR, 0, MPI_COMM_WORLD);
#endif
}

// ===========================================================================
// Error handling
// ===========================================================================
void Comm::global_abort_parser()
{
#ifdef HAVE_MPI
   MPI_Abort(MPI_COMM_WORLD, 1);
#endif
   exit(1);
}
// ===========================================================================
} // End of PP namespace


