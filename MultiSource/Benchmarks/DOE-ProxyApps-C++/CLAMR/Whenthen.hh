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

#ifndef WHENTHENHHINCLUDE
#define WHENTHENHHINCLUDE

// ***************************************************************************
// ***************************************************************************

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

class Whenthen
{

public:
    Whenthen();
    Whenthen(int &nwhen, Cmd &cmdi, bool &skipwhen, bool &single_line_when,
             bool eflag, stringstream &serr, int &ierr);
    void add_cmdf(Cmd &cmdi);
    void list_condition(string offset1, string offset2,
                        stringstream &ssc);
    void list_cmdsf_ss(stringstream &ssc);

    void check_wt(vector<string> &code_varnames,
                  vector<string> &code_values,
                  vector<int> &vv_active,
                  int *wtci, stringstream &serr, int &ierr);

    deque<Cmd> *get_cmdsf_ptr() { return &cmdsf; }

    void get_char_array_size(int *ca_size);
    void get_char_array(string &sc);

    void get_satsize(int *sat_size);
    void getsat(int *sat);
    void setsat(int *sat);
    void getprocessed(int *wtp);
    void setprocessed(int wtp);
    void getseq(int *wtseq);
    void setseq(int wtseq);
    int get_num_varnames() { return (int)varname.size(); }
    string get_varname(int i) { return varname[i].get_string(); }


private:

    void add_word(Cmd &cmdi, int idex, deque<Word> &wq);
    void add_word(Cmd &cmdi, int idex, deque<Word> &wq, string sadd);
    void process_words(deque <Word> &words, vector<string> &code_varnames,
                       vector<string> &code_values,
                       vector<int> &vv_active,
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

    // Commands to be done when the condition is satisfied.
    deque<Cmd> cmdsf;

    // The whenthen is only done once when the condition is satisfied.
    // This flag keeps it from being done again.
    bool processed;

    // This flag is used to distinguish between the when command and the
    // whenever command.
    bool ever_flag;

    // This is a sequence index to keep track of what order the whenthen's
    // have been processed in.
    int seqdex;
};


} // end of PP namespace

#endif

