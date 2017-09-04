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
// This class holds command lines broken up into words.
// The term command is used in a general sense, it includes variable
// assignments, do loops, usual commands, etc.
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
#include <algorithm>
#include <math.h>
#include <assert.h>

#include "Parser_utils.hh"
#include "Variable.hh"
#include "Function.hh"
#include "Word.hh"
#include "Parser_math.hh"
#include "Cmd.hh"

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
using std::setw;

// index base, generally 1 for Fortran style and 0 for C/C++, default 1
static int index_base = 1;
static bool case_sensitive = false;

// ===========================================================================
// Default constructor.
// ===========================================================================
Cmd::Cmd() 
{
    init();
}


// ===========================================================================
// Constructor including map of variables.
// ===========================================================================
Cmd::Cmd(string s, map<string, Variable> *v, map<string, Function> *f,
         deque<string> *lstr, int lnum, int file_lnum, string fname,
         stringstream &serr, int &ierr)
{
    init();
    vmap = v;
    fmap = f;
    original_str = s;
    line_number = lnum;
    file_line_number = file_lnum;
    filename = fname;
    lines = lstr;
    process_string(s, serr, ierr);
}


// ===========================================================================
// Add a word to this cmd.
// ===========================================================================
void Cmd::add_word(string str, int lnum, int file_lnum, string fname)
{
    Word w(str, lnum, file_lnum, fname, lines);
    words.push_back(w);
}


// ===========================================================================
// Erase a word from this cmd.
// ===========================================================================
void Cmd::erase_word(int iw)
{
    words.erase(words.begin()+iw);
}
void Cmd::erase_last_word()
{
    words.erase(words.begin()+(int)words.size()-1);
}


// ===========================================================================
// Remove words that are commas.
// ===========================================================================
void Cmd::remove_commas()
{
    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].is_comma()) {
            words.erase(words.begin()+i);
            i -= 1;
        }
    }
}


// ===========================================================================
// Initialize various private data.
// ===========================================================================
void Cmd::init()
{
    original_str = "";
    //processed = false;
    white_space = " \t";
    delims = " \t()[],*/+-=!#";
    vmap = NULL;
    fmap = NULL;
    line_number = 0;
    file_line_number = 0;
    filename = "";
}


// ===========================================================================
// Set index base for input file indexing. 1 -- Fortran like, 0 -- Other
//   languages
// ===========================================================================
void Cmd::set_index_base(int base)
{
    //cout << "Info:: Setting index base to " << base << endl;
    index_base = base;
}

// ===========================================================================
// Set case sensitivity for input file commands.
// ===========================================================================
void Cmd::set_case_sensitive(bool case_sensitive_in)
{
    case_sensitive = case_sensitive_in;
}

// ===========================================================================
// Process a string.
// Break the string into words and copy each word to a double ended queue.
// ===========================================================================
void Cmd::process_string(string in_str, stringstream &serr, int &ierr)
{
    //cout << "&&&&& Original line = " << endl;
    //cout << in_str << endl;
    //cout << "01234567890123456789012345678901234567890123456789" << endl;
    //cout << "0         1         2         3         4         " << endl;

    string s;
    int istart = 0;
    bool found = false;
    //int plevel = 0;
    for (;;) {
        delims = " \t()[],*/+-=!#";

        // Extract the next word from the line.
        found = extract_next_word(istart, in_str, s, serr, ierr);
        if (!found) break;

        // Create a new word using the word that was found.
        // This removes quotes if there are any and types the word.
        Word w(s, line_number, file_line_number, filename, lines);

        // Copy the word to the end of the queue.
        words.push_back(w);
    }

    // Set the command name and type.
    reset_name_type();
}


// ===========================================================================
// Given a string, str, and a starting position in
// that string, istart, extract the next word and
// pass it back as a string.
// ===========================================================================
bool Cmd::extract_next_word(int &istart, string &str, string &word,
                            stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    //assert(serr == serr);
    assert(ierr == ierr);

    // If istart is out of bounds then there is nothing to do.
    if (istart < 0) return false;
    if (istart >= (int)str.size()) return false;

    // Find the next non blank character.
    int i1 = str.find_first_not_of(white_space, istart);

    // If a non whitespace character was not found then there are no more
    // words to extract.
    if (i1 == (int)string::npos) return false;

    // If the non blank character that was found is a delimiter, like
    // ()[]+-/* ... then it needs to be a word by itself.
    if (delims.find(str[i1], 0) != string::npos) {
        word = str[i1];
        istart = i1+1;
        return true;
    }

    // At this point we have found the start of a word. The end of the
    // word will be one of the delimiters like ()[]+=-*/spacetab ...
    string wend = delims;

    // A word delimited by quotes is handled differently. If the i1
    // position in the string is a beginning quotes then we need to search
    // for an ending quotes. Anything between quotes is part of the word
    // including delimters.
    bool quotes = false;
    if (str[i1] == '"') {
        quotes = true;
        wend = "\"";
    }
    if (str[i1] == '\'') {
        quotes = true;
        wend = "\'";
    }

    // Search for the end of the word by finding the next delimiter. The
    // delimiter is one index past the end of the word.
    // But if the next delimiter is + or - then we have to consider that
    // this could be a floating point number in which case we continue
    // past the + or - to find the next delimiter.
    int i2;
    int i1_start = i1+1;
    for(;;) {
        i2 = str.find_first_of(wend, i1_start);

        // If a delimiter was not found then the word extends to the end
        // of the line.
        if (i2 == (int)string::npos) {
            i2 = str.size();
            break;
        }
        else {
            // Check for a floating point number (fpn). For example
            //       1.34e+14  or -3.8E-19
            // i2 might point to the + or - in e+14 or E-19, so we check
            // for that case. Note that if the + or - is not found, then it
            // could be a number like 1.e14 but then i2 would point to
            // something after e14 and we would be ok.
            // If we do find +e or -e, then everything in front of it needs
            // to be a digit, if not then this is not a number.
            bool fpn = false;
            if (str[i2] == '+' || str[i2] == '-') {
                if (str[i2-1] == 'e' || str[i2-1] == 'E' ||
                    str[i2-1] == 'd' || str[i2-1] == 'D') {
                    fpn = true;
                    for (int j=i1; j<=i2-2; j++) {
                        if (!isdigit(str[j]) && str[j] != '.') {
                            fpn = false;
                            break;
                        }
                    }
                }
            }

            if (!fpn) break;
            i1_start = i2+1;
        }
    }

    // If the word is quoted then it should end in quotes.
    // We do not check for quotes matching here because at this
    // point we might be in a comment region where quotes mismatch
    // is allowed. We check for quotes mismatch later.
    if (quotes) {
        if (i2 >= (int)str.size()) i2 = (int)str.size() - 1;
    }
    /*
    if (quotes) {
        bool missing = false;
        if (i2 >= (int)str.size()) missing = true;
        else if (str[i1] == '\"' && str[i2] != '\"') missing = true;
        else if (str[i1] == '\'' && str[i2] != '\'') missing = true;
        else if (str[i1] == '\"' && str[i2] == '\'') missing = true;
        else if (str[i1] == '\'' && str[i2] == '\"') missing = true;
        if (missing) {
            fatal_error2(serr, ierr);
            serr << "Quotes mismatch found." << endl;
            serr << "A starting quotes must have a closing quotes." << endl;
            serr << "Double quotes, \", must be matched with double quotes." << endl;
            serr << "Single quotes, \', must be matched with single quotes." << endl;
            ierr = 2;
            return false;
        }
    }
    */

    // We include the quotes symbols in the word. The quote symbols will
    // be removed elsewhere.
    if (quotes) i2 += 1;

    // The word is now delimited by i1 and i2-1, return it in word.
    word = str.substr(i1, i2 - i1);

    // Update the starting point for finding the next word.
    istart = i2;

    // A word was successfully found so return true.
    return true;
}


// ===========================================================================
// Reset the command name and type. Consider the following command:
//      * lasdkj */ cmd = 5.0
// The original command name is "*", but after the multi-line comment is
// removed, the command name should be "cmd".
// ===========================================================================
void Cmd::reset_name_type()
{
    if ((int)words.size() == 0) {
        cmd_name = " ";
        cmd_type = " ";
        return;
    }
    cmd_name = words[0].get_string();
    if (! case_sensitive) {
       transform(cmd_name.begin(), cmd_name.end(), cmd_name.begin(), tolower);
    }
    cmd_type = "command";
    if (words[0].is_variable()) cmd_type = "assignment";
    if (cmd_name == "parser_list_variables") cmd_type = "debug";
    if (cmd_name == "parser_list_functions") cmd_type = "debug";
    if (cmd_name == "parser_print_fbuffer")  cmd_type = "debug";
    if (cmd_name == "if")      cmd_type = "internal_cmd";
    if (cmd_name == "elseif")  cmd_type = "internal_cmd";
    if (cmd_name == "endif")   cmd_type = "internal_cmd";
    if (cmd_name == "do")      cmd_type = "internal_cmd";
    if (cmd_name == "return")  cmd_type = "internal_cmd";
    if (cmd_name == "enddo")   cmd_type = "internal_cmd";
    if (cmd_name == "stop")    cmd_type = "internal_cmd";
    if (cmd_name == "when")    cmd_type = "internal_cmd";
    if (cmd_name == "endwhen") cmd_type = "internal_cmd";
}


// ===========================================================================
// Given a line like
//    include filename1 filename2 filename3 ...
// Find the first filename that exists and return that.
// This should only be called on the io processor.
// ===========================================================================
string Cmd::get_cmd_filename(stringstream &ssfiles)
{
    for (int i=1; i<(int)words.size(); i++) {
        string fn = words[i].get_string();

        // The quotes may still be on the word, strip them off if they are
        // present.
        int len = (int)fn.size();
        if ((fn[len-1] == '\"') || (fn[len-1] == '\'')) {
            fn.erase(fn.end() - 1);
        }
        if ((fn[0] == '\"') || (fn[0] == '\'')) {
            fn.erase(fn.begin());
        }

        ssfiles << "    " << fn << endl;

        // Open the file to test if it exists.
        ifstream instm(fn.c_str(), ios::in);
        instm.close();
        if( instm.fail() ) continue;
        return fn;
    }
    return "";
}


// ===========================================================================
// Handle unary minus in a command line (not in math(..))
// ===========================================================================
void Cmd::handle_cmd_unary_minus(stringstream &serr, int &ierr)
{
    int ipstart = 0;
    for (;;) {
        int ip = find(ipstart, (int)words.size()-1, "-");

        // If we do not find any more minus signs then we are done.
        if (ip == -1) return;

        // The word after the minus sign must be a number.
        if (!words[ip+1].is_number()) {
            words[ip+1].fatal_error(serr, ierr);
            serr << "Expected the object following the unary - to"
                " be a number." << endl;
            serr << "Instead, it was " << words[ip+1].get_string() << endl;
            ierr = 2;
            return;
        }

        // Actually do the negate operation.
        do_unary_op(ip, "-");
        ipstart = ip+1;
        continue;
    }
}
         

// ===========================================================================
// Handle unary plus in a command line (not in math(..))
// ===========================================================================
void Cmd::handle_cmd_unary_plus(stringstream &serr, int &ierr)
{
    int ipstart = 0;
    for (;;) {
        int ip = find(ipstart, (int)words.size()-1, "+");

        // If we do not find any more minus signs then we are done.
        if (ip == -1) return;

        // The word after the plus sign must be a number.
        if (!words[ip+1].is_number()) {
            words[ip+1].fatal_error(serr, ierr);
            serr << "Expected the object following the unary + to"
                " be a number." << endl;
            serr << "Instead, it was " << words[ip+1].get_string() << endl;
            ierr = 2;
            return;
        }

        // The + sign is not needed.
        delete_words(ip, ip);
        ipstart = ip+1;
        continue;
    }
}
         

// ===========================================================================
// The following type of command is allowed:
//      a(1) = 15*3.0
// meaning that 3.0 is to be replicated 15 times and thus a(1)-a(15) is set
// by this command.
// ===========================================================================
void Cmd::handle_cmd_multiplicity(stringstream &serr, int &ierr)
{
    int ipstart = 0;
    for (;;) {
        int ip = find(ipstart, (int)words.size()-1, "*");

        // If we do not find any more asterisks then we are done.
        if (ip == -1) return;

        if (ip==0) {
            fatal_error2(serr, ierr);
            serr << "Asterisk cannot be at the start of a line." << endl;
            ierr = 2;
            return;
        }

        if (ip == (int)words.size()-1) {
            words[ip].fatal_error(serr, ierr);
            serr << "Asterisk cannot be at the end of a line." << endl;
            ierr = 2;
            return;
        }

        // The word after the asterisk must be a number or a boolean.
        // Wait, why is this? We actually allow strings also, really
        // we allow anything.
        //if (!words[ip+1].is_number() && !words[ip+1].is_bool()) {
        //    words[ip+1].fatal_error(serr, ierr);
        //    serr << "Expected the object following the * to"
        //        " be a number or a logical." << endl;
        //    serr << "Instead, it was " << words[ip+1].get_string() << endl;
        //    ierr = 2;
        //    return;
        //}

        // The word before the asterisk must be a number.
        if (!words[ip-1].is_number()) {
            words[ip-1].fatal_error(serr, ierr);
            serr << "Expected the object before the * to"
                " be a number." << endl;
            serr << "Instead, it was " << words[ip-1].get_string() << endl;
            ierr = 2;
            return;
        }

        // Set the multiplicity.
        int imult = words[ip-1].get_int(serr, ierr);
        words[ip+1].set_multiplicity(imult);
        Word w = words[ip+1];
        replace_words(ip-1, ip+1, w);
        ipstart = ip;
    }
}
         


