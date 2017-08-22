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
 * vectorUtils.h
 *
 *  Created on: Jun 21, 2013
 *      Author: J. Brian Rigdon
 */

#ifndef VECTORUTILS_H_
#define VECTORUTILS_H_

#include <stdio.h>
#include <stdbool.h>

#include "node.h"

/* The IntVector is sort of a C version of std::vector<int> */
typedef struct IntVectorStruct IntVector;
struct IntVectorStruct
{
    int size; /* number of integers actively stored */
    int allocatedSize;
    int *vector;
};

IntVector *IntVector_new(int size); /* constructor */
void IntVector_delete(IntVector *trash); /* destructor */
#define IntVector_clear(intVectorPtr) (intVectorPtr->size = 0)
#define IntVector_size(intVectorPtr) (intVectorPtr->size)
bool IntVector_insertEnd(IntVector *vector, int datum);

/*
 * parse space-delimited null-terminated string into an IntVector.
 * Returns the number of integers collected
 */
int IntVector_createFromString(IntVector *vector, char *inputString);





/* The CharVector is sort of a C version of std::vector<char> */
typedef struct CharVectorStruct CharVector;
struct CharVectorStruct
{
    int size; /* number of integers actively stored */
    int allocatedSize;
    char *string;
};

CharVector *CharVector_new(int size); /* constructor */
void CharVector_delete(CharVector *trash); /* destructor */
bool CharVector_insertEnd(CharVector *vector, char c);
int CharVector_getLineFromFile(CharVector *vector, FILE *input);






/* -------------------------------------------
 * Node Pointer Vector Definitions
 *
 *      NodePtrVec are an alternative storage mechanism to the Node Lists.
 *      The Vector is single ended, with a push and a pop. It maintains
 *      a count of contained Node pointers, the maximum allocated size for
 *      the storage and a pointer to the array of Node pointers. When the
 *      contained size reaches the maximum, another piece of memory, we
 *      realloc for twice the size. This is patterned after STL vectors
 */



/* A simple, sized vector class. The vector is initially created with a specified size
 * even though it holds nothing. Each push increments a counter (pops decrement) until
 * it reaches its initial size. The next push will be slow, because the vector needs
 * to grow. At that point, we realloc with DOUBLE the size of the original vector. If
 * successful, the last datagram is inserted in the end of the vector.
 */

typedef struct NodePtrVecStruct NodePtrVec;

struct NodePtrVecStruct
{
    int contentSize;    // the number of elements currently in the vector
    int allocatedSize;  // the amount (in sizeof int) currently allocated for this vector
    Node **vector;       // a pointer to the actual data (array of node pointers).
};


NodePtrVec *NodePtrVec_new(int initialSize); /* create a new vector allocating specified size */
void NodePtrVec_delete(NodePtrVec *trash); /* destructor */
NodePtrVec *NodePtrVec_copy(NodePtrVec *from, bool exact_copy); /* creates duplicate vector (not duplicate nodes!) */

/* pushes the element if it can. If a memory allocation is required but
 * fails - false is returned
 */
bool NodePtrVec_push(NodePtrVec *vector, Node *node);
Node * NodePtrVec_pop(NodePtrVec *vector); /* returns the top item and decrements. If empty, we return -1 */

/* Screams through the vector from bottom to top to find the specified element. If found,
 * returns true.
 */
bool NodePtrVec_find(NodePtrVec *vector, Node *node);

/* Screams through the vector from top to bottom to find the specified element. If found,
 * returns true.
 */
bool NodePtrVec_findReverse(NodePtrVec *vector, Node *node);

/* Appends the second vector to the first. If the "keepFirst" flag is set, the
 * entire second vector is appended to the first. Otherwise, the [0] element of
 * the second vector is skipped. This is useful when the last element of the
 * first vector is identical to the first element of the second vector, and
 * we don't want duplication. (And who, really, wants duplication? Really, who
 * wants duplication?)
 */
void NodePtrVec_appendVectors(NodePtrVec *first, NodePtrVec *second, bool keepFirst);


/* -------------------------------------------
 * And a vector of Node Pointer Vectors
 *
 * Results from the searches are presented as NodePtrVectors. To store a bunch of these
 * we are defining a vector of these vectors.
 */

typedef struct NodeVecVecStruct NodeVecVec;

struct NodeVecVecStruct
{
    int contentSize;
    int allocatedSize;
    NodePtrVec **vector;
};

NodeVecVec *NodeVecVec_new(int initialSize); /* constructor */
void NodeVecVec_delete(NodeVecVec* trash); /* destructor */
bool NodeVecVec_insert(NodeVecVec* vector, NodePtrVec* path); /* puts a copy of "path" at the end of the vector */

#endif /* VECTORUTILS_H_ */
