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
#include <ozcollide/intr_tribox.h>
#include <ozcollide/intr_tripoint.h>
#include <ozcollide/intr_linebox.h>
#include <ozcollide/vec3f.h>
#include <ozcollide/obb.h>
#include <ozcollide/polygon.h>
#include <ozcollide/matrix.h>
#endif

/********************************************************/
/* AABB-triangle overlap test code                      */
/* by Tomas Akenine-Möller                              */
/* Function: int triBoxOverlap(float boxcenter[3],      */
/*          float boxhalfsize[3],float triverts[3][3]); */
/* History:                                             */
/*   2001-03-05: released the code in its first version */
/*   2001-06-18: changed the order of the tests, faster */
/*                                                      */
/* Acknowledgement: Many thanks to Pierre Terdiman for  */
/* suggestions and discussions on how to optimize code. */
/* Thanks to David Hunt for finding a ">="-bug!         */
/********************************************************/

ENTER_NAMESPACE_OZCOLLIDE

#define X 0
#define Y 1
#define Z 2

#define CROSS(dest,v1,v2) \
          dest[0]=v1[1]*v2[2]-v1[2]*v2[1]; \
          dest[1]=v1[2]*v2[0]-v1[0]*v2[2]; \
          dest[2]=v1[0]*v2[1]-v1[1]*v2[0]; 

#define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

#define SUB(dest,v1,v2) \
          dest[0]=v1[0]-v2[0]; \
          dest[1]=v1[1]-v2[1]; \
          dest[2]=v1[2]-v2[2]; 

#define FINDMINMAX(x0,x1,x2,min,max) \
  min = max = x0;   \
  if(x1<min) min=x1;\
  if(x1>max) max=x1;\
  if(x2<min) min=x2;\
  if(x2>max) max=x2;

static int planeBoxOverlap(const float *normal, float d, const float *maxbox)
{
  int q;
  float vmin[3],vmax[3];
  for(q=X;q<=Z;q++)
  {
    if(normal[q]>0.0f)
    {
      vmin[q]=-maxbox[q];
      vmax[q]=maxbox[q];
    }
    else
    {
      vmin[q]=maxbox[q];
      vmax[q]=-maxbox[q];
    }
  }
  if(DOT(normal,vmin)+d>0.0f) return 0;
  if(DOT(normal,vmax)+d>=0.0f) return 1;
  
  return 0;
}


/*======================== X-tests ========================*/
#define AXISTEST_X01(a, b, fa, fb)			   \
	p0 = a*v0[Y] - b*v0[Z];			       	   \
	p2 = a*v2[Y] - b*v2[Z];			       	   \
        if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
	rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

#define AXISTEST_X2(a, b, fa, fb)			   \
	p0 = a*v0[Y] - b*v0[Z];			           \
	p1 = a*v1[Y] - b*v1[Z];			       	   \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
	rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

/*======================== Y-tests ========================*/
#define AXISTEST_Y02(a, b, fa, fb)			   \
	p0 = -a*v0[X] + b*v0[Z];		      	   \
	p2 = -a*v2[X] + b*v2[Z];	       	       	   \
        if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

#define AXISTEST_Y1(a, b, fa, fb)			   \
	p0 = -a*v0[X] + b*v0[Z];		      	   \
	p1 = -a*v1[X] + b*v1[Z];	     	       	   \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

/*======================== Z-tests ========================*/

