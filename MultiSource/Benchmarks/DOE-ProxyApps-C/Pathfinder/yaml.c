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
 * yaml.h
 *
 *  Created on: Jun 21, 2013
 *      Author: J. Brian Rigdon
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "yaml.h"
static FILE *output = NULL;

/* This file doesn't yet do a true key/element pair clustering the way YAML is
 * intended to do. It is currently a minimalistic approach to output the most
 * important data from the run.
 */
 
/* In case configuration info isn't passed in... */
#ifndef CXXFLAGS
#define CXXFLAGS "unknown"
#endif
#ifndef CXXVERSION
#define CXXVERSION "unknown"
#endif




void YAMLOpen()
{
    time_t rawTime;
    struct tm *timeinfo = NULL;
    char *fileName = calloc(200, sizeof(char));
    char *timeStr = calloc(200, sizeof(char));
    
    
    time(&rawTime);
    timeinfo = localtime(&rawTime);

    if ( output != NULL || fileName==NULL || timeStr==NULL || timeinfo == NULL )
        return;

    sprintf(fileName, "PathFinder_%d-%d-%d_%d-%d-%d.yaml", timeinfo->tm_year+1900, timeinfo->tm_mon+1,
        timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    sprintf(timeStr, "%d/%d/%d, %d:%d:%d", timeinfo->tm_year+1900, timeinfo->tm_mon+1,
        timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    printf("\nWriting YAML: %s\n\n", fileName);

    /* static data - no need to free(timeinfo); */
    
    output = fopen(fileName, "w");
    if ( output != NULL )
    {
        YAMLWriteString("Mini-Application Name", "PathFinder");
        YAMLWriteString("Mini-Application Version", "1.0.0");
        YAMLWriteString("Run Date/Time", timeStr);
        YAMLWriteString("Compiler Version", CXXVERSION);
        YAMLWriteString("Compiler Flags", CXXFLAGS);
        
#ifdef MPI
        YAMLWriteString("MPI", "Yes");
#else
        YAMLWriteString("MPI", "No");
#endif
#ifdef OPENMP
        YAMLWriteString("OpenMP", "Yes");
        YAMLWriteString("Open MP Threads", getenv("OMP_NUM_THREADS"));
#else
        YAMLWriteString("OpenMP", "No");
#endif

    }
}

void YAMLClose()
{
    if ( output!=NULL )
        fclose(output);
}
 
void YAMLWriteString(char *tag, char *data)
{
    if ( output!=NULL )
        fprintf(output, "%s: %s\n", tag, data);
}

void YAMLWriteInt(char *tag, int data)
{
    if ( output!=NULL )
        fprintf(output, "%s: %i\n", tag, data);
}

void YAMLWriteDouble(char *tag, double data)
{
    if ( output!=NULL )
        fprintf(output, "%s: %lf\n", tag, data);
}

void YAMLWriteFloat(char *tag, float data)
{
    if ( output!=NULL )
        fprintf(output, "%s: %f\n", tag, data);
}