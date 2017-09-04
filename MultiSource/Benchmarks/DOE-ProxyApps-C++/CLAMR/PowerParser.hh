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
#ifndef PARSEHHINCLUDE
#define PARSEHHINCLUDE

// Need to include Cmd.hh because on the PGI compiler, the deque<Cmd>
// declaration did not work with just doing "class Cmd;", we need to fully
// include Cmd.hh. 
#include "Comm.hh"
#include <sstream>
#include <fstream>
#include "Word.hh"
#include "Cmd.hh"
#include "Restartblock.hh"
#include "Whenthen.hh"

/****************************************************************//**
 * PP is the namespace for PowerParser. Example:
 *
 *     using namespace PP;
 *******************************************************************/
namespace PP
{
using std::ofstream;
using std::streambuf;

/****************************************************************//**
 * PowerParser class 
 *    Provide a class that parses text files into lines and words.
 *******************************************************************/
class PowerParser
{

public:

    ofstream fileout;
    streambuf *coutbuf;

    // Constructors, destructors and drivers.
/****************************************************************//**
 * \brief
 * Constructor with no arguments
 *
 * Typical Usage   
 *
 *     PowerParser parse;
 *           or
 *     PowerParser *parse = new PowerParser();
 *******************************************************************/
    PowerParser(void);

/****************************************************************//**
 * \brief
 * Constructor -- with input filename in string format
 *
 * **Parameters**
 * * string filename[in] -- the input file. The file will be
 *    read in, broadcast, and then parsed
 *
 * Typical Usage
 *
 *     string fin("simfile.in");
 *     PowerParser parse(fin);
 *           or
 *     string fin("simfile.in");
 *     PowerParser *parse = new PowerParser(fin);
 *******************************************************************/
    PowerParser(string filename);

/****************************************************************//**
 * \brief
 *  Constructor -- with input filename in char array format
 *
 *  **Parameters**
 *  * const char *filename[in] -- the input file. The file will be
 *    read in, broadcast, and then parsed
 *
 * Typical Usage
 *
 *     PowerParser parse("simfile.in");
 *           or
 *     PowerParser *parse = new PowerParser("simfile.in");
 *******************************************************************/
    PowerParser(const char *filename);

/****************************************************************//**
 * \brief
 *  Destructor with no arguments
 *
 * Typical Usage   
 *
 *     delete parse;
 *******************************************************************/
    ~PowerParser(void);

