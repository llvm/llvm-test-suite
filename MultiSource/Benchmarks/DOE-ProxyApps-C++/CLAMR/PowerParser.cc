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
// Provide a class that parses text files into lines and words.
// ***************************************************************************
// ***************************************************************************

#include "PowerParser.hh"
#include "Parser_utils.hh"
#include "Variable.hh"
#include "Function.hh"
#include <cctype>
#include <cstdio>
#include <unistd.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm>
#include <stdint.h>
#include <string.h>
#include <cstdlib>
#include <assert.h>

namespace PP
{
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::deque;
using std::map;
using std::pair;
using std::vector;
using std::stringstream;
using std::setw;
using std::setprecision;
using std::numeric_limits;

static int index_base = 1;
static bool case_sensitive = false;

// ===========================================================================
// Various constructors.
// ===========================================================================
PowerParser::PowerParser()
{
    comm = new Comm();

    init();                     // Init vars, setup functions, ...
    nrb_on_dump = 0;
    coutbuf = NULL;
}

PowerParser::PowerParser(string filename)
{
    comm = new Comm();

    init();                     // Init vars, setup functions, ...
    nrb_on_dump = 0;
    parse_file(filename);       // Parse the file.
    coutbuf = NULL;
}

PowerParser::PowerParser(const char *filename)
{
    comm = new Comm();

    string fstring(filename);

    init();                     // Init vars, setup functions, ...
    nrb_on_dump = 0;
    parse_file(fstring);        // Parse the file.
    coutbuf = NULL;
}

// ===========================================================================
// Destructor
// ===========================================================================
PowerParser::~PowerParser()
{
    fileout.close();
    if (coutbuf != NULL) cout.rdbuf(coutbuf); // restore cout's original streambuf
    delete comm;

    cmd_strings.clear();
    vmap.clear();
    fmap.clear();
    cmds.clear();
    cmdsf.clear();
    whenthens.clear();
    restartblocks.clear();
    pre_defined_varss.str("");
}

// ===========================================================================
// Parse a file. The basic strategy is to read the file into a string on the
// io processor, broadcast the string to all the other processors, then parse
// the string.
// ===========================================================================
void PowerParser::parse_file(string filename)
{
    // Read the file into a string. This simply copies every character in
    // the file to the string including end of line characters.
    // Note that only the io processor reads the file into the string.
    string s_in = "";
    read_into_string(filename, s_in);

    // Broadcast the buffer string to all the other processors. After this
    // braodcast, all the processors should have the same buffer string.
    broadcast_buffer(s_in);

    // Parse the string. After this is done, the parser is ready to be used
    // by the application code.
    parse_string(filename, s_in);
}

void PowerParser::parse_file(const char *filename)
{
    string fstring(filename);
    parse_file(fstring);
}

int PowerParser::NumIncludeFiles()
{
    return IncludeFiles.size();
}

string PowerParser::GetIncludeFile(int i)
{
    if (0 <= i && i < IncludeFiles.size()) return IncludeFiles[i];
    return string("");
}

void PowerParser::ListIncludeFiles()
{
    int i, num_include;
    num_include = NumIncludeFiles();
    std::cerr << "Number of include files = " << num_include << "\n";
    for (i = 0; i < num_include; ++i)
    {
        std::cerr << "Include file << "<< i << " = " << GetIncludeFile(i) << "\n";
    }
}

// ===========================================================================
// Given a multi-line string on every processor, parse it into cmds and words.
// After calling this function, the parser is ready for use.
// ===========================================================================
void PowerParser::parse_string(string filename, string buffer)
{
    // Get command lines from the buffer and store them as strings.
    int current_pos = 0;
    string sline1 = "";
    string sline = "";
    int file_line_number = 0;
    bool exe_args_inserted = false;
    for (;;) {
        // Get the next line from the buffer. No processing is done, just
        // get each line. This does, however, remove the end of line
        // characters (either \r\n or only \n) from the string.
        if (!get_line_from_string(buffer, sline1, current_pos)) break;
        line_number += 1;
        file_line_number += 1;

        // Store the line without any processing. This is done so that a
        // fortran routine can get each original line and echo it to an
        // output file.
        cmd_strings.push_back(sline1);

        // The line, sline1, may be composed of sub-lines separated by
        // semicolons. Loop through the line extracting each semicolon
        // separated sub-line and process it.
        int current_sc_pos = 0;
        for (;;) {
            if (!get_sc_line_from_string(sline1, sline, current_sc_pos)) break;

            // Flag for making the command or not.
            bool make_cmd = true;

            // Get rid of leading and trailing blanks and tabs.
            eliminate_white_space(sline);

            // If after removing white space, the resulting line string is empty,
            // then do not turn it into a command.
            if ((int)sline.size() == 0) make_cmd = false;

            // Turn the line into a command. This creates the words. Empty lines
            // can be skipped.
            if (make_cmd) {
                stringstream serr;
                int ierr = 0;
                Cmd cmd(sline, &vmap, &fmap, &cmd_strings,
                        line_number, file_line_number, filename, serr, ierr);
                process_error(serr, ierr);
                if (cmd.get_string(0) == "set_index_base_zero") {
                   // C/C++ index convention
                   cmd.set_index_base(0);
                   Variable v(0);
                   index_base = 0;
                }
                if (cmd.get_string(0) == "set_index_base_one") {
                   // Fortran index convention
                   cmd.set_index_base(1);
                   Variable v(1);
                   index_base = 1;
                }
                if (cmd.get_string(0) == "set_case_sensitive") {
                   cmd.set_case_sensitive(true);
                   case_sensitive = true;
                }
                if (cmd.get_string(0) == "set_case_insensitive") {
                   cmd.set_case_sensitive(false);
                   case_sensitive = false;
                }
                if (cmd.get_string(0) == "put_exe_args_here") {
                    if (exe_args_str != "") {
                        parse_string("execution line arguments", exe_args_str);
                        exe_args_inserted = true;
                    }
                }
                else if (cmd.is_include()) {
                    string fname = "";
                    stringstream ssfiles;
                    if(comm->isIOProc()) {
                        fname = cmd.get_cmd_filename(ssfiles);
                    }
                    broadcast_buffer(fname);
		    map<int,string>::iterator ifp;
		    int isize = IncludeFiles.size();
		    IncludeFiles[isize] = fname;
                    if (fname == "") {
                        stringstream serr;
                        serr << endl;
                        serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
                        serr << "    " << cmd_strings[line_number-1] << endl;
                        serr << "in file: " << filename << endl;
                        serr << "Could not open include file." << endl;
                        serr << "The name of the file and any alternates are:" << endl;
                        serr << ssfiles.str() << endl;
                        int ierr = 2;
                        process_error(serr, ierr);
                        return;
                    }
                    parse_file(fname);
                }
                else {
                    cmds.push_back(cmd);                
                }
            }
        }
    }
    // process inserted command line args if not parsing just the args
    if (filename != "execution line arguments" && 
        filename != "exe_args_tmp" &&
        exe_args_str != "") {
      // if inserting manually, remove the tmp insertion at the beginning
      if (exe_args_inserted) {
        for (int i=0; i<(int)cmds.size(); i++) {
          if (cmds[i].get_filename() == "exe_args_tmp") {
            cmds.erase(cmds.begin()+i);
            i -= 1;
          }
        }
      }
      // change the file name to the real name for args
      else {
        for (int i=0; i<(int)cmds.size(); i++) {
          if (cmds[i].get_filename() == "exe_args_tmp") {
            cmds[i].set_filename("execution line arguments");
          }
        }
      }
    }
}


// ===========================================================================
// Handle the execution line arguments.
// ===========================================================================
void PowerParser::handle_exe_args(string other_args)
{
    if ((int)other_args.size() == 0) return;

    stringstream serr;
    int ierr = 0;
    Cmd cmd(other_args, &vmap, &fmap, &cmd_strings,
            1, 1, "", serr, ierr);
    process_error(serr, ierr);
    //print_line(cmd);
    exe_args_str = "";
    cmd.handle_exe_args(exe_args_str);
    if (cmd.get_nwords() == 0) {
        exe_args_str = "";
        return;
    }
    parse_string("exe_args_tmp", exe_args_str);
}


// ===========================================================================
// Clear out the parser and re-init.
// ===========================================================================
void PowerParser::clear_and_init()
{
    // comm does not need to be reset
    cmd_strings.clear();
    vmap.clear();
    fmap.clear();
    cmds.clear();
    cmdsf.clear();
    whenthens.clear();
    restartblocks.clear();
    pre_defined_varss.str("");

    // Do not clear out the restart block info from the dump since the whole
    // point of doing this function is to be able to reset the parser with
    // the restart block info from the dump.

    //for (int i=0; i<(int)bnames_on_dump.size(); i++) {
    //    cout << "&&&&&cw PowerParser.cc, clear_and_init, bnames_on_dump = " <<
    //        bnames_on_dump[i] << endl;
    //    cout << "&&&&&cw PowerParser.cc, clear_and_init, baflags_on_dump = " <<
    //        baflags_on_dump[i] << endl;
    //}

    // Do the initialization again.
    init();
}

// ===========================================================================
// Echo user input to a stringstream.
// ===========================================================================
void PowerParser::echo_input_start()
{
    ssfout.str("");
    echo_input_ss(ssfout);
    ssfout_current_pos = 0;
}
void PowerParser::echo_input_ss(stringstream &ssinp)
{
    if (!comm->isIOProc()) return;
    for (int i=0; i<(int)cmd_strings.size(); i++) {
        ssinp << cmd_strings[i] << endl;
    }
}


// ===========================================================================
// The input file(s) has been read and put into commands. Now do the
// compilation phase.
// ===========================================================================
void PowerParser::compile_buffer(int &return_value)
{
    // At this point, the list of variables only contains the pre-defined
    // parser variables, thus if we list the variables at this point we will
    // have a list of only the pre-defined variables. This is stored in a
    // stringstream to be printed later.
    string lv1 = "********** List of pre-defined parser variables";
    string lv2 = "********** End list of pre-defined parser variables";
    list_vars_ss(lv1, lv2, "", pre_defined_varss);

    int return_local;

    return_local =-1;
    return_value = 0;

    // Handle single line (! and //) comments and multi line
    // comments (/* ... */)
    // The level variable is used for nested multi line comments.
    int level = 0;
    for (int i=0; i<(int)cmds.size(); i++) {
        cmds[i].single_line_comments();
        cmds[i].multi_line_comments(level);
    }

    // Check for matching quotes and remove them.
    int ierr = 0;
    stringstream serr;
    for (int i=0; i<(int)cmds.size(); i++) {
        cmds[i].handle_quotes(serr, ierr);
    }
    return_local = process_error_return_int(serr, ierr);
    return_value = return_local;

    if (return_local > 0) {
       cout << "handle quotes gave error " << ierr << endl;
       if (return_local > 1) return;
    }

    // Remove empty lines.
    for (int i=0; i<(int)cmds.size(); i++) {
        if (cmds[i].get_nwords() == 0) {
            cmds.erase(cmds.begin()+i);
            i -= 1;
            continue;
        }
    }

    // Handle continuation lines (ending in & or ,).
    // Continuation lines are merged into one long (possibly very long)
    // line.
    for (int i=(int)cmds.size()-1; i>=0; i--) {
        int nw1 = cmds[i].get_nwords();
        if (cmds[i].get_string(nw1-1) == "&" ||
            cmds[i].get_string(nw1-1) == ",") {
            if (cmds[i].get_string(nw1-1) == "&")
                cmds[i].erase_word(nw1-1);
            int nw2 = cmds[i+1].get_nwords();
            for (int j=0; j<nw2; j++) {
                cmds[i].add_word(cmds[i+1].get_string(j),
                                 cmds[i+1].get_line_number(j),
                                 cmds[i+1].get_file_line_number(j),
                                 cmds[i+1].get_filename(j)
                                 );
            }
            cmds.erase(cmds.begin()+i+1);
            continue;
        }
    }


    // Reset the command name and type. Consider the following command:
    //      * lasdkj */ cmd = 5.0
    // The original command name is "*", but after the multi-line comment is
    // removed, the command name should be "cmd".
    for (int i=0; i<(int)cmds.size(); i++) {
        cmds[i].reset_name_type();
    }


    // Debug: print each command.
    //for (int i=0; i<(int)cmds.size(); i++) {
        //stringstream ss3;
        //cmds[i].print_all_words(ss3);
        //cmds[i].print_using_words(ss3);
        //cmds[i].print_original_string(ss3);
        //cout << ss3.str() << endl;

        //cout << "Command name = " << cmds[i].get_cmd_name() << endl;
        //cout << "Command type = " << cmds[i].get_cmd_type() << endl;
    //}
    //cout << endl;

    // Handle all the variable dimension statements.
    ierr = 0;
    serr.str("");
    for (int i=0; i<(int)cmds.size(); i++) {
        if (cmds[i].check_for_dimension(serr, ierr)) {
            cmds.erase(cmds.begin()+i);
            i--;
            continue;
        }            
    }
    return_local = process_error_return_int(serr, ierr);

    if (return_local > 0) {
       cout << "handle variable dimension statement has error " << ierr << endl;
       if (return_local > 1) return;
    }

    // Combine things like "end if" into one word, i.e. "endif".
    for (int i=0; i<(int)cmds.size(); i++) {
        cmds[i].handle_two_words();
    }

    // Handle the case of a space between digits and the e for reals.
    // For example, in the following,
    //     1.0, 2.3 e14, -5.6
    // there is a space between 2.3 and e14 which should most likely
    // be treated as a single number, 2.3e14.
    ierr = 0;
    serr.str("");
    string action = "error";
    bool action_set = false;
    for (int i=0; i<(int)cmds.size(); i++) {
        if (cmds[i].get_cmd_name() == "depcmd_dse") {
            action = cmds[i].get_string(1);
            action_set = true;
            cmds.erase(cmds.begin()+i);
            i--;
            continue;
        }
        if (cmds[i].get_cmd_name() == "matdef") {
            if (!action_set) action = "fix";
        }
        cmds[i].deprecated_input01(action, serr, ierr);
    }

    return_local = process_error_return_int(serr, ierr);
    return_value = return_local;
    if (return_local > 0) {
       cout << "handle space between digits has error " << ierr << endl;
       if (return_local > 1) return;
    }


    // This is the main loop where most everything is done.
    bool print_final_buffer = false;
    deque<bool> skip_level;
    deque<bool> satisfied;
    deque<int> do_start;
    string sub_name = "";
    deque<int> icall, isub;
    bool skip_sub = false;
    int nwhen = 0;
    int when_level = 0;
    bool single_line_when = false;
    int nrb = 0;                       // Number of restart blocks
    bool single_line_rb = false;       // Flag for single line restart blocks
    bool skiprb = false;               // Flag for skipping cmds in restart block
    for (int i=0; i<(int)cmds.size(); i++) {
        // Work with cmdi, so that cmds will be available for do loops.
        Cmd cmdi = cmds[i];
        //print_line(cmdi);

        if (cmdi.get_cmd_name() == "parser_redirect_to_file") {
            string fname;
            int nw = cmdi.get_nwords();
            if (nw > 1) {
               fname = cmdi.get_string(1);
            } else {
               fname = "parser.out";
            }
            if (comm->isIOProc()) {
               //cout << "DEBUG fname is " << fname << endl;
               //cout << "Redirecting output to file" << endl;
               cout.flush();
               coutbuf = cout.rdbuf();
               fileout.open(fname.c_str());
               cout.rdbuf(fileout.rdbuf());
               //cout << "Start of output to file" << endl;
            }

            continue;
        }

        // Handle restart_block commands.
        if (cmdi.get_string(0) == "restart_block") {
            Restartblock rb(nrb, cmdi, skiprb, single_line_rb, 
                            bnames_on_dump, baflags_on_dump,
                            rbsatprb_on_dump, rbsat_on_dump,
                            serr, ierr);
            restartblocks.push_back(rb);

            for (int rbi=0; rbi<(int)restartblocks.size(); rbi++) {
                string rbi_name = restartblocks[rbi].get_name();
                for (int rbj=rbi+1; rbj<(int)restartblocks.size(); rbj++) {
                    if (rbi_name == restartblocks[rbj].get_name()) {
                        cmdi.fatal_error(0, serr, ierr);
                        serr << "Restart block names must be unique." << endl;
                        serr << "Non unique name = " << rbi_name << endl;
                        ierr = 2;
                    }
                }
            }

            if (single_line_rb && skiprb) {
                skiprb = false;
                continue;
            }
            bool cflag = true;
            if (single_line_rb && !skiprb) cflag = false;
            if (cflag) continue;
        }
        if (cmdi.get_string(0) == "end_restart_block") {
            skiprb = false;
            continue;
        }
        if (skiprb) continue;


        if (skip_sub) {
            if (cmdi.get_string(0) == "endsubroutine") {
                skip_sub = false;
                //cout << "endsubroutine found, turning skip_sub to false" << endl;
            }
            continue;
        }

        return_local = ierr;
        return_value = return_local;
        if (return_local > 0) {
           if (return_local > 1) return;
        }
     


        // List variables, functions, etc.
        if (cmdi.get_cmd_name() == "parser_list_variables") {
            string lv1 = "********** Debugging: list variable names and values "
                "available in input file.";
            string lv2 = "********** Debugging END: list variable names and values";
            string var_to_list = "";
            int nw = cmdi.get_nwords();
            if (nw > 1) var_to_list = cmdi.get_string(1);
            if (comm->isIOProc()) cout << endl;
            list_vars(lv1, lv2, var_to_list);
            if (comm->isIOProc()) cout << endl;
            continue;
        }
        if (cmdi.get_cmd_name() == "parser_list_functions") {
            string lf1 = "********** Debugging: list function names available in input file.";
            string lf2 = "********** Debugging END: list function names.";
            if (comm->isIOProc()) cout << endl;
            list_funcs(lf1, lf2);
            if (comm->isIOProc()) cout << endl;
            continue;
        }
        if (cmdi.get_cmd_name() == "parser_print_fbuffer") {
            print_final_buffer = true;
            continue;
        }

        // Handle when ... then commands.
        string wtcmd = cmdi.get_string(0);
        if (wtcmd == "when" || wtcmd == "whenever") {
            bool skipwhen = true;
            bool ever_flag = false;
            if (wtcmd == "whenever") ever_flag = true;
            Whenthen wt(nwhen, cmdi, skipwhen, single_line_when, ever_flag, serr, ierr);
            when_level += 1;
            whenthens.push_back(wt);
            if (skipwhen) continue;
        }
        if (cmdi.get_string(0) == "endwhen") {
            when_level -= 1;
            if (when_level < 0) {
                cmdi.fatal_error(0, serr, ierr);
                serr << "Extra endwhen (or end when) found with no matching "
                        "when command." << endl;
                serr << "Make sure every when command has one and only one"
                     << endl << "matching endwhen command." << endl;
                ierr = 2;
            }
            return_local = ierr;
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "handle endwhen " << ierr << endl;
                 return;
             }
             continue;
        }


        // Handle if/elseif/else/endif statements.
        bool skip = false;
        cmdi.handle_if(skip, skip_level, satisfied, serr, ierr);
        if (skip) continue;

        // Handle do loops. Note that we terminate if there is an error to
        // avoid the possibility of an infinite loop.
        int cdex = i;
        bool end_do = false;
        int ierr2 = 0;
        cmdi.handle_do(skip, do_start, cdex, end_do, serr, ierr2);
        if (ierr2 == 2) {
            ierr = 2;
            return_local = ierr;
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "handle endwhen " << ierr << endl;
             }
            break;
        }
        if (end_do) {
            if (!end_do_loop(i, do_start, serr, ierr)) break;
            continue;
        }
        i = cdex;
        if (skip) continue;

