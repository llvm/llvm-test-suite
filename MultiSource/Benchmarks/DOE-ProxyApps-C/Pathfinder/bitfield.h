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

#ifndef BITFIELD_H
#define BITFIELD_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct NodeStruct;

/* --------
 * Bitfield is a mask around a character pointer. An array of character
 * pointers is allocated such that there is a sequence of available bits
 * equal in length to the number of nodes in a given graph. Bitfield
 * defines operations that check if a bit corresponding to a node index
 * is set. This is used by the graph traversal path finding algorithms
 * to determine if a node has been visited.
 */

typedef struct BitfieldStruct Bitfield;

struct BitfieldStruct
{
    int bitsNeeded; /* in BYTES!!! */
    char *bitfield;
};


Bitfield *Bitfield_new(int bitsNeeded); /* constructor */
void Bitfield_delete(Bitfield *this); /* destructor */

/* Returns true if the specified node has been visited */
bool Bitfield_nodeVisited(Bitfield *this, struct NodeStruct *node);

/* Makes a byte-by-byte copy of the "from" bitfield */
Bitfield *Bitfield_copy(Bitfield *from);

void Bitfield_clear();

#endif

