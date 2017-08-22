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
 * node.h
 *
 *  Created on: Feb 1, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

#ifndef NODE_H_
#define NODE_H_




/* --------
 * Nodes are the basic data structure within the graph. Nodes hold information
 * regarding their identity (id, label, type, etc.) and information about their
 * edges (list of edges, number of edges).
 *
 * Node.h/.c contains the data definitions for nodes and edges as well as con-
 * tainers for nodes (NodeList, NodePtrVec) and edges (EdgeList)
 */




typedef enum
{
    exteriorNode, /* Default unless Node_setParent is called */
    interiorNode,
    entranceNode  /* special interior node(s) that begin the interior graph */
} NodeType;


/* -------------------------------------------
 * Node Definitions
 *
 */



typedef struct NodeStruct Node;
typedef struct NodeListStruct NodeList;
typedef struct EdgeListStruct EdgeList;

#include "bitfield.h"
#include "vectorUtils.h"
#include <stdbool.h>

struct NodeStruct
{
    int id; /* id value for the node - typically associated with an address of the basic block */
    int nodeCount; /* a unique index for this node (0 .. whatever) */
    char *label;
    int labelIdx;
    NodeType type;
    Node *container; /* if this is an interior node, this points to the outer node containing this one */
    NodeList *interiorNodes; /* All the nodes contained in this node's subgraph */
    EdgeList *edges; /* Nodes that can be accessed from this node (includes entrance nodes) */

    int edgeCount; /* edges from this node to others (DOES NOT INLCUDE INTRANCE NODES) */
    int entranceCount; /* number of entrance nodes (if any) */
};

/* "methods" for nodes */

Node *Node_new( int id, int nodeCount );    /* Constructor */
void Node_delete( Node *trash ); /* Destructor */
Node *Node_duplicate(Node *from, int newIndex); /* Duplicates node data, BUT NO EDGE INFORMATION */
void Node_setParent( Node *this, Node *parent );  /* Identifies the Upper-level node containing inner level node */
void Node_addInteriorNode( Node *this, Node *interior ); /* Inserts interior node into parent list */
bool Node_addEdgeToNode(Node *this, Node *node); /* Node* based insertion method */


/* -------------------------------------------
 * Node List Definitions
 *
 */

struct NodeListStruct
{
    Node *node;
    NodeList *nextNode;
};

/* "methods" for NodeLists */

NodeList *NodeList_new(); /* Constructor */

/* Destructor - also frees the data allocated for nodes if freeMemory is
 * true (calls their "destructor )
 */
void NodeList_clear( NodeList *trash, bool deleteNodes );

/* insertFront modifies the list passed in such that the first element
 * points to the new node. This is done by duplicating the first element
 * into a new element, and then modifying the true first element to point
 * to the node passed and and the created element (which references the
 * rest of the list).
 */
bool NodeList_insertFront( NodeList *this, Node *newFront );
/* Create a new node list element, have it reference the node passed in
 * and then put it in the back of the list. Returns true on success
 */
bool NodeList_insertBack( NodeList *this, Node *newBack );

/* -------------------------------------------
 * Edge List Definitions
 *
 *     Edges are processed a little differently than nodes. As soon as a
 *     node is identified, it is created. However, the edges may be
 *     identified prior to the creation of the node to which it references.
 *     Ergo, there's a two pass process - first identifying the edges,
 *     then subsequently setting the pointers to reference them.
 *
 *     Rather than making a dual structure "Edge" and "EdgeList" pair,
 *     the author is combining the data into a single structure.
 */

struct EdgeListStruct
{
    int targetNodeId;
    Node *targetNode;
    EdgeList *nextEdge;
};

EdgeList *EdgeList_new(); /* Constructor */
void EdgeList_clear(EdgeList* this); /* Destructor */
bool EdgeList_insertNodeId(EdgeList *this, int targetNodeId); /* Id based insertion method */

#endif /* NODE_H_ */
