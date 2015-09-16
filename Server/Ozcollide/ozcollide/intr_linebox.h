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

#ifndef OZCOLLIDE_INTERSECTION_LINEBOX_H
#define OZCOLLIDE_INTERSECTION_LINEBOX_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#include <ozcollide/plane.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

class Vec3f;
class Box;

// Test if a segment intersects with a box
OZCOLLIDE_API bool testIntersectionSegmentBox(const Vec3f &pt0, const Vec3f &pt1, const Box &);

// Calcul the intersection (if any) between a box and a ray
// [in] rayOrg      origin of the ray
// [in] rayDir      direction of the ray (not necessarily normalised)
// [in] box         the box
// [out] tnear      first (near) time of collision from rayOrg
// [out] tfar       last (far) time of collision from rayOrg
// (return]         return the collided face of the box or -1 if none

OZCOLLIDE_API PLANE intersectRayBox(const Vec3f &rayOrg,
                                    const Vec3f &rayDir,
                                    const Box &box,
                                    float &tnear,
                                    float &tfar);

LEAVE_NAMESPACE

#endif