// ***************************************************************************
// ***************************************************************************
// Functions for getting values from the commands.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Get boolean values. This gets all the words past the = sign,
// converts them to bool (and then to int), and puts them in the output arrays.
//
// The expected commands are:
//    cmdname = .true.                    0d
//    cmdname(5) = false true false       1d
//    cmdname(5,9) = true false true      2d
//    etc.
//
// We also allow
//    cmdname = false true false
// and we will supply the starting indices of (1) or (1,1), etc.
//
// But note that the , is gone at this point, so the 2d command is
//    cmdname ( 5 9 ) = true false true      2d
//
// This function works for any dimension, 0,1,2,3,...
//
// We pass the result back as an int because of the incompatibility between
// fortran logical and c++ bool.
// ===========================================================================
void Cmd::get_bool_int(string &cname, int *array_vals, const vector<int> &size,
                       vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                       int dup_fatal, vector<int> &dup_vals,
                       bool skip, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, for example an equals sign must be present, and set istart.
    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // If skipping, we don't need to get array values.
    if (skip) {
        set_processed(true);
        return;
    }

    // Get the number of values past the = sign.
    // Also mark the words up to and including the = sign as processed.
    int nvals = 0;
    if (!get_nvals(istart, size, nvals, serr, ierr)) return;

    // 0d is a special case.
    if (dim == 0) {
        bool b = words[2].get_bool(serr, ierr);
        int cvalue = 0;
        if (b) cvalue = 1;
        *array_vals = cvalue;
        return;
    }

    // Get the values and return.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;
    Parser_utils putils(index_base);
    int k = putils.start_dex(istart, size);
    for (int i=ieqp1; i<(int)words.size(); i++) {
        bool b = words[i].get_bool(serr, ierr);
        int cvalue = 0;
        if (b) cvalue = 1;
        int imult = words[i].get_multiplicity();
        for (int j=1; j<=imult; j++) {
            error_dup_line(cname, i, k, dup_wdex1, dup_cmd1, dup_vals, 
                           size, dup_fatal, serr, ierr);
            array_vals[k++] = cvalue;
        }
    }
}

// ===========================================================================
// Get boolean values. This gets all the words past the = sign,
// converts them to bool and puts them in the output arrays.
//
// The expected commands are:
//    cmdname = .true.                    0d
//    cmdname(5) = false true false       1d
//    cmdname(5,9) = true false true      2d
//    etc.
//
// We also allow
//    cmdname = false true false
// and we will supply the starting indices of (1) or (1,1), etc.
//
// But note that the , is gone at this point, so the 2d command is
//    cmdname ( 5 9 ) = true false true      2d
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
void Cmd::get_bool(string &cname, bool *array_vals, const vector<int> &size,
                   vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                   int dup_fatal, vector<int> &dup_vals,
                   bool skip, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, for example an equals sign must be present, and set istart.
    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // If skipping, we don't need to get array values.
    if (skip) {
        set_processed(true);
        return;
    }

    // Get the number of values past the = sign.
    // Also mark the words up to and including the = sign as processed.
    int nvals = 0;
    if (!get_nvals(istart, size, nvals, serr, ierr)) return;

    // 0d is a special case.
    if (dim == 0) {
        bool b = words[2].get_bool(serr, ierr);
        *array_vals = b;
        return;
    }

    // Get the values and return.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;
    Parser_utils putils(index_base);
    int k = putils.start_dex(istart, size);
    for (int i=ieqp1; i<(int)words.size(); i++) {
        bool b = words[i].get_bool(serr, ierr);
        int imult = words[i].get_multiplicity();
        for (int j=1; j<=imult; j++) {
            error_dup_line(cname, i, k, dup_wdex1, dup_cmd1, dup_vals, 
                           size, dup_fatal, serr, ierr);
            array_vals[k++] = b;
        }
    }
}


// ===========================================================================
// Get integer values. This gets all the words past the = sign,
// converts them to int, and puts them in the output arrays.
//
// The expected commands are:
//    cmdname = some_int                  0d
//    cmdname(5) = 3, 5, -15, 10          1d
//    cmdname(5,9) = 3, 7, -20, 154       2d
//    etc.
//
// We also allow
//    cmdname = 3, 5, -15, 10
// and we will supply the starting indices of (1) or (1,1), etc.
//
// But note that the , is gone at this point, so the 2d command is
//    cmdname ( 5 9 ) = 3  7  -20  154 ...
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
void Cmd::get_int(string &cname, int *array_vals, const vector<int> &size,
                  vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                  int dup_fatal, vector<int> &dup_vals,
                  bool skip, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, for example an equals sign must be present, and set istart.
    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // If skipping, we don't need to get array values.
    if (skip) {
        set_processed(true);
        return;
    }

    // Get the number of values past the = sign.
    // Also mark the words up to and including the = sign as processed.
    int nvals = 0;
    if (!get_nvals(istart, size, nvals, serr, ierr)) return;

    // 0d is a special case.
    if (dim == 0) {
        *array_vals = words[2].get_int(serr, ierr);
        return;
    }

    // Get the values and return.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;
    Parser_utils putils(index_base);
    int k = putils.start_dex(istart, size);
    for (int i=ieqp1; i<(int)words.size(); i++) {
        int iw = words[i].get_int(serr, ierr);
        int imult = words[i].get_multiplicity();
        for (int j=1; j<=imult; j++) {
            error_dup_line(cname, i, k, dup_wdex1, dup_cmd1, dup_vals, 
                           size, dup_fatal, serr, ierr);
            array_vals[k++] = iw;
        }
    }
}


// ===========================================================================
// Get int64_t values. This gets all the words past the = sign,
// converts them to int, and puts them in the output arrays.
//
// The expected commands are:
//    cmdname = some_int                  0d
//    cmdname(5) = 3, 5, -15, 10          1d
//    cmdname(5,9) = 3, 7, -20, 154       2d
//    etc.
//
// We also allow
//    cmdname = 3, 5, -15, 10
// and we will supply the starting indices of (1) or (1,1), etc.
//
// But note that the , is gone at this point, so the 2d command is
//    cmdname ( 5 9 ) = 3  7  -20  154 ...
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
void Cmd::get_int(string &cname, int64_t *array_vals, const vector<int> &size,
                  vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                  int dup_fatal, vector<int> &dup_vals,
                  bool skip, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, for example an equals sign must be present, and set istart.
    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // If skipping, we don't need to get array values.
    if (skip) {
        set_processed(true);
        return;
    }

    // Get the number of values past the = sign.
    // Also mark the words up to and including the = sign as processed.
    int nvals = 0;
    if (!get_nvals(istart, size, nvals, serr, ierr)) return;

    // 0d is a special case.
    if (dim == 0) {
        *array_vals = words[2].get_int64_t(serr, ierr);
        return;
    }

    // Get the values and return.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;
    Parser_utils putils(index_base);
    int k = putils.start_dex(istart, size);
    for (int i=ieqp1; i<(int)words.size(); i++) {
        int64_t iw = words[i].get_int64_t(serr, ierr);
        int imult = words[i].get_multiplicity();
        for (int j=1; j<=imult; j++) {
            error_dup_line(cname, i, k, dup_wdex1, dup_cmd1, dup_vals, 
                           size, dup_fatal, serr, ierr);
            array_vals[k++] = iw;
        }
    }
}

// ===========================================================================
// Get the real (double) values. This gets all the words past the = sign,
// converts them to doubles, and puts them in the output arrays.
//
// The expected commands are:
//    cmdname = some_double                         0d
//    cmdname(5) = 3.0, 35, -15e20, 10.154          1d
//    cmdname(5,9) = 3.0, 35, -15e20, 10.154        2d
//    etc.
//
// We also allow
//    cmdname = 3.0, 35, -15e20, 10.154
// and we will supply the starting indices of (1) or (1,1), etc.
//
// But note that the , is gone at this point, so the 2d command is
//    cmdname ( 5 9 ) = 3.0  35  -15e20  10.154  ...
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
void Cmd::get_real(string &cname, double *array_vals, const vector<int> &size,
                   vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                   int dup_fatal, vector<int> &dup_vals,
                   bool skip, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, for example an equals sign must be present, and set istart.
    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // If skipping, we don't need to get array values.
    if (skip) {
        set_processed(true);
        return;
    }

    // Get the number of values past the = sign.
    // Also mark the words up to and including the = sign as processed.
    int nvals = 0;
    if (!get_nvals(istart, size, nvals, serr, ierr)) return;

    // 0d is a special case.
    // Note that we do not increment dup_vals for 0d because duplicate scalar
    // commands are handled differently from array commands.
    if (dim == 0) {
        *array_vals = words[2].get_double(serr, ierr);
        return;
    }

    // All other dimensions.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;
    Parser_utils putils(index_base);
    int k = putils.start_dex(istart, size);
    for (int i=ieqp1; i<(int)words.size(); i++) {
        double d = words[i].get_double(serr, ierr);
        int imult = words[i].get_multiplicity();
        for (int j=1; j<=imult; j++) {
            error_dup_line(cname, i, k, dup_wdex1, dup_cmd1, dup_vals, 
                           size, dup_fatal, serr, ierr);
            array_vals[k++] = d;
        }
    }
}


// ===========================================================================
// Get the character values. This gets all the words past the = sign,
// converts them to chars, and puts them in the output arrays.
//
// The expected commands are:
//    cmdname = q                                   0d single character
//    cmdname = char_string                         0d character string
//    cmdname(3) = "May" "the", "force", "be"       1d array of strings
//    cmdname(5,9) = "11" "21" "31"                 2d
//    etc.
//
// We also allow
//    cmdname = "May" "the", "force", "be"
// and we will supply the starting indices of (1) or (1,1), etc.
//
// But note that the , is gone at this point, so the 2d command is
//    cmdname ( 5 9 ) = "11" "21" "31"
//
// This function works for any dimension, 0,1,2,3,...
// For 0d, it has an extra flag to distinguish between single characters
// and a character string.
// ===========================================================================
void Cmd::get_char(string &cname, vector<string> &vstr, const vector<int> &size,
                   bool single_char, vector<Cmd *> &dup_cmd1,
                   vector<int> &dup_wdex1, int dup_fatal,
                   vector<int> &dup_vals, bool skip,
                   stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, for example an equals sign must be present, and set istart.
    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // If skipping, we don't need to get array values.
    if (skip) {
        set_processed(true);
        return;
    }

    // Get the number of values past the = sign.
    // Also mark the words up to and including the = sign as processed.
    int nvals = 0;
    if (!get_nvals(istart, size, nvals, serr, ierr)) return;

    // 0d is a special case - get a single char
    if (dim == 0 && single_char) {
        vstr[0] = words[2].get_single_char(serr, ierr);
        return;
    }

    // 0d is a special case - get a single string
    if (dim == 0) {
        vstr[0] = words[2].get_stringp();
        return;
    }

    // Get the value and return, dim > 0.
    // get_stringp is the same as get_string except get_stringp also marks
    // the word as being processed.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;
    Parser_utils putils(index_base);
    int k = putils.start_dex(istart, size);
    for (int i=ieqp1; i<(int)words.size(); i++) {
        string s = words[i].get_stringp();
        int imult = words[i].get_multiplicity();
        for (int j=1; j<=imult; j++) {
            error_dup_line(cname, i, k, dup_wdex1, dup_cmd1, dup_vals, 
                           size, dup_fatal, serr, ierr);
            vstr[k++] = s;
        }
    }

}


// ===========================================================================
// Get sizes of arrays, this works for dimensions 1,2,3,...
//
// The size vector contains the sizes (or bounds) of each array dimensions.
// It is assumed in this routine that all but the last size is known (this
// is input) and that this routine will determine the last size. See the
// get_sizeb function below where a different assumption is made.
//
// Suppose, for example, we have a 3d array called a3d which is dimensioned
// a3d(5,3,:). The first two dimensions are known, 5 and 3, the last dimension
// is unknown and will be determined by this routine.
//
// size is a vector of ints of size 3, with elements 5,3,? where the ? is
// to be determined.
//
// Note that this routine is called in a loop over all the lines in the
// input which is why we set the size using maximum.
// ===========================================================================
void Cmd::get_size(vector<int> &size, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // Check syntax, also sets istart.
    // istart   Position in array where we start filling it.
    //          Example command might be a3d(3,2,2) = ...  In this case istart
    //          would be a vector of length 3 contining 3,2,2
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // Get the number of values past the = sign.
    int nvals = 0;
    vector<int> size0(dim,0);
    if (!get_nvals(istart, size0, nvals, serr, ierr)) return;

    int sm = 1;
    for (int i=0; i<dim-1; i++) {
        sm *= size[i];
    }

    // Set the size.
    int maxval = istart[dim-1] + (nvals-1)/sm;
    if (maxval > size[dim-1]) {
        size[dim-1] = maxval;
    }
}


// ===========================================================================
// This is a special purpose routine to get sizes for certain 2d arrays.
//
// Suppose we have the following input
//      mults(1,1) = 0. 0.  1. 5.  6. 9.
//      mults(1,2) = 3. 5.  8. 9.  10. 11. 20. 10
//      mults(1,3) = 30. 5. 38. 3.
// In this case we don't know the size of either of the array dimensions, and
// of course the user does not know the size either and thus cannot somehow
// merge the above two lines. 
//
// The purpose of this function is to obtain sizes for both the array
// dimensions so memory allocation of the array can be done.
//
// The size vector contains the sizes (or bounds) of each array dimensions.
// For the above example, this function would determine size[0] to be 8 and
// size[1] to be 3. 8 is just the max of the number of values put in per
// entry and 3 is just the max of the second index.
//
// Note that this routine is called in a loop over all the lines in the
// input which is why we set the size using maximum.
//
// This routine only works for 2d arrays.
// ===========================================================================
void Cmd::get_sizeb(vector<int> &size, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)size.size();

    // This is a special purpose routine, dim must be 2.
    if (dim != 2) {
        fatal_error2(serr, ierr);
        serr << "Cmd.cc, get_sizeb, internal error." << endl;
        serr << "dim != 2, dim=" << dim << endl << endl;
        ierr = 2;
        return;
    }

    // Check syntax, also sets istart.
    // istart   Position in array where we start filling it.
    //          Example command might be a3d(3,2,2) = ...  In this case istart
    //          would be a vector of length 3 contining 3,2,2
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    vector<int> istart(dim,0);
    if (!check_syntax(istart, serr, ierr)) return;

    // Get the number of values past the = sign.
    int nvals = 0;
    vector<int> size0(dim,0);
    if (!get_nvals(istart, size0, nvals, serr, ierr)) return;

    // Set the size vector
    int maxval = istart[0] + nvals - 1;
    if (maxval > size[0]) {
        size[0] = maxval;
    }

    maxval = istart[1];
    if (maxval > size[1]) {
        size[1] = maxval;
    }
}


