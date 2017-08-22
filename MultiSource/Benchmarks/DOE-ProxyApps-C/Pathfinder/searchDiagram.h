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
 * searchDiagram.h
 *
 *  Created on: Feb 1, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#ifndef SEARCHDIAGRAM_H_
#define SEARCHDIAGRAM_H_

#include "node.h"

typedef struct SearchDiagramStruct SearchDiagram;
typedef struct EdgeReferencesStruct EdgeReferences;

struct SearchDiagramStruct
{
    Node *node;  /* a reference to the node */
    EdgeReferences *edgeReferenceArray; /* All the nodes reachable from here */
};

/* We are creating arrays of SearchDiagram - constructor/destructor would be superfluous */


/* The EdgeSearchStruct holds a different representation of
 * the tree through which we're searching. Our search diagram
 * will create an array of these for each node in the graph.
 * Searches will go through the array, looking to match the
 * search criteria. If the search is unsuccessful, it will
 * then search the edges of the node. In this array, the  first
 * element is the SEARCH ELEMENT we're comparing against. In
 * this iteration of the code, we're using the Node pointer
 * as the search key. The second element is the search edges
 * contained by that node. The search edges are referenced
 * directly, no need to go back to the SearchDiagram instance
 * to get to the edges.
 */

struct EdgeReferencesStruct
{
    Node *edgeTarget; /* The address of the node is how we're defining our search */
    EdgeReferences *targetNodeEdges; /* pointer to the "to" node's edge references */
};

/* We are creating arrays of EdgeReferences - constructor/destructor would be superfluous */

/* Scream through the diagram to get the element corresponding to this Node* */
SearchDiagram *SearchDiagram_findNode ( SearchDiagram *diagram, Node *node );

/* The meat of this process - the function that creates the search diagram.
 * It allocates the memory for the array of search diagram elements and
 * populates them with node data and edgeID arrays.
 */
SearchDiagram *SearchDiagram_build ( NodeList *nodeTree, int nodeCount );


/* And, our search methods. The first calls the second, which is recursive */

bool SearchDiagram_findSignatureAlongEdges ( Node *node, EdgeReferences *edges,
                                             char *labels[], NodePtrVec *result, Bitfield *visited );



#endif /* SEARCHDIAGRAM_H_ */