        // Handle call/subroutines.
        bool go_to_sub = false;
        bool go_to_call = false;
        cmdi.handle_subroutines(skip, go_to_sub, sub_name, go_to_call,
                                serr, ierr);
        if (go_to_call) {
            end_do_ret(i, do_start, serr, ierr);
            return_local = jump_to_call(i, icall, isub, serr, ierr);
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "jump_to_call error " << ierr << endl;
             }
            continue;
        }

        if (go_to_sub) {
            icall.push_back(i);
            return_local = jump_to_sub(i, sub_name, serr, ierr);
            isub.push_back(i);
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "jump_to_sub error " << ierr << endl;
             }
            continue;
        }

        if (cmdi.get_string(0) == "subroutine") {
            //cout << "subroutine found!!!, turning skip_sub to true" << endl;
            skip_sub = true;
            continue;
        }

        // Check for a variable description command. If found we set the description,
        // then go to the next line.
        if (cmdi.check_for_var_description(serr, ierr)) continue;

        // Stop if we hit a stop command or a fatal_error command
        bool kill_run = false;
        if (cmdi.check_input_end(kill_run, serr, ierr)) {
            // Killing the calculation will be done, for example, if the user
            // issues a fatal_error command.
            if (kill_run) {
                return_local = process_error_return_int(serr, ierr);
               if (return_local > return_value) {
                   return_value = return_local;
               }
               if (return_local > 0) {
                    cout << "handle endwhen " << ierr << endl;
                    if (return_local > 1) return;
                }
            }
            
            // Clear out all do's so we don't get an error about unmatched
            // do/enddo.
            do_start.clear();
            break;
        }

        cmdi.math_eval(serr, ierr);
        cmdi.substitute_variables(serr, ierr);   // Sub vars not in math expressions.
        cmdi.check_ppmm(serr, ierr);             // All ++, -- should be gone.
        cmdi.remove_commas();
        cmdi.handle_cmd_unary_minus(serr, ierr);
        cmdi.handle_cmd_unary_plus(serr, ierr);
        cmdi.handle_cmd_multiplicity(serr, ierr);
        cmdi.check_misplaced_math(serr, ierr);
        cmdi.set_variables(serr, ierr);

        // Copy the command to the final commands deque.
        if (cmdi.get_cmd_type() == "command") {
            if (when_level > 0) {
                whenthens[nwhen-1].add_cmdf(cmdi);
                if (single_line_when) {
                    when_level -= 1;
                    single_line_when = false;
                }
            }
            else {
                cmdsf.push_back(cmdi);
            }
        }
    }
    // Print error messages and terminate if fatal.
    return_local = process_error_return_int(serr, ierr);
    if (return_local > return_value) {
        return_value = return_local;
    }
    if (return_local > 0) {
        return_value = return_local;
        if (return_local > 1) return;
    }

    // Check that an enddo was found for every do.
    check_enddo(do_start, serr, ierr);

    // Print error messages and terminate if fatal.
    return_local = process_error_return_int(serr, ierr);
    if (return_local > return_value) {
        return_value = return_local;
    }
    if (return_local > 0) {
        return_value = return_local;
        if (comm->isIOProc()) {
           cout << "handle enddo is wrong with err " << ierr << endl;
        }
        if (return_local > 1) return;
    }

    // Set the processed flag in every word in every command to be false.
    // At the end of parsing, if any word has not been processed in some way,
    // then that is a fatal error.
    for (int i=0; i<(int)cmdsf.size(); i++) {
        cmdsf[i].clear_processed();
    }

    // If this is a recreate of the parser, then there might be some commands 
    // that have already been processed, set these.
    cmd_set_reprocessed(true);

    // Check and print duplicate scalar commands.
    // Remove duplicate scalar commands.
    // Process the duplicate_array_values command.
    return_local = process_dav_cmd();
    if (return_local > return_value) {
        return_value = return_local;
    }
    if (return_local > 0) {
        if (comm->isIOProc()) {
           cout << "Checked for  duplicate arrays and error is " << return_local << endl;
        }
    }
    //check_duplicates();

    // Debug: print each of the final commands to the screen.
    if (print_final_buffer) {
        if (comm->isIOProc()) {
            cout << "********************************************************************************\n"
                 << "********** Echo final parser buffer, this is what the code uses to set internal \n" 
                 << "********** code variables." << endl;
            list_cmdsf("", "");
            cout << "********** End of echo final parser buffer.\n" 
                 << "********************************************************************************\n\n" 
                 << endl;

            cout << "********************************************************************************\n"
                 << "********** Echo final when...then parser buffers, this is what the code uses to \n"
                 << "********** set internal code variables when processing when...then commands." << endl;
            list_wt_cmdsf();
            cout << "********** End of echo final when...then parser buffers.\n"
                 << "********************************************************************************\n\n" 
                 << endl;

            cout << "********************************************************************************\n"
                 << "********** Echo restart block information." << endl;
            list_rb();
            cout << "********** End of echo restart block information.\n"
                 << "********************************************************************************\n\n"
                 << endl;
        }
    }

    // Return the to the calling program

    return;
}


