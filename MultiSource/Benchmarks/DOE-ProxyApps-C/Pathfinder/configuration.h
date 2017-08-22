/*************************************************************************
 *
 *        PathFinder: finding a series of labeled nodes within a
 *                two-layer directed, cyclic graph.
 *               Copyright (2013) Sandia Corporation
 *
 * Copyright (2013) Sandia Corporation. Under the terms of Contract 
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government 
 * retains certain rights in this software.
 *
 * This file is part of PathFinder.
 * 
 * PathFinder is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * PathFinder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PathFinder.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Questions? Contact J. Brian Rigdon (jbrigdo@sandia.gov)
 *
 */


/*
 * configuration.h
 *
 *  Created on: October 1, 2013
 *      Author: Brian "Rig" Rigdon
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <stdbool.h>
#include "graph.h"
#include "graphGen.h"

/* I was hoping to avoid this - however because we are dealing with
 * pointers to arrays of pointers, passing the address of an such
 * a beast becomes really confusing: Graph *(**pointer)[]
 * Ergo, I am building a structure to contain all the information
 * necessary for a given running of this software. For lack of
 * a better name, we are calling it the "configuration".
 */

/* A simple enum to define which search is to be done */
typedef enum { treeSearch, diagramSearch } SearchType;

typedef struct SearchOptionsStruct SearchOptions;
struct SearchOptionsStruct
{
    SearchType searchType;
    bool multiThreaded;
    bool doStatistics;
    bool writeOutputFile;
    char *outputFile;
    BuildType buildType;
};

SearchOptions * SearchOptions_new();

typedef struct ConfigurationStruct Configuration;
struct ConfigurationStruct
{
    Graph **graphs; /* a pointer to a NULL terminated array of pointers */
    Signature *signatures; /* a pointer to a NULL terminated array of Signatures */
    SearchOptions *searchOptions;
    int qThreadCount; /* recursion depth to STOP spawning new tasks */
};

Configuration* Configuration_new();

#endif /*  CONFIGURATION_H_  */
