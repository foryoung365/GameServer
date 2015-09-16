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
#include <ozcollide/intr_tripoint.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

// This function uses the Dan Sunday's algorithm.

bool isPointInsideTriangle(const Vec3f &_v0,
							 const Vec3f &_v1,
							 const Vec3f &_v2,
							 const Vec3f &_pt)
{
	Vec3f u = _v1 - _v0;
	Vec3f v = _v2 - _v0;
	Vec3f w = _pt - _v0;

	float uu = u.dot(u);
	float uv = u.dot(v);
	float vv = v.dot(v);
	float wu = w.dot(u);
	float wv = w.dot(v);
	float d = uv * uv - uu * vv;

	float invD = 1 / d;
	float s = (uv * wv - vv * wu) * invD;
	if (s < 0 || s > 1)
		return false;
	float t = (uv * wu - uu * wv) * invD;
	if (t < 0 || (s + t) > 1)
		return false;

	return true;

/*
	float sum = 0;

	Vec3f da = vertex0 - pt;
	Vec3f db = vertex1 - pt;
	Vec3f dc = vertex2 - pt;

	da.normalize();
	db.normalize();
	dc.normalize();

	sum += (float) SAFE_ACOS( da.dot(db) );
	sum += (float) SAFE_ACOS( db.dot(dc) );
	sum += (float) SAFE_ACOS( dc.dot(da) );

	if (sum < OZ_TWOPI - 0.1 || sum > OZ_TWOPI + 0.1)
		return OZFALSE;

	return OZTRUE;
	*/
}

bool isPointInsidePolygon(int _nbVertices,
							const Vec3f *_pnts,
							const Vec3f &_pt)
{
	int nbTriangles = _nbVertices - 2;
	for (int i = 0; i < nbTriangles; i++) {
		const Vec3f &pt0 = _pnts[0];
		const Vec3f &pt1 = _pnts[i + 1];
		const Vec3f &pt2 = _pnts[i + 2];
		if (isPointInsideTriangle(pt0, pt1, pt2, _pt))
			return true;
	}
	return false;
}

LEAVE_NAMESPACE
