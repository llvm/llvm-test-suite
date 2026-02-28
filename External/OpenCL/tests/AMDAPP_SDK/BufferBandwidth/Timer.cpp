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

#include "Timer.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <time.h>
#endif

CPerfCounter::CPerfCounter() : _clocks(0), _start(0)
{

#ifdef _WIN32
    QueryPerformanceFrequency((LARGE_INTEGER *)&_freq);
#else
    _freq = 1000;
#endif

}

CPerfCounter::~CPerfCounter()
{
    // EMPTY!
}

void
CPerfCounter::Start(void)
{

#ifdef _WIN32
    QueryPerformanceCounter((LARGE_INTEGER *)&_start);
#else
    struct timespec s;
    clock_gettime( CLOCK_REALTIME, &s );
    _start = (i64)s.tv_sec * 1e9 + (i64)s.tv_nsec;
#endif

}

void
CPerfCounter::Stop(void)
{
    i64 n;

#ifdef _WIN32
    QueryPerformanceCounter((LARGE_INTEGER *)&n);
#else
    struct timespec s;
    clock_gettime( CLOCK_REALTIME, &s );
    n = (i64)s.tv_sec * 1e9 + (i64)s.tv_nsec;
#endif

    n -= _start;
    _start = 0;
    _clocks += n;
}

void
CPerfCounter::Reset(void)
{

    _clocks = 0;
}

double
CPerfCounter::GetElapsedTime(void)
{
#if _WIN32
    return (double)_clocks / (double) _freq;
#else
    return (double)_clocks / (double) 1e9;
#endif

}

