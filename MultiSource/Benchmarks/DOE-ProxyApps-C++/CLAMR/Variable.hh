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

#ifndef VARIABLEHHINCLUDE
#define VARIABLEHHINCLUDE

// ***************************************************************************
// ***************************************************************************
// This class holds information about a variable.
// ***************************************************************************
// ***************************************************************************

#include <string>
#include <sstream>
#include <vector>
#include <deque>

namespace PP
{
using std::string;
using std::stringstream;
using std::vector;
using std::deque;



class Variable
{

public:
    Variable();
    Variable(int base);
    Variable(string nme, string v, bool pred, string tdes);
    Variable(string nme);
    Variable(string nme, vector<int> &istart, vector<string> &vvec,
             int lnum, int file_lnum, string fname, deque<string> *lines,
             stringstream &serr, int &ierr);

    // Accessor methods.
    string get_varname() { return name; }
    void set_varname(string s) { name = s; }
    int get_ndim() { return ndim; }

    int get_nvalues() { return (int)value.size(); }

    string get_var_value()   { return value[0]; }
    string get_var_value(int idex)   { return value[idex]; }
    string get_var_value(vector<int> &adex, string vname, int lnum,
                         int file_lnum, string fname, deque<string> *lines,
                         stringstream &serr, int &ierr);


    void set_var_value(vector<int> &istart, vector<string> &valvec,
                       int lnum, int file_lnum, string fname,
                       deque<string> *lines, stringstream &serr, int &ierr);
    void bump_var(vector<int> &istart, int increment,
                  int lnum, int file_lnum, string fname,
                  deque<string> *lines, stringstream &serr, int &ierr);


    void set_bounds(vector<int> &bounds, int lnum, int file_lnum,
                    string fname, deque<string> *lines,
                    stringstream &serr, int &ierr);

    void get_indices(int icdex, vector<int> &adex);

    string get_description() { return description; }
    void set_description(string vardes) { description = vardes; }

    bool is_pre_defined() { return pre_defined; }

    void set_temporary(bool b) { temporary = b; }
    bool is_temporary() { return temporary; }

private:

    // name         The name of the variable.
    // value        Vector containing the values of the variable.
    // ndim         Number of dimensions, for example var(9,3) has ndim=2
    // maxdim       Max num for each dimension except the last.
    // lnum_ndim    The line number where ndim was set.
    // lnum_bounds  The line number where maxdim was set.
    // pre_defined  Pre-defined vars cannot be redefined.
    // description  Text description of the variable.
    // temporary    A temporary variable.
    string name;
    vector<string> value;
    int ndim, lnum_bounds, lnum_ndim;
    vector<int> maxdim;
    bool pre_defined, temporary;
    string description;
};


} // End of the PP namespace

#endif