// ===========================================================================
// Check command syntax for any dimension array. The expected command is:
//    cmdname = .true.                          0d
//    cmdname(5) = 1, 3, -4                     1d
//    cmdname(3,4) = 1.e19, 23., -45.           2d
//    etc.
//
// We also allow
//    cmdname = "May" "the", "force", "be"
// and we will supply the starting indices of (1) or (1,1), etc.
//
// Note that at this point, the commas have been removed so the 2d command
// is actually
//    cmdname ( 3 4 ) = 1.e19 23. -45. 
// ===========================================================================
bool Cmd::check_syntax(vector<int> &istart, stringstream &serr, int &ierr)
{
    // Get the dimension of the array, 0,1,2,3,...
    int dim = (int)istart.size();

    bool skip_check = false;
    if (dim > 0) {
        int ieqt = find_equals();
        if (ieqt == 1) skip_check = true;
    }

    // Must be at least a certain number of words on the line.
    int nw_min = 3;
    int nw_min_wc = 3;
    if (dim > 0 && (!skip_check)) {
        nw_min = 6 + dim - 1;
        nw_min_wc = nw_min + dim - 1;
    }
    if ((int)words.size() < nw_min) {
        fatal_error2(serr, ierr);
        serr << "Expected number words in this line >= " << nw_min_wc << endl;
        serr << "Actual number words = " << words.size() << endl << endl;
        ierr = 2;
        // If there aren't enough words on the line, then it is hopeless.
        return false;
    }


    // Word at index ieq must be an = sign.
    int ieq = 1;
    int ieq_wc = 2;
    if (dim > 0 && (!skip_check)) {
        ieq = 4 + dim -1;
        ieq_wc = ieq + 1 + dim - 1;
    }
    if (words[ieq].get_string() != "=") {
        words[ieq].fatal_error(serr, ierr);
        serr << "Expected an equals sign for symbol " << ieq_wc << endl;
        serr << "Instead symbol " << ieq_wc << " is: " <<
            words[ieq].get_string() << endl << endl;
        ierr = 2;
    }

    // The value must not have any multiplicity, i.e. be just a single value.
    // This only applies to 0d, values for arrays can have multiplicity.
    if (dim == 0) {
        if (words[2].get_multiplicity() != 1) {
            words[2].fatal_error(serr, ierr);
            serr << "Multiplicity not equal 1 for " << words[2].get_string() << endl;
            serr << "Multiplicity is: " << words[2].get_multiplicity() << endl << endl;
            ierr = 2;
        }
    }

    // Nothing more to check for 0d.
    if (dim == 0) return true;

    if (!skip_check) {
        // Word at index 1 must be a "(".
        if (words[1].get_string() != "(") {
            words[1].fatal_error(serr, ierr);
            serr << "Expected an open parenthesis ,(, following the command name"
                " in this line," << endl;
            serr << "For example: " << cmd_name << "(...) = ..." << endl;
            serr << "Instead found: " << words[1].get_string() << endl << endl;
            ierr = 2;
        }

        // There must be a closing parenthses.
        int irp = 3 + dim - 1;
        if (words[irp].get_string() != ")") {
            words[irp].fatal_error(serr, ierr);
            serr << "Expected a close parenthesis ,), following the array indices"
                " in this line," << endl;
            serr << "For example: " << cmd_name << "(...) = ..." << endl;
            serr << "Instead found: " << words[irp].get_string() << endl << endl;
            ierr = 2;
        }
    }


    // istart   Position in array_vals where we start filling it.
    //          Note that istart starts from index base (default 1, Fortran style)
    //          Use set_index_base_zero for C/C++ index convention
    if (skip_check) {
        for (int i=0; i<dim; i++) {
            istart[i] = index_base;
        }
    }
    else {
        int ierr2 = 0;
        for (int i=0; i<dim; i++) {
            int iloc = 2 + i;
            istart[i] = words[iloc].get_int(serr, ierr);
            if (ierr < 2  &&  istart[i] < index_base) {
                words[iloc].fatal_error(serr, ierr);
                serr << "The index for the array must be an integer that is >= " << index_base << endl;
                serr << "Integer includes numbers like 3, 3., 3.0, but not 3.5" << endl;
                serr << "The index input is: " << istart[i] << endl << endl;
                ierr2 = 2;
            }
        }
        if (ierr2 == 2) ierr = 2;
    }

    for (int i=0; i<dim; i++) {
        if (istart[i] < index_base) return false;
    }
    return true;
}


// ===========================================================================
// Get the number of values (nvals) past the = sign.
// Check that nvals does not exceed array size.
// Also mark the words up to and including the = sign as processed.
//
// Works for any array dimension = 0,1,2,3,...
// ===========================================================================
bool Cmd::get_nvals(vector<int> &istart, const vector<int> &size,
                    int &nvals, stringstream &serr, int &ierr)
{
    int nvals_cur;
    // Get the array dimension, 0,1,2,3,...
    int dim = (int)istart.size();

    // 0d is a special case.
    if (dim == 0) {
        nvals = 1;
        //if (size[0] == 0) return true;        
        words[0].set_processed(true);
        words[1].set_processed(true);
        return true;
    }

    // Index of word after equals sign.
    //int ieqp1 = 5 + dim - 1;
    int ieqp1 = find_equals() + 1;

    // nvals    Number of values after the = sign.
    nvals = 0;
    for (int i=ieqp1; i<(int)words.size(); i++) {
        nvals_cur = words[i].get_multiplicity();
        if( nvals_cur <= 0 ){
            fatal_error2(serr, ierr);
            serr << "Count must be positive [" << nvals_cur << "]" << endl;
            ierr = 2;
        }
        nvals += nvals_cur;
    }

    // This is for the get size function. We just want nvals and do not want
    // to do the check or marking as processed.
    if (size[0] == 0) return true;

    // Get the max size of the array.
    //int maxvals = size1*size2;
    int maxvals = size[0];
    for (int i=2; i<=dim; i++) {
        maxvals *= size[i-1];
    }

    //int ip = istart[0]-1;
    //if (dim == 2) {
    //    ip = istart[0]-1 + (istart[1]-1)*size[0];
    //}
    //if (dim == 3) {
    //    ip = istart[0]-1 + (istart[1]-1)*size[0] + (istart[2]-1)*size[0]*size[1];
    //}
    //if (dim == 4) {
    //    ip = istart[0]-1 + (istart[1]-1)*size[0] + (istart[2]-1)*size[0]*size[1] +
    //        (istart[3]-1)*size[0]*size[1]*size[2];
    //}
    //ip += nvals - maxvals;

    // Find the excess, i.e. the max array position the user is trying to
    // fill compared with the max size allowed. 
    Parser_utils putils(index_base);
    int ix = putils.start_dex(istart, size);
    int excess = ix + nvals - maxvals;

    //cout << "&&&&&cw ip = " << ip << "  excess = " << excess << endl;

    // Check that the number of values input by the user does not exceed
    // the array size.
    //int excess = istart1 - 1 + (istart2-1)*size1 + nvals - maxvals;
    if (excess > 0) {
        fatal_error2(serr, ierr);
        serr << "Maximum number of values allowed = " << maxvals << endl;
        serr << "(for multi-dimension arrays this max number is" << endl;
        serr << "     max_dim1 * max_dim2 * ...)" << endl;
        serr << "This command exceeds that value by " <<
             excess << endl << endl;
        ierr = 2;
    }
    
    // If fatal errors, then do not attempt further processing.
    if (ierr == 2) return false;

    // Mark as processed.
    for (int i=0; i<ieqp1; i++) {
        words[i].set_processed(true);
    }

    return true;
}



// ***************************************************************************
// ***************************************************************************
// Handle variables.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Check for the user defining variable dimensions for multi-dimensional
// arrays.
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
bool Cmd::check_for_dimension(stringstream &serr, int &ierr)
{
    // First do some checks.
    string varname = words[0].get_string();
    if (!words[0].is_variable()) return false;

    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].get_string() == "=") {
            return false;
        }
    }

    if (words[1].get_string() != "dimension") return false;

    // Find the variable, if not found, then create it.
    map<string, Variable>::iterator p;
    p = vmap->find(varname);
    if (p == vmap->end()) {
        Variable v(varname);
        vmap->insert(pair<string, Variable>(v.get_varname(), v));
    }
    p = vmap->find(varname);

    // Extract the bounds from the line.
    vector<int> bounds;
    for (int i=2; i<(int)words.size(); i++) {
        if (words[i].get_string() == "(") continue;
        if (words[i].is_comma())          continue;
        if (words[i].get_string() == ":") continue;
        if (words[i].get_string() == ")") break;

        // Get the bounds, note that this also makes sure it is an integer.
        bounds.push_back(words[i].get_int(serr, ierr));
    }

    // Actually set the bounds for the variable.
    int lnum = words[0].get_line_number();
    int file_lnum = words[0].get_file_line_number();
    string fname = words[0].get_filename();
    p->second.set_bounds(bounds, lnum, file_lnum, fname,
                         lines, serr, ierr);

    return true;
}


// ===========================================================================
// Check for the command
//    variable_description variable_name description
// If found, then set the description for the variable.
// Create the variable if necessary.
// ===========================================================================
bool Cmd::check_for_var_description(stringstream &serr, int &ierr)
{
    if (words[0].get_string() != "variable_description") return false;

    // Must be 3 words in the line.
    if (words.size() != 3) {
        words[0].fatal_error(serr, ierr);
        serr << "The variable_description command must have 3 words on the"
            " line" << endl;
        serr << "First word =  variable_description" << endl;
        serr << "Second word =  name of the variable" << endl;
        serr << "Third word =  description (usually some phrase in quotes)" << endl;
        serr << "This command has " << words.size() <<
            " words instead of 3 words." << endl;
        ierr = 2;
        return true;
    }

    // The variable name is word 1.
    string varname = words[1].get_string();
    if (!words[1].is_variable()) {
        words[0].fatal_error(serr, ierr);
        serr << "Expected a variable name as word 2" << endl;
        serr << "Variable names must begin with the $ character." << endl;
        serr << "This variable name does not begin with a $ character." << endl;
        serr << "Note that putting quotes around a variable name makes it" << endl;
        serr << "a string, not a variable." << endl;
        serr << "Variable name = " << varname << endl;
        ierr = 2;
        return true;
    }

    // Get the description.
    string vardes = words[2].get_string();

    // Find the variable, if not found, then create it.
    map<string, Variable>::iterator p;
    p = vmap->find(varname);
    if (p == vmap->end()) {
        Variable v(varname);
        vmap->insert(pair<string, Variable>(v.get_varname(), v));
    }
    p = vmap->find(varname);

    // Cannot change pre-defined variables.
    if (p->second.is_pre_defined()) {
        words[0].fatal_error(serr, ierr);
        serr << "Cannot change the description for a pre-defined"
             " variable" << endl;
        serr << "Variable name = " << varname << " is pre-defined." << endl;
        ierr = 2;
        return true;
    }
    
    // Actually set the description.
    p->second.set_description(vardes);

    return true;
}


// ===========================================================================
// Go through each word on the line (starting after the equals sign if
// present), and replace each variable with its value.
// This is for scalar variables only.
// ===========================================================================
void Cmd::substitute_variables(stringstream &serr, int &ierr)
{
    int irstart = 0;
    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].get_string() == "=") {
            irstart = 1;
            break;
        }
    }
    int nw1 = (int)words.size()-1;
    subvar_w0(irstart, nw1, serr, ierr);
}


// ===========================================================================
// Scan words i1 through i2 inclusive, replace any variables found with
// their value.
// If the variable is followed by ++ or --, handle that also.
// This is for scalar variables only.
// ===========================================================================
void Cmd::subvar_w0(int i1, int &i2, stringstream &serr, int &ierr)
{
    for (int i=i1; i<=i2; i++) {
        string s = words[i].get_string();
        if (words[i].is_variable()) {
            int increment = 0;
            if (i < i2) {
                string ppmm = words[i+1].get_string();
                if (ppmm == "++") increment = 1;
                if (ppmm == "--") increment = -1;
            }
            subvar0(i, s, increment, serr, ierr);
            if (increment != 0) {
                delete_words(i+1,i+1);
                i2 -= 1;
            }
        }
    }
}


// ===========================================================================
// Given a variable name, varname, and its index in the words array, vardex,
// replace it with its value.
// This is for scalar variables only.
// ===========================================================================
void Cmd::subvar0(int vardex, string &varname, int increment,
                  stringstream &serr, int &ierr)
{
    vector<int> adex;

    map<string, Variable>::iterator p;
    p = vmap->find(varname);
    if (p != vmap->end()) {
        int lnum = words[vardex].get_line_number();
        int file_lnum = words[vardex].get_file_line_number();
        string fname = words[vardex].get_filename();
        string svalue = p->second.get_var_value(adex, words[vardex].get_string(),
                                                lnum, file_lnum, fname,
                                                lines, serr, ierr);
        //int increment = words[vardex].get_increment();
        if (increment != 0) p->second.bump_var(adex, increment,
                                               lnum, file_lnum, fname,
                                               lines, serr, ierr);
        //words[vardex].set_increment(0);
        words[vardex].set_value(svalue);
    }
    else {
        // The variable has not been defined yet.
        words[vardex].fatal_error(serr, ierr);
        serr << "Attempted to use a variable before it was defined."
             << endl;
        serr << "Undefined variable = " << varname << endl;
        ierr = 2;
    }
}


