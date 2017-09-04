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

#ifndef CMDHHINCLUDE
#define CMDHHINCLUDE

// ***************************************************************************
// ***************************************************************************
// Generalized command class.
// ***************************************************************************
// ***************************************************************************

#include <string>
#include <deque>
#include <vector>
#include <map>
#include <sstream>
#include "Variable.hh"
#include "Function.hh"

namespace PP
{
using std::string;
using std::deque;
using std::vector;
using std::map;
using std::stringstream;

//class Variable;
//class Function;

class Cmd
{
public:
    Cmd();
    Cmd(string s, map<string, Variable> *v, map<string, Function> *f,
        deque<string> *lstr, int lnum, int file_lnum, string fname,
        stringstream &serr, int &ierr);

    void set_index_base(int base);
    void set_case_sensitive(bool case_sensitive_in);

    void add_word(string str, int lnum, int file_lnum, string fname);
    void erase_word(int iw);
    void erase_last_word();
    void reset_name_type();
    void delete_words(int i1, int i2);
    void check_ppmm(stringstream &serr, int &ierr);
    void remove_commas();
    void handle_two_words();
    bool check_input_end(bool kill_run, stringstream &serr, int &ierr);
    void print_duplicate_line(int iw, stringstream &ss, int fn_width,
                              int lnum_width, string after_lnum);
    void get_duplicate_sizes(int iw, int &fn_width, int &lnum_width);

    string get_cmd_filename(stringstream &ssfiles);
    void handle_quotes(stringstream &serr, int &ierr);
    void handle_exe_args(string &sout);
    void deprecated_input01(string action, stringstream &serr, int &ierr);
    void fatal_error(int iw, stringstream &serr, int &ierr);
    void warning(int iw, stringstream &serr, int &ierr);

    void get_bool_int(string &cname, int *array_vals, const vector<int> &size,
                      vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                      int dup_fatal, vector<int> &dup_vals,
                      bool skip, stringstream &serr, int &ierr);

    void get_bool(string &cname, bool *array_vals, const vector<int> &size,
                  vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                  int dup_fatal, vector<int> &dup_vals,
                  bool skip, stringstream &serr, int &ierr);

    void get_int(string &cname, int *array_vals, const vector<int> &size,
                 vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                 int dup_fatal, vector<int> &dup_vals,
                 bool skip, stringstream &serr, int &ierr);

    void get_int(string &cname, int64_t *array_vals, const vector<int> &size,
                 vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                 int dup_fatal, vector<int> &dup_vals,
                 bool skip, stringstream &serr, int &ierr);

    void get_real(string &cname, double *array_vals, const vector<int> &size,
                  vector<Cmd *> &dup_cmd1, vector<int> &dup_wdex1,
                  int dup_fatal, vector<int> &dup_vals,
                  bool skip, stringstream &serr, int &ierr);

    void get_char(string &cname, vector<string> &vstr, const vector<int> &size,
                  bool single_char, vector<Cmd *> &dup_cmd1,
                  vector<int> &dup_wdex1, int dup_fatal,
                  vector<int> &dup_vals, bool skip,
                  stringstream &serr, int &ierr);

    void get_size(vector<int> &size, stringstream &serr, int &ierr);
    void get_sizeb(vector<int> &size, stringstream &serr, int &ierr);

    // Handle unary minus and plus in command lines.
    void handle_cmd_unary_minus(stringstream &serr, int &ierr);
    void handle_cmd_unary_plus(stringstream &serr, int &ierr);

    // Handle multiplicity in command lines, i.e. a(1)=15*3.0
    void handle_cmd_multiplicity(stringstream &serr, int &ierr);

    // Handle variables.
    bool check_for_dimension(stringstream &serr, int &ierr);
    bool check_for_var_description(stringstream &serr, int &ierr);
    void substitute_variables(stringstream &serr, int &ierr);
    void set_variables(stringstream &serr, int &ierr);

    // Math evaluation.
    void math_eval(stringstream &serr, int &ierr);
    void check_misplaced_math(stringstream &serr, int &ierr);

    // Handle comments.
    void single_line_comments();
    void multi_line_comments(int &level);

    // Handle processed flags.
    void clear_processed();
    void set_processed(bool ip);
    void check_processed(bool &good, stringstream &serr, int &ierr);

    // If statements.
    void handle_if(bool &skip, deque<bool> &skip_level,
                   deque<bool> &satisfied, 
                   stringstream &serr, int &ierr);

    // Do loops.
    void handle_do(bool &skip, deque<int> &do_start, int &cdex,
                   bool &end_do_loop, stringstream &serr, int &ierr);
    bool find_matching_enddo(int &dlev, bool &stop_checking);

