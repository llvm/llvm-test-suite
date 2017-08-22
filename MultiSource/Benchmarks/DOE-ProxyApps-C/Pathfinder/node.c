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
 * node.c
 *
 *  Created on: Feb 1, 2013
 *      Author: Brian "Rig" Rigdon, Marcus Smith, Samuel Mulder
 */

/* --------
 * Nodes are the basic data structure within the graph. Nodes hold information
 * regarding their identity (id, label, type, etc.) and information about their
 * edges (list of edges, number of edges).
 *
 * Node.h/.c contains the data definitions for nodes and edges as well as con-
 * tainers for nodes (NodeList, NodePtrVec) and edges (EdgeList)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "graph.h"


/* -------------------------------------------
 * Node Method Definitions
 *
 */

/* "methods" for nodes */
/* Constructor */
Node *Node_new(int id, int nodeCount)
{
    Node *node = malloc(sizeof(Node));

    if ( !node )
        return(NULL);

    node->id = id;
    node->nodeCount = nodeCount; /* index into bitfield - caller must increment! */
    node->label = NULL;
    node->labelIdx = -1;
    node->type = exteriorNode;
    node->container = NULL;
    node->interiorNodes = NULL;
    node->edges = NULL;

    node->edgeCount = 0;
    node->entranceCount = 0;

    return(node);
}

/* Destructor */
void Node_delete(Node *trash)
{
    /* Some basic error checking */
    if ( !trash ) return;

    if ( trash->interiorNodes ) /* "true" tells clearNodeList to free the mallocs */
        NodeList_clear( trash->interiorNodes, true );

    if ( trash->edges )
        EdgeList_clear( trash->edges );

    free( trash );
}

/* Duplicates node data, BUT NO EDGE INFORMATION */
Node *Node_duplicate(Node *from, int newIndex)
{
    Node *copy = malloc(sizeof(Node));

    if ( !copy || !from )
        return(NULL);

    copy->id = from->id;
    copy->nodeCount = newIndex; /* index into bitfield - caller must increment! */
    copy->label = from->label;
    copy->labelIdx = from->labelIdx;
    copy->type = from->type;
    copy->container = NULL;
    copy->interiorNodes = NULL;
    copy->edges = NULL;

    copy->edgeCount = 0;
    copy->entranceCount = 0;

    return(copy);
}

/* Identifies the Upper-level node containing inner level node */
void Node_setParent(Node *this, Node *parent)
{
    /* Some basic error checking */
    if ( !this || !parent )
        return;

    this->container = parent;
    this->type = interiorNode;
}

/* Inserts interior node into parent list */
void Node_addInteriorNode(Node *this, Node *interior)
{
    /* some basic error checking */
    if ( !this || !interior )
        return;

    if ( this->interiorNodes == NULL )
    {
        this->interiorNodes = NodeList_new();
        if ( this->interiorNodes == NULL )
            return; /* malloc failed */
        this->interiorNodes->node = interior;
    }
    else
        NodeList_insertBack(this->interiorNodes, interior);

    Node_setParent(interior, this);
    return;
}


/* adds an edge from "this" to "node. If an allocation error occurs
 * this method returns false. If an edge already exists, the method
 * will NOT add a duplicate edge, and will return true.
 */
bool Node_addEdgeToNode(Node *this, Node *node)
{
    EdgeList *end = NULL;
    EdgeList *newEdge = NULL;

    if ( !this || !node )
        return(false);

    /* Scream through the list and make sure edge doesn't already exist */
    for ( end = this->edges; end != NULL; end = end->nextEdge )
        if ( end->targetNode == node )
            return true;

    /* Otherwise, we have a new edge. Insert it at the head of the list */
    newEdge = EdgeList_new();
    if ( !newEdge ) /* allocation error */
        return false;
    newEdge->targetNode = node;
    newEdge->targetNodeId = node->id;
    newEdge->nextEdge = this->edges; /* First time, this is NULL, terminates our list. */
    this->edges = newEdge;
    ++this->edgeCount;
    return(true);
}