// ===========================================================================
// Store the variable value(s), define if needed.
// Examples:
//    $radius = 3.0                         0d
//    $radius(1) = 3.0 4. 5.6e19            1d
//    $radius(3,4) = 3.0 4. 5.6e19 4 5 9    2d
//    ...
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
void Cmd::set_variables(stringstream &serr, int &ierr)
{
    //cout << "&&&&&cw Enter set_variables, words[0] = " << words[0].get_string() << endl;
    int ieq = -1;
    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].get_string() == "=") {
            ieq = i;
            break;
        }
    }

    // If an equals sign was not found on the line, then this is not a
    // variable assignment.
    if (ieq == -1) return;

    // If the first character of the first word is not a $, then this is not
    // a variable assignment.
    string vname = words[0].get_string();
    if (!words[0].is_variable()) return;

    // Define a few common things.
    int lnum = words[0].get_line_number();
    int file_lnum = words[0].get_file_line_number();
    string fname = words[0].get_filename();
    vector<string> valvec;

    int dim = 0;
    if (ieq >= 4) dim = ieq - 3;
    //cout << "&&&&&cw vname=" << vname << "  ieq=" << ieq << "  dim=" << dim << endl;

    // Do some checking.
    if (dim == 0) {
        // Must be 3 words in the line (for example: $radius = 3.0)
        if (words.size() != 3) {
            fatal_error2(serr, ierr);
            serr << "Expected number words in this line = 3" << endl;
            serr << "Actual number words = " << words.size() << endl << endl;
            ierr = 2;
            // If there aren't enough words on the line, then it is hopeless.
            if (words.size() < 3) return;
        }

        // The value must not have any multiplicity, i.e. be just a single value.
        // This only applies to 0d, values for arrays can have multiplicity.
        if (words[2].get_multiplicity() != 1) {
            words[2].fatal_error(serr, ierr);
            serr << "Multiplicity not equal 1 for " << words[2].get_string() << endl;
            serr << "Multiplicity is: " << words[2].get_multiplicity() << endl << endl;
            ierr = 2;
        }
    }

    if (dim > 0) {
        int nw_min = dim + 5;
        int nw_min_wc = nw_min + dim - 1;
        if ((int)words.size() < nw_min) {
            fatal_error2(serr, ierr);
            serr << "Expected number of symbols in this line >= " << nw_min_wc << endl;
            serr << "Actual number of symbols is less than expected." << endl << endl;
            ierr = 2;
            // If there aren't enough words on the line, then it is hopeless.
            return;
        }

        // Word at index 1 must be a "(".
        if (words[1].get_string() != "(") {
            words[1].fatal_error(serr, ierr);
            serr << "Expected an open parenthesis ,(, following the variable name"
                " in this line," << endl;
            serr << "For example: " << vname << "(...) = ..." << endl;
            serr << "Instead found: " << words[1].get_string() << endl << endl;
            ierr = 2;
            return;
        }

        // There must be a closing parenthses.
        int irp = 3 + dim - 1;
        if (words[irp].get_string() != ")") {
            words[irp].fatal_error(serr, ierr);
            serr << "Expected a close parenthesis ,), following the array indices"
                " in this line," << endl;
            serr << "For example: " << vname << "(...) = ..." << endl;
            serr << "Instead found: " << words[irp].get_string() << endl << endl;
            ierr = 2;
            return;
        }
    }

    // Store the values in a vector.
    for (int i=ieq+1; i<(int)words.size(); i++) {
        int imult = words[i].get_multiplicity();
        string s = words[i].get_string();
        for (int j=1; j<=imult; j++) {
            valvec.push_back(s);
        }
    }

    // Store the array indices in a vector.
    vector<int> istart(dim,0);
    int ierr2 = 0;
    for (int d=0; d<dim; d++) {
        istart[d] = words[d+2].get_int(serr, ierr);
        if (istart[d] <= 0) {
            words[d+2].fatal_error(serr, ierr);
            serr << "The index for the array must be an integer that is >= " << index_base << endl;
            serr << "Integer includes numbers like 3, 3., 3.0, but not 3.5" << endl;
            serr << "The index input is: " << istart[d] << endl << endl;
            ierr2 = 2;
        }
    }
    if (ierr2 == 2) {
        ierr = 2;
        return;
    }

    // Find the variable name in the variable map.
    map<string, Variable>::iterator p;
    p = vmap->find(vname);

    // If the variable is found in the variable map, then replace
    // its value with the new value. If the variable is not found
    // in the variable map, then add it as a new variable.
    if (p != vmap->end()) {
        p->second.set_var_value(istart, valvec, lnum, file_lnum, fname,
                                lines, serr, ierr);
    }
    else {
        Variable v(vname, istart, valvec, lnum, file_lnum, fname, lines,
                   serr, ierr);
        vmap->insert(pair<string, Variable>(v.get_varname(), v));
    }
}



// ===========================================================================
// Evaluate a variable.
// We have a word followed by multiple arguments. Find out if the word is
// a variable, use the arguments to get the variable value, replace the
// variable and arguments with its value.
//
// This function works for any dimension, 0,1,2,3,...
// ===========================================================================
bool Cmd::evaluate_variable(int iw1, int &i2, int &nargs,
                            stringstream &serr, int &ierr)
{
    // If there is no map of variables, then we do nothing.
    if (vmap == NULL) return false;

    // Do nothing if the word is not a variable (begins with $).
    if (!words[iw1].is_variable()) return false;

    // Get the variable name.
    string varname = words[iw1].get_string();

    // Find the variable.
    map<string, Variable>::iterator p;
    p = vmap->find(varname);

    // The variable was not found.
    if (p == vmap->end()) {
        words[iw1].fatal_error(serr, ierr);
        serr << "Trying to use a variable before it is defined." << endl;
        serr << "Undefined variable = " << varname << endl;
        serr << "The list of defined variables (at this point) is:" << endl;
        for (p=vmap->begin(); p!=vmap->end(); p++) {
            serr << p->second.get_varname() << endl;
        }
        ierr = 2;
        return true;
    }

    // The variable was found, do the evaluation and replace the words.

    // Check to see if all the variable arguments have a value.
    bool has_value = true;
    for (int i=0; i<nargs; i++) {
        int j = iw1 + 1 + i;
        if (!words[j].is_number()) {
            has_value = false;
            words[j].fatal_error(serr, ierr);
            serr << "Expected a number for variable index " <<
                i+1 << endl;
            serr << "Instead found:   " << words[j].get_string() << endl;
            ierr = 2;
        }
    }
    if (!has_value) return true;

    // Check to see if all the variable arguments are integer.
    bool all_int = true;
    for (int i=0; i<nargs; i++) {
        int j = iw1 + 1 + i;
        if (!words[j].is_integer()) {
            all_int = false;
            words[j].fatal_error(serr, ierr);
            serr << "Expected an integer for variable index " <<
                i+1 << endl;
            serr << "Instead found:   " << words[j].get_string() << endl;
            ierr = 2;
        }
    }
    if (!all_int) return true;

    // All the indices have values and are ints.
    // Load all the arguments into a vector of ints.
    vector<int> vdex;
    for (int i=0; i<nargs; i++) {
        int j = iw1 + 1 + i;
        int iv = words[j].get_int();
        vdex.push_back(iv);
    }

    // Check for ++ or -- following the variable.
    int increment = 0;
    int ippmm = iw1 + nargs + 1;
    if (ippmm <= i2 && ippmm <(int)words.size()) {
        string sppmm = words[ippmm].get_string();
        if (sppmm == "++") increment = 1;
        if (sppmm == "--") increment = -1;
    }

    // Evaluate the variable and replace the words.
    // Works in any dimensionality.
    int ln = words[iw1].get_line_number();
    int file_ln = words[iw1].get_file_line_number();
    string fname = words[iw1].get_filename();
    string result = p->second.get_var_value(vdex, varname, ln, file_ln,
                                            fname, lines, serr, ierr);
    //int increment = words[iw1].get_increment();
    if (increment != 0) p->second.bump_var(vdex, increment, ln, file_ln,
                                           fname, lines, serr, ierr);
    //words[iw1].set_increment(0);
    Word w(result, ln, file_ln, fname, lines);
    replace_words(iw1, iw1+nargs, w);
    i2 -= nargs;

    // If the variable was followed by a ++ or --, then remove the
    // ++ or -- since it has been used.
    if (increment != 0) {
        delete_words(iw1+1, iw1+1);
        i2 -= 1;
    }

    return true;
}






// ***************************************************************************
// ***************************************************************************
// Math evaluation.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Math evaluation driver.
// ===========================================================================
void Cmd::math_eval(stringstream &serr, int &ierr)
{
    // Combine * * into **, i.e. form the exponentiation operator.
    handle_star_star();

    // Ops like .and., .eq., ... can at this point be part of larger words,
    // they need to be extracted as individual words.
    handle_ops();

    //cout << "&&&&&cw Cmd.cc, Enter math_eval" << endl;
    //for (int i=0; i<(int)words.size(); i++) {
    //    cout << words[i].get_string() << endl;
    //}

    int ieq = find_any_char(0, (int)words.size()-1, "=");

    bool ifcmd = false;
    if (words[0].get_string() == "if") {
        ifcmd = true;
        ieq = -1;
    }

    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].get_string() == "(" /*&& i>ieq*/) {
            if (ifcmd && i>1) continue;
            if (i > (int)words.size()-2) {
                words[i].fatal_error(serr, ierr);
                serr << "Expected (...)" << endl;
                serr << "Found " << words[(int)words.size()-2].get_string() <<
                    words[(int)words.size()-1].get_string() << endl;
                ierr = 2;
                return;
            }

            // The starting index of the math expression.
            int istart = i+1;

            // Find the ending index of the math expression.
            int iclose = find_closing_symbol("(", ")", istart);
            if (iclose == -1) {
                words[i+1].fatal_error(serr, ierr);
                serr << "Did not find a closing parenthesis, ), in"
                    " math expression" << endl;
                serr << "Check for unbalanced parentheses in math expression." << endl;
                ierr = 2;
                return;
            }
            int iend = iclose - 1;

            int iwres = 0;
            int nargs = 0;
            for (;;) {
                if (!handle_innermost_parens(istart, iend, iwres, nargs, true,
                                             serr, ierr)) break;
                bool isvar = false;
                bool doit = true;
                if (iwres <= 0) doit = false;
                if (cmd_type == "assignment" && iwres==1) doit = false;
                if (doit) {
                    isvar = evaluate_variable(iwres-1, iend, nargs, serr, ierr);
                }
                if ((iwres > 0) && (!isvar)) {
                    evaluate_function(iwres-1, iend, nargs, serr, ierr);
                }
            }

            // Now set ihip1,2 to the original set of parens and handle those.
            // This will do a math eval inside the parens, handle multiple arguments
            // and possibly remove the parens.
            // We do not remove the parens if this is a command line or an assignment
            // line and we are to the left of the equals because a lot of checks
            // depend on the parens being there.
            int ihip1 = istart-1;
            int ihip2 = iend + 1;
            bool remp = true;
            if (ieq>ihip2 && ihip1==1) remp = false;
            handle_innermost_parens(ihip1, ihip2, iwres, nargs, remp,
                                    serr, ierr);

            // Handle the case of a variable array, i.e. evaluate and replace
            // the variable array reference. We of course do not do this for
            // an assignment statement where we are to the left of the equals.
            //bool isvar = false;
            bool doit = true;
            if (iwres <= 0) doit = false;
            if (cmd_type == "assignment" && iwres==1) doit = false;
            if (doit) {
                // We use ihip3 to account for ++ or -- following a
                // variable array reference.
                int ihip3 = ihip2 + 1;
                //isvar = evaluate_variable(iwres-1, ihip3, nargs, serr, ierr);
                evaluate_variable(iwres-1, ihip3, nargs, serr, ierr);
            }

            // Do not allow a function outside of parens. We could do this
            // but for now all math is inside parens.
            //if ((iwres > 0) && (!isvar)) {
            //    evaluate_function(iwres-1, iend, nargs, serr, ierr);
            //}

        }  // if find (
    } // End of loop through all words on the line.

    //cout << "&&&&&cw Cmd.cc, Exit math_eval" << endl;
}


// ===========================================================================
// Handle the innermost set of parentheses.
// The return value is false if parens were not found or if they were
// unbalanced. If parens were found and handled then true is returned.
// iwres is an output quantity and is the location of the resultant word.
// ===========================================================================
bool Cmd::handle_innermost_parens(int &i1, int &i2, int &iwres, int &nargs,
                                  bool remp, stringstream &serr, int &ierr)
{
    // If no innermost parens are found then iwres is meaningless.
    iwres = -1;

    // Search for the innermost left parens. It is ok if there is no left
    // parens, this line just does not have parens.
    int ip1 = find_last("(", i1, i2);
    if (ip1 == -1) return false;

    // After evaluation, the resultant word will be at ip1.
    iwres = ip1;

    int ipstart = ip1 + 1;
    bool done = false;
    nargs = 1;
    for (;;) {
        int ip2 = find_any_char(ipstart, i2, ",)");
        if (ip2 == -1) {
            words[ipstart].fatal_error(serr, ierr);
            serr << "Did not find a closing parenthesis, ), in"
                " math expression" << endl;
            serr << "Check for unbalanced parentheses in math expression." << endl;
            ierr = 2;
            return false;
        }

        if (words[ip2].get_string() == ")") done = true;
        if (words[ip2].is_comma()) nargs += 1;

        if (remp) {
            delete_words(ip2, ip2);
            i2 -= 1;
        }
        int ip21a = ip2 - 1;
        int ip21 = ip2 - 1;
        seval(ipstart, ip21, serr, ierr);
        i2 -= ip21a - ip21;

        if (done) break;

        ipstart += 1;
    }

    // Delete the leading paren.
    if (remp) {
        delete_words(ip1, ip1);
        i2 -= 1;
    }

    return true;
}


// ===========================================================================
// Simple evaluation of a series of words i1 to i2 inclusive.
// ===========================================================================
void Cmd::seval(int &i1, int &i2, stringstream &serr, int &ierr)
{
    Parser_math pmath;

    subvar_w0(i1, i2, serr, ierr);
    handle_unary_op(i1, i2, "-", serr, ierr);
    handle_unary_op(i1, i2, "+", serr, ierr);

    //     Level   Operators
    //     -----   -----------------------
    //       8     ()
    //       7     ++ --
    //       6     **
    //       5     *  /
    //       4     +  -
    //       3     .gt. .ge. .lt. .le. .eq. .ne.
    //       2     .not.
    //       1     .and.
    //       0     .or.
    for (int level=6; level>=0; level--) {
        for (int i=i1; i<=i2; i+=1) {
            if (words[i].is_operator(level)) {
                int ln = words[i].get_line_number();
                int file_ln = words[i].get_file_line_number();
                string fname = words[i].get_filename();
                Word w("", ln, file_ln, fname, lines);

                string op_type = words[i].get_op_type();
                if (op_type == "arithmetic")
                    pmath.do_op(i-1, i, i+1, words, w, serr, ierr);
                if (op_type == "relational")
                    pmath.do_op_relational(i-1, i, i+1, words, w, serr, ierr);
                if (op_type == "logical" && level == 2)   // .not. is unary
                    pmath.do_op_not(i, i+1, words, w, serr, ierr);
                if (op_type == "logical" && level != 2)
                    pmath.do_op_logical(i-1, i, i+1, words, w, serr, ierr);

                // level 2, .not., is unary and is handled differently.
                if (level == 2) {
                    replace_words(i, i+1, w);
                    i2 -= 1;
                }
                else {
                    replace_words(i-1, i+1, w);
                    i2 -= 2;
                    i -= 1;
                }
                continue;
            }
        }
    }
    //cout << "&&&&&cw Leave seval" << endl;
}


