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
#include <ozcollide/dist_pointline.h>
#include <ozcollide/vec3f.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

float sqrDistancePointToLine(const Vec3f &_point,
							 const Vec3f &_pt0,
							 const Vec3f &_pt1,
							 Vec3f *_linePt)
{
	Vec3f v = _point - _pt0;
	Vec3f s = _pt1 - _pt0;
	float lenSq = s.lenSq();
	float dot = v.dot(s) / lenSq;
	Vec3f disp = s * dot;
	if (_linePt)
		*_linePt = _pt0 + disp;
	v -= disp;
	return v.lenSq();
}

float distancePointToLine(const Vec3f &_point,
						  const Vec3f &_pt0,
						  const Vec3f &_pt1,
						  Vec3f *_linePt)
{
	return sqrt( sqrDistancePointToLine(_point, _pt0, _pt1, _linePt) );
}

LEAVE_NAMESPACE
