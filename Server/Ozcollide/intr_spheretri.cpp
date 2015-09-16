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
#include <ozcollide/intr_spheretri.h>
#include <ozcollide/intr_sphereline.h>
#include <ozcollide/intr_tripoint.h>
#include <ozcollide/intr_lineline.h>
#include <ozcollide/dist_pointline.h>
#include <ozcollide/plane.h>
#include <ozcollide/sphere.h>
#include <ozcollide/vec2f.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionSphereTriangle(Vec3f &_center, float _radius,
									const Vec3f &_pt0, const Vec3f &_pt1, const Vec3f &_pt2,
									const Plane &_plane,
									Vec3f *_closestPoint,
									int *_edgesFlags)
{
	float dist;
	float dist2plane;

	dist = _center.x * _plane.a + _center.y * _plane.b + _center.z * _plane.c + _plane.d;
	dist2plane = dist;
	if (dist > _radius || dist < -_radius) {
		if (_edgesFlags)
			_edgesFlags = 0;
		return false;
	}

	Plane planeE0, planeE1, planeE2;
	Vec3f up;
	up.x = _plane.a;
	up.y = _plane.b;
	up.z = _plane.c;

	float distE0 = _center.x * planeE0.a + _center.y * planeE0.b + _center.z * planeE0.c + planeE0.d;
	float distE1 = _center.x * planeE1.a + _center.y * planeE1.b + _center.z * planeE1.c + planeE1.d;
	float distE2 = _center.x * planeE2.a + _center.y * planeE2.b + _center.z * planeE2.c + planeE2.d;

	if (distE0 <= -_radius || distE1 <= -_radius || distE2 <= -_radius) {
		if (_edgesFlags)
			_edgesFlags = 0;
		return false;
	}

	if (distE0 >= _radius && distE1 >= _radius && distE2 >= _radius) {
		if (_edgesFlags)
			_edgesFlags = 0;
		return true;
	}

	Vec3f c, v;
	Vec3f closest;
	float d, t;
	float minDist = FLT_MAX;
	int edges = 0;

	// Edge0
	c = _center - _pt0;
	v = _pt1 - _pt0;
	d = v.len();
	v.normalize();
	t = v.dot(c);

	if (t < 0.0f)
		closest = _pt0;
	else if (t > d)
		closest = _pt1;
	else
		closest = v * t + _pt0;
	
	dist = (closest - _center).len();
	if (dist < _radius)
		edges |= 1;
	if (_closestPoint && dist < minDist) {
		minDist = dist;
		*_closestPoint = closest;
	}

	// Edge1
	c = _center - _pt1;
	v = _pt2 - _pt1;
	d = v.len();
	v.normalize();
	t = v.dot(c);

	if (t < 0.0f)
		closest = _pt1;
	else if (t > d)
		closest = _pt2;
	else
		closest = v * t + _pt1;
	
	dist = (closest - _center).len();
	if (dist < _radius)
		edges |= 2;
	if (_closestPoint && dist < minDist) {
		minDist = dist;
		*_closestPoint = closest;
	}

	// Edge3
	c = _center - _pt2;
	v = _pt0 - _pt2;
	d = v.len();
	v.normalize();
	t = v.dot(c);

	if (t < 0.0f)
		closest = _pt2;
	else if (t > d)
		closest = _pt0;
	else
		closest = v * t + _pt2;
	
	dist = (closest - _center).len();
	if (dist < _radius)
		edges |= 4;
	if (_closestPoint && dist < minDist) {
		minDist = dist;
		*_closestPoint = closest;
	}

	if (_edgesFlags)
		*_edgesFlags = edges;

	if (edges)
		return true;

	return false;
}