/* -------------------------------------------
 * NodeList Method Definitions
 *
 */

/* Constructor */
NodeList * NodeList_new()
{
    NodeList *list = malloc(sizeof(NodeList));

    if ( !list )
        return(NULL);

    list->node = NULL;
    list->nextNode = NULL;

    return(list);
}

/* Destructor - also frees the data allocated for nodes if freeMemory is
 * true (calls their "destructor )
 */
void NodeList_clear(NodeList *trash, bool deleteNodes)
{
    /* Some basic error checking */
    if ( !trash ) return;

    if ( trash->nextNode )
        NodeList_clear(trash->nextNode, deleteNodes);

    if ( deleteNodes )
    {
        Node_delete(trash->node);
    }
    free(trash);
}

/* insertFront modifies the list passed in such that the first element
 * points to the new node. This is done by duplicating the first element
 * into a new element, and then modifying the true first element to point
 * to the node passed and and the created element (which references the
 * rest of the list).
 */
bool NodeList_insertFront(NodeList *this, Node *newFront)
{
    /* Make a new element that holds the information that used to
     * be at the front.
     */
    NodeList *oldFront = NodeList_new();

    /* Some basic error checking */
    if ( !this || !newFront || !oldFront )
        return(false);

    /* move the formerly front data to the new element */
    oldFront->node = this->node;
    oldFront->nextNode = this->nextNode; /* Now points to the remainder of the list (or NULL) */

    /* And change the head element to reference the new front node. */
    this->node = newFront;
    this->nextNode = oldFront;

    return(true);
}

/* Create a new node list element, have it reference the node passed in
 * and then put it in the back of the list. Returns true on success
 */
bool NodeList_insertBack(NodeList *this, Node *newBack)
{
    NodeList *end;
    NodeList *newElement;

    /* Some basic error checking */
    if ( !this || !newBack )
        return(false);

    /* If the node portion of "this" is null,
     * then we're starting with an empty list.
     */

    if ( this->node == NULL )
    {
        this->node = newBack;
        return(true); /* We're done! */
    }

    /* Otherwise, we need to find the end of the list */
    for ( end = this; end->nextNode != NULL; end = end->nextNode )
    { /* No-op */ }

    newElement = NodeList_new();
    if ( !newElement )
        return(false);

    newElement->node = newBack;
    end->nextNode = newElement; /* new nodelist element has a null next */

    return(true);
}





/* -------------------------------------------
 * Edge List Method Definitions
 *
 */

/* Constructor */
EdgeList *EdgeList_new()
{
    EdgeList *newNode = malloc( sizeof( struct EdgeListStruct ));
    if ( newNode )
    {
        newNode->targetNodeId = -1; /* Potentially a bug. what if there's a node named -1? */
        newNode->targetNode = NULL;
        newNode->nextEdge = NULL;
    }
    return(newNode);
}

/* Destructor */
void EdgeList_clear( EdgeList *this )
{
    /* Some basic error checking */
    if ( !this )
        return;

    if ( this->nextEdge )
        EdgeList_clear(this->nextEdge);

    free(this);
}

/* Insertion Method
 *     It is important to realize that this inserts the edge as an Id, it does
 *     not find or initialize the node specified by that Id. That has to be
 *     done as a separate step later.
 */
bool EdgeList_insertNodeId(EdgeList *this, int targetNodeId)
{
    EdgeList *end;
    EdgeList *newElement;

    /* some basic error checking */
    if ( !this )
        return(false);

    /* Check to see if this is the initial insertion into the
     * Edge list
     */
    if ( this->targetNodeId == -1 )
    {
        this->targetNodeId = targetNodeId;
        return(true);
    }

    /* Otherwise we find the end of the list and make a new entry */
    for ( end = this; end->nextEdge != NULL; end = end->nextEdge )
    { /* No-op */ }

    newElement = EdgeList_new();
    if ( !newElement )
        return(false);

    newElement->targetNodeId = targetNodeId;
    end->nextEdge = newElement; /* new edge list element has a null node and next */

    return(true);
}









/* Search Algorithms */
