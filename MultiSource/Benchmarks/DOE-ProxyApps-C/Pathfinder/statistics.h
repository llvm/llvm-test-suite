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
 * statistics.h
 *
 *  Created on: Sept 24, 2013
 *      Author: Brian "Rig" Rigdon
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include "vectorUtils.h"

typedef struct HistogramElementStruct HistogramElement;
struct HistogramElementStruct
{
    int length;
    int count;
    struct HistogramElementStruct *next;
};

HistogramElement *HistogramElement_new(int length);

typedef struct StatsStruct Stats;
struct StatsStruct
{
    IntVector *pathLengths;
    int minLength;
    int maxLength;
    double averageLength; // does it make sense to say 2.7823 nodes long?
    double standardDeviation;
    int *histogram;
};

Stats *Stats_new();
void Stats_delete(Stats* stats);
bool Stats_logPath(Stats* stats, NodePtrVec* path);
void Stats_calculate(Stats* stats);

void testStats();

#endif // STATISTICS_H