// ===========================================================================
// A "endsubroutine" or "return" command has been found. Jump back to the call
// statement. This sets the loop index i so that we end up on the line after
// the call.
// ===========================================================================
int PowerParser::jump_to_call(int &i, deque<int> &icall, deque<int> &isub,
                         stringstream &serr, int &ierr)
{
    int return_value;
    int return_local;
    return_value = 0;
    return_local = 0;

    int icsize = (int)icall.size();
    if (icsize == 0) {
        cmds[i].fatal_error(0, serr, ierr);
        serr << "icall size = 0, this should never happen." << endl;
        ierr = 2;
        return_value = process_error_return_int(serr, ierr);
        if (return_local > return_value) {
           return_value = return_local;
        }
        if (return_local > 0) {
             cout << "jump_to_call icall  error " << ierr << endl;
             if (return_local > 1) return return_value;
        }
    }
    i = icall[icsize-1];
    icall.erase(icall.begin()+icsize-1);

    vector<string> call_args;
    vector<bool> call_args_isvar;
    cmds[i].copy_call_args(call_args, call_args_isvar);
    int idex_sub = isub[(int)isub.size()-1];
    vector<string> sub_args;
    vector<bool> sub_args_isvar;
    cmds[idex_sub].copy_sub_args(sub_args, sub_args_isvar);
    //cout << "jump_to_call, sub args, then call args" << endl;
    //for (int j=0; j<(int)sub_args.size(); j++) {
    //    cout << sub_args[j] << endl;
    //}
    //for (int j=0; j<(int)call_args.size(); j++) {
    //    cout << call_args[j] << endl;
    //}
    //cout << "--------------------------------" << endl;

    for (int j=0; j<(int)sub_args.size(); j++) {
        string sub_var = sub_args[j];
        string call_var = call_args[j];

        map<string, Variable>::iterator psub;
        psub = vmap.find(sub_var);
        string sub_value = "";
        if (psub != vmap.end()) {
            sub_value = psub->second.get_var_value();
        }
        else {
            cmds[i].fatal_error(0, serr, ierr);
            serr << "Subroutine argument not found." << endl;
            serr << "This should not happen." << endl;
            ierr = 2;
            return_value = process_error_return_int(serr, ierr);
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "jump_to_call Subroutine argument not found " << endl;
                 if (return_local > 1) return return_value;
            }
        }

        if (!call_args_isvar[j]) {
            if (sub_value != call_var) {
                cmds[i].fatal_error(0, serr, ierr);
                cmds[isub[(int)isub.size()-1]].fatal_error(0, serr, ierr);
                serr << "The calling argument, argument number " << j+1
                     << ", (after any math eval) is " << call_var << endl;
                serr << "The corrseponding subroutine dummy argument, "
                     << sub_var << ", has"
                     << " the value of " << sub_value << endl;
                serr << "These are different and should not be." << endl;
                serr << "The calling argument is not a variable and thus" 
                     " is fixed and cannot be changed." << endl;
                serr << "The dummy argument was changed in the subroutine," << endl;
                serr << "thus you are trying to change a fixed quantity which" 
                     " is not allowed." << endl;
                ierr = 2;
                return_value = process_error_return_int(serr, ierr);
                if (return_local > return_value) {
                   return_value = return_local;
                }
                if (return_local > 0) {
                     cout << "jump_to_call subroutine arguments errors " << endl;
                     if (return_local > 1) return return_value;
            }
            }
        }
        else {
            map<string, Variable>::iterator pcall;
            pcall = vmap.find(call_var);
            if (pcall != vmap.end()) {
                pcall->second = psub->second;
                pcall->second.set_temporary(false);
                pcall->second.set_varname(call_var);
            }
            else {
                cmds[i].fatal_error(0, serr, ierr);
                serr << "Calling argument not found." << endl;
                serr << "This should not happen." << endl;
                ierr = 2;
                return_value = process_error_return_int(serr, ierr);
                if (return_local > return_value) {
                   return_value = return_local;
                }
                if (return_local > 0) {
                     cout << "jump_to_call calling argument not found " << endl;
                     if (return_local > 1) return return_value;
                }
            }
        }

    }

    // Erase temporary variables.
    // There should be a better way to do this.
    map<string, Variable>::iterator p;
    for (;;) {
        bool erase_done = false;
        for(p = vmap.begin(); p != vmap.end(); p++) {
            if (p->second.is_temporary()) {
                vmap.erase(p);
                erase_done = true;
                break;
            }
        }
        if (!erase_done) break;
    }

    // Remove the index to the subroutine line.
    isub.erase(isub.begin()+(int)isub.size()-1);

    return return_value;

}  // End of jump_to_call


// ===========================================================================
// A "call" command has been found. Find the subroutine it is trying to call
// and set the loop index, i, to the subroutine line so we will end up on the
// line after the subroutine.
// ===========================================================================
int PowerParser::jump_to_sub(int &i, string &sub_name,
                        stringstream &serr, int &ierr)
{
    int return_value;
    int return_local;
    return_value = 0;
    return_local = 0;

    // At this point, i is the index for the call line.
    //cout << "&&&&&cw PowerParser loop, jump_to_sub, i=" << i << endl;

    // Find the line index, cdex, for the subroutine.
    int cdex = -1;
    for (int j=0; j<(int)cmds.size(); j++) {
        if (cmds[j].find_subroutine(sub_name)) {
            cdex = j;
            break;
        }
    }

    if (cdex == -1) {
        cmds[i].fatal_error(0, serr, ierr);
        serr << "Subroutine " << sub_name << " not found." << endl;
        ierr = 2;
        return_value = process_error_return_int(serr, ierr);
        if (return_local > return_value) {
           return_value = return_local;
        }
        if (return_local > 0) {
             cout << "Subroutine name not found " << ierr << endl;
             if (return_local > 1) return return_value;
        }
    }

    // Get the calling arguments. This will potentially be a mix
    // of variable names and numbers. This does not modify the words
    // in cmds[i], but it does store the call arguments in cmds[i].
    vector<string> call_args;
    vector<bool> call_args_isvar;
    cmds[i].get_call_args(call_args, call_args_isvar, serr, ierr);
    //for (int j=0; j<(int)call_args.size(); j++) {
    //    cout << call_args[j] << endl;
    //}

    // Get the subroutine arguments.
    // This does not modify the words in cmds[cdex], but it does store
    // the subroutine arguments in cmds[cdex]
    //print_line(cdex);
    vector<string> sub_args;
    vector<bool> sub_args_isvar;
    cmds[cdex].get_sub_args(sub_args, sub_args_isvar);
    //for (int j=0; j<(int)sub_args.size(); j++) {
    //    cout << sub_args[j] << endl;
    //}

    // Error checking.
    int ncall_args = (int)call_args.size();
    int nsub_args = (int)sub_args.size();
    if (ncall_args != nsub_args) {
        cmds[i].fatal_error(0, serr, ierr);
        cmds[cdex].fatal_error(0, serr, ierr);
        serr << "Number of calling arguments = " << ncall_args << endl;
        serr << "Number of subroutine arguments = " << nsub_args << endl;
        serr << "These must be the same." << endl;
        ierr = 2;
        return_local = process_error_return_int(serr, ierr);
        if (return_local > return_value) {
           return_value = return_local;
        }
        if (return_local > 0) {
             cout << "Arguments in subroutine and in calling are different " << ierr << endl;
             if (return_local > 1) return return_value;
        }
    }

    for (int j=0; j<(int)sub_args.size(); j++) {
        if (!sub_args_isvar[j]) {
            cmds[cdex].fatal_error(0, serr, ierr);
            serr << "Subroutine dummy arguments must always be variables." << endl;
            serr << "Argument " << j+1 << ", " << sub_args[j] << ", "
                 << "is not a variable." << endl;
            serr << "Remember that variables always begin with a" 
                " dollar sign, $" << endl;
            serr << "Note that putting quotes around a variable name makes it" << endl;
            serr << "a string, not a variable." << endl;
            ierr = 2;
            return_local = process_error_return_int(serr, ierr);
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "Dummy arguments must be variables " << ierr << endl;
                 if (return_local > 1) return return_value;
            }
        }
    }


    // Define new, temporary variables for the subroutine dummy arguments.
    // Set their values to the call values.
    for (int j=0; j<(int)sub_args.size(); j++) {
        string sub_vname = sub_args[j];
        string call_vname = call_args[j];

        // Find the subroutine variable name in the variable map.
        map<string, Variable>::iterator psub;
        psub = vmap.find(sub_vname);

        if (psub != vmap.end()) {
            cmds[cdex].fatal_error(0, serr, ierr);
            serr << "Argument " << j+1 << ", " << sub_args[j] << ", "
                 << "is both a global variable and a dummy subroutine argument." << endl;
            serr << "This is not allowed, dummy subroutine arguments "
                "cannot also be" << endl;
            serr << "global variables." << endl;
            ierr = 2;
            return_local = process_error_return_int(serr, ierr);
            if (return_local > return_value) {
               return_value = return_local;
            }
            if (return_local > 0) {
                 cout << "Dummy argument cannot be global variable " << ierr << endl;
                 if (return_local > 1) return return_value;
            }
        }
        else {
            // If the calling argument is a variable, then we set the
            // temporary variable equal to the calling variable. This passes
            // in the correct value, but it also passes in arrays, and
            // whatever characteristics the calling variable has.
            //
            // If the calling argument is not a variable, then we just
            // create the new, temporary variable and give it the calling
            // argument as its value.
            if (call_args_isvar[j]) {
                map<string, Variable>::iterator pcall;
                pcall = vmap.find(call_vname);
                if (pcall != vmap.end()) {
                    Variable v = pcall->second;
                    v.set_varname(sub_vname);
                    v.set_temporary(true);
                    vmap.insert(pair<string, Variable>(v.get_varname(), v));
                }
                else {
                    // FATAL ERROR
                    // calling argument variable not defined.
                }
            }
            else {
                vector<int> istart(0,0);
                vector<string> valvec;
                valvec.push_back(call_vname);
                int lnum = cmds[cdex].get_line_number(0);
                int file_lnum = cmds[cdex].get_file_line_number(0);
                string fname = cmds[cdex].get_filename(0);
                Variable v(sub_vname, istart, valvec, lnum, file_lnum,
                           fname, &cmd_strings, serr, ierr);
                v.set_temporary(true);
                vmap.insert(pair<string, Variable>(v.get_varname(), v));
            }

        }
    }

    // Set the loop index to the index of the subroutine so we
    // will end up at the line after the subroutine line.
    i = cdex;
    return return_value;
}  // End of jump_to_sub




