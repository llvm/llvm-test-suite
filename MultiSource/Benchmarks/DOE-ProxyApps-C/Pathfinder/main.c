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
 * main.c
 *
 *  Created on: Jan 9, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include "parsing.h"
#include "utils.h"
#include "searchAlgorithms.h"
#include "vectorUtils.h"
#include "statistics.h"
#include "configuration.h"
#include "yaml.h"

#ifdef QT
   #include "qThreadSearch.h"
#endif /* QT */

extern double currentTime();

#define helpString "\nUsage: PathFinder.exe [OPTIONS] [<fileName>]\n\n\
  Operation:\n\
    -c  <config file>   use configuration file\n\
    -i  <data file>     interactive search of specified data file\n\
    -x  <data file>     exhaustive leg search (any label to any label) of data file\n\n\
  Other:\n\
    -o  <output file>   save optimized graph to file\n\
    -h,u                prints this help message.\n\
    -q  <depth>         use qthread parallelism (config file only). The depth value\n\
                        specifies how deep in recursion to continue spawning new tasks\n\
                        during searches\n\
    -y                  create YAML output\n"

/* Forward declarations so that main is the first function we read */
void runBatch(char *configFile, Configuration *config);
void runInteractively(char *fileName, Configuration *config);
void exhaustiveLegSearch(char *fileName, Configuration *config);

int main(int argc, char *argv[])
{
    char defaultFile[] = "MicroTestData.adj_list";
    char *fileName = NULL;
    Configuration *config = Configuration_new();
    signed char c;
    int cFlag = 0; // Why did I make these ints instead of bool? JBR - 10/25/13
    int iFlag = 0;
    int xFlag = 0;
    int tFlag = 0;
    int dFlag = 0;
    int oFlag = 0;
    bool qFlag = 0;
    int qCount = 0;
    char commandLine[200];
    int i;

        printf ( "\n\n"
    "        PathFinder: finding a series of labeled nodes within a\n"
    "                two-layer directed, cyclic graph.\n"
    "               Copyright (2013) Sandia Corporation\n"
    "\n"
    " Sandia National Laboratories is a multi-program laboratory managed and\n"
    " operated by Sandia Corporation, a wholly owned subsidiary of Lockheed\n"
    " Martin Corporation, for the U.S. Department of Energy's National Nuclear\n"
    " Security Administration under terms of Contract DE-AC04-94AL85000,\n"
    " there is a non-exclusive license for use of this work by or on behalf\n"
    " of the U.S. Government. Export of this program may require a license \n"
    " from the United States Government.\n\n\n" );

    #ifdef DEBUG
        printf("\tRunning debug build\n\n");
    #endif
    #ifdef OPENMP
        printf("\tRunning Open MP build\n\n");
    #endif
    #ifdef QT
        printf("\tRunning Q Thread build\n\n");
    #endif
    
    if ( !config )
    {
        printf("Error: Could not allocation configuration structure.\n\n\t---Exiting\n\n");
        exit(0);
    }

    if ( argc < 2 )
    {
        exhaustiveLegSearch(defaultFile, config);
    }
    else
    {
        while ( (c = getopt(argc, argv, "c:i:x:o:q:huy")) != -1 )
        {
            switch (c)
            {
            case '?': /* we had a problem */
                if ( optopt == 'c' )
                    fprintf(stderr, "\tPlease specify configuration file.\n\n");
                else if ( optopt == 'i' || optopt == 'x' )
                    fprintf(stderr, "\tPlease specify data file.\n\n");
                else if ( optopt == 'o' )
                    fprintf(stderr, "\tPlease specify output graph data file.\n\n");
                else if ( optopt == 'q' )
                    fprintf(stderr, "\tPlease specify recursion depth to keep spawning tasks.\n\n");
                return(1);
                break; /* Superfluous, I know */
            case 'h':
            case 'u':
                printf ("\n%s\n\n", helpString);
                return(0); /* Nothing else matters */
                break; /* Superfluous, I know. */
            case 'c': /* configuration file */
                fileName = optarg;
                cFlag = 1;
                break;
            case 'i': /* interactive */
                fileName = optarg;
                iFlag = 1;
                break;
            case 'x': /* exhaustive leg search */
                fileName = optarg;
                xFlag = 1;
                break;
            case 'o': /* Save optimized paths in a new graph definition data file */
                config->searchOptions->outputFile = optarg;
                config->searchOptions->writeOutputFile = true;
                oFlag = 1;
                break;
            case 's':
                config->searchOptions->doStatistics = true;
                break;
            case 'q':
                qCount = atoi(optarg);
                if ( qCount < 1 ) 
                    qCount =  1;
                config->qThreadCount = qCount;
                break;
            case 'y':
                /* if ( commandLine != NULL ) */
                {
                    YAMLOpen();
                    commandLine[0] = '\0';
                    for ( i = 0; i < argc; ++i )
                        sprintf(commandLine, "%s %s", commandLine, argv[i] );
                    YAMLWriteString("Command", commandLine+1);
                }
                break;
            default :
                break;
            }
        }

        /* Debug --* /
        if (cFlag) printf ("cFlag ");
        if (iFlag) printf ("iFlag ");
        if (xFlag) printf ("xFlag ");
        if (oFlag) printf ("oFlag ");
        if (fileName) printf ( " - %s", fileName );
        if (outFile) printf ( " - %s", outFile);
        printf ("\n");
        / *-- End Debug */

        if ( (cFlag+iFlag+xFlag) > 1 )
        {
            fprintf(stderr, "-c -i and -x are mutually exclusive, PathFinder can only do one of those.\n\n");
            return(1);
        }

        if ( (cFlag+iFlag+xFlag) == 0 )
        {
            fprintf(stderr, "-c (config file) -i (interactive) or -x (exhaustive) must be specified.\n\n");
            return(1);
        }

        if ( oFlag && !xFlag )
        {
            fprintf(stderr, "-o (optimized graph output) is only compatible with -x (exhaustive searches).\n\n");
            return(1);
        }

        if ( cFlag )
            runBatch(fileName, config);
        else if ( iFlag )
            runInteractively(fileName, config);
        else
        {
            exhaustiveLegSearch(fileName, config);
        }
    }

    YAMLClose(); /* works even if YAML logging isn't present */
    return(0); /* zero means no error */
}

