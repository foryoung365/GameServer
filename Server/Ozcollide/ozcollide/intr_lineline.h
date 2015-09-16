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

#ifndef OZOSMATH_INTERSECTION_LINELINE_H
#define OZOSMATH_INTERSECTION_LINELINE_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

class Vec2f;

// test if two 2D lines (p0, p1) and (p2, p3) intersect
// if they do true is returned, false otherwhise
bool testIntersectionLineLine(  const Vec2f &p1, const Vec2f &p2,
                                const Vec2f &p3, const Vec2f &p4,
                                float *t);

LEAVE_NAMESPACE

#endif
