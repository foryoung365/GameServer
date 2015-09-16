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

#ifndef OZCOLLIDE_POLYGON_H
#define OZCOLLIDE_POLYGON_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/vec3f.h>
#include <ozcollide/plane.h>

ENTER_NAMESPACE_OZCOLLIDE

/**
 * Defines a polygon (sometime called n-gons).
 * A polygon is merely a set of indices defining a set of points.
 * A polygon is, thus, always associated with a list of points.
 */
class Polygon {
public:
    
    /**
     * Creates a new empty polygon.
     */
    OZCOLLIDE_API Polygon();

    /**
     * Destructs this polygon instance.
     */
    OZCOLLIDE_API ~Polygon();

    /**
     * Set the number indices of this polygon.
     * Note that changing the number of indices doesn't erase the old content of the object.
     * For example passing from a triangle (3 indices) to a quadrangle (4 indices) keeps
     * the 3 first indices intact.
     * This methods make uses of malloc() and so, is slower than setIndicesMemory()
     */
    OZCOLLIDE_API void setNbIndices(int nbIndices);

    /**
     * Gets the number of indices used by this polygon.
     * A polygon of 1 index is a point, two indices is a line, three indices is a triangle, etc.
     * Maximum number of indices is 255.
     */
    ozinline int getNbIndices() const { return nbIndices_ & 0xff; }

    /**
     * Force this polygon to use the supplied memory location for its indices.
     * That's allow for example a big block of memory to be chunked into several set of indices
     * without the heavy mechanism of new memory allocation for each newly created polygon.
     * @param _nbIndices The number of indices of this polygon.
     * @param _indices A pointer to the indices, no recopy is made, the pointer will just be further used.
     */
    ozinline void setIndicesMemory(int _nbIndices, int *_indices)
    {
        nbIndices_ = _nbIndices | 0x100;
        indices_ = _indices;
    }

    /**
     * Gets a point index for this polygon.
     * @return The point index.
     */
    ozinline int getIndex(int i) const { return indices_[i]; }
    
    /**
     * Sets a point index for this polygon.
     * @param i The index inside the polygon.
     * @param index The point index.
     */
    ozinline void setIndex(int i, int index) { indices_[i] = index; }

	// Get/Set the normal of the polygon
    /**
     * Returns the normal of this polygon.
     * For performance reason, the normal is precalculated.
     * @return The normal of the polygon.
     */
    ozinline const Vec3f& getNormal() const { return normal_; }

    /**
     * Sets the normal for this polygon.
     * @param normal The normal of the polygon.
     */
    ozinline void setNormal(const Vec3f &normal) { normal_ = normal; }

    /**
     * Tells if this polygon is degenerated.
     * A degenerated polygon is a polygon where two or more points are the same.
     * @return true if the polygon is degenerated, false otherwhise.
     */
    OZCOLLIDE_API bool isDegenerate() const;

    /**
     * Copies this polygon (nbIndices, indices and normal) to one another polygon.
     * It causes its content to be erased by this one.
     * @param polygon The Polygon where the copy will occur.
     */
    OZCOLLIDE_API void copyTo(Polygon &) const;

    /**
     * Clones the polygon.
     * @return A pointer to a cloned polygon.
     */
    OZCOLLIDE_API Polygon* clone() const;

    /**
     * Calculates a Plane instance for this polygon
     * @param _pnts A list of points to read from (which is associated with the polygon indices).
     * @return A Plane instance for this polygon.
     */
    ozinline Plane calculPlane(const Vec3f *_pnts) const
    {
        Plane plane;
        plane.fromPointAndNormal(_pnts[indices_[0]], normal_);
        return plane;
    }

private:
    int     nbIndices_;
    int     *indices_;
    Vec3f   normal_;
};

LEAVE_NAMESPACE

#endif
