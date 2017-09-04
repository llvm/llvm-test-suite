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

#ifndef PARSERMATHHHINCLUDE
#define PARSERMATHHHINCLUDE

// ***************************************************************************
// ***************************************************************************
// This class collects various parser math functions.
// There are two reasons to have this class:
// 1. To keep the command processing class from getting too big.
// 2. Some of these functions are used in more than one class.
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


class Parser_math
{

public:
    Parser_math();

    void do_op(int i1, int i2, int i3, deque <Word> &wq, Word &wres,
               stringstream &serr, int &ierr);
    void do_op_relational(int i1, int i2, int i3, deque <Word> &wq,
                          Word &wres, stringstream &serr, int &ierr);
    void do_op_logical(int i1, int i2, int i3, deque <Word> &wq,
                       Word &wres, stringstream &serr, int &ierr);
    void do_op_not(int i2, int i3, deque <Word> &wq,
                   Word &wres, stringstream &serr, int &ierr);


private:

};


} // End of the PP namespace

#endif
