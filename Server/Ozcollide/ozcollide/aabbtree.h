/*
OZCollide - Collision Detection Library
Copyright (C) 2006-2014 by Igor Kravtchenko

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

Contact the author: igor@tsarevitch.org
*/

#ifndef OZCOLLIDE_AABBTREE_H
#define OZCOLLIDE_AABBTREE_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/box.h>

ENTER_NAMESPACE_OZCOLLIDE

class DataOut;
class StringTokenizer;
class Monitor;

/**
 * Defines a node if an AABB tree.
 */
class AABBTreeNode {
public:
    Box aabb; /**<The box that fully contains this node.*/
    const AABBTreeNode *left; /**<A pointer to left node if any. If this is NULL and there is also no right node, it's a leaf.*/
    const AABBTreeNode *right; /**<A pointer to right node if any. If this is NULL and there is also no left node, it's a leaf.*/
};

/**
 * @file aabbtree.h
 * Defines the kind of leaves we will encount in the AABB tree node.
 */
enum AABBTREE_LEAFTYPE {
	AABBTREE_LEAFTYPE_POLYGON, /**<Each leaf is a polygon.*/
	AABBTREE_LEAFTYPE_SPHERE, /**<Each leaf is a sphere.*/
	AABBTREE_LEAFTYPE_AABB, /**<Each leaf is an AABB.*/
};

/**
 * This is the base class of all implementations of AABB tree that is, the base of OZCollide.
 * Note about the memory's layout.
 * All nodes are placed in one big block. The start of this block is the address of the root's node.
 * All leafs are also placed in one big block.
 * In other words, there are two pointers, one for the nodes array and one for the leafs array.
 * That merely optimizes the memory's layout of the tree.
 * Note we build the tree by only providing memory pointers that could be a little confusing since a given memory pointer is not obviously in the correct memory block.
 * The problem could be minimised by using indices but that would slighty slow further read access.
 * Anyway the AABBs tree construction is not currently in charge of the client and blackboxed.
 * An AABB tree is not directly used, it's implemented via AABBTreeAABB, AABBTreePoly or AABBTreeSphere.
*/
class AABBTree {

    /**
     * Construsts an AABBTREE.
     * @param _type The kind of leaves we have on each leaf of the tree.
     * @param _leafDepth The maximum number of leaves we can encount on a leaf.
     */
    AABBTree(AABBTREE_LEAFTYPE _type, int _leafDepth);

    /**
     * Destructs this AABBTree instance.
     */
    virtual ~AABBTree();

public:

    /**
     * Saves the tree on the disk given a location.
     * @param filename Location of the filename
     * @return NOERR if everything ok.
     */
    virtual ERR saveBinary(const char *filename) = 0;
    
    /**
     * Saves the tree via a DataOut pipe.
     * @param _data The pipe instance.
     * @return NOERR if everything ok.
     */
    virtual ERR saveBinary(DataOut &_data) = 0;

    /**
     * Scale the tree by a given factor.
     * @param The scale factor.
     */
    virtual void scale(float) = 0;

    /**
     * Load a tree from the disk.
     * @param filename Location of the file on the disk.
     * @param tree A pointer to a pointer that will receive the loaded tree.
     * @return NOERR if everything ok.
     */
    OZCOLLIDE_API static ERR loadBinary(const char *filename, AABBTree **tree);

    /**
     * Destroy this tree instance.
     */
    OZCOLLIDE_API void destroy();

    /**
     * Returns the maximum number of primitives we can encount on a single leaf.
     * @return The maximum number of primitives we can encount on a single leaf.
     */
    ozinline int getLeafDepth() const { return leafDepth_; }

    /**
     * Gets the total number of nodes of that tree.
     * @return The total number of nodes.
     */
    ozinline int getNbNodes() const { return nbNodes_; }

    /**
     * Gets the total number of leaves of that tree.
     * @return The total number of leaves.
     */
    ozinline int getNbLeafs() const { return nbLeafs_; }

    /**
     * Returns the kind of leaf we encount on that tree.
     * @return the kind of leaf we encount on that tree.
     */
    ozinline AABBTREE_LEAFTYPE getLeafType() const { return leafType_; }

    /**
     * Tells if the tree has temporal cohnrence. Temporal coherence is a way to speed up collision detection when movements are not too important.
     * @return true if temporal coherence is turned on, false otherwhise.
     */
    ozinline bool hasTemporalCoherence() const { return bUseTemporalCoherence_; }

    /**
     * Active/unactive temporal coherence. It behaves differently depending of the query.
     * @param _b true to active temporal coherence, false otherwhise.
     */
    ozinline void setTemporalCoherence(bool _b) { bUseTemporalCoherence_ = _b; }

    /**
     * Gets the coefficient used to inflate the volume in a collision query when temporal coherence is turned on.
     * @return The coefficient.
     */
    ozinline float getCoefVolumeInflater() const { return coefVolInflater_; }

    /**
     * Sets the coefficient used to inflate the volume in a collision query when temporal coherence is turned on.
     * @param _f The coefficient.
     */
    ozinline void setCoefVolumeInflater(float _f) { coefVolInflater_ = _f; }

    /**
     * Gets the arbitraty value which define the type of the user data we can found on each leaf.
     * @return An arbitrary value.
     */
    ozinline int getTypeOfUserData() const { return userDataType_; }

    /**
     * Sets an arbitraty value which define the type of the user data we can found at each leaf.
     * @param type The arbitrary value.
     */
    ozinline void setTypeOfUserData(int type) { userDataType_ = type; }

    /**
     * Gets the root node of the tree.
     * @return The root node.
     */
    ozinline const AABBTreeNode* getRootNode() const { return root_; }

    /**
     * Get the memory consumption of the entire content of the tree in bytes.
     * @return The memory consumption in bytes.
     */
    virtual int getMemoryConsumption() const = 0;

protected:

    int             nbNodes_;
    AABBTreeNode    *root_;
    int             nbLeafs_;

    AABBTREE_LEAFTYPE   leafType_;
    int                 userDataType_;

    bool    bUseTemporalCoherence_;
    float   coefVolInflater_;

    int leafDepth_;

    friend class AABBTreePoly;
    friend class AABBTreeSphere;
    friend class AABBTreeAABB;
};

LEAVE_NAMESPACE

#endif
