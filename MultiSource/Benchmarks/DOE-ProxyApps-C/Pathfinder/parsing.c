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
 * graph.c
 *
 *  Created on: Jan 9, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#include "parsing.h"
#include "graph.h"
#include "utils.h"
#include "systemCallMap.h"
#include "yaml.h"


#include <ctype.h>


/* buildEntranceList takes an array of integers, and builds a
 * non-resolved edge list from the array. This is a special
 * edge list, used only be outer nodes to identify entrance
 * points into their subgraph. Only the edge data is passed in,
 * this begins with the second entry (index 1) in the parsed
 * data array. Likewise the size only counts edges.
 *
 * Initially, entrance transitions were handled as a separate
 * list of edges. After further analysis, however, there is
 * no operational difference between outer edges and entrance
 * edges. Ergo, we are modifying this code to put the entrance
 * edges into the edge list and deprecating the entrance list.
 * The code is being left in for the time being as comments,
 * since there are some contextual significances to interior
 * nodes and entrance edges that may later be required. Otherwise
 * we could go to a simple flat graph.
 */
void buildEntranceList( Node *outerNode, IntVector *nodeData )
{
    int i;
    int entranceCount;

    /* some basic error checking */
    if ( !outerNode || !nodeData ) return;

    entranceCount = nodeData->vector[1]; /* count is the first entry, (second of original data); */
    if ( entranceCount == 0 )
        return; /* Nothing to see here, folks */

    if ( entranceCount != nodeData->size-2 )
    {
        fprintf ( stderr, "Specified entrance edge length does not match data size for node: %d\n",
                outerNode->id );
    }

    /* Deprecated: outerNode->entranceNodes = EdgeList_new(); */
    /* Deprecated: if ( outerNode->entranceNodes ) */
    if ( !outerNode->edges )
        outerNode->edges = EdgeList_new();
    if ( outerNode->edges )
        for ( i = 2; i < nodeData->size; ++i )
        {
            /* Deprecated EdgeList_insertBack( outerNode->entranceNodes, edgeData[i] ); */
            EdgeList_insertNodeId( outerNode->edges, nodeData->vector[i] );
            ++outerNode->entranceCount;
        }
}


/* buildNodeFromData takes the integer array built by the above
 * method, and creates a node from it. If that node has
 * edge data, that is also built. The data is in an array,
 * the size of which is also passed in.
 */
Node *buildNodeFromData( IntVector *nodeData )
{
    int i;
    int edgeCount;

    /* some basic error checking */
    if ( nodeData == NULL || nodeData->size == 0 )
        return( NULL );

    Node *node = Node_new( nodeData->vector[0], -1 ); /* Calling method must set index. */
    if ( !node )
        return( NULL );

    /* Currently, the second element in is the edge count */
    edgeCount = nodeData->vector[1];
    if ( edgeCount != nodeData->size-2 )
    {
        fprintf ( stderr, "Specified edge length does not match data size for node: %d\n",
                  nodeData->vector[0] );
    }

    if ( edgeCount > 0 )
    {
        node->edges = EdgeList_new();
        if ( node->edges )
            for ( i = 2; i < nodeData->size; ++i )
            {
                EdgeList_insertNodeId ( node->edges, nodeData->vector[i] );
                ++node->edgeCount;
            }
    }

    return( node );
}


/* resolveNodeEdges is the second pass through the graph data
 * structures. The first pass defines the nodes, and puts the edge
 * ids in place. The second pass finds the nodes corresponding to
 * the edge id, and sets the edge pointer to that node. Edges for
 * outer nodes will only reference other outer nodes. Interior
 * nodes may have edges to outer nodes or other interior nodes of
 * their containing node. If an edge references an undefined node
 * or if an edge goes into the interior of another outer node,
 * the user will be notified.
 *
 * Note: The section that resolves entrance edges has been commented
 * out because entrance edges are now processed as part of the edge
 * list.
 */
