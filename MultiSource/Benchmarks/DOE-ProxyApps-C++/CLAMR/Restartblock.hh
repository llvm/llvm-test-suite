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

#ifndef RESTARTBLOCKHHINCLUDE
#define RESTARTBLOCKHHINCLUDE

// ***************************************************************************
// ***************************************************************************
// Restart Blocks
// Run the code until a restart block condition is satisfied. Set the restart
// block as active, write a restart dump, stop the code, and restart.
// ***************************************************************************
// ***************************************************************************

#include <string>
#include <deque>
#include <vector>
#include <map>
#include <sstream>

#include "Word.hh"

namespace PP
{
using std::string;
using std::deque;
using std::vector;
using std::map;
using std::stringstream;

class Restartblock
{

public:
    Restartblock();
    Restartblock(int &nrb, Cmd &cmdi, bool &skiprb,
                 bool &single_line_rb,
                 deque<string> &bnames_on_dump,
                 deque<bool> &baflags_on_dump,
                 stringstream &serr, int &ierr);

    Restartblock(int &nrb, Cmd &cmdi, bool &skiprb,
                 bool &single_line_rb,
                 deque<string> &bnames_on_dump,
                 deque<bool> &baflags_on_dump,
                 deque<int> &rbsatprb_on_dump,
                 deque<bool> &rbsat_on_dump,
                 stringstream &serr, int &ierr);


    void check_rb(vector<string> &code_varnames,
                  vector<string> &code_values,
                  vector<int> &vv_active, int *rbci,
                  stringstream &serr, int &ierr);

    void list_condition(string offset1, string offset2,
                        stringstream &ssc);

    string get_name() { return name; }
    int get_aflag() { return active; }
    void set_aflag(int af) { active = af; }
    int get_satsize() { return (int)satisfied.size(); }
    int get_sat(int j) { if (satisfied[j] == "true") return 1; return 0; }
    int get_num_varnames() { return (int)varname.size(); }
    string get_varname(int i) { return varname[i].get_string(); }


private:

    void add_word(Cmd &cmdi, int idex, deque<Word> &wq);
    void add_word(Cmd &cmdi, int idex, deque<Word> &wq, string sadd);
    void process_words(deque <Word> &words, vector<string> &code_varnames,
                       vector<string> &code_values, vector<int> &vv_active,
                       stringstream &serr, int &ierr);
    void delete_words(int i1, int i2, deque <Word> &words);
    void replace_words(int i1, int i2, deque <Word> &words, Word &w);


    // The condition:   varname relation value  logical  varname relation value etc.
    // Example:           time     .gt.   3.0    .and.    ncycle   .ge.    50
    // The condition is thought of as a sequence of subconditions connected by
    // logical operators. The above example has two subconditions connected by the
    // .and. logical operator.
    deque<Word>   varname;    // Host code variable name to be replaced by host code value.
    deque<Word>   relation;   // Relation between varname and value, like .gt., .hglt., ...
    deque<Word>   value;      // Value to compare with host code value.
    deque<Word>   logop;      // Logical operator connecting subconditions.
    deque<string> satisfied;  // Satisfied flag for each subcondition.
    deque<bool>   has_got;    // Has got flag for the relation. This is true if
                              // the relation is .hggt., .hglt., ..., false otherwise.

    // The restart_block commands are processed if active is true (== 1)
    int active;

    // The name of this restart block.
    string name;
};


} // end of PP namespace

#endif