void runBatch(char *configFile, Configuration *config)
{
    bool success;
    int i;
    int j;
    double tick, tock;
    int hours;
    int min;
    double sec;
    
    if ( !configFile )
    {
        printf("Error: No config file entered.\n\n\t---Exiting---");
        exit(0);
    }

    // printf("config file: %s\n", configFile);

    tick = currentTime();
    success = parseConfigFile(configFile, config);
    tock = currentTime();
    sec = tock-tick;
    hours = (int)sec/3600;
    sec = fmod( sec, 3600.0 );
    min = (int)sec/60;
    sec = fmod(sec, 60.0);
    printf ("\n\nOverall Parse Time: %02d:%02d:%02.3f\n", hours, min, sec);

    /* Debug --* /
    for ( i = 0; config->signatures[i] != NULL; ++i );
    for ( j = 0; config->graphs[j] != NULL; ++j );
    printf( "%d files, %d signatures \n", j, i ); 
    exit(1);
    / *-- End Debug */

    if ( success )
    {
    #ifdef QT
        doMultiSearchesQT(config);
    #else
        doMultiSearches(config);
    #endif
    }

    printf ("\n\nSearches complete.\n");
}


void runInteractively(char *fileName, Configuration *config)
{
    char stringBuffer[200];
    Graph *graph;
    char *labels[25]; /* Do we need an interactive signature bigger than 25? */
    NodePtrVec *path = NULL;
    bool success = false;
    int i, j;
    int fullIntSignature[3] = { 0, 0, -1 };
    

    graph = parseFile(fileName);

    if ( !graph )
        return;

    while ( 1 )
    {
        i = 0;
        do {

            printf("\nPlease insert a node label for this signature (\"\" to complete, \"bail\" to exit):\n");
            gets(stringBuffer);

            if ( strcmp (stringBuffer, "bail") == 0 )
                exit(1);

            if ( strcmp(stringBuffer, "") != 0 )
            {
                labels[i] = strdup(stringBuffer);
                ++i;
            }

        } while ( i < 25 && strcmp(stringBuffer, "") != 0 );

        labels[i] = NULL;

        /* Debug */
        printf("\nSignature: ");
        for ( j = 0; j < i; ++j )
        {
            printf("'%s'", labels[j]);
            if ( j < i-1 )
                printf(" -> ");
            else
                printf("\n\n");
        }
        /* end debug */

        path = NodePtrVec_new(50);
        success = findLabelPath(graph, (Signature)labels, path, config->searchOptions->searchType);

        /* Sanity check to verify that a valid path exists */
        if( success )
        {
            /* printStack ( path ); */
            printf ("Found, resultant path has %d steps.\n", path->contentSize);
        }
        else
            printf("\n\tPath not found for signature.\n");

        NodePtrVec_delete(path);
    }

}

void exhaustiveLegSearch(char *fileName, Configuration *config)
{
    Graph *graph;
    int found;

    graph = parseFile(fileName);

    if ( !graph || !config )
        return;

    if ( config->searchOptions->outputFile == NULL )
        found = findAllPossibleLegs(graph, config->searchOptions->searchType);
    else
        found = findAndLogAllPossibleLegs(graph, config->searchOptions);
    printf("\n\nTotal %d legs found\n\n", found);
    Graph_delete(graph);
}