// ===========================================================================
// End a do loop. This happens when a do loop has gone through all its
// iterations or when an exit statment is encountered.
// Basically, find the matching enddo  and continue after that statement.
// ===========================================================================
bool PowerParser::end_do_loop(int &i, deque<int> &do_start,
                        stringstream &serr, int &ierr)
{
    int rtvl = 0;
    // Find the matching enddo.
    // Stop checking will be true if we are in main and hit a subroutine
    // statement or if we are in a subroutine and hit an endsubroutine
    // statement.
    int cdex = -1;
    int dlev = 1;
    for (int j=i+1; j<(int)cmds.size(); j++) {
        bool stop_checking = false;
        if (cmds[j].find_matching_enddo(dlev, stop_checking)) {
            cdex = j;
            break;
        }
        if (stop_checking) break;
    }

    // If the matching enddo was not found then that is a fatal error.
    int nlevels = (int)do_start.size();
    if (cdex == -1) {
        if (nlevels > 0) {
            int ido = do_start[nlevels-1];
            cmds[ido].fatal_error(0, serr, ierr);
        }
        serr << "No enddo found for do statement." << endl;
        ierr = 2;
        rtvl = process_error_return_int(serr, ierr);
        if (rtvl > 0) cout << "Enddo not found " << endl;
        return false;
    }

    // We are done with this do loop, so we can get rid of the reference
    // to it.
    if (nlevels > 0) {
        do_start.erase(do_start.begin()+nlevels-1);
    }

    // Set the loop index to the enddo statement so that we will start
    // processing immediately after the enddo.
    i = cdex;
    return true;
} // End end_do_loop


// ===========================================================================
// A return statement in a subroutine has been encountered. We need to handle
// the do loops before returning to the call statement, otherwise the code
// will complain about do loops without enddo statements.
// This routine searches from the return statement to the endsubroutine
// statement, finds any free enddo's and erases the corresponding references
// to the do statements.
// ===========================================================================
void PowerParser::end_do_ret(int &i, deque<int> &do_start,
                       stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    //assert(serr == serr);
    assert(ierr == ierr);

    int istart = i;
    for (;;) {

        // Find an enddo.
        // Stop checking will be true if we are in main and hit a subroutine
        // statement or if we are in a subroutine and hit an endsubroutine
        // statement.
        int cdex = -1;
        int dlev = 1;
        bool stop_checking = false;
        for (int j=istart; j<(int)cmds.size(); j++) {
            if (cmds[j].find_matching_enddo(dlev, stop_checking)) {
                cdex = j;
                istart = j+1;
                break;
            }
            if (stop_checking) break;
        }

        // If we don't find an enddo, then we are done.
        if (cdex == -1) break;
        if (stop_checking) break;

        // We are done with this do loop, so we can get rid of the reference
        // to it.
        int nlevels = (int)do_start.size();
        if (nlevels > 0) {
            do_start.erase(do_start.begin()+nlevels-1);
        }
    }
} // End end_do_ret




// ===========================================================================
// Check that an enddo was found for every do.
// ===========================================================================
void PowerParser::check_enddo(deque<int> &do_start, stringstream &serr, int &ierr)
{
    for (int i=0; i<(int)do_start.size(); i++) {
        int ido = do_start[i];
        cmds[ido].fatal_error(0, serr, ierr);
        serr << "No enddo found for do statement." << endl;
        ierr = 2;
    }
}


// ===========================================================================
// Check all processed flags on every command. If any word on any command
// has not been processed, then that is a fatal error.
// ===========================================================================
void PowerParser::check_processed(bool &good)
{
    int rtvl = 0;
    int ierr = 0;
    stringstream serr;

    for (int i=0; i<(int)cmdsfp->size(); i++) {
        (*cmdsfp)[i].check_processed(good, serr, ierr);
    }

    process_error(serr, ierr);
}


// ===========================================================================
// Process the duplicate array values command.
// ===========================================================================
int PowerParser::process_dav_cmd()
{
    int rtvl         = 0;
    int return_value = 0;

    // Process the duplicate_array_values command.
    // Note that duplicate array values are processed when the calls are made
    // from the host code to actually extract information from the final
    // buffer.
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        string cmdi = (*cmdsfp)[i].get_string(0);
        if (cmdi != "duplicate_array_values") continue;
        (*cmdsfp)[i].set_processed(true);
        string vali = (*cmdsfp)[i].get_string(2);
        if (vali == "warning") dup_fatal = 1;
        else if (vali == "fatal") dup_fatal = 2;
        else if (vali == "none") dup_fatal = 0;
        else {
            int ierr = 0;
            stringstream serr;
            (*cmdsfp)[i].fatal_error(0, serr, ierr);
            serr << "The value for the duplicate_array_values command must" << endl <<
                "be either none, warning, or fatal" << endl;
            ierr = 2;
            cout << "The value for the duplicate_array_values command must" << endl;
            cout << "be either none, warning, or fatal" << endl;
            rtvl = process_error_return_int(serr, ierr);
            if (rtvl > return_value) {
                return_value = rtvl;
            }

            if (rtvl > 0) {
                 cout << "Duplicate array values not recognized " << ierr << endl;
            }
            return return_value;
        }
        if (dup_fatal > 0 ) return dup_fatal;
    }
    return 0;
}


// ===========================================================================
// If commands appear more than once in the input file(s), print a warning
// to the user.
// ===========================================================================
void PowerParser::check_duplicates()
{
    // Check for and print and duplicate scalar commands in the input file.
    //if (comm->isIOProc()) {
    //    cout << "********************************************************************************" << endl;
    //}
    //bool found_any = false;
    bool fany;
    check_dup_scalar(-1, fany);
    //if (fany) found_any = true;
    for (int wtn=0; wtn<(int)whenthens.size(); wtn++) {
        check_dup_scalar(wtn, fany);
        //if (fany) found_any = true;
    }
    wt_reset();

    // If duplicate scalar commands are not found, we do not really need to
    // pollute the output telling the user that.
    //if (!found_any) {
    //    if (comm->isIOProc()) {
    //        cout << "********** No Duplicate Scalar Commands Found in User Input File" << endl;
    //    }
    //}
    //if (comm->isIOProc()) {
    //    cout << "********************************************************************************" << endl;
    //    cout << endl << endl;
    //}


    // Remove and duplicate scalar commands from the final buffer.
    remove_dup_scalar(-1);
    for (int wtn=0; wtn<(int)whenthens.size(); wtn++) {
        remove_dup_scalar(wtn);
    }
    wt_reset();
}

// ===========================================================================
// Check for duplicate scalar commands in the user input file.
// Print a table of any duplicate scalar commands to stdout.
// ===========================================================================
void PowerParser::check_dup_scalar(int wtn, bool &found_any)
{
    vector< vector<string> > rows;

    vector<string> row1;
    row1.push_back(" ");
    row1.push_back("Line");
    row1.push_back(" ");
    rows.push_back(row1);

    vector<string> row2;
    row2.push_back("Filename");
    row2.push_back("Number");
    row2.push_back("Command");
    rows.push_back(row2);

    int n_header_rows = (int)rows.size();

    if (wtn < 0) cmdsfp = &cmdsf;
    else         cmdsfp = whenthens[wtn].get_cmdsf_ptr();

    vector<string> cmds_done;
    found_any = false;
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        bool already_printed_i = false;
        string cmdi = (*cmdsfp)[i].get_string(0);
        string w1i = (*cmdsfp)[i].get_string(1);
        if (w1i == "(") continue;

        bool already_done = false;
        for (int j=0; j<(int)cmds_done.size(); j++) {
            if (cmdi == cmds_done[j]) {
                already_done = true;
                break;
            }
        }
        if (already_done) continue;

        bool found = false;
        for (int j=i+1; j<(int)cmdsfp->size(); j++) {
            string cmdj = (*cmdsfp)[j].get_string(0);
            if (cmdi == cmdj) {
                stringstream ss;
                if (!already_printed_i) {
                    vector<string> row;
                    set_dup_row(row, (*cmdsfp)[i], 0);
                    rows.push_back(row);
                    already_printed_i = true;
                }
                vector<string> row;
                set_dup_row(row, (*cmdsfp)[j], 0);
                rows.push_back(row);
                found = true;
                found_any = true;
            }
        }
        if (found) {
            cmds_done.push_back(cmdi);
            vector<string> row;
            row.push_back(" ");  row.push_back(" ");  row.push_back(" ");
            rows.push_back(row);
        }
    }

    if (found_any) {
        if (comm->isIOProc()) {
            cout << endl;
            if (wtn < 0) {
                cout << "********** WARNING: Duplicate Scalar Commands Found in User Input File" << endl;
                cout << "  The following commands appear more than once in the user input file." << endl;
            }
            else {
                cout << "********** WARNING: Duplicate Scalar Commands Found in when...then" << endl;
                cout << "  The following commands appear more than once in the when...then." << endl;
            }
            cout << "  The last instance of the command will be used." << endl;
            cout << "  Is this what you want??" << endl << endl;
            stringstream ssout;
            Parser_utils putils(index_base);
            putils.print_strings(rows, n_header_rows, 4, 3, 80, ssout);
            cout << ssout.str() << endl;
        }
    }
}


// ===========================================================================
// Helper function for check_dup_scalar.
// The duplicate scalar commands are printed as rows with each row containing
// the file name the duplicate command was found in, the line number, and the
// command line itself.
// Given the duplicate command, this function generates that row of
// information and adds it to the row vector.
// ===========================================================================
void PowerParser::set_dup_row(vector<string> &row, Cmd &cmdi, int iw)
{
    int lnum = cmdi.get_line_number(iw);
    int file_lnum = cmdi.get_file_line_number(iw);
    string fname = cmdi.get_filename(iw);

    row.push_back(fname);
    stringstream ss;
    ss << file_lnum;
    row.push_back(ss.str());
    row.push_back(cmd_strings[lnum-1]);
}



// ===========================================================================
// Remove duplicate scalar commands in the user input file.
// Keep only the last instance of the command.
// ===========================================================================
void PowerParser::remove_dup_scalar(int wtn)
{
    if (wtn < 0) cmdsfp = &cmdsf;
    else         cmdsfp = whenthens[wtn].get_cmdsf_ptr();

    for (int i=(int)cmdsfp->size()-1; i>=0; i--) {
        string cmdi = (*cmdsfp)[i].get_string(0);
        string w1i = (*cmdsfp)[i].get_string(1);
        if (w1i == "(") continue;

        for (int j=i-1; j>=0; j--) {
            string cmdj = (*cmdsfp)[j].get_string(0);
            if (cmdi == cmdj) {
                cmdsfp->erase(cmdsfp->begin()+j);
                i--;
            }
        }
    }
}

// ===========================================================================
// Helper function to convert doubles to strings.
// ===========================================================================
std::string const to_string( double const x )
{
    std::ostringstream tmp;
    tmp << std::setprecision(16) << x;
    return tmp.str();
}

