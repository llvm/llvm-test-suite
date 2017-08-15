/*
 * InputFile.cc
 *
 *  Created on: Mar 20, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#include "InputFile.hh"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Parallel.hh"

using namespace std;


InputFile::InputFile(const char* filename) {

    using Parallel::mype;

    ifstream ifs(filename);
    if (!ifs.good())
    {
        if (mype == 0)
            cerr << "File " << filename << " not found" << endl;
        exit(1);
    }

    while (true)
    {
        string line;
        getline(ifs, line);
        if (ifs.eof()) break;

        istringstream iss(line);
        string key;

        iss >> key;
        if (key.empty() || key[0] == '#')
          continue;

        if (pairs.find(key) != pairs.end()) {
            if (mype == 0)
                cerr << "Duplicate key " << key << " in input file" << endl;
            exit(1);
        }

        string val;
        getline(iss, val);
        pairs[key] = val;

    } // while true

    ifs.close();

}


InputFile::~InputFile() {}


template <typename T>
T InputFile::get(const string& key, const T& dflt) const {
    pairstype::const_iterator itr = pairs.find(key);
    if (itr == pairs.end())
        return dflt;
    istringstream iss(itr->second);
    T val;
    iss >> val;
    return val;
}


int InputFile::getInt(const string& key, const int dflt) const {
    return get(key, dflt);
}


double InputFile::getDouble(const string& key, const double dflt) const {
    return get(key, dflt);
}


string InputFile::getString(const string& key, const string& dflt) const {
    return get(key, dflt);
}


vector<double> InputFile::getDoubleList(
        const string& key,
        const vector<double>& dflt) const {
    pairstype::const_iterator itr = pairs.find(key);
    if (itr == pairs.end())
        return dflt;
    istringstream iss(itr->second);
    vector<double> vallist;
    double val;
    while (iss >> val) vallist.push_back(val);
    return vallist;
}
