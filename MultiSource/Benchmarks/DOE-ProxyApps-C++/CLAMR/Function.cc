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
// This class holds information about a function. It is mostly for use with
// the parser.
// ***************************************************************************
// ***************************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <cctype>
#include <cmath>

#include "stdio.h"
#include "stdlib.h"

#include "Function.hh"

namespace PP
{
using std:: string;
using std::cout;
using std::endl;
using std::deque;
using std::stringstream;
using std::setprecision;
using std::vector;


// ===========================================================================
// Default constructor.
// ===========================================================================
Function::Function()
{
   name = "__NO_NAME_GIVEN__";
   external = true;
   nargs = 1;
   description = " ";
   type = "real";
}


// ===========================================================================
// Most used constructor for functions.
// ===========================================================================
Function::Function(string nme, bool ext, int na, string ftype, string fdes)
{
   name = nme;
   external = ext;
   nargs = na;
   description = fdes;
   type = ftype;
}


// ===========================================================================
// Evaluate the function. This is for the case that the arguments all have
// values (double type values) and the function can be evaluated to a double.
// ===========================================================================
double Function::evaluate(vector<double> &vd, stringstream &serr, int &ierr,
                          int line_number, int file_line_number,
                          string filename, deque<string> *lines)
{
    // Verify that the number of args needed is equal to the number of args
    // supplied.
    int nvd = (int)vd.size();
    if (nvd != nargs) {
        args_mismatch_err(nvd, nargs, serr, ierr, line_number,
                          file_line_number, filename, lines);
        return 0.;
    }

    // Functions with one argument.
    if (nargs == 1) {
        double d = vd[0];
        if (name == "acos") {
            if (d < -1. || d > 1.) {
                serr << endl;
                serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
                serr << "    " << (*lines)[line_number-1] << endl;
                serr << "in file: " << filename << endl;
                serr << "Argument to acos is out of bounds." << endl;
                serr << "Argument = " << d << endl;
                serr << "This must be between -1. and 1." << endl;
                ierr = 2;
                return 0.;
            }
            return acos(d);
        }

        if (name == "asin") {
            if (d < -1. || d > 1.) {
                serr << endl;
                serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
                serr << "    " << (*lines)[line_number-1] << endl;
                serr << "in file: " << filename << endl;
                serr << "Argument to asin is out of bounds." << endl;
                serr << "Argument = " << d << endl;
                serr << "This must be between -1. and 1." << endl;
                ierr = 2;
                return 0.;
            }
            return asin(d);
        }

        if (name == "atan")  return atan(d);
        if (name == "ceil")  return ceil(d);
        if (name == "cos")   return cos(d);
        if (name == "cosh")  return cosh(d);
        if (name == "exp")   return exp(d);
        if (name == "fabs")  return fabs(d);
        if (name == "floor") return floor(d);
        if (name == "log")   return log(d);
        if (name == "log10") return log10(d);
        if (name == "sin")   return sin(d);
        if (name == "sinh")  return sinh(d);
        if (name == "sqrt")  return sqrt(d);
        if (name == "tan")   return tan(d);
        if (name == "tanh")  return tanh(d);
    }

    // Functions with two arguments.
    if (nargs == 2) {
        double d1 = vd[0];
        double d2 = vd[1];

        if (name == "atan2") return atan2(d1, d2);
        if (name == "fmod") return fmod(d1, d2);

        if (name == "max") {
            double result = d2;
            if (d1 > d2) result = d1;
            return result;
        }

        if (name == "min") {
            double result = d2;
            if (d1 < d2) result = d1;
            return result;
        }

        if (name == "pow") {
            if (d1 <= 0.) {
                serr << endl;
                serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
                serr << "    " << (*lines)[line_number-1] << endl;
                serr << "in file: " << filename << endl;
                serr << "First argument (base) to pow is out of bounds." << endl;
                serr << "Argument = " << d1 << endl;
                serr << "This must be greater than 0." << endl;
                ierr = 2;
                return 0.;
            }
            return pow(d1, d2);
        }
    }


    // If we get down to this point, then the name supplied at
    // construction was not recognized as a function name.
    // This should never happen because we check for a valid function
    // name before entering this function.
    name_err(serr, ierr, line_number, file_line_number, filename, lines);
    return 0.;
}


// ===========================================================================
// Evaluate the function. This is for string functions.
// ===========================================================================
string Function::evaluate(vector<string> &vs, stringstream &serr, int &ierr,
                          int line_number, int file_line_number,
                          string filename, deque<string> *lines)
{
    // Verify that the number of args needed is equal to the number of args
    // supplied.
    int nvs = (int)vs.size();
    if (nvs != nargs) {
        args_mismatch_err(nvs, nargs, serr, ierr, line_number,
                          file_line_number, filename, lines);
        return "";
    }

    // Functions with one argument.
    if (nargs == 1) {
        string s1 = vs[0];
        if (name == "strlen") {
            int len = (int)s1.size();
            stringstream ss;
            ss << len;
            return ss.str();
        }

        if (name == "strtrim") {
            int len = (int)s1.size();
            if (len == 0) return s1;
            string whitespace = " \t";
            int iend = s1.find_last_not_of(whitespace, len - 1);
            int NPOS = (int)string::npos;
            if (iend == NPOS) return s1;
            s1.erase(iend+1, (len-1) -(iend+1) + 1);
            return s1;
        }
    }

    // Functions with two arguments.
    if (nargs == 2) {
        string s1 = vs[0];
        string s2 = vs[1];
        if (name == "strcat") {
            return s1+s2;
        }
    }

    // Functions with three arguments.
    if (nargs == 3) {
        string s1 = vs[0];
        string s2 = vs[1];
        string s3 = vs[2];
        if (name == "strerase") {
            int i1 = atoi(s2.c_str()) - 1;   // minus 1 to get c index
            int i2 = atoi(s3.c_str()) - 1;
            s1.erase(i1, i2-i1+1);
            return s1;
        }

        if (name == "strinsert") {
            int i1 = atoi(s2.c_str()) - 1;   // minus 1 to get c index
            s1.insert(i1, s3);
            return s1;
        }

        if (name == "strsubstr") {
            int i1 = atoi(s2.c_str()) - 1;     // minus 1 to get c index
            int nchar = atoi(s3.c_str()); 
            string sret = s1.substr(i1, nchar);
            return sret;
        }
    }

    // If we get down to this point, then the name supplied at
    // construction was not recognized as a function name.
    // This should never happen because we check for a valid function
    // name before entering this function.
    name_err(serr, ierr, line_number, file_line_number, filename, lines);
    return "";
}


// ===========================================================================
// Name not recognized error.
// ===========================================================================
void Function::name_err(stringstream &serr, int &ierr,
                        int line_number, int file_line_number,
                        string filename, deque<string> *lines)
{
    serr << endl;
    serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
    serr << "    " << (*lines)[line_number-1] << endl;
    serr << "in file: " << filename << endl;
    serr << "** Math function fatal error **" << endl;
    serr << "Name not recognized as a function." << endl;
    serr << "Name = " << name << endl;
    ierr = 2;
}


// ===========================================================================
// Number of args mismatch error.
// ===========================================================================
void Function::args_mismatch_err(int nargs_found, int nargs_expected,
                                 stringstream &serr, int &ierr,
                                 int line_number, int file_line_number,
                                 string filename, deque<string> *lines)
{
    serr << endl;
    serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
    serr << "    " << (*lines)[line_number-1] << endl;
    serr << "in file: " << filename << endl;
    serr << "For function " << name << endl;
    serr << "Number of args expected = " << nargs_expected << endl;
    serr << "Number of args found = " << nargs_found << endl;
    ierr = 2;
}

} // End of the PP namespace
