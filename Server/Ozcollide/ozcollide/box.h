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

#ifndef OZCOLLIDE_BOX_H
#define OZCOLLIDE_BOX_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/plane.h>
#include <ozcollide/vec3f.h>

ENTER_NAMESPACE_OZCOLLIDE

/**
 * @brief Defines the edge of a box.
 */
class BoxEdge {
public:
    /**
     * Constructs a box edge giving two points.
     * @param a The first point of the box edge.
     * @param b The second point of the box edge.
     */
    BoxEdge(const Vec3f &a, const Vec3f &b) : p0(a) , p1(b) { };

    /**The first point defining the box edge.*/
    Vec3f p0;

    /**The second point defining the box edge.*/
    Vec3f p1;
};

/**
 * Defines an AABB (Axis Aligned Bounding Box). An AABB is an Axis Aligned Bounding Box, in the opposite of an OBB that is oriented (Oriented Bounding Box).
 * Typicaly you just have one size for each axis.
 */
class Box {
public:

    /**
     * Constructs an uninitalized box.
     */
    ozinline Box()
    {
    }

    /**
     * Constructs an initalized box.
     * @param _center The center of the box.
     * @param _extent The extent of the box for each axis.
     */
    ozinline Box(const Vec3f &_center, const Vec3f &_extent) : center(_center), extent(_extent)
    {
    }

     /**
      * Destructs this box instance.
      */
    ~Box()
    {
    }

    /**
     * Build an AABB from two points.
     * @param _pt0 The first point.
     * @param _pt1 The second point.
     */
    ozinline void setFromPoints(const Vec3f &_pt0, const Vec3f &_pt1)
    {
        center = (_pt1 + _pt0) * 0.5f;
	extent = (_pt1 - _pt0) * 0.5f;
	extent.positive();
    }

    /**
     * Gets the minimum corner of this box.
     * @return The minimum corner box.
     */
    ozinline Vec3f getMin() const
    {
        return center - extent;
    }

    /**
     * Gets the maximum corner of this box.
     * @return The maximum corner box.
     */
    ozinline Vec3f getMax() const
    {
        return center + extent;
    }

    /**
     * Gets the minimal and maximal point of this box.
     * @param _min Will contain th minimal point of this box.
     * @param _max Will contain th maximal point of this box.
     */
    ozinline void getMinMax(Vec3f &_min, Vec3f &_max) const
    {
        _min = center - extent;
        _max = center + extent;
    }

    /**
     * Tests if that box overlaps with one another
     * @param _box The other box to test with.
     * @return true if this box overlaps with _box, false otherwhise.
     */
    ozinline bool isOverlap(const Box &_box) const
    {
        if (isOverlapOnX(_box) &&
            isOverlapOnY(_box) &&
            isOverlapOnZ(_box))
                return true;

        return false;
    }

    /**
     * Same than is isOverlap() method but only occurs on X axis.
     * @param _box The other box to test with.
     * @return true if this box overlaps with _box, false otherwhise.
     */
    ozinline bool isOverlapOnX(const Box &_box) const
    {
        float t = _box.center.x - center.x;
        if (t < 0) t = -t;

        float ext = _box.extent.x + extent.x;
        if (t <= ext)
            return true;

        return false;
    }

    /**
     * Same than is isOverlap() method but only occurs on Y axis.
     * @param _box The other box to test with.
     * @return true if this box overlaps with _box, false otherwhise.
     */
    ozinline bool isOverlapOnY(const Box &_box) const
    {
        float t = _box.center.y - center.y;
        if (t < 0) t = -t;

        float ext = _box.extent.y + extent.y;
            if (t <= ext)
                return true;

        return false;
    }

    /**
     * Same than is isOverlap() method but only occurs on Z axis.
     * @param _box The other box to test with.
     * @return true if this box overlaps with _box, false otherwhise.
     */
    ozinline bool isOverlapOnZ(const Box &_box) const
    {
        float t = _box.center.z - center.z;
	if (t < 0) t = -t;

        float ext = _box.extent.z + extent.z;
        if (t <= ext)
            return true;

        return false;
    }

    /**
     * Tests if one box is fully inside one another.
     * @param _box The box to test with.
     * @return true if _box is fully inside this box, false otherwhise.
     */
    ozinline bool isInside(const Box &_box) const
    {
        if (center.x - extent.x > _box.center.x - _box.extent.x &&
            center.x + extent.x < _box.center.x + _box.extent.x &&
            center.y - extent.y > _box.center.y - _box.extent.y &&
            center.y + extent.y < _box.center.y + _box.extent.y &&
            center.z - extent.z > _box.center.z - _box.extent.z &&
            center.z + extent.z < _box.center.z + _box.extent.z)
            return true;
		
            return false;
    }