    void dictionary_add(char *name, double value, bool pred, char *vdesc);
    void dictionary_env_add(char *name, bool pred);

/****************************************************************//**
 * \brief
 * Reads the file in on the IO processor, broadcast the string
 * to all the other processors, then parse the string.
 *
 * **Parameters**
 * * string filename
 *
 * Typical Usage
 *
 *     string fin("simfile.in");
 *     PowerParser parse();
 *     parse.parse_file(fin);
 *******************************************************************/
    void parse_file(string filename);

/****************************************************************//**
 * \brief
 * Reads the file in on the IO processor, broadcast the string
 * to all the other processors, then parse the string.
 *
 * **Parameters**
 * * const char *filename
 *
 * Typical Usage
 *
 *     PowerParser parse();
 *     parse.parse_file("simfile.in");
 *******************************************************************/
    void parse_file(const char *filename);

/****************************************************************//**
 * \brief
 * Given a multi-line string on every processor, parse it into cmds
 * and words. After calling this function, the parser is ready for use.
 *******************************************************************/
    void parse_string(string filename, string s_in);

/****************************************************************//**
 * \brief
 * The input file(s) has been read and put into commands. Now do the
 * compilation phase.
 *******************************************************************/
    void compile_buffer(int &return_value);

/****************************************************************//**
 * \brief
 * Handle the execution line arguments
 *******************************************************************/
    void handle_exe_args(string other_argggs);

/****************************************************************//**
 * \brief
 * Clear out the parser and re-init
 *******************************************************************/
    void clear_and_init();

/****************************************************************//**
 *******************************************************************/
    void store_exe_args(string &oargs, string &fname) {
        other_args = oargs;
        file_name = fname;
    }

/****************************************************************//**
 *******************************************************************/
    void get_exe_args(string &oargs, string &fname) {
        oargs = other_args;
        fname = file_name;
    }

/****************************************************************//**
 * \brief
 * String version of the driver for getting boolean values as integers.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * string &cname -- key word in input file
 * * int *cvalue -- variable to set in simulation code
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        string InputName("OutputGraphics");
 *        int iflag = 0;
 *        parse.get_bool_int(InputName, &iflag);
 *     or for arrays
 *        string InputName("OutputGraphicsTypes");
 *        vector<int> iflags[2] = {0, 0};
 *        vector<int> size = {2};
 *        parse.get_bool_int(InputName, &iflags[0], size);
 *******************************************************************/
    void get_bool_int(string &cname,
                      int *cvalue,
                      const vector<int> &size = vector<int>(), // optional argument
                      bool skip = false);                      // optional argument

/****************************************************************//**
 * \brief
 * String version of the driver for getting boolean values.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * string &cname -- key word in input file
 * * bool *cvalue -- variable to set in simulation code
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        string InputName("OutputGraphics");
 *        bool iflag = 0;
 *        parse.get_bool(InputName, &iflag);
 *     or for arrays
 *        string InputName("OutputGraphicsTypes");
 *        vector<bool> iflags[2] = {0, 0};
 *        vector<int> size = {2};
 *        parse.get_bool(InputName, &iflags[0], size);
 *******************************************************************/
    void get_bool(string &cname,
                  bool *cvalue,
                  const vector<int> &size = vector<int>(),     // optional argument
                  bool skip = false);                          // optional argument

/****************************************************************//**
 * \brief
 * String version of the driver for getting integer values.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * const char *cname -- key word in input file
 * * int *cvalue -- variable to set in simulation code. Int can be
 *      either standard int or long long int
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        int ivalue = 0;
 *        parse.get_int("Num_Cycles", &ivalue);
 *     or for arrays
 *        vector<int> ivalue[2] = {0, 0};
 *        vector<int> size = {2};
 *        parse.get_int("Dimensions", &ivalue[0], size);
 *******************************************************************/
    template< typename T >
    void get_int(string &cname,
                 T *cvalue,
                 const vector<int> &size = vector<int>(),      // optional argument
                 bool skip = false);                           // optional argument

/****************************************************************//**
 * \brief
 * String version of the driver for getting real values.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * const char *cname -- key word in input file
 * * double *cvalue -- variable to set in simulation code.
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        double rvalue = 0;
 *        parse.get_real("TimeStop", &rvalue);
 *     or for arrays
 *        vector<double> rvalues[2] = {0.0, 0.0};
 *        vector<int> size = {2};
 *        parse.get_real("DumpTimes", &rvalues[0], size);
 *******************************************************************/
    void get_real(string &cname,
                  double *cvalue,
                  const vector<int> &size = vector<int>(),     // optional argument
                  bool skip = false);                          // optional argument

/****************************************************************//**
 *******************************************************************/
    void get_char(string &cname,
                  vector<string> &vstr,
                  const vector<int> &size = vector<int>(),     // optional argument
                  bool single_char = false,                    // optional argument
                  bool skip = false);                          // optional argument

