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
//#include <ozcollide/Box.h> milad
#include <ozcollide/box.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

float sqrDistancePointToBox(const Vec3f &_pt, const Box &_box, Vec3f *_nearestPoint)
{
	float x0 = _box.center.x - _box.extent.x;
	float x1 = _box.center.x + _box.extent.x;
	float y0 = _box.center.y - _box.extent.y;
	float y1 = _box.center.y + _box.extent.y;
	float z0 = _box.center.z - _box.extent.z;
	float z1 = _box.center.z + _box.extent.z;

	Vec3f closest = _box.center;

	if (_pt.x < x0)
		closest.x = x0;
	else if (_pt.x > x1)
		closest.x = x1;
	else
		closest.x = _pt.x;

	if (_pt.y < y0)
		closest.y = y0;
	else if (_pt.y > y1)
		closest.y = y1;
	else
		closest.y = _pt.y;

	if (_pt.z < z0)
		closest.z = z0;
	else if (_pt.z > z1)
		closest.z = z1;
	else
		closest.z = _pt.z;

	if (_nearestPoint)
		*_nearestPoint = closest;

	Vec3f ray = _pt - closest;
	float sqrDist = ray.dot(ray);

	return sqrDist;
}

float distancePointToBox(const Vec3f &_pt, const Box &_box, Vec3f *_nearestPoint)
{
	return (float) sqrt(sqrDistancePointToBox(_pt, _box, _nearestPoint));
}

LEAVE_NAMESPACE
