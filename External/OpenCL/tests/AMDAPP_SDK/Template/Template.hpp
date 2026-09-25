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


#ifndef TEMPLATE_H_
#define TEMPLATE_H_




#include <CL/cl.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>


// GLOBALS 
#define SDK_SUCCESS 0
#define SDK_FAILURE 1

/*
 * Input data is stored here.
 */
cl_uint *input;

/*
 * Output data is stored here.
 */
cl_uint *output;

/*
 * Multiplier is stored in this variable 
 */
cl_uint multiplier;

/* problem size for 1D algorithm and width of problem size for 2D algorithm */
cl_uint width;

/* The memory buffer that is used as input/output for OpenCL kernel */
cl_mem   inputBuffer;
cl_mem	 outputBuffer;

cl_context          context;
cl_device_id        *devices;
cl_command_queue    commandQueue;

cl_program program;

/* This program uses only one kernel and this serves as a handle to it */
cl_kernel  kernel;


// FUNCTION DECLARATIONS 

/*
 * OpenCL related initialisations are done here.
 * Context, Device list, Command Queue are set up.
 * Calls are made to set up OpenCL memory buffers that this program uses
 * and to load the programs into memory and get kernel handles.
 */
int initializeCL(void);

/*
 * Convert char* to string
 */
std::string convertToString(const char * filename);

/*
 * This is called once the OpenCL context, memory etc. are set up,
 * the program is loaded into memory and the kernel handles are ready.
 * 
 * It sets the values for kernels' arguments and enqueues calls to the kernels
 * on to the command queue and waits till the calls have finished execution.
 *
 * It also gets kernel start and end time if profiling is enabled.
 * @return returns SDK_SUCCESS on success and SDK_FAILURE otherwise
 */
int runCLKernels(void);

/**
 * Releases OpenCL resources (Context, Memory etc.) 
 * @return returns SDK_SUCCESS on success and SDK_FAILURE otherwise
 */
int cleanupCL(void);

/**
 * Releases program's resources
 * @return returns SDK_SUCCESS on success and SDK_FAILURE otherwise 
 */
void cleanupHost(void);

/*
 * Prints no more than 256 elements of the given array.
 * Prints full array if length is less than 256.
 *
 * Prints Array name followed by elements.
 */
void print1DArray(
         const std::string arrayName, 
         const unsigned int * arrayData, 
         const unsigned int length);


#endif  /* #ifndef TEMPLATE_H_ */
