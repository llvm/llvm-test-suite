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
 * searchAlgorithms.c
 *
 *  Created on: Jun 18, 2013
 *      Author: jbrigdo
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifdef USE_OMP
#include <omp.h>
#endif

#include "searchAlgorithms.h"
#include "vectorUtils.h"
#include "utils.h"
#include "graphGen.h"
#include "statistics.h"
#include "yaml.h"


extern double currentTime();

static Stats *globalStats = NULL;



void doMultiSearches(Configuration *config)
{
    NodePtrVec *result;
    bool success;
    Graph *graph;
    Signature signature;
    int i;
    int j;
    char *debug;
    double tick, tock;
    int hours;
    int min;
    double sec;

    tick = currentTime();
    result = NodePtrVec_new(64); /* 64 is an arbitrary size */

    for ( i = 0; config->signatures[i] != NULL; ++i )
    {
        signature = config->signatures[i];
        /* Debug --* /
        printf ("\n\nSignature (");
        for ( k = 0; signature[k] != NULL; ++k )
        {
            debug = signature[k];
            printf("%s", signature[k]);
            if ( signature[k+1] != NULL )
                printf(" ");
            else
                printf("):\n");
        }
        / *-- End Debug */
        // printf("Signature %d:\n", i);
        for ( j = 0; config->graphs[j] != NULL; ++j )
        {
            graph = config->graphs[j];
            result->contentSize = 0; /* clear last search's result */
            // printf("\t checking file %s... ", graph->fileName);
            fflush(stdout);
            success = findLabelPath(graph, signature, result, config->searchOptions->searchType);
            if ( success )
                {}// printf("Found!\n");
            else
                {}// printf("Not found. Bummer.\n");
        }
    }

    tock = currentTime();
    sec = tock-tick;
    hours = (int)sec/3600;
    sec = fmod( sec, 3600.0 );
    min = (int)sec/60;
    sec = fmod(sec, 60.0);
    printf ("\n\nOverall Search Time: %02d:02%d:%05.2f\n", hours, min, sec);

}

/* findNextLabel is a recursive method that determines if a path exists between a
 * specific node and the label that is at the start of the label array argument. The
 * label array is an array of char pointers that is terminated with a NULL pointer. The
 * first pointer is the "current" label.
 *
 * The node's edge nodes are checked against the current label. If none of them match, then
 * this method recurses with each edge node and the current label.
 *
 * If an edge matches, then we are beginning a search for the next "leg" of the labels.
 * We recurse with that specific edge and the "next" label. That is the [1] element of
 * the label array. This starts the search along the next leg - at this point we have
 * to start a new "result" vector, because we check that vector for loops. It MAY be the
 * case that the next path segment passes through nodes already traversed in a previous
 * leg. A new "result" vector will solve that.
 *
 * If the next element in the labels list is NULL, the matching edge signifies the end of
 * our search! VICTORY!
 *
 * If we reach the last edge with out a match (directly or recursively) we return a false
 * list.
 */

