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
#include <ozcollide/intr_sphereline.h>
#include <ozcollide/vec3f.h>
#include <ozcollide/sphere.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

#define square(a) ((a)*(a))

bool testIntersectionSphereLine(const Sphere &_sphere,
								const Vec3f &_pt0,
								const Vec3f &_pt1,
								int *_nbInter,
								float *_inter1,
								float *_inter2)
{
	float a, b, c, i;

	a = square(_pt1.x - _pt0.x) + square(_pt1.y - _pt0.y) + square(_pt1.z - _pt0.z);
	b =  2 * ( (_pt1.x - _pt0.x) * (_pt0.x - _sphere.center.x)
		+ (_pt1.y - _pt0.y) * (_pt0.y - _sphere.center.y)
		+ (_pt1.z - _pt0.z) * (_pt0.z - _sphere.center.z) ) ;
	c = square(_sphere.center.x) + square(_sphere.center.y) +
		square(_sphere.center.z) + square(_pt0.x) +
		square(_pt0.y) + square(_pt0.z) -
		2 * ( _sphere.center.x * _pt0.x + _sphere.center.y * _pt0.y + _sphere.center.z * _pt0.z ) - square(_sphere.radius) ;
	i =  b * b - 4 * a * c;

	if (i < 0)
		return false;

	if (i == 0) {
		if (_nbInter) *_nbInter = 1;
		if (_inter1) *_inter1 = -b / (2 * a);
	}
	else {
		if (_nbInter) *_nbInter = 2;
		if (_inter1) *_inter1 = (-b + sqrt( square(b) - 4*a*c )) / (2 * a);
		if (_inter2) *_inter2 = (-b - sqrt( square(b) - 4*a*c )) / (2 * a);
	}

	return true;
}

float intersectRaySphere(const Vec3f &_rO, const Vec3f &_rV, const Vec3f &_sO, float _sR)
{
	Vec3f q = _sO - _rO;
	float c = q.len();
	float v = q.dot(_rV);
	float d = _sR * _sR - (c * c - v * v);

	if (d < 0.0f)
		return -1.0f;

	return v - sqrt(d);
}

LEAVE_NAMESPACE
