// -*- mode: c++ -*-
// $Id$
// http://www.bagley.org/~doug/shootout/
// with help from Allan Stokes

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    typedef deque<string> LINES;
    LINES l;
    char line[256];
    char buff[4096];
    cin.rdbuf()->pubsetbuf(buff, 4096); // enable buffering
    cout.rdbuf()->pubsetbuf(buff, 4096); // enable buffering

    while (cin.getline(line, 256)) {
        l.push_front(line);
    }
    copy (l.begin(), l.end(), ostream_iterator<string>(cout,"\n"));
}
