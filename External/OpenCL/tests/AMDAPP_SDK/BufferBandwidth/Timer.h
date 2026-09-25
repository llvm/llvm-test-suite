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

#ifndef _TIMER_H_
#define _TIMER_H_
/**
 * \file Timer.h
 * \brief A timer class that provides a cross platform timer for use
 * in timing code progress with a high degree of accuracy.
 */
#ifdef _WIN32
/**
 * \typedef __int64 i64
 * \brief Maps the windows 64 bit integer to a uniform name
 */
#if defined(__MINGW64__) || defined(__MINGW32__)
typedef long long i64;
#else
typedef __int64 i64;
#endif
#else
/**
 * \typedef long long i64
 * \brief Maps the linux 64 bit integer to a uniform name
 */
typedef long long i64;
#endif

/**
 * \class CPerfCounter
 * \brief Counter that provides a fairly accurate timing mechanism for both
 * windows and linux. This timer is used extensively in all the samples.
 */
class CPerfCounter {

public:
    /**
     * \fn CPerfCounter()
     * \brief Constructor for CPerfCounter that initializes the class
     */
    CPerfCounter();
    /**
     * \fn ~CPerfCounter()
     * \brief Destructor for CPerfCounter that cleans up the class
     */
    ~CPerfCounter();
    /**
     * \fn void Start(void)
     * \brief Start the timer
     * \sa Stop(), Reset()
     */
    void Start(void);
    /**
     * \fn void Stop(void)
     * \brief Stop the timer
     * \sa Start(), Reset()
     */
    void Stop(void);
    /**
     * \fn void Reset(void)
     * \brief Reset the timer to 0
     * \sa Start(), Stop()
     */
    void Reset(void);
    /**
     * \fn double GetElapsedTime(void)
     * \return Amount of time that has accumulated between the \a Start()
     * and \a Stop() function calls
     */
    double GetElapsedTime(void);

private:

    i64 _freq;
    i64 _clocks;
    i64 _start;
};

#endif // _TIMER_H_

