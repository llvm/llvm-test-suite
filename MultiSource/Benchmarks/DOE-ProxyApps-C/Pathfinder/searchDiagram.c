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
 * searchDiagram.c
 *
 *  Created on: Feb 1, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#include "searchDiagram.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/* Scream through the diagram to get the element corresponding to this key. This
 * simply iterates through the entire list, there is no optimization in the search
 * algorithm.
 */
SearchDiagram *SearchDiagram_findNode ( SearchDiagram *diagram, Node *node )
{
    int idx;

    /* Do some basic error checking */
    if ( !diagram )
        return( NULL );

    for ( idx = 0; diagram[idx].node != NULL; ++idx )
    {
        if ( diagram[idx].node == node ) /* We found it! */
            return( &diagram[idx] );
    }

    /* If we made it here, we couldn't find it. */
    return( NULL );
}



/* The meat of this process - the function that creates the search diagram.
 * It allocates the memory for the array of search diagram elements and
 * populates them with node data and edgeID arrays. Outer nodes are inserted
 * into the node array from the lowest addresses and inner nodes are inserted
 * into the search diagram from the highest. The authors did this to (hopefully)
 * give a little more efficiency to the searching of the diagram.
 */
SearchDiagram *SearchDiagram_build( NodeList *nodeTree, int nodeCount )
{
    SearchDiagram *diagram = NULL;
    NodeList *outerNodes = NULL;
    Node *node = NULL;
    NodeList *innerNodes = NULL;
    /* Originally, we speculated that searches would stream through the outer
     * nodes more than through the interior nodes. (We were wrong.) So we had
     * this mechanism in place to put the outer nodes at the beginning of the
     * diagram and the interior nodes at the end. Because we were wrong, this
     * increases the likelihood of cache misses rather than decreasing it. Ergo
     * we have replaced the outerIdx and the innerIdx calls.
     *
     * So... it turns out that putting the inner nodes near their containing
     * node actually slows things down - but it's minor (2% - 3 minutes in a
     * 120 minute run.)
    int index = 0;
     */
    int outerIdx = 0;           /* index from the bottom up for outer nodes */
    int innerIdx = nodeCount-1; /* and from the top down for interior nodes */

    int edgeCount;
    EdgeList *edges;
    SearchDiagram *element; /* for searching in our diagram */

    /* Do some basic error checking */
    if ( !nodeTree || nodeCount == 0 )
        return NULL;

    /* Allocate an array of SearchDiagram Elements (+1 for a terminus element) */
    diagram = malloc ( (nodeCount+1) * sizeof(SearchDiagram) );
    if ( !diagram ) /* malloc failed */
        return( NULL );

    diagram[nodeCount].node = NULL;
    diagram[nodeCount].edgeReferenceArray = NULL;

    /* Scream through the Nodes and fill in the Search Array allocate space for edges */
    for ( outerNodes = nodeTree; outerNodes != NULL; outerNodes = outerNodes->nextNode )
    {
        node = outerNodes->node;
        /* This diagram entry needs a key */
        diagram[outerIdx].node = node;
        /* How many edges do we need? */
        edgeCount = node->edgeCount + node->entranceCount;
        if ( edgeCount > 0 ) /* allocate space for edgeIdArray (+1 for a terminus element) */
        {
            diagram[outerIdx].edgeReferenceArray = malloc ( (edgeCount+1) * sizeof(EdgeReferences) );
            diagram[outerIdx].edgeReferenceArray[edgeCount].edgeTarget = NULL;
            diagram[outerIdx].edgeReferenceArray[edgeCount].targetNodeEdges = NULL;
        }
        else
            diagram[outerIdx].edgeReferenceArray = NULL;

        /* What do we do if that malloc fails? */

        /* increment the outer index: */
        ++outerIdx;

        /* Now do the same for this node's interior graph (if present) */
        for ( innerNodes = node->interiorNodes; innerNodes != NULL; innerNodes = innerNodes->nextNode )
        {
            node = innerNodes->node;
            diagram[innerIdx].node = node;
            edgeCount = node->edgeCount + node->entranceCount;
            if ( node->edgeCount > 0 ) /* allocate space for edgeIdArray (+1 for a terminus element) */
            {
                diagram[innerIdx].edgeReferenceArray = malloc ( (edgeCount+1) * sizeof(EdgeReferences) );
                diagram[innerIdx].edgeReferenceArray[edgeCount].edgeTarget = NULL;
                diagram[innerIdx].edgeReferenceArray[edgeCount].targetNodeEdges = NULL;
            }
            else
                diagram[innerIdx].edgeReferenceArray = NULL;

            /* Again, what do we do if that malloc fails? */

            /* decrement the interior index: */
            --innerIdx;
        }

    }


    /* Check to make sure our counters line up. If they don't, we have a corrupt
     * graph. That is, there is a mismatch between node definitions and edge lists.
     * The innerIdx should reference the previous outerIdx location.
     */
    if ( outerIdx != innerIdx +1 )
    {
        /* Houston, we have a problem */
        printf ( "Bummer. outerIdx: %d, innerIdx: %d, node count: %d\n", outerIdx, innerIdx, nodeCount );
    }


    /* For each node, populate its edge list - edges and entrance nodes (if there) */
    outerIdx = 0;
    innerIdx = nodeCount-1;
    for ( outerNodes = nodeTree; outerNodes != NULL; outerNodes = outerNodes->nextNode )
    {
        /* iterate through this node's edges to populate the EdgeIdArray */
        node = outerNodes->node;
        for ( edges = node->edges, edgeCount = 0;
              edges != NULL;
              edges = edges->nextEdge, ++edgeCount )
        {
            element = SearchDiagram_findNode( diagram, edges->targetNode );
            diagram[outerIdx].edgeReferenceArray[edgeCount].edgeTarget = edges->targetNode;
            diagram[outerIdx].edgeReferenceArray[edgeCount].targetNodeEdges = element->edgeReferenceArray;
        }
        ++outerIdx;

        /* And then scream through the interior nodes to take care of their edges */
        for ( innerNodes = node->interiorNodes; innerNodes != NULL; innerNodes = innerNodes->nextNode )
        {
            node = innerNodes->node;
            for ( edges = node->edges, edgeCount = 0;
                  edges != NULL;
                  edges = edges->nextEdge, ++edgeCount )
            {
                element = SearchDiagram_findNode( diagram, edges->targetNode );
                diagram[innerIdx].edgeReferenceArray[edgeCount].edgeTarget = edges->targetNode;
                diagram[innerIdx].edgeReferenceArray[edgeCount].targetNodeEdges = element->edgeReferenceArray;
            }
            --innerIdx;
        }
    }

    return diagram;
}



