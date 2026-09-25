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

#include "Shared.h"
#include "Host.h"
#include "Log.h"
#include "Timer.h"

#define SUCCESS 0
#define FAILURE 1
#define EXPECTED_FAILURE 2

#define SAMPLE_VERSION "AMD-APP-SDK-v2.9.214.1"

#define  WS 128       // work group size

int nLoops;           // overall number of timing loops
int loop;             // number of read/write buffer loops
int nRepeats;         // # of repeats for each transfer step
int nSkip;            // to discount lazy allocation effects, etc.
int nKLoops;          // repeat inside kernel to show peak mem B/W
int nBytes;           // input and output buffer size
int nThreads;         // number of Device work items
int nItems;           // number of 32-bit 4-vectors for Device kernel
int nAlign;           // safe bet for most PCs

int nBytesResult;

bool printLog;
bool doHost;
int  whichTest;

bool mapRW;
bool timings;
int  nWF;
double setupTime;

TestLog *tlog;
bool vFailure = false;
bool signalA = false;
bool signalB = false;
void *memIn,
     *memOut,
     *memResult,
     *memScratch;

cl_mem inputBuffer,
       outputBuffer,
       resultBuffer,
	   resultBuffer2,
       copyBuffer;

void usage()
{
            std::cout << "\nOptions:\n\n" <<
                 "   -type <n>          Type of test:\n\n" <<
                 "                      0 clEnqueue[Map,Unmap]\n" <<
                 "                      1 clEnqueue[Read,Write]\n" <<
                 "                      2 clEnqueueCopy\n" <<
                 "                      3 clEnqueue[Read,Write], prepinned\n\n" <<
                 "   -pcie or -dma      Measure PCIe/interconnect bandwidth\n" <<
				 "   -noblock           When -pcie is active, measure PCIe/interconnect\n" <<
				 "                      bandwidth using multiple back-to-back asynchronous\n" <<
				 "                      buffer copies\n" <<
				 "   -lp <n>            When -noblock is active, set the number of read/write\n" << 
				 "                      buffer\n" <<
				 "   -nwk <n>           Number of CPU workers (max: 32 (Linux: 1))\n" <<
                 "   -nl <n>            Number of timing loops\n" <<		
                 "   -nr <n>            Repeat each timing <n> times (can't be 0)\n" <<
                 "   -nk <n>            Number of loops in kernel\n" <<
                 "   -nb <n>            Buffer size in bytes (min: 2048*CPU Workers)\n" <<
                 "   -nw <n>            # of wave fronts per SIMD (can't be 0)\n" <<
                 "                      (default: 7)\n" <<
                 "   -l                 Print complete timing log\n" <<
                 "   -s <n>             Skip first <n> timings for average\n" <<
                 "                      (default: 1)\n" << 
                 "   -[if,of,cf] <n>    Input, output, copy flags\n" <<
                 "                      (ok to use multiple):\n\n";

            for(int i = 0; i < nFlags; i++ )
                std::cout << "                      " << i << " " << flags[i].s << "\n";
            std::cout << "\n";

            std::cout << "   -m                 always map as MAP_READ | MAP_WRITE\n" <<
                         "   -db                disable host mem B/W baseline\n" <<
                         "   -d <n>             Number of Device device\n" << 
						 "                      (always be 0, mean use the first device)\n" <<
						 "   -t                 Print all timings including setup-time\n" <<
                         "   -h                 print this message\n\n" <<
                         "   -v                 print the APP SDK version\n\n";
            exit(SUCCESS);
}