// ===========================================================================
// Initialize the parser. This will typically be called by the
// constructors.
// ===========================================================================
void PowerParser::init()
{
    line_number = 0;
    cmdsfp = &cmdsf;
    dup_fatal = 1;
    ierr_global = 0;

    // make a little smaller (2.0) to avoid floating point excepting on some
    // compilers
    double huge_double = numeric_limits<double>::max( )/2.0;
    Word whuge_double(huge_double, 1, 1, "", NULL);
    Variable vhuge_double("$huge_double", whuge_double.get_string(), true, "largest double/2.0");
    vmap.insert(pair<string, Variable>(vhuge_double.get_varname(), vhuge_double));

    float huge_float = numeric_limits<float>::max( );
    Word whuge_float(huge_float, 1, 1, "", NULL);
    Variable vhuge_float("$huge_float", whuge_float.get_string(), true, "largest float");
    vmap.insert(pair<string, Variable>(vhuge_float.get_varname(), vhuge_float));

    int huge_int = numeric_limits<int>::max( );
    Word whuge_int(huge_int, 1, 1, "", NULL);
    Variable vhuge_int("$huge_int", whuge_int.get_string(), true, "largest integer");
    vmap.insert(pair<string, Variable>(vhuge_int.get_varname(), vhuge_int));

    double tiny_double = numeric_limits<double>::min( );
    Word wtiny_double(tiny_double, 1, 1, "", NULL);
    Variable vtiny_double("$tiny_double", wtiny_double.get_string(), true, "tiniest double");
    vmap.insert(pair<string, Variable>(vtiny_double.get_varname(), vtiny_double));

    float tiny_float = numeric_limits<float>::min( );
    Word wtiny_float(tiny_float, 1, 1, "", NULL);
    Variable vtiny_float("$tiny_float", wtiny_float.get_string(), true, "tiniest float");
    vmap.insert(pair<string, Variable>(vtiny_float.get_varname(), vtiny_float));

    int tiny_int = numeric_limits<int>::min( );
    Word wtiny_int(tiny_int, 1, 1, "", NULL);
    Variable vtiny_int("$tiny_int", wtiny_int.get_string(), true, "tiniest integer");
    vmap.insert(pair<string, Variable>(vtiny_int.get_varname(), vtiny_int));

    int ncores_tot = comm->getNumProcs();
    Word wncores_tot(ncores_tot, 1, 1, "", NULL);
    Variable vncores_tot("$ncores_tot", wncores_tot.get_string(), true, "total number of cores");
    vmap.insert(pair<string, Variable>(vncores_tot.get_varname(), vncores_tot));


    // ***********************************************************************
    // Define the default functions.
    Function facos("acos", true, 1, "real",
                   "arccosine, radians, arg -1 to 1");
    fmap.insert(pair<string, Function>(facos.get_name(), facos));

    Function fasin("asin", true, 1, "real",
                   "arcsine, radians, arg -1 to 1");
    fmap.insert(pair<string, Function>(fasin.get_name(), fasin));

    Function fatan("atan", true, 1, "real", "arctangent, returns radians");
    fmap.insert(pair<string, Function>(fatan.get_name(), fatan));

    Function fceil("ceil", true, 1, "real", "round up (smallest int >= arg)");
    fmap.insert(pair<string, Function>(fceil.get_name(), fceil));

    Function fcos("cos", true, 1, "real", "cosine, arg in radians");
    fmap.insert(pair<string, Function>(fcos.get_name(), fcos));

    Function fcosh("cosh", true, 1, "real", "hyperbolic cosine");
    fmap.insert(pair<string, Function>(fcosh.get_name(), fcosh));

    Function fexp("exp", true, 1, "real", "exponential");
    fmap.insert(pair<string, Function>(fexp.get_name(), fexp));

    Function ffabs("fabs", true, 1, "real", "absolute value of a real");
    fmap.insert(pair<string, Function>(ffabs.get_name(), ffabs));

    Function ffloor("floor", true, 1, "real",
                    "round down (largest int <= arg)");
    fmap.insert(pair<string, Function>(ffloor.get_name(), ffloor));

    Function flog("log", true, 1, "real", "log to base e, arg>0");
    fmap.insert(pair<string, Function>(flog.get_name(), flog));

    Function flog10("log10", true, 1, "real", "log to base 10, arg>0");
    fmap.insert(pair<string, Function>(flog10.get_name(), flog10));

    Function fsin("sin", true, 1, "real", "sine, arg in radians");
    fmap.insert(pair<string, Function>(fsin.get_name(), fsin));

    Function fsinh("sinh", true, 1, "real", "hyperbolic sine");
    fmap.insert(pair<string, Function>(fsinh.get_name(), fsinh));

    Function fsqrt("sqrt", true, 1, "real", "square root (arg >= 0)");
    fmap.insert(pair<string, Function>(fsqrt.get_name(), fsqrt));

    Function ftan("tan", true, 1, "real", "tangent, arg in radians");
    fmap.insert(pair<string, Function>(ftan.get_name(), ftan));

    Function ftanh("tanh", true, 1, "real", "hyperbolic tangent");
    fmap.insert(pair<string, Function>(ftanh.get_name(), ftanh));

    Function fatan2("atan2", true, 2, "real", "arctangent, 2 args");
    fmap.insert(pair<string, Function>(fatan2.get_name(), fatan2));

    Function ffmod("fmod", true, 2, "real", "remainder of arg1/arg2");
    fmap.insert(pair<string, Function>(ffmod.get_name(), ffmod));

    Function fpow("pow", true, 2, "real", "arg1 raised to arg2 power");
    fmap.insert(pair<string, Function>(fpow.get_name(), fpow));

    Function ffmax("max", true, 2, "real", "return the greater of two args");
    fmap.insert(pair<string, Function>(ffmax.get_name(), ffmax));

    Function ffmin("min", true, 2, "real", "return the lesser of two args");
    fmap.insert(pair<string, Function>(ffmin.get_name(), ffmin));

    Function fstrlen("strlen", true, 1, "string", "number of chars in arg");
    fmap.insert(pair<string, Function>(fstrlen.get_name(), fstrlen));

    Function fstrcat("strcat", true, 2, "string", "concatenate two strings");
    fmap.insert(pair<string, Function>(fstrcat.get_name(), fstrcat));

    Function fstrerase("strerase", true, 3, "string", "erase chars from string");
    fmap.insert(pair<string, Function>(fstrerase.get_name(), fstrerase));

    Function fstrinsert("strinsert", true, 3, "string", "insert chars into string");
    fmap.insert(pair<string, Function>(fstrinsert.get_name(), fstrinsert));

    Function fstrsubstr("strsubstr", true, 3, "string", "get sub string");
    fmap.insert(pair<string, Function>(fstrsubstr.get_name(), fstrsubstr));

    Function fstrtrim("strtrim", true, 1, "string", "remove trailing whitespace");
    fmap.insert(pair<string, Function>(fstrtrim.get_name(), fstrtrim));

    Function fdefined("defined", true, 1, "logical", "is a variable defined or not");
    fmap.insert(pair<string, Function>(fdefined.get_name(), fdefined));
}

void PowerParser::dictionary_add(char *name, double value, bool pred, char *vdesc)
{
   Variable *Var_entry = new Variable(name, to_string(value), pred, vdesc);
   vmap.insert(pair<string, Variable>(Var_entry->get_varname(), *Var_entry));
}

void PowerParser::dictionary_env_add(char *name, bool pred)
{
   const char *getenv_p;
   const char *getenv_p_not_defined = "";

   getenv_p = getenv(name);
   if( getenv_p == NULL ){
      getenv_p = getenv_p_not_defined;
   }

   int len_name = strlen(name);

   // One extra character for $ and another for null termination
   char *varname = (char *)malloc(sizeof(char)*(len_name+2));

   varname[0] = '$';
   strncpy(varname+1, name, len_name+1);

   Variable *Var_entry = new Variable(varname, getenv_p, pred, name);
   vmap.insert(pair<string, Variable>(Var_entry->get_varname(), *Var_entry));

   free(varname);
}


// ===========================================================================
// Read a file into a string.
// This is only done on the io processor.
// ===========================================================================
void PowerParser::read_into_string(string filename, string &s_in)
{
    if(comm != NULL) {
        if(!comm->isIOProc()) return;
    }

    // Its OK if an input file is not specified.
    if (filename == " ") {
        s_in = " ";
        return;
    }

    // Open the input data file.
    ifstream in_stream(filename.c_str(), ios::in);
    if( !in_stream ) {
        stringstream serr;
        serr << endl << "*** FATAL ERROR" << endl;
        serr << "Could not open input (or include) file." << endl;
        serr << "The name of the file is " << filename << endl;
        if (filename == "") {
            serr << "(The file name is blank.)" << endl;
        }
        int ierr = 2;
        process_error(serr, ierr);
        return;
    }

    // Read each character and store in a string. We use a string so we
    // don't have to fiddle with memory allocation and reallocation.
    // There are more efficient ways to do this, but whatever way is
    // used has to handle arbitrarily long files.
    char c;
    while (in_stream) {
        in_stream.get(c);
        if (!in_stream) break;
        s_in += c;
    }

    // Check for a 0 size input file, this might be an indication of a
    // full file system.
    if( (int)s_in.size() == 0 ) {
        stringstream serr;
        serr << endl << "*** FATAL ERROR" << endl;
        serr << "The name of the input file is " << filename << endl;
        serr << "This file exists, but its size is 0 bytes, (empty file)." << endl;
        serr << "Perhaps the file system is full??" << endl;
        serr << "Use a unix command like \"df -k .\" to find out how full the"
             " file system is." << endl;
        int ierr = 2;
        process_error(serr, ierr);
        return;
    }

    // Now that the file contents are transferred to a string we do not need
    // the data file anymore and can close it.
    in_stream.close();
}


//+***************************************************************************
// ***************************************************************************
// Driver functions for getting values from the commands.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Driver for getting boolean values as integers.
// This works for arrays of any dimension, 0,1,2,3,...
// ===========================================================================
void PowerParser::get_bool_int(string &cname,
                         int *cvalue,
                         const vector<int> &size,
                         bool skip)
{
    // Note that we do not default cvalue. Its value only changes if the
    // command is found.

    // Used in checking for duplicate array values
    int dim = (int)size.size();
    int tot_size = 1;
    for (int i=0; i<dim; i++) {
        tot_size *= size[i];
    }
    vector<int> dup_vals(tot_size, 0);
    vector<Cmd *> dup_cmd1(tot_size);
    vector<int> dup_wdex1(tot_size, -1);

    int ierr = 0;
    stringstream serr;
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_bool_int(cname, cvalue, size, dup_cmd1, dup_wdex1,
                                      dup_fatal, dup_vals, skip, serr, ierr);
            processed_cmd_names.push_back(cname);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}

void PowerParser::get_bool_int(const char *cname,
                         int *cvalue,
                         const vector<int> &size,
                         bool skip)
{
   string cstring(cname);
   get_bool_int( cstring, cvalue, size, skip);
}

void PowerParser::get_bool(string &cname,
                     bool *cvalue,
                     const vector<int> &size,
                     bool skip)
{
    // Note that we do not default cvalue. Its value only changes if the
    // command is found.

    // Used in checking for duplicate array values
    int dim = (int)size.size();
    int tot_size = 1;
    for (int i=0; i<dim; i++) {
        tot_size *= size[i];
    }
    vector<int> dup_vals(tot_size, 0);
    vector<Cmd *> dup_cmd1(tot_size);
    vector<int> dup_wdex1(tot_size, -1);

    int ierr = 0;
    stringstream serr;
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_bool(cname, cvalue, size, dup_cmd1, dup_wdex1,
                                  dup_fatal, dup_vals, skip, serr, ierr);
            processed_cmd_names.push_back(cname);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}

void PowerParser::get_bool(const char *cname,
                     bool *cvalue,
                     const vector<int> &size,
                     bool skip)
{
   string cstring(cname);
   get_bool( cstring, cvalue, size, skip);
}


// ===========================================================================
// Driver for getting integer values.
// This works for arrays of any dimension, 0,1,2,3,...
// ===========================================================================
template< typename T >
void PowerParser::get_int(string &cname, T *cvalue, const vector<int> &size, bool skip)
{
    // Note that we do not default cvalue. Its value only changes if the
    // command is found.

    // Used in checking for duplicate array values
    int dim = (int)size.size();
    int tot_size = 1;
    for (int i=0; i<dim; i++) {
        tot_size *= size[i];
    }
    vector<int> dup_vals(tot_size, 0);
    vector<Cmd *> dup_cmd1(tot_size);
    vector<int> dup_wdex1(tot_size, -1);

    int ierr = 0;
    stringstream serr;
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_int(cname, cvalue, size, dup_cmd1, dup_wdex1,
                                 dup_fatal, dup_vals, skip, serr, ierr);
            processed_cmd_names.push_back(cname);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}

//! Explicit instantiation of supported template types.  If more types are
//! needed those explicit versions must be listed here.  We are not using
//! automatic inclusion (we would need to move the function definition into
//! the header file for that).  The listed versions below are the only ones
//! that will be included in the library.
template void PowerParser::get_int(
    string &cname, int     *cvalue, const vector<int> &size, bool skip);
