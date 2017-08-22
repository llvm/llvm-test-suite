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
 * parsing.h
 *
 *  Created on: Jan 9, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

/* --------
 * This pair of files contains the utility data types and methods for
 * parsing data files into graphs. It also defines a "configuration"
 * for a given run of PathFinder. The configuration holds all the info
 * corresponding to the run - graphs, signatures, search types.
 */

#ifndef PARSING_H_
#define PARSING_H_

#include "vectorUtils.h"

/* Since we're parsing into graphs, we need to know what they are... */
#include "graph.h"
#include "configuration.h"



/* buildEntranceList takes an array of integers, and builds a
 * non-resolved edge list from the array. This is a special
 * edge list, used only be outer nodes to identify entrance
 * points into their subgraph.
 */
void buildEntranceList( Node *outerNode, IntVector *nodeData );


/* buildNodeFromData takes the integer array built by the above
 * method, and creates a node from it. If that node has
 * edge data, that is also built. The data is in an array,
 * the size of which is also passed in.
 */
Node *buildNodeFromData( IntVector *nodeData );


/* resolveNodeEdges is the second pass through the graph data
 * structures. The first pass defines the nodes, and puts the edge
 * ids in place. The second pass finds the nodes corresponding to
 * the edge id, and sets the edge pointer to that node. Edges for
 * outer nodes will only reference other outer nodes. Interior
 * nodes may have edges to outer nodes or other interior nodes of
 * their containing node. If an edge references an undefined node
 * or if an edge goes into the interior of another outer node,
 * the user will be notified.
 */
void resolveNodeEdges( Graph *graph, Node *sourceNode, bool outerNode );



/* parseFile goes through the specified file to build the graph. It
 * returns true if everything goes as planned. Any errors will cause
 * false to be returned. The built graph can be accessed via
 * Graph_the().
 */

Graph *parseFile( char *fileName );

/* parseSignature takes a space delimited string and turns it
 * into a "signature" - a packed array of c-string pointers with
 * a NULL pointer to signify completion. As with our edge parser
 * the code depends on a space character to terminate the line.
 */
char **parseSignature( char *data );

/* parseConfigFile reads the data file names and desired search
 * signatures from the config file. It returns a packed array
 * of Graph pointers populated corresponding to the data files.
 * Also, it returns a packed array of pointers to signatures.
 * (Signatures are themselves packed arrays to C-Strings.) These
 * packed arrays are terminated with a NULL pointer. They
 * are returned in the "graphs" and "signatures" parameters
 * which should be references to the desired pointers. See main.c.
 */
bool parseConfigFile( char *configFileName, Configuration *config );



#endif /* PARSING_H_ */
