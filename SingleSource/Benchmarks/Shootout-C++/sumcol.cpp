// -*- mode: c++ -*-
// $Id$
// http://www.bagley.org/~doug/shootout/
// with help from Waldek Hebisch

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAXLINELEN 128

int main(int argc, char * * argv) {
    char line[MAXLINELEN];
    int sum = 0;
    char buff[4096];
    cin.rdbuf()->pubsetbuf(buff, 4096); // enable buffering

    while (cin.getline(line, MAXLINELEN)) {
        sum += atoi(line);
    }
    cout << sum << '\n';
}
