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
 * statistics.c
 *
 *  Created on: Sept 24, 2013
 *      Author: Brian "Rig" Rigdon
 */

#include "statistics.h"
#include <math.h>
#include <limits.h>

HistogramElement *HistogramElement_new(int length)
{
    HistogramElement *new = malloc(sizeof(HistogramElement));
    if ( !new )
        return NULL;
    new->length = length;
    new->count = 1;
    new->next = NULL;
    return(new);
}

bool HistogramElement_updateList(HistogramElement **head, int length)
{
    HistogramElement **prev = NULL;
    HistogramElement *current = NULL;
    HistogramElement *new = NULL;
    bool histogramInsert = false;
    
    prev = head;
    for ( current = *head; current != NULL; current = current->next )
    {
        if ( current->length < length )
        {
            prev = &current->next;
            continue; /* iterate down the histogram linked list */
        }
        if ( current->length == length )
        {
            ++current->count;
            histogramInsert = true;
            break;
        }
        if ( current->length > length )
        {
            /* we are logging a new length, need to allocate and insert */
            new = HistogramElement_new(length);
            if ( ! new )
                return(false);
            new->next = current;
            (*prev) = new;
            histogramInsert = true;
            break;
        }
    }
    
    if ( !histogramInsert ) /* this element belongs at the end of the chain */
    {
        (*prev) = HistogramElement_new(length);
        if ( (*prev) == NULL )
            return(false);
    }

    return(true);
}

Stats *Stats_new()
{
    Stats* new = malloc(sizeof(Stats));
    if ( new )
    {
        new->pathLengths = IntVector_new(16); // Arbitrary, multiple of 8 for vectorization
        new->averageLength = 0.0;
        new->standardDeviation = 0.0;
        new->minLength = INT_MAX;
        new->maxLength = 0;
        new->histogram = NULL;
        if ( new->pathLengths )
            return(new);
        else
        {
            free(new);
            return(NULL);
        }
    }
    else
        return(NULL);
}


void Stats_delete(Stats* stats)
{
    if ( stats )
    {
        if ( stats->pathLengths )
            free(stats->pathLengths);
        free(stats);
    }
}


bool Stats_logPath(Stats* stats, NodePtrVec* path)
{
//    bool histogramInsert = false;
//    HistogramElement **prev = NULL;
//    HistogramElement *hist = NULL;
//    HistogramElement *new = NULL;
    int length;
    
    if ( !stats || !stats->pathLengths || !path )
        return(false);

    length = path->contentSize;
    if ( length < stats->minLength )
        stats->minLength = length;
    if ( length > stats->maxLength )
        stats->maxLength = length;
    return ( IntVector_insertEnd(stats->pathLengths, length) );
}

void Stats_calculate(Stats* stats)
{
    int i;
    int length;
    double sum;
    double diff;
    
    /* a little basic error checking */
    if ( !stats || !stats->pathLengths || stats->pathLengths == 0 )
        return;
    stats->histogram = calloc((stats->maxLength+1), sizeof(int));
    if ( !stats->histogram )
        return;
    
    for ( i = 0; i < stats->pathLengths->size; ++i )
    {
        if ( stats->pathLengths->vector[i] > 0 )
        {
            length = stats->pathLengths->vector[i];
            sum += (double)length;
            /* While we're iterating through the list, let's build our histogram... */
            /* HistogramElement_updateList(&stats->histogram, length); */
            stats->histogram[length] += 1;
        }
    }
    if ( i > 0 )
        stats->averageLength = sum / (double)i;
    
    sum = 0.0;
    for ( i = 0; i < stats->pathLengths->size; ++i )
    {
        if ( stats->pathLengths->vector[i] > 0 )
        {
            diff = (double)stats->pathLengths->vector[i] - stats->averageLength;
            sum += diff * diff; 
        }
    }
    
    if ( i > 0 )
        stats->standardDeviation = sqrt(sum/(double)i);
}


void testStats()
{
    int i;
    Stats *test = Stats_new();
    NodePtrVec bogon;
    
    for ( i = 2; i < 10; ++i )
    {
        bogon.contentSize = i;
        Stats_logPath(test,&bogon);
    }
    
    /* Throw in some more silly data */
    bogon.contentSize = 1;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 4;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 5;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 6;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 5;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 5;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 4;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 5;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 6;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 5;
    Stats_logPath(test,&bogon);
    bogon.contentSize = 5;
    Stats_logPath(test,&bogon);
    
    Stats_calculate(test);
    printf("avg: %f\nstd dev: %f\n", test->averageLength, test->standardDeviation);
    printf("Histogram:\n");
    for ( i = test->minLength; i < test->maxLength; ++i )
    {
        printf ("\tlength %d appeared %d times\n", i, test->histogram[i] );
    }
    
}

