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
#include <ozcollide/intr_segmenttri.h>
#include <ozcollide/intr_tripoint.h>
#include <ozcollide/plane.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionRayTri(	const Vec3f &_rayOrg,
								const Vec3f &_rayDir,
								const Vec3f &_v0,
								const Vec3f &_v1,
								const Vec3f &_v2,
								Vec3f *_intrPoint)
{

	Plane plane;
	plane.fromPointsNN(_v0, _v1, _v2);

	float div = plane.dot(_rayDir);
	if (div == 0)
		return false;

	float t = -plane.dist(_rayOrg) / div;
	if (t < 0)
		return false;
	Vec3f pt = _rayDir * t + _rayOrg;

	bool res = isPointInsideTriangle(_v0, _v1, _v2, pt);

	if (res == true && _intrPoint)
		*_intrPoint = pt;

	return res;
}

bool testIntersectionSegmentTri(	const Vec3f &_seg_pt0,
									const Vec3f &_seg_pt1,
									const Vec3f &_v0,
									const Vec3f &_v1,
									const Vec3f &_v2,
									Vec3f *_intrPoint)
{
	Plane plane;
	plane.fromPointsNN(_v0, _v1, _v2);

	Vec3f ray = _seg_pt1 - _seg_pt0;

	float div = plane.dot(ray);
	if (div == 0)
		return false;

	float t = -plane.dist(_seg_pt0) / div;
	if (t < 0 || t > 1)
		return false;
	Vec3f pt = ray * t + _seg_pt0;

	bool res = isPointInsideTriangle(_v0, _v1, _v2, pt);

	if (res == true && _intrPoint)
		*_intrPoint = pt;

	return res;
}

bool intersectionLinePlane(const Vec3f &_pt0,
							 const Vec3f &_pt1,
							 const Plane &_plane,
							 Vec3f *_intrPoint)
{

	Vec3f dir = _pt1 - _pt0;
	float div = _plane.dot(dir);
	if (div == 0)
		return false;

	float t = -_plane.dist(_pt0) / div;
	*_intrPoint = dir * t + _pt0;

	return true;
}

LEAVE_NAMESPACE
