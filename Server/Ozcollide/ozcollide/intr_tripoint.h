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

#ifndef OZCOLLIDE_INTERSECTION_TRIPOINT_H
#define OZCOLLIDE_INTERSECTION_TRIPOINT_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/vec3f.h>

ENTER_NAMESPACE_OZCOLLIDE

// Test if a point is inside a triangle (in a pretty speedy way) given three points.

OZCOLLIDE_API bool isPointInsideTriangle(   const Vec3f &vertex0,
                                            const Vec3f &vertex1,
                                            const Vec3f &vertex2,
                                            const Vec3f &pt);

OZCOLLIDE_API bool isPointInsidePolygon(int nbVertices,
                                        const Vec3f *pnts,
                                        const Vec3f &pt);

LEAVE_NAMESPACE

#endif
