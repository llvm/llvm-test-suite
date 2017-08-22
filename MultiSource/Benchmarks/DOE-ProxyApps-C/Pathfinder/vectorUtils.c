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
 * vectorUtils.c
 *
 *  Created on: Jun 21, 2013
 *      Author: jbrigdo
 */

#include "vectorUtils.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* --------
 * IntVector Methods
 */

/* constructor */
IntVector *IntVector_new( int size )
{
    IntVector *new = malloc( sizeof(IntVector) );
    if ( new )
    {
        int *vector = malloc ( size * sizeof(int) );
        if ( vector )
        {
            new->vector = vector;
            new->size = 0;
            new->allocatedSize = size;
            return( new );
        }
        else
        {
            free( new );
            return( NULL );
        }
    }
    else
        return( NULL );
}

/* destructor */
void IntVector_delete(IntVector *trash)
{
    if ( trash )
    {
        if ( trash->vector )
            free( trash->vector );
        free( trash );
    }
}

/* inserts a new integer at the tail of the vector */
bool IntVector_insertEnd(IntVector *vector, int datum)
{
    int current = 0;
    int max = 0;

    /* some basic error checking */
    if ( !vector )
        return( false );

    current = vector->size;
    max = vector->allocatedSize;

    if ( current == max ) /* we're full */
    {
        vector->vector = realloc( vector->vector, 2*max*sizeof(int) );
        if ( vector->vector )
        {
            vector->allocatedSize = 2*max;
        }
        else
        {
            fprintf( stderr, "\n\nIntVector_insertEnd failed realloc size = %d\n", current*2 );
            return( false );
        }
    }

    vector->vector[current] = datum;
    vector->size += 1;
    return( true );
}

/*
 * A utility method that takes an input string to the next number. If it currently
 * points to a number, we iterate past that number, past any whitespace or non-number
 * and point to the first digit character we find. If input currently points a non-
 * digit character, we find the next digit character and return a pointer to it. If
 * no non-digit character is found with these rules, we return null.
 */
static char *findNextNumber(char *input)
{
    if ( isdigit( (int)input[0] ) )
    {
        /* scream through the string to find a non-digit */
        ++input;
        while ( isdigit( (int)input[0] ) && *input != '\0' )
            ++input;
        if ( input[0] == '\0' )
            return( NULL );
        else
            /* now find the next digit */
            while ( !isdigit( (int)input[0] ) && *input != '\0' )
                ++input;
        if ( input[0] == '\0' )
            return(NULL);
        else
            return(input);
    }
    else
    {
        /* find the first digit character */
        do {
            if ( input[0] == '\0' )
                return(NULL);
            ++input;
        } while ( !isdigit( (int)input[0] ) );
        return(input);
    }
}

/*
 * parse space-delimited null-terminated string into an IntVector.
 * Returns the number of integers collected
 */
int IntVector_createFromString(IntVector *vector, char *inputString)
{
    int dataCount = 0;
    int datum;

    /* make sure we have valid pointers passed in*/
    if ( !vector || !inputString )
        return(0);

    /* make sure we're pointing to a digit */
    if ( !isdigit((int)inputString[0]))
    {
        inputString = findNextNumber(inputString);
    }

    /* ok, at this point, we know we're pointing at a number */
    while (inputString) /* set to NULL when there are no more numbers. */
    {
        datum = atoi(inputString);
        inputString = findNextNumber(inputString);
        if ( !IntVector_insertEnd(vector, datum) )
            return(0); /* realloc failure */
        ++dataCount;
    }

    return(dataCount);
}




/* constructor */
CharVector *CharVector_new(int size)
{
    CharVector *new = malloc( sizeof(CharVector) );
    if ( new )
    {
        char *string = malloc ( size * sizeof(char) );
        if ( string )
        {
            new->string = string;
            new->size = 0;
            new->allocatedSize = size;
            return( new );
        }
        else
        {
            free( new );
            return( NULL );
        }
    }
    else
        return( NULL );
}

/* destructor */
void CharVector_delete( CharVector *trash )
{
    if ( trash )
    {
        if ( trash->string )
            free( trash->string );
        free( trash );
    }
}


