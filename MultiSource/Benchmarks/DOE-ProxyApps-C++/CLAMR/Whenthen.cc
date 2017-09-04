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

// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <map>
#include <math.h>

#include "Variable.hh"
#include "Function.hh"
#include "Word.hh"
#include "Parser_math.hh"
#include "Cmd.hh"
#include "Whenthen.hh"

namespace PP
{
using std::cout;
using std::endl;
using std::string;
using std::deque;
using std::vector;
using std::stringstream;
using std::pair;
using std::ifstream;
using std::ios;


// ===========================================================================
// Default constructor.
// ===========================================================================
Whenthen::Whenthen() 
{
    processed = false;
    seqdex = -1;
    ever_flag = false;
}


// ===========================================================================
// Usual constructor.
// ===========================================================================
Whenthen::Whenthen(int &nwhen, Cmd &cmdi, bool &skipwhen,
                   bool &single_line_when, bool eflag,
                   stringstream &serr, int &ierr)
{
    processed = false;
    seqdex = -1;
    ever_flag = eflag;
    nwhen += 1;
    skipwhen = true;
    single_line_when = false;
    int nwords = cmdi.get_nwords();

    // &&&&&cw
    //stringstream ssprint;
    //cmdi.print_using_words(ssprint);
    //cout << ssprint.str() << endl;

    if (nwords < 7) {
        cmdi.fatal_error(0, serr, ierr);
        serr << "A when command line must have at least 7 words on it (the "
             << endl
             << "opening and closing parenthses each count as a word)"
             << endl;
        serr << "This when command only has " << nwords << " words on it." << endl;
        serr << "Expected something like (this has 7 words):" << endl;
        serr << "    when (time .gt. 5) then" << endl;
        serr << "Or perhaps a single line when like (this has 9 words):" << endl;
        serr << "    when (time .gt. 5) shortmodcyc = 5" << endl;
        ierr = 2;
        return;
    }

    string p1 = cmdi.get_string(1);
    if (p1 != "(") {
        cmdi.fatal_error(1, serr, ierr);
        serr << "Expected an open parentheses following the when keyword."
             << endl;
        serr << "Instead found " << p1 << " following the when keyword."
             << endl;
        serr << "The when command should be something like:" << endl;
        serr << "    when (time .gt. 5) then" << endl;
        serr << "Or perhaps a single line when like:" << endl;
        serr << "    when (time .gt. 5) shortmodcyc = 5" << endl;
        ierr = 2;
        return;
    }


    for (int i=1; i<nwords-1; i++) {
        string t1 = cmdi.get_string(i);
        if (t1 == "then") {
            cmdi.fatal_error(i, serr, ierr);
            serr << "Found a then keyword embedded in the when command."
                 << endl;
            serr << "If a then keyword is present it must be the last "
                 "word on the line." << endl;
            serr << "The when command should be something like:" << endl;
            serr << "    when (time .gt. 5) then" << endl;
            serr << "Or perhaps a single line when like:" << endl;
            serr << "    when (time .gt. 5) shortmodcyc = 5" << endl;
            ierr = 2;
            return;
        }
    }


    // Find the closing parenthesis
    int close_paren_dex = -1;
    for (int i=2; i<nwords; i++) {
        string pi = cmdi.get_string(i);
        if (pi == "then") break;
        if (pi == ")") {
            close_paren_dex = i;
            break;
        }
    }

    if (close_paren_dex == -1) {
        cmdi.fatal_error(0, serr, ierr);
        serr << "Expected a close parentheses following the condition."
             << endl;
        serr << "Did not find a close parentheses." << endl;
        serr << "The when command should be something like:" << endl;
        serr << "    when (time .gt. 5) then" << endl;
        serr << "Or perhaps a single line when like:" << endl;
        serr << "    when (time .gt. 5) shortmodcyc = 5" << endl;
        ierr = 2;
        return;
    }


    int nw = close_paren_dex - 2;
    if ((nw+1)%4 != 0) {
        cmdi.fatal_error(0, serr, ierr);
        serr << "Wrong number of words in the when...then condition."
             << endl;
        serr << "The number of words in this condition is " << nw << endl;
        serr << "The number of words + 1 should be a multiple of 4." << endl;
        serr << "The condition should be something like:" << endl;
        serr << "    time .gt. 5" << endl;
        serr << "This has 3 words and 3+1 is a multiple of 4." << endl;
        serr << "Or the following is valid" << endl;
        serr << "    time .gt. 5 .and. ncycle .ge. 10" << endl;
        serr << "This has 7 words and 7+1 is a multiple of 4." << endl;
        ierr = 2;
        return;
    }

    


    for (int i=2; i<close_paren_dex; i+=4) {
        add_word(cmdi, i,   varname);
        add_word(cmdi, i+1, relation);
        add_word(cmdi, i+2, value);

        if (i+3 < close_paren_dex) add_word(cmdi, i+3, logop);
        else                       add_word(cmdi, i+3, logop, "none");

        satisfied.push_back("false");
    }


    // Check to make sure that the relation is valid.
    for (int n=0; n<(int)varname.size(); n++) {
        bool valid_relation = false;
        if (relation[n].get_string() == ".hglt.") valid_relation = true;
        if (relation[n].get_string() == ".hgle.") valid_relation = true;
        if (relation[n].get_string() == ".hgeq.") valid_relation = true;
        if (relation[n].get_string() == ".hgne.") valid_relation = true;
        if (relation[n].get_string() == ".hggt.") valid_relation = true;
        if (relation[n].get_string() == ".hgge.") valid_relation = true;
        if (relation[n].get_string() == ".lt.") valid_relation = true;
        if (relation[n].get_string() == ".le.") valid_relation = true;
        if (relation[n].get_string() == ".eq.") valid_relation = true;
        if (relation[n].get_string() == ".ne.") valid_relation = true;
        if (relation[n].get_string() == ".gt.") valid_relation = true;
        if (relation[n].get_string() == ".ge.") valid_relation = true;

        if (!valid_relation) {
            relation[n].fatal_error(serr, ierr);
            serr << "Invalid when...then relation." << endl;
            serr << "Expected  .lt., .le., .eq., .ne., .gt., .ge." << endl;
            serr << "Also could be .hglt., .hgle., .hgeq., .hgne., .hggt., .hgge." << endl;
            serr << "Instead found relation:  " << relation[n].get_string() << endl;
            ierr = 2;
            return;
        }
    }


    // Set the has gotten to flags.
    for (int n=0; n<(int)varname.size(); n++) {
        bool hg = false;

        if (relation[n].get_string() == ".hglt.") {
            hg = true;
            relation[n].set_value(".lt.");
        }
        else if (relation[n].get_string() == ".hgle.") {
            hg = true;
            relation[n].set_value(".le.");
        }
        else if (relation[n].get_string() == ".hgeq.") {
            hg = true;
            relation[n].set_value(".eq.");
        }
        else if (relation[n].get_string() == ".hgne.") {
            hg = true;
            relation[n].set_value(".ne.");
        }
        else if (relation[n].get_string() == ".hggt.") {
            hg = true;
            relation[n].set_value(".gt.");
        }
        else if (relation[n].get_string() == ".hgge.") {
            hg = true;
            relation[n].set_value(".ge.");
        }


        has_got.push_back(hg);
    }


    // Handle single line when...then
    if (cmdi.get_string(nwords-1) != "then") {
        single_line_when = true;
        cmdi.delete_words(0, 5);
        cmdi.reset_name_type();
        skipwhen = false;
    }
}


// ===========================================================================
// Add word.
// ===========================================================================
void Whenthen::add_word(Cmd &cmdi, int idex, deque<Word> &wq)
{
    int ln = cmdi.get_line_number(idex);
    int file_ln = cmdi.get_file_line_number(idex);
    string fname = cmdi.get_filename(idex);
    deque<string> *lines = cmdi.get_lines();
    Word w(cmdi.get_string(idex), ln, file_ln, fname, lines);
    wq.push_back(w);
}

void Whenthen::add_word(Cmd &cmdi, int idex, deque<Word> &wq, string sadd)
{
    int ln = cmdi.get_line_number(idex);
    int file_ln = cmdi.get_file_line_number(idex);
    string fname = cmdi.get_filename(idex);
    deque<string> *lines = cmdi.get_lines();
    Word w(sadd, ln, file_ln, fname, lines);
    wq.push_back(w);
}



// ===========================================================================
// Add a command to the deque of commands for this whenthen.
// ===========================================================================
void Whenthen::add_cmdf(Cmd &cmdi)
{
    cmdsf.push_back(cmdi);
}


// ===========================================================================
// This is the check for when the condition is satisfied.
// ===========================================================================
void Whenthen::check_wt(vector<string> &code_varnames,
                        vector<string> &code_values,
                        vector<int> &vv_active,
                        int *wtci, stringstream &serr, int &ierr)
{
    *wtci = 0;
    if (processed) return;

    Parser_math pmath;

    deque<Word> wordsf;

    bool skip_sat = false;
    int num_sub_cond = (int)varname.size();
    for (int n=0; n<num_sub_cond; n++) {
        deque<Word> words;

        if (satisfied[n] == "true") {
            int ln = varname[n].get_line_number();
            int file_ln = varname[n].get_file_line_number();
            string fname = varname[n].get_filename();
            deque<string> *lines = varname[n].get_lines();
            Word w("true", ln, file_ln, fname, lines);
            words.push_back(w);
        }
        else {
            words.push_back(varname[n]);
            words.push_back(relation[n]);
            words.push_back(value[n]);

            process_words(words, code_varnames, code_values, vv_active,
                          serr, ierr);

            if (has_got[n]) {
                if (words[0].get_bool(serr, ierr)) {
                    bool doit = true;
                    if (n > 0) {
                        if (logop[n-1].get_string() == ".andthen." && skip_sat) {
                            doit = false;
                        }
                    }
                    if (doit) satisfied[n] = "true";
                }
                else {
                    skip_sat = true;
                }
            }
        }

        wordsf.push_back(words[0]);
        if (logop[n].get_string() == "none") break;
        else wordsf.push_back(logop[n]);
    }

    process_words(wordsf, code_varnames, code_values, vv_active,
                  serr, ierr);

    // The output value, wtci, defaults to false (0). If the condition
    // is satisfied then the output is true (1). 
    if (wordsf[0].get_bool(serr, ierr)) {
        *wtci = 1;
        if (!ever_flag) processed = true;
        return;
    }
}



// ===========================================================================
// Given a deque of words, go through them evaluating relational and logical
// operators. The words should evaluate to one final word.
// ===========================================================================
void Whenthen::process_words(deque <Word> &words, vector<string> &code_varnames,
                             vector<string> &code_values,
                             vector<int> &vv_active,
                             stringstream &serr, int &ierr)
{
    Parser_math pmath;

    // Replace any code vars with their values.
    int i2 = (int)words.size();
    for (int i=0; i<i2; i++) {
        for (int j=0; j<(int)code_varnames.size(); j++) {
            if (words[i].get_string() == code_varnames[j]) {
                int ln = words[i].get_line_number();
                int file_ln = words[i].get_file_line_number();
                string fname = words[i].get_filename();
                deque<string> *lines = words[i].get_lines();
                if (vv_active[j] == 0) {
                    Word wj("false", ln, file_ln, fname, lines);
                    replace_words(i, i+2, words, wj);
                    i2 -= 2;
                    break;
                }
                else {
                    Word wj(code_values[j], ln, file_ln, fname, lines);
                    words[i] = wj;
                }
            }
        }
    }

    int i1 = 0;
    i2 = (int)words.size() - 1;
    for (int level=6; level>=0; level--) {
        for (int i=i1; i<=i2; i+=1) {
            if (words[i].is_operator(level)) {
                int ln = words[i].get_line_number();
                int file_ln = words[i].get_file_line_number();
                string fname = words[i].get_filename();
                deque<string> *lines = words[i].get_lines();
                Word w("", ln, file_ln, fname, lines);

                string op_type = words[i].get_op_type();

                if (op_type == "relational") {
                    pmath.do_op_relational(i-1, i, i+1, words, w, serr, ierr);
                }

                if (op_type == "logical" && level == 2)   // .not. is unary
                    pmath.do_op_not(i, i+1, words, w, serr, ierr);

                if (op_type == "logical" && level != 2)
                    pmath.do_op_logical(i-1, i, i+1, words, w, serr, ierr);

                // level 2, .not., is unary and is handled differently.
                if (level == 2) {
                    replace_words(i, i+1, words, w);
                    i2 -= 1;
                }
                else {
                    replace_words(i-1, i+1, words, w);
                    i2 -= 2;
                    i -= 1;
                }
                continue;
            }
        }
    }

    // The condition has to evaluate to a single boolean value.
    if ((int)words.size() != 1) {
        words[0].fatal_error(serr, ierr);
        serr << "When...then condition did not evaluate to a single boolean value."
             << endl;
        serr << "Fix the when...then condition" << endl;
        ierr = 2;
    }
}


// ===========================================================================
// ===========================================================================
void Whenthen::get_char_array_size(int *ca_size)
{
    string sc;
    get_char_array(sc);
    (*ca_size) = (int)sc.size();
}


// ===========================================================================
// ===========================================================================
void Whenthen::get_char_array(string &sc)
{
    for (int n=0; n<(int)varname.size(); n++) {
        sc += varname[n].get_string();
        sc += relation[n].get_string();
        sc += value[n].get_string();
        sc += logop[n].get_string();
        if (has_got[n]) sc += "hasgot";
    }
    for (int n=0; n<(int)cmdsf.size(); n++) {
        int nw = cmdsf[n].get_nwords();
        for (int i=0; i<nw; i++) {
            sc += cmdsf[n].get_string(i);
        }
    }
}


// ===========================================================================
// ===========================================================================
void Whenthen::get_satsize(int *sat_size)
{
    (*sat_size) = (int)satisfied.size();
}


// ===========================================================================
// Get and Set the satisfied flags.
// ===========================================================================
void Whenthen::getsat(int *sat)
{
    for (int i=0; i<(int)satisfied.size(); i++) {
        if (satisfied[i] == "true")  sat[i] = 1;
        if (satisfied[i] == "false") sat[i] = 0;
    }
}

void Whenthen::setsat(int *sat)
{
    for (int i=0; i<(int)satisfied.size(); i++) {
        if (sat[i] == 1) satisfied[i] = "true";
        if (sat[i] == 0) satisfied[i] = "false";
    }
}


// ===========================================================================
// Get and Set the processed flag for a whenthen.
// ===========================================================================
void Whenthen::getprocessed(int *wtp)
{
    *wtp = 0;
    if (processed) *wtp = 1;
}

void Whenthen::setprocessed(int wtp)
{
    processed = false;
    if (wtp == 1) processed = true;
}


// ===========================================================================
// Get and Set the sequence index.
// ===========================================================================
void Whenthen::getseq(int *wtseq)
{
    *wtseq = seqdex;
}

void Whenthen::setseq(int wtseq)
{
    seqdex = wtseq;
}




// ===========================================================================
// List the final commands deque for this whenthen to a stringstream.
// This is done to let the user know what the final commands are. It is
// also useful for debugging.
// ===========================================================================
void Whenthen::list_cmdsf_ss(stringstream &ssc)
{
    for (int i=0; i<(int)cmdsf.size(); i++) {
        ssc << "        ";
        cmdsf[i].print_using_words_fm(ssc);
        ssc << endl;
    }
}


// ===========================================================================
// List the condition for this whenthen to a stringstream.
// This is done to let the user indentify this whenthen. It is
// also useful for debugging.
// ===========================================================================
void Whenthen::list_condition(string offset1, string offset2,
                              stringstream &ssc)
{
    for (int n=0; n<(int)varname.size(); n++) {

        string relstr = relation[n].get_string();
        string rstr = relstr;
        if (has_got[n]) {
            if (relstr == ".lt.") rstr = ".hglt.";
            if (relstr == ".le.") rstr = ".hgle.";
            if (relstr == ".eq.") rstr = ".hgeq.";
            if (relstr == ".ne.") rstr = ".hgne.";
            if (relstr == ".gt.") rstr = ".hggt.";
            if (relstr == ".ge.") rstr = ".hgge.";
        }
        relstr = rstr;

        string offset = offset1;
        if (n > 0) offset = offset2;

        ssc << offset << varname[n].get_string() << " "
            << relstr << " " << value[n].get_string();

        if (logop[n].get_string() == "none") break;
        ssc << " " << logop[n].get_string();
        ssc << endl;
    }
}


// ===========================================================================
// Delete words i1 through i2 inclusive from the deque.
// ===========================================================================
void Whenthen::delete_words(int i1, int i2, deque <Word> &words)
{
    deque<Word>::iterator p = words.begin();
    words.erase(p + i1, p + i2 + 1);
}


// ===========================================================================
// Replace words i1 through i2 inclusive with word w.
// ===========================================================================
void Whenthen::replace_words(int i1, int i2, deque <Word> &words, Word &w)
{
    delete_words(i1, i2, words);
    deque<Word>::iterator p = words.begin();
    words.insert(p + i1, w);
}





} // End of the PP namespace

