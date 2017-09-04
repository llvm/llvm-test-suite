/* Copyright 2015.  Los Alamos National Security, LLC. This material was produced
 * under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
 * Laboratory (LANL), which is operated by Los Alamos National Security, LLC
 * for the U.S. Department of Energy. The U.S. Government has rights to use,
 * reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS
 * ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR
 * ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified
 * to produce derivative works, such modified software should be clearly marked,
 * so as not to confuse it with the version available from LANL.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 *
 * Under this license, it is required to include a reference to this work. We
 * request that each derivative work contain a reference to LANL Copyright
 * Disclosure C15076/LA-CC-15-054 so that this work's impact can be roughly
 * measured.
 *
 * This is LANL Copyright Disclosure C15076/LA-CC-15-054
 */

/*
 *  PowerParser is a general purpose input file parser for software applications.
 *
 *  Authors: Chuck Wingate   XCP-2   caw@lanl.gov
 *           Robert Robey    XCP-2   brobey@lanl.gov
 */

#ifndef FUNCTIONHHINCLUDE
#define FUNCTIONHHINCLUDE

// ***************************************************************************
// ***************************************************************************
// This class holds information about a function. It is mostly for use with
// the parser.
// ***************************************************************************
// ***************************************************************************

#include <string>
#include <sstream>
#include <vector>
#include <deque>

namespace PP
{
using std::string;
using std::deque;
using std::stringstream;
using std::vector;

enum FuncType {FUNC_};

//class ErrorState;

class Function
{

public:
    Function();
    Function(string nme, bool ext, int na, string ftype,  string fdes);

    // Evaluate the function.
    double evaluate(vector<double> &vd, stringstream &serr, int &ierr,
                    int line_number, int file_line_number,
                    string filename, deque<string> *lines);

    string evaluate(vector<string> &vs, stringstream &serr, int &ierr,
                    int line_number, int file_line_number,
                    string filename, deque<string> *lines);

    // Accessor methods.
    string get_name()        { return name; }
    int    get_num_args()    { return nargs; }
    string get_description() { return description; }
    string get_type()        { return type; }

private:

    void name_err(stringstream &serr, int &ierr,
                  int line_number, int file_line_number,
                  string filename, deque<string> *lines);

    void args_mismatch_err(int nargs_found, int nargs_expected,
                           stringstream &serr, int &ierr,
                           int line_number, int file_line_number,
                           string filename, deque<string> *lines);

    // The name of the function.
    string name;

    // Whether the function is external or internal. External functions
    // are C++ functions like sin(), log(), ... Internal functions
    // are defined within the input to the parser (this feature is not
    // implemented yet).
    bool external;

    // The number of arguments for the function.
    int nargs;

    // A text description of the function.
    string description;

    // The type of function. Allowed types are:
    //     real    double arguments, double result (cos, sin, log, ...)
    //     string  string arguments, string results (strlen, strcat, ...)
    string type;
};


} // End of the PP namespace

#endif
