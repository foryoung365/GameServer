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
#include <ozcollide/plane.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

Plane::Plane()
{
}

Plane::Plane(float _a, float _b, float _c, float _d)
{
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}

void Plane::fromPoints(const Vec3f &_p0, const Vec3f &_p1, const Vec3f &_p2)
{
	Vec3f v0(_p0 - _p1);
	Vec3f v1(_p2 - _p1);
	Vec3f n = v1 | v0;
	n.normalize();
	a = n.x;
	b = n.y;
	c = n.z;
	d = -(_p0.x * a + _p0.y * b + _p0.z * c);
}

void Plane::fromPointsNN(const Vec3f &_p0, const Vec3f &_p1, const Vec3f &_p2)
{
	Vec3f v0(_p0 - _p1);
	Vec3f v1(_p2 - _p1);
	Vec3f n = v1 | v0;
	a = n.x;
	b = n.y;
	c = n.z;
	d = -(_p0.x * a + _p0.y * b + _p0.z * c);
}

void Plane::fromPointAndNormal(const Vec3f &_p, const Vec3f &_n)
{
	Vec3f nn = _n;
	nn.normalize();
	a = nn.x;
	b = nn.y;
	c = nn.z;
	d = -(_p.x * a + _p.y * b + _p.z * c);
}

LEAVE_NAMESPACE