void resolveNodeEdges( Graph *graph, Node* sourceNode, bool outerNode )
{
    EdgeList *edges;
    Node *node;
    bool okSoFar;

    for ( edges = sourceNode->edges; edges != NULL; edges = edges->nextEdge )
    {
        if ( outerNode )
        {
            /* We only check for edges to other outer nodes*/
            node = Graph_findNode( graph, edges->targetNodeId, true ); /* true-> check outer and interior nodes */
            if ( node )
            {
                okSoFar = true;
                /* Since entrance edges are now part of our edge list, we have to make sure
                 * the link here is appropriate.
                 */
                if ( node->type == entranceNode || node->type == interiorNode )
                {
                    if ( node->container != sourceNode )
                    {
                        fprintf( stderr,
                                 "resolveNodeEdges: Outer node %d edge to non-contained node: %d\n",
                                 sourceNode->id, edges->targetNodeId );
                        fprintf(stderr, "\t%d is type: %s (%d)\n", node->id, node->type == interiorNode ? "interior" : "entrance", (int)node->type);
                        okSoFar = false;
                    }
                }
                if ( okSoFar )
                    edges->targetNode = node;
            }
            else
                fprintf( stderr,
                        "resolveNodeEdges: Outer node %d has edge reference to undefined node: %d\n",
                        sourceNode->id, edges->targetNodeId );
        }
        else
        {
            /* Interior node - the edge can be to an outer node... */
            node = Graph_findNode( graph, edges->targetNodeId, false ); /* false-> only check outer nodes */
            if ( node )
                edges->targetNode = node;
            else
            {
                /* ... or nodes interior to the container of this node */
                node = Graph_findContainedNode( sourceNode->container, edges->targetNodeId );
                if ( node )
                    edges->targetNode = node;
                else
                {
                    /* we have an undefined node */
                    fprintf( stderr,
                            "resolveNodeEdges: Interior node %d has edge reference to undefined node: %d\n",
                            sourceNode->id, edges->targetNodeId );
                }
            }
        }
    }

}


/* pruneLine takes the \r\n off the end of the label. This is an artifact of
 * the windows file system, not something that was intended to be a part
 * of the actual label string.
 */
static void pruneLine( char *label )
{
    int i = 0;

    for ( ; label[i] != '\0'; ++i )
    {
        if ( label[i] == '\r' )
        {
            label[i] = '\0';
            return;
        }
        if ( label[i] == '\n' )
        {
            label[i] = '\0';
            return;
        }
    }
}

/* parseFile goes through the specified file to build the graph. It
 * returns a pointer to the graph instance created by the data. Otherwise
 * it returns NULL if the file is not parsable.
 */