// ===========================================================================
// Handle unary plus and minus.
// utype is either "+" or "-".
// ===========================================================================
void Cmd::handle_unary_op(int i1, int &ipend, string utype,
                          stringstream &serr, int &ierr)
{
    int ipstart = i1;
    for (;;) {
        int ip = find(ipstart, ipend, utype);

        // If we do not find any more plus/minus signs then we are done.
        if (ip == -1) return;

        // Fatal error is the plus/minus sign is the last word on the line.
        if (ip >= ((int)words.size()-1)) {
            words[ip].fatal_error(serr, ierr);
            serr << "Found a " << utype << " sign at the end of a line." << endl;
            serr << "Expected something to the right of the  " << utype
                 << " sign to operate on." << endl;
            ierr = 2;
            return;
        }


        // If the plus/minus sign is the first word on the line, then it has
        // to be a unary op. The word after the plus/minus sign must be a
        // number or variable.
        // This should never happen because we are always inside (...)
        // and will never be word 0, still we should be general and take care
        // of this case.
        if (ip == 0) {
            if (!words[ip+1].is_number()) {
                words[ip+1].fatal_error(serr, ierr);
                serr << "Expected the object following the unary " << utype
                     << " to be a number." << endl;
                serr << "Instead, it was " << words[ip+1].get_string() << endl;
                ierr = 2;
                return;
            }

            // Actually do the negate operation.
            do_unary_op(ip, utype);
            ipstart = ip+1;
            ipend -= 1;
            continue;
        }
         
        // Check to see if the +/- is a binary op. If so, then nothing needs
        // to be done with this +/- sign, binary ops are handled elsewhere.
        if (words[ip-1].is_number() &&
            (words[ip+1].is_number() || words[ip+1].get_string() == "-" ||
             words[ip+1].get_string() == "+")
            ) {
            ipstart = ip+1;
            continue;
        }

        // Check to see if the +/- is a unary op.
        if (!words[ip-1].is_number() && words[ip+1].is_number()) {
            do_unary_op(ip, utype);
            ipstart = ip+1;
            ipend -= 1;
            continue;
        }

        // Check for an error.
        if (!words[ip-1].is_number() &&
            !words[ip+1].is_number()) {
            words[ip-1].fatal_error(serr, ierr);
            serr << "Expected the object following the unary " << utype << " to"
                " be a number." << endl;
            serr << "Instead, it was " << words[ip+1].get_string() << endl;
            ierr = 2;
            return;
        }

        words[ip].fatal_error(serr, ierr);
        serr << "Unknown error with unary " << utype << endl;
        serr << "Error with words: " << endl;
        serr << words[ip].get_string() << words[ip+1].get_string() << endl;
        ierr = 2;
        return;
    }
}



// ===========================================================================
// Do a unary operation.
// The minus sign is at word ip and the word to be negated is at word ip+1.
// After negation, both words get replaced by the new negated word.
// If the unary op is plus then all we need to do is get rid of the + sign.
// ===========================================================================
void Cmd::do_unary_op(int ip, string utype)
{
    if (utype == "+") {
        delete_words(ip,ip);
        return;
    }

    if (utype == "-") {
        if (words[ip+1].is_number()) {
            Word w = words[ip+1];
            w.negate_value();
            replace_words(ip, ip+1, w);
            return;
        }
    }
}



// ===========================================================================
// Check to see that all ++ and -- have been handled and removed.
// ===========================================================================
void Cmd::check_ppmm(stringstream &serr, int &ierr)
{
    for (int i=0; i<(int)words.size(); i++) {
        string s = words[i].get_string();
        if (s == "++" || s == "--") {
            words[i].fatal_error(serr, ierr);
            serr << "Misplaced " << s << " operator." << endl;
            serr << "++ and -- operators must follow a variable or " << endl;
            serr << "an element of an array variable. " << endl;
            ierr = 2;
        }
    }
}


// ===========================================================================
// Evaluate a function.
// ===========================================================================
void Cmd::evaluate_function(int iw1, int &i2, int &nargs,
                            stringstream &serr, int &ierr)
{
    // If there is no map of functions, then we do nothing.
    if (fmap == NULL) return;

    // If the word at iw1 is not a string then it will not be a function.
    if (!words[iw1].is_string()) return;

    // Find the function.
    string s = words[iw1].get_string();
    map<string, Function>::iterator p;
    p = fmap->find(s);

    // The function was not found.
    if (p == fmap->end()) {
        words[iw1].fatal_error(serr, ierr);
        serr << "Expected a function" << endl;
        serr << "Instead found:   " << words[iw1].get_string() << endl;
        serr << "The list of known functions is:" << endl;
        for (p=fmap->begin(); p!=fmap->end(); p++) {
            serr << p->second.get_name() << endl;
        }
        ierr = 2;
        return;
    }

    // The function was found, do the evaluation and replace the words.

    // Common items needed for all types of functions.
    int ln = words[iw1].get_line_number();
    int file_ln = words[iw1].get_file_line_number();
    string fname = words[iw1].get_filename();


    // Is a variable defined or not.
    if (s == "defined") {
        string varname = words[iw1+1].get_string();
        string result = "true";
        map<string, Variable>::iterator p;
        p = vmap->find(varname);
        if (p == vmap->end()) result = "false";
        Word w(result, ln, file_ln, fname, lines);
        replace_words(iw1, iw1+nargs, w);
        i2 -= nargs;
        return;
    }


    // String functions - string arguments, string results.
    if (p->second.get_type() == "string") {
        // Load all the arguments into a vector of strings.
        vector<string> vs;
        for (int i=0; i<nargs; i++) {
            int j = iw1 + 1 + i;
            string s = words[j].get_string();
            vs.push_back(s);
        }

        // Calculate the function and replace the words.
        string result = p->second.evaluate(vs, serr, ierr, ln, file_ln,
                                           fname, lines);
        Word w(result, ln, file_ln, fname, lines);
        replace_words(iw1, iw1+nargs, w);
        i2 -= nargs;
    }


    // Real functions - double arguments, double results.
    if (p->second.get_type() == "real") {
        // Check to see if all the function arguments have a value.
        bool has_value = true;
        for (int i=0; i<nargs; i++) {
            int j = iw1 + 1 + i;
            if (!words[j].is_number()) {
                has_value = false;
                words[j].fatal_error(serr, ierr);
                serr << "Expected a number for function argument number " <<
                    i+1 << endl;
                serr << "Instead found:   " << words[j].get_string() << endl;
                ierr = 2;
            }
        }
        if (!has_value) return;

        // All the arguments have values so we can deal with them
        // as doubles.
        // Load all the arguments into a vector of doubles.
        vector<double> vd;
        for (int i=0; i<nargs; i++) {
            int j = iw1 + 1 + i;
            double d = words[j].get_double();
            vd.push_back(d);
        }

        // Calculate the function and replace the words.
        double result = p->second.evaluate(vd, serr, ierr, ln, file_ln,
                                       fname, lines);
        Word w(result, ln, file_ln, fname, lines);
        replace_words(iw1, iw1+nargs, w);
        i2 -= nargs;
    }
}



// ===========================================================================
// When two "*" characters are together, assume that is the exponentiation
// operator, "**", and replace both "*"'s with "**".
// ===========================================================================
void Cmd::handle_star_star()
{
    for (int i=0; i<(int)words.size()-1; i++) {
        if (words[i].get_string() == "*" && words[i+1].get_string() == "*") {
            int lnum = words[i].get_line_number();
            int file_ln = words[i].get_file_line_number();
            string fname = words[i].get_filename();
            string s = "**";
            Word w(s, lnum, file_ln, fname, lines);
            replace_words(i, i+1, w);
        }
    }
}


// ===========================================================================
// The parser does not automatically separate operators like .eq., .ne., etc.
// For example, the phrase a.eq.b will be one word when it should be 3 words.
// This routine finds those cases and splits the one word into multiple words.
// ===========================================================================
void Cmd::handle_ops()
{
    vector<string> subs;
    subs.push_back(".eq.");
    subs.push_back(".ne.");
    subs.push_back(".gt.");
    subs.push_back(".ge.");
    subs.push_back(".lt.");
    subs.push_back(".le.");
    subs.push_back(".hgeq.");
    subs.push_back(".hgne.");
    subs.push_back(".hggt.");
    subs.push_back(".hgge.");
    subs.push_back(".hglt.");
    subs.push_back(".hgle.");
    subs.push_back(".not.");
    subs.push_back(".and.");
    subs.push_back(".or.");

    for (int i=0; i<(int)words.size(); i++) {
        string fstr = words[i].get_string();
        for (int j=0; j<(int)subs.size(); j++) {
            vector<string> vs;
            bool b = separate_str(subs[j], fstr, vs);
            if (b) {
                vector<Word> vw;
                for (int k=0; k<(int)vs.size(); k++) {
                    int lnum = words[i].get_line_number();
                    int file_lnum = words[i].get_file_line_number();
                    string fname = words[i].get_filename();
                    Word w(vs[k], lnum, file_lnum, fname, lines);
                    vw.push_back(w);
                    //cout << vs[k] << endl;
                }
                replace_words(i, i, vw);
                i--;
                break;
            }
        }


        //int lnum = words[i].get_line_number();
        //string s = "**";
        //Word w(s, lnum, lines);
        //replace_words(i, i+1, w);
    }
}


// ===========================================================================
// After the line has mostly been processed, check for any misplaced math
// operations. For example, the following line
//    xcenter = 1.0 + 2.0
// has a misplaced math op in it, i.e. it should be in parentheses
//    xcenter = (1.0 + 2.0)
// ===========================================================================
void Cmd::check_misplaced_math(stringstream &serr, int &ierr)
{
    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].is_operator()) {
            words[i].fatal_error(serr, ierr);
            serr << "Misplaced math operation." << endl;
            serr << "All math operations must be inside parentheses." << endl;
            ierr = 2;
        }
    }
}


// ***************************************************************************
// ***************************************************************************
// Handle if/elseif/else/endif
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Handle if/elseif/else/endif statements.
// ===========================================================================
void Cmd::handle_if(bool &skip, deque<bool> &skip_level,
                    deque<bool> &satisfied, stringstream &serr, int &ierr)
{
    // If's can be nested to any level, the number of levels is determined
    // by the size of skip_level, the size of satisfied would also work here.
    int nlevels = (int)skip_level.size();

    // The endif statement ends a block if.
    if (words[0].get_string() == "endif") {
        if ((int)words.size() > 1) {
            words[1].fatal_error(serr, ierr);
            serr << "The endif (or end if) statement should not have "
                 "anything else on the line." << endl;
            serr << "Found other words on the line." << endl;
            ierr = 2;
        }

        // The if level has ended, just erase it.
        skip_level.erase(skip_level.begin()+nlevels-1);
        satisfied.erase(satisfied.begin()+nlevels-1);
        skip = true;
        return;
    }

    // Else statment.
    if (words[0].get_string() == "else") {
        if ((int)words.size() > 1) {
            words[1].fatal_error(serr, ierr);
            serr << "The else statement should not have "
                 "anything else on the line." << endl;
            serr << "Found other words on the line." << endl;
            ierr = 2;
        }

        // If the if has been satisfied before this else, then just
        // skip the else block. Otherwise the if will be satisfied and
        // we do not skip the else block.
        if (satisfied[nlevels-1]) {
            skip_level[nlevels-1] = true;
        }
        else {
            satisfied[nlevels-1] = true;
            skip_level[nlevels-1] = false;
        }
        skip = true;
        return;
    }

    // If any level is in skip mode, then we will skip this line.
    // This is mostly for non if related lines, but the skip flag is
    // used below.
    skip = false;
    for (int n=0; n<nlevels; n++) {
        if (skip_level[n]) {
            skip = true;
        }
    }


    // Process the elseif statement.
    if (words[0].get_string() == "elseif") {
        if (satisfied[nlevels-1]) {
            skip_level[nlevels-1] = true;
        }
        else {
            // If we are in skip mode at a higher level, then we can ignore this
            // elseif.
            if (skip && !skip_level[nlevels-1]) return;

            // Do some syntax checking.
            int wsize = (int)words.size();

            if (wsize > 1) {
                if (words[1].get_string() != "(") {
                    words[1].fatal_error(serr, ierr);
                    serr << "Expected an open parentheses, (, following " <<
                          words[0].get_string() << endl;
                    serr << "Instead found: " << words[1].get_string() << endl;
                    ierr = 2;
                }
            }

            int nw = wsize-2;
            if (nw >= 0) {
                if (words[nw].get_string() != ")") {
                    words[nw].fatal_error(serr, ierr);
                    serr << "Expected a close parentheses, ), as the next to last "
                        "symbol on the line." << endl;
                    serr << "Instead found: " << words[nw].get_string() << endl;
                    ierr = 2;
                }
            }

            nw = wsize-1;
            if (nw >= 0) {
                if (words[nw].get_string() != "then") {
                    words[nw].fatal_error(serr, ierr);
                    serr << "Expected then as the last word on the line." << endl;
                    serr << "Instead found: " << words[nw].get_string() << endl;
                    ierr = 2;
                }
            }

            // Evaluate the conditional.
            math_eval(serr, ierr);

            if (words[1].get_bool(serr, ierr)) {
                satisfied[nlevels-1] = true;
                skip_level[nlevels-1] = false;
            }
            else {
                skip_level[nlevels-1] = true;
            }

        }

        // Set skip to skip the elseif statement.
        skip = true;
        return;
    }




    if (words[0].get_string() == "if") {
        //cout << "&&&&&cw Cmd.cc, if statment encountered" << endl;

        // If we are in skip mode at a higher level, then we can ignore this
        // if.
        if (skip) {
            skip_level.push_back(true);
            satisfied.push_back(true);
            return;
        }

        // Do some syntax checking.
        int wsize = (int)words.size();

        if (wsize > 1) {
            if (words[1].get_string() != "(") {
                words[1].fatal_error(serr, ierr);
                serr << "Expected an open parentheses, (, following " <<
                    words[0].get_string() << endl;
                serr << "Instead found: " << words[1].get_string() << endl;
                ierr = 2;
            }
        }

        // Evaluate the conditional.
        math_eval(serr, ierr);

        //for (int i=0; i<(int)words.size(); i++) {
        //    cout << words[i].get_string() << endl;
        //}

        // Single line if
        if (words[2].get_string() != "then") {
            if (words[1].get_bool(serr, ierr)) {
                delete_words(0,1);
                reset_name_type();
                skip = false;
            }
            else {
                skip = true;
            }
            return;
        }

        // Multi-block if
        if (words[2].get_string() == "then") {
            if (words[1].get_bool(serr, ierr)) {
                skip_level.push_back(false);
                satisfied.push_back(true);
                skip = true;
            }
            else {
                skip_level.push_back(true);
                satisfied.push_back(false);
                skip = true;
            }
            return;
        }
    }


    //for (int i=0; i<(int)words.size(); i++) {
    //    if (words[i].get_string() == "*" && words[i+1].get_string() == "*") {
    //    }
    //}
}


