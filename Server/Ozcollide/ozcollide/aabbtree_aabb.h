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

#ifndef OZCOLLIDE_AABBTREEAABB_H
#define OZCOLLIDE_AABBTREEAABB_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/aabbtree.h>
#include <ozcollide/vector.h>
#include <ozcollide/sphere.h>

ENTER_NAMESPACE_OZCOLLIDE

class DataIn;
class DataOut;

typedef void AABBCDAABB_callback(   const class AABBTreeAABB &,
                                    const Box &box,
                                    const Box &boundingBox,
                                    void *userCallback);

/**
 * Represents the leaf of an AABBTreeAABB
 */
class AABBTreeAABBLeaf : public AABBTreeNode {
public:
    AABBTreeAABBLeaf();

    int nbBoxes; /**< Number of boxes on the leaf.*/
    const Box *boxes; /**< List of boxes on that leaf.*/
    int users; /**< Potential user values on that leaf. User values are arbitrary values to hold personnal informations.*/
};

/**
 * The concrete implementation of an AABBTree that contains AABB.
 */
class AABBTreeAABB : public AABBTree {

    AABBTreeAABB(int leafDepth);
    ~AABBTreeAABB();

public:

    /**
     * Defines the result of a collision detection query with a Box.
     */
    class BoxColResult {
    public:
        Vector<const Box*> boxes_;
        Vector<int> users_;
        Box boxQuery_;
    };

    OZCOLLIDE_API static ERR loadBinary(const char *fileName, AABBTreeAABB **);
    OZCOLLIDE_API static ERR loadBinary(DataIn &, AABBTreeAABB **);

    OZCOLLIDE_API int getMemoryConsumption() const;

    //
    // BOX QUERY

    // Simply return a boolean. No caching and/or temporal coherence are used
    OZCOLLIDE_API bool isCollideWithBox(const Box &);

    // Simple return a boolean but use collision cache if temporal coherence is turned on.
    // The method tests collision with the first previous collided box ; if it still
    // collides the method return immediatly with TRUE
    OZCOLLIDE_API bool isCollideWithBox(const Box &, BoxColResult &);

    // Fill BoxColResult with the result of the collision.
    // If temporal coherence is turned on, the current content of BoxColResult is taken as a
    // collision cache. The method then returns immediatly if the box is inside 'boxQuery'
    // (which usually has been inflated to favorise collision cache)
    // That 'boxQuery' is updated by the method itself.
    OZCOLLIDE_API void collideWithBox(const Box &, BoxColResult &);

    // Perform a brute query and return result through a callback.
    // No caching and/or temporal coherence are used.
    // This method should be used only when memory usage is a concern.
    OZCOLLIDE_API void collideWithBox(const Box &, AABBCDAABB_callback *, void *userCallback = NULL);

    // Return the number of collided primitives since the last collision query
    OZCOLLIDE_API int getNbCollidedPrimitives() const;

    OZCOLLIDE_API ERR saveBinary(const char *filename);
    OZCOLLIDE_API ERR saveBinary(DataOut &);

    // Scale the entire tree (nodes + leafs)
    OZCOLLIDE_API void scale(float);

private:
    bool isCollideWithBox(const AABBTreeNode &);
    void collideWithBox(const AABBTreeNode &);

    void calculNbLeafs(const AABBTreeNode *, int &nb) const;

    void readPNTSchunk(DataIn &, int chunkSize);
    void readNODSchunk(DataIn &, int chunkSize, int nbNodes);
    void readLEFSchunk(DataIn &, int chunkSize, int nbLeafs);

    AABBTreeAABBLeaf *leafs_;

    AABBCDAABB_callback *callback_;
    void                *userCallback_;
    BoxColResult    	*colRes_;

    // Some primitives used internally for a reason or another...
    Box     box_;
    Vec3f   segment_pt0_;
    Vec3f   segment_pt1_;
    Sphere  sphere_;

    int							nbColls_;

    friend class AABBTree;
    friend class AABBTreeAABB_Builder;
};

LEAVE_NAMESPACE

#endif
