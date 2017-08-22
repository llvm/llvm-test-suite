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
 * searchAlgorithms.h
 *
 *  Created on: Jun 18, 2013
 *      Author: Brian "Rig" Rigdon
 */

#ifndef SEARCHALGORITHMS_H_
#define SEARCHALGORITHMS_H_


#include "vectorUtils.h"
#include "graph.h"
#include "configuration.h"


/* findNextLabel is a recursive method that determines if a path exists between a
 * specific node and the label that is at the start of the label array argument. The
 * label array is an array of char pointers that is terminated with a NULL pointer. The
 * first pointer is the "current" label.
 *
 * The node's edge nodes are checked against the current label. If none of them match, then
 * this method recurses with each edge node and the current label.
 *
 * If an edge matches, then we are beginning a search for the next "leg" of the labels.
 * We recurse with that specific edge and the "next" label. That is the [1] element of
 * the label array. If that element is NULL, the matching edge signifies the end of our
 * search! VICTORY!
 *
 * If we reach the last edge with out a match (directly or recursively) we return a false
 * list.
 */

bool findNextLabel( Node *node, char *labels[], NodePtrVec *result, Bitfield *visited ); /* NodePtrVec *visited ); */

/* findAndRecordAllPaths is almost exactly like findNextLabel. It differs only in that it
 * 1) doesn't stop with the first discovery of the specified path and 2) records the discovered
 * path. To do this, it doesn't create a new result vector for
 */

void findAndRecordAllPaths( Node *node, Signature labels, int *labelIdxs,
        NodePtrVec *result, Bitfield *visited, NodeVecVec *storage,
        SearchOptions *options );

/*
 *  findLabelPath takes an array of labels, determines if there are nodes associated
 * with the labels (each label search will return a NodePtrVec*), and determine if
 * paths exist passing through the set of labels.
 */
bool findLabelPath( Graph *graph, Signature labels, NodePtrVec *result, SearchType searchType );

/*
 *  findAllPossibleLegs does an exhaustive search through each possible label
 * pairing to determine which legs are possible. This is a brute-force nxn
 * approach that builds a signature holding only the second label and then
 * searches for that signature from the nodes representing the first label.
 * For the time being, it simply prints out the legs that are  possible in
 * this graph.
 */
int findAllPossibleLegs( Graph *graph, SearchType searchType );

/*
 * findAndLogAllPossibleLegs is a duplicate of the above method, but it
 * stores the results that are found
 */

int findAndLogAllPossibleLegs( Graph *graph, SearchOptions *options );

/* Once the configuration file is parsed, a config structure is created that
 * specifies the graphs and the signatures to be searched against. This method
 * does multiple signature searches against multiple files 
 */
 
void doMultiSearchesQT(Configuration *config);
void doMultiSearches(Configuration *config);

#endif /* SEARCHALGORITHMS_H_ */
