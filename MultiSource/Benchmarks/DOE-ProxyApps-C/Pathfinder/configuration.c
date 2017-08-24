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
 * configuration.c
 *
 *  Created on: October 1, 2013
 *      Author: Brian "Rig" Rigdon
 */

#include <stdio.h>
 #include "configuration.h"

 SearchOptions* SearchOptions_new()
 {
    SearchOptions *options = malloc(sizeof(SearchOptions));
    if ( !options )
        return(NULL);
    options->searchType = treeSearch;
    options->multiThreaded = false;
    options->doStatistics = false;
    options->writeOutputFile = false;
    options->outputFile = NULL;
    options->buildType = endNodesOnly;
    return(options);
 }

 Configuration* Configuration_new()
 {
    Configuration *new = malloc(sizeof(Configuration));
    SearchOptions *options = SearchOptions_new();
    if ( !new || !options )
    {
        if ( new ) free(new);
        if ( options ) free(options);
        return(NULL);
    }
    new->graphs = NULL;
    new->signatures = NULL;
    new->searchOptions = options;
    new->qThreadCount = 0;
    return(new);
 }
