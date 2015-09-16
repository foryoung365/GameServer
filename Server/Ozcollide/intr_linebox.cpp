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
#include <ozcollide/intr_linebox.h>
#include <ozcollide/box.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

bool testIntersectionSegmentBox(const Vec3f &segment_pt0, const Vec3f &segment_pt1,
								  const Box &box)
{
	if (box.isInside(segment_pt0) && box.isInside(segment_pt1))
		return true;

	float fAWdU[3], fADdU[3], fAWxDdU[3], fRhs;
	Vec3f kSDir = 0.5f * (segment_pt1 - segment_pt0);
	Vec3f kSCen = segment_pt0 + kSDir;

	Vec3f kDiff = kSCen - box.center;

	fAWdU[0] = fabsf(kSDir.x);
	fADdU[0] = fabsf(kDiff.x);
	fRhs = box.extent.x + fAWdU[0];
	if (fADdU[0] > fRhs)
		return false;

	fAWdU[1] = fabsf(kSDir.y);
	fADdU[1] = fabsf(kDiff.y);
	fRhs = box.extent.y + fAWdU[1];
	if (fADdU[1] > fRhs)
		return false;

	fAWdU[2] = fabsf(kSDir.z);
	fADdU[2] = fabsf(kDiff.z);
	fRhs = box.extent.z + fAWdU[2];
	if (fADdU[2] > fRhs)
		return false;

	Vec3f kWxD = kSDir | kDiff;

	fAWxDdU[0] = fabsf(kWxD.x);
	fRhs = box.extent.y * fAWdU[2] + box.extent.z * fAWdU[1];
	if (fAWxDdU[0] > fRhs)
		return false;

	fAWxDdU[1] = fabsf(kWxD.y);
	fRhs = box.extent.x * fAWdU[2] + box.extent.z * fAWdU[0];
	if (fAWxDdU[1] > fRhs)
		return false;

	fAWxDdU[2] = fabsf(kWxD.z);
	fRhs = box.extent.x * fAWdU[1] + box.extent.y * fAWdU[0];
	if (fAWxDdU[2] > fRhs)
		return false;

    return true;


/*
	Vec3f min = box.center - box.extent;
	Vec3f max = box.center + box.extent;

	Vec3f deltaSeg = segment_pt1 - segment_pt0;

	// left plane
	if ( (segment_pt0.x <= min.x && segment_pt1.x >= min.x) || (segment_pt1.x <= min.x && segment_pt0.x >= min.x) ) {
		float denom = deltaSeg.x;
		if (denom != 0.0f) {
			float t = (min.x - segment_pt0.x) / denom;
			float y = deltaSeg.y * t + segment_pt0.y;
			float z = deltaSeg.z * t + segment_pt0.z;
			if (y >= min.y && y <= max.y && z >= min.z && z <= max.z)
				return true;
		}
	}

	// right plane
	if ( (segment_pt0.x <= max.x && segment_pt1.x >= max.x) || (segment_pt1.x <= max.x && segment_pt0.x >= max.x) ) {
		float denom = deltaSeg.x;
		if (denom != 0.0f) {
			float t = (max.x - segment_pt0.x) / denom;
			float y = deltaSeg.y * t + segment_pt0.y;
			float z = deltaSeg.z * t + segment_pt0.z;
			if (y >= min.y && y <= max.y && z >= min.z && z <= max.z)
				return true;
		}
	}

	// bottom plane
	if ( (segment_pt0.y <= min.y && segment_pt1.y >= min.y) || (segment_pt1.y <= min.y && segment_pt0.y >= min.y) ) {
		float denom = deltaSeg.y;
		if (denom != 0.0f) {
			float t = (min.y - segment_pt0.y) / denom;
			float x = deltaSeg.x * t + segment_pt0.x;
			float z = deltaSeg.z * t + segment_pt0.z;
			if (x >= min.x && x <= max.x && z >= min.z && z <= max.z)
				return true;
		}
	}

	// top plane
	if ( (segment_pt0.y <= max.y && segment_pt1.y >= max.y) || (segment_pt1.y <= max.y && segment_pt0.y >= max.y) ) {
		float denom = deltaSeg.y;
		if (denom != 0.0f) {
			float t = (max.y - segment_pt0.y) / denom;
			float x = deltaSeg.x * t + segment_pt0.x;
			float z = deltaSeg.z * t + segment_pt0.z;
			if (x >= min.x && x <= max.x && z >= min.z && z <= max.z)
				return true;
		}
	}

	// near plane
	if ( (segment_pt0.z <= min.z && segment_pt1.z >= min.z) || (segment_pt1.z <= min.z && segment_pt0.z >= min.z) ) {
		float denom = deltaSeg.z;
		if (denom != 0.0f) {
			float t = (min.y - segment_pt0.z) / denom;
			float x = deltaSeg.x * t + segment_pt0.x;
			float y = deltaSeg.y * t + segment_pt0.y;
			if (x >= min.x && x <= max.x && y >= min.y && y <= max.y)
				return true;
		}
	}

	// far plane
	if ( (segment_pt0.z <= max.z && segment_pt1.z >= max.z) || (segment_pt1.z <= max.z && segment_pt0.z >= max.z) ) {
		float denom = deltaSeg.z;
		if (denom != 0.0f) {
			float t = (max.z - segment_pt0.z) / denom;
			float x = deltaSeg.x * t + segment_pt0.x;
			float y = deltaSeg.y * t + segment_pt0.y;
			if (x >= min.x && x <= max.x && y >= min.y && y <= max.y)
				return true;
		}
	}

	if (box.isInside(segment_pt0) && box.isInside(segment_pt1))
		return true;

	return false;
*/
}

// This function uses the Policarpo/Watt method itself based on Kay and Kayjia.

PLANE intersectRayBox(const Vec3f &rayOrg,
					  const Vec3f &rayDir,
					  const Box &box,
					  float &tnear,
					  float &tfar)
{
	float t1, t2;
	int ret = -1;

	tnear = -FLT_MAX;
	tfar = FLT_MAX;

	Vec3f min = box.getMin();
	Vec3f max = box.getMax();

	int a, b;
	for (a = 0; a < 3; a++) {
		if (rayDir[a] > -0.001f && rayDir[a] < 0.001f) {
			if (rayOrg[a] < min[a] || rayOrg[a] > max[a])
				return (PLANE) -1;
		}
		else {
			float inv = 1.0f / rayDir[a];
			t1 = (min[a] - rayOrg[a]) * inv;
			t2 = (max[a] - rayOrg[a]) * inv;
			if (t1 > t2) {
				float t = t1; t1 = t2; t2 = t;
				b = a * 2 + 1;
			}
			else
				b = a * 2;

			if (t1 > tnear) {
				tnear = t1;
				ret = b;
			}
			if (t2 < tfar)
				tfar = t2;
			if (tnear > tfar || tfar < 0.001f)
				return (PLANE) -1;
		}
	}

	if (tnear > tfar || tfar < 0.001f)
		return (PLANE) -1;

	return (PLANE) ret;
}

LEAVE_NAMESPACE