bool findNextLabel( Node *node, Signature labels, NodePtrVec *result, Bitfield *visited ) /* NodePtrVec *visited ) */
{
    EdgeList *edge;
    bool success = false;
    NodePtrVec *nextLegResult = NULL;
    /* NodePtrVec *nextLegVisited = NULL; */
    Bitfield *nextLegVisited = NULL;


    /* A little basic error checking */
    if ( !node || !labels || !result|| !visited )
    {
        return( false );
    }

    /* If this node is already in the vector, we have found a loop. return false. */

    if ( Bitfield_nodeVisited( visited, node ) )
        return( false );

    /* put this node on the result vector to show that we've been here */
    NodePtrVec_push( result, node );

    /* Check this node's edges to see if there's a match */
    /* Note: We have a NodePtrVec holding the set of nodes with this label. It
     *       may be more optimal to see if a given edge node is in that set
     *       rather than doing a bunch of inefficient strcmp calls. Another approach
     *       would be to have unique hash values for each label, and thereby be
     *       able to compare those. However for the initial version of this code,
     *       keeping things simple and straightforward, we're doing the string
     *       compare.
     */

    for ( edge = node->edges; edge != NULL; edge = edge->nextEdge )
    {

        // string based:
        if ( edge->targetNode->label && strcmp( edge->targetNode->label, labels[0] ) == 0 )
        // index based: if ( edge->targetNode->labelIdx == labelIdxs[0] )
        {
            if ( labels[1] != NULL ) /* more steps in the signature */
            {
                nextLegResult = NodePtrVec_new( 50 ); /* arbitrary size, malloc success checked in recursion */
                nextLegVisited = Bitfield_new(visited->bitsNeeded);

                success = findNextLabel( edge->targetNode, &labels[1], nextLegResult, nextLegVisited );
                /* NodePtrVec_delete( nextLegVisited ); */
                Bitfield_delete( nextLegVisited );
                if ( success )
                {
                    NodePtrVec_appendVectors( result, nextLegResult, true );
                    NodePtrVec_delete( nextLegResult );
                    return( true );
                }

            }
            else /* We have exhausted the signature - ultimate victory! */
            {
                /* Register this edge node as being the final node */
                NodePtrVec_push( result, edge->targetNode );
                return( true );
            }
        }
    }


    /* IF we made it here, we need to continue through the tree, seeing if any of our
     * edge nodes have a connection to a labeled node.
     */
    for ( edge = node->edges; edge != NULL; edge = edge->nextEdge )
    {
        success = findNextLabel( edge->targetNode, labels, result, visited );
        if ( success )
            return( true ); /* this edge has a path to the ultimate signature path */
    }


    /* and, if we make it here, we have failed. */
    NodePtrVec_pop( result ); /* take current node off the result vector */
    return false;
}



/* A method to custom-store our results */
static void logStats(NodePtrVec *result)
{
    if ( !result ) return;
    if ( !globalStats )
        globalStats = Stats_new();
    Stats_logPath(globalStats, result);
}

static void printStats()
{
    int i;

    if ( globalStats )
    {
        Stats_calculate(globalStats);

        printf ( "\nThis graph has %f average nodes between labels.\nStandard deviation: %f, total paths: %d\n\n",
                globalStats->averageLength, globalStats->standardDeviation, globalStats->pathLengths->size );
        printf ("\tShortest Path: %d, Longest Path: %d\n", globalStats->minLength, globalStats->maxLength);
        for ( i = globalStats->minLength; i <= globalStats->maxLength; ++i )
        {
            if ( globalStats->histogram[i] != 0 )
                printf ("\tlength %d appeared %d times\n", i, globalStats->histogram[i] );
        }

    }
}


/* A method to custom-store our results */

/* At some point, we will want to use the FullPath argument and pass it along to
 * buildGraphFromPaths. Until then, however, we're only going to build the most
 * minimal graph possible.
 */
static void logResult(NodeVecVec *storage, NodePtrVec *result, SearchOptions *options)
{
    NodePtrVec *tips = NodePtrVec_new(2);
    if ( !storage || !result || !tips ) return;

    /* We log the stats here, because the storage method below may not hold
     * the entire path.
     */
    if ( !options->multiThreaded && options->doStatistics ) /* statistics are not thread-safe yet */
        logStats(result);

    /* Ultimately we may want to log more than the ends... */
    /* Future: if ( options->buildType == endNodesOnly ) { */
    NodePtrVec_push(tips, result->vector[0]);
    NodePtrVec_push(tips, result->vector[result->contentSize-1]);
    if ( !NodeVecVec_insert(storage, tips) ) /* makes a copy of tips, so we need to... */
    {
        printf("CrashAndBURN!!!\n\n");
        fflush(stdout);
    }
    NodePtrVec_delete(tips); /* ... free the mallocs! */
}



/* findAndRecordAllPaths is almost exactly like findNextLabel. It differs only in that it
 * 1) doesn't stop with the first discovery of the specified path and 2) records the discovered
 * path. To do this, it doesn't create a new result vector for
 */

