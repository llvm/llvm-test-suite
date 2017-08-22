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
 * graph.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifdef USE_OMP
#include <omp.h>
#endif

#include "graph.h"
#include "systemCallMap.h"
#include "bitfield.h"
#include "utils.h"




/* -------------------------------------------
 * Graph Method Definitions
 *
 */
/* We deleted the code that made a graph singleton. Now we may have
 * more than one graph. Ergo, the main method (or whatever) will maintain
 * the graph pointer.
 */

Graph *Graph_new()
{
    Graph *graph= NULL;
    graph = malloc( sizeof( Graph ));
    if ( graph )
    {
        /* The malloc worked! */
        graph->fileName = NULL;
        graph->totalNodes = 0;
        graph->outerNodes = NULL;
        graph->searchDiagram = NULL;
    }

    return( graph );
}

/* Destructor - erases current graph, sets singleton to NULL */
void Graph_delete( Graph *trash )
{
    SearchDiagram *element;
    if ( trash )
    {
        free( trash->fileName );
        NodeList_clear( trash->outerNodes, true );
        if ( trash->searchDiagram ) {
            for ( element = trash->searchDiagram; element->node != NULL; ++element )
            {
                free( element->edgeReferenceArray );
            }
            free( trash->searchDiagram );
        }
        free( trash );
    }
}

bool Graph_addOuterNode( Graph *graph, Node *newOuterNode )
{
    /* a little basic error checking */
    if ( !graph || !newOuterNode )
        return (false);

    /* Is this the first outer node? */
    if ( graph->outerNodes == NULL ) /* Allocates singletonGraph if it's not there */
        {
        graph->outerNodes = NodeList_new();
            if ( !graph->outerNodes )
                return( false ); /* the malloc failed */
            graph->outerNodes->node = newOuterNode;
            return( true );
        }

    /* Otherwise, insert the new node at the tail of the singleton graph */
    return( NodeList_insertBack( graph->outerNodes, newOuterNode ));
}


/* Finds a node within the graph. If deep is true, we check interior nodes as well.
 * If deep is false, we only check to see if the id is an outer node. This does NOT
 * find the path to the node.
 */
Node *Graph_findNode( Graph *graph, int id, bool deep )
{
    NodeList *nodes;
    Node *node;

    for ( nodes = graph->outerNodes; nodes != NULL; nodes = nodes->nextNode )
    {
        if ( nodes->node->id == id )
            return( nodes->node );
        /* If that wasn't the node, and we're going deep, see if it's there. */
        if ( deep )
        {
            node = Graph_findContainedNode( nodes->node, id );
            if ( node )
                return( node );
        }
    }

    return( NULL );
}




/* Determine if a given node contains the node specified by id. If this problem extended
 * beyond two layers, this method would be recursive. Returns NULL if node is not contained.
 * This does NOT find the path to the node.
 */
Node *Graph_findContainedNode( Node *node, int id )
{
    NodeList *nodes;

    for ( nodes = node->interiorNodes; nodes != NULL; nodes = nodes->nextNode )
    {
        if ( nodes->node->id == id )
            return( nodes->node );
    }

    return( NULL );
}






/* Search Algorithms */
