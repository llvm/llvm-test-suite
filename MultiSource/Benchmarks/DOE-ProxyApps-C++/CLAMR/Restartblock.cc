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
// Restart Blocks
// Run the code until a restart block condition is satisfied. Set the restart
// block as active, write a restart dump, stop the code, and restart.
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
#include "Restartblock.hh"

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
Restartblock::Restartblock() 
{
    active = -1;
}

// ===========================================================================
// Usual constructor.
//    restart_block name (time .eq. 50) then
// ===========================================================================
Restartblock::Restartblock(int &nrb, Cmd &cmdi, bool &skiprb,
                           bool &single_line_rb,
                           deque<string> &bnames_on_dump,
                           deque<bool> &baflags_on_dump,
                           deque<int> &rbsatprb_on_dump,
                           deque<bool> &rbsat_on_dump,
                           stringstream &serr, int &ierr)
{
    //cout << "&&&&&cw ********** Restartblock.cc, Enter Constructor **********" << endl;
    active = -1;
    nrb += 1;
    skiprb = true;
    single_line_rb = false;
    int nwords = cmdi.get_nwords();

    // &&&&&cw
    //stringstream ssprint;
    //cmdi.print_using_words(ssprint);
    //cout << ssprint.str() << endl;

    if (nwords < 8) {
        cmdi.fatal_error(0, serr, ierr);
        serr << "A restart block line must have at least 8 words on it (the "
             << endl
             << "opening and closing parentheses each count as a word)"
             << endl;
        serr << "This restart block command only has " << nwords <<
            " words on it." << endl;
        serr << "Expected something like (this has 8 words):" << endl;
        serr << "    restart_block after5 (time .gt. 5) then" << endl;
        serr << "Or perhaps a single line restart block like (this has 13 words):"
             << endl;
        serr << "    restart_block after5 (time .gt. 5) sizemat(2) = 0.005" << endl;
        ierr = 2;
        return;
    }

    string p2 = cmdi.get_string(2);
    if (p2 != "(") {
        cmdi.fatal_error(2, serr, ierr);
        serr << "Expected an open parentheses following the restart block name.."
             << endl;
        serr << "Instead found " << p2 << " following the restart block name."
             << endl;
        serr << "The restart block command should be something like:" << endl;
        serr << "    restart_block t_is_gt_5 (time .gt. 5) then" << endl;
        serr << "Or perhaps a single line restart block like:" << endl;
        serr << "    restart_block t_is_gt_5 (time .gt. 5) sizemat(2) = 0.005" << endl;
        ierr = 2;
        return;
    }


    for (int i=1; i<nwords-1; i++) {
        string t1 = cmdi.get_string(i);
        if (t1 == "then") {
            cmdi.fatal_error(i, serr, ierr);
            serr << "Found a then keyword embedded in the restart_block command."
                 << endl;
            serr << "If a then keyword is present it must be the last "
                 "word on the line." << endl;
            serr << "The restart_block command should be something like:" << endl;
            serr << "    restart_block t_is_gt_5 (time .gt. 5) then" << endl;
            serr << "Or perhaps a single line restart block like:" << endl;
            serr << "    restart_block t_is_gt_5 (time .gt. 5) sizemat(2) = 0.005" << endl;
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
        serr << "The restart_block command should be something like:" << endl;
        serr << "    restart_block t_is_gt_5 (time .gt. 5) then" << endl;
        serr << "Or perhaps a single line restart block like:" << endl;
        serr << "    restart_block t_is_gt_5 (time .gt. 5) sizemat(2) = 0.005" << endl;
        ierr = 2;
        return;
    }


    int nw = close_paren_dex - 3;
    if ((nw+1)%4 != 0) {
        cmdi.fatal_error(0, serr, ierr);
        serr << "Wrong number of words in the restart_block condition."
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

    


    for (int i=3; i<close_paren_dex; i+=4) {
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
            serr << "Invalid restart_block relation." << endl;
            serr << "Expected  .lt., .le., .eq., .ne., .gt., .ge." << endl;
            serr << "Also could be .hglt., .hgle., .hgeq., .hgne., .hggt., .hgge." << endl;
            serr << "Instead found relation:  " << relation[n].get_string() << endl;
            ierr = 2;
            return;
        }
    }

    // The name of the restart block is the second word on the
    // restart_block command.
    name = cmdi.get_string(1);
    //cout << "&&&&&cw Restartblock.cc, name1 = " << name << endl;
    //cout << "&&&&&cw Restartblock.cc, satsize = " << satisfied.size() << endl;

    // If this is a restart, then restart block names and active flags
    // could be stored on the restart dump. If this restart block matches
    // any stored on the dump, then set the active flag to what is on
    // the dump.
    for (int i=0; i<(int)bnames_on_dump.size(); i++) {
        //cout << "&&&&&cw Restartblock.cc, name = " << name << endl;
        //cout << "&&&&&cw Restartblock.cc, bnames_on_dump = " << 
        //    bnames_on_dump[i] << endl;
        //cout << "&&&&&cw Restartblock.cc, baflags_on_dump = " << 
        //    baflags_on_dump[i] << endl;
        if (name == bnames_on_dump[i]) {
            active = 0;
            if (baflags_on_dump[i]) active = 1;

            int satdex = 0;
            for (int j=0; j<i; j++) {
                satdex += rbsatprb_on_dump[j];
            }
            for (int j=satdex; j<satdex+rbsatprb_on_dump[i]; j++) {
                string s = "false";
                if (rbsat_on_dump[j]) s = "true";
                satisfied[j-satdex] = s;
            }

            break;
        }
    }
    //cout << "&&&&&cw Restartblock.cc, after set restart" << endl;


    // If this restart block is active, that means we want to process
    // the commands in the block, therefore we set the skip flag to false.
    if (active == 1) skiprb = false;


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


    // Handle single line restart_block
    if (cmdi.get_string(nwords-1) != "then") {
        single_line_rb = true;
        cmdi.delete_words(0, 5);
        cmdi.reset_name_type();
    }
    //cout << "&&&&&cw ********** Restartblock.cc, Exit Constructor **********" << endl;
}


// ===========================================================================
// Add word to the deque wq.
// ===========================================================================
void Restartblock::add_word(Cmd &cmdi, int idex, deque<Word> &wq)
{
    int ln = cmdi.get_line_number(idex);
    int file_ln = cmdi.get_file_line_number(idex);
    string fname = cmdi.get_filename(idex);
    deque<string> *lines = cmdi.get_lines();
    Word w(cmdi.get_string(idex), ln, file_ln, fname, lines);
    wq.push_back(w);
}

void Restartblock::add_word(Cmd &cmdi, int idex, deque<Word> &wq, string sadd)
{
    int ln = cmdi.get_line_number(idex);
    int file_ln = cmdi.get_file_line_number(idex);
    string fname = cmdi.get_filename(idex);
    deque<string> *lines = cmdi.get_lines();
    Word w(sadd, ln, file_ln, fname, lines);
    wq.push_back(w);
}


// ===========================================================================
// This is the check for when the condition is satisfied.
// ===========================================================================
void Restartblock::check_rb(vector<string> &code_varnames,
                            vector<string> &code_values,
                            vector<int> &vv_active, int *rbci,
                            stringstream &serr, int &ierr)
{
    *rbci = 0;
    //if (active==1) return;

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

    // rbci is an output flag telling the code to write a dump and end
    // the calculation or not. rbci=0 means do not end the calc,
    // rbci=1 tells the code to end the calc.
    // Basically, if the condition changes from its previous value, then
    // set rbci to 1.

    // This is the current value of the condition that was calculated above.
    bool b = wordsf[0].get_bool(serr, ierr);

    // *rcbi is the key output result from this function
    //     *rbci = 0    Calling code does nothing
    //     *rbci = 1    Calling code stops calculation, normally does restart
    *rbci = 0;

    // Here we check to see if the condition has changed, i.e. is b different
    // from the active flag. If so, then we end the calculation.
    // When the restart block is first created, the active flag is set to -1,
    // this is for runs from scratch.
    // If this is a restart, then the active flag will come from the dump and
    // be either 0 or 1.
    // So if active is -1 and the condition is true, then we end the calculation
    // right away (this should not be common, but could happen).
    //
    // Changed on 7/2/10 - The original idea for restart blocks was that they
    // would trigger when the condition changed from false to true. But they
    // would also trigger when the condition changed back from true to false.
    // This causes problems for the users when the restart block would
    // repeatedly trigger because the condition oscillates between true and
    // false. Therefore, change the restart blocks so they trigger once and
    // only once (which happens when the condition first becomes true). If
    // the users ever need a restart block that also triggers when the
    // condition changes from true to false, then some
    // sort of option could be put in to allow this.
    if (b  && active == -1) { *rbci = 1; active = 1; return; }   // Trigger
    if (b  && active ==  0) { *rbci = 1; active = 1; return; }   // Trigger
    if (b  && active ==  1) { *rbci = 0;             return; }   // Do nothing
    if (!b && active == -1) { *rbci = 0; active = 0; return; }   // Do nothing
    if (!b && active ==  0) { *rbci = 0;             return; }   // Do nothing

    // This is the true to false trigger that causes problems.
    //if (!b && active ==  1) { *rbci = 1; active = 0; return; }   // Trigger
}



// ===========================================================================
// Given a deque of words, go through them evaluating relational and logical
// operators. The words should evaluate to one final word.
// ===========================================================================
void Restartblock::process_words(deque <Word> &words, vector<string> &code_varnames,
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
        serr << "restart_block condition did not evaluate to a single boolean value."
             << endl;
        serr << "Fix the restart_block condition" << endl;
        ierr = 2;
    }
}


// ===========================================================================
// List the condition for this restart block to a stringstream.
// This is done to let the user indentify this restart block. It is
// also useful for debugging.
// ===========================================================================
void Restartblock::list_condition(string offset1, string offset2,
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
void Restartblock::delete_words(int i1, int i2, deque <Word> &words)
{
    deque<Word>::iterator p = words.begin();
    words.erase(p + i1, p + i2 + 1);
}


// ===========================================================================
// Replace words i1 through i2 inclusive with word w.
// ===========================================================================
void Restartblock::replace_words(int i1, int i2, deque <Word> &words, Word &w)
{
    delete_words(i1, i2, words);
    deque<Word>::iterator p = words.begin();
    words.insert(p + i1, w);
}



} // End of the PP namespace



