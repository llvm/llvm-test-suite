// -*- mode: c++ -*-
// $Id$
// http://www.bagley.org/~doug/shootout/
// with help from PeterB

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    int i, n = ((argc == 2) ? atoi(argv[1]) : 1);
    string str;
    size_t capacity = 31;
    str.reserve(capacity); // as per C-string
    size_t newLength = 6;
    for (i = 0; i < n; i++)
    {
	if(newLength > capacity)
	{
	    capacity *= 2;
	    str.reserve(capacity);
	}
	str += "hello\n";
	newLength += 6;
    }
    cout << str.length() << endl;
    return 0;
}