bool magic_testIntersectionSphereTriangle(const Vec3f &center, float radius, const Vec3f &pt0, const Vec3f &pt1, const Vec3f &pt2, float *dist)
{
	Vec3f triOrg = pt0;
	Vec3f triEdge0 = pt1 - pt0;
	Vec3f triEdge1 = pt2 - pt0;

	Vec3f kDiff = triOrg - center;
	float fA00 = triEdge0.lenSq();
	float fA01 = triEdge0.dot(triEdge1);
	float fA11 = triEdge1.lenSq();
	float fB0 = kDiff.dot(triEdge0);
	float fB1 = kDiff.dot(triEdge1);
	float fC = kDiff.lenSq();
	float fDet = (float) fabs(fA00 * fA11 - fA01 * fA01);
	float fS = fA01 * fB1 - fA11 * fB0;
	float fT = fA01 * fB0 - fA00 * fB1;
	float sqrDist;

	if (fS + fT <= fDet) {
		if (fS < 0.0f) {
			if (fT < 0.0f) {
				// region 4
				if (fB0 < 0.0f) {
					fT = 0.0f;
					if (-fB0 >= fA00) {
						fS = 1.0f;
						sqrDist = fA00 + 2.0f * fB0 + fC;
					}
					else {
						fS = -fB0 / fA00;
						sqrDist = fB0 * fS + fC;
					}
				}
				else {
					fS = 0.0f;
					if (fB1 >= 0.0f) {
						fT = 0.0f;
						sqrDist = fC;
					}
					else if (-fB1 >= fA11) {
						fT = 1.0f;
						sqrDist = fA11 + 2.0f * fB1 + fC;
					}
					else {
						fT = -fB1 / fA11;
						sqrDist = fB1 * fT + fC;
					}
				}
			}
			else {
				// region 3
				fS = 0.0f;
				if (fB1 >= 0.0f) {
					fT = 0.0f;
					sqrDist = fC;
				}
				else if (-fB1 >= fA11) {
					fT = 1.0f;
					sqrDist = fA11 + 2.0f * fB1 + fC;
				}
				else {
					fT = -fB1 / fA11;
					sqrDist = fB1 * fT + fC;
				}
			}
		}
		else if (fT < 0.0f) {
			// region 5
			fT = 0.0f;
			if (fB0 >= 0.0f) {
				fS = 0.0f;
				sqrDist = fC;
			}
			else if (-fB0 >= fA00) {
				fS = 1.0f;
				sqrDist = fA00 + 2.0f * fB0 + fC;
			}
			else {
				fS = -fB0 / fA00;
				sqrDist = fB0 * fS + fC;
			}
		}
		else {
			// region 0
            // minimum at interior point
			float fInvDet = 1.0f / fDet;
			fS *= fInvDet;
			fT *= fInvDet;
			sqrDist = fS * (fA00 * fS + fA01 * fT + 2.0f * fB0) +
					  fT * (fA01 * fS + fA11 * fT + 2.0f * fB1) + fC;
		}
	}
	else {
		float fTmp0, fTmp1, fNumer, fDenom;
		
		if (fS < 0.0f)  {
			// region 2
			fTmp0 = fA01 + fB0;
			fTmp1 = fA11 + fB1;
			if (fTmp1 > fTmp0) {
				fNumer = fTmp1 - fTmp0;
				fDenom = fA00 - 2.0f * fA01 + fA11;
				if (fNumer >= fDenom) {
					fS = 1.0f;
					fT = 0.0f;
					sqrDist = fA00 + 2.0f * fB0 + fC;
				}
				else {
					fS = fNumer / fDenom;
					fT = 1.0f - fS;
					sqrDist = fS * (fA00 * fS + fA01 * fT + 2.0f * fB0) +
							  fT * (fA01 * fS + fA11 * fT + 2.0f * fB1) + fC;
				}
			}
			else {
				fS = 0.0f;
				if (fTmp1 <= 0.0f) {
					fT = 1.0f;
					sqrDist = fA11 + 2.0f * fB1 + fC;
				}
				else if (fB1 >= 0.0f) {
					fT = 0.0f;
					sqrDist = fC;
				}
				else {
					fT = -fB1 / fA11;
					sqrDist = fB1 * fT + fC;
				}
			}
		}
		else if (fT < 0.0f) {
			// region 6
			fTmp0 = fA01 + fB1;
			fTmp1 = fA00 + fB0;
			if (fTmp1 > fTmp0) {
				fNumer = fTmp1 - fTmp0;
				fDenom = fA00 - 2.0f * fA01 + fA11;
				if (fNumer >= fDenom) {
					fT = 1.0f;
					fS = 0.0f;
					sqrDist = fA11 + 2.0f * fB1 + fC;
				}
				else {
					fT = fNumer / fDenom;
					fS = 1.0f - fT;
					sqrDist = fS * (fA00 * fS + fA01 * fT + 2.0f * fB0) +
							  fT * (fA01 * fS + fA11 * fT + 2.0f * fB1) + fC;
				}
			}
			else {
				fT = 0.0f;
				if (fTmp1 <= 0.0f) {
					fS = 1.0f;
					sqrDist = fA00 + 2.0f * fB0 + fC;
				}
				else if (fB0 >= 0.0f) {
					fS = 0.0f;
					sqrDist = fC;
				}
				else {
					fS = -fB0 / fA00;
					sqrDist = fB0 * fS + fC;
				}
			}
		}
		else {
			// region 1
			fNumer = fA11 + fB1 - fA01 - fB0;
			if (fNumer <= 0.0f) {
				fS = 0.0f;
				fT = 1.0f;
				sqrDist = fA11 + 2.0f * fB1 + fC;
			}
			else {
				fDenom = fA00 - 2.0f * fA01 + fA11;
				if (fNumer >= fDenom) {
					fS = 1.0f;
					fT = 0.0f;
					sqrDist = fA00 + 2.0f * fB0 + fC;
				}
				else {
					fS = fNumer / fDenom;
					fT = 1.0f - fS;
					sqrDist = fS * (fA00 * fS + fA01 * fT + 2.0f * fB0) +
							  fT * (fA01 * fS + fA11 * fT + 2.0f * fB1) + fC;
				}
			}
		}
	}

	sqrDist = (float) fabs(sqrDist);

	if (dist)
		*dist = (float) sqrt(sqrDist);

	float radius2 = radius * radius;
	return sqrDist < radius2 ? true : false;
}