    // These are just convenience function to allow char arrays for get variable so
    // the calls are simpler. They convert the cname to a string and call the 
    // string versions above

/****************************************************************//**
 * \brief
 * Char array version of the driver for getting boolean values as integers.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * const char *cname -- key word in input file
 * * int *cvalue -- variable to set in simulation code
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        int iflag = 0;
 *        parse.get_bool_int("OutputGraphics", &iflag);
 *     or for arrays
 *        vector<int> iflags[2] = {0, 0};
 *        vector<int> size = {2};
 *        parse.get_bool_int("OutputGraphicsTypes", &iflags[0], size);
 *******************************************************************/
    void get_bool_int(const char *cname,
                      int *cvalue,
                      const vector<int> &size = vector<int>(), // optional argument
                      bool skip = false);                      // optional argument

/****************************************************************//**
 * \brief
 * Char array version of the driver for getting boolean values.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * const char *cname -- key word in input file
 * * bool *cvalue -- variable to set in simulation code
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        bool iflag = 0;
 *        parse.get_bool("OutputGraphics", &iflag);
 *     or for arrays
 *        vector<bool> iflags[2] = {0, 0};
 *        vector<int> size = {2};
 *        parse.get_bool("OutputGraphicsTypes", &iflags[0], size);
 *******************************************************************/
    void get_bool(const char *cname,
                  bool *cvalue,
                  const vector<int> &size = vector<int>(),     // optional argument
                  bool skip = false);                          // optional argument

/****************************************************************//**
 * \brief
 * Char array version of the driver for getting integer values.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * const char *cname -- key word in input file
 * * int *cvalue -- variable to set in simulation code. Int can be
 *      either standard int or long long int
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        int ivalue = 0;
 *        parse.get_int("Num_Cycles", &ivalue);
 *     or for arrays
 *        vector<int> ivalue[2] = {0, 0};
 *        vector<int> size = {2};
 *        parse.get_int("Dimensions", &ivalue[0], size);
 *******************************************************************/
    template< typename T >
    void get_int(const char *cname,
                 T *cvalue,
                 const vector<int> &size = vector<int>(),      // optional argument
                 bool skip = false);                           // optional argument

/****************************************************************//**
 * \brief
 * Char array version of the driver for getting real values.
 * This works for arrays of any dimension, 0,1,2,3,...
 *
 * **Parameters**
 * * const char *cname -- key word in input file
 * * double *cvalue -- variable to set in simulation code.
 * * const vector<int> &size = vector<int>() -- sizes of array,
 *      (default is null for a scalar).
 * * bool skip = false -- skip setting variable, (default is false)
 *
 * Typical Usage
 *
 *     for scalars
 *        double rvalue = 0;
 *        parse.get_real("TimeStop", &rvalue);
 *     or for arrays
 *        vector<real> rvalue[2] = {0.0, 0.0};
 *        vector<int> size = {2};
 *        parse.get_real("DumpTimes", &rvalue[0], size);
 *******************************************************************/
    void get_real(const char *cname,
                  double *cvalue,
                  const vector<int> &size = vector<int>(),     // optional argument
                  bool skip = false);                          // optional argument

/****************************************************************//**
 *******************************************************************/
    void get_char(const char *cname,
                  vector<string> &vstr,
                  const vector<int> &size = vector<int>(),     // optional argument
                  bool single_char = false,                    // optional argument
                  bool skip = false);                          // optional argument


/****************************************************************//**
 * \brief
 * Driver for getting array sizes.
 *******************************************************************/
    void get_size(string &cname, vector<int> &size);

/****************************************************************//**
 * \brief
 * Driver for getting array sizes. Version to get all sizes
 *******************************************************************/
    void get_sizeb(string &cname, vector<int> &size);


/****************************************************************//**
 * \brief
 * Check if the input command, cname, appears in the final, parsed user input.
 *
 * The two outputs are in_input and in_whenthen,
 *    in_input     command is in (or not) the main part of the input, i.e.
 *                 everything except the when...then statements.
 *    in_whenthen  command is in (or not) at least one when...then statement.
 *******************************************************************/
    void cmd_in_input(string &cname, bool &in_input, bool &in_whenthen);

/****************************************************************//**
 * \brief
 * Set the processed flag for all words for all commands that match cname.
 * The value to set the processed flag to is bval.
 * This sets the processed flag for commands in the final buffer and in the
 * when...then final buffers.
 *******************************************************************/
    void cmd_set_processed(string &cname, bool bval);

/****************************************************************//**
 * \brief
 * Check all processed flags on every command. If any word on any command
 * has not been processed, then that is a fatal error.
 *******************************************************************/
    void check_processed(bool &good);

/****************************************************************//**
 * \brief
 * If commands appear more than once in the input file(s), print a warning
 * to the user.
 *******************************************************************/
    void check_duplicates();


/****************************************************************//**
 * \brief
 * Echo user input to a stringstream.
 *******************************************************************/
    void echo_input_start();

/****************************************************************//**
 * \brief
 * Echo user input to a stringstream.
 *******************************************************************/
    void echo_input_ss(stringstream &ssinp);

/****************************************************************//**
 * Get a line from the ssfout stringstream. (low-level function)
 *******************************************************************/
    bool get_ssfout_line(string &sline);