void parseOptions(int argc, char * argv[])
{
    while(--argc) 
    {
#ifdef _WIN32
        if( strcmp(argv[argc], "-nwk") == 0 )
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -nwk!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				nWorkers = atoi( argv[ argc + 1 ] );
				if (nWorkers <= 0)
				{
					std::cout<<"Invalid argument for -nwk!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}
			}
		}
            
#endif
        if( strcmp(argv[argc], "-nl") == 0 )           
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -nl!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				nLoops = atoi( argv[ argc + 1 ] );
				if (nLoops <= 0)
				{
					std::cout<<"Invalid argument for -nl!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}
			}
		}
		if( strcmp(argv[argc], "-lp") == 0 )           
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -lp!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				loop = atoi( argv[ argc + 1 ] );
				if (loop <= 0)
				{
					std::cout<<"Invalid argument for -lp!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}
			}
		}
        if( strcmp(argv[argc], "-nb") == 0 )          
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -nb!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				nBytes = atoi( argv[ argc + 1 ] );
				if (nBytes <= 0)
				{
					std::cout<<"Invalid argument for -nb!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}
			}
		}

        if( strcmp(argv[argc], "-nr") == 0 )           
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -nr!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				nRepeats = atoi( argv[ argc + 1 ] );
				if (nRepeats <= 0)
				{
					std::cout<<"Invalid argument for -nr!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}	
			}
		}

        if( strcmp(argv[argc], "-nk") == 0 )          
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -nk!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				nKLoops = atoi( argv[ argc + 1 ] );
				if (nKLoops <= 0)
				{
					std::cout<<"Invalid argument for -nk!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}
			}
		}

        if( strcmp(argv[argc], "-nw") == 0 )         
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -nw!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else 
			{
				nWF = atoi( argv[ argc + 1 ] );
				if (nWF <= 0)
				{
					std::cout<<"Invalid argument for -nw!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}	
			}
					
		}

        if( strcmp(argv[argc], "-type") == 0 )
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -type!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				whichTest = atoi( argv[ argc + 1 ] );
			}
		}

		if( strcmp(argv[argc], "-pcie") == 0 ||
		    strcmp(argv[argc], "-dma") == 0 )
		{    
			signalA = true;
		}

		if(strcmp(argv[argc], "-noblock") == 0)
		{    
			signalB = true;
		}

		if( strcmp(argv[argc], "-s") == 0 )           
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -s!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				nSkip = atoi( argv[ argc + 1 ] );
				if (nSkip <= 0)
				{
					std::cout<<"Invalid argument for -s!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}	
			}
		}

        if( strcmp(argv[argc], "-l") == 0 )
            printLog = true;

        if( strcmp(argv[argc], "-if") == 0 )
        {
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -if!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				 int f = atoi( argv[ argc + 1 ] );
				 if( f < nFlags )
                 inFlags |= flags[ f ].f;
			}           
        }

        if( strcmp(argv[argc], "-of") == 0 )
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -of!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				int f = atoi( argv[ argc + 1 ] );
                if( f < nFlags )
                outFlags |= flags[ f ].f;
			}           
        }

        if( strcmp(argv[argc], "-cf") == 0 )
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -cf!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				int f = atoi( argv[ argc + 1 ] );
                if( f < nFlags )
                copyFlags |= flags[ f ].f;
			}           
        }      

        if( strcmp(argv[argc], "-db") == 0 )
        {
            doHost = false;
        }

        if( strcmp(argv[argc], "-m") == 0 )
        {
            mapRW = true;
        }

		if( strcmp(argv[argc], "-t") == 0 )
        {
			timings = true;
        }

        if( strcmp(argv[argc], "-d") == 0 )
		{
			if ((argv[ argc + 1 ]) == NULL)
			{
				std::cout<<"Argument needed for -d!"<<std::endl;
				exit(EXPECTED_FAILURE);
			}
			else
			{
				devnum = atoi( argv[ argc + 1 ] );
				if (devnum != 0)
				{
					std::cout<<"Invalid argument for -d!"<<std::endl;
					exit(EXPECTED_FAILURE);
				}
			}
		}

        if( strcmp(argv[argc], "-h") == 0 )
           usage();

        if( strcmp(argv[argc], "-v") == 0 )
        {
            std::cout << "SDK version : " << SAMPLE_VERSION << std::endl;
            exit(0);
        }
    }

    if( whichTest > 3 || whichTest < 0 )
	{
		std::cout<<"Testtype index should be between 0 and 3!"<<std::endl;
		usage();
	}
    
}

