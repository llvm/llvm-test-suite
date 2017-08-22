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
 * Graph.h
 *
 *  Created on: Jan 9, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */


/* --------
 * Graphs are made up of nodes and edges. Nodes hold data and edges
 * connect nodes to each other. In this representation, edges are
 * directional (they lead from one node to the next) and may create
 * looped paths. The data sets from which these graphs are defined
 * define two-layered graphs. The outer layer may contain one or
 * more interior nodes. These interior nodes may be linked among each
 * other. Each containing node may have up to two "entrance" nodes;
 * that is, an edge goes from the containing node to its entrance node.
 *
 * As mentioned above, the graphs are defined in data files. The graph
 * data structure contains the file name, a count of nodes, a list of
 * exterior nodes, and structures that assist in the searching through
 * the graph for "signatures"
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdbool.h> /* bool is no longer part of the C language */
#include "node.h"
#include "searchDiagram.h"
#include "systemCallMap.h"


/* -------------------------------------------
 * Graph Definitions
 *
 */

typedef struct GraphStruct Graph;

struct GraphStruct
{
    char *fileName; /* the file parsed to give us this graph */
    int totalNodes; /* Nodes, both outer and interior */
    NodeList *outerNodes; /* The Linked-List capture of the node data */
    SearchDiagram *searchDiagram; /* The compressed Node/Edge search structures */
    SystemCallMap *systemCallMap;
};


/* "methods" */

Graph *Graph_new(); /* Graph constructor */
void Graph_delete( Graph *trash ); /* Destructor - erases current graph */
bool Graph_addOuterNode( Graph *graph, Node *newOuterNode );
/* Finds a node within the graph. If deep is true, we check interior nodes as well.
 * If deep is false, we only check to see if the id is an outer node. This does NOT
 * find the path to the node.
 */
Node *Graph_findNode( Graph *graph, int id, bool deep );



/* Determine if a given node contains the node specified by id. If this problem extended
 * beyond two layers, this method would be recursive. Returns NULL if node is not contained.
 * This does NOT find the path to the node.
 */
Node *Graph_findContainedNode( Node *node, int id );


#endif /* GRAPH_H_ */