void findAndRecordAllPaths( Node *node, Signature labels, int *labelIdxs,
        NodePtrVec *result, Bitfield *visited, NodeVecVec *storage,
        SearchOptions *options )
{
    EdgeList *edge;
    /* NodePtrVec *nextLegVisited = NULL; */
    Bitfield *nextLegVisited = NULL;


    /* A little basic error checking */
    if ( !node || !labels || !labelIdxs || !result|| !visited )
    {
        return;
    }

    /* If this node is already in the vector, we have found a loop. return false. */
/*
    if ( NodePtrVec_findReverse( visited, node ) )
        return( false );
    else
        NodePtrVec_push( visited, node );
*/
    if ( Bitfield_nodeVisited( visited, node ) )
        return;

    /* put this node on the result vector to show that we've been here */
    NodePtrVec_push( result, node );

    /* Check this node's edges to see if there's a match */
    /* Note: We have a NodePtrVec holding the set of nodes with this label. It
     *       may be more optimal to see if a given edge node is in that set
     *       rather than doing a bunch of inefficient strcmp calls. Another approach
     *       would be to have unique hash values for each label, and thereby be
     *       able to compare those. However for the initial version of this code,
     *       keeping things simple and straightforward, we're doing the string
     *       compare.
     */

    for ( edge = node->edges; edge != NULL; edge = edge->nextEdge )
    {

        // string based:
        if ( edge->targetNode->label && strcmp( edge->targetNode->label, labels[0] ) == 0 )
        // index based: if ( edge->targetNode->labelIdx == labelIdxs[0] )
        {
            // strcmp based:
            if ( labels[1] != NULL ) /* more steps in the signature */
            // index based: if ( labelIdxs[1] != -1 ) /* more steps in the signature */
            {
                nextLegVisited = Bitfield_new(visited->bitsNeeded);
                findAndRecordAllPaths(edge->targetNode, &labels[1], &labelIdxs[1], result,
                        nextLegVisited, storage, options );
                Bitfield_delete(nextLegVisited);
            }
            else /* We have exhausted the signature - ultimate victory! */
            {
                /* Register this edge node as being the final node */
                // printf ("\tFound!\n");
                NodePtrVec_push(result, edge->targetNode);
                Bitfield_nodeVisited(visited, edge->targetNode);/* Mark it as visited */
                logResult(storage, result, options); // <<<--- here's where I record it
                NodePtrVec_pop(result);
            }
        }
    }


    /* IF we made it here, we need to continue through the tree, seeing if any of our
     * edge nodes have a connection to a labeled node.
     */
    for ( edge = node->edges; edge != NULL; edge = edge->nextEdge )
    {
        findAndRecordAllPaths(edge->targetNode, labels, labelIdxs, result, visited, storage, options);
    }

    NodePtrVec_pop( result ); /* take current node off the result vector */
    return;
}



/* findLabelPath takes an array of labels, determines if there are nodes associated
 * with the labels (each label search will return a NodePtrVec*), and determine if
 * paths exist passing through the set of labels. This returns the first FOUND
 * path, not the optimal one. We could do that in a future iteration of the code
 * by keeping track of all paths found, and going with the shortest.
 *
 * The labels passed in is an array of char pointers. The array is null terminated -
 * i.e. the last valid entry in the array is followed by a pointer with NULL in it.
 */
bool findLabelPath( Graph *graph, Signature labels, NodePtrVec *result, SearchType searchType )
{
    NodePtrVec *startNodes = NULL; /* set of nodes with the first label - potential path start nodes */
    int i;
    bool found = false; /* stopping as soon as we can find a path to a final node */
    /* NodePtrVec *visited = NodePtrVec_new( 50 ); /-* arbitrary size *-/ */
    Bitfield *visited = Bitfield_new(graph->totalNodes);


    /* some basic error checking */
    if ( !graph || !labels || !labels[0] || !labels[1] || !result  || !visited )
        return( false );

    /* Un-comment to short-circuit searches for non-represented signatures. -->* /
    if ( !SystemCallMap_signatureRepresented( graph->systemCallMap, labels ) )
    {
        //printf( "%s %s invalid signature labels for graph.\n", labels[0], labels[1] );
        return( false );
    }
    / *<-- end of short-circuit region */

    startNodes = SystemCallMap_findLabeledNodes( graph->systemCallMap, labels[0] );

    if ( !startNodes )
        return( false );

    /* So, if we've made it this far, we have a valid start label.  Now, we need to
     * iterate through the start nodes and see if they can get to the next label...
     */

    for ( i = 0; i < startNodes->contentSize && !found; ++i )
    {
        if ( searchType == diagramSearch )
        {
            SearchDiagram *element = SearchDiagram_findNode( graph->searchDiagram, startNodes->vector[i] );
            if ( element )
                found = SearchDiagram_findSignatureAlongEdges( element->node, element->edgeReferenceArray,
                                                               &labels[1], result, visited );
        }
        else
            found = findNextLabel( startNodes->vector[i], &labels[1], result, visited );
        Bitfield_clear( visited );

        if ( !found && result->contentSize != 0 ) /* If it's not found the result SHOULD be empty, however... */
            result->contentSize = 0; /* effectively clear the result NodePtrVec */
    }


    /* NodePtrVec_delete( visited ); */
    Bitfield_delete( visited );
    return( found );
}