Graph *parseFile( char *fileName )
{
    FILE *inFile;
    IntVector *fileData = NULL;
    CharVector *fileString = NULL;
    Node *newNode = NULL;
    Node *outerNode = NULL;
    Node *findNode = NULL;
    int temp, count;
    NodeList *outerNodeList = NULL;
    NodeList *innerNodeList = NULL;
    Graph *newGraph = NULL;
    int funcCount = 50; /* used as a default initial size for the system call table */
    int blockCount =  0;
    bool systemCallSection = false;
    int i;

    /* A little error checking */
    if ( !fileName )
        return( NULL );

#ifdef PRINT_FILE
    printf ( "Parsing file %s...\n", fileName );
#endif

    inFile = fopen( fileName, "r" );
    if ( !inFile )
    {
        printf( "Could not open data file: %s (parsing.c:parseFile)\n", fileName );
        return( NULL );
    }
    /* else
        printf( "Opened %s\n\n", fileName ); */

    newGraph = Graph_new();
    if ( !newGraph )
        return( NULL );

    newGraph->fileName = strdup( fileName );
    fileString = CharVector_new( 1024 ); /* allocate our data parsing storage - 1024 is a semi-arbitrary power of 2 */

    i = 0;

    /* The first two lines define the number of Functions and basic blocks. */
    CharVector_getLineFromFile( fileString, inFile );
    if ( !feof( inFile ) && ( strncmp ( "Functions:", fileString->string, 10 ) == 0 ) )
    {
        funcCount = atoi ( fileString->string+10 );
        printf ( "\t%d functions specified\n", funcCount );
        YAMLWriteInt("Functions", funcCount);
    }
    else
    {
        fprintf ( stderr, "Malformed file, Function count not specified in first line\n" );
        return( NULL );
    }

    CharVector_getLineFromFile( fileString, inFile );
    if ( !feof( inFile ) && ( strncmp ( "Basic blocks:", fileString->string, 13 ) == 0 ) )
    {
        blockCount = atoi ( fileString->string+13 );
        printf ( "\t%d basic blocks specified\n", blockCount );
        YAMLWriteInt("Basic Blocks", blockCount);
    }
    else
    {
        fprintf ( stderr, "Malformed file, Function count not specified in first line\n" );
        return( NULL );
    }

    // printf ("Done with header\n");

    fileData = IntVector_new( 8 ); /* allocate our data parsing storage - 8 is a semi-arbitrary power of 2 */

    /*
     * The first section defines the outer nodes. Scan through it to identify the
     * nodes and to do the first pass of edge definition.
     */
    while ( !feof( inFile ) ) /* clumsy use of feof */
    {
        CharVector_getLineFromFile( fileString, inFile );

        if ( feof( inFile ) ) /* that read line was the last line */
            break;

        if ( strncmp( "----------", fileString->string, 10 ) == 0 ) /* we have a section break */
            break;

        count = IntVector_createFromString ( fileData, fileString->string );

        if ( count > 0 )
        {
            // printf("processing node %d\n", fileData->vector[0] );
            newNode = buildNodeFromData( fileData );
            if ( newNode )
            {
                Graph_addOuterNode( newGraph, newNode );
                newNode->nodeCount = newGraph->totalNodes;
                newGraph->totalNodes += 1;
            }
        }
        IntVector_clear( fileData );
    }

    //printf ("Done with outer nodes\n");

    /* Parse the subsequent sections to get the inner nodes */
    while ( !feof( inFile ) )
    {
        /* The first line will identify the outer node for which the inner nodes are defined. */
        CharVector_getLineFromFile( fileString, inFile );

        if ( feof( inFile ) ) /* that fgets was the last line */
            break;

        systemCallSection = strncmp( "SYSTEM CALLS", fileString->string, 12) == 0;
        if ( systemCallSection )
            break;

        if ( isdigit( (int)fileString->string[0] ) )
            temp = atoi( fileString->string ); /* Note: No format error check here... */
        else
            temp = -1; /* Man, I hope -1 is never a node id value... */
        outerNode = Graph_findNode( newGraph, temp, false ); /* false -> only check outer nodes */

        if ( outerNode == NULL )
        {
            fprintf (stderr, "Error in parseFile: Node %d undefined as an outer node\n", temp );
            break; /* No error recovery  - but continue with the program */
        }

        /* Now, subsequent lines (up to the section break) identify interior nodes; */
        while  ( !feof( inFile ) )
        {
            CharVector_getLineFromFile( fileString, inFile );

            if ( strncmp( "----------", fileString->string, 10 ) == 0 ) /* we have a section break */
                break;

            count = IntVector_createFromString( fileData, fileString->string );
            if ( count > 0 )
            {
                /*
                 * special case: If the node specified is the outerNode, the edge nodes specified
                 * here are the entrance nodes
                 */
                if ( fileData->vector[0] == outerNode->id )
                    buildEntranceList( outerNode, fileData );
                else
                {
                    newNode = buildNodeFromData( fileData );
                    if ( newNode )
                    {
                        Node_addInteriorNode( outerNode, newNode );
                        newNode->nodeCount = newGraph->totalNodes;
                        newGraph->totalNodes += 1;
                    }
                }
            }
            IntVector_clear( fileData );
        }
    }

    //printf ( "Done with interior nodes. On to System Calls\n" );

    /* All the node mappings have been done, now we build a map of system calls to the
     * node keys.
     */
    newGraph->systemCallMap = SystemCallMap_new( funcCount );
    if ( newGraph->systemCallMap == NULL )
    {
        IntVector_delete( fileData );
        return( NULL ); /* if we can't build the system call map, we're done. */
    }

    if ( systemCallSection )
    {
        while ( !feof( inFile ) )
        {
            CharVector_getLineFromFile( fileString, inFile );
            
            if ( feof( inFile ) ) /* that fgets was the last line */
                break;

            if ( isdigit( (int)fileString->string[0] ) )
                temp = atoi ( fileString->string ); /* get the key */
            else
                temp = -1;
            if ( temp >= 0 ) /* valid key */
            {
                /* get the system call name. First, get past the ' ' */
                for ( i = 0; fileString->string[i] != '\0' && fileString->string[i] != ' '; ++i ) {}
                if ( fileString->string[i] == ' ' )
                {
                    ++i;
                    findNode = Graph_findNode( newGraph, temp, true );
                    pruneLine( fileString->string+i );
                    SystemCallMap_insert( newGraph->systemCallMap, fileString->string+i, findNode );
                }
            }
        }
    } /* ....aaaand we're done parsing the input file. */

    CharVector_delete(fileString);

    //printf ( "Done parsing, resolve edges\n" );
    /* Now that we have all the nodes, resolve all edge definitions */
    for ( outerNodeList = newGraph->outerNodes;
          outerNodeList != NULL;
          outerNodeList = outerNodeList->nextNode )
    {
        resolveNodeEdges( newGraph, outerNodeList->node, true ); /* true -> outer node */
        for ( innerNodeList = outerNodeList->node->interiorNodes;
              innerNodeList != NULL;
              innerNodeList = innerNodeList->nextNode )
        {
            resolveNodeEdges( newGraph, innerNodeList->node, false ); /* false -> interior node */
        }
    }


    /* How many nodes did we count (outer + interior)?
    printf ( "\tTotal nodes parsed: %d\n", newGraph->totalNodes ); */

    /* Debug --* /
    graphPrettyPrint( newGraph );
    systemCallMapPrettyPrint( newGraph->systemCallMap );
    / *-- End Debug */
    
    printf( "\t%d total System Call Map elements\n", newGraph->systemCallMap->contentSize );
    YAMLWriteInt( "System Calls", newGraph->systemCallMap->contentSize );

    /* Build the search diagram */
    newGraph->searchDiagram = SearchDiagram_build( newGraph->outerNodes, newGraph->totalNodes );

    printf ( "\t...parsing complete.\n" );
    return( newGraph );
}




