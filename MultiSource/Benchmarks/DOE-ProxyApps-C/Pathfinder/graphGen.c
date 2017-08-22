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
 * graphGen.c
 *
 *  Created on: Aug 2, 2013
 *      Author: jbrigdo
 */

#include <stdbool.h>
#include <stdio.h>
#include "graphGen.h"
#include "vectorUtils.h"


/* getDuplicateNodeForGraph takes a node from another graph and sees if
 * a duplicate has previously been created for this graph. If not, it tries
 * to create and insert a new duplicate. If that fails, we're out of memory.
 * In that circumstance, we have a significant error condition. It is
 * time to delete the graph being built and report that error to the
 * calling method (buildGraphFromPaths).
 */
static Node *getDuplicateNodeForGraph(Graph *graph, Node *from)
{
    Node *newNode = Graph_findNode(graph, from->id, true); /* true == deep search */
    if ( newNode )
        return(newNode);

    /* else */
    newNode = Node_duplicate(from, graph->totalNodes++ ); /* POST increment */
    if ( newNode )
    {
        Graph_addOuterNode(graph,newNode); /* all nodes are exterior in this graph */
        newNode->type = exteriorNode;
        return(newNode);
    }

    /* else */
    Graph_delete(graph); /* Failure is DESTRUCTIVE at this point */
    return NULL;
}


Graph *buildGraphFromPaths(NodeVecVec **pathList, BuildType build)
{
    Graph *newGraph = Graph_new();
    Node *pathNode; /* The node we're looking at in the path */
    Node *currentNode;
    Node *nextNode;
    int i; /* Iterator through the path List array */
    int j; /* Iterator through each path List */
    int k; /* Iterator through each path in the path List */

    if ( !pathList || !newGraph )
        return(NULL);

    for ( i = 0; pathList[i] ; ++i )
    {
        for (j = 0; j < pathList[i]->contentSize; ++j)
        {
            pathNode = pathList[i]->vector[j]->vector[0];
            currentNode = getDuplicateNodeForGraph(newGraph, pathNode);
            if ( !currentNode )
                return(NULL); /* out of memory: crashing! newGraph has already been cleaned up */

            for ( k = 1; k < pathList[i]->vector[j]->contentSize; ++k /*also incremented below*/ )
            {
                if ( build == endNodesOnly )
                {
                    k = pathList[i]->vector[j]->contentSize - 1;
                }
                else if ( build == labeledNodes )
                {
                    while ( pathList[i]->vector[j]->vector[k]->labelIdx < 0 )
                        ++k;
                }
                /* else if ( build == completePath ) no-op */

                pathNode = pathList[i]->vector[j]->vector[k];
                nextNode = getDuplicateNodeForGraph(newGraph, pathNode);
                if ( !nextNode )
                    return(NULL); /* out of memory: crashing! newGraph has already been cleaned up */
                Node_addEdgeToNode(currentNode, nextNode);
                // printf ( "Adding edge: %d ==> %d\n", currentNode->id, nextNode->id );
                currentNode = nextNode;
            }
        }
    }

    return(newGraph);
}


/* Write the given graph to a file */
bool exportGraph(Graph *graph, char *fileName)
{
    FILE *out = NULL;
    NodeList *nodes = NULL;
    EdgeList *edges = NULL;
    int nodeCount = 0;

    if ( !graph || !fileName ) /* A little basic error checking */
        return(false);

    out = fopen(fileName, "w");

    if ( !out ) /* A little more basic error checking */
        return(false);

    /* Write out the header */
    /* ... find out how many functions (outer nodes) the graph holds */
    for ( nodes = graph->outerNodes; nodes != NULL; nodes = nodes->nextNode )
    {
        ++nodeCount;
    }
    fprintf(out, "Functions: %d\n", nodeCount);
    fprintf(out, "Basic blocks: %d\n\n", graph->totalNodes);

    /* First, write out the graph's outer nodes */
    for ( nodes = graph->outerNodes; nodes != NULL; nodes = nodes->nextNode )
    {
        fprintf(out, "%d ", nodes->node->id);
        //printf("Node: %d ", nodes->node->id);
        if ( nodes->node->edges )
        {
            nodeCount = 0;
            /* Wow is this inefficient, but two passes is the easiest way to do it. */
            for ( edges = nodes->node->edges; edges != NULL; edges = edges->nextEdge )
            {
                if ( edges->targetNode->type == exteriorNode )
                    ++nodeCount;
            }
            fprintf(out, "%d ", nodeCount);
            //printf("has %d edges: ", nodeCount);
            for ( edges = nodes->node->edges; edges != NULL; edges = edges->nextEdge )
                {
                    if ( edges->targetNode->type == exteriorNode )
                    {
                        fprintf(out, "%d ", edges->targetNodeId);
                        //printf("%d, ", edges->targetNodeId);
                    }
                }
            fprintf(out, "\n");
            //printf("\n");
        }
        else
        {
            fprintf(out, "0 \n" );
            //printf(" no edges.\n");
        }
    }

    /* then, for each of the outer nodes, write out its interior nodes (if any) */
    /* We are skipping this for the time being. This currently is being called with flat graphs. */

    /* Finally, write out the labels. */
    fprintf(out, "-------------------------------------------- \nSYSTEM CALLS \n\n");

    for ( nodes = graph->outerNodes; nodes != NULL; nodes = nodes->nextNode )
    {
        if ( nodes->node->label != NULL )
            fprintf(out, "%d %s \n", nodes->node->id, nodes->node->label );
        /* If we were worried about interior nodes, we'd need a duplicate loop here. */
    }

    return(true);

}