template void PowerParser::get_int(
    string &cname, int64_t *cvalue, const vector<int> &size, bool skip);

template< typename T >
void PowerParser::get_int(const char *cname,
                    T *cvalue,
                    const vector<int> &size,
                    bool skip)
{
   string cstring(cname);
   get_int( cstring, cvalue, size, skip);
}

template void PowerParser::get_int(
    const char *cname, int     *cvalue, const vector<int> &size, bool skip);
template void PowerParser::get_int(
    const char *cname, int64_t *cvalue, const vector<int> &size, bool skip);

// ===========================================================================
// Driver for getting real values.
// This works for arrays of any dimension, 0,1,2,3,...
// ===========================================================================
void PowerParser::get_real(string &cname,
                     double *cvalue,
                     const vector<int> &size,
                     bool skip)
{
    // Note that we do not default cvalue. Its values only change if the
    // command is found.

    // Used in checking for duplicate array values
    int dim = (int)size.size();
    int tot_size = 1;
    for (int i=0; i<dim; i++) {
        tot_size *= size[i];
    }
    vector<int> dup_vals(tot_size, 0);
    vector<Cmd *> dup_cmd1(tot_size);
    vector<int> dup_wdex1(tot_size, -1);

    int ierr = 0;
    stringstream serr;
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_real(cname, cvalue, size, dup_cmd1, dup_wdex1,
                                  dup_fatal, dup_vals, skip, serr, ierr);
            processed_cmd_names.push_back(cname);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}

void PowerParser::get_real(const char *cname,
                     double *cvalue,
                     const vector<int> &size,
                     bool skip)
{
   string cstring(cname);
   get_real( cstring, cvalue, size, skip);
}

// ===========================================================================
// Driver for getting character strings.
// This works for arrays of any dimension, 0,1,2,3,...
// ===========================================================================
void PowerParser::get_char(string &cname,
                     vector<string> &vstr,
                     const vector<int> &size,
                     bool single_char,
                     bool skip)
{
    // Note that we do not default cvalue. Its value only changes if the
    // command is found.

    // Used in checking for duplicate array values
    int dim = (int)size.size();
    int tot_size = 1;
    for (int i=0; i<dim; i++) {
        tot_size *= size[i];
    }
    vector<int> dup_vals(tot_size, 0);
    vector<Cmd *> dup_cmd1(tot_size);
    vector<int> dup_wdex1(tot_size, -1);

    int ierr = 0;
    stringstream serr;
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_char(cname, vstr, size, single_char, dup_cmd1,
                                  dup_wdex1, dup_fatal, dup_vals,
                                  skip, serr, ierr);
            processed_cmd_names.push_back(cname);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}

void PowerParser::get_char(const char *cname,
                     vector<string> &vstr,
                     const vector<int> &size,
                     bool single_char,
                     bool skip)
{
   string cstring(cname);
   get_char( cstring, vstr, size, single_char, skip);
}

// ===========================================================================
// Driver for getting array sizes.
// ===========================================================================
void PowerParser::get_size(string &cname, vector<int> &size)
{
    int ierr = 0;
    stringstream serr;
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_size(size, serr, ierr);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}


// ===========================================================================
// Driver for getting array sizes. Version to get all sizes
// ===========================================================================
void PowerParser::get_sizeb(string &cname, vector<int> &size)
{
    int ierr = 0;
    stringstream serr;
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].get_sizeb(size, serr, ierr);
        }
    }

    // Process errors, global abort if ierr==2
    process_error(serr, ierr);
}


// ===========================================================================
// Check if the input command, cname, appears in the final, parsed user input.
//
// The two outputs are in_input and in_whenthen,
//    in_input     command is in (or not) the main part of the input, i.e.
//                 everything except the when...then statements.
//    in_whenthen  command is in (or not) at least one when...then statement.
// ===========================================================================
void PowerParser::cmd_in_input(string &cname, bool &in_input, bool &in_whenthen)
{
    in_input = false;
    in_whenthen = false;

    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            in_input = true;
            break;
        }
    }

    for (int wtn=0; wtn<(int)whenthens.size(); wtn++) {
        cmdsfp = whenthens[wtn].get_cmdsf_ptr();
        for (int i=0; i<(int)cmdsfp->size(); i++) {
            if ((*cmdsfp)[i].get_cmd_name() == cname) {
                in_whenthen = true;
                break;
            }
        }
        if (in_whenthen) break;
    }

    wt_reset();
}


// ===========================================================================
// Set the processed flag for all words for all commands that match cname.
// The value to set the processed flag to is bval.
// This sets the processed flag for commands in the final buffer and in the
// when...then final buffers.
// ===========================================================================
void PowerParser::cmd_set_processed(string &cname, bool bval)
{
    if (! case_sensitive) {
       transform(cname.begin(), cname.end(), cname.begin(), tolower);
    }
    for (int i=0; i<(int)cmdsfp->size(); i++) {
        if ((*cmdsfp)[i].get_cmd_name() == cname) {
            (*cmdsfp)[i].set_processed(bval);
        }
    }
    for (int wtn=0; wtn<(int)whenthens.size(); wtn++) {
        cmdsfp = whenthens[wtn].get_cmdsf_ptr();
        for (int i=0; i<(int)cmdsfp->size(); i++) {
            if ((*cmdsfp)[i].get_cmd_name() == cname) {
                (*cmdsfp)[i].set_processed(bval);
            }
        }
    }
    wt_reset();
}


// ===========================================================================
// ===========================================================================
void PowerParser::cmd_set_reprocessed(bool bval)
{
    for (int c=0; c<(int)processed_cmd_names.size(); c++) {
        string cname = processed_cmd_names[c];
        cmd_set_processed(cname, bval);
    }
}


// ===========================================================================
// Process errors.
// ===========================================================================
void PowerParser::process_error_global(int &return_value)
{
    int return_val_local;
    int ierr = ierr_global;

    return_val_local = 0;
    if (ierr == 0) {
      return_value = 0;
      return;
    }

    return_val_local = process_error_return_int(serr_global, ierr);
    return_value     = return_val_local;
}

// ===========================================================================
//

void PowerParser::process_error(stringstream &serr, int &ierr)
{
    if (ierr == 0) return;

    if (ierr == 3) {
        serr_global << serr.str();
        ierr_global = ierr;
        return;
    }

    string err_type = "Warnings";
    if (ierr == 2) err_type = "Fatal errors";

    if (comm->isIOProc()) {
        cout << endl;
        cout << err_type << " have been encountered while parsing the user"
            " input file." << endl;
        cout << "Note that often fixing the first error will also fix the"
            " other errors." << endl;
        cout << serr.str() << endl;
        fflush(NULL);
    }
    if (ierr == 2) {
        // Force all processors to quit.
        // We have the problem that the non-IO procs may kill the calculation
        // before the IO proc can finish printing the error messages, thus
        // force the IO proc to do the global abort but still allow the
        // possibility that the IO proc may not have aborted, some other
        // proc might have.
        if (comm->isIOProc()) {
            comm->global_abort_parser();
        }
        else {
            sleep(2);
            comm->global_abort_parser();
        }
    }


    // A possible sleep function if the library sleep function is not portable.
    // #include <time.h>
    // void sleep(unsigned int mseconds)
    // {
    //    clock_t goal = mseconds + clock();
    //    while (goal > clock());
    // }


    // A better function is the following since it uses CLOCKS_PER_SEC and
    // thus does not assume its value.
    //
    //#include <time.h>
    //void wait ( int seconds )
    //{
    //  clock_t endwait;
    //  endwait = clock () + seconds * CLOCKS_PER_SEC ;
    //  while (clock() < endwait) {}
    //}

    // We might want to put this in Comm, i.e. modify global_abort.
}


// ===========================================================================
int PowerParser::process_error_return_int(stringstream &serr, int &ierr)
{
    int return_value;

    return_value = ierr;

    if (ierr == 0) return(return_value);

    return_value = ierr;

    if (ierr == 3) {
      serr_global << serr.str();
      ierr_global = ierr;
      cout << "Error encountered in process_error_return_int -- err code is " << ierr << endl; 
      fflush(NULL);
    }

    if (comm->isIOProc()) {
        cout << endl;
        cout << "Error encountered while parsing the user input file -- err code is "
             << ierr << endl;
        cout << "Note that often fixing the first error will also fix the"
            " other errors." << endl;
        cout << serr.str() << endl;
        cout.flush();
        fflush(NULL);
    }

    return(return_value);


    // A possible sleep function if the library sleep function is not portable.
    // #include <time.h>
    // void sleep(unsigned int mseconds)
    // {
    //    clock_t goal = mseconds + clock();
    //    while (goal > clock());
    // }


    // A better function is the following since it uses CLOCKS_PER_SEC and
    // thus does not assume its value.
    //
    //#include <time.h>
    //void wait ( int seconds )
    //{
    //  clock_t endwait;
    //  endwait = clock () + seconds * CLOCKS_PER_SEC ;
    //  while (clock() < endwait) {}
    //}

}


//+***************************************************************************
// ***************************************************************************
// When...then commands
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Check if a when...then condition is satisfied.
// ===========================================================================
void PowerParser::wt_check(int wtn, vector<string> &code_varnames,
                     vector<string> &code_values, 
                     vector<int> &vv_active, int *wtci)
{
    stringstream serr;
    int ierr = 0;
    whenthens[wtn-1].check_wt(code_varnames, code_values, vv_active, wtci,
                              serr, ierr);
    process_error(serr, ierr);
    if ( (*wtci) == 1) {
        cmdsfp = whenthens[wtn-1].get_cmdsf_ptr();
    }
}


// ===========================================================================
// Set the commands final buffer pointer.
// This is also done in the check routine.
// ===========================================================================
void PowerParser::wt_set_cmdsfp(int wtn)
{
    cmdsfp = whenthens[wtn-1].get_cmdsf_ptr();
}


// ===========================================================================
// Reset the commands final buffer pointer.
// ===========================================================================
void PowerParser::wt_reset()
{
    cmdsfp = &cmdsf;
}


// ===========================================================================
// ===========================================================================
void PowerParser::wt_casize(int wtn, int *wt_casize)
{
    // To suppress compiler warnings of unused parameters
    assert(wt_casize == wt_casize);

    whenthens[wtn-1].get_char_array_size(wt_casize);
}


// ===========================================================================
// ===========================================================================
void PowerParser::wt_carray(int wtn, char *wt_ca, int wt_casize)
{
    // To suppress compiler warnings of unused parameters
    assert(wt_casize == wt_casize);

    string sc;
    whenthens[wtn-1].get_char_array(sc);
    for (int i=0; i<(int)sc.size(); i++) {
        wt_ca[i] = sc[i];
    }
}


// ===========================================================================
// ===========================================================================
void PowerParser::wt_satsize(int wtn, int *wt_satsize)
{
    // To suppress compiler warnings of unused parameters
    assert(wt_satsize == wt_satsize);

    whenthens[wtn-1].get_satsize(wt_satsize);
}


// ===========================================================================
// ===========================================================================
void PowerParser::wt_getsat(int wtn, int *wt_sat, int wt_satsize)
{
    // To suppress compiler warnings of unused parameters
    assert(wt_satsize == wt_satsize);

    whenthens[wtn-1].getsat(wt_sat);
}


// ===========================================================================
// ===========================================================================
void PowerParser::wt_setsat(int wtn, int *wt_sat, int wt_satsize)
{
    // To suppress compiler warnings of unused parameters
    assert(wt_satsize == wt_satsize);

    whenthens[wtn-1].setsat(wt_sat);
}


// ===========================================================================
// Get and Set the processed flag for a whenthen.
// ===========================================================================
void PowerParser::wt_getprocessed(int wtn, int *wtp)
{
    whenthens[wtn-1].getprocessed(wtp);
}

void PowerParser::wt_setprocessed(int wtn, int wtp)
{
    whenthens[wtn-1].setprocessed(wtp);
}


