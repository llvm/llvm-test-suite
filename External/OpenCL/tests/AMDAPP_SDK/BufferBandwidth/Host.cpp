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

#include "Host.h"
#include "Timer.h"

#include <iostream>
#include <iomanip>

#include <stdio.h>
#if !defined(__MINGW64__)
#include <emmintrin.h>
#include <xmmintrin.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <process.h>
#else
#include <unistd.h>
#include <string.h>
#endif

#define MTYPE unsigned long

// Suppress the warning #810 if intel compiler is used.
#if defined(__INTEL_COMPILER) || defined(__MINGW64__)
#pragma warning(disable : 810)
#endif

int nWorkers;

typedef struct {

    void (*work_func)( int );

    void *ptr;
    void *ptr2;
    unsigned char v;
    size_t len;

    bool ret;
    bool noop;
    bool exit;

} _threadWork;

static _threadWork work[MAXWORKERS];

#ifdef MEM_MULTICORE

static HANDLE      tn[MAXWORKERS];
static unsigned    tid[MAXWORKERS];

// pad to something > cacheline to avoid false sharing
static int volatile myBarrier[MAXWORKERS][64]={0};

unsigned int __stdcall myThreadFunc( void * arg )
{
    int* idPtr = (int*)(arg);
    int id = *idPtr;
    bool exit = false;

    while( !exit )
    {
        // counterpart to releaseThreads()
        while(myBarrier[id][0] != 1)
            Sleep(0);
        myBarrier[id][0] = 0;

        if( work[id].work_func != NULL )
            work[id].work_func( id );

        if( work[id].exit == true )
            exit = true;

        // counterpart to waitForThreads()
        myBarrier[id][1] = 1;
        Sleep(0);
    }

    return 0;
}
#endif

void releaseThreads()
{
#ifdef MEM_MULTICORE
    int n;

    for( n=1; n<nWorkers; n++ )
    {
        myBarrier[n][0] = 1;
    }
    Sleep(0);
#endif
}

void waitForThreads()
{
#ifdef MEM_MULTICORE
    int n;

    for( n = 1; n < nWorkers; n++ )
    {
        while( myBarrier[n][1] != 1 )
            Sleep(0);

        myBarrier[n][1] = 0;
    }
#endif
}

void launchThreads()
{
#ifdef MEM_MULTICORE
    int *nArg = (int*)malloc(sizeof(int) *(nWorkers + 1));
    int n;
    for( n = 1; n < nWorkers; n++ )
    {
        nArg[n] = n;
        work[n].exit = false;
        work[n].work_func = NULL;

        tn[n] = (HANDLE) _beginthreadex( NULL, 0, myThreadFunc, (void *) (&nArg[n]), 0, &tid[n] );
    }

    // XXX if this isn't here subsequent barrier roundtrips
    // are more expensive. Why?
    releaseThreads();
    waitForThreads();
    if(nArg)
        free(nArg);
#endif
}

void shutdownThreads()
{
#ifdef MEM_MULTICORE
    int n;

    for( n = 1; n < nWorkers; n++ )
    {
        work[n].exit = true;
        work[n].work_func = NULL;
    }

    releaseThreads();
    waitForThreads();

    for(int n = 1; n < nWorkers; n++)
    {
        WaitForSingleObject( tn[n], INFINITE );
    }
#endif
}

bool myMasterFunc()
{
    releaseThreads();

    // do my chunk of work
    work[0].work_func( 0 );

    waitForThreads();

    bool ret = true;

    for(int n = 0; n < nWorkers; n++)
    {
        if( work[n].ret == false ) ret = false;
    }

    return( ret );
}

void readVerifyMemCPU_WF( int id )
{
    work[id].ret = readVerifyMemCPU( work[id].ptr, work[id].v, work[id].len );
}

