/*
OZCollide - Collision Detection Library
Copyright (C) 2006-2104 by Igor Kravtchenko

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

#ifndef OZCOLLIDE_AABBTREESPHERE_H
#define OZCOLLIDE_AABBTREESPHERE_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/aabbtree.h>
#include <ozcollide/sphere.h>
#include <ozcollide/frustum.h>

ENTER_NAMESPACE_OZCOLLIDE

class DataIn;
class DataOut;

typedef void AABBCDSphere_callback( const class AABBTreeSphere &,
                                    const Sphere &,
                                    int user,
                                    const Box &,
                                    void *userCallback);

/**
 * Represents the leaf of an AABBTreeSphere
 */
class AABBTreeSphereLeaf : public AABBTreeNode {
public:
    /**
     * Contructs an empty polygon leaf. Usually you don't have to invoke this constructor. It's made by the builder or the serializer.
     */
    AABBTreeSphereLeaf() : nbSpheres(0), spheres(NULL), users(NULL) { };

    int nbSpheres; /**< Number of spheres on the leaf.*/
    const Sphere *spheres; /**< List of spheres on that leaf.*/
    int *users; /**< Potential user values on that leaf. User values are arbitrary values to hold personnal informations.*/
};

/**
 * The concrete implementation of an AABBTree that contains spheres.
 */
class AABBTreeSphere : public AABBTree {

    AABBTreeSphere(int leafDepth);
    ~AABBTreeSphere();

public:

    OZCOLLIDE_API static ERR loadBinary(const char *filename, AABBTreeSphere **);
    OZCOLLIDE_API static ERR loadBinary(DataIn &, AABBTreeSphere **);

    OZCOLLIDE_API int getMemoryConsumption() const;

    // Collide with Box
    OZCOLLIDE_API bool isCollideWithBox(const Box &);
    OZCOLLIDE_API void collideWithBox(const Box &, AABBCDSphere_callback *, void *userCallback = NULL);

    // Collide with frustum
    OZCOLLIDE_API void collideWithFrustum(const Frustum &, AABBCDSphere_callback *, void *userCallback = NULL);

    // Return the number of collided primitives since the last call to collideWithxxx()
    OZCOLLIDE_API int getNbCollidedPrimitives() const;

    OZCOLLIDE_API ERR saveBinary(const char *filename);
    OZCOLLIDE_API ERR saveBinary(DataOut &);

    OZCOLLIDE_API void scale(float);

private:
    bool isCollideWithBox(const AABBTreeNode &);
    void collideWithBox(const AABBTreeNode &);

    void collideWithFrustum(const AABBTreeNode &);

    void calculNbLeafs(const AABBTreeNode *, int &nb) const;

    void readNODSchunk(DataIn &, int chunkSize, int nbNodes);
    void readLEFSchunk(DataIn &, int chunkSize, int nbLeafs);

    AABBTreeSphereLeaf  *leafs_;
    int                 nbPoints_;
    Vec3f               *points_;

    AABBCDSphere_callback   *callback_;
    void                    *userCallback_;

    // Some primitives used internally for a reason or another...
    Box     box_;
    Vec3f   segment_pt0_;
    Vec3f   segment_pt1_;
    Sphere  sphere_;
    Frustum frustum_;

    int nbColls_;

    friend class AABBTree;
    friend class AABBTreeSphere_Builder;
};

LEAVE_NAMESPACE

#endif
