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
 * utils.h
 *
 *  Created on: Jan 10, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "graph.h"
#include "systemCallMap.h"
#include "searchDiagram.h"
void edgeListPrettyPrint( EdgeList *edges, int depth, char *header );
void nodeListPrettyPrint( NodeList *nodes, int depth, char *separator, bool multiLine );
void graphPrettyPrint( Graph *graph );
void systemCallMapPrettyPrint( SystemCallMap *map );
void printStack ( NodePtrVec *stack );
bool testGraph();
void testStack();

void searchDiagramPrettyPrint ( SearchDiagram *diagram );

#endif /* UTILS_H_ */