bool testIntersectionTriSphere(const Vec3f *_triPts[3],
								 const Vec3f &_triNormal,
								 const Sphere &_sphere,
								 const Vec3f &_sphereVel,
								 float &_distTravel,
								 Vec3f &_reaction)
{
	int i;
	Vec3f nvelo = _sphereVel;
	nvelo.normalize();

	if (_triNormal.dot(nvelo) >= 0)
		return false;

	float minDist = FLT_MAX;
	Vec3f reaction;
	int col = -1;
	_distTravel = FLT_MAX;

	Plane plane;
	plane.fromPointAndNormal(*_triPts[0], _triNormal);

	// pass1: sphere VS plane
	float h = plane.dist( _sphere.center );
	if (h < -_sphere.radius)
		return false;

	if (h > _sphere.radius) {
		h -= _sphere.radius;
		float dot = _triNormal.dot(nvelo);
		if (dot != 0) {
			float t = -h / dot;
			if (t >= 0) {
				Vec3f onPlane = _sphere.center + nvelo * t;
				onPlane -= _triNormal * _sphere.radius;
				if (isPointInsideTriangle( *_triPts[0], *_triPts[1], *_triPts[2], onPlane)) {
					if (t < _distTravel) {
						_distTravel = t;
						_reaction = _triNormal;
						col = 0;
					}
				}
			}
		}
	}

	// pass2: sphere VS triangle vertices
	for (i = 0; i < 3; i++) {
		Vec3f seg_pt0 = *_triPts[i];
		Vec3f seg_pt1 = seg_pt0 - nvelo;
		Vec3f v = seg_pt1 - seg_pt0;

		float inter1=FLT_MAX, inter2=FLT_MAX;
		int nbInter;
		bool res = testIntersectionSphereLine(_sphere, seg_pt0, seg_pt1, &nbInter, &inter1, &inter2);
		if (res == false)
			continue;

		float t = inter1;
		if (inter2 < t)
			t = inter2;

		if (t < 0)
			continue;

		if (t < _distTravel) {
			_distTravel = t;
			Vec3f onSphere = seg_pt0 + v * t;
			_reaction = _sphere.center - onSphere;
			col = 1;
		}
	}

	// pass3: sphere VS triangle edges
	for (i = 0; i < 3; i++) {
		Vec3f edge0 = *_triPts[i];
		int j = i + 1;
		if (j == 3)
			j = 0;
		Vec3f edge1 = *_triPts[j];

		Plane plane;
		plane.fromPoints(edge0, edge1, edge1 - nvelo);
		float d = plane.dist(_sphere.center);
		if (d > _sphere.radius || d < -_sphere.radius)
			continue;

		float srr = _sphere.radius * _sphere.radius;
		float r = sqrt(srr - d*d);

		Vec3f pt0 = plane.project(_sphere.center); // center of the sphere slice (a circle)

		Vec3f onLine;
		float h = distancePointToLine(pt0, edge0, edge1, &onLine);
		Vec3f v = onLine - pt0;
		v.normalize();
		Vec3f pt1 = v * r + pt0; // point on the sphere that will maybe collide with the edge

		int a0 = 0, a1 = 1;
		float pl_x = fabsf(plane.a);
		float pl_y = fabsf(plane.b);
		float pl_z = fabsf(plane.c);
		if (pl_x > pl_y && pl_x > pl_z) {
			a0 = 1;
			a1 = 2;
		}
		else {
			if (pl_y > pl_z) {
				a0 = 0;
				a1 = 2;
			}
		}

		Vec3f vv = pt1 + nvelo;

		float t;
		bool res = testIntersectionLineLine(	Vec2f(pt1[a0], pt1[a1]),
												Vec2f(vv[a0], vv[a1]),
												Vec2f(edge0[a0], edge0[a1]),
												Vec2f(edge1[a0], edge1[a1]),
												&t);
		if (!res || t < 0)
			continue;

		Vec3f inter = pt1 + nvelo * t;

		Vec3f r1 = edge0 - inter;
		Vec3f r2 = edge1 - inter;
		if (r1.dot(r2) > 0)
			continue;

		if (t > _distTravel)
			continue;

		_distTravel = t;
		_reaction = _sphere.center - pt1;
		col = 2;
	}

	if (col == -1)
		return false;

	_reaction.normalize();

	return true;
}

LEAVE_NAMESPACE
