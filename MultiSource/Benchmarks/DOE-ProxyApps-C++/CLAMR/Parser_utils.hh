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

#ifndef PARSERUTILSHHINCLUDE
#define PARSERUTILSHHINCLUDE

// ***************************************************************************
// ***************************************************************************
// This class collects various low level utilities for the parser.
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


class Parser_utils
{

public:
    Parser_utils(int base);

    int start_dex(vector<int> &istart, const vector<int> &size);
    void reverse_dex(int icdex, int nvals, vector<int> &istart,
                     const vector<int> &size);

    void print_strings(vector< vector<string> > rows, int n_header_rows,
                       int offset, int col_spacing, int line_len_max,
                       stringstream &ss);

private:

};


} // End of the PP namespace

#endif