bool CharVector_insertEnd( CharVector *vector, char c )
{
    int size = 0;
    int max = 0;

    /* some basic error checking */
    if ( !vector )
        return( false );

    size = vector->size;
    max = vector->allocatedSize;

    if ( size == max ) /* we're full */
    {
        vector->string = realloc( vector->string, 2*size*sizeof(char) );
        if ( vector->string )
        {
            vector->allocatedSize = size*2;
        }
        else
        {
            fprintf( stderr, "\n\nIntVector_insertEnd failed realloc size = %d\n", size*2 );
            return( false );
        }
    }

    vector->string[size] = c;
    vector->size += 1;
    return( true );
}


int CharVector_getLineFromFile( CharVector *vector, FILE *input )
{
    bool notDoneYet = true;
    char c = '\0';

    /* Some basic error checking */
    if ( !vector || !input )
        return( -1 );

    vector->size = 0; /* reset the vector prior to filling */

    /* get to the next digit */
    do {
        c = fgetc( input );
        if ( feof( input ) || c == '\n' )
            notDoneYet = false;
        else
            if ( ! CharVector_insertEnd( vector, c ) )
                return( -1 ); /* CharVector_insertEnd reached a memory limit. Fail */
    } while ( notDoneYet );

    /* make the data a c-string */
    if ( ! CharVector_insertEnd( vector, '\0' ) )
        return( -1 ); /* CharVector_insertEnd reached a memory limit. Fail */
    return( vector->size );
}



/* -------------------------------------------
 * Node Pointer Vector Method Definitions
 *
 */

/* create a new vector allocating specified size */
NodePtrVec *NodePtrVec_new( int initialSize )
{
    NodePtrVec *newVector;
    Node **vector; /* an array of pointers */

    vector = malloc ( initialSize * sizeof(Node *) );
    if ( !vector )
    {
        printf ( "Malloc failure in NodePtrVec creation\n" );
        return( NULL );
    }

    newVector =  malloc ( sizeof(NodePtrVec) );
    if ( !newVector )
    {
        free(vector);
        printf ( "Malloc failure in NodePtrVec storage creation\n" );
        return( NULL );
    }

    newVector->allocatedSize = initialSize;
    newVector->contentSize = 0;
    newVector->vector = vector;
    return( newVector );
}



/* destructor */
void NodePtrVec_delete( NodePtrVec *trash )
{
    if ( trash )
    {
        if ( trash->vector )
            free(trash->vector);
        free(trash);
    }
}


/* creates duplicate vector (not duplicate nodes!). If exact_copy is true, the
 * new vector is the same size as the copied one. If false, then only enough
 * room to hold the copy is allocated.
 */
NodePtrVec *NodePtrVec_copy(NodePtrVec *from, bool exact_copy)
{
    int i;

    if ( !from )
        return NULL;

    NodePtrVec *to = exact_copy ? NodePtrVec_new(from->allocatedSize)
                                : NodePtrVec_new(from->contentSize);
    if ( !to )
        return NULL;

    for ( i = 0; i < from->contentSize; ++i )
        to->vector[i] = from->vector[i];
    to->contentSize = from->contentSize;
    return to;
}

/* pushes the element if it can. If a memory allocation is required but
 * fails - false is returned
 */
bool NodePtrVec_push( NodePtrVec *vector, Node *node )
{
    int current;
    int max;

    /* some basic error checking */
    if ( !vector ) return false;

    current = vector->contentSize;
    max = vector->allocatedSize;

    /* see if our vector is full */
    if ( current == max )
    {
        vector->vector = realloc( vector->vector, 2*max * sizeof(Node *) );
        if ( vector->vector )
        {
            vector->allocatedSize = 2*max;
        }
        else
        {
            printf ( "\n\nNodePtrVec_push failed malloc(%d). Node: %d", 2*max, node->id );
            if ( node->label )
                printf ( ", label: %s\n", node->label );
            else
                printf ( "\n\n" );
            return false;
        }
    }

    /* do the actual pushing */
    vector->vector[current] = node;
    vector->contentSize += 1;

    return true;
}