/* parseSignature takes a space delimited string and turns it
 * into a "signature" - a packed array of c-string pointers with
 * a NULL pointer to signify completion.
 */
char **parseSignature( char *data )
{
    int i = 0;
    int labelCount = 0; // Used to be 1. The algorithm depends on a terminating space, so it counts based on the END of the label.
    int copiedLabels = 0;
    char **labels = NULL;
    char *debug = NULL;

    /* A little error checking */
    if ( !data )
        return NULL;

    /* First, scream through the array counting labels */
    for( i = 0; data[i] != '\0'; ++i )
    {
        if ( data[i] == ' ' )
        {
            ++labelCount;
            data[i] = '\0';
        }
    }

    /* Now, allocate the array and make copies */
    labels = (char **)malloc( (labelCount+1) * sizeof(char*) );
    i = 0;
    if ( labels )
    {
        for ( copiedLabels = 0; copiedLabels < labelCount; ++copiedLabels )
        {
            debug = &data[i];
            labels[copiedLabels] = strdup( &data[i] );
            while ( data[i] != '\0' )
            {
                /* advance to the end of this label */
                ++i;
            }
            ++i; /* advance beyond the \0 to the start of the next label */
        }
        labels[labelCount] = NULL; /* terminate the array */
    }

    /* Debug print out * /
    printf ( "\nSignature: ");
    for ( i = 0; labels[i] != NULL; ++i )
    {
        printf ( "%s ", labels[i] );
    }
    / * end Debug */

    return labels;
}





