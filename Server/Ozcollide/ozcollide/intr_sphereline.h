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

#ifndef OZCOLLIDE_INTERSECTION_SPHERELINE_H
#define OZCOLLIDE_INTERSECTION_SPHERELINE_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

class Vec3f;
class Sphere;

// Test the intersection between a sphere and a line
// The implementation uses standard quadratic solver and so, is not especially optimized
OZCOLLIDE_API bool testIntersectionSphereLine(  const Sphere &,
                                                const Vec3f &pt0,
                                                const Vec3f &pt1,
                                                int *nbInter = NULL,
                                                float *inter1 = NULL,
                                                float *inter2 = NULL);

OZCOLLIDE_API float intersectRaySphere(const Vec3f &rO, const Vec3f &rV, const Vec3f &sO, float sR);

LEAVE_NAMESPACE

#endif