bool readVerifyMemCPU_MT( void *ptr, unsigned char v, size_t len )
{
    size_t blksz = len / nWorkers;

    // distribute work
    for(int n = 0; n < nWorkers; n++)
    {
        work[n].work_func = readVerifyMemCPU_WF;
        work[n].ptr = (void *) ((char *) ptr + n * blksz);
        work[n].v = v;
        work[n].len = blksz;
    }

    return myMasterFunc();
}

void memcpy_WF( int id )
{
    memcpy( work[id].ptr, work[id].ptr2, work[id].len );
}

void memcpy_MT( void *ptr, void *ptr2, size_t len )
{
    size_t blksz = len / nWorkers;

    // distribute work
    for(int n = 0; n < nWorkers; n++)
    {
        work[n].work_func = memcpy_WF;
        work[n].ptr = (void *) ((char *) ptr + n * blksz);
        work[n].ptr2 = (void *) ((char *) ptr2 + n * blksz);
        work[n].len = blksz;
    }

    (void) myMasterFunc();
}

void memset_WF( int id )
{
    memset( work[id].ptr, work[id].v, work[id].len );
}

void memset_MT( void *ptr, unsigned char v, size_t len )
{
    size_t blksz = len / nWorkers;

    // distribute work
    for(int n = 0; n < nWorkers; n++)
    {
        work[n].work_func = memset_WF;
        work[n].ptr = (void *) ((char *) ptr + n * blksz);
        work[n].v = v;
        work[n].len = blksz;
    }

    (void) myMasterFunc();
}

void empty_WF( int id )
{
    volatile int i=0;
}

void empty_MT()
{
    // distribute work
    for(int n = 0; n < nWorkers; n++) {
        work[n].work_func = empty_WF;
    }

    (void) myMasterFunc();
}

void benchLaunch()
{
   CPerfCounter t; t.Reset();

   int nl = 100;

   t.Start();

   for(int n = 0; n < nl; n++)
   {
      launchThreads();
      shutdownThreads();
   }

   t.Stop();

   std::cout << "Launch speed" << "  " << t.GetElapsedTime() / nl * 1e9 << nWorkers << " ns\n";
}

void benchBarrier()
{
   CPerfCounter t; 
   t.Reset();

   int nl=100000;

   t.Start();

   for(int n = 0; n < nl; n++)
   {
      empty_MT();
   }

   t.Stop();
   std::cout << std::setw(21) << std::left << "Barrier speed" << std::setw(7) << t.GetElapsedTime() / nl * 1e9 << " ns\n";
}

bool readVerifyMemCPU( void *ptr, unsigned char v, size_t len )
{
   register MTYPE r = (MTYPE) 0;
   register MTYPE *p = (MTYPE *) ptr;
   register size_t i = len / sizeof(MTYPE);
   register unsigned int idx = 0;

#define UNROLL 32

   while( i >= UNROLL )
   {
      _mm_prefetch( (char *) &p[idx + 8], _MM_HINT_NTA );

      r |= p[idx];
      r |= p[idx + 1];
      r |= p[idx + 2];
      r |= p[idx + 3];
      r |= p[idx + 4];
      r |= p[idx + 5];
      r |= p[idx + 6];
      r |= p[idx + 7];

      _mm_prefetch( (char *) &p[idx + 16], _MM_HINT_NTA );

      r |= p[idx + 8];
      r |= p[idx + 9];
      r |= p[idx + 10];
      r |= p[idx + 11];
      r |= p[idx + 12];
      r |= p[idx + 13];
      r |= p[idx + 14];
      r |= p[idx + 15];

      _mm_prefetch( (char *) &p[idx + 24], _MM_HINT_NTA );

      r |= p[idx + 16];
      r |= p[idx + 17];
      r |= p[idx + 18];
      r |= p[idx + 19];
      r |= p[idx + 20];
      r |= p[idx + 21];
      r |= p[idx + 22];
      r |= p[idx + 23];

      _mm_prefetch( (char *) &p[idx + 32], _MM_HINT_NTA );

      r |= p[idx + 24];
      r |= p[idx + 25];
      r |= p[idx + 26];
      r |= p[idx + 27];
      r |= p[idx + 28];
      r |= p[idx + 29];
      r |= p[idx + 30];
      r |= p[idx + 31];

      i -= UNROLL;
      idx += UNROLL;
   }

   // make sure compiler can't optimize
   static __volatile MTYPE always = r;

   MTYPE val = 0;

   for(int i = 0; i < sizeof(MTYPE); i++)
       val |= (MTYPE) v << (i*8);

   if( r == val )
       return true;
   else
       return false;
}