    /**
     * Tests if  point is inside this box.
     * @param _pt The point to test.
     * @return true if the point is inside this this box, false otherwhise.
     */
    ozinline bool isInside(const Vec3f &_pt) const
    {
        Vec3f min = getMin();
        Vec3f max = getMax();

        if (_pt.x < min.x || _pt.x > max.x ||
            _pt.y < min.y || _pt.y > max.y ||
            _pt.z < min.z || _pt.z > max.z)
                return false;

        return true;
    }

    /**
     * Gets the smallest extension of that box. It means the axis that has the smallest amplitude on X, Y, or Z.
     * @return The smallest extension, it can be the X, Y, or Z axis.
     */
    ozinline float getMinExtent() const
    {
        if (extent.x < extent.y && extent.x < extent.z)
            return extent.x;
        if (extent.y < extent.z)
            return extent.y;
        return extent.z;
    }

    /**
     * Gets the highest extension of that box. It means the axis that has the highest amplitude on X, Y, or Z.
     * @return The highest extension, it can be the X, Y, or Z axis.
     */
    ozinline float getMaxExtent() const
    {
        if (extent.x > extent.y && extent.x > extent.z)
            return extent.x;
        if (extent.y > extent.z)
            return extent.y;

        return extent.z;
    }

    /**
     * Returns the extension of the box on X, Y or Z axis.
     * @param i The index of the axis. 0 for X, 1 for Y, 2 for Z. If index are not in the valid range [0, 2], Z extension is returned by default.
     * @return The extension of the asked axis.
     */
    ozinline float ext(int i) const
    {
        if (i == 0) return extent.x;
        else if (i == 1) return extent.y;
        return extent.z;
    }

    /**
     * Returns a point of the cube.
     * A cube is made of 8 points. This method allow you to return the required point.
     * @param _index The index of the point from 0 to 7. If _index is not in the valid range, 0 is returned.
     * @return The point.
     */
    ozinline Vec3f getPoint(int _index) const
    {
        switch(_index) {
            case 0: return Vec3f(center.x - extent.x, center.y - extent.y, center.z - extent.z);
            case 1: return Vec3f(center.x + extent.x, center.y - extent.y, center.z - extent.z);
            case 2: return Vec3f(center.x - extent.x, center.y + extent.y, center.z - extent.z);
            case 3: return Vec3f(center.x + extent.x, center.y + extent.y, center.z - extent.z);
            case 4: return Vec3f(center.x - extent.x, center.y - extent.y, center.z + extent.z);
            case 5: return Vec3f(center.x + extent.x, center.y - extent.y, center.z + extent.z);
            case 6: return Vec3f(center.x - extent.x, center.y + extent.y, center.z + extent.z);
            case 7: return Vec3f(center.x + extent.x, center.y + extent.y, center.z + extent.z);
            default: return ZEROVEC3F;
        }
    }

    /**
     * Gets the normal of the cube given its point index.
     * A box is made of 8 points. This method allows you to get the normal of each of these points.
     * @param _index The index of the vertex to get the normal from (from 0 to 7). If the index is not in the valid range, 0 vector is returned.
     * @return The normal of the vertex. The normal is normalized.
     */
    ozinline static Vec3f getVertexNormal(int _index)
    {
        switch(_index) {
            case 0: return Vec3f(-OZ_INVQSQR3, -OZ_INVQSQR3, -OZ_INVQSQR3);
            case 1: return Vec3f(+OZ_INVQSQR3, -OZ_INVQSQR3, -OZ_INVQSQR3);
            case 2: return Vec3f(-OZ_INVQSQR3, +OZ_INVQSQR3, -OZ_INVQSQR3);
            case 3: return Vec3f(+OZ_INVQSQR3, +OZ_INVQSQR3, -OZ_INVQSQR3);
            case 4: return Vec3f(-OZ_INVQSQR3, -OZ_INVQSQR3, +OZ_INVQSQR3);
            case 5: return Vec3f(+OZ_INVQSQR3, -OZ_INVQSQR3, +OZ_INVQSQR3);
            case 6: return Vec3f(-OZ_INVQSQR3, +OZ_INVQSQR3, +OZ_INVQSQR3);
            case 7: return Vec3f(+OZ_INVQSQR3, +OZ_INVQSQR3, +OZ_INVQSQR3);
            default: return ZEROVEC3F;
        }
    }

