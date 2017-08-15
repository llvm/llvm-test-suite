/*
 * InputFile.hh
 *
 *  Created on: Mar 20, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef INPUTFILE_HH_
#define INPUTFILE_HH_

#include <string>
#include <vector>
#include <map>


class InputFile {
public:
    InputFile(const char* filename);
    ~InputFile();
    int getInt(const std::string& key, const int dflt) const;
    double getDouble(const std::string& key, const double dflt) const;
    std::string getString(const std::string& key,
            const std::string& dflt) const;
    std::vector<double> getDoubleList(
            const std::string& key,
            const std::vector<double>& dflt) const;

private:
    typedef std::map<std::string, std::string> pairstype;

    pairstype pairs;               // map of key-value string pairs

    template <typename T>
    T get(const std::string& key, const T& dflt) const;


}; // class InputFile


#endif /* INPUTFILE_HH_ */