// ===========================================================================
// Get and Set the sequence index for a whenthen.
// ===========================================================================
void PowerParser::wt_getseq(int wtn, int *wtseq)
{
    whenthens[wtn-1].getseq(wtseq);
}

void PowerParser::wt_setseq(int wtn, int wtseq)
{
    whenthens[wtn-1].setseq(wtseq);
}




//+***************************************************************************
// ***************************************************************************
// restart_block commands
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Check if a restart block condition is satisfied.
// ===========================================================================
void PowerParser::rb_check(vector<string> &code_varnames,
                     vector<string> &code_values,
                     vector<int> &vv_active, int *rbci,
                     int *rb_ntriggered, int *rb_triggered_indices)
{
    stringstream serr;
    int ierr = 0;
    *rbci = 0;
    *rb_ntriggered = 0;
    for (int i=0; i<(int)restartblocks.size(); i++) {
        int ri = 0;
        restartblocks[i].check_rb(code_varnames, code_values, vv_active, &ri,
                                  serr, ierr);
        if (ri == 1) {
            *rbci = 1;
            rb_triggered_indices[*rb_ntriggered] = i;
            *rb_ntriggered += 1;
        }
    }
    process_error(serr, ierr);
}


// ===========================================================================
// Get/set the restart block names
// ===========================================================================
void PowerParser::get_rb_names(vector<string> &rb_names_vstr)
{
    rb_names_vstr.clear();
    for (int i=0; i<(int)restartblocks.size(); i++) {
        rb_names_vstr.push_back(restartblocks[i].get_name());
    }
}
void PowerParser::set_rb_names(vector<string> &rb_names_vstr)
{
    bnames_on_dump.clear();
    for (int i=0; i<(int)rb_names_vstr.size(); i++) {
        bnames_on_dump.push_back(rb_names_vstr[i]);
    }
}


// ===========================================================================
// Get/set the restart block activity flags.
// ===========================================================================
void PowerParser::get_rb_aflags(int *rb_aflags)
{
    for (int i=0; i<(int)restartblocks.size(); i++) {
        rb_aflags[i] = restartblocks[i].get_aflag();
    }
}
void PowerParser::set_rb_aflags(int *rb_aflags, int rb_num)
{
    baflags_on_dump.clear();
    for (int j=0; j<rb_num; j++) {
        baflags_on_dump.push_back(rb_aflags[j]);
    }
}


// ===========================================================================
// Get/set the restart block satsize.
// satsize is defined as the total number of sub-conditions over all restart
// blocks.
// ===========================================================================
void PowerParser::get_rb_satsize(int *rb_satsize)
{
    int rb_sum = 0;
    for (int i=0; i<(int)restartblocks.size(); i++) {
        rb_sum += restartblocks[i].get_satsize();
    }
    *rb_satsize = rb_sum;
}

void PowerParser::set_rb_satsize(int rb_satsize)
{
    satsize_on_dump = rb_satsize;
}


// ===========================================================================
// Get/set the number of sub-conditions per restart block
// ===========================================================================
void PowerParser::get_rb_satprb(int *rb_satprb)
{
    for (int i=0; i<(int)restartblocks.size(); i++) {
        rb_satprb[i] = restartblocks[i].get_satsize();
    }
}

void PowerParser::set_rb_satprb(int *rb_satprb, int rb_num)
{
    rbsatprb_on_dump.clear();
    for (int i=0; i<rb_num; i++) {
        rbsatprb_on_dump.push_back(rb_satprb[i]);
    }
}


// ===========================================================================
// Get/set the satisfied flag for each sub-condition for each restart block
// ===========================================================================
void PowerParser::get_rb_sat(int *rb_sat)
{
    int k = 0;
    for (int i=0; i<(int)restartblocks.size(); i++) {
        for (int j=0; j<(int)restartblocks[i].get_satsize(); j++) {
            rb_sat[k] = restartblocks[i].get_sat(j);
            k++;
        }
    }
}


void PowerParser::set_rb_sat(int *rb_sat, int rb_satsize)
{
    rbsat_on_dump.clear();
    for (int i=0; i<rb_satsize; i++) {
        bool b = false;
        if (rb_sat[i] == 1) b = true;
        rbsat_on_dump.push_back(b);
    }
}


// ===========================================================================
// Get a combined list of the restart block variable names. Note that there
// might be more than one variable name per restart block depending on how
// complicated the condition is.
// ===========================================================================
int PowerParser::get_rb_num_varnames()
{
    int numv = 0;
    for (int i=0; i<(int)restartblocks.size(); i++) {
        numv += restartblocks[i].get_num_varnames();
    }
    for (int i=0; i<(int)whenthens.size(); i++) {
        numv += whenthens[i].get_num_varnames();
    }
    return numv;
}
void PowerParser::get_rb_varnames(vector<string> &rb_varnames_vstr)
{
    rb_varnames_vstr.clear();
    for (int i=0; i<(int)restartblocks.size(); i++) {
        int numv = restartblocks[i].get_num_varnames();
        for (int j=0; j<numv; j++) {
            rb_varnames_vstr.push_back(restartblocks[i].get_varname(j));
        }
    }
    for (int i=0; i<(int)whenthens.size(); i++) {
        int numv = whenthens[i].get_num_varnames();
        for (int j=0; j<numv; j++) {
            rb_varnames_vstr.push_back(whenthens[i].get_varname(j));
        }
    }
}


// ===========================================================================
// Print info about restart blocks.
// ===========================================================================
void PowerParser::list_rb()
{
    stringstream ssc;
    list_rb_ss(ssc);
    if (comm->isIOProc()) {
        cout << ssc.str();
    }
}

void PowerParser::list_rb_start()
{
    ssfout.str("");
    list_rb_ss(ssfout);
    ssfout_current_pos = 0;
}

void PowerParser::list_rb_ss(stringstream &ssc)
{
    int rblen = (int)restartblocks.size();
    if (rblen <= 0) {
        ssc << endl << "No restart blocks have been specified."
            << endl << endl;
        return;
    }

    for (int rb=0; rb<rblen; rb++) {
        list_one_rb_ss(ssc, rb);
    }
}

void PowerParser::list_rb1_start(int *rb)
{
    ssfout.str("");
    list_rb1_ss(ssfout, rb);
    ssfout_current_pos = 0;
}

void PowerParser::list_rb1_ss(stringstream &ssc, int *rbp)
{
    int rb = *rbp;
    int rblen = (int)restartblocks.size();
    if (rb < 0) {
        ssc << endl << "List restart block error: rb<0"
            << endl << endl;
        return;
    }
    if (rb >= rblen) {
        ssc << endl << "List restart block error: rb>=rblen"
            << endl << endl;
        return;
    }

    list_one_rb_ss(ssc, rb);
}


// ===========================================================================
// List info for one restart block, index=rb
// ===========================================================================
void PowerParser::list_one_rb_ss(stringstream &ssc, int rb)
{
    ssc << endl;
    ssc << "** Echo restart block info, restart block name = "
        << restartblocks[rb].get_name() << endl;
    string s = "false";
    if (restartblocks[rb].get_aflag() == 1) s = "true";
    ssc << "    Active flag = " << s << endl;
    ssc << "    Condition for this restart block =" << endl;
    restartblocks[rb].list_condition("        ", "        ", ssc);
    ssc << endl;
    ssc << "    Number of sub-conditions = " <<
        restartblocks[rb].get_satsize() << endl;
    for (int i=0; i<restartblocks[rb].get_satsize(); i++) {
        string t = "false";
        if (restartblocks[rb].get_sat(i) == 1) t = "true";
        ssc << "        For sub-condition " << i+1 <<
            ", satisfied flag = " << t << endl;
    }
    ssc << endl;
}

//+***************************************************************************
// ***************************************************************************
// Debugging commands/functions.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Print a cmds line.
// ===========================================================================
void PowerParser::print_line(int i)
{
    if (!comm->isIOProc()) return;
    stringstream ss3;
    cmds[i].print_using_words(ss3);
    cout << ss3.str() << endl;
}

void PowerParser::print_line(Cmd &cmd)
{
    if (!comm->isIOProc()) return;
    //cout << cmd.get_cmd_name() << endl;
    //if (cmd.get_cmd_name() != "acmd5") return;
    stringstream ss3;
    cmd.print_using_words(ss3);
    //cmd.print_all_words(ss3);
    cout << ss3.str() << endl;
}


// ===========================================================================
// List variables
//
// lv1 and lv2 are header and footer strings to delimit the list.
//
// var_to_list is a specific variable to list. If it is blank then all vars
// will be listed, otherwise only the specific var will be listed.
// ===========================================================================
void PowerParser::list_vars(string lv1, string lv2, string var_to_list)
{
    stringstream ssv;
    list_vars_ss(lv1, lv2, var_to_list, ssv);
    if (comm->isIOProc()) {
        cout << ssv.str();
    }
}
    
void PowerParser::list_vars_start()
{
    ssfout.str("");
    ssfout << pre_defined_varss.str() << endl;
    list_vars_ss("", "", "", ssfout);
    ssfout_current_pos = 0;
}

void PowerParser::list_vars_ss(string lv1, string lv2, string var_to_list,
                         stringstream &ssvars)
{
    if (!comm->isIOProc()) return;
    ssvars << lv1 << endl;

    map<string, Variable>::iterator p;

    // Holds the various header and data rows to be printed.
    vector< vector<string> > rows;

    // Construct the header row.
    vector<string> header_row;
    header_row.push_back("Variable name");
    header_row.push_back("Value");
    header_row.push_back("Description");
    rows.push_back(header_row);
    int n_header_rows = (int)rows.size();

    // Set the number of columns.
    int ncol = (int)header_row.size();

    // Construct the data rows.
    for(p = vmap.begin(); p != vmap.end(); p++) {
        string vname = p->first;
        if (var_to_list != "") {
            if (vname != var_to_list) continue;
        }
        int nvalues = p->second.get_nvalues();
        string description = p->second.get_description();

        int ndim = p->second.get_ndim();
        vector<int> istart(ndim,0);

        for (int n=0; n<nvalues; n++) {
            string vnamep = vname;
            if (nvalues > 1) {
                p->second.get_indices(n, istart);
                stringstream ss;
                ss << vname << "(";
                for (int d=0; d<ndim; d++) {
                    if (d < ndim-1) ss << istart[d] << ",";
                    else            ss << istart[d];
                }
                ss << ")";
                vnamep = ss.str();
            }
            string value = p->second.get_var_value(n);
            vector<string> sv;
            for (int c=0; c<ncol; c++) {
                if (c == 0) sv.push_back(vnamep);
                if (c == 1) sv.push_back(value);
                if (c == 2) sv.push_back(description);
            }
            rows.push_back(sv);
        }
    }

    // List the data with the columns lined up.
    Parser_utils putils(index_base);
    putils.print_strings(rows, n_header_rows, 3, 3, 85, ssvars);

    ssvars << lv2 << endl;
}


// ===========================================================================
// List functions.
// ===========================================================================
void PowerParser::list_funcs(string lf1, string lf2)
{
    stringstream ssf;
    list_funcs_ss(lf1, lf2, ssf);
    if (comm->isIOProc()) {
        cout << ssf.str();
    }

    // Alternate method. 
    //list_funcs_start();
    //for (;;) {
    //    string sline;
    //    if (!get_ssfout_line(sline)) break;
    //    if (comm->isIOProc()) {
    //        cout << sline << endl;
    //    }
    //}
}

void PowerParser::list_funcs_start()
{
    ssfout.str("");
    list_funcs_ss("", "", ssfout);
    ssfout_current_pos = 0;
}