void timedBufMappedRead( cl_command_queue queue,
                         cl_mem buf,
                         unsigned char v,
                         bool pcie )
{
    CPerfCounter t1, t2, t3;
    cl_int ret;
    cl_event ev;
    void *ptr;
    cl_map_flags mapFlag = CL_MAP_READ | CL_MAP_WRITE;

    t1.Reset();
    t2.Reset();
    t3.Reset();

    t1.Start();

    if( !mapRW )
        mapFlag = CL_MAP_READ;

    ptr = (void * ) clEnqueueMapBuffer( queue,
                                        buf,
                                        CL_FALSE,
                                        mapFlag,
                                        0,
                                        nBytes,
                                        0, NULL,
                                        &ev,
                                        &ret );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    t2.Start();

    bool verify = readVerifyMemCPU_MT( ptr, v, nBytes );
	if(!verify)
		vFailure = true;

    t2.Stop();

    t3.Start();

    ret = clEnqueueUnmapMemObject( queue,
                                   buf,
                                   (void *) ptr,
                                   0, NULL, &ev );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t3.Stop();

    if( pcie )
    {
        tlog->Timer( "PCIe B/W host->device (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
    }
    else
    {
        const char *msg;

        if( mapRW )
            msg = "clEnqueueMapBuffer -- READ|WRITE (GBPS)";
        else
            msg = "clEnqueueMapBuffer -- READ (GBPS)";

        tlog->Timer( msg, t1.GetElapsedTime(), nBytes, 1 );
        tlog->Timer( "CPU read (GBPS)", t2.GetElapsedTime(), nBytes, 1 ); 
		tlog->Timer( "clEnqueueUnmapMemObject() (GBPS)", t3.GetElapsedTime(), nBytes, 1 );

	    if( verify )
            tlog->Msg( "\n Verification Passed!\n", "" );
        else
        {
            tlog->Error( "\n Verification Failed!\n", "" );
            vFailure = true;
        }
    }
}

void timedBufMappedWrite( cl_command_queue queue,
                          cl_mem buf,
                          unsigned char v,
                          bool pcie )
{
    CPerfCounter t1, t2, t3;
    cl_int ret;
    cl_event ev;
    void *ptr;
    cl_map_flags mapFlag = CL_MAP_READ | CL_MAP_WRITE;

    t1.Reset();
    t2.Reset();
    t3.Reset();

    t1.Start();

    if( !mapRW )
        mapFlag = CL_MAP_WRITE_INVALIDATE_REGION;

    ptr = (void * ) clEnqueueMapBuffer( queue,
                                        buf,
                                        CL_FALSE,
                                        mapFlag,
                                        0,
                                        nBytes,
                                        0, NULL, 
                                        &ev,
                                        &ret );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    t2.Start();

    memset_MT( ptr, v, nBytes );

    t2.Stop();

    t3.Start();

    ret = clEnqueueUnmapMemObject( queue,
                                   buf,
                                   (void *) ptr,
                                   0, NULL, &ev );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t3.Stop();

    if( pcie )
    {
        tlog->Timer( "PCIe B/W device->host (GBPS)", t3.GetElapsedTime(), nBytes, 1 );
    }
    else
    {
        const char *msg;

        if( mapRW )
            msg = "clEnqueueMapBuffer -- READ|WRITE (GBPS)";
        else
            msg = "clEnqueueMapBuffer -- WRITE (GBPS)";

        tlog->Timer( msg, t1.GetElapsedTime(), nBytes, 1 );

        tlog->Timer( "memset() (GBPS)", t2.GetElapsedTime(), nBytes, 1 );

        tlog->Timer( "clEnqueueUnmapMemObject() (GBPS)", t3.GetElapsedTime(), nBytes, 1 );
    }
}

void timedBufMap( cl_command_queue queue,
                  cl_mem buf,
                  void **ptr,
                  bool quiet )
{
    CPerfCounter t1;
    cl_int ret;
    cl_event ev;
    cl_map_flags mapFlag = CL_MAP_READ | CL_MAP_WRITE;

    t1.Reset();
    t1.Start();

    *ptr = (void * ) clEnqueueMapBuffer( queue,
                                         buf,
                                         CL_FALSE,
                                         mapFlag,
                                         0,
                                         nBytes,
                                         0, NULL,
                                         &ev,
                                         &ret );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    const char *msg;

    if( mapRW )
        msg = "clEnqueueMapBuffer -- READ|WRITE (GBPS)";
    else
        msg = "clEnqueueMapBuffer -- READ (GBPS)";

    if( !quiet )
        tlog->Timer( msg, t1.GetElapsedTime(), nBytes, 1 );
}

void timedBufUnmap( cl_command_queue queue,
                    cl_mem buf,
                    void **ptr,
                    bool quiet )
{
    CPerfCounter t1;
    cl_int ret;
    cl_event ev;

    t1.Reset();
    t1.Start();

    ret = clEnqueueUnmapMemObject( queue,
                                   buf,
                                   (void *) *ptr,
                                   0, NULL, &ev );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    if( !quiet )
        tlog->Timer( "clEnqueueUnmapMemObject() (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
}

void timedBufCLRead( cl_command_queue queue,
                     cl_mem buf,
                     void *ptr,
                     unsigned char v,
                     bool pcie )
{
    CPerfCounter t1;
    cl_int ret;
    cl_event ev;

    t1.Start();

    ret = clEnqueueReadBuffer( queue,
                               buf,
                               CL_FALSE,
                               0,
                               nBytes,
                               ptr,
                               0, NULL,
                               &ev );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    bool verify = readVerifyMemCPU_MT( ptr, v, nBytes );
	if(!verify)
		vFailure = true;

    if( pcie )
    {
        tlog->Timer("PCIe B/W device->host (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
    }
    else
    {
        tlog->Timer( "clEnqueueReadBuffer (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
    }
}

void timedBufCLWrite( cl_command_queue queue,
                      cl_mem buf,
                      void *ptr,
                      unsigned char v,
                      bool pcie )
{
    CPerfCounter t1;
    cl_int ret;
    cl_event ev;

    memset( ptr, v, nBytes );

    t1.Start();

    ret = clEnqueueWriteBuffer( queue,
                                buf,
                                CL_FALSE,
                                0,
                                nBytes,
                                ptr,
                                0, NULL,
                                &ev );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    if( pcie )
    {
        tlog->Timer( "PCIe B/W host->device (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
    }
    else
    {
        tlog->Timer( "clEnqueueWriteBuffer (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
    }
}

void timedBufCLCopy( cl_command_queue queue,
                     cl_mem srcBuf,
                     cl_mem dstBuf )
{
    CPerfCounter t1;
    cl_int ret;
    cl_event ev;

    t1.Start();

    ret = clEnqueueCopyBuffer( queue,
                               srcBuf,
                               dstBuf,
                               0, 0,
                               nBytes,
                               0, NULL,
                               &ev );
    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

    t1.Stop();

    tlog->Timer( "clEnqueueCopyBuffer (GBPS)", t1.GetElapsedTime(), nBytes, 1 );
}

void timedKernel( cl_command_queue queue,
                  cl_kernel        kernel,
                  cl_mem           bufSrc,
                  cl_mem           bufDst,
                  unsigned char    v,
                  bool             quiet )
{
     cl_int ret;
     cl_event ev=0;
     CPerfCounter t;

     cl_uint nItemsPerThread = nItems / nThreads;

     size_t global_work_size[2] = { nThreads, 0 };
     size_t local_work_size[2] = { WS, 0 };

     cl_uint val=0;

     for(int i = 0; i < sizeof( cl_uint ); i++)
        val |= v << (i * 8);

     clSetKernelArg( kernel, 0, sizeof(void *),  (void *) &bufSrc );
     clSetKernelArg( kernel, 1, sizeof(void *),  (void *) &bufDst );
     clSetKernelArg( kernel, 2, sizeof(cl_uint), (void *) &nItemsPerThread);
     clSetKernelArg( kernel, 3, sizeof(cl_uint), (void *) &val);
     clSetKernelArg( kernel, 4, sizeof(cl_uint), (void *) &nKLoops);

     t.Reset();
     t.Start();

     ret = clEnqueueNDRangeKernel( queue,
                                   kernel,
                                   1,
                                   NULL,
                                   global_work_size,
                                   local_work_size,
                                   0, NULL, &ev );
     ASSERT_CL_RETURN( ret );

     clFlush( queue );
     spinForEventsComplete( 1, &ev );

     t.Stop();

     if( !quiet )
         tlog->Timer( "clEnqueueNDRangeKernel() (GBPS)", 
                      t.GetElapsedTime(), nBytes, nKLoops );
}

void timedReadKernelVerify( cl_command_queue queue,
                            cl_kernel        kernel,
                            cl_mem           bufSrc,
                            cl_mem           bufRes,
                            unsigned char    v,
                            bool             quiet )
{
    cl_int ret;
    cl_event ev;

    timedKernel( queue, kernel, bufSrc, bufRes, v, quiet );

    ret = clEnqueueReadBuffer( queue,
                               bufRes,
                               CL_FALSE,
                               0,
                               nBytesResult,
                               memResult,
                               0, NULL,
                               &ev );

    ASSERT_CL_RETURN( ret );

    clFlush( queue );
    spinForEventsComplete( 1, &ev );

     cl_uint sum = 0;

     for(int i = 0; i < nThreads / WS; i++)
         sum += ((cl_uint *) memResult)[i];

     bool verify;

     if( sum == nBytes / sizeof(cl_uint) )
         verify = true;
     else
     {
         verify = false;
         vFailure = true;
     }

	 if( !quiet )
     {
        if( verify )
            tlog->Msg( "\n Verification Passed!\n", "" );
        else
            tlog->Error( "\n Verification Failed!\n", "" );
     }
}

void createBuffers()
{
   // host memory buffers

#ifdef _WIN32
   memIn =      (void *) _aligned_malloc( nBytes, nAlign );
   memOut =     (void *) _aligned_malloc( nBytes, nAlign );
   memResult =  (void *) _aligned_malloc( nBytesResult, nAlign );
   memScratch = (void *) _aligned_malloc( nBytes, nAlign );
#else
   memIn =      (void *) memalign( nAlign, nBytes );
   memOut =     (void *) memalign( nAlign, nBytes );
   memResult =  (void *) memalign( nAlign, nBytesResult );
   memScratch = (void *) memalign( nAlign, nBytes );
#endif

   if( memIn == NULL ||
       memOut == NULL ||
       memResult == NULL ||
       memScratch == NULL ) 
   {
       fprintf( stderr, "%s:%d: error: %s\n", \
                __FILE__, __LINE__, "could not allocate host buffers\n" );
       exit(FAILURE);
   }

   // CL buffers

   cl_int ret;
   void *hostPtr = NULL;

   if( inFlags & CL_MEM_USE_HOST_PTR ||
       inFlags & CL_MEM_COPY_HOST_PTR )
       hostPtr = memIn;

   inputBuffer = clCreateBuffer( context,
                                 inFlags,
                                 nBytes,
                                 hostPtr, &ret );

   ASSERT_CL_RETURN( ret );

   hostPtr = NULL;

   if( outFlags & CL_MEM_USE_HOST_PTR ||
       outFlags & CL_MEM_COPY_HOST_PTR )
       hostPtr = memOut;

   outputBuffer = clCreateBuffer( context,
                                  outFlags,
                                  nBytes,
                                  hostPtr, &ret );

   ASSERT_CL_RETURN( ret );

   hostPtr = NULL;

   if( copyFlags & CL_MEM_USE_HOST_PTR ||
       copyFlags & CL_MEM_COPY_HOST_PTR )
       hostPtr = memScratch;

   if( whichTest == 2 ||
       whichTest == 3 ||
	   signalA )
      copyBuffer = clCreateBuffer( context,
                                   copyFlags,
                                   nBytes,
                                   hostPtr, &ret );

   ASSERT_CL_RETURN( ret );

   resultBuffer = clCreateBuffer( context,
                                  CL_MEM_READ_WRITE,
                                  nBytesResult,
                                  NULL, &ret );
   ASSERT_CL_RETURN( ret );

   resultBuffer2 = clCreateBuffer( context,
                                  CL_MEM_READ_WRITE,
                                  nBytesResult,
                                  NULL, &ret );
   ASSERT_CL_RETURN( ret );
}

void printHeader()
{
	std::cout << "\nDevice " << std::setw(2) << devnum << "            " << devname << "\n";

#ifdef _WIN32
    std::cout << "Build:               _WINxx"; 
#ifdef _DEBUG
    std::cout << " DEBUG";
#else
    std::cout << " release";
#endif
    std::cout << "\n" ;
#else
#ifdef NDEBUG
    std::cout << "Build:               release\n";
#else
    std::cout << "Build:               DEBUG\n";
#endif
#endif

    std::cout << "Device work items:      " << nThreads << std::endl <<
                 "Buffer size:         " << nBytes << std::endl <<
                 "CPU workers:         " << nWorkers << std::endl <<
                 "Timing loops:        " << nLoops << std::endl <<
                 "Repeats:             " << nRepeats << std::endl <<
                 "Kernel loops:        " << nKLoops << std::endl;

    std::cout << "inputBuffer:         ";

   for( int i = 0; i < nFlags; i++ )
      if( inFlags & flags[i].f )
          std::cout << flags[i].s << " ";

   std::cout << "\noutputBuffer:        ";

   for( int i = 0; i < nFlags; i++ )
      if( outFlags & flags[i].f )
         std::cout << flags[i].s << " ";

   if( whichTest == 2 ||
       whichTest == 3 ||
       signalA)
   {
       std::cout << "\ncopyBuffer:          " ;

      for( int i = 0; i < nFlags; i++ )
      if( copyFlags & flags[i].f )
          std::cout << flags[i].s << " ";
   }

   std::cout << "\n\n";
}

void printResults()
{
    if(timings)
	{
		std::cout << std::setw(21) << std::left << "Setup Time"
				<< setupTime << " secs" << std::endl;
	}
	
	if( printLog ) 
      tlog->printLog();

   tlog->printSummary( nSkip );

   std::cout << "\n" ;
   fflush(stdout);
}

void runMapTest()
{
   int  nl = nLoops;

   while( nl-- )
   {
      tlog->loopMarker();

      tlog->Msg( "\n\n%s\n", "1. Host mapped write to inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufMappedWrite( queue, inputBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "2. Device kernel read of inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedReadKernelVerify( queue, read_kernel, inputBuffer, resultBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "3. Device kernel write to outputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedKernel( queue, write_kernel, resultBuffer, outputBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "4. Host mapped read of outputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufMappedRead( queue, outputBuffer, nl & 0xff, false );

      tlog->Msg( "%s\n", "" );
   }
}

void runPCIeTest()
{
   int nl = nLoops;

   void *mappedPtr;
   while( nl-- )
   {
      tlog->loopMarker();

      tlog->Msg( "%s\n", "" );

      timedBufMap( queue, copyBuffer, &mappedPtr, true );
	  
      for(int i = 0; i < nRepeats; i++)
          timedBufCLWrite( queue, inputBuffer, mappedPtr, nl & 0xff, true );
	  
      for(int i = 0; i < nRepeats; i++)
          timedReadKernelVerify( queue, read_kernel, inputBuffer, resultBuffer, nl & 0xff, true );

      for(int i = 0; i < nRepeats; i++)
          timedKernel( queue, write_kernel, resultBuffer, outputBuffer, nl & 0xff, true );
	 
      for(int i = 0; i < nRepeats; i++)
          timedBufCLRead( queue, outputBuffer, mappedPtr, nl & 0xff, true );

      timedBufUnmap( queue, copyBuffer, &mappedPtr, true );

      tlog->Msg( "%s\n", "" );
   }
}
void runPCIeTestNoblock()
{
   	int nl = nLoops;
    void *mappedPtr;

	while( nl-- )
	{
		tlog->loopMarker();

		tlog->Msg( "%s\n", "" );

		timedBufMap( queue, copyBuffer, &mappedPtr, true );
		CPerfCounter t1;
		cl_int ret;
		cl_event ev;
		bool flag=true;
		memset( mappedPtr, nl & 0xff, nBytes );
		t1.Reset();
		t1.Start();
		for(int i = 0; i < loop; i++)
		{
			ret = clEnqueueWriteBuffer( queue,
										inputBuffer,
										CL_FALSE,
										0,
										nBytes,
										mappedPtr,
										0, NULL,
										&ev );
			ASSERT_CL_RETURN( ret );
		}
		clFlush( queue );
		spinForEventsComplete( 1, &ev );

		t1.Stop();
		double avg=(t1.GetElapsedTime())/loop;
		if( flag )
		{
			tlog->Timer( "PCIe B/W host->device (GBPS)", avg, nBytes, 1 );
		}
		else
		{
			tlog->Timer( "clEnqueueWriteBuffer (GBPS)", avg, nBytes, 1 );
		}
		timedReadKernelVerify( queue, read_kernel, inputBuffer, resultBuffer, nl & 0xff, true );

		timedKernel( queue, write_kernel, resultBuffer, outputBuffer, nl & 0xff, true );
		t1.Reset();
		t1.Start();
		for(int i = 0; i < loop; i++)
		{
			ret = clEnqueueReadBuffer( queue,
								   outputBuffer,
								   CL_FALSE,
								   0,
								   nBytes,
								   mappedPtr,
								   0, NULL,
								   &ev );
			ASSERT_CL_RETURN( ret );
		}
		clFlush( queue );
		spinForEventsComplete( 1, &ev );

		t1.Stop();
		avg=(t1.GetElapsedTime())/loop;
		bool verify = readVerifyMemCPU_MT( mappedPtr, nl & 0xff, nBytes );

		if(flag)
		{
			tlog->Timer( "PCIe B/W device->host (GBPS)", avg, nBytes, 1 );
		}
		else
		{
			tlog->Timer( "clEnqueueReadBuffer (GBPS)", avg, nBytes, 1 );
		}
		timedBufUnmap( queue, copyBuffer, &mappedPtr, true );

		if(!flag)
		{
			if(!verify)
			{
				vFailure = true;
			}
		}
		tlog->Msg( "%s\n", "" );
	}
}

void runReadWriteTest()
{
   
   int nl = nLoops;

   while( nl-- )
   {
      tlog->loopMarker();

      tlog->Msg( "\n\n%s\n", "1. Host CL write to inputBuffer" );
	 
      for(int i = 0; i < nRepeats; i++)
          timedBufCLWrite( queue, inputBuffer, memScratch, nl & 0xff, false );
	  
      tlog->Msg( "\n\n%s\n", "2. Device kernel read of inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedReadKernelVerify( queue, read_kernel, inputBuffer, resultBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "3. Device kernel write to outputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedKernel( queue, write_kernel, resultBuffer, outputBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "4. Host CL read of outputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufCLRead( queue, outputBuffer, memScratch, nl & 0xff, false );
	 
      tlog->Msg( "%s\n", "" );
   }
}

void runMappedReadWriteTest()
{
   int nl = nLoops;

   void *mappedPtr;

   while( nl-- )
   {
      tlog->loopMarker();

      tlog->Msg( "\n\n%s\n", "1. Mapping copyBuffer as mappedPtr" );

      timedBufMap( queue, copyBuffer, &mappedPtr, false );

      tlog->Msg( "\n\n%s\n", "2. Host CL write from mappedPtr to inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufCLWrite( queue, inputBuffer, mappedPtr, nl & 0xff, false );
	  
      tlog->Msg( "\n\n%s\n", "3. Device kernel read of inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedReadKernelVerify( queue, read_kernel, inputBuffer, resultBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "4. Device kernel write to outputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedKernel( queue, write_kernel, resultBuffer, outputBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "5. Host CL read of outputBuffer to mappedPtr" );
	  
	  
      for(int i = 0; i < nRepeats; i++)
          timedBufCLRead( queue, outputBuffer, mappedPtr, nl & 0xff, false );
	  
      tlog->Msg( "\n\n%s\n", "6. Unmapping copyBuffer" );

      timedBufUnmap( queue, copyBuffer, &mappedPtr, false );

      tlog->Msg( "%s\n", "" );
   }
}

void runCopyTest()
{
   int nl = nLoops;

   while( nl-- )
   {
      tlog->loopMarker();

      tlog->Msg( "\n\n%s\n", "1. Host mapped write to copyBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufMappedWrite( queue, copyBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "2. CL copy of copyBuffer to inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufCLCopy( queue, copyBuffer, inputBuffer );

      tlog->Msg( "\n\n%s\n", "3. Device kernel read of inputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedReadKernelVerify( queue, read_kernel, inputBuffer, resultBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "4. Device kernel write to outputBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedKernel( queue, write_kernel, resultBuffer, outputBuffer, nl & 0xff, false );

      tlog->Msg( "\n\n%s\n", "5. CL copy of outputBuffer to copyBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufCLCopy( queue, outputBuffer, copyBuffer );

      tlog->Msg( "\n\n%s\n", "6. Host mapped read of copyBuffer" );

      for(int i = 0; i < nRepeats; i++)
          timedBufMappedRead( queue, copyBuffer, nl & 0xff, false );

      tlog->Msg( "%s\n", "" );
   }
}

void initDefaults()
{
    nWorkers = 1;
    nLoops = 20;
	loop = 20;
    nRepeats = 1;
    nSkip = 2;
    nKLoops = 20;

    nBytes = 32*1024*1024;
    nAlign = 4096;

    printLog = false;
    doHost = true;
    whichTest = 0;
    mapRW = false;
	timings = false;
    nWF = 7;
    devnum = 0;
}

void computeGlobals()
{
    if( nWorkers > MAXWORKERS ) nWorkers = MAXWORKERS;
    if( nWorkers <= 0 ) nWorkers = 1;

    cl_mem_flags f = CL_MEM_READ_ONLY |
                     CL_MEM_WRITE_ONLY |
                     CL_MEM_READ_WRITE;

    if( (inFlags & f) == 0 )
             inFlags |= CL_MEM_READ_ONLY;

    if( (outFlags & f) == 0 )
             outFlags |= CL_MEM_WRITE_ONLY;

    f |= CL_MEM_USE_HOST_PTR |
         CL_MEM_COPY_HOST_PTR |
         CL_MEM_ALLOC_HOST_PTR;

    /*
    f |= CL_MEM_USE_HOST_PTR |
         CL_MEM_COPY_HOST_PTR |
         CL_MEM_ALLOC_HOST_PTR |
         CL_MEM_USE_PERSISTENT_MEM_AMD;
    */

    if( (copyFlags & f) == 0 )
             copyFlags = CL_MEM_ALLOC_HOST_PTR | CL_MEM_READ_WRITE;

    f = CL_MEM_READ_ONLY |
        CL_MEM_WRITE_ONLY |
        CL_MEM_READ_WRITE;

    if( (copyFlags & f) == 0 )
             copyFlags |= CL_MEM_READ_WRITE;

    nSkip = nLoops > nSkip ? nSkip : 0;

    if( signalA )
    {
        inFlags = CL_MEM_READ_ONLY;
        outFlags = CL_MEM_WRITE_ONLY;
        copyFlags = CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE;
        nKLoops = 1;
        doHost = false;
    }

    // educated guess of optimal work size
    int minBytes = WS * sizeof( cl_uint ) * 4 * nWorkers;

    nBytes = ( nBytes / minBytes ) * minBytes;
    nBytes = nBytes < minBytes ? minBytes : nBytes;
    nItems = nBytes / ( 4 * sizeof(cl_uint) );
    
    int maxThreads = nBytes / ( 4 * sizeof( cl_uint ) );

    nThreads = deviceMaxComputeUnits * nWF * WS;
 
    if( nThreads > maxThreads )
        nThreads = maxThreads;
    else
    {
        while( nItems % nThreads != 0 )
            nThreads += WS;
    }

    nBytesResult = ( nThreads / WS ) * sizeof(cl_uint);
}

int main(int argc, char **argv)
{
	initDefaults();
    parseOptions( argc, argv );

    tlog = new TestLog( nLoops * nRepeats * 50 );

	initCL( (char *) "BufferBandwidth_Kernels.cl", setupTime );

    computeGlobals();
    printHeader();
    createBuffers();

	#ifdef MEM_MULTICORE
		launchThreads();
	#endif

    if( doHost )
       assessHostMemPerf( memIn, memOut, nBytes );
	if(signalA)
	{
		if(signalB)
		{
			runPCIeTestNoblock();
		}
		else
		{
			runPCIeTest();
		}
	}
	else
	{
		switch( whichTest )
		{
		   case 0: runMapTest(); break;
		   case 1: runReadWriteTest(); break;
		   case 2: runCopyTest(); break;
		   case 3: runMappedReadWriteTest(); break;
		}
	}

	if((!signalA) && signalB) 
	{
		std::cout<<"-noblock will only work when -pcie or -dma is active!"<<std::endl;
		exit(FAILURE);
	}
    printResults();

	#ifdef MEM_MULTICORE
		shutdownThreads();
	#endif

    if( vFailure )
    {
        std::cerr << "Failed!" << std::endl;
		return FAILURE;
    }                                                                                                                                                                                                                 
    else
    {
        std::cout << "Passed!" << std::endl;
		return SUCCESS;
    }
}