bool readmem2DPitch( void *ptr, unsigned char v, size_t pitch, int rows )
{
   register MTYPE r = (MTYPE) 0;
   register MTYPE *p;
   register size_t i;
   register unsigned int idx;

   for( int row = 0; row < rows; row++ )
   {
       p = (MTYPE *) ((unsigned char *) ptr + (size_t) row * pitch );
       idx = 0;
       i = pitch / sizeof( MTYPE );

#define UNROLL 32
       while( i >= UNROLL )
       {
          _mm_prefetch( (char *) &p[idx + UNROLL * sizeof(MTYPE)], _MM_HINT_NTA );

          r |= p[idx];
          r |= p[idx + 1];
          r |= p[idx + 2];
          r |= p[idx + 3];
          r |= p[idx + 4];
          r |= p[idx + 5];
          r |= p[idx + 6];
          r |= p[idx + 7];
          r |= p[idx + 8];
          r |= p[idx + 9];
          r |= p[idx + 10];
          r |= p[idx + 11];
          r |= p[idx + 12];
          r |= p[idx + 13];
          r |= p[idx + 14];
          r |= p[idx + 15];
          r |= p[idx + 16];
          r |= p[idx + 17];
          r |= p[idx + 18];
          r |= p[idx + 19];
          r |= p[idx + 20];
          r |= p[idx + 21];
          r |= p[idx + 22];
          r |= p[idx + 23];
          r |= p[idx + 24];
          r |= p[idx + 25];
          r |= p[idx + 26];
          r |= p[idx + 27];
          r |= p[idx + 28];
          r |= p[idx + 29];
          r |= p[idx + 30];
          r |= p[idx + 31];

          i -= UNROLL;
          idx += UNROLL;
       }
   }

   // make sure compiler can't optimize
   static __volatile MTYPE always = r;

   MTYPE val = 0;

   for(int i = 0; i < sizeof(MTYPE); i++)
       val |= (MTYPE) v << (i * 8);

   if( r == val )
       return true;
   else
       return false;
}

void writeMemCPU( void *ptr, unsigned char v, size_t len )
{
   register MTYPE r = 0;
   register MTYPE *p = (MTYPE *) ptr;
   register size_t i = len / sizeof(MTYPE);
   register size_t idx = 0;

   for(int i = 0; i < sizeof(MTYPE); i++)
       r |= (MTYPE) v << (i * 8);

   while( idx < (const size_t) ( len / sizeof(MTYPE) ) )
   {
      p[idx] = r;
      idx++;
   }
}

bool readVerifyMemSSE( void *ptr, unsigned char v, size_t len )
{
    register __m128i r1 = _mm_setzero_si128();
    register __m128i r2 = _mm_setzero_si128();
    register __m128i *p = (__m128i *) ptr;
    register unsigned int idx = 0;

    while(idx < (const size_t) (len / sizeof(__m128i)) ) 
    {
        if( idx < (const size_t) (len / sizeof(__m128i)) - 64 )
           _mm_prefetch( (char *) &p[idx + 64], _MM_HINT_NTA );

        r1 = _mm_load_si128( &p[idx] );
        r2 = _mm_or_si128( r1, r2 );

        idx++;
    }

    // make sure compiler can't optimize
    static __volatile __m128i always = r2;

    unsigned char res[16];
    _mm_storeu_si128( (__m128i *) res, r2 );

    bool ret = true;

    unsigned char val;
    val = v;

    for(int i = 0; i < sizeof( __m128i ); i++)
        if( res[i] != val ) {
            ret = false;
        }

    return ret;
}

