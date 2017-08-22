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
 * utils.c
 *
 *  Created on: Jan 10, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void edgeListPrettyPrint( EdgeList *edges, int depth, char *header )
{
    int i;
    for ( i = 0; i < depth; ++i )
        printf( "\t" );
    printf( "%s: ", header );
    for ( ; edges != NULL; edges = edges->nextEdge )
        printf( " %d,", edges->targetNodeId );
    printf( "\n" );
}


void nodeListPrettyPrint( NodeList *nodes, int depth, char *separator, bool multiLine )
{
    int i;

    if ( !nodes )
        return;

    if ( nodes->node )
        printf( "%d", nodes->node->id );
    if ( nodes->nextNode )
    {
        if ( multiLine )
        {
            printf( "\n" );
            for ( i = 0; i < depth; ++i )
            {
                printf( "    " );
            }
        }
        printf( "%s", separator );
        nodeListPrettyPrint( nodes->nextNode, depth + 1, separator, multiLine );
    }
    else
        printf( "\n" );
}


void graphPrettyPrint ( Graph *graph )
{
    NodeList *outerPtr;
    NodeList *innerPtr;

    for ( outerPtr = graph->outerNodes;
            outerPtr != NULL;
            outerPtr = outerPtr->nextNode )
    {
        printf( "Outer Node: %d, idx: %d, label: %s (%d)\n", outerPtr->node->id,
                outerPtr->node->nodeCount, outerPtr->node->label ? outerPtr->node->label : "none",
                outerPtr->node->labelIdx );
        edgeListPrettyPrint( outerPtr->node->edges, 1, "Edges" );
        /* Deprecated: edgeListPrettyPrint( outerPtr->node->entranceNodes, 1, "EntranceNodes" ); */
        for ( innerPtr = outerPtr->node->interiorNodes;
                innerPtr != NULL;
                innerPtr = innerPtr->nextNode )
        {
            printf( "\tInner Node: %d\n", innerPtr->node->id );
            edgeListPrettyPrint( innerPtr->node->edges, 2, "Edges" );
        }
    }

    printf ( "\n\n" );
}


void systemCallMapPrettyPrint( SystemCallMap *map )
{
    SystemCallMapElement *element = NULL;
    int i = 0;
    int j = 0;

    if ( !map )
        return;

    for ( i = 0; i < map->contentSize; ++i )
    {
        element = map->vector[i];
        printf( "'%s'\n\t:", element->label );
         for ( j = 0; element->nodes && j < element->nodes->contentSize; ++j )
        {
            printf( "%d", element->nodes->vector[j]->id );
            if ( j < element->nodes->contentSize-1 )
                printf( ", " );
            else
                printf( "\n\n" );
        }

    }

    printf( "\t%d total System Call Map elements\n", map->contentSize );
}

bool testGraph()
{
    /* Build it and see if it will get made */
    Graph *graph = malloc( sizeof( Graph ) );
    Node *outerNode1 = Node_new( 10, 0 );
    Node *outerNode2 = Node_new( 20, 1 );
    Node *innerNode11 = Node_new( 11, 2 );
    Node *innerNode12 = Node_new( 12, 3 );
    Node *innerNode21 = Node_new( 21, 4 );
    Node *innerNode22 = Node_new( 22, 5 );
    Node *innerNode23 = Node_new( 23, 6 );

    if ( !graph ) return( false );

    Graph_addOuterNode( graph, outerNode1 );
    Graph_addOuterNode( graph, outerNode2 );

    Node_addInteriorNode( outerNode1, innerNode11 );
    Node_addInteriorNode( outerNode1, innerNode12 );

    Node_addInteriorNode( outerNode2, innerNode21 );
    Node_addInteriorNode( outerNode2, innerNode22 );
    Node_addInteriorNode( outerNode2, innerNode23 );


    /* Ok, let's print out the graph and see if it works */
    graphPrettyPrint( graph );

    return( true );
}

void printStack ( NodePtrVec *stack )
{
    if ( !stack ) return;
    int i;
    // printf ( "stack size %d out of %d max\n", stack->contentSize, stack->allocatedSize );
    for ( i = 0; i < stack->contentSize; ++i )
    {
        printf("%d", stack->vector[i]->id );
        fflush(stdout);
        if ( stack->vector[i]->label )
        {
            printf( "(%s)", stack->vector[i]->label );
            fflush(stdout);
        }
        if ( i != stack->contentSize-1 )
        {
            printf ( " : " );
            fflush(stdout);
        }
    }
    printf( "\n" );
    fflush(stdout);
}

void testStack()
{
    /* This was written when the stack was storing integers
    int a, b, c, d, e;
    printf ( "\n\nTesting stack operations" );
    NodePtrVec *vector = Stack_new(3);
    if ( !vector )
    {
        printf( "stack allocation failed\n" );
        return;
    }
    Stack_push( vector, 1 );
    Stack_push( vector, 2 );
    printStack( vector );
    Stack_push( vector, 3 );
    printStack( vector );
    Stack_push( vector, 4 );
    printStack( vector );

    printf ( "\n2 %s in the stack\n", Stack_find( vector, 2 ) ? "is" : "is not" );
    printf ( "5 %s in the stack\n\n", Stack_find( vector, 5 ) ? "is" : "is not" );

    printf ( "\n4 %s in the stack\n", Stack_findReverse( vector, 4 ) ? "is" : "is not" );
    printf ( "45 %s in the stack\n\n", Stack_findReverse( vector, 45 ) ? "is" : "is not" );

    a = Stack_pop( vector );
    printStack( vector );
    b = Stack_pop( vector );
    c = Stack_pop( vector );
    d = Stack_pop( vector );
    e = Stack_pop( vector );
    printStack( vector );
    printf ( "%d, %d, %d, %d, %d\n", a, b, c, d, e );
    */
}


/* The below code gives compile warnings about the size difference
 * between pointers and ints. Since this doesn't impact execution, 
 * I am not going to chase down a fix.
 */
void searchDiagramPrettyPrint ( SearchDiagram *diagram )
{
#if 0
    SearchDiagram *node;
    EdgeReferences *edge;

    for ( node = diagram; node != NULL && node->node != NULL; ++node )
    {
        printf ( "Node %x -> %d\n", (unsigned int)node, node->node->id );
        if ( node->edgeReferenceArray )
        {
            printf ( "\t%x\n", (int)node->edgeReferenceArray );
            for ( edge = node->edgeReferenceArray; edge->edgeTarget != NULL; ++edge )
            {
                printf ( "\t\tEdge (target %d) -> %x\n",
                         edge->edgeTarget->id, (int)edge->targetNodeEdges );
            }
        }

    }
#endif
}