    // Communications object from the infrastructure.
/****************************************************************//**
 * \brief
 *  Holds internal comm class for PowerParser. Comm is initialized
 *  automatically and will use an already initialized MPI or 
 *  initialize it itself.  This is meant to be for use internal to
 *  the package, but developers can get the number of processors
 *  and rank with
 *
 *      int mype = parse->comm->getProcRank();
 *      int npes = parse->comm->getNumProcs();
 *******************************************************************/
    Comm *comm;

/****************************************************************//**
 *******************************************************************/
    void list_funcs_start();

/****************************************************************//**
 *******************************************************************/
    void list_vars_start();

/****************************************************************//**
 *******************************************************************/
    void list_cmdsf_start();

/****************************************************************//**
 *******************************************************************/
    void list_wt_cmdsf_start();

    void process_error_global(int &return_value);


    void rb_check(vector<string> &code_varnames,
                  vector<string> &code_values,
                  vector<int> &vv_active, int *rbci,
                  int *rb_ntriggered, int *rb_triggered_indices);
    int  get_rb_num_varnames();
    void get_rb_varnames(vector<string> &rb_varnames_vstr);
    void get_num_rb(int *rbnum) { *rbnum = (int)restartblocks.size(); }
    void set_num_rb(int rbnum)  { nrb_on_dump = rbnum; }
    void get_rb_names(vector<string> &rb_names_vstr);
    void set_rb_names(vector<string> &rb_names_vstr);
    void get_rb_aflags(int *rb_aflags);
    void set_rb_aflags(int *rb_aflags, int rb_num);
    void get_rb_satsize(int *rb_satsize);
    void set_rb_satsize(int rb_satsize);
    void get_rb_satprb(int *rb_satprb);
    void set_rb_satprb(int *rb_satprb, int rb_num);
    void get_rb_sat(int *rb_sat);
    void set_rb_sat(int *rb_sat, int rb_satsize);
    void list_rb();
    void list_rb_start();
    void list_rb_ss(stringstream &ssc);
    void list_rb1_start(int *rb);
    void list_rb1_ss(stringstream &ssc, int *rbp);
    void list_one_rb_ss(stringstream &ssc, int rb);


    void get_num_whenthen(int *wtnum) { *wtnum = (int)whenthens.size(); }
    void wt_check(int wtn, vector<string> &code_varnames,
                  vector<string> &code_values,
                  vector<int> &vv_active, int *wtci);
    void wt_set_cmdsfp(int wtn);
    void wt_reset();
    void wt_casize(int wtn, int *wt_casize);
    void wt_carray(int wtn, char *wt_ca, int wt_casize);

    void wt_satsize(int wtn, int *wt_satsize);
    void wt_getsat(int wtn, int *wt_sat, int wt_satsize);
    void wt_setsat(int wtn, int *wt_sat, int wt_satsize);
    void wt_getprocessed(int wtn, int *wtp);
    void wt_setprocessed(int wtn, int wtp);
    void wt_getseq(int wtn, int *wtseq);
    void wt_setseq(int wtn, int wtseq);

    void chars_to_vstr(char *chars_1d, vector<string> &vstr,
                       int nv, int nchar);
    void vstr_to_chars(char *chars_1d, vector<string> &vstr,
                       int nv, int nchar);

