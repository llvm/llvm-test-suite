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
 * systemCallMap.c
 *
 *  Created on: Feb 5, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#include "systemCallMap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Element constructor */
SystemCallMapElement *SystemCallMapElement_new ( char *label, int initialSize )
{
    SystemCallMapElement *element = malloc ( sizeof( SystemCallMapElement ) );
    if ( element )
    {
        element->label = strdup ( label );
        element->index = -1; /* Set by the insertion algorithm */
        if ( !element->label )
        {
            free( element );
            return( NULL );
        }
        element->nodes = NodePtrVec_new( initialSize );
        if ( !element->nodes )
        {
            free( element->label );
            free( element );
            return( NULL );
        }
    }

    return( element );
}

/* Element destructor */
void SystemCallMapElement_delete( SystemCallMapElement *trash )
{
    /* free the mallocs! */
    if ( trash )
    {
        if ( trash->label )
            free( trash->label );
        NodePtrVec_delete ( trash->nodes );
    }
}





/* Constructor */
SystemCallMap *SystemCallMap_new ( int initialSize )
{
    SystemCallMap *map = NULL;
    SystemCallMapElement **vector = NULL;

    if ( initialSize <= 0 )
        return NULL;

    vector = malloc(  initialSize * sizeof( SystemCallMapElement* ) );
    if ( vector )
    {
        map = malloc ( sizeof( SystemCallMap ) );
        if ( map )
        {
            map->allocatedSize = initialSize;
            map->contentSize = 0;
            map->vector = vector;
        }
        else
            free( vector );
    }

    return map;
}

/* destructor for an ENTIRE MAP!!! */
void SystemCallMap_delete( SystemCallMap *trash )
{
    int i;

    /* basic error checking */
    if ( !trash )
        return;

    for ( i = 0; i < trash->contentSize; ++i )
    {
        SystemCallMapElement_delete( trash->vector[i] );
    }
}



/* setter */
bool SystemCallMap_insert ( SystemCallMap *map, char *label, Node *node )
{
    int i = 0;
    SystemCallMapElement *newElement = NULL;
    bool success = false;

    /* Some basic error checking */
    if ( !map || !label || !node )
        return( false );

    /* See if this label has already been implemented */
    for ( i = 0; i < map->contentSize; ++i )
    {
        if ( strcmp( label, map->vector[i]->label ) == 0 )
        {
            /* found it! */
            node->label = map->vector[i]->label;
            node->labelIdx = i;
            return( NodePtrVec_push( map->vector[i]->nodes, node ) );
        }
    }

    /* If we make it here, we have a new label */
    if ( map->contentSize == map->allocatedSize )
    {
        /* Full up! Need a new vector */
        map->vector = realloc( map->vector, (map->allocatedSize*2 * sizeof( SystemCallMapElement * )) );
        if ( map->vector )
        {
            map->allocatedSize *= 2;
        }
        else
            return( false );
    }

    newElement = SystemCallMapElement_new( label, 8 ); /* arbitrary size of 8 */
    if ( !newElement )
        return( false );

    success = NodePtrVec_push( newElement->nodes, node );
    if ( !success )
        SystemCallMapElement_delete( newElement );

    node->label = newElement->label;
    node->labelIdx = newElement->index = map->contentSize; /* Does newElement really need the index? */
    map->vector[map->contentSize] = newElement;
    map->contentSize += 1;

    return( true );

}



/* Finds all nodes associated with a label. */
NodePtrVec *SystemCallMap_findLabeledNodes( SystemCallMap *systemCalls, char *label )
{
    int i;

    /* Debug --> * /
    printf("Inside SystemCallMap_findLabeledNodes, label: %s\n", label);
    / *<-- end debug */
    if ( !systemCalls || !label )
        return( NULL );

    for( i = 0; i < systemCalls->contentSize; ++i )
    {
        /* Debug -->* /
        printf("\t...checking against %s...\n", systemCalls->vector[i]->label);
        / * <-- end debug */
        if ( strcmp( label, systemCalls->vector[i]->label ) == 0 )
            return( systemCalls->vector[i]->nodes );
    }

    /* Debug --> * /
    printf("\tleaving SystemCallMap_findLabeledNodes, nothing found.\n");
    / *<-- end debug */
    return( NULL );
}

/* Returns the index of a given label */
int SystemCallMap_getLabelIndex( SystemCallMap *map, char *label )
{
    int i;

    /* See if this label has already been implemented */
    for ( i = 0; i < map->contentSize; ++i )
    {
        if ( strcmp( label, map->vector[i]->label ) == 0 )
        {
            return( i );
        }
    }

    /* If we made it here, this label is not represented */
    return( -1 );
}


/*
 * Determines if all the labels in a given signature are represented
 * within this graph. If not, we know the search will fail. There's
 * gotta be a better name for this...
 */
bool SystemCallMap_signatureRepresented( SystemCallMap *map, Signature signature )
{
    int i;
    bool foundByLabel = true;

    for ( i = 0; signature[i] != NULL && foundByLabel; ++i )
    {
        /* if the signature is in the map, its index will be >=0 */
        if ( SystemCallMap_getLabelIndex( map, signature[i] ) < 0 )
            foundByLabel = false;
    }

    return( foundByLabel );
}


