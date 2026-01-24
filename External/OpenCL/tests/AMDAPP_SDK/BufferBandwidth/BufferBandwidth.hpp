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

#ifndef BUFFER_BANDWIDTH_H_
#define BUFFER_BANDWIDTH_H_

#undef   USE_CL_PROFILER
#define  MAX_WAVEFRONT_SIZE 64               // work group size

#include "Host.h"
#include "Log.h"
#include "Timer.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


/**
 * BufferBandwidth 
 * Class implements OpenCL Constant Buffer Bandwidth sample
 * Derived from SDKSample base class
 */

class BufferBandwidth 
{
    bool correctness;  // correctness status variable
    bool enable;       // Enable flags -i, -r, -k, -x and -s
    int nLoops;        // overall number of timing loops
    int nRepeats;      // # of repeats for each transfer step
    int nSkip;         // to discount lazy allocation effects, etc.
    int nKLoops;       // repeat inside kernel to show peak mem B/W,

    int nBytes;        // input and output buffer size
    int nThreads;      // number of Device work items
    int nItems;        // number of 32-bit 4-vectors for Device kernel
    int nAlign;        // safe bet for most PCs
    int nBytesResult;

    bool printLog;
    bool doHost;
    int  whichTest;   // Type of the test
    bool mapRW;
    int  numWavefronts;

    TestLog *tlog;    // Log information class

    void *memIn;
    void *memOut;
    void *memResult;
    void *memRW;

    int inFlagsValue; 
    int outFlagsValue;
    int copyFlagsValue;
 
public:
    /** 
     * Constructor 
     * Initialize member variables
     * @param name name of sample (string)
     */
    BufferBandwidth(std::string name)
        :
         nLoops(20),
         nRepeats(1),
         nSkip(2),
         nKLoops(20),
         nBytes(32 * 1024 * 1024),
         nThreads(MAX_WAVEFRONT_SIZE), 
         nItems(2), 
         nAlign(4096),
         nBytesResult(1024 * 1024),
         printLog(false),
         doHost(false),
         whichTest(0),
         mapRW(false), 
         numWavefronts(7), 
         tlog(NULL),
         memIn(NULL), 
         memOut(NULL),
         memResult(NULL), 
         memRW(NULL),
         inFlagsValue(0), 
         outFlagsValue(1),
         copyFlagsValue(2),
         correctness(true),
         enable(false)
    {
    }

    /** 
     * Constructor 
     * Initialize member variables
     * @param name name of sample (const char*)
     */
    BufferBandwidth(const char* name)
        :
         nLoops(20),
         nRepeats(1),
         nSkip(2),
         nKLoops(20),
         nBytes(32 * 1024 * 1024), 
         nThreads(MAX_WAVEFRONT_SIZE), 
         nItems(2), 
         nAlign(4096),
         nBytesResult(1024 * 1024),
         printLog(false),
         doHost(false),
         whichTest(0),
         mapRW(false), 
         numWavefronts(7), 
         tlog(NULL),
         memIn(NULL), 
         memOut(NULL),
         memResult(NULL), 
         memRW(NULL),
         inFlagsValue(0), 
         outFlagsValue(1),
         copyFlagsValue(2),
         correctness(true),
         enable(false)
    {
    }

    /**
     * Allocate and initialize host memory array with random values
     * @return 1 on success and 0 on failure
     */
    int setupBufferBandwidth();

    /**
     * OpenCL related initialisations. 
     * Set up Context, Device list, Command Queue, Memory buffers
     * Build CL kernel program executable
     * @return 1 on success and 0 on failure
     */
    int setupCL();


    /**
     * Override from SDKSample. Initialize 
     * command line parser, add custom options
     */
    int initialize();

    /**
     * Override from SDKSample, Generate binary image of given kernel 
     * and exit application
     */
    int genBinaryImage();

    /**
     * Override from SDKSample, adjust width and height 
     * of execution domain, perform all sample setup
     */
    int setup();

    /**
     * Override from SDKSample
     */
    int run();

    /**
     * Override from SDKSample
     * Cleanup memory allocations
     */
    int cleanup();

    /**
     * Override from SDKSample
     * Verify against reference implementation
     */
    int verifyResults();

    void printStats();

    /**
     * Parses Extra command line options and 
     * calls SDKSample::parseCommandLine()
     */
    int parseExtraCommandLineOptions(int argc, char**argv);
    int runMapTest();
    int runReadWriteTest();
    int runCopyTest();
    int timedBufMappedRead(cl_mem buf, unsigned char v);
    int timedBufMappedWrite(cl_mem buf, unsigned char v);
    int timedBufCLRead(cl_mem buf, void *ptr, unsigned char v);
    int timedBufCLWrite(cl_mem buf, void *ptr);
    int timedBufCLCopy(cl_mem srcBuf, cl_mem dstBuf);
    int timedKernel(cl_kernel kernel, cl_mem bufSrc, cl_mem bufDst, unsigned char v);
    int timedReadKernelVerify(cl_kernel kernel, cl_mem bufSrc, cl_mem bufRes, unsigned char v);
    void printLogMsg();

};


#endif
