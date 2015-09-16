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
#include <ozcollide/intr_frustumsphere.h>
#include <ozcollide/plane.h>
#include <ozcollide/frustum.h>
#include <ozcollide/sphere.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionFrustumSphere(const Frustum &_f, const Sphere &_s)
{
	int i;
	float res;

	for (i = 0; i < 6; i++) {
		const Plane &plane = _f.planes[i];
		res =	_s.center.x * plane.a +
				_s.center.y * plane.b +
				_s.center.z * plane.c +
				plane.d;
		if (res < -_s.radius)
			return false;
	}
	return true;
}

LEAVE_NAMESPACE
