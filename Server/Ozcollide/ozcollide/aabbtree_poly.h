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

#ifndef OZCOLLIDE_AABBTREEPOLY_H
#define OZCOLLIDE_AABBTREEPOLY_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/aabbtree.h>
#include <ozcollide/polygon.h>
#include <ozcollide/vector.h>
#include <ozcollide/obb.h>
#include <ozcollide/sphere.h>
#include <ozcollide/ellipsoid.h>

ENTER_NAMESPACE_OZCOLLIDE

class DataIn;

typedef void AABBCDPoly_callback(   const class AABBTreePoly &,
                                    const Polygon &,
                                    int user,
                                    const Box &,
                                    void *userCallback);

/**
 * Represents the leaf of an AABBTreePolygon
 */
class AABBTreePolygonLeaf : public AABBTreeNode {
public:
    /**
     * Contructs an empty polygon leaf. Usually you don't have to invoke this constructor. It's made by the builder or the serializer.
     */
    AABBTreePolygonLeaf() : nbPolys (0), polys (NULL), users (NULL) { };

    int nbPolys; /**< Number of polygons on the leaf.*/
    const Polygon *polys; /**< List of polygons on that leaf.*/
    int *users; /**< Potential user values on that leaf. User values are arbitrary values to hold personnal informations.*/
};

/**
 * The concrete implementation of an AABBTree that contains polygons.
 */
class AABBTreePoly : public AABBTree {
    
    AABBTreePoly(int leafDepth);
    ~AABBTreePoly();

public:

    /**
     * Defines the result of a collision detection query with a Box.
     */
    class BoxColResult {
    public:
        Vector<const Polygon *> polys_;
        Vector<int> users_;
        Box boxQuery_;
    };

    /**
     * Defines the result of a collision detection query with an OBB.
     */
    class OBBColResult {
    public:
        Vector<const Polygon *> polys_;
        Vector<int> users_;
        OBB obbQuery_;
    };

    /**
     * Defines the result of a collision detection query with an Sphere.
     */
    class SphereColResult {
    public:
        Vector<const Polygon *> polys_;
        Vector<int> users_;
        Sphere sphereQuery_;
    };

    /**
     * Defines the result of a collision detection query with an Ellipsoid.
     */
    class EllipsoidColResult {
    public:
        Vector<const Polygon *> polys_;
        Vector<int> users_;
        Ellipsoid ellipsoidQuery_;
    };

    /**
     * Defines the result of a collision detection query with a segment.
     */
    class SegmentColResult {
    public:
        Vector<const Polygon *> polys_;
        Vector<int> users_;
        Vec3f segmentPt0_;
        Vec3f segmentPt1_;
    };

    OZCOLLIDE_API static ERR loadBinary(const char *filename, AABBTreePoly **);
    OZCOLLIDE_API static ERR loadBinary(DataIn &, AABBTreePoly **);

    OZCOLLIDE_API ERR saveBinary(const char *filename);
    OZCOLLIDE_API ERR saveBinary(DataOut &data);

    OZCOLLIDE_API int getMemoryConsumption() const;

    OZCOLLIDE_API int getNbPoints() const;
    OZCOLLIDE_API const Vec3f* getPointsList() const;

    //
    // BOX QUERY
    OZCOLLIDE_API bool isCollideWithBox(const Box &);
    OZCOLLIDE_API bool isCollideWithBox(const Box &, BoxColResult &);
    OZCOLLIDE_API void collideWithBox(const Box &, AABBCDPoly_callback *, void *userCallback = NULL);
    OZCOLLIDE_API void collideWithBox(const Box &, BoxColResult &);

    //
    // SPHERE QUERY
    OZCOLLIDE_API bool isCollideWithSphere(const Sphere &);
    OZCOLLIDE_API void collideWithSphere(const Sphere &, AABBCDPoly_callback *, void *userCallback = NULL);
    OZCOLLIDE_API void collideWithSphere(const Sphere &, SphereColResult &);

    //
    // ELLIPSOID QUERY
    OZCOLLIDE_API bool isCollideWithEllipsoid(const Ellipsoid &);
    OZCOLLIDE_API void collideWithEllipsoid(const Ellipsoid &, AABBCDPoly_callback *, void *userCallback = NULL);
    OZCOLLIDE_API void collideWithEllipsoid(const Ellipsoid &, EllipsoidColResult &);

    //
    // SEGMENT QUERY
    OZCOLLIDE_API bool isCollideWithSegment(const Vec3f &seg_pt0, const Vec3f &seg_pt1);
    OZCOLLIDE_API bool isCollideWithSegment(const Vec3f &seg_pt0, const Vec3f &seg_pt1, SegmentColResult &);
    OZCOLLIDE_API void collideWithSegment(const Vec3f &seg_pt0, const Vec3f &seg_pt1, AABBCDPoly_callback *, void *userCallback = NULL);
    OZCOLLIDE_API void collideWithSegment(const Vec3f &seg_pt0, const Vec3f &seg_pt1, SegmentColResult &);

    //
    // OBB QUERY
    OZCOLLIDE_API bool isCollideWithOBB(const OBB &);
    OZCOLLIDE_API bool isCollideWithOBB(const OBB &, OBBColResult &);
    OZCOLLIDE_API void collideWithOBB(const OBB &, AABBCDPoly_callback *, void *userCallback = NULL);
    OZCOLLIDE_API void collideWithOBB(const OBB &, OBBColResult &);

    // Return the number of collided primitives since the last call to collideWithxxx()
    OZCOLLIDE_API int getNbCollidedPrimitives() const;

    OZCOLLIDE_API void scale(float);

private:
    // bunch of internal recursive methods
    bool isCollideWithBox(const AABBTreeNode &);
    void collideWithBox(const AABBTreeNode &);

    bool isCollideWithSphere(const AABBTreeNode &);
    void collideWithSphere(const AABBTreeNode &);

    bool isCollideWithEllipsoid(const AABBTreeNode &);
    void collideWithEllipsoid(const AABBTreeNode &);

    bool isCollideWithSegment(const AABBTreeNode &);
    void collideWithSegment(const AABBTreeNode &);

    bool isCollideWithOBB(const AABBTreeNode &);
    void collideWithOBB(const AABBTreeNode &);

    void calculNbLeafs(const AABBTreeNode *, int &nb) const;

    void readPNTSchunk(DataIn &, int chunkSize);
    void readNODSchunk(DataIn &, int chunkSize, int nbNodes);
    void readLEFSchunk(DataIn &, int chunkSize, int nbLeafs);

    // Calcul polygon's normal
    void final();

    AABBTreePolygonLeaf *leafs_;
    int                  nbPoints_;
    Vec3f                *points_;

    AABBCDPoly_callback *callback_;
    void                *userCallback_;

    BoxColResult        *boxColRes_;
    OBBColResult        *obbColRes_;
    SphereColResult     *sphereColRes_;
    EllipsoidColResult  *ellipColRes_;
    SegmentColResult    *segmentColRes_;

    // Some primitives used internally for a reason or another...
    Box         box_;
    Vec3f       seg_pt0_, seg_pt1_;
    Sphere      sphere_;
    Ellipsoid   ellip_;
    OBB         obb_;

    int nbColls_;

    // one shot buffer for allocation (faster loading)
    int     *bufEdges_;
    int     offBufEdges_;
    Polygon *bufPols_;
    int     offBufPols_;

    friend class AABBTree;
    friend class AABBTreePolyBuilder;
};

LEAVE_NAMESPACE

#endif