void PowerParser::list_funcs_ss(string lf1, string lf2, stringstream &ssfunc)
{
    if (!comm->isIOProc()) return;
    ssfunc << lf1 << endl;

    map<string, Function>::iterator p;

    // Holds the various header and data rows to be printed.
    vector< vector<string> > rows;

    // Construct the header row.
    vector<string> header_row;
    header_row.push_back("Function name");
    header_row.push_back("nargs");
    header_row.push_back("type");
    header_row.push_back("Description");
    rows.push_back(header_row);
    int n_header_rows = (int)rows.size();

    // Set the number of columns.
    int ncol = (int)header_row.size();

    // Construct the data rows.
    for(p = fmap.begin(); p != fmap.end(); p++) {
        string fname = p->first;
        vector<string> sv;
        int nargs = p->second.get_num_args();
        stringstream ss;
        ss << nargs;
        string type = p->second.get_type();
        string fdes = p->second.get_description();
        for (int c=0; c<ncol; c++) {
            if (c == 0) sv.push_back(fname);
            if (c == 1) sv.push_back(ss.str());
            if (c == 2) sv.push_back(type);
            if (c == 3) sv.push_back(fdes);
        }
        rows.push_back(sv);
    }

    // List the data with the columns lined up.
    Parser_utils putils(index_base);
    putils.print_strings(rows, n_header_rows, 3, 4, 85, ssfunc);

    ssfunc << lf2 << endl;
}



// ===========================================================================
// List final set of commands.
// ===========================================================================
void PowerParser::list_cmdsf(string lc1, string lc2)
{
    stringstream ssc;
    list_cmdsf_ss(lc1, lc2, ssc);
    if (comm->isIOProc()) {
        cout << ssc.str();
    }
}

void PowerParser::list_cmdsf_start()
{
    ssfout.str("");
    list_cmdsf_ss("", "", ssfout);
    ssfout_current_pos = 0;
}

void PowerParser::list_cmdsf_ss(string lc1, string lc2,
                          stringstream &ssc)
{
    if (!comm->isIOProc()) return;
    ssc << lc1;

    for (int i=0; i<(int)cmdsfp->size(); i++) {
        (*cmdsfp)[i].print_using_words_fm(ssc);
        //(*cmdsfp)[i].print_all_words(ssc);
        //(*cmdsfp)[i].print_original_string(ssc);
        ssc << endl;
    }

    for (int wt=0; wt<(int)whenthens.size(); wt++) {
        ssc << "when (";
        whenthens[wt].list_condition("", "      ", ssc);
        ssc << ") then " << endl;
        whenthens[wt].list_cmdsf_ss(ssc);
        ssc << "endwhen" << endl;
    }

    ssc << lc2;
}


void PowerParser::list_wt_cmdsf()
{
    stringstream ssc;
    list_wt_cmdsf_ss(ssc);
    if (comm->isIOProc()) {
        cout << ssc.str();
    }
}

void PowerParser::list_wt_cmdsf_start()
{
    ssfout.str("");
    list_wt_cmdsf_ss(ssfout);
    ssfout_current_pos = 0;
}

void PowerParser::list_wt_cmdsf_ss(stringstream &ssc)
{
    int wtlen = (int)whenthens.size();
    if (wtlen <= 0) {
        ssc << endl << "No when...then commands have been specified."
            << endl << endl;
        return;
    }

    for (int wt=0; wt<wtlen; wt++) {
        ssc << endl;
        ssc << "** Echo when...then final buffer, when...then number = "
               << wt+1 << endl;
        ssc << "    Condition for this when...then =" << endl;
        whenthens[wt].list_condition("        ", "        ", ssc);
        ssc << endl;
        ssc << "    Commands for this when...then =" << endl;
        whenthens[wt].list_cmdsf_ss(ssc);
        ssc << endl;
    }
}



//+***************************************************************************
// ***************************************************************************
// Low level functions.
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Get a line from the ssfout stringstream.
// ===========================================================================
bool PowerParser::get_ssfout_line(string &sline)
{
    string s = ssfout.str();
    if (!get_line_from_string(s, sline,
                              ssfout_current_pos)) return false;
    return true;
}


// ===========================================================================
// Broadcast the buffer the all the other processors.
// ===========================================================================
void PowerParser::broadcast_buffer(string &s_in)
{
    // If there is no comm or if there is only one processor, then we don't
    // have to do anything.
    if (comm == NULL) return;
    if (comm->getNumProcs() == 1) return;

    // Get the length of the input string on the io processor.
    int cbuffer_len = 0;
    if(comm->isIOProc()) cbuffer_len = (int)s_in.size();

    // Broadcast the length of the input buffer to the other processors.
    comm->broadcast((char*)&cbuffer_len, sizeof(int));

    // All processors allocate memory for the buffer.
    vector<char> cbuffer(cbuffer_len, 'a');

    // The io processor fills the buffer from the string.
    if(comm->isIOProc()) {
        for (int i=0; i<cbuffer_len; i++) cbuffer[i] = s_in[i];
    }

    // The io processor broadcasts the buffer to everyone.
    char *cb = &cbuffer[0];
    comm->broadcast(cb, cbuffer_len);

    // On all the other processors, copy the buffer into the string.
    if(!comm->isIOProc()) {
        s_in.resize(cbuffer_len);
        for (int i=0; i<cbuffer_len; i++) s_in[i] = cbuffer[i];
    }
}



// ===========================================================================
// Get the next line from the buffer without any processing.
// Starting at the current position in the buffer, current_pos, search for
// the next \n. The output string is from the current position to the \n (but
// does not include the \n). Also remove any \r in the string.
// ===========================================================================
bool PowerParser::get_line_from_string(string &strn, string &sout, int &current_pos)
{
    // Default the output.
    sout = "";

    // If the current position is at or beyond the end of the input string,
    // then nothing further needs to be done.
    int strn_len = (int)strn.size();
    if (current_pos >= strn_len) return false;

    for (int i = current_pos; i<strn_len; i++) {
        // If we encounter an eol, then we are done.
        if (strn[i] == '\n') {
            current_pos = i+1;
            return true;
        }

        // Some systems use \r\n instead of \n only. Ignore any \r characters.
        if (strn[i] == '\r') continue;

        // If we get to this point, then all that remains is to add the
        // character to the output string.
        sout += strn[i];
    }

    // If we reach this point then we have gone through the entire input
    // string and have found that it does not end in a \n. This is ok and does
    // happen sometimes. We just set the current position to one past the
    // end of the buffer and return success.
    current_pos = strn_len;
    return true;
}


// ===========================================================================
// This is similar to the get_line_from_string() but this routine gets
// lines from the input string that are separated by semicolons.
// Starting at the current position in the buffer, current_pos, search for
// the next ;. The output string is from the current position to the ; (but
// does not include the ;).
// ===========================================================================
bool PowerParser::get_sc_line_from_string(string &strn, string &sout, int &current_pos)
{
    // Default the output.
    sout = "";

    // If the current position is at or beyond the end of the input string,
    // then nothing further needs to be done.
    int strn_len = (int)strn.size();
    if (current_pos >= strn_len) return false;

    bool ignore_sc = false;
    for (int i = current_pos; i<strn_len; i++) {
        if (strn[i] == '!') ignore_sc = true;
        if (strn[i] == '#') ignore_sc = true;
        if (i < strn_len-1) {
            if (strn[i] == '/' && strn[i+1] == '/') ignore_sc = true;            
        }

        // If we encounter a semicolon, then we are done.
        if (!ignore_sc) {
            if (strn[i] == ';') {
                current_pos = i+1;
                return true;
            }
        }

        // If we get to this point, then all that remains is to add the
        // character to the output string.
        sout += strn[i];
    }

    // If we reach this point then we have gone through the entire input
    // string and have found that it does not end in a ;. This is ok and does
    // happen sometimes. We just set the current position to one past the
    // end of the buffer and return success.
    current_pos = strn_len;
    return true;
}


// ===========================================================================
// Get rid of leading and trailing blanks and tabs.
// ===========================================================================
void PowerParser::eliminate_white_space(string &sline)
{
    int NPOS = (int)string::npos;

    // Eliminate leading stuff first.
    int len = (int)sline.size();
    if (len == 0) return;
    string whitespace = " \t";
    int istart = sline.find_first_not_of(whitespace, 0);
    if (istart == NPOS) istart = (int)sline.size();
    sline.erase(0, istart);

    // Now eliminate trailing stuff.
    len = (int)sline.size();
    if (len == 0) return;
    int iend = sline.find_last_not_of(whitespace, len - 1);
    if (iend == NPOS) return;
    sline.erase(iend+1, (len-1) -(iend+1) + 1);

    return;
}


// ===========================================================================
// Convert an array of characters into a vector of C++ strings.
//
// chars_1d   The array of characters (input). This is composed of a sequence
//            of strings, each one nchar long. The number of strings is nv.
// vstr       Vector of C++ strings (output). There will be nv number of
//            C++ strings in this vector. The length of each C++ string will
//            vary depending on how much white space is removed.
// nv         Number of strings in chars_1d (input).
// nchar      Number of characters in each string in chars_1d (input).
//
// Why would anyone want to do this?
// When passing strings between Fortran and C++ it is cleaner and easier to
// pass a packed array of single characters. This routine takes that packed
// array and converts it to something familiar to C++ developers.
// ===========================================================================
void PowerParser::chars_to_vstr(char *chars_1d, vector<string> &vstr,
                          int nv, int nchar)
{
    // Temporary storage for each string in the array of characters.
    char *cnchar = new char[nchar];

    // Loop through all the strings in the array of characters.
    for (int i=0; i<nv; i++) {

        // Copy each string in the 1d array into a temporary array of chars.
        // This will be used to create the C++ string.
        int istart = i * nchar;
        for (int c=istart; c<istart+nchar; c++) {
            cnchar[c-istart] = chars_1d[c];
        }
        int cnchar_len = nchar;

        // Remove trailing spaces.
        for (int c=nchar-1; c >= 0; c--) {
            if (cnchar[c] != ' ') {
                cnchar_len = c+1;
                break;
            }
        }

        // Create the C++ string.
        string s(cnchar,cnchar_len);

        // Remove leading spaces.
        int i2=0;
        for (int c=0; c<(int)s.size(); c++) {
            if (s[c] != ' ') {
                i2=c;
                break;
            }
        }
        if (i2 != 0) s.erase(s.begin(), s.begin()+i2);

        // Add the string to the vector of strings.
        vstr.push_back(s);
    }
    delete [] cnchar;
}


// ===========================================================================
// Convert  a vector of C++ strings into a packed array of characters.
//
// chars_1d   The array of characters (output). This is composed of a sequence
//            of strings, each one nchar long. The number of strings is nv.
// vstr       Vector of C++ strings (input). There will be nv number of
//            C++ strings in this vector. The length of each C++ string will
//            vary, whitespace is added to each C++ string to make its length
//            nchar.
// nv         Number of strings in chars_1d (input).
// nchar      Number of characters in each string in chars_1d (input).
//
// Why would anyone want to do this?
// When passing strings between Fortran and C++ it is cleaner and easier to
// pass a packed array of single characters. This routine takes the vector
// of strings and converts that to a packed character array.
// ===========================================================================
void PowerParser::vstr_to_chars(char *chars_1d, vector<string> &vstr,
                          int nv, int nchar)
{
    // To suppress compiler warnings of unused parameters
    assert(nv == nv);

    // Loop through each string in the vector of strings.
    for (int strdex=0; strdex<(int)vstr.size(); strdex++) {

        // Starting location in the 1d array of characters for each string.
        int i1d = strdex * nchar;

        // Number of characters in the C++ string. Should be smaller or 
        // equal to nchar, but we handle the case where it is larger
        // than nchar.
        int nc = (int)vstr[strdex].size();
        if (nc > nchar) nc = nchar;

        // Copy the string into the 1d character array.
        for (int c=i1d; c<i1d+nc; c++) {
            chars_1d[c] = vstr[strdex][c-i1d];
        }

        // Pad with blanks.
        for (int c=i1d+nc; c<i1d+nchar; c++) {
            chars_1d[c] = ' ';
        }
    }
}




} // end of PP namespace

