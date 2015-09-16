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
#include <ozcollide/intr_boxbox.h>
#include <ozcollide/obb.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionAABB_OBB(const Box &_aabb, const OBB &_obb)
{
	float t, s;
	int r;
	float Bf[3][3];
	float reps = (float) 1e-6;

	const Vec3f &a = _aabb.extent;
	const Vec3f &b = _obb.extent;
	const Vec3f T = _obb.center - _aabb.center;

//	float B[3][3];

//	const Matrix3x3 &m = _obb.matrix;
//	B[0][0] = m._11;	B[0][1] = m._21;	B[0][2] = m._31;
//	B[1][0] = m._12;	B[1][1] = m._22;	B[1][2] = m._32;
//	B[2][0] = m._13;	B[2][1] = m._23;	B[2][2] = m._33;

	typedef float _mat3x3[3][3];
	_mat3x3 B;
	memcpy(B, _obb.matrix.m_, sizeof(_mat3x3));
  
	// Bf = fabs(B)
	Bf[0][0] = fabsf(B[0][0]);  Bf[0][0] += reps;
	Bf[0][1] = fabsf(B[0][1]);  Bf[0][1] += reps;
	Bf[0][2] = fabsf(B[0][2]);  Bf[0][2] += reps;
	Bf[1][0] = fabsf(B[1][0]);  Bf[1][0] += reps;
	Bf[1][1] = fabsf(B[1][1]);  Bf[1][1] += reps;
	Bf[1][2] = fabsf(B[1][2]);  Bf[1][2] += reps;
	Bf[2][0] = fabsf(B[2][0]);  Bf[2][0] += reps;
	Bf[2][1] = fabsf(B[2][1]);  Bf[2][1] += reps;
	Bf[2][2] = fabsf(B[2][2]);  Bf[2][2] += reps;

	// if any of these tests are one-sided, then the polyhedra are disjoint
	r = 1;

	// A1 x A2 = A0
	t = fabsf(T[0]);
	r &= (t <= (a[0] + b[0] * Bf[0][0] + b[1] * Bf[0][1] + b[2] * Bf[0][2]));
	if (!r) return false;
  
	// B1 x B2 = B0
	s = T[0]*B[0][0] + T[1]*B[1][0] + T[2]*B[2][0];
	t = fabsf(s);
	r &= ( t <= (b[0] + a[0] * Bf[0][0] + a[1] * Bf[1][0] + a[2] * Bf[2][0]));
	if (!r) return false;
    
	// A2 x A0 = A1
	t = fabsf(T[1]);
	r &= ( t <=  (a[1] + b[0] * Bf[1][0] + b[1] * Bf[1][1] + b[2] * Bf[1][2]));
	if (!r) return false;

	// A0 x A1 = A2
	t = fabsf(T[2]);
	r &= ( t <= (a[2] + b[0] * Bf[2][0] + b[1] * Bf[2][1] + b[2] * Bf[2][2]));
	if (!r) return false;

	// B2 x B0 = B1
	s = T[0]*B[0][1] + T[1]*B[1][1] + T[2]*B[2][1];
	t = fabsf(s);
	r &= ( t <= (b[1] + a[0] * Bf[0][1] + a[1] * Bf[1][1] + a[2] * Bf[2][1]));
	if (!r) return false;

	// B0 x B1 = B2
	s = T[0]*B[0][2] + T[1]*B[1][2] + T[2]*B[2][2];
	t = fabsf(s);
	r &= ( t <= (b[2] + a[0] * Bf[0][2] + a[1] * Bf[1][2] + a[2] * Bf[2][2]));
	if (!r) return false;

	// A0 x B0
	s = T[2] * B[1][0] - T[1] * B[2][0];
	t = fabsf(s);
  
	r &= ( t <= (a[1] * Bf[2][0] + a[2] * Bf[1][0] + b[1] * Bf[0][2] + b[2] * Bf[0][1]));
	if (!r) return false;
  
	// A0 x B1
	s = T[2] * B[1][1] - T[1] * B[2][1];
	t = fabsf(s);
	r &= ( t <= (a[1] * Bf[2][1] + a[2] * Bf[1][1] + b[0] * Bf[0][2] + b[2] * Bf[0][0]));
	if (!r) return false;

	// A0 x B2
	s = T[2] * B[1][2] - T[1] * B[2][2];
	t = fabsf(s);
	r &= ( t <= (a[1] * Bf[2][2] + a[2] * Bf[1][2] + b[0] * Bf[0][1] + b[1] * Bf[0][0]));
	if (!r) return false;

	// A1 x B0
	s = T[0] * B[2][0] - T[2] * B[0][0];
	t = fabsf(s);
	r &= ( t <= (a[0] * Bf[2][0] + a[2] * Bf[0][0] + b[1] * Bf[1][2] + b[2] * Bf[1][1]));
	if (!r) return false;

	// A1 x B1
	s = T[0] * B[2][1] - T[2] * B[0][1];
	t = fabsf(s);
	r &= ( t <= (a[0] * Bf[2][1] + a[2] * Bf[0][1] +  b[0] * Bf[1][2] + b[2] * Bf[1][0]));
	if (!r) return false;

	// A1 x B2
	s = T[0] * B[2][2] - T[2] * B[0][2];
	t = fabsf(s);
	r &= (t <= (a[0] * Bf[2][2] + a[2] * Bf[0][2] +  b[0] * Bf[1][1] + b[1] * Bf[1][0]));
	if (!r) return false;

	// A2 x B0
	s = T[1] * B[0][0] - T[0] * B[1][0];
	t = fabsf(s);
	r &= (t <= (a[0] * Bf[1][0] + a[1] * Bf[0][0] +  b[1] * Bf[2][2] + b[2] * Bf[2][1]));
	if (!r) return false;

	// A2 x B1
	s = T[1] * B[0][1] - T[0] * B[1][1];
	t = fabsf(s);
	r &= ( t <= (a[0] * Bf[1][1] + a[1] * Bf[0][1] + b[0] * Bf[2][2] + b[2] * Bf[2][0]));
	if (!r) return false;

	// A2 x B2
	s = T[1] * B[0][2] - T[0] * B[1][2];
	t = fabsf(s);
	r &= ( t <= (a[0] * Bf[1][2] + a[1] * Bf[0][2] +  b[0] * Bf[2][1] + b[1] * Bf[2][0]));
	if (!r) return false;

	return true;
}

LEAVE_NAMESPACE
