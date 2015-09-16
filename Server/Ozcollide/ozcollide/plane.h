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

#ifndef OZCOLLIDE_PLANE_H
#define OZCOLLIDE_PLANE_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/vec3f.h>

ENTER_NAMESPACE_OZCOLLIDE

/**
 * @file plane.h
 * Determines a kind of cube plane.
 */
enum PLANE {
    LEFT_PLANE, /**< Left plane.*/
    RIGHT_PLANE, /**< Right plane.*/
    BOTTOM_PLANE, /**< Bottom plane.*/
    TOP_PLANE, /**< Top plane.*/
    NEAR_PLANE, /**< Near plane.*/
    FAR_PLANE /**< Far plane.*/
};

/**
 * Determines a 3D plane.
 * A plane is defined by the equation ax+by+cz+d = 0
 */
class Plane {
public:

    /**
     * Constructs an uninitialised plane.
     */
    OZCOLLIDE_API Plane();

    /**
     * Constructs an initialised plane.
     * @param a The a factor.
     * @param b The b factor.
     * @param c The c factor.
     * @param d The d factor.
     */
    OZCOLLIDE_API Plane(float a, float b, float c, float d);

    /**
     * Constructs a plane from three points.
     * @param p0 1th point.
     * @param p1 2nd point.
     * @param p2 3th point.
     */
    OZCOLLIDE_API void fromPoints(const Vec3f &p0, const Vec3f &p1, const Vec3f &p2);

    /**
     * Constructs a plane from three points and don't normalize the equation.
     * @param p0 1th point.
     * @param p1 2nd point.
     * @param p2 3th point.
     */
    OZCOLLIDE_API void fromPointsNN(const Vec3f &p0, const Vec3f &p1, const Vec3f &p2);

    /**
     *  Constructs a plane from a point and a normal.
     * @param p The point that lies on the plane.
     * @param n The normal of the plane.
     */
    OZCOLLIDE_API void fromPointAndNormal(const Vec3f &p, const Vec3f &n);

    /**
     * Makes a dot product between a point and the plane. Result becomes closer to d's factor as the point is near to the plane.
     * @param p The point.
     * @return The dot product.
     */
    ozinline float dot(const Vec3f &p) const
    {
	return a * p.x + b * p.y + c * p.z;
    }

    /**
     * Calculates the distance between a point and the plane.
     * @param p The point.
     * @return The distance.
     */
    ozinline float dist(const Vec3f &p) const
    {
	return a * p.x + b * p.y + c * p.z + d;
    }

    /**
     * Reflects a vector on the plane.
     * @param p The vector to be reflected.
     * @return The reflected vector.
     */
    ozinline Vec3f reflect(const Vec3f &vec)
    {
        float d = dist(vec);
        return  vec + 2 * Vec3f(-a, -b, -c) * d;
    }

    /**
     * Projects a point onto the plane.
     * @param p The point to be projected.
     * @returned the projected point.
     */
    ozinline Vec3f project(const Vec3f &p)
    {
        float h = dist(p);
        return Vec3f(   p.x - a * h,
                        p.y - b * h,
                        p.z - c * h);
    }

    /**
     * Tells if a point is on the plane or not.
     * @param p The point to test.
     * @param (optional) The threshold to use to determine if the point is on the plane or not. Indeed we couldn't just test if the distance from the point to the plane is zero because of potential numerical error. Default is 10^-3.
     * @return true if the point is on the plane, false otherwhise.
     */
    ozinline bool isOnPlane(const Vec3f &p, float threshold = 0.001f)
    {
        float d = dist(p);
        if (d < threshold && d > -threshold)
            return true;
        return false;
    }

    /**
     * Determines if a line and the place intersect.
     * @param p0 The first point of the line.
     * @param p1 The second point of the line.
     * @param t A value that will be filled with the distance to travel to get the intersection.
     * @return If the plane and the line are parallel false is returned, true otherwhise since the line obviously intersects with the plane.
     */
    ozinline bool intersectWithLine(const Vec3f &p0, const Vec3f &p1, float &t)
    {
        Vec3f dir = p1 - p0;
        float div = dot(dir);
        if (div == 0)
            return false;

	t = -dist(p0) / div;
        return true;
    }

    /**The a factor of the plane.*/
    float a;
    /**The b factor of the plane.*/
    float b;
    /**The c factor of the plane.*/
    float c;
    /**The d factor of the plane.*/
    float d;
};

LEAVE_NAMESPACE

#endif
