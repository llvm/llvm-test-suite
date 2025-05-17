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

#ifndef _LOG_H_
#define _LOG_H_

extern int nBytes;

class Sample {

public:

    Sample() : _isMsg(false), _isErr(false), _timer(0.), _msg(0), _loops(1) {}
    ~Sample() {}

    void   setMsg( const char *, const char * );
    void   setErr( void ) { _isErr = true; }
    bool   isMsg( void ) { return _isMsg; }
    bool   isErr( void ) { return _isErr; }
    void   setTimer( const char *, double, unsigned int, int );
    double getTimer( void ) { return _timer; }
    void   printSample ( int firstColumnWidth=0 );

private:

    bool          _isMsg;
    bool          _isErr;
    double        _timer;
    unsigned int  _nbytes;
    int           _loops;
    char *        _fmt;
    char *        _msg;
};

class TestLog {

public:

    TestLog( int );
    ~TestLog() {}

    void loopMarker( void );
    void Msg( const char *, const char * );
    void Error( const char *, const char * );
    void Timer( const char *, double, unsigned int, int );

    void printLog( void );
    void printSummary( int );

private:

    int _logIdx;
    int _logLoops;
    int _logLoopEntries;
    int _logLoopTimers;
	int _maxMsgWidth;
 
    Sample *_samples;
};

#endif // _LOG_H_