/* findAllPossibleLegs does an exhaustive search through each possible label
 * pairing to determine which legs are possible. This is a brute-force nxn
 * approach that builds a signature holding only the second label and then
 * searches for that signature from the nodes representing the first label.
 * For the time being, it simply prints out the legs that are  possible in
 * this graph.
 */
int findAllPossibleLegs( Graph *graph, SearchType searchType )
{
    int i, j;
    int found = 0;
    int searches = 0;
    double tick, tock;
    int hours, min;
    double sec;
    char timeStr[50];

    tick = currentTime();
    fprintf ( stdout, "Immediately before parallel\n" );

    //#pragma omp parallel private(i,j) shared(graph) reduction(+:found) reduction(+:searches)
    //#pragma omp single
    {
        //#pragma omp parallel for private(i,j) default(none)
        #ifdef USE_OMP
        #pragma omp parallel for private(i,j) shared(graph) reduction(+:found) reduction(+:searches) 
        #pragma omp collapse(2)
        #endif
        for ( i = 0; i < graph->systemCallMap->contentSize; ++i )
        {
            for ( j = 0; j < graph->systemCallMap->contentSize; ++j )
            {
                ++searches;
                char *fullSignature[3] = { NULL, NULL, NULL };
                int fullIntSignature[3] = { 0, 0, -1 };
                fullSignature[0] = graph->systemCallMap->vector[i]->label;
                fullSignature[1] = graph->systemCallMap->vector[j]->label;
                fullIntSignature[0] = i;
                fullIntSignature[1] = j;
                // NodePtrVec *result = NodePtrVec_new(25);

                /* findLabelPath does the findNextLabel in the above loops */
                //#pragma omp task shared(graph, fullSignature, found)
                {
                    NodePtrVec *result = NodePtrVec_new( 25 );
                    if ( findLabelPath( graph, fullSignature, result, searchType ) )
                    {
//                        printStack(result);
                        // logStats(result);
                        ++ found;
                    }
                    else
                    {
//                        printf ( "\n\tPath does not exist %s --/ /-> %s. %d steps.\n", fullSignature[0],
//                                 fullSignature[1], result->contentSize );
                    }
                    if ( result )
                    {
                        NodePtrVec_delete( result );
                    }
                }
            }
            //#pragma omp taskwait
        }
    }


    tock = currentTime();


    sec = tock-tick;
    hours = (int)sec/3600;
    sec = fmod( sec, 3600.0 );
    min = (int)sec/60;
    sec = fmod( sec, 60.0 );
    printf ( "\n\n%d found out of %d searches. Overall Time: %d:%d:%2.3f\n",
             found, searches, hours, min, sec );
    timeStr[0] = '\0'; /* just in case sprintf doesn't do what we want. */
    sprintf ( timeStr, "%02d:%02d:%02.3f", hours, min, sec );
    YAMLWriteInt("Signatures Found", found);
    YAMLWriteString("Search Time", timeStr);
    

    //printStats();

    return( found );
}

/*
 * findAndLogAllPossibleLegs has the same search algorithm as findAllPossibleLegs. However, the requirement
 * that all the legs be logged requires a more sophisticated means of parallelization in order to do a
 * reduction of the solutions when all the threads are done.
 */
