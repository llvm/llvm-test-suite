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
 * systemCallMap.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#ifndef SYSTEMCALLMAP_H_
#define SYSTEMCALLMAP_H_

#include <stdbool.h>
#include "node.h"



/* A signature is an array of character pointers. Signature arrays
 * are terminated with a NULL pointer so we don't have to have an
 * additional datum to contain the length of the array. To make
 * the code more readable, we are using this typedef:
 */
typedef char **Signature; /* code must be careful to ensure NULL termination */


/*
 * SystemCallMapStruct specifies a label and all the nodes that are associated with
 * that label. Currently, this is sub-optimal, managing via strcmp. If optimization
 * is needed, that is left as an exercise for the future. We could see the future
 * addition of hash values
 */

typedef struct SystemCallMapElementStruct SystemCallMapElement;

struct SystemCallMapElementStruct
{
    char *label;
    int index;
    NodePtrVec *nodes;
};

SystemCallMapElement *SystemCallMapElement_new ( char *label, int initialSize ); /* Element constructor */
void SystemCallMapElement_delete( SystemCallMapElement *trash ); /* Element destructor */




/* The call map is actually a stack (managed like the STL deque) of SystemCallMapElements.
 * It will insert up to its capacity, and then double its size (allocating a new space, copying
 * and then freeing the old) when it grows beyond its capacity.
 */

typedef struct SystemCallMapStruct SystemCallMap;

struct SystemCallMapStruct
{
    int contentSize;
    int allocatedSize;
    SystemCallMapElement **vector; /* a pointer to an array of pointers */
};

SystemCallMap *SystemCallMap_new( int initialSize );
void SystemCallMap_delete( SystemCallMap *trash ); /* destructor for an ENTIRE MAP!!!  */

/* insert checks to see if there is already an entry for the name passed in. If so,
 * it appends the node to that map element. If not, a new element is created, the
 * name is duplicated
 */
bool SystemCallMap_insert ( SystemCallMap *map, char *label, Node *node );


/* Finds a list of nodes associated with a label. */
NodePtrVec *SystemCallMap_findLabeledNodes( SystemCallMap *systemCalls, char *label );

/* Returns the index of a given label */
int SystemCallMap_getLabelIndex( SystemCallMap *map, char *label );

/*
 * Determines if all the labels in a given signature are represented
 * within this graph. If not, we know the search will fail. There's
 * gotta be a better name for this...
 */
bool SystemCallMap_signatureRepresented( SystemCallMap *map, Signature signature );

#endif /* SYSTEMCALLMAP_H_ */
