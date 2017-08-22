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

#include "bitfield.h"
#include "node.h"
#include <stdio.h>


/* --------
 * Bitfield is a mask around a character pointer. An array of character
 * pointers is allocated such that there is a sequence of available bits
 * equal in length to the number of nodes in a given graph. Bitfield
 * defines operations that check if a bit corresponding to a node index
 * is set. This is used by the graph traversal path finding algorithms
 * to determine if a node has been visited.
 */


/* constructor */
Bitfield *Bitfield_new(int bitsNeeded)
{
    int size = (bitsNeeded+7) / 8; /* CHAR_BIT; */
    Bitfield *new = malloc(sizeof(Bitfield));
    if ( !new )
        return(NULL);
    new->bitfield = calloc(size, sizeof(char));
    if ( !new->bitfield )
    {
        free(new);
        return(NULL);
    }

    new->bitsNeeded = bitsNeeded;
    return new;
} 

/* destructor */
void Bitfield_delete(Bitfield *this)
{
    if ( this )
    {
        if ( this->bitfield )
            free(this->bitfield);
        free(this);
    }
}

/* Returns true if the specified node has been visited */
bool Bitfield_nodeVisited(Bitfield *this, struct NodeStruct *node)
{
    int index = node->nodeCount >> 3;
    char byte = this->bitfield[index];
    char bit = 1 << (node->nodeCount & 0x07);
    bool set = byte & bit;

    this->bitfield[index] |= bit;

    /* printf ( "Inside Bitfield nodeVisited: Node: %d, index %d, byte %x, bit: %x\n",
             node->nodeCount, index, byte, bit ); */
    return(set);
}


/* Makes a byte-by-byte copy of the "from" bitfield */
Bitfield *Bitfield_copy(Bitfield *from)
{
    int i;

    if ( !from )
        return(NULL);

    Bitfield *new = Bitfield_new(from->bitsNeeded);
    if ( new )
    {
        for ( i = 0; i*8 < from->bitsNeeded; ++i )
            new->bitfield[i] = from->bitfield[i];
        return(new);
    }
    else
        return(NULL);
}


void Bitfield_clear(Bitfield *this)
{
    int size = (this->bitsNeeded+7) / 8;
    memset(this->bitfield, 0, size);
}
