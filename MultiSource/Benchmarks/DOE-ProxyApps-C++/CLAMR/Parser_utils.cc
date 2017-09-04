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
// This class collects various low level utilities for the parser.
// ***************************************************************************
// ***************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

#include "Parser_utils.hh"

namespace PP
{
using std:: string;
using std::cout;
using std::endl;
using std::stringstream;
using std::setprecision;
using std::vector;
using std::deque;
using std::setw;

static int index_base = 1; // For Fortran, 0 for C/C++style


// ===========================================================================
// Default constructor.
// ===========================================================================
Parser_utils::Parser_utils(int base)
{
   index_base = base;
}


// ===========================================================================
// Given an array command like
//     cmd(5,3) = 1.0, 3.0, -5.0
// find the starting position in a 1d array.
//
// The indices in cmd are referenced from 1 (i.e. fortran) while the 1d array
// is referenced from 0 (C++).
//
// This function works for any dimension array, 0,1,2,3,...
//
// Example 1: Consider a 1d command
//     cmd(5) = 1.0, 3.4
// We start filling the 1d fortran array at position 5 and put in two values.
// Subtract 1 to reference from 0, so this function returns 4.
//
// Example 2: Consider the 2d command above:
//     cmd(5,3) = 1.0, 3.0, -5.0
// We also need to know that the max size of the first dimension is say 7.
// Since in fortran, the first index varies fastest, the fortran 1d index
// would be
//     5 + (3-1)*7 = 19
// Subtract 1 to reference from 0, thus the return value is 18.
//
// The istart vector contains the indices, for example 2 this would be 5 and
// 3. The size vector contains the max size of each dimension, for example 2
// this would be 7 and whatever for the second dimension.
// ===========================================================================
int Parser_utils::start_dex(vector<int> &istart, const vector<int> &size)
{
    // Get the array dimension, 0,1,2,3,...
    int dim = (int)istart.size();

    // 0d is a special case.
    if (dim == 0) return 0;

    // Find the index.
    // Adjustment for base 1
    int ix = istart[0]-index_base;
    for (int i=1; i<dim; i++) {
        int t = istart[i]-index_base;
        for (int j=0; j<i; j++) {
            t *= size[j];
        }
        ix += t;
    }

    return ix;
}
    

// ===========================================================================
// This is the reverse of the start_dex function above.
// Given the 1d index, icdex (from 0 to nvals-1), find the corresponding
// multi dimensional fortran indices (each starting from 1).
//
// Example 1: Consider a 1d array
//     var1d(1) = 1 3 5 9 -4 -5 6
// Suppose the user inputs icdex=3, corresponding to array value 9.
// This 1d case is very simple, all we do is add 1 to icdex to get a reference
// from 1, thus returning 4.
//
// Example 1: Consider a 2d array
//     $var2d(1,1) = 11. 21. 31.   12. 22. 32.   13. 23. 33.
// Where the max of the first dimension is 3. Suppose the user specifies
// icdex = 5, this corresponds to array value 32. The two indices returned
// would be 3,2 (referenced from 1).
//
// The istart vector contains the output indices, for example 2 this would be 3
// and 2. The size vector contains the max size of each dimension, for example
// 2 this would be 3 and whatever for the second dimension. The number of
// elements in size is normally dim-1, but it does not hurt if it has dim
// elements (in which case the last element is not referenced or used).
// ===========================================================================
void Parser_utils::reverse_dex(int icdex,
                               int nvals,
                               vector<int> &istart,
                               const vector<int> &size)
{
    // Get the dimension.
    int dim = (int)istart.size();

    // Nothing to do for scalars.
    if (dim == 0) return;

    // Start at 1,1,1,1,1,1,...
    for (int i=0; i<dim; i++) {
        istart[i] = index_base;
    }

    // Get the first 1d index (referenced from 0)
    int i1 = start_dex(istart, size);
    if (i1 == icdex) return;

    // Go through all indices until the desired one is found.
    // Yes, this is inefficient, but dim is a small integer, like 2,3,4, so
    // the efficiency does not really matter.
    // Perhaps somebody can devise a better algorithm someday.
    for (int i1dex=0; i1dex<nvals; i1dex++) {
        for (int i=0; i<dim; i++) {
            if (i < dim-1) {
                if (istart[i] == size[i]) {
                    istart[i] = index_base;
                }
                else {
                    istart[i] += 1;
                    break;
                }
            }
            else {
                istart[i] += 1;
                break;
            }
        }

        i1 = start_dex(istart, size);
        if (i1 == icdex) return;
    }
}



// ***************************************************************************
// ***************************************************************************
// Utilities for printing to the screen (or to a file).
// ***************************************************************************
// ***************************************************************************



// ===========================================================================


//                    Line                                                        
//      Filename     Number                         Command                       
//    ------------   ------   ------------------------------------------------
//         test.in        4   some_logical_cmd = false
//         test.in       28   some_logical_cmd = false
//         test.in      170   some_logical_cmd = false
//         test.in      175   some_logical_cmd = true     //No space betwe ...
//    test_inc1.in        2   some_logical_cmd = true
//    test_inc3.in        2   some_logical_cmd = true
//                             
//         test.in      442   strinsert_cmd01 = "test duplicates commands"
//         test.in      456   strinsert_cmd01 = "test duplicates commands"



// Given a header row of strings and several data rows of string where each
// row consists of the same number of columns, list all the rows with the
// columns lined up and the headers centered on the columns.
// ===========================================================================
void Parser_utils::print_strings(vector< vector<string> > rows, int n_header_rows,
                                 int offset, int col_spacing, int line_len_max,
                                 stringstream &ss)
{
    // Get the number of columns.
    int ncol = (int)rows[0].size();

    // Find the max number of characters in each column for all the rows.
    vector<int> maxc(ncol, 0);
    for (int row=0; row<(int)rows.size(); row++) {
        for (int c=0; c<ncol; c++) {
            string s = rows[row][c];
            if ((int)s.size() > maxc[c]) maxc[c] = (int)s.size();
        }
    }

    // Find the column widths.
    vector<int> col_width(ncol,0);
    for (int c=0; c<ncol; c++) {
        if (maxc[c] > col_width[c]) col_width[c] = maxc[c];
    }

    // Spacing between columns.
    vector<int> cspace(ncol, col_spacing);
    cspace[0] = offset;

    // Limit the lines to a max length.
    if (line_len_max > 0) {
        int line_len = 0;
        for (int c=0; c<ncol; c++) {
            line_len += cspace[c] + col_width[c];
        }
        int excess_c = line_len - line_len_max;

        if (excess_c > 0) {
            col_width[ncol-1] -= excess_c;
            for (int row=0; row<(int)rows.size(); row++) {
                int len = 0;
                for (int c=0; c<ncol; c++) {
                    string s = rows[row][c];
                    if (c < ncol-1) len += cspace[c] + col_width[c];
                    if (c == ncol-1) len += cspace[c] + (int)s.size();
                }
                if (len <= line_len_max) continue;

                int c = ncol -1;
                string s = rows[row][c];
                int ec = len - line_len_max;
                int start = (int)s.size() - ec - 4;
                if (start < 0) start = 0;
                int nc = ec+4;
                if (nc > (int)s.size()) nc = (int)s.size();
                s.erase(start, nc);
                rows[row][c] = s + " ...";
            }
        }
    }


    // Write the rows.
    for (int row=0; row<(int)rows.size(); row++) {

        // Insert the line of dashes after the header rows.
        if (row == n_header_rows) {
            for (int c=0; c<ncol; c++) {
                for (int i=0; i<cspace[c]; i++) ss << " ";
                for (int i=0; i<col_width[c]; i++) ss << "-";
            }
            ss << endl;
        }

        for (int c=0; c<ncol; c++) {
            // Use nc to center the headers, but not center the data.
            int nc = maxc[c];
            if (row < n_header_rows) nc = (int)rows[row][c].size();

            int nsp_left = 0;
            int nsp_right = 0;
            int dsp = col_width[c] - nc;
            if (dsp > 0) {
                nsp_left = dsp/2;
                nsp_right = col_width[c] - nsp_left - nc;
            }
            for (int i=0; i<cspace[c]; i++) ss << " ";
            for (int i=0; i<nsp_left; i++) ss << " ";


            if (row >= n_header_rows) {
                if (c < ncol-1)  ss << setw(maxc[c]) << rows[row][c];
                if (c == ncol-1) ss << rows[row][c];
            }
            else {
                ss << rows[row][c];
            }

            for (int i=0; i<nsp_right; i++) ss << " ";
        }
        ss << endl;
    }
}



} // End of the PP namespace
