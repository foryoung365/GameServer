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

#ifndef OZCOLLIDE_INTERSECTION_SPHERETRI_H
#define OZCOLLIDE_INTERSECTION_SPHERETRI_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

class Vec3f;
class Plane;
class Sphere;

// Test if a sphere intersects with a triangle
//
// [in] center                  center of the sphere
// [in] radius                  radius of the sphere
// [in] pt0, pt1, pt2           three points which define the triangle to be tested with the sphere
// [in] plane                   plane on which all triangle's points are
// [out] closestPoint           optional point that corresponds to the nearest point of the triangle's perimeter
//                              to the center of the sphere
// [out] edgesFlags             optional flags to know which edges of the triangle intersect with the sphere
//                              the n-th bit of the int is a flag that is 1 if the n-th edge intersect and 0 otherwhise
//                              for example a flags of 5 (101 in binary) means that the first and third egde of the
//                              triangle intersect with the sphere
// [return]                     true if the sphere and triangle intersect, false otherwhise

OZCOLLIDE_API bool testIntersectionSphereTriangle(  Vec3f &center,
                                                    float radius,
                                                    const Vec3f &pt0, const Vec3f &pt1, const Vec3f &pt2,
                                                    const Plane &plane,
                                                    Vec3f *closestPoint = NULL,
                                                    int *edgesFlags = NULL);


// Test if a sphere intersects with a triangle - Based on the Eberly's method in Magic
//
// [in] center              center of the sphere
// [in] radius              radius of the sphere
// [in] pt0, pt1, pt2       three points which define the triangle to be tested with the sphere
// [in] dist                optional floating value to know the distance of the triangle from the sphere
// [return]                 true if the sphere and triangle intersect, false otherwhise

OZCOLLIDE_API bool magic_testIntersectionSphereTriangle(const Vec3f &center,
                                                        float radius,
                                                        const Vec3f &pt0,
                                                        const Vec3f &pt1,
                                                        const Vec3f &pt2,
                                                        float *dist = NULL);

OZCOLLIDE_API bool testIntersectionTriSphere(   const Vec3f *triPts[3],
                                                const Vec3f &triNormal,
                                                const Sphere &sphere,
                                                const Vec3f &sphereVel,
                                                float &distTravel,
                                                Vec3f &reaction);


LEAVE_NAMESPACE

#endif