// ***************************************************************************
// ***************************************************************************
// Handle do loops
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Handle do loops.
// ===========================================================================
void Cmd::handle_do(bool &skip, deque<int> &do_start, int &cdex,
                    bool &end_do_loop, stringstream &serr, int &ierr)
{
    // Do's can be nested to any level, the number of levels is determined
    // by the size of do_start.
    int nlevels = (int)do_start.size();

    // End of do loop, go back to do line.
    if (words[0].get_string() == "enddo") {
        //cout << "&&&&&cw Cmd, handle_do, start of enddo, cdex=" << cdex << endl;
        if ((int)words.size() > 1) {
            words[1].fatal_error(serr, ierr);
            serr << "The enddo (or end do) statement should not have "
                 "anything else on the line." << endl;
            serr << "Found other words on the line." << endl;
            ierr = 2;
        }

        cdex = do_start[nlevels-1] - 1;
        skip = true;
        return;
    }


    // Cycle command encountered.
    if (words[0].get_string() == "cycle") {
        if ((int)words.size() > 1) {
            words[1].fatal_error(serr, ierr);
            serr << "The cycle statement should not have "
                 "anything else on the line." << endl;
            serr << "Found other words on the line." << endl;
            ierr = 2;
        }

        cdex = do_start[nlevels-1] - 1;
        skip = true;
        return;
    }

    // Break out of the do loop.
    if (words[0].get_string() == "exit") {
        if ((int)words.size() > 1) {
            words[1].fatal_error(serr, ierr);
            serr << "The exit statement should not have "
                 "anything else on the line." << endl;
            serr << "Found other words on the line." << endl;
            ierr = 2;
        }

        end_do_loop = true;
        return;
    }

    if (words[0].get_string() == "do") {

        //for (int i=0; i<(int)words.size(); i++) {
        //  cout << words[i].get_string() << endl;
        //}

        // Evaluate any math expressions on the do line.
        math_eval(serr, ierr);

        // Replace any simple variables on the line with their values.
        // Of course, do not replace the loop variable.
        int ieq = -1;
        for (int i=0; i<(int)words.size(); i++) {
            if (words[i].get_string() == "=") {
                ieq = i;
                break;
            }
        }
        if (ieq >= 0) {
            int nw1 = (int)words.size()-1;
            subvar_w0(ieq+1, nw1, serr, ierr);
        }

        // Handle unary minus
        handle_cmd_unary_minus(serr, ierr);

        // Number of words on the line after math evaluation.
        int nwords = (int)words.size();

        // Get the loop variable name.
        string do_varname = "$i";
        bool isvar = true;
        if (nwords>1) {
            do_varname = words[1].get_string();
            if (!words[1].is_variable()) isvar = false;
        }

        // Expecting 6 or 8 words, i.e. "do $i = 1 , 10" 
        if (nwords < 6) {
            words[0].fatal_error(serr, ierr);
            serr << "Expected at least 6 words on this line after any math evaluations."
                 << endl;
            serr << "For example, " << endl
                 << "    do " << do_varname << " = 1 , 10" << endl;
            serr << "Instead found " << nwords << " words on the line." << endl;
            serr << "The line (after any math evaluations have been done) is:" << endl;
            serr << "    ";
            for (int iw=0; iw<nwords; iw++) {
                serr << words[iw].get_string() << " ";
            }
            serr << endl;
            ierr = 2;
            return;
        }

        // Variables must begin with a $
        if (!isvar) {
            words[0].fatal_error(serr, ierr);
            serr << "Loop variable names must begin with a $ sign." << endl;
            serr << "Note that putting quotes around a variable name makes it" << endl;
            serr << "a string, not a variable." << endl;
            serr << "Instead found: " << do_varname << endl;
            ierr = 2;
            return;
        }

        // Word 3 must be an = sign.
        if (words[2].get_string() != "=") {
            words[2].fatal_error(serr, ierr);
            serr << "The third word must be an = sign." << endl;
            serr << "Instead found: " << words[2].get_string() << endl;
            ierr = 2;
            return;
        }

        // Word 5 must be a comma.
        if (!words[4].is_comma()) {
            words[4].fatal_error(serr, ierr);
            serr << "The fifth word must be a comma." << endl;
            serr << "Instead found: " << words[4].get_string() << endl;
            ierr = 2;
            return;
        }

        // The get_int functions generate an error if the values are
        // not integer.
        int i1 = words[3].get_int(serr, ierr);
        int i2 = words[5].get_int(serr, ierr);

        // Get the step (increment) if specified.
        int istep = 1;
        if (nwords > 7) istep = words[7].get_int(serr, ierr);

        string s1 = words[3].get_string();
        string s2 = words[5].get_string();

        bool do_continue = false;
        if (nlevels > 0) {
            if (do_start[nlevels-1] == cdex) do_continue = true;
        }

        if (do_continue) {  // This do has already been encountered.
            //cout << "&&&&&cw Cmd, handle_do, do:continue" << endl;

            // Find the variable in the list of variables, increment it, test for
            // ending the loop, and store the incremented value.
            map<string, Variable>::iterator p;
            p = vmap->find(do_varname);
            if (p != vmap->end()) {
                string do_var_value = p->second.get_var_value();
                int lnum = words[0].get_line_number();
                int file_lnum = words[0].get_file_line_number();
                string fname = words[0].get_filename();
                Word w(do_var_value, lnum, file_lnum, filename, lines);
                int ival = w.get_int(serr, ierr);
                ival += istep;
                //cout << "&&&&&cw Cmd, handle_do, do:continue, do_var_value=" << ival << endl;
                if (istep >= 0 && ival > i2) {
                    end_do_loop = true;
                    return;
                }
                if (istep < 0 && ival < i2) {
                    end_do_loop = true;
                    return;
                }
                stringstream ss;
                ss << ival;
                string sval = ss.str();
                vector<string> valvec;
                valvec.push_back(sval);
                vector<int> istart(0,0);
                p->second.set_var_value(istart, valvec, lnum, file_lnum, fname,
                                        lines, serr, ierr);
            }
            else {
                words[1].fatal_error(serr, ierr);
                serr << "The loop variable, " << do_varname <<
                    " was not found in the variable list." << endl;
                serr << "This should not happen, possible code bug?" << endl;
                ierr = 2;
                return;
            }
        }
        else {  // A new do loop has been encountered.
            do_start.push_back(cdex);

            // It is possible that we don't execute the do loop at all.
            if (istep >= 0 && i1 > i2) {
                end_do_loop = true;
                return;
            }
            if (istep < 0 && i1 < i2) {
                end_do_loop = true;
                return;
            }

            //cout << "&&&&&cw Cmd, handle_do, do:start, cdex=" << cdex << endl;
            //cout << "&&&&&cw Cmd, handle_do, do:start, s1=" << s1 << endl;
            //cout << "&&&&&cw Cmd, handle_do, do:start, s2=" << s2 << endl;

            // Store the loop variable, create it if necessary.
            vector<int> istart(0,0);
            int lnum = words[0].get_line_number();
            int file_lnum = words[0].get_file_line_number();
            string fname = words[0].get_filename();
            vector<string> valvec;
            valvec.push_back(s1);
            map<string, Variable>::iterator p;
            p = vmap->find(do_varname);
            if (p != vmap->end()) {
                p->second.set_var_value(istart, valvec, lnum, file_lnum, fname,
                                        lines, serr, ierr);
            }
            else {
                Variable v(do_varname, istart, valvec, lnum, file_lnum, fname,
                           lines, serr, ierr);
                vmap->insert(pair<string, Variable>(v.get_varname(), v));
            }
        }
        skip = true;
        return;
    }
}



// ===========================================================================
// Starting at a do statement, find the matching enddo.
// ===========================================================================
bool Cmd::find_matching_enddo(int &dlev, bool &stop_checking)
{
    if (words[0].get_string() == "enddo") {
        if (dlev == 1) return true;
        dlev -= 1;
        return false;
    }
    if (words[0].get_string() == "do") {
        dlev += 1;
        return false;
    }

    // If we are in main and hit a subroutine statement then that is the
    // end of main and we need to stop checking.
    if (words[0].get_string() == "subroutine") {
        stop_checking = true;
        return false;
    }

    // If we are in a subroutine and hit an endsubroutine statement then
    // we need to stop checking.
    if (words[0].get_string() == "endsubroutine") {
        stop_checking = true;
        return false;
    }

    return false;
}



// ***************************************************************************
// ***************************************************************************
// Subroutines
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Handle subroutines.
// ===========================================================================
void Cmd::handle_subroutines(bool &skip, bool &go_to_sub, string &sub_name,
                             bool &go_to_call, stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(skip == skip);
    //assert(serr == serr);
    assert(ierr == ierr);

    // 
    if (words[0].get_string() == "call") {
        sub_name = words[1].get_string();
        go_to_sub = true;
        return;
    }

    if (words[0].get_string() == "endsubroutine" ||
        words[0].get_string() == "return") {
        go_to_call = true;
        return;
    }

}


// ===========================================================================
// Searching for subroutine sub_name.
// ===========================================================================
bool Cmd::find_subroutine(string &sub_name)
{
    if ((int)words.size() < 2) return false;
    if (words[0].get_string() == "subroutine" &&
        words[1].get_string() == sub_name) return true;
    return false;
}


// ===========================================================================
// A call statement has been encountered, get the arguments, if any.
// The call is expected to be
//      call subname ( arg1, arg2, ...)
// ===========================================================================
void Cmd::get_call_args(vector<string> &sargs, vector<bool> &sargs_isvar,
                        stringstream &serr, int &ierr)
{
    //debug_print_words("Cmd, enter get_call_args");

    // We do not want to modify the words on this line, but we have to
    // temporarily to get the math eval to work right. Therefore store the
    // words on the line and restore them later.
    deque <Word> words_store;
    for (int i=0; i<(int)words.size(); i++) {
        words_store.push_back(words[i]);
    }

    // Erase the call and the subroutine name.
    erase_word(0);
    erase_word(0);

    // Erase the opening and closing parens.
    if ((int)words.size() > 0) {
        if (words[0].get_string() == "(") erase_word(0);
    }
    if ((int)words.size() > 0) {
        if (words[(int)words.size()-1].get_string() == ")") erase_last_word();
    }
    //debug_print_words("Cmd, get_call_args, after erase");

    // Do a math eval to get one word arguments. If the arguments are
    // variables they will not be evaluated, so we will end up with a mix
    // of variables and numbers.
    if ((int)words.size() > 0) {
        math_eval(serr, ierr);
        int wlen = (int)words.size() - 1;
        handle_unary_op(0, wlen, "-", serr, ierr);
        wlen = (int)words.size() - 1;
        handle_unary_op(0, wlen, "+", serr, ierr);
    }

    //debug_print_words("Cmd, get_call_args, after math eval");

    // Store the arguments in the vector of strings, sargs, to be returned
    // to the calling code and also store in the class, call_args.
    call_args.clear();
    call_args_isvar.clear();
    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].is_comma()) continue;
        sargs.push_back(words[i].get_string());
        sargs_isvar.push_back(words[i].is_variable());
        call_args.push_back(words[i].get_string());
        call_args_isvar.push_back(words[i].is_variable());
    }

    // Restore the words before leaving this function.
    words.clear();
    for (int i=0; i<(int)words_store.size(); i++) {
        words.push_back(words_store[i]);
    }
    //debug_print_words("Cmd, get_call_args, after restoring words");
}


// ===========================================================================
// A subroutine statement has been encountered, get the arguments, if any.
// The subroutine statement is expected to be
//      subroutine subname ( arg1, arg2, ...)
// ===========================================================================
void Cmd::get_sub_args(vector<string> &sargs, vector<bool> &sargs_isvar)
{
    sub_args.clear();
    sub_args_isvar.clear();
    for (int i=3; i<(int)words.size(); i+=2) {
        sargs.push_back(words[i].get_string());
        sargs_isvar.push_back(words[i].is_variable());
        sub_args.push_back(words[i].get_string());
        sub_args_isvar.push_back(words[i].is_variable());
    }
}


// ===========================================================================
// Accessor functions for the calling and subroutine arguments.
// ===========================================================================
void Cmd::copy_call_args(vector<string> &sargs, vector<bool> &sargs_isvar)
{
    for (int i=0; i<(int)call_args.size(); i++) {
        sargs.push_back(call_args[i]);
        sargs_isvar.push_back(call_args_isvar[i]);
    }
}

void Cmd::copy_sub_args(vector<string> &sargs, vector<bool> &sargs_isvar)
{
    for (int i=0; i<(int)sub_args.size(); i++) {
        sargs.push_back(sub_args[i]);
        sargs_isvar.push_back(sub_args_isvar[i]);
    }
}




