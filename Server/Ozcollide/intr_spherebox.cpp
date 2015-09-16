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
#include <ozcollide/dist_pointbox.h>
#include <ozcollide/box.h>
#include <ozcollide/ellipsoid.h>
#include <ozcollide/sphere.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionSphereBox(const Sphere &_sphere, const Box &_box)
{
	float sqrDist = sqrDistancePointToBox(_sphere.center, _box);
	float rr = _sphere.radius * _sphere.radius;
	if (sqrDist > rr)
		return false;

	return true;
}

bool testIntersectionEllipsoidBox(const Ellipsoid &_ellip, const Box &_box)
{
	Vec3f unitPos = _ellip.getCenter() * _ellip.getInvRadii();

	Box nbox;
	nbox.center = _box.center * _ellip.getInvRadii();
	nbox.extent = _box.extent * _ellip.getInvRadii();

	float sqrDist = sqrDistancePointToBox(unitPos, nbox);
	if (sqrDist > 1)
		return false;

	return true;
}

LEAVE_NAMESPACE