    void ListIncludeFiles();
    int NumIncludeFiles();
    string GetIncludeFile(int);



private:

    void init();
    int  process_dav_cmd();
    void check_dup_scalar(int wtn, bool &found_any);
    void set_dup_row(vector<string> &row, Cmd &cmdi, int iw);
    void remove_dup_scalar(int wtn);
    void read_into_string(string filename, string &s_in);
    void broadcast_buffer(string &s_in);
    bool get_line_from_string(string &strn, string &sout, int &current_pos);
    bool get_sc_line_from_string(string &strn, string &sout, int &current_pos);
    void store_line_strings(string &s_in);
    void eliminate_white_space(string &sline);
    void cmd_set_reprocessed(bool bval);
    int  process_error_return_int(stringstream &serr, int &ierr);
    void process_error(stringstream &serr, int &ierr);

    void list_vars(string lv1, string lv2, string var_to_list);
    void list_vars_ss(string lv1, string lv2, string var_to_list,
                      stringstream &ssvars);

    void list_funcs(string lf1, string lf2);
    void list_funcs_ss(string lf1, string lf2, stringstream &ssfunc);

    void list_cmdsf(string lc1, string lc2);
    void list_cmdsf_ss(string lc1, string lc2,
                       stringstream &ssc);
    void list_wt_cmdsf();
    void list_wt_cmdsf_ss(stringstream &ssc);

    void print_strings(vector< vector<string> > rows, int n_header_rows,
                       int offset, int col_spacing, int line_len_max,
                       stringstream &ss);
    bool end_do_loop(int &i, deque<int> &do_start,
                     stringstream &serr, int &ierr);
    void end_do_ret(int &i, deque<int> &do_start,
                    stringstream &serr, int &ierr);
    void check_enddo(deque<int> &do_start, stringstream &serr, int &ierr);
    int  jump_to_call(int &i, deque<int> &icall, deque<int> &isub,
                      stringstream &serr, int &ierr);
    int  jump_to_sub(int &i, string &sub_name,
                     stringstream &serr, int &ierr);
    void print_line(int i);
    void print_line(Cmd &cmd);

    // Store exe line arguments.
    string other_args, file_name;

    // A double ended queue for storing the original lines. This is
    // before the lines get turned into Cmds. 
    // line_number is an index into cmd_strings, note that it starts
    // from 1, not 0.
    deque<string> cmd_strings;
    int line_number;

    // Define a map for a set of variables.
    map<string, Variable> vmap;
    
    // Maintain a list of included files

    std::map<int,string> IncludeFiles;

    // Define a map for the functions.
    map<string, Function> fmap;

    // A double ended queue for storing the commands.
    deque<Cmd> cmds;
    deque<Cmd> cmdsf;
    deque<Cmd> *cmdsfp;

    // Store cmd names that have been processed, used for clearing and
    // recreating the parser.
    deque<string> processed_cmd_names;

    // Related to writing output to a fortran file.
    int ssfout_current_pos;
    stringstream ssfout;

    // Used for storing the list of pre-defined variables to be printed
    // out later.
    stringstream pre_defined_varss;

    // Used for storing multiple errors and processing them later.
    stringstream serr_global;
    int ierr_global;

    // The execution line arguments are put in this string.
    string exe_args_str;

    // The when ... then objects.
    deque<Whenthen> whenthens;

    // Restart blocks.
    deque<Restartblock> restartblocks;
    int nrb_on_dump;
    deque<string> bnames_on_dump;
    deque<bool> baflags_on_dump;
    int satsize_on_dump;
    deque<bool> rbsat_on_dump;
    deque<int> rbsatprb_on_dump;

    // Flag for whether duplicate array values will be none, fatal, or
    // a warning, determined by the duplicate_array_values command.
    //    dup_fatal = 0     Turn off duplicate array value checking
    //    dup_fatal = 1     Duplicate array value checking is a warning
    //    dup_fatal = 2     Duplicate array value checking is a fatal error
    int dup_fatal;
};

} // end of PP namespace

#endif