// ***************************************************************************
// ***************************************************************************
// Handle comments.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Process single line comments.
// ===========================================================================
void Cmd::single_line_comments()
{
    for (int i=0; i<(int)words.size()-1; i++) {
        if ((words[i].get_string() == "!") ||
            (words[i].get_string() == "#") ||
            (words[i].get_string() == "/" && words[i+1].get_string() == "/")
            ) {
            words.erase(words.begin()+i, words.begin()+(int)words.size());
            break;
        }
    }

    // Handle the case where the last word might be an ! or a #
    int ilast = (int)words.size()-1; 
    if (ilast < 0) return;
    if ((words[ilast].get_string() == "!") || (words[ilast].get_string() == "#"))
        words.erase(words.begin()+ilast);
}


// ===========================================================================
// Process multi-line comments.
// ===========================================================================
void Cmd::multi_line_comments(int &level)
{
    /*
    cout << "*** Enter multi_line_comments, level=" << level << endl;
    cout << "**** original string: " << original_str << endl;
    stringstream ss;
    print_using_words(ss);
    cout << "     print words before:" << endl;
    cout << "         " << ss.str() << endl;
    */

    int istart = -1;
    if (level > 0) istart = 0;

    for (int i=0; i<(int)words.size()-1; i++) {
        //cout << "Top of i loop, i=" << i << endl;
        if (words[i].get_string() == "/" && words[i+1].get_string() == "*") {
            if (level == 0) istart = i;
            level += 1;
            //cout << "found /*, i=" << i << endl;
            i += 1;
            continue;
        }

        if (words[i].get_string() == "*" && words[i+1].get_string() == "/") {
            if (level == 0) {
                cout << "Error in line " << line_number << " umatched */" << endl;
            }
            //cout << "found */, istart=" << istart << "  words[istart]=" <<
            //    words[istart].get_string() << endl;
            //cout << "found */, i=" << i << "  words[i]=" <<
            //    words[i].get_string() << endl;
            //cout << "found */, i+1=" << i+1 << "  words[i+1]=" <<
            //    words[i+1].get_string() << endl;
            words.erase(words.begin()+istart, words.begin()+i+2);
            level -= 1;
            int ndel = i+1-istart+1;
            //cout << "ndel=" << ndel << "  i=" << i << endl;
            i = i+1-ndel+1;
            //cout << "after changing i, i=" << i << "  words[i]=" <<
            //    words[i].get_string() << endl;
            if (level > 0) istart = i;
            continue;
        }

    }

    if (level > 0) {
        words.erase(words.begin()+istart, words.begin()+(int)words.size());
    }

    /*
    stringstream ss1;
    print_using_words(ss1);
    cout << "     print words after:" << endl;
    cout << "         " << ss1.str() << endl;

    cout << endl << "**********" << endl;
    */
}


// ***************************************************************************
// ***************************************************************************
// Miscellaneous
// ***************************************************************************
// ***************************************************************************


// ===========================================================================
// Go through every word on the line, check for matching quotes, then remove
// them.
// ===========================================================================
void Cmd::handle_quotes(stringstream &serr, int &ierr)
{
    for (int i=0; i<(int)words.size(); i++) {
        words[i].handle_quotes(serr, ierr);
    }
}



// ===========================================================================
// The execution line arguments are expected to be of the form
//     -v r1=5 -v somevar = 14
// The -v is a keyword indicating that a variable setting follows. There is
// no $ because the shell does not allow that.
// At this point the execution line arguments have been parsed into words.
// This function extracts the variable definitions, inserts the $, and turns
// them into separate lines, and returns that in string sout. Then the
// parser can simply add that to the top of the user input file.
// ===========================================================================
void Cmd::handle_exe_args(string &sout)
{
  // We use a stringstream here instead of modifying sout directly so that
  // we can use endl instead of \n since endl is portable and \n is not.
  stringstream ss;
  bool line;
  for (int i=0; i<(int)words.size()-1; i++) {
    // if you hit a -<letter>
    if (words[i].get_string() == "-" &&
        ( words[i+1].get_string() == "v" ||
          words[i+1].get_string() == "l" ) ) {
      // get type of argument
      line = true;
      if( words[i+1].get_string() == "v" ){
        line = false;
      }
      // move in after the -<letter> and stuff line until next -<letter>
      int istart = i+2;
      for (int j=istart; j<(int)words.size(); j++) {
        // stop at next -<letter>
        if (j < (int)words.size()-1) {
          if (words[j].get_string() == "-" &&
              ( words[j+1].get_string() == "v" ||
                words[j+1].get_string() == "l" ) ) {
            break;
          }
        }
        string sj = words[j].get_string();
        if (j == istart && !line) {
          sj.insert(sj.begin(), '$');
        }
        ss << sj << " ";
      }
      ss << endl;
    }
  }
  sout = ss.str();
}


// ===========================================================================
// Consider the following input
//     2.0, 3.0 e15, -7.0
// The issue is with the middle two words, "3.0 e15", the old parser ignored
// the space and treated this as one word, 3.0e15. The new parser treats is
// as two words.
//
// This should have been treated as an input error by the old parser but was
// not, so now we have to deal with it.
//
// This routine detects this situation and allows the calling code to deal
// with it according to the action input, allowed action values are:
//
//    ignore      Treat it as two words and silently continue.
//    fix         Merge the two words into one word, as the old parser did.
//    error       Generate a fatal error, force the user to fix it.
//
// ===========================================================================
void Cmd::deprecated_input01(string action, stringstream &serr, int &ierr)
{
    //if (cmd_name != "depcmd01") return;

    if (cmd_type != "command") return;

    for (int i=0; i<(int)words.size()-2; i++) {
        // A comma must be found first.
        if (!words[i].is_comma()) continue;

        // There could be a unary plus or minus on the next number, if so
        // then skip it. At this point, the unary plus and minus have not
        // been merged with their number.
        int in1 = i+1;
        string spm = words[i+1].get_string();
        string s1;
        if (spm == "+" || spm == "-") {
            s1 = spm;
            in1 += 1;
        }
        s1 += words[in1].get_string();

        // in1 is where the first number is, it needs to be a number.
        if (!words[in1].is_number()) continue;

        // in2 is where the second number is, it needs to be a number.
        int in2 = in1 + 1;
        if (in2 > (int)words.size() - 1) break;
        if (!words[in2].is_number()) continue;
        string s2 = words[in2].get_string();
        s2.erase(s2.begin());

        // The first character of the second number should be an e or E.
        // But at this point we have already detected this and prepended
        // a 1 on to the word. So the first character should be 1 and the
        // second character should be e or E
        char c30 = words[in2].get_string()[0];
        if (c30 != '1') continue;

        char c31 = words[in2].get_string()[1];
        if (c31 != 'e' && c31 != 'E') continue;

        // The next word, if present should be a comma.
        int ic2 = in2 + 1;
        if (ic2 <= (int)words.size()-1) {
            if (!words[ic2].is_comma()) continue;
        }

        // A deprecated input has been found, ignore it, fix it, or
        // generate a fatal error.
        if (action == "ignore") continue;
        if (action == "fix") {
            words[in2].erase_char(0);
            merge_words(in1, in2);
            continue;
        }
        if (action == "error") {
            words[in1].fatal_error(serr, ierr);
            serr << "Possible error, detected the following" << endl;
            serr << "   comma digits space exponent comma" << endl;
            serr << "The digits and exponent are separated by one or more spaces,"
                 << endl;
            serr << "this is not allowed for a single number." << endl;
            serr << "The digits are: " << s1 << "  and the exponent is: "
                 << s2 << endl;
            serr << "If this is one number, then remove the space." << endl;
            serr << "If this is two numbers, then put a comma between the"
                 << " digits and exponent."<< endl;
            serr << "This error (and the same error in subsequent lines) can"
                 << endl;
            serr << "be controlled with the following input file command"
                 << endl;
            serr << "and arguments (put before the lines with errors)" << endl;
            serr << "      depcmd_dse argument" << endl;
            serr << "where argument has one of the following values:" << endl;
            serr << "      fix     Silently remove the space, merge into one number" << endl;
            serr << "      ignore  Silently treat as two numbers" << endl;
            serr << "      error   Generate fatal error (default)" << endl;
            serr << "While the default is to generate an error, if the" << endl;
            serr << "command name is matdef, then the default is fix." << endl;
            ierr = 2;
            continue;
        }
    }
}



// ===========================================================================
// Fatal error
// This is mainly meant to be called from some other class that does not
// know about words.
// ===========================================================================
void Cmd::fatal_error(int iw, stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(ierr == ierr);

    int lnum = words[iw].get_line_number();
    int file_lnum = words[iw].get_file_line_number();
    string fname = words[iw].get_filename();
    serr << endl;
    serr << "*** FATAL ERROR in line " << file_lnum << ":" << endl;
    serr << "    " << (*lines)[lnum-1] << endl;
    serr << "in file: " << fname << endl;
}

// ===========================================================================
// This is meant to be called from within this class.
// ===========================================================================
void Cmd::fatal_error2(stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(ierr == ierr);

    serr << endl;
    serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
    serr << "    " << (*lines)[line_number-1] << endl;
    serr << "in file: " << filename << endl;
}


// ===========================================================================
// Warning
// ===========================================================================
void Cmd::warning(int iw, stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(ierr == ierr);

    int lnum = words[iw].get_line_number();
    int file_lnum = words[iw].get_file_line_number();
    string fname = words[iw].get_filename();
    serr << endl;
    serr << "*** WARNING in line " << file_lnum << ":" << endl;
    serr << "    " << (*lines)[lnum-1] << endl;
    serr << "in file: " << fname << endl;
}


// ===========================================================================
// This is used when printing duplicate lines warnings.
// ===========================================================================
void Cmd::print_duplicate_line(int iw, stringstream &ss, int fn_width,
                               int lnum_width, string after_lnum)
{
    int lnum = words[iw].get_line_number();
    int file_lnum = words[iw].get_file_line_number();
    string fname = words[iw].get_filename();
    ss << setw(fn_width) << fname;
    ss << setw(lnum_width) << file_lnum << after_lnum;
    ss << (*lines)[lnum-1];
    //print_using_words_fm(ss);
}


// ===========================================================================
// Get the filename size and line number size for formatting purposes
// when printing duplicate lines warnings.
// ===========================================================================
void Cmd::get_duplicate_sizes(int iw, int &fn_width, int &lnum_width)
{
    int file_lnum = words[iw].get_file_line_number();
    string fname = words[iw].get_filename();
    fn_width = (int)fname.size();
    lnum_width = 1;
    if (file_lnum >= 10)       lnum_width = 2;
    if (file_lnum >= 100)      lnum_width = 3;
    if (file_lnum >= 1000)     lnum_width = 4;
    if (file_lnum >= 10000)    lnum_width = 5;
    if (file_lnum >= 100000)   lnum_width = 6;
    if (file_lnum >= 1000000)  lnum_width = 7;
}


// ===========================================================================
// Look at the places where this function is called to understand the
// following indices.
//     wdex = i    Index into the words array.
//     cdex = k    C index in the output array.
// ===========================================================================
void Cmd::error_dup_line(string &cname, int wdex, int cdex,
                         vector<int> &dup_wdex1, vector<Cmd *> &dup_cmd1,
                         vector<int> &dup_vals, const vector<int> &size,
                         int dup_fatal, stringstream &serr, int &ierr)
{
    if (dup_vals[cdex] == 0) {
        dup_cmd1[cdex] = this;
        dup_wdex1[cdex] = wdex;
    }
    dup_vals[cdex] += 1;
    if (dup_fatal == 0) return;
    if (dup_vals[cdex] > 1) {
        int wdex1 = dup_wdex1[cdex];
        Cmd *cmd = dup_cmd1[cdex];

        // Get the dimension of the array, 0,1,2,3,...
        int dim = (int)size.size();

        if (dup_fatal == 2) words[wdex].fatal_error(serr, ierr);
        if (dup_fatal == 1) words[wdex].warning(serr, ierr);
        int tot_size = 1;
        for (int ts=0; ts<dim; ts++) {
            tot_size *= size[ts];
        }
        vector<int> irdices(dim, 0);
        Parser_utils putils(index_base);
        putils.reverse_dex(cdex, tot_size, irdices, size);
        serr << "A duplicate value has been specified for: " << cname << "(";
        for (int irdex=0; irdex<dim; irdex++) {
            serr << irdices[irdex];
            if (irdex < dim-1) serr << ",";
        }
        serr << ") = " <<
            words[wdex].get_string() << endl;

        serr << "This array element was first specified in line " <<
            cmd->get_file_line_number(wdex1) << endl;
        string fname = cmd->get_filename(wdex1);
        serr << "    " << (*lines)[cmd->get_line_number(wdex1)-1] <<
            endl;
        serr << "in file: " << fname << endl;

        if (dup_fatal == 2) {
            serr << "This fatal error can be turned into a warning with the command " <<
                endl << "    duplicate_array_values = warning" << endl;
        }
        if (dup_fatal == 1) {
            serr << "This warning can be turned into a fatal error with the command " <<
                endl << "    duplicate_array_values = fatal" << endl;
        }
        serr << "Duplicate array value checking can be turned off totally with" <<
            endl << "    duplicate_array_values = none" << endl;
        serr << "This is not recommended since you will lose the opportunity" <<
            endl << "to check for legimate errors in your input." << endl;

        ierr = 1;
        if (dup_fatal == 2) ierr = 3;
    }
}


