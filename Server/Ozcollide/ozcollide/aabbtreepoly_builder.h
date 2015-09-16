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

#ifndef OZCOLLIDE_AABBTREEPOLY_BUILDER_H
#define OZCOLLIDE_AABBTREEPOLY_BUILDER_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/box.h>
#include <ozcollide/vector.h>

ENTER_NAMESPACE_OZCOLLIDE

class AABBTreePoly;
class AABBTreePolygonLeaf;
class MeshLayer;
class Monitor;
class Polygon;
class World;

/**
 * A helper to create an AABBTreePoly from a set of polygons.
 */
class AABBTreePolyBuilder {
public:

    /**
     * Creates an instance to build an AABBTreePoly.
     */
    OZCOLLIDE_API AABBTreePolyBuilder();

    /**
     * Destructs that instance.
     */
    OZCOLLIDE_API ~AABBTreePolyBuilder();

    /**
     * Constructs a AABBTreePoly from a set of polygons.
     * @param polys The set of polygons.
     * @param nbPolys Number of polygons.
     * @param points The set of points associated with the polygons
     * @param nbPoints The number of points pointed by points.
     * @param leafDepth Maximum number of polygons we can find on a leaf. Default value is 1 but usually a value of 4 is a good compromise (lesser leaves so smaller tree).
     * @param monitor If not NULL, it's used to monitor the progression of the build.
     * @return A ready to work AABBTreePoly instance.
     */
    OZCOLLIDE_API AABBTreePoly* buildFromPolys( const Polygon *polys,
                                                int nbPolys,
                                                const Vec3f *points,
                                                int nbPoints,
                                                int leafDepth = 1,
                                                Monitor * = NULL);

private:
    class WorkingItem {
    public:
        Box aabb;
        int left, right; // both to -1 whether it's a leaf
        Vector<Polygon*> pols;
    };

    void build(Monitor *);

    void workOnItem(WorkingItem &, int leafDepth);

    // Classify a polygon from an axis X, Y or Z
    // return: 0=negative 1=positive
    int classifyPol(const Polygon &, int axis, float middle, float &min, float &max);

    // Take the min/max value of a polygon on an axis (X, Y or Z)
    void takeMinMax(const Polygon &, int axis, float &min, float &max);

    // Calcul the average point's component on a given axis
    float calculAvgPoint(WorkingItem &, int axis);

    Vector<WorkingItem*> items_;
    AABBTreePoly *tree_;
};

LEAVE_NAMESPACE

#endif
