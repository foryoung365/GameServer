/*
OZCollide - Collision Detection Library
Copyright (C) 2014 Igor Kravtchenko

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

#include <ozcollide/ozcollide.h>

#ifndef OZCOLLIDE_PCH
#include <ozcollide/intr_lineline.h>
#include <ozcollide/vec2f.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionLineLine(const Vec2f &_p1, const Vec2f &_p2,
								const Vec2f &_p3, const Vec2f &_p4,
								float *_t)
{
	Vec2f d1 = _p2 - _p1;
	Vec2f d2 = _p3 - _p4;

	float denom = d2.y*d1.x - d2.x*d1.y;
	if (!denom)
		return false;

	if (_t) {
		float dist = d2.x*(_p1.y-_p3.y) - d2.y*(_p1.x-_p3.x);
		dist /= denom;
		*_t = dist;
	}

	return true;
}

LEAVE_NAMESPACE
