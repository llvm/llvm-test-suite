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
// This class holds each word from the line.
// ***************************************************************************
// ***************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <deque>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef SGI
#else
#include <cctype>
#endif

#include "Word.hh"

namespace PP
{
using std::string;
using std::cout;
using std::endl;
//using std::isdigit;
using std::stringstream;
using std::setprecision;
using std::vector;
using std::map;
using std::deque;
using std::pair;


// ===========================================================================
// Default constructor.
// ===========================================================================
Word::Word() 
{
    wstr = "";
    init();
}


// ===========================================================================
// Construct given a string.
// ===========================================================================
Word::Word(string s)
{
    wstr = s;
    init();
    set_type();
}


// ===========================================================================
// Construct given a string. Also set the map of variables.
// ===========================================================================
Word::Word(string s, int lnum, int file_lnum, string fname,
           deque<string> *lstr)
{
    wstr = s;
    init();
    line_number = lnum;
    file_line_number = file_lnum;
    filename = fname;
    lines = lstr;
    set_type();
}


// ===========================================================================
// Construct given a double
// ===========================================================================
Word::Word(double d, int lnum, int file_lnum, string fname,
           deque<string> *lstr)
{
    stringstream ss;
    ss << setprecision(15) << d;
    wstr = ss.str();
    init();
    type = DOUBLE;
    line_number = lnum;
    file_line_number = file_lnum;
    filename = fname;
    lines = lstr;
}


// ===========================================================================
// Construct given an integer.
// ===========================================================================
Word::Word(int ia, int lnum, int file_lnum, string fname,
           deque<string> *lstr)
{
    stringstream ss;
    ss << ia;
    wstr = ss.str();
    init();
    type = DOUBLE;
    line_number = lnum;
    file_line_number = file_lnum;
    filename = fname;
    lines = lstr;
}


// ===========================================================================
/*! = operator. */
// ===========================================================================
Word Word::operator=(const Word &ws) 
{
   if (&ws == this) return *this;
   wstr = ws.wstr;
   processed = ws.processed;
   type = ws.type;
   negate = ws.negate;
   line_number = ws.line_number;
   file_line_number = ws.file_line_number;
   filename = ws.filename;
   lines = ws.lines;
   multiplicity = ws.multiplicity;
   op_level = ws.op_level;
   op_type = ws.op_type;
   return *this;
}


// ===========================================================================
/*! Copy constructor. */
// ===========================================================================
Word::Word(const Word &ws) 
{
   wstr = ws.wstr;
   processed= ws.processed;
   type = ws.type;
   negate = ws.negate;
   line_number = ws.line_number;
   file_line_number = ws.file_line_number;
   filename = ws.filename;
   lines = ws.lines;
   multiplicity = ws.multiplicity;
   op_level = ws.op_level;
   op_type = ws.op_type;
}


// ===========================================================================
// Common initialization routine called from constructors.
// ===========================================================================
void Word::init()
{
    processed = false;
    type = WUNKNOWN;
    negate = false;
    lines = NULL;
    line_number = 0;
    file_line_number = 0;
    filename = "";
    multiplicity = 1;
    op_level = -1;
    op_type = "";
}



// ===========================================================================
/*! Destructor */
// ===========================================================================
Word::~Word()
{
}


// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// Change the value of a word.
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Set the word to a double.
// ===========================================================================
void Word::set_value(double d)
{
    stringstream ss;
    ss << setprecision(15) << d;
    wstr = ss.str();
    set_type();
}


// ===========================================================================
// Set the word to a string.
// ===========================================================================
void Word::set_value(string s)
{
    wstr = s;
    set_type();
}


// ===========================================================================
// Set the word to a string.
// Use this when you want to do set_value("lasjdf"), otherwise c++ cannot
// get which set_type to use (and it does not tell you it is having trouble).
// ===========================================================================
void Word::set_value(const char *s)
{
    wstr = s;
    set_type();
}


// ===========================================================================
// Set the word to a boolean.
// ===========================================================================
void Word::set_value(bool b)
{
    if (!b) wstr = "false";
    if (b)  wstr = "true";
    set_type();
}




// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// This section handles the type of the word, whether it is an operator,
// a function, a string, etc.
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************


// ===========================================================================
/*! Set the type of word. */
// ===========================================================================
void Word::set_type()
{
   // Make sure the type is initialized. If the word is not anything else,
   // then it is a string.
   type = WSTRING;

   // Just for convenience.
   int len = (int)wstr.size();

   // First determine if the word starts and ends with quotes. If it does,
   // then it is a string. We do not strip off the quote symbols at this
   // point because we might be in a comment region where the quotes donot
   // matter. Later after the comments are stripped out, we check for
   // matching quotes and remove them.
   if ((wstr[0] == '\"') || (wstr[0] == '\'') ||
       (wstr[len-1] == '\"') || (wstr[len-1] == '\'')) {
      type = WSTRING;
      //wstr.erase(wstr.end() - 1);
      //wstr.erase(wstr.begin());
      return;
   }

   // Check for a delimiter.
   if (wstr == "(") { type = OPEN_PARENS; return; }
   if (wstr == ")") { type = CLOSED_PARENS; return; }
   if (wstr == "[") { type = OPEN_SQUARE_BRACKET; return; }
   if (wstr == "]") { type = CLOSED_SQUARE_BRACKET; return; }
   if (wstr == "{") { type = OPEN_BRACE; return; }
   if (wstr == "}") { type = CLOSED_BRACE; return; }

   // Comma is used for a couple of things.
   if (wstr == ",") { type = COMMA; return; }

   // Variables always begin with $. Of course, if the word is in quotes it is
   // not a variable even if it does begin with $.
   if (wstr[0] == '$') { type = VARIABLE; return; }

   // Check for an operator.
   if (wstr == "++")    { type=OPERATOR; op_level=7; op_type="arithmetic"; return; }
   if (wstr == "--")    { type=OPERATOR; op_level=7; op_type="arithmetic"; return; }

   if (wstr == "**")    { type=OPERATOR; op_level=6; op_type="arithmetic"; return; }

   // Do not implement the % operator, it is too much like the fortran %
   // operator which is for referencing components of a fortran structure.
   //if (wstr == "%")     { type=OPERATOR; op_level=5; op_type="arithmetic"; return; }
   if (wstr == "*")     { type=OPERATOR; op_level=5; op_type="arithmetic"; return; }
   if (wstr == "/")     { type=OPERATOR; op_level=5; op_type="arithmetic"; return; }

   if (wstr == "+")     { type=OPERATOR; op_level=4; op_type="arithmetic"; return; }
   if (wstr == "-")     { type=OPERATOR; op_level=4; op_type="arithmetic"; return; }

   if (wstr == ".gt.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".ge.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".lt.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".le.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".eq.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".ne.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }

   if (wstr == ".hggt.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".hgge.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".hglt.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".hgle.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".hgeq.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }
   if (wstr == ".hgne.")  { type=OPERATOR; op_level=3; op_type="relational"; return; }

   if (wstr == ".not.") { type=OPERATOR; op_level=2; op_type="logical";    return; }

   if (wstr == ".and.") { type=OPERATOR; op_level=1; op_type="logical";    return; }

   if (wstr == ".or.")  { type=OPERATOR; op_level=0; op_type="logical";    return; }

   // Equals sign.
   if (wstr == "=")  { type = EQUALS; return; }

   // At this point the word is either a string or a number.

   // If the word begins with a + or - sign, then it is numeric.
   bool start_with_pm = false;
   if (wstr[0] == '+') start_with_pm = true;
   if (wstr[0] == '-') start_with_pm = true;

   // If the word does not begin with a + or - sign or a digit, or a
   // ., or an e or a d then it is a string.
   if (!start_with_pm) {
       if(!isdigit(wstr[0])) {
           if (wstr[0] != '.') {
               if (wstr[0] != 'e') {
                   if (wstr[0] != 'E') {
                       if (wstr[0] != 'd') {
                           if (wstr[0] != 'D') {
                               type = WSTRING; return;
                           }
                       }
                   }
               }
           }
       }
   }

   // Check for all digits, i.e. an integer.
   bool is_number = true;
   int istart = 0;
   if (start_with_pm) istart = 1;
   for (int i=istart; i<(int)wstr.size(); i++) {
      if (!isdigit(wstr[i])) {
         is_number = false;
         break;
      }
   }
   if (is_number) { type = INTEGER; return; }

   // Check for floating point.
   // If there is anything in the string that is not a component of a
   // floating point number, then that makes it a string.
   is_number = true;
   for (int i=0; i<(int)wstr.size(); i++) {
      if (!isdigit(wstr[i]) && wstr[i]!='.' && wstr[i]!='e' && wstr[i]!='E' &&
          wstr[i]!='d' && wstr[i]!='D' && wstr[i]!='+' && wstr[i]!='-') {
         is_number = false;
         break;
      }
   }
   //if (is_number) { type = DOUBLE; return; }
   if (!is_number) { type = WSTRING; return; }

   // We suspect a floating point number.
   // At this point, everything in the string is a component of a floating
   // point number, i.e.  "+ - digit e E d D ."
   type = DOUBLE;

   // Check that strings that start with "e E d D" really are numbers.
   // And for numbers like e+01, e-05, etc, the atof or strtod functions do not
   // interpret those as numbers, therefore we insert a 1 in front of the e
   // so that atof and strtod will call it a number.
   if (wstr[0] == 'e' || wstr[0] == 'E' || wstr[0] == 'd' || wstr[0] == 'D') {

       // Check for proper syntax after the "e E d D".
       if (!check_after_e(wstr, 1, (int)wstr.size()-1)) {
           type = WSTRING;
           return;
       }

       // This appears to be a number, insert the digit.
       wstr.insert(0, "1");
       return;
   }

   // The string appears to be a floating point number (fpn), check syntax.
   // First, find the location of the "e E d D". Check that there can be
   // only one "e E d D" in the string.
   int ie = -1;
   for (int i=0; i<(int)wstr.size(); i++) {
       if (wstr[i] == 'e' || wstr[i] == 'E' || wstr[i] == 'd' ||
           wstr[i] == 'D') {
           ie = i;
           break;
       }
   }
   if (ie > -1) {
       for (int i=ie+1; i<(int)wstr.size(); i++) {
           if (wstr[i] == 'e' || wstr[i] == 'E' || wstr[i] == 'd' ||
               wstr[i] == 'D') {
               type = WSTRING;
               return;
           }
       }
   }

   // Check that the characters before the "e E d D" are valid. If no
   // "e E d D" was found then check the entire string as if it preceeded
   // an "e E d D".
   int ic1 = 0;
   int ic2 = (int)wstr.size() - 1;
   if (ie > -1) {
       ic2 = ie - 1;
   }
   if (!check_before_e(wstr, ic1, ic2)) {
       type = WSTRING;
       return;
   }

   // All other cases handled, this must be a fpn (type DOUBLE).
   return;
}


// ===========================================================================
// The input string, s, could be a floating point number (fpn). It has been
// determined that s contains an "e E d D" located at position i2+1. Check
// everything before the "e E d D", postions i1 through i2 inclusive to
// verify that this is a fpn.
//
// It is also possible that an "e E d D" was not found in which case the
// entire string is checked as if it preceeded an "e E d D".
//
// Return false if this is a string
//        true  if this could be a fpn
// ===========================================================================
bool Word::check_before_e(string s, int i1, int i2)
{
    // If there is nothing before the "e E d D" then this still could be a fpn.
    int size = i2 - i1 + 1;
    if (size < 1) return true;
           
    // The first character could be "+ -", but the remaining characters
    // cannot be "+ -".
    int ie1 = i1;
    if (s[i1] == '+' || s[i1] == '-') ie1 = i1+1;
    for (int i=ie1; i<=i2; i++) {
        if (s[i] == '+' || s[i] == '-') return false;
    }

    // Locate the optional "." character. There can only be one ".".
    int pointdex = -1;
    for (int i=ie1; i<=i2; i++) {
        if (s[i] == '.') {
            pointdex = i;
            break;
        }
    }
    if (pointdex > -1) {
        for (int i=pointdex+1; i<=i2; i++) {
            if (s[i] == '.') return false;
        }
    }


    // Everything before and after the point must be a digit (except
    // that the very first character could be "+ -").
    if (pointdex > -1) {
        for (int i=ie1; i<pointdex; i++) {
            if (!isdigit(s[i])) return false;
        }
        for (int i=pointdex+1; i<=i2; i++) {
            if (!isdigit(s[i])) return false;
        }
    }

    // If there is no point then everything must be digits (except
    // that the very first character could be "+ -").
    if (pointdex == -1) {
        for (int i=ie1; i<=i2; i++) {
            if (!isdigit(s[i])) return false;
        }
    }

    // All other cases handled, this could be a fpn.
    return true;
}
    

// ===========================================================================
// The input string, s, could be a floating point number (fpn). It has been
// determined that s contains an "e E d D" located at position i1-1. Check
// everything after the "e E d D", postions i1 through i2 inclusive to
// verify that this is a fpn.
//
// Return false if this is a string
//        true  if this could be a fpn
// ===========================================================================
bool Word::check_after_e(string s, int i1, int i2)
{
    // If there is nothing after the "e E d D" then that is not a number.
    int size = i2 - i1 + 1;
    if (size < 1) return false;
           
    // The character following the "e E d D" must be "+ - digit"
    if (s[i1] != '+' && s[i1] != '-' && (!isdigit(s[i1])))
        return false;

    // Everything after the e or e+ or e- must be a digit.
    int ie1 = i1;
    if (s[i1] == '+' || s[i1] == '-') ie1 = i1+1;
    for (int i=ie1; i<=i2; i++) {
        if (!isdigit(s[i])) return false;
    }

    // All other cases handled, this could be a fpn.
    return true;
}
    


// ===========================================================================
/*! Print the type of word. */
// ===========================================================================
void Word::print_type(stringstream &ss)
{
   if (type == WUNKNOWN) ss << "unknown";
   if (type == WSTRING) ss << "string";
   if (type == INTEGER) ss << "integer";
   if (type == DOUBLE) ss << "double";
   if (type == EQUALS) ss << "=";
   if (type == OPERATOR) ss << "operator";
   if (type == OPEN_PARENS) ss << "(";
   if (type == CLOSED_PARENS) ss << ")";
   if (type == OPEN_SQUARE_BRACKET) ss << "[";
   if (type == CLOSED_SQUARE_BRACKET) ss << "]";
   if (type == OPEN_BRACE) ss << "{";
   if (type == CLOSED_BRACE) ss << "}";
   if (type == COMMA) ss << ",";
   if (type == VARIABLE) ss << "variable";
}


// ===========================================================================
// Check to see if the word is boolean (true or false)
// ===========================================================================
bool Word::is_bool()
{
    bool retValue = false;

    // We don't want to test all possible combinations of spellings for
    // "True" vs "true" vs "tRue" etc.  So we create a temporary string that
    // is all lower case and compare against the temporary.

    // Create a copy of the string that can be modified locally.
    string str( wstr );

    // Force the string to all lower case.
    string_to_lower( str );
    
    // The comparison is a character-by-character over the length of the
    // first string.  To avoid uninitialized memory reads we convert char
    // array literals to strings.
    if( str == string("true") || str == string(".true.") ) 
        retValue = true;
    if ( str == string("false") || str == string(".false.") )
        retValue = true;

   return retValue;
}


// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// This section provides the methods for returning the word as double,
// int, bool, etc.
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************

// ===========================================================================
// Get the word as a boolean
// ===========================================================================
bool Word::get_bool(stringstream &serr, int &ierr)
{
    // Mark this word as having been processed.
    processed = true;

    bool retValue = false;

    // We don't want to test all possible combinations of spellings for
    // "True" vs "true" vs "tRue" etc.  So we create a temporary string that
    // is all lower case and compare against the temporary.
    string str( wstr );

    // Force the string to all lower case.
    string_to_lower( str );
    
    // The comparison is a character-by-character over the length of the
    // first string.  To avoid uninitialized memory reads we convert char
    // array literals to strings.
    if( str == string("true") || str == string(".true.") ) 
        retValue = true;
    else if ( str == string("false") || str == string(".false.") )
        retValue = false;
    else { // We default any other bool value to false but also warn the user. 
        if (lines != NULL) {
            serr << endl;
            serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
            serr << "    " << (*lines)[line_number-1] << endl;
            serr << "in file: " << filename << endl;
        }
        serr << "Values on this line should be true or false "
            "(or .true. or .false.)" << endl;
        serr << "    (any case is fine, for example true, True, TrUe "
            "are all ok)" << endl;
        serr << "Instead found value: " << wstr << endl << endl;
        ierr = 2;
        retValue = false;
    }

    // Apply the negate flag if it is turned on.
    if (negate) {
        bool b = false;
        if (retValue == false) b = true;
        retValue = b;
    }

    return retValue;
}        


// ===========================================================================
// Get the word as as int, error processing version.
// ===========================================================================
int Word::get_int(stringstream &serr, int &ierr)
{
    // Mark this word as having been processed.
    processed = true;

    // The word must at least be a number.
    if ((type != DOUBLE) && (type != INTEGER)) {
        if (lines != NULL) {
            serr << endl;
            serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
            serr << "    " << (*lines)[line_number-1] << endl;
            serr << "in file: " << filename << endl;
        }
        serr << "Expected a numerical, integer value." << endl;
        serr << "Instead got: " << wstr << endl << endl;
        ierr = 2;
        return 0;
    }

    // The word might begin with a + or - sign.
    bool start_with_pm = false;
    if (wstr[0] == '+') start_with_pm = true;
    if (wstr[0] == '-') start_with_pm = true;

    // We allow 2. or 2.0 for example as an integer, but not 2.3.
    bool dot_found = false;
    bool is_int = true;
    int istart = 0;
    if (start_with_pm) istart = 1;
    for (int i=istart; i<(int)wstr.size(); i++) {
        if (!isdigit(wstr[i]) && wstr[i]!='.' ) {
            is_int = false;
            break;
        }
        if (wstr[i]=='.' ) {
            dot_found = true;
            continue;
        }
        if (dot_found && wstr[i]!='0' ) {
            is_int = false;
            break;
        }
    }
    if (!is_int) {
        if (lines != NULL) {
            serr << endl;
            serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
            serr << "    " << (*lines)[line_number-1] << endl;
            serr << "in file: " << filename << endl;
        }
        serr << "Expected an integer." << endl;
        serr << "For example, 2 or 3, even 2. or 2.0 is ok." << endl;
        serr << "Instead got: " << wstr << endl << endl;
        ierr = 2;
        return 0;
    }

    
    // Apply the negate flag if it is turned on.
    int iret = atoi(wstr.c_str() ); 
    if (negate) iret *= -1;
    return iret;
}

int64_t Word::get_int64_t(stringstream &serr, int &ierr)
{
    // Mark this word as having been processed.
    processed = true;

    // The word must at least be a number.
    if ((type != DOUBLE) && (type != INTEGER)) {
        if (lines != NULL) {
            serr << endl;
            serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
            serr << "    " << (*lines)[line_number-1] << endl;
            serr << "in file: " << filename << endl;
        }
        serr << "Expected a numerical, integer value." << endl;
        serr << "Instead got: " << wstr << endl << endl;
        ierr = 2;
        return 0;
    }

    // The word might begin with a + or - sign.
    bool start_with_pm = false;
    if (wstr[0] == '+') start_with_pm = true;
    if (wstr[0] == '-') start_with_pm = true;

    // We allow 2. or 2.0 for example as an integer, but not 2.3.
    bool dot_found = false;
    bool is_int = true;
    int istart = 0;
    if (start_with_pm) istart = 1;
    for (int i=istart; i<(int)wstr.size(); i++) {
        if (!isdigit(wstr[i]) && wstr[i]!='.' ) {
            is_int = false;
            break;
        }
        if (wstr[i]=='.' ) {
            dot_found = true;
            continue;
        }
        if (dot_found && wstr[i]!='0' ) {
            is_int = false;
            break;
        }
    }
    if (!is_int) {
        if (lines != NULL) {
            serr << endl;
            serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
            serr << "    " << (*lines)[line_number-1] << endl;
            serr << "in file: " << filename << endl;
        }
        serr << "Expected an integer." << endl;
        serr << "For example, 2 or 3, even 2. or 2.0 is ok." << endl;
        serr << "Instead got: " << wstr << endl << endl;
        ierr = 2;
        return 0;
    }

    std::stringstream sstr(wstr);
    int64_t iret;
    sstr >> iret;
    // Apply the negate flag if it is turned on.
    if (negate) iret *= -1;
    return iret;
}        

// ===========================================================================
// Get the word as a double, error processing version.
// ===========================================================================
double Word::get_double(stringstream &serr, int &ierr)
{
    // Mark this word as having been processed.
    processed = true;

    // The word must at least be a number.
    if ((type != DOUBLE) && (type != INTEGER)) {
        if (lines != NULL) {
            serr << endl;
            serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
            serr << "    " << (*lines)[line_number-1] << endl;
            serr << "in file: " << filename << endl;
        }
        serr << "Expected a numerical value." << endl;
        serr << "Instead got: " << wstr << endl << endl;
        ierr = 2;
        return 0;
    }

    // Use a temporary string that might be modified.
    string s = wstr;

    // We allow exponents using d and D in addition to e and E, for example
    // 1.d14 or -1.38D-18. The problem with this is that atof and strtod
    // do not allow d or D, therefore we have to replace d or D with e
    // before sending it to atof or strtod.
    if (type == DOUBLE) {
        for (int i=0; i<(int)s.size(); i++) {
            if (s[i] == 'd') s[i] = 'e';
            if (s[i] == 'D') s[i] = 'e';
        }
    }

    // Convert the string to a double.
    double d = atof(s.c_str()); 

    // Apply the negate flag if it is turned on.
    if (negate) d *= -1.0;
    return d;
}        


// ===========================================================================
// Get the word as a single character, error processing version.
// ===========================================================================
char Word::get_single_char(stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    //assert(serr == serr);
    assert(ierr == ierr);

    // Mark this word as having been processed.
    processed = true;

    return wstr[0];
}


// ===========================================================================
// Get the word as an int, no error processing version.
// ===========================================================================
int Word::get_int()
{
   int dummy;
   return get_val( dummy );
}

// support uint64_t
int64_t Word::get_int64_t()
{
   int64_t dummy;
   return get_val( dummy );
}

// ===========================================================================
// Get the word as a float
// ===========================================================================
float Word::get_float()
{
   float dummy;
   return get_val( dummy );
}        

// ===========================================================================
// Get the word as a double
// ===========================================================================
double Word::get_double()
{
   double dummy;
   return get_val( dummy );
}        


// ===========================================================================
// Get the word as a Type T. 
// ===========================================================================
template< class T >
T Word::get_val( T &dummyValue )
{
   // To suppress compiler warnings of unused parameters
   assert(dummyValue == dummyValue);

   T retValue;

   // Mark this word as having been processed.
   processed = true;

   // Convert the word to the requested data type.
   retValue = convertFromString( retValue, wstr );

   return retValue;
}        

//! Explicit instantiation of supported template types.  If more types are
//! needed those explicit versions must be listed here.  We are not using
//! automatic inclusion (we would need to move the function definition into
//! the header file for that).  The listed versions below are the only ones
//! that will be included in the library.
template int     Word::get_val( int&     );
template int64_t Word::get_val( int64_t& );
template float   Word::get_val( float&   );
template double  Word::get_val( double&  );
//template bool  Word::get_val( bool&    );
template string  Word::get_val( string&  );

// ===========================================================================
// Convert from string to return type explicitly.
// ===========================================================================

//! rtti is only used for type identification (each overloaded function must
//! have a unique signature.  The return value is not part of the signature).

// Convert string to integer.
int    Word::convertFromString( const int &rtti, const string &s ) const 
{ 
   // To suppress compiler warnings of unused parameters
   assert(rtti == rtti);

   int iret = atoi( s.c_str() ); 
   if (negate) iret *= -1;
   return iret;
}

// Convert string to int64_t.
int64_t Word::convertFromString( const int64_t &rtti, const string &s ) const 
{
   // To suppress compiler warnings of unused parameters
   assert(rtti == rtti);

   int64_t iret;
   std::stringstream( s ) >> iret;
   if (negate) iret *= -1;
   return iret;
}

// Convert string to string (do nothing).
string Word::convertFromString( const string &rtti, const string &s ) const 
{ 
   // To suppress compiler warnings of unused parameters
   assert(rtti == rtti);

    return s; 
}

// Convert string to float.
float Word::convertFromString( const float &rtti, const string &s ) const 
{ 
   // To suppress compiler warnings of unused parameters
   assert(rtti == rtti);

    // Use a temporary string that might be modified.
    string sm = s;

    // We allow exponents using d and D in addition to e and E, for example
    // 1.d14 or -1.38D-18. The problem with this is that atof and strtod
    // do not allow d or D, therefore we have to replace d or D with e
    // before sending it to atof or strtod.
    for (int i=0; i<(int)sm.size(); i++) {
        if (sm[i] == 'd') sm[i] = 'e';
        if (sm[i] == 'D') sm[i] = 'e';
    }

    float f = (float)atof( sm.c_str() );  
    if (negate) f *= -1.;
    return f;
}

// Convert string to double.
double Word::convertFromString( const double &rtti, const string &s ) const 
{ 
    // To suppress compiler warnings of unused parameters
    assert(rtti == rtti);

    // Use a temporary string that might be modified.
    string sm = s;

    // We allow exponents using d and D in addition to e and E, for example
    // 1.d14 or -1.38D-18. The problem with this is that atof and strtod
    // do not allow d or D, therefore we have to replace d or D with e
    // before sending it to atof or strtod.
    for (int i=0; i<(int)sm.size(); i++) {
        if (sm[i] == 'd') sm[i] = 'e';
        if (sm[i] == 'D') sm[i] = 'e';
    }

    double d = atof( sm.c_str() );  
    if (negate) d *= -1.;
    return d;
}


// ***************************************************************************
// ***************************************************************************
// ***************************************************************************
// Utility functions.
// ***************************************************************************
// ***************************************************************************
// ***************************************************************************


// ===========================================================================
// Return the word as a string for printing. This is usually just the word
// but if it has multiplicity, then include that in the return string.
// ===========================================================================
string Word::get_print_string(bool enc_quotes)
{
    bool equotes = true;
    if (!enc_quotes) equotes = false;
    if (wstr == "true") equotes = false;
    if (wstr == "false") equotes = false;


    string sq = "";

    if (equotes) {
        if (type == WSTRING) sq = "\"";
        sq += wstr;
        if (type == WSTRING) sq += "\"";
    }
    else {
        sq = wstr;
    }

    if (multiplicity <= 1) return sq;

    stringstream ss;
    ss << multiplicity;
    string s = "";
    s = ss.str() + "*" + sq;
    return s;
}


// ===========================================================================
// If a word starts or ends with quotes, make sure the quotes match, if not
// generate a fatal error, and then strip off the quotes.
// ===========================================================================
void Word::handle_quotes(stringstream &serr, int &ierr)
{
    // Just for convenience.
    int len = (int)wstr.size();

    // Check for matching quotes, generate a fatal error if they do not match.
    bool ferr = false;
    if ((wstr[0] == '\"') && (wstr[len-1] != '\"')) ferr = true;
    if ((wstr[0] == '\'') && (wstr[len-1] != '\'')) ferr = true;
    if ((wstr[len-1] == '\"') && (wstr[0] != '\"')) ferr = true;
    if ((wstr[len-1] == '\'') && (wstr[0] != '\'')) ferr = true;

    if (ferr) {
        fatal_error(serr, ierr);
        serr << "Quotes mismatch found." << endl;
        serr << "A starting quotes must have a closing quotes." << endl;
        serr << "Double quotes, \", must be matched with double quotes."
             << endl;
        serr << "Single quotes, \', must be matched with single quotes."
             << endl;
        ierr = 2;
    }

    // Determine if the word starts and ends with quotes. If it does,
    // then we strip off the quote symbols.
    if (((wstr[0] == '\"') || (wstr[0] == '\'')) &&
        ((wstr[len-1] == '\"') || (wstr[len-1] == '\''))) {
        wstr.erase(wstr.end() - 1);
        wstr.erase(wstr.begin());
        return;
    }
}


// ===========================================================================
// Erase a single character from the word, ic is the index of the character
// to be erased (starting from 0).
// ===========================================================================
void Word::erase_char(int ic)
{
    if (ic >= (int)wstr.size()) return;
    wstr.erase(wstr.begin() + ic);
}



// ===========================================================================
// Fatal error
// ===========================================================================
void Word::fatal_error(stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(ierr == ierr);

    serr << endl;
    serr << "*** FATAL ERROR in line " << file_line_number << ":" << endl;
    serr << "    " << (*lines)[line_number-1] << endl;
    serr << "in file: " << filename << endl;
}

void Word::warning(stringstream &serr, int &ierr)
{
    // To suppress compiler warnings of unused parameters
    assert(ierr == ierr);

    serr << endl;
    serr << "*** WARNING in line " << file_line_number << ":" << endl;
    serr << "    " << (*lines)[line_number-1] << endl;
    serr << "in file: " << filename << endl;
}


// ===========================================================================
// Negate a word.
// ===========================================================================
void Word::negate_value()
{
   int len = (int)wstr.size();

   if (type == INTEGER || type == DOUBLE) {
      negate = false;

      // If the string starts with a - sign, then delete it.
      for (int i=0; i<len; i++) {
         if (wstr[i] == ' ' || wstr[i] == '\t') continue;
         if (wstr[i] == '-') {
            wstr[i] = ' ';
            return;
         }
         break;
      }

      // The string did not start with a minus sign so insert one.
      // Using insert causes link problems with SGI CC
      string s = "-" + wstr;
      wstr = s;
      //wstr.insert(0, s);
      return;
   }
}



// ===========================================================================
// Convert the input string to lower case.
// ===========================================================================
void Word::string_to_lower( string &s ) const 
{
   int i, c, d;
   int len = (int)s.size();
   for (i=0; i<len; i++) {
      c = (int)s[i];
      d = c;
      if (isalpha(c)) d = tolower(c);
      s[i] = (char)d;
   }
}



} // End of the PP namespace