/* parseConfigFile reads the data file names and desired search
 * signatures from the config file. It returns a packed array
 * of Graph pointers populated corresponding to the data files.
 * Also, it returns a packed array of pointers to signatures.
 * (Signatures are themselves packed arrays to C-Strings.) These
 * packed arrays are terminated with a NULL pointer. They
 * are returned in the "graphs" and "signatures" parameters
 * which should be references to the desired pointers. See main.c.
 */
bool parseConfigFile( char *configFileName, Configuration *config )
{
    char data[1000];
    FILE *configFile = NULL;
    int fileNum = -1;
    int sigNum = -1;
    int i = 0;

    configFile = fopen( configFileName, "r" );
    if ( !configFile )
    {
        printf( "Could not open %s\n", configFileName );
        return( NULL );
    }
    else
        printf( "Opened %s\n\n", configFileName );

    fgets ( data, 1000, configFile );
    if ( feof( configFile ) || ( strncmp ( "Pathfinder Configuration", data, 24 ) != 0 ) )
    {
        printf( "Error in config file: doesn't start with \"Pathfinder Configuration\"\n" );
        return false;
    }

    fgets ( data, 1000, configFile );
    if ( feof( configFile ) || ( strncmp ( "files", data, 5 ) != 0 ) )
    {
        printf( "Error in config file: second line is not file count\n" );
        return false;
    }
    fileNum = atoi( &data[6] );
    if ( fileNum == 0 )
    {
        printf( "No files to parse, exiting.\n" );
        return false;
    }

    fgets ( data, 1000, configFile );
    if ( feof( configFile ) || ( strncmp ( "signatures", data, 10 ) != 0 ) )
    {
        printf( "Error in config file: third line is not signature count\n" );
        return false;
    }
    sigNum = atoi( &data[11] );
    if ( sigNum == 0 )
    {
        printf( "No signatures to search, exiting.\n" );
        return false;
    }

    fgets ( data, 1000, configFile );
    if ( feof( configFile ) || ( strncmp ( "search type", data, 11 ) != 0 ) )
    {
        printf( "Error in config file: third line is not signature count\n" );
        return false;
    }
    if ( strncmp( &data[12], "tree", 4 ) == 0 )
        config->searchOptions->searchType = treeSearch;
    else
        config->searchOptions->searchType = diagramSearch;

    config->graphs = (Graph **)malloc( (fileNum+1) * sizeof( Graph* ) );
    if ( !config->graphs )
    {
        printf ( "Could not allocate graph storage. Exiting\n" );
        return false;
    }

    for ( i = 0; i < fileNum; ++i )
    {
        fgets ( data, 1000, configFile );
        if ( feof( configFile ) || ( strncmp ( "file ", data, 5 ) != 0 ) ) /* note the ' ' */
        {
            printf( "Error in config file: mismatch of file count\n" );
            return false;
        }

        /* strip the \n from the file name. */
        pruneLine( &data[5] );
        config->graphs[i] = parseFile( &data[5] );
        if ( !config->graphs[i] )
        {
            /* the file did not parse */
            printf( "Error parsing %s", &data[5] );
            free( config->graphs );
            return false;
        }
    }
    config->graphs[fileNum] = NULL;

    config->signatures = (Signature *)malloc( (sigNum+1) * sizeof( Signature ) );
    if ( !config->signatures )
    {
        printf ( "Could not allocate signature storage. Exiting\n" );
        return false;
    }

    for ( i = 0; i < sigNum; ++i )
    {
        fgets ( data, 1000, configFile );
        if ( feof( configFile ) || ( strncmp ( "signature ", data, 10 ) != 0 ) ) /* note the ' ' */
        {
            printf( "Error in config file: mismatch of signature count\n" );
            return false;
        }

        /* strip the \n from the file name. */
        pruneLine( &data[10] );
        config->signatures[i] = parseSignature( &data[10] );
        if ( !config->signatures[i] )
        {
            /* the file did not parse */
            printf( "Error parsing %s", &data[10] );
            free( config->graphs ); /* Insufficient! Should call a destructor on each */
            free( config->signatures );
            return false;
        }
    }
    config->signatures[sigNum] = NULL;

    return true;
}