int findAndLogAllPossibleLegs(Graph *graph, SearchOptions *options)
{
    int i, j, k;
    int found = 0;
    int searches = 0;
    double tick, tock;
    int hours, min;
    double sec;
    int maxThreads = 1;
    NodeVecVec **lastingResults;
    Graph *optimizedGraph = NULL;
    char timeStr[50];

    /* A little bit of error checking */
    if ( !graph )
        return 0;

    tick = currentTime();
    fprintf(stdout, "Immediately before parallel\n" );

    #ifdef USE_OMP
    #pragma omp parallel private(i,j,k) shared(graph,maxThreads,lastingResults) reduction(+:found) reduction(+:searches)
    #endif
    {
        #ifdef USE_OMP
        int myThread = omp_get_thread_num();
        #else
        int myThread = 0;
        #endif

        NodeVecVec *myResults = NULL;

        #ifdef USE_OMP
        #pragma omp single
        #endif
        {
            #ifdef USE_OMP
            maxThreads = omp_get_num_threads();
            #else
            maxThreads = 1;
            #endif

            options->multiThreaded = maxThreads > 1;
            /* debug * /printf( "%d total threads, this one is %d\n", maxThreads, myThread ); / * debug */
            lastingResults = malloc((maxThreads+1) * sizeof(NodeVecVec*) );
            lastingResults[maxThreads] = 0; /* Null terminated to avoid having to keep track of bitsNeeded */
        }

        #ifdef USE_OMP
        #pragma omp critical
        #endif
        {
            lastingResults[myThread] = NodeVecVec_new(64); /* Arbitrary - multiple of 8, eventually cache line aligned... */
            myResults = lastingResults[myThread];
        }

        #ifdef USE_OMP
        #pragma omp single
        #endif
        {
            printf ("Immediately before nested for's\n");
        }

        #ifdef USE_OMP
        #pragma omp for 
        #pragma omp collapse(2)
        #endif
        for ( i = 0; i < graph->systemCallMap->contentSize; ++i )
        {
            for ( j = 0; j < graph->systemCallMap->contentSize; ++j )
            {
                ++searches;
                for (k = 0; k < graph->systemCallMap->vector[i]->nodes->contentSize; ++k)
                {
                    char *fullSignature[3] = { NULL, NULL, NULL };
                    int fullIntSignature[3] = { 0, 0, -1 };
                    fullSignature[0] = graph->systemCallMap->vector[i]->label;
                    fullSignature[1] = graph->systemCallMap->vector[j]->label;
                    fullIntSignature[0] = i;
                    fullIntSignature[1] = j;
                    NodePtrVec *result = NodePtrVec_new(16);
                    Bitfield *visited = Bitfield_new(graph->totalNodes);
                    /* debug ---> * /
                    printf( "Searching for %s(%d) ~~~> %s\n", fullSignature[0],
                            graph->systemCallMap->vector[i]->nodes->vector[k]->id,
                            fullSignature[1]);
                    / * <-- debug */
                    findAndRecordAllPaths( graph->systemCallMap->vector[i]->nodes->vector[k], &fullSignature[1],
                            &fullIntSignature[1], result, visited, myResults, options );
                    Bitfield_delete(visited);
                    if ( result )
                        NodePtrVec_delete( result );
                } // end of for (k)... fork? heh.
            } // end of for (j)
        } // end of for (i)

        found = myResults->contentSize;
    }

    tock = currentTime();
    sec = tock-tick;
    hours = (int)sec/3600;
    sec = fmod( sec, 3600.0 );
    min = (int)sec/60;
    sec = fmod( sec, 60.0 );
    printf ( "\n\n%d found for %d searches. Overall Time: %d:%d:%2.3f\n",
            found, searches, hours, min, sec );
    timeStr[0] = '\0'; /* just in case sprintf doesn't do what we want. */
    sprintf ( timeStr, "%02d:%02d:%02.3f", hours, min, sec );
    YAMLWriteInt("Signatures Found", found);
    YAMLWriteString("Search Time", timeStr);

    /* debug --> * /
    printf ("max threads still:%d\n", maxThreads);
    for ( i = 0; i < maxThreads; ++i )
    {
        printf ( "printing out thread %d result - %d long\n", i, lastingResults[i]->contentSize );
        for ( j = 0; j < lastingResults[i]->contentSize; ++j )
        {
            printf("\t");
            printStack( lastingResults[i]->vector[j] );
            printf("\n");
        }
    }
    / * <-- debug */

    /* At some point, we will want to use the FullPath argument and pass it along to
     * buildGraphFromPaths. Until then, however, we're only going to build the most
     * minimal graph possible.
     */
    if ( options->writeOutputFile && options->outputFile )
    {
        optimizedGraph = buildGraphFromPaths(lastingResults, options->buildType);
        exportGraph(optimizedGraph, options->outputFile);
    }

    if ( options->doStatistics && !options->multiThreaded )
        printStats();

    return( found );
}