// ===========================================================================
// There are some commands that can be written as two words such as "end if",
// "else if", and "end do". Find these and combine them into one word.
// ===========================================================================
void Cmd::handle_two_words()
{
    // Handle + + -> ++
    for (int i=0; i<(int)words.size()-1; i++) {
        if (words[i].get_string() == "+" && words[i+1].get_string() == "+") {
            bool combine = false;
            if (i == (int)words.size()-2) combine = true;
            if (i < (int)words.size()-2) {
                if (!words[i+2].is_numvar()) combine = true;
            }
            if (combine) {
                int lnum = words[i].get_line_number();
                int file_lnum = words[i].get_file_line_number();
                string fname = words[i].get_filename();
                string s = "++";
                Word w(s, lnum, file_lnum, fname, lines);
                replace_words(i, i+1, w);
            }
        }
    }

    // Handle - - -> --
    for (int i=0; i<(int)words.size()-1; i++) {
        if (words[i].get_string() == "-" && words[i+1].get_string() == "-") {
            bool combine = false;
            if (i == (int)words.size()-2) combine = true;
            if (i < (int)words.size()-2) {
                if (!words[i+2].is_numvar()) combine = true;
            }
            if (combine) {
                int lnum = words[i].get_line_number();
                int file_lnum = words[i].get_file_line_number();
                string fname = words[i].get_filename();
                string s = "--";
                Word w(s, lnum, file_lnum, fname, lines);
                replace_words(i, i+1, w);
            }
        }
    }


    // The rest of these have at least two words on the line,
    // like "end subroutine".
    if ((int)words.size() < 2) return;

    // Common settings.
    int lnum = words[0].get_line_number();
    int file_lnum = words[0].get_file_line_number();
    string fname = words[0].get_filename();

    // Handle the case where enddo is written as two
    // words, just combine them into one word.
    if (words[0].get_string() == "end" && words[1].get_string() == "do") {
        string s = "enddo";
        Word w(s, lnum, file_lnum, fname, lines);
        replace_words(0, 1, w);
    }

    // Handle the case where endsubroutine is written as two
    // words, just combine them into one word.
    if (words[0].get_string() == "end" && words[1].get_string() == "subroutine") {
        string s = "endsubroutine";
        Word w(s, lnum, file_lnum, fname, lines);
        replace_words(0, 1, w);
    }

    // Handle the case where endwhen is written as two
    // words, just combine them into one word.
    if (words[0].get_string() == "end" && words[1].get_string() == "when") {
        string s = "endwhen";
        Word w(s, lnum, file_lnum, fname, lines);
        replace_words(0, 1, w);
    }

    // Handle the case where endif and elseif are written as two
    // words, just combine them into one word.
    if (words[0].get_string() == "end" && words[1].get_string() == "if") {
        string s = "endif";
        Word w(s, lnum, file_lnum, fname, lines);
        replace_words(0, 1, w);
    }
    if (words[0].get_string() == "else" && words[1].get_string() == "if") {
        string s = "elseif";
        Word w(s, lnum, file_lnum, fname, lines);
        replace_words(0, 1, w);
    }
}


// ===========================================================================
// Check for end of input. There are several ways user input ends:
//    End of file
//    Encounter a stop command
//    Encounter a fatal error command.
// ===========================================================================
bool Cmd::check_input_end(bool kill_run, stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(kill_run == kill_run);

    if (words[0].get_string() == "fatal_error") {
        int lnum = words[0].get_line_number();
        int file_lnum = words[0].get_file_line_number();
        string fname = words[0].get_filename();
        serr << endl;
        serr << "*** User has issued a fatal_error command in line "
             << file_lnum << ":" << endl;
        serr << "    " << (*lines)[lnum-1] << endl;
        serr << "in file: " << fname << endl;
        serr << endl << "The user supplied fatal_error message is: " << endl;
        serr << "    ";
        string s = (*lines)[lnum-1];
        int i1 = s.find("f", 0);
        for (int i=i1+12; i<(int)s.size(); i++) {
            serr << s[i];
        }
        serr << endl;
        ierr = 2;
        return true;
    }

    if (words[0].get_string() == "stop") return true;
    return false;
}




// ***************************************************************************
// ***************************************************************************
// Operations on the deque of words.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Find the first occurrence of string s in part of the line.
// ===========================================================================
int Cmd::find(int i1, int i2, string s)
{
    for (int i=i1; i<=i2; i++) {
        if (words[i].get_string() == s) {
            return i;
        }
    }
    return -1;
}


// ===========================================================================
// Find the first occurrence of any character in string s in part of
// the line.
// ===========================================================================
int Cmd::find_any_char(int i1, int i2, string s)
{
    for (int i=i1; i<=i2; i++) {
        for (int j=0; j<(int)s.size(); j++) {
            string ssub = s.substr(j, 1);
            if (words[i].get_string() == ssub) {
                return i;
            }
        }
    }
    return -1;
}


// ===========================================================================
// Find the last occurrence of string s in the line.
// ===========================================================================
int Cmd::find_last(string s, int i1, int i2)
{
    int iloc = -1;
    for (int i=i1; i<=i2; i++) {
        if (words[i].get_string() == s) {
            iloc = i;
        }
    }
    return iloc;
}


// ===========================================================================
// Given an input string, fstr, and a sub string, subs, find the first
// occurrence of subs in fstr. Return in the string vector, vs, the string
// to the left of subs, if any, the sub string itself, subs, and the string
// to the right of subs, if any.
// ===========================================================================
bool Cmd::separate_str(string &subs, string &fstr, vector<string> &vs)
{
    // Make sure the return vector is empty.
    vs.clear();

    // Find the sub string, if not found, then nothing more to do.
    int loc = (int)fstr.find(subs,0);
    if (loc == (int)string::npos) return false;

    // If fstr only contains subs and nothing more, then there is nothing
    // to do.
    if (subs == fstr) return false;

    // Anything to the left of the sub string is the first string returned.
    if (loc > 0) {
        string s1 = fstr.substr(0,loc);
        vs.push_back(s1);
    }

    // The sub string itself is the second string returned.
    vs.push_back(subs);

    // Find the number of characters to the right of the sub string.
    int subs_len = (int)subs.size();
    int fstr_len = (int)fstr.size();
    int istart = loc + subs_len;
    int nchar = fstr_len - istart;

    // Anything to the right of the sub string is the third string returned.
    if (nchar > 0) {
        string s2 = fstr.substr(istart,nchar);
        vs.push_back(s2);
    }

    return true;
}


// ===========================================================================
// Find the location of the closing symbol that matches the opening symbol.
// Symbol examples are (), [], {}
// We assume that the opening symbol has been found and we are starting the
// search after the opening symbol location.
// Nesting is handled, for example, (...(...(...)...)...)
// ===========================================================================
int Cmd::find_closing_symbol(string opensym, string closesym, int i1)
{
    int level = 0;
    for (int i=i1; i<(int)words.size(); i++) {
        string w = words[i].get_string();
        if (w == opensym) {
            level += 1;
            continue;
        }
        if (w == closesym) {
            if (level == 0) return i;
            level -= 1;
            continue;
        }
    }
    return -1;
}


// ===========================================================================
// Delete words i1 through i2 inclusive from the deque.
// ===========================================================================
void Cmd::delete_words(int i1, int i2)
{
    deque<Word>::iterator p = words.begin();
    words.erase(p + i1, p + i2 + 1);
}


// ===========================================================================
// Replace words i1 through i2 inclusive with word w.
// ===========================================================================
void Cmd::replace_words(int i1, int i2, Word &w)
{
    delete_words(i1, i2);
    deque<Word>::iterator p = words.begin();
    words.insert(p + i1, w);
}


// ===========================================================================
// Replace words i1 through i2 inclusive with all the words in vector vw.
// ===========================================================================
void Cmd::replace_words(int i1, int i2, vector<Word> &vw)
{
    delete_words(i1, i2);
    for (int i=(int)vw.size()-1; i>=0; i--) {
        deque<Word>::iterator p = words.begin();
        words.insert(p + i1, vw[i]);
    }
}


// ===========================================================================
// Merge words i1 through i2 inclusive into one word located at i1, remove
// words i1+1 through i2 inclusive.
// ===========================================================================
void Cmd::merge_words(int i1, int i2)
{
    int lnum = words[i1].get_line_number();
    int file_lnum = words[i1].get_file_line_number();
    string fname = words[i1].get_filename();
    string s = words[i1].get_string();

    for (int i=i1+1; i<=i2; i++) {
        s += words[i].get_string();
    }

    Word w(s, lnum, file_lnum, fname, lines);
    replace_words(i1, i2, w);
}


// ===========================================================================
// Find the equals sign on the line.
// ===========================================================================
int Cmd::find_equals()
{
    int ieq = -1;
    for (int i=0; i<(int)words.size(); i++) {
        if (words[i].get_string() == "=") {
            ieq = i;
            break;
        }
    }
    return ieq;
}



// ***************************************************************************
// ***************************************************************************
// Handle processed flags.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Set all the processed flags in the line to be false.
// ===========================================================================
void Cmd::clear_processed()
{
    for (int i=0; i<(int)words.size(); i++) {
        words[i].set_processed(false);
    }
}

void Cmd::set_processed(bool ip)
{
    for (int i=0; i<(int)words.size(); i++) {
        words[i].set_processed(ip);
    }
}



// ===========================================================================
// Check processed flags for each word.
// ===========================================================================
void Cmd::check_processed(bool &good, stringstream &serr, int &ierr)
{
    // First we check to see if any of the words on the line have been
    // processed. If none of the words have been processed, then we print
    // the entire line as an error. This saves the user from having to
    // wade through an error print for every word on the line.
    bool p = false;
    for (int i=0; i<(int)words.size(); i++) {
        p = words[i].get_processed();
        if (p) break;
    }

    if (!p) {
        good = false;
        words[0].fatal_error(serr, ierr);
        serr << "This line has not been processed." << endl;
        ierr = 2;

        return;
    }


    // At least one word on the line has been processed.
    // Check all the words on the line, throw an error for any word not
    // processed.
    for (int i=0; i<(int)words.size(); i++) {
        p = words[i].get_processed();

        if (!p) {
            good = false;
            words[i].fatal_error(serr, ierr);
            serr << "A word on this line has not been processed." << endl;
            serr << "Not proccessed word = " << words[i].get_string() << endl;
            ierr = 2;

        }
    }
}


// ***************************************************************************
// ***************************************************************************
// Debug
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Print all the words on the line mainly for debugging.
// Output is to a stringstream so the calling method can decide what to do
// with the output - send it to the screen, use it for testing, whatever.
// ===========================================================================
void Cmd::print_all_words()
{
    stringstream ss;
    print_all_words(ss);
    cout << ss.str();
}

void Cmd::print_all_words(stringstream &ss)
{
    ss << "*** Command name = " << cmd_name << endl;
    for (int i=0; i<(int)words.size(); i++) {
        stringstream ss2;
        words[i].print_type(ss2);
        ss << words[i].get_string() << " " << ss2.str() << endl;
    }
    ss << endl;
}


// ===========================================================================
// Print all the words on the line mainly for debugging.
// Output is to a stringstream so the calling method can decide what to do
// with the output - send it to the screen, use it for testing, whatever.
// ===========================================================================
void Cmd::print_using_words(stringstream &ss)
{
    for (int i=0; i<(int)words.size(); i++) {
        bool enc_quote = true;
        if (i == 0) enc_quote = false;
        ss << words[i].get_print_string(enc_quote) << " ";
    }
}

// ===========================================================================
// Another version of printing all the words on the line.
// This version is mainly for printing out the final cmds buffer.
//
// The output is formatted, commas are put back in, spaces are handled better,
// if a line is too long (see nctot_max), it is split into more than one line.
//
// For example, suppose the words on a line were
//     a4d ( 1 1 1 2 ) = -3.4 4.7 5.2 4.6e19
// spaces are used to delimit the words, but it is not very readable. This
// routine will print the above line as
//     a4d(1, 1, 1, 2) = -3.4, 4.7, 5.2, 4.6e19
// This has the added advantage that spaces can be eliminated and a compact
// form can be achieved.
//
// Another example is the line
//    strinsert_cmd01 = Use The Force
// The string "Use The Force" is actually one word, even though it appears to
// be three words. This routine prints this correctly as
//    strinsert_cmd01 = "Use The Force"
// ===========================================================================
void Cmd::print_using_words_fm(stringstream &ss)
{
    //debug_print_words("print_using_words_fm");
    int nctot_max = 75;
    int istart = 0;
    int ieq = -1;
    int ip1 = -1;
    int ip2 = -1;
    for (;;) {
        if (istart > 0) ss << "     ";
        int nctot = 0;
        bool done = false;
        for (int i=istart; i<(int)words.size(); i++) {
            bool enc_quote = true;
            if (i == 0) enc_quote = false;
            string s = words[i].get_print_string(enc_quote);
            if (s == "=") ieq = i;
            if (s == "(") ip1 = i;
            if (s == ")") ip2 = i;
            string sp = "";
            if (i<(int)words.size()-1) {
                sp = words[i+1].get_print_string(enc_quote);
            }
            if (sp == ")") ip2 = i+1;
            int nc = (int)s.size();
            if ((i>istart) && (nc+1+nctot > nctot_max)) {
                istart = i;
                break;
            }
            if (i >= (int)words.size()-1) {
                done = true;
                ss << s;
            }
            else {
                string endstr = " ";
                int endinc = 1;
                if (ieq > -1) {
                    if (i > ieq) {
                        endstr = ", ";
                        endinc = 2;
                    }
                }
                if (ip1 > -1 && (ip2 == -1 || i < ip2)) {
                    if (i > ip1 && (ip2 == -1 || i < ip2-1)) {
                        endstr = ", ";
                        endinc = 2;
                    }
                }                    
                if (endstr == " ") {
                    if (s == "(") {
                        endstr = "";
                        endinc = 0;
                    }
                    if (i == ip2-1) {
                        endstr = "";
                        endinc = 0;
                    }
                    if (i == 0 && sp == "(") {
                        endstr = "";
                        endinc = 0;
                    }
                }
                ss << s << endstr;
                nctot += nc + endinc;
            }
        }
        if (done) break;
        ss << endl;
    }
}


// ===========================================================================
// Print the original command before processing, mainly for debugging.
// Output is to a stringstream so the calling method can decide what to do
// with the output - send it to the screen, use it for testing, whatever.
// ===========================================================================
void Cmd::print_original_string(stringstream &ss)
{
    ss << original_str;
}


// ===========================================================================
// This is mainly for debugging this class. It prints on all procs.
// ===========================================================================
void Cmd::debug_print_words(string s)
{
    cout << s << endl;
    cout << "    ";
    for (int i=0; i<(int)words.size(); i++) {
        bool enc_quote = true;
        if (i == 0) enc_quote = false;
        cout << words[i].get_print_string(enc_quote) << " ";
    }
    cout << endl;
}






} // End of the PP namespace