    // Subroutines
    void handle_subroutines(bool &skip,
                            bool &go_to_sub, string &sub_name,
                            bool &go_to_call,
                            stringstream &serr, int &ierr);
    bool find_subroutine(string &sub_name);
    void get_call_args(vector<string> &sargs, vector<bool> &sargs_isvar,
                       stringstream &serr, int &ierr);
    void get_sub_args(vector<string> &sargs, vector<bool> &sargs_isvar);
    void copy_call_args(vector<string> &sargs, vector<bool> &sargs_isvar);
    void copy_sub_args(vector<string> &sargs, vector<bool> &sargs_isvar);

    // Accessor functions.
    string get_cmd_name() { return cmd_name; }
    string get_cmd_type() { return cmd_type; }
    int get_nwords() { return words.size(); }
    string get_string(int iw) {
        if ((int)words.size() <= iw) return "";
        return words[iw].get_string();
    }
    string get_original_str() { return original_str; }

    int get_line_number(int iw) { return words[iw].get_line_number(); }
    int get_file_line_number(int iw) { return words[iw].get_file_line_number(); }
    string get_filename(int iw) { return words[iw].get_filename(); }
    string get_filename() { return filename; }
    deque<string> *get_lines() { return lines; }

    void set_filename(string fn) {
        filename = fn;
        for (int iw=0; iw<(int)words.size(); iw++) {
            words[iw].set_filename(fn);
        }
    }

    bool is_include() { if(words[0].get_string() == "include") return true;
                        return false; }

    // Debug
    void print_all_words();
    void print_all_words(stringstream &ss);
    void print_using_words(stringstream &ss);
    void print_using_words_fm(stringstream &ss);
    void print_original_string(stringstream &ss);


private:
    // Initialization method for this class.
    void init();

    void process_string(string in_str, stringstream &serr, int &ierr);
    bool extract_next_word(int &istart, string &str, string &word,
                           stringstream &serr, int &ierr);
    int find_closing_symbol(string opensym, string closesym, int i1);
    bool handle_innermost_parens(int &i1, int &i2, int &iwres, int &nargs,
                                 bool remp, stringstream &serr, int &ierr);
    void evaluate_function(int iw1, int &i2, int &nargs,
                           stringstream &serr, int &ierr);
    void seval(int &i1, int &i2, stringstream &serr, int &ierr);
    void handle_unary_op(int i1, int &i2, string utype,
                         stringstream &serr, int &ierr);
    void do_unary_op(int ip, string utype);
    void handle_star_star();  // ** exponentiation
    void handle_ops();

    void subvar_w0(int i1, int &i2, stringstream &serr, int &ierr);
    void subvar0(int vardex, string &varname, int increment,
                 stringstream &serr, int &ierr);
    bool evaluate_variable(int iw1, int &i2, int &nargs,
                           stringstream &serr, int &ierr);

    int find(int i1, int i2, string s);
    int find_last(string s, int i1, int i2);
    int find_any_char(int i1, int i2, string s);
    void replace_words(int i1, int i2, Word &w);
    void replace_words(int i1, int i2, vector<Word> &vw);
    void merge_words(int i1, int i2);
    bool separate_str(string &subs, string &fstr, vector<string> &vs);
    int find_equals();

    bool check_syntax(vector<int> &istart, stringstream &serr, int &ierr);
    bool get_nvals(vector<int> &istart, const vector<int> &size,
                   int &nvals, stringstream &serr, int &ierr);
    void debug_print_words(string s);

    void fatal_error2(stringstream &serr, int &ierr);
    void error_dup_line(string &cname, int wdex, int cdex,
                        vector<int> &dup_wdex1, vector<Cmd *> &dup_cmd1,
                        vector<int> &dup_vals, const vector<int> &size,
                        int dup_fatal, stringstream &serr, int &ierr);


    // This is needed for telling the user what line in the input
    // file or include file the error occurred on.
    //
    // line_number  The line_number corresponding to this command, this is
    //              an index into lines and starts from 1, not 0.
    // lines        Pointer to the deque of original lines. This contains all
    //              the lines from the input file and any include files.
    // file_line_number  The line number in the input file or include file.
    // filename          The name of the input file or include file.
    //
    // file_line_number and filename are needed to that the user can open
    // the file and go to the line in error.
    int line_number, file_line_number;
    string filename;
    deque<string> *lines;
    
    // index base, generally 1 for Fortran style and 0 for C/C++, default 1
    // int index_base; -- using static variable instead

    // The original string before processing.
    string original_str;

    // Pointer to the map of variables.
    map<string, Variable> *vmap;

    // Pointer to the map of functions.
    map<string, Function> *fmap;

    // Definitions of white space, delimiters, etc.
    string white_space;
    string delims;

    // Storage for all the words on the line.
    deque <Word> words;

    // The name and type of the command.
    string cmd_name;
    string cmd_type;

    // Used for subroutines.
    vector<string> call_args, sub_args;
    vector<bool> call_args_isvar, sub_args_isvar;
};


} // end of PP namespace

#endif