/* returns the top item and decrements. What do we do to define empty? */
Node * NodePtrVec_pop( NodePtrVec *vector )
{
    Node *top = NULL;

    /* some basic error checking */
    if ( !vector ) return NULL;

    if ( vector->contentSize > 0 )
    {
        vector->contentSize -= 1;
        top = vector->vector[vector->contentSize];
    }

    return top;
}

/* Screams through the vector from bottom to top to find the specified element. If found,
 * returns true.
 */
bool NodePtrVec_find( NodePtrVec *vector, Node *node )
{
    int i;

    /* some basic error checking */
    if ( !vector ) return false;

    for ( i = 0; i < vector->contentSize; ++i )
        if ( vector->vector[i] == node )
            return true;

    return false;
}

/* Screams through the vector from top to bottom to find the specified element. If found,
 * returns true.  */
bool NodePtrVec_findReverse( NodePtrVec *vector, Node *node )
{
    int i;

    /* some basic error checking */
    if ( !vector || !vector->vector || !node ) return false;

    for ( i = vector->contentSize-1; i >= 0; --i )
        if ( vector->vector[i] == node )
            return true;

    return false;
}


/* Appends the second vector to the first. If the "keepFirst" flag is set, the
 * entire second vector is appended to the first. Otherwise, the [0] element of
 * the second vector is skipped. This is useful when the last element of the
 * first vector is identical to the first element of the second vector, and
 * we don't want duplication. (And who, really, wants duplication? Really, who
 * wants duplication?)
 */
void NodePtrVec_appendVectors ( NodePtrVec *first, NodePtrVec *second, bool keepFirst )
{
    int i;

    /* Some basic error checking */
    if ( !first || !second )
        return;

    if ( keepFirst )
        i = 0;
    else
        i = 1;

    for ( ; i < second->contentSize; ++i )
        NodePtrVec_push( first, second->vector[i] );
}



/* -------------------------------------------
 * Node Vec Vec Method definitions
 *
 * (vector of Node Pointer Vectors )
 */

/* create a new vector allocating specified size */
NodeVecVec *NodeVecVec_new( int initialSize )
{
    NodeVecVec *newVector;
    NodePtrVec **vector; /* an array of pointers */

    vector = malloc ( initialSize * sizeof(NodePtrVec *) );
    if ( !vector )
    {
        printf ( "Malloc failure in NodeVecVec storage creation\n" );
        fflush(stdout);
        return( NULL );
    }

    newVector =  malloc ( sizeof(NodeVecVec) );
    if ( !newVector )
    {
        free(vector);
        printf ( "Malloc failure in NodeVecVec creation\n" );
        fflush(stdout);
        return( NULL );
    }

    newVector->allocatedSize = initialSize;
    newVector->contentSize = 0;
    newVector->vector = vector;
    return( newVector );
}



/* destructor */
void NodeVecVec_delete( NodeVecVec *trash )
{
    int i;
    if ( trash )
    {
        for ( i = 0; i < trash->contentSize; ++i )
            NodePtrVec_delete(trash->vector[i]);
        if ( trash->vector )
            free(trash->vector);
        free(trash);
    }
}


/* pushes a copy of the element if it can. If a memory allocation is required but
 * fails - false is returned
 */
bool NodeVecVec_insert( NodeVecVec *vector, NodePtrVec *path )
{
    int current;
    int max;
    NodePtrVec *copy = NodePtrVec_copy(path,false);

    /* some basic error checking */
    if ( !vector || !path || !copy ) return false;

    current = vector->contentSize;
    max = vector->allocatedSize;

    /* see if our vector is full */
    if ( current == max )
    {
        vector->vector = realloc( vector->vector, 2*max * sizeof(Node *) );
        if ( vector->vector )
        {
            vector->allocatedSize = 2*max;
        }
        else
        {
            printf ( "\n\nNodeVecVec_push failed malloc\n" );
            fflush(stdout);
            return false;
        }
    }

    /* do the actual pushing */
    vector->vector[current] = copy;
    vector->contentSize += 1;

    return true;
}