bool SearchDiagram_findSignatureAlongEdges ( Node *node, EdgeReferences *edges,
                                             char *labels[], NodePtrVec *result, Bitfield *visited )
{
    bool success = false;
    NodePtrVec *nextLegResult = NULL;
    Bitfield *nextLegVisited = NULL;
    int i;

    /* A little basic error checking */
    if ( !node || !edges || !labels || !result|| !visited )
    {
        return( false );
    }

    /* If this node has already been visited, we have found a loop. return false. */

/*
    if ( NodePtrVec_findReverse( visited, node ) )
        return( false );
    else
        NodePtrVec_push( visited, node );
*/
    if ( Bitfield_nodeVisited( visited, node ) )
        return( false );

    NodePtrVec_push( result, node );

    /* Go through the edges once to see if we've found a label match */
    for ( i = 0; edges[i].edgeTarget != NULL; ++i )
    {
        if ( edges[i].edgeTarget->label )
        {
            //strcmp based:
            if ( strcmp( edges[i].edgeTarget->label, labels[0] ) == 0 ) /* match! */
            // index based: if ( edges[i].edgeTarget->labelIdx == labelIdxs[0] )
            {
                if ( labels[1] == NULL ) /* end of the signature, we're DONE */
                {
                    NodePtrVec_push( result, edges[i].edgeTarget );
                    return( true );
                }
                else /* RECURSE TO SEE IF THE REST OF THE SIGNATURE CAN BE FOUND!!! */
                {
                    nextLegResult = NodePtrVec_new( 50 ); /* arbitrary size, malloc success checked in recursion */
                    nextLegVisited = Bitfield_new(visited->bitsNeeded);

                    success = SearchDiagram_findSignatureAlongEdges ( edges[i].edgeTarget,
                                                                      edges[i].targetNodeEdges,
                                                                      &labels[1], nextLegResult, nextLegVisited );
                    Bitfield_delete( nextLegVisited );
                    if ( success )
                    {
                        NodePtrVec_appendVectors( result, nextLegResult, true );
                        NodePtrVec_delete( nextLegResult );
                        return( true );
                    }
                }
            }
        }
    }

    /* IF we made it here, we need to continue through the tree, seeing if any of our
     * edge nodes have a connection to a labeled node.
     */
    for ( i = 0; edges[i].edgeTarget != NULL; ++i )
    {
        success = SearchDiagram_findSignatureAlongEdges( edges[i].edgeTarget,
                                                         edges[i].targetNodeEdges,
                                                         labels, result, visited );
        if ( success )
            return( true ); /* this edge has a path to the ultimate signature path */
    }


    /* and, if we make it here, we have failed. */
    NodePtrVec_pop( result ); /* take current node off the result stack */
    return false;
}