    /**
     * Returns a face normal of the cube.
     * A box is made of 6 faces. This method allows you to get the normal of each of these faces.
     * @param _which The index of the vertex to get the normal from (from 0 to 5). If the index is not in the valid range, 0 is returned.
     * @return The normal of the face. The normal is normalized.
     */
    ozinline static Vec3f getFaceNormal(PLANE _which)
    {
        switch(_which) {
            case 0: return Vec3f(-1,  0,  0);
            case 1: return Vec3f( 1,  0,  0);
            case 2: return Vec3f( 0, -1,  0);
            case 3: return Vec3f( 0,  1,  0);
            case 4: return Vec3f( 0,  0, -1);
            case 5: return Vec3f( 0,  0,  1);
            default: return ZEROVEC3F;
        }
    }

    /**
     * Gets the plane of one face of the cube.
     * A box is made of 6 faces. This method allows you to get a Plane instance of each of these faces.
     * @param _which The index of the face to get the plane from (from 0 to 5). If the index is not in the valid range, a 0 plane is returned.
     * @return The plane of the face. The plane is normalized.
     */
    ozinline Plane getPlane(PLANE _which) const
    {
        Plane plane;
        switch(_which) {
            case 0: plane.fromPointAndNormal(Vec3f(center.x - extent.x, 0, 0), getFaceNormal(_which));
            case 1: plane.fromPointAndNormal(Vec3f(center.x + extent.x, 0, 0), getFaceNormal(_which));
            case 2: plane.fromPointAndNormal(Vec3f(0, center.y - extent.y, 0), getFaceNormal(_which));
            case 3: plane.fromPointAndNormal(Vec3f(0, center.y + extent.y, 0), getFaceNormal(_which));
            case 4: plane.fromPointAndNormal(Vec3f(0, 0, center.z - extent.z), getFaceNormal(_which));
            case 5: plane.fromPointAndNormal(Vec3f(0, 0, center.z + extent.z), getFaceNormal(_which));
            default: plane = Plane(0, 0, 0, 0);
        }
	return plane;
    }

    /**
     * Returns an edge of the cube given its index.
     * A box is made of many edges (12 in total). This method allows you to get an edge of the box.
     * @param _index The index of the edge (from 0 to 11). If the index is not in the valid range, a 0 BoxEdge is returned.
     * @return An instance of BoxEdge.
     */
    ozinline BoxEdge getEdge(int _index) const
    {
        float x0 = center.x - extent.x;
        float y0 = center.y - extent.y;
        float z0 = center.z - extent.z;
        float x1 = center.x + extent.x;
        float y1 = center.y + extent.y;
        float z1 = center.z + extent.z;

        switch(_index) {
            case 0: return BoxEdge(Vec3f(x0, y0, z0), Vec3f(x1, y0, z0));
            case 1: return BoxEdge(Vec3f(x1, y0, z0), Vec3f(x1, y1, z0));
            case 2: return BoxEdge(Vec3f(x1, y1, z0), Vec3f(x0, y1, z0));
            case 3: return BoxEdge(Vec3f(x0, y1, z0), Vec3f(x0, y0, z0));

            case 4: return BoxEdge(Vec3f(x0, y0, z1), Vec3f(x1, y0, z1));
            case 5: return BoxEdge(Vec3f(x1, y0, z1), Vec3f(x1, y1, z1));
            case 6: return BoxEdge(Vec3f(x1, y1, z1), Vec3f(x0, y1, z1));
            case 7: return BoxEdge(Vec3f(x0, y1, z1), Vec3f(x0, y0, z1));

            case 8: return BoxEdge(Vec3f(x0, y0, z0), Vec3f(x0, y0, z1));
            case 9: return BoxEdge(Vec3f(x1, y0, z0), Vec3f(x1, y0, z1));
            case 10: return BoxEdge(Vec3f(x1, y1, z0), Vec3f(x1, y1, z1));
            case 11: return BoxEdge(Vec3f(x0, y1, z0), Vec3f(x0, y1, z1));

            default: return BoxEdge(ZEROVEC3F, ZEROVEC3F);
        }
    }

    /**The center of the box.*/
    Vec3f center;
    /**The extent of the box.*/
    Vec3f extent;
};

LEAVE_NAMESPACE

#endif
