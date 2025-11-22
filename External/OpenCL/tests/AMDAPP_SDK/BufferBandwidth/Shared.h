/**********************************************************************
Copyright ©2013 Advanced Micro Devices, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

•	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
•	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************/

#ifndef _SHARED_H_
#define _SHARED_H_

#define SUCCESS 0
#define FAILURE 1
#define EXPECTED_FAILURE 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <CL/opencl.h>

#ifdef _WIN32
#include <windows.h>
#endif

#if defined(__MINGW32__) && !defined(__MINGW64_VERSION_MAJOR)
#define _aligned_malloc __mingw_aligned_malloc 
#define _aligned_free  __mingw_aligned_free 
#endif // __MINGW32__  and __MINGW64_VERSION_MAJOR

#include <malloc.h>



#define ASSERT_CL_RETURN( ret )\
   if( (ret) != CL_SUCCESS )\
   {\
      fprintf( stderr, "%s:%d: error: %s\n", \
             __FILE__, __LINE__, cluErrorString( (ret) ));\
      exit(FAILURE);\
   }

extern cl_mem_flags inFlags;
extern cl_mem_flags outFlags;
extern cl_mem_flags copyFlags;

extern struct _flags { cl_mem_flags f;
                       const char  *s; } flags[];
extern int nFlags;

extern cl_command_queue queue;
extern cl_context       context;
extern cl_kernel        read_kernel;
extern cl_kernel        write_kernel;
extern cl_uint          deviceMaxComputeUnits;
extern int              devnum;
extern char             devname[];

const char *cluErrorString(cl_int);
cl_int      spinForEventsComplete( cl_uint, cl_event * );
void        initCL( char *, double&);

#endif // _SHARED_H_