void writeMemSSE ( void *ptr, unsigned char val, size_t len )
{
    register const __m128i r1 = _mm_set1_epi8( val );
    register __m128i *p = (__m128i *) ptr;
    register size_t idx = 0;

    while( idx < (const size_t) (len / sizeof(__m128i)) )
    { 
        _mm_store_si128( &p[idx], r1 );
        idx++;
    }
}

void memset2DPitch( void *ptr, unsigned char val, size_t columns, size_t rows, size_t pitch )
{
    for( size_t r = 0; r < rows; r++ )
        memset( ( unsigned char * ) ptr + r * pitch, val, columns );
}

void stridePagesCPU( void *ptr, size_t stride, size_t nbytes )
{
    register unsigned int *p = ( unsigned int * ) ptr;
    register size_t i;

    CPerfCounter t;
    double kTime;

    t.Reset();
    t.Start();

    for(i = 0; i < nbytes/sizeof(unsigned int); i += stride/sizeof(unsigned int))
        p[i] = 0;

    t.Stop();
    kTime = t.GetElapsedTime();

    std::cout << std::setw(21) << std::left << "Page fault" << std::setw(7) << (kTime*1e9) / ((double) nbytes/stride) << " ns" << std::endl;
}

#define TIMED_LOOP( STRING, EXPR, NBYTES ) \
{\
   t.Reset();\
   t.Start();\
\
   int nl = 20;\
   for( int i = 0; i < nl; i++ )\
      EXPR;\
\
   t.Stop();\
\
    std::cout << std::setw(21) << std::left << STRING << (((double) nl*(NBYTES)) / t.GetElapsedTime()) / 1e9 << " GB/s\n"; \
}

void assessHostMemPerf( void *ptr, void *ptr2, size_t nbytes )
{
    CPerfCounter t;

    std::cout << "Host baseline (naive):\n\n";

    double sum = 0.;
    int ctr = 0;

    for(int i = 0; i < 1e6; i++)
    {
        t.Reset();
        t.Start();
        t.Stop();

        double e = t.GetElapsedTime();

        if( e > 0. ) {
            sum += e;
             ctr++;
        }
    }

	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	std::cout << std::setw(21) << std::left << "Timer resolution" 
              << std::setw(7) << ( sum / (double) ctr ) * 1e9 << " ns\n";

#ifdef _WIN32
    //Sleep( 1000 );
#else
    usleep( 1000 * 1e3 );
#endif
    size_t pagesize;

#ifdef _WIN32
    SYSTEM_INFO system_info;

    GetSystemInfo (&system_info);
    pagesize = (size_t) system_info.dwPageSize;
#else
    pagesize = getpagesize();
#endif

    stridePagesCPU( ptr, pagesize, nbytes );

#ifdef MEM_MULTICORE
    benchBarrier();

    std::cout << "\n";

#endif

#if 0
    TIMED_LOOP( "SSE read", readVerifyMemSSE( ptr, 0, nbytes ), nbytes )
    TIMED_LOOP( "SSE write", writeMemSSE( ptr, 0, nbytes ), nbytes )
    TIMED_LOOP( "CPU write", writeMemCPU( ptr, 0, nbytes ), nbytes )
#endif

    TIMED_LOOP( "CPU read", readVerifyMemCPU_MT( ptr, 0, nbytes ), nbytes )

    TIMED_LOOP( "memcpy()", memcpy_MT( ptr, ptr2, nbytes ), nbytes )

    TIMED_LOOP( "memset(,1,)", memset_MT( ptr, 1, nbytes ), nbytes )
    TIMED_LOOP( "memset(,0,)", memset_MT( ptr, 0, nbytes ), nbytes )

    std::cout << "\n";
}