#define AXISTEST_Z12(a, b, fa, fb)			   \
	p1 = a*v1[X] - b*v1[Y];			           \
	p2 = a*v2[X] - b*v2[Y];			       	   \
        if(p2<p1) {min=p2; max=p1;} else {min=p1; max=p2;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
	if(min>rad || max<-rad) return 0;

#define AXISTEST_Z0(a, b, fa, fb)			   \
	p0 = a*v0[X] - b*v0[Y];				   \
	p1 = a*v1[X] - b*v1[Y];			           \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
	if(min>rad || max<-rad) return 0;

static int triBoxOverlap(const float *boxcenter, const float *boxhalfsize, const Vec3f *triverts)
{

  /*    use separating axis theorem to test overlap between triangle and box */
  /*    need to test for overlap in these directions: */
  /*    1) the {x,y,z}-directions (actually, since we use the AABB of the triangle */
  /*       we do not even need to test these) */
  /*    2) normal of the triangle */
  /*    3) crossproduct(edge from tri, {x,y,z}-directin) */
  /*       this gives 3x3=9 more tests */
   float v0[3],v1[3],v2[3];
   //float axis[3];
   float min,max,d,p0,p1,p2,rad,fex,fey,fez;  
   float normal[3],e0[3],e1[3],e2[3];

   /* This is the fastest branch on Sun */
   /* move everything so that the boxcenter is in (0,0,0) */
   SUB(v0,triverts[0],boxcenter);
   SUB(v1,triverts[1],boxcenter);
   SUB(v2,triverts[2],boxcenter);

   /* compute triangle edges */
   SUB(e0,v1,v0);      /* tri edge 0 */
   SUB(e1,v2,v1);      /* tri edge 1 */
   SUB(e2,v0,v2);      /* tri edge 2 */

   /* Bullet 3:  */
   /*  test the 9 tests first (this was faster) */
   fex = fabsf(e0[X]);
   fey = fabsf(e0[Y]);
   fez = fabsf(e0[Z]);
   AXISTEST_X01(e0[Z], e0[Y], fez, fey);
   AXISTEST_Y02(e0[Z], e0[X], fez, fex);
   AXISTEST_Z12(e0[Y], e0[X], fey, fex);

   fex = fabsf(e1[X]);
   fey = fabsf(e1[Y]);
   fez = fabsf(e1[Z]);
   AXISTEST_X01(e1[Z], e1[Y], fez, fey);
   AXISTEST_Y02(e1[Z], e1[X], fez, fex);
   AXISTEST_Z0(e1[Y], e1[X], fey, fex);

   fex = fabsf(e2[X]);
   fey = fabsf(e2[Y]);
   fez = fabsf(e2[Z]);
   AXISTEST_X2(e2[Z], e2[Y], fez, fey);
   AXISTEST_Y1(e2[Z], e2[X], fez, fex);
   AXISTEST_Z12(e2[Y], e2[X], fey, fex);

   /* Bullet 1: */
   /*  first test overlap in the {x,y,z}-directions */
   /*  find min, max of the triangle each direction, and test for overlap in */
   /*  that direction -- this is equivalent to testing a minimal AABB around */
   /*  the triangle against the AABB */

   /* test in X-direction */
   FINDMINMAX(v0[X],v1[X],v2[X],min,max);
   if(min>boxhalfsize[X] || max<-boxhalfsize[X]) return 0;

   /* test in Y-direction */
   FINDMINMAX(v0[Y],v1[Y],v2[Y],min,max);
   if(min>boxhalfsize[Y] || max<-boxhalfsize[Y]) return 0;

   /* test in Z-direction */
   FINDMINMAX(v0[Z],v1[Z],v2[Z],min,max);
   if(min>boxhalfsize[Z] || max<-boxhalfsize[Z]) return 0;

   /* Bullet 2: */
   /*  test if the box intersects the plane of the triangle */
   /*  compute plane equation of triangle: normal*x+d=0 */
   CROSS(normal,e0,e1);
   d=-DOT(normal,v0);  /* plane eq: normal.x+d=0 */
   if(!planeBoxOverlap(normal,d,boxhalfsize)) return 0;

   return 1;   /* box and triangle overlaps */
}

bool testIntersectionTriBox(const Vec3f *_pts, const Box &_box)
{
	//float pt[3][3];
/*
	pt[0][0] = _pts[0].x;	pt[0][1] = _pts[0].y;	pt[0][2] = _pts[0].z;
	pt[1][0] = _pts[1].x;	pt[1][1] = _pts[1].y;	pt[1][2] = _pts[1].z;
	pt[2][0] = _pts[2].x;	pt[2][1] = _pts[2].y;	pt[2][2] = _pts[2].z;
*/
	int res = triBoxOverlap(&_box.center.x, &_box.extent.x, _pts);
	if (res == 1)
		return true;

	return false;
}


bool testIntersectionTriBox(const Polygon &_tri, const Vec3f *_pnts, const Box &_box)
{
	Vec3f pts[3];
	for (int i = 0;  i< 3; i++) {
		int ivert = _tri.getIndex(i);
		pts[i] = _pnts[ivert];
	}
	return testIntersectionTriBox(pts, _box);
}


bool testIntersectionTriOBB(const Polygon &_tri, const Vec3f *_pnts, const OBB &_obb)
{
	Matrix mat, invMat;
//	mat = _obb.matrix;
	mat.identity();
	mat.recopyFrom3x3(_obb.matrix);
//	D3DXMatrixInverse(&invMat, NULL, &mat);



	Vec3f pts[3];
	for (int i = 0; i < 3; i++) {
		int ivert = _tri.getIndex(i);
		Vec3f pt = _pnts[ivert];
		pt -= _obb.center;

		Vec3f tr = invMat.mul(pt);
		pts[i] = tr;
	}

	Box box;
	box.center = ZEROVEC3F;
	box.extent = _obb.extent;

	return testIntersectionTriBox(pts, box);
}


static void projectTriangle(const Vec3f &rkD,
							const Vec3f *apkTri[3],
							float &rfMin, float &rfMax)
{
	rfMin = rkD.dot(*apkTri[0]);
	rfMax = rfMin;

	float fDot = rkD.dot(*apkTri[1]);
	if ( fDot < rfMin )
		rfMin = fDot;
	else if ( fDot > rfMax )
		rfMax = fDot;

	fDot = rkD.dot(*apkTri[2]);
	if ( fDot < rfMin )
		rfMin = fDot;
	else if ( fDot > rfMax )
		rfMax = fDot;
}

static void projectBox(const Vec3f &rkD,
					   const Box &rkBox,
					   float &rfMin,
					   float &rfMax)
{
	float fDdC = rkD.dot(rkBox.center);
	float fR =
		rkBox.extent.x * fabsf(rkD.x) +
		rkBox.extent.y * fabsf(rkD.y) +
		rkBox.extent.z * fabsf(rkD.z);
	rfMin = fDdC - fR;
	rfMax = fDdC + fR;
}

bool magic_testIntersectionTriBox(const Vec3f *apkTri[3], const Box &rkBox)
{
	float fMin0, fMax0, fMin1, fMax1;
	Vec3f kD, akE[3];

	// test direction of triangle normal
	akE[0] = (*apkTri[1]) - (*apkTri[0]);
	akE[1] = (*apkTri[2]) - (*apkTri[0]);
	kD = akE[0] | akE[1];
	fMin0 = kD.dot(*apkTri[0]);
	fMax0 = fMin0;
	projectBox(kD, rkBox, fMin1, fMax1);
	if ( fMax1 < fMin0 || fMax0 < fMin1 )
		return false;

	// test direction of box faces
	for (int i = 0; i < 3; i++) {
		if (i == 0) kD = Vec3f(1, 0, 0);
		else if (i == 1) kD = Vec3f(0, 1, 0);
		else kD = Vec3f(0, 0, 1);

		projectTriangle(kD, apkTri, fMin0, fMax0);
		float fDdC = kD.dot(rkBox.center);
		fMin1 = fDdC - rkBox.ext(i);
		fMax1 = fDdC + rkBox.ext(i);
		if (fMax1 < fMin0 || fMax0 < fMin1)
			return false;
	}

	// test direction of triangle-box edge cross products
	akE[2] = akE[1] - akE[0];
	for (int i0 = 0; i0 < 3; i0++) {
		for (int i1 = 0; i1 < 3; i1++) {
			if (i1 == 0) kD = akE[i0] | Vec3f(1, 0, 0);
			else if (i1 == 1) kD = akE[i0] | Vec3f(0, 1, 0);
			else kD = akE[i0] | Vec3f(0, 0, 1);
			projectTriangle(kD, apkTri, fMin0, fMax0);
			projectBox(kD, rkBox, fMin1,fMax1);
			if (fMax1 < fMin0 || fMax0 < fMin1)
				return false;
		}
	}
    return true;
}

static bool noIntersect (float fTMax,
						 float fSpeed,
						 float fMin0,
						 float fMax0,
						 float fMin1,
						 float fMax1,
						 float &rfTFirst,
						 float &rfTLast)
{
	float fInvSpeed, fT;

	if (fMax1 < fMin0) {  // C1 initially on left of C0
		if (fSpeed <= 0.0f) {
			// intervals moving apart
			return true;
		}

		fInvSpeed = 1.0f / fSpeed;

		fT = (fMin0 - fMax1) * fInvSpeed;
		if (fT > rfTFirst)
			rfTFirst = fT;
		if (rfTFirst > fTMax)
			return true;

		fT = (fMax0 - fMin1) * fInvSpeed;
		if (fT < rfTLast)
			rfTLast = fT;
		if (rfTFirst > rfTLast)
			return true;
	}
	else if (fMax0 < fMin1) {  // C1 initially on right of C0
		if (fSpeed >= 0.0f) {
			// intervals moving apart
            return true;
		}

		fInvSpeed = 1.0f / fSpeed;

		fT = (fMax0 - fMin1) * fInvSpeed;
		if (fT > rfTFirst)
			rfTFirst = fT;
		if (rfTFirst > fTMax)
			return true;

		fT = (fMin0 - fMax1) * fInvSpeed;
		if (fT < rfTLast)
			rfTLast = fT;
		if (rfTFirst > rfTLast)
			return true;
	}
	else {  // C0 and C1 overlap
		if (fSpeed > 0.0f) {
			fT = (fMax0 - fMin1) / fSpeed;
			if (fT < rfTLast)
				rfTLast = fT;
			if (rfTFirst > rfTLast)
				return true;
		}
		else if (fSpeed < 0.0f) {
			fT = (fMin0 - fMax1) / fSpeed;
			if (fT < rfTLast)
				rfTLast = fT;
			if (rfTFirst > rfTLast)
				return true;
		}
	}

    return false;
}

bool magic_testIntersectionTriBox(const Vec3f *apkTri[3],
									const Box &rkBox,
									const Vec3f &rkBoxVel,
									float fTMax,
									float &rfTFirst,
									float &rfTLast)
{
	float fMin0, fMax0, fMin1, fMax1, fSpeed;
	Vec3f kD, akE[3];

	Vec3f kW = rkBoxVel;
	rfTFirst = 0.0f;
	rfTLast = FLT_MAX;

	// test direction of triangle normal
	akE[0] = (*apkTri[1]) - (*apkTri[0]);
	akE[1] = (*apkTri[2]) - (*apkTri[0]);
	kD = akE[0] | akE[1];
	fMin0 = kD.dot(*apkTri[0]);
	fMax0 = fMin0;
	projectBox(kD, rkBox, fMin1, fMax1);
	fSpeed = kD.dot(kW);
	if (noIntersect(fTMax, fSpeed, fMin0, fMax0, fMin1, fMax1, rfTFirst, rfTLast))
		return false;

	// test direction of box faces
	for (int i = 0; i < 3; i++) {
		if (i == 0) kD = Vec3f(1, 0, 0);
		else if (i == 1) kD = Vec3f(0, 1, 0);
		else kD = Vec3f(0, 0, 1);

		projectTriangle(kD, apkTri, fMin0, fMax0);
		float fDdC = kD.dot(rkBox.center);
		fMin1 = fDdC - rkBox.ext(i);
		fMax1 = fDdC + rkBox.ext(i);
		fSpeed = kD.dot(kW);
		if (noIntersect(fTMax, fSpeed, fMin0, fMax0, fMin1, fMax1, rfTFirst, rfTLast) )
            return false;
    }

	// test direction of triangle-box edge cross products
	akE[2] = akE[1] - akE[0];
	for (int i0 = 0; i0 < 3; i0++) {
		for (int i1 = 0; i1 < 3; i1++) {
			if (i1 == 0) kD = akE[i0] | Vec3f(1, 0, 0);
			else if (i1 == 1) kD = akE[i0] | Vec3f(0, 1, 0);
			else kD = akE[i0] | Vec3f(0, 0, 1);

			projectTriangle(kD, apkTri, fMin0, fMax0);
			projectBox(kD, rkBox, fMin1, fMax1);
			fSpeed = kD.dot(kW);
			if (noIntersect(fTMax, fSpeed, fMin0, fMax0, fMin1, fMax1, rfTFirst, rfTLast) )
				return false;
		}
	}

	return true;
}



OZCOLLIDE_API bool testIntersectionTriBox(const Vec3f *_triPts[3],
										 const Vec3f &_triNormal,
										 const Box &_box,
										 const Vec3f &_boxVel,
										 float &_distTravel,
										 Vec3f &_reaction)
{
	int i, j;
	float d0, d1;
	float t;

	Plane tri_plane;
	tri_plane.fromPointAndNormal(*_triPts[0], _triNormal);

	Vec3f n_boxvel = _boxVel;
	n_boxvel.normalize();

	if (_triNormal.dot(n_boxvel) > 0)
		return false;

	float minDist = FLT_MAX;
	int col = -1;

	// box vertices VS triangle
	for (i = 0; i < 8; i++) {
		Vec3f box_vertex = _box.getPoint(i);

		Vec3f box_vertex_normal = _box.getVertexNormal(i);
		if (box_vertex_normal.dot(n_boxvel) < -OZ_COS45)
			continue;

		float t;
		if (!tri_plane.intersectWithLine(box_vertex, box_vertex + n_boxvel, t) )
			continue;

		if (t >= minDist)
			continue;
		if (t < 0)
			continue;

		Vec3f inter;
		inter = box_vertex + n_boxvel * t;

		if (!isPointInsideTriangle(*_triPts[0], *_triPts[1], *_triPts[2], inter))
			continue;

		minDist = t;
		_reaction = _triNormal;
		col = 0;
	}

	// triangle vertices VS box faces
	for (i = 0; i < 3; i++) {
		float tnear, tfar;
		PLANE plane = intersectRayBox(*_triPts[i], -n_boxvel, _box, tnear, tfar);
		if (plane == -1)
			continue;

		if (tnear < 0)
			continue;

		if (tnear < minDist) {
			minDist = tnear;
			_reaction = -_box.getFaceNormal(plane);
			col = 1;
		}
	}

	// box edges VS triangle edges
	for (i = 0; i < 12; i++) {
		BoxEdge boxEdge = _box.getEdge(i);
		Plane boxEdgePlane;
		boxEdgePlane.fromPoints(boxEdge.p1, boxEdge.p0, boxEdge.p0 + _boxVel);

		Vec3f boxEdgeNormal = Vec3f(boxEdgePlane.a, boxEdgePlane.b, boxEdgePlane.c);

		Vec3f v0 = boxEdge.p1 - boxEdge.p0;

		for (j = 0; j < 3; j++) {
			const Vec3f *tpt0;
			const Vec3f *tpt1;
			tpt0 = _triPts[j];
			if (j < 2) tpt1 = _triPts[j + 1];
			else tpt1 = _triPts[0];

			d0 = boxEdgePlane.dist(*tpt0);
			d1 = boxEdgePlane.dist(*tpt1);
			if (d0 * d1 > 0)
				continue;

			if (!boxEdgePlane.intersectWithLine(*tpt0, *tpt1, t))
				continue;

			Vec3f v1 = *tpt1 - *tpt0;
			Vec3f ipt = *tpt0 + v1 * t;

			int a0 = 0, a1 = 1;
			float pl_x = fabsf(boxEdgePlane.a);
			float pl_y = fabsf(boxEdgePlane.b);
			float pl_z = fabsf(boxEdgePlane.c);
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

			float dist = v0[a0] * (ipt[a1] - boxEdge.p0[a1]) - v0[a1] * (ipt[a0] - boxEdge.p0[a0]);
			float denom = v0[a1] * -n_boxvel[a0] - v0[a0] * -n_boxvel[a1];
			if (!denom)
				continue;
			dist /= denom;

			if (dist < 0)
				continue;

			ipt -= dist * n_boxvel;

			Vec3f r1 = boxEdge.p0 - ipt;
			Vec3f r2 = boxEdge.p1 - ipt;
			if (r1.dot(r2) > 0)
				continue;

			if (dist < minDist) {
				minDist = dist;
				_reaction = v0 | v1;
				_reaction.normalize();
				if (_reaction.dot(n_boxvel) > 0)
					_reaction = -_reaction;
				col = 2;
			}
		}
	}

	if (col == -1)
		return false;

	_distTravel = minDist;

	return true;
}

LEAVE_NAMESPACE
