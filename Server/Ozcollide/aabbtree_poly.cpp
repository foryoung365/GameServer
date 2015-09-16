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
#include <ozcollide/aabbtree_poly.h>
#include <ozcollide/dataio.h>
#include <ozcollide/intr_boxbox.h>
#include <ozcollide/intr_spherebox.h>
#include <ozcollide/intr_tribox.h>
#include <ozcollide/intr_spheretri.h>
#include <ozcollide/intr_linebox.h>
#include <ozcollide/intr_segmenttri.h>
#endif

#include "aabbtreepoly_io.cpp"

ENTER_NAMESPACE_OZCOLLIDE

AABBTreePoly::AABBTreePoly(int _leafDepth) :
AABBTree(AABBTREE_LEAFTYPE_POLYGON, _leafDepth)
{
	points_ = NULL;
	leafs_ = NULL;
	bufEdges_ = NULL;
	offBufEdges_ = 0;
	bufPols_ = NULL;
	offBufPols_ = 0;
}

AABBTreePoly::~AABBTreePoly()
{
	SAFE_ARRAYDELETE(points_);
	SAFE_ARRAYDELETE(leafs_);
}

void AABBTreePoly::final()
{
	int i, j;

	for (i = 0; i < nbLeafs_; i++) {
		AABBTreePolygonLeaf *leaf = &leafs_[i];
		for (j = 0; j < leaf->nbPolys; j++) {
			Polygon &pol = (Polygon&) leaf->polys[j];

			int rel1 = pol.getIndex(0);
			int rel2 = pol.getIndex(1);
			int rel3 = pol.getIndex(pol.getNbIndices() - 1);

			Vec3f vec1 = points_[rel2] - points_[rel1];
			Vec3f vec2 = points_[rel3] - points_[rel1];
			Vec3f normal = vec1 | vec2;
			normal.normalize();
			pol.setNormal(normal);
		}
	}
}

int AABBTreePoly::getNbPoints() const
{
	return nbPoints_;
}

const Vec3f* AABBTreePoly::getPointsList() const
{
	return points_;
}

int AABBTreePoly::getMemoryConsumption() const
{
	int size = 0;
	size += getNbNodes() * sizeof(AABBTreeNode);
	size += getNbLeafs() * sizeof(AABBTreePolygonLeaf);

	int t = sizeof *points_;
	size += nbPoints_ * t;

	size += sizeof *this;

	return size;
}

// BOX

bool AABBTreePoly::isCollideWithBox(const Box &_box)
{
	nbColls_ = 0;
	box_ = _box;
	boxColRes_ = NULL;
	return isCollideWithBox(*root_);
}

bool AABBTreePoly::isCollideWithBox(const Box &_box, BoxColResult &_cr)
{
	if (bUseTemporalCoherence_ && _cr.polys_.size() != 0) {
		bool res = testIntersectionTriBox(*_cr.polys_[0], points_, _box);
		if (res == true) {
			nbColls_ = 1;
			return true;
		}
	}

	nbColls_ = 0;
	box_ = _box;

	boxColRes_ = &_cr;
	boxColRes_->boxQuery_ = _box;
	boxColRes_->polys_.resize(0);
	return isCollideWithBox(*root_);
}

void AABBTreePoly::collideWithBox(const Box &_box, BoxColResult &_cr)
{
	if (bUseTemporalCoherence_ == true) {
		if (_box.isInside(_cr.boxQuery_)) {
			nbColls_ = _cr.polys_.size();
			return;
		}

		// Too bad, will do normal query with an inflated volume
		box_ = _box;
		box_.extent *= coefVolInflater_;
	}
	else {
		box_ = _box;
	}

	_cr.boxQuery_ = box_;
	callback_ = NULL;
	boxColRes_ = &_cr;
	_cr.polys_.resize(0);
	nbColls_ = 0;

	collideWithBox(*root_);
}

void AABBTreePoly::collideWithBox(const Box &_box,
								  AABBCDPoly_callback *_callback,
								  void *_userCallback)
{
	if (!_callback)
		return;
	callback_ = _callback;
	userCallback_ = _userCallback;
	boxColRes_ = NULL;
	nbColls_ = 0;
	box_ = _box;
	collideWithBox(*root_);
}


// OBB

bool AABBTreePoly::isCollideWithOBB(const OBB &_obb)
{
	nbColls_ = 0;
	obb_ = _obb;
	obbColRes_ = NULL;
	return isCollideWithOBB(*root_);
}

bool AABBTreePoly::isCollideWithOBB(const OBB &_obb, OBBColResult &_cr)
{
	/*
	if (bUseTemporalCoherence_ && cr.polys_.size() != 0) {
		ozbool res = testIntersectionTriBox(*cr.polys_[0], points_, box);
		if (res == OZTRUE) {
			nbColls_ = 1;
			return OZTRUE;
		}
	}
*/
	nbColls_ = 0;
	obb_ = _obb;

	obbColRes_ = &_cr;
	obbColRes_->obbQuery_ = _obb;
	obbColRes_->polys_.resize(0);
	return isCollideWithOBB(*root_);
}

void AABBTreePoly::collideWithOBB(const OBB &_obb, OBBColResult &_cr)
{
	/*
	if (bUseTemporalCoherence_ == OZTRUE) {
		if (box.isInside(cr.boxQuery_)) {
			nbColls_ = cr.polys_.size();
			return;
		}

		// Too bad, will do normal query with an inflated volume
		box_ = box;
		box_.extent *= coefVolInflater_;
	}
	else {
	*/
		obb_ = _obb;
//	}

	_cr.obbQuery_ = obb_;
	callback_ = NULL;
	obbColRes_ = &_cr;
	_cr.polys_.resize(0);
	nbColls_ = 0;

	collideWithOBB(*root_);
}

void AABBTreePoly::collideWithOBB(const OBB &_obb,
								  AABBCDPoly_callback *_callback,
								  void *_userCallback)
{
	if (!_callback)
		return;
	callback_ = _callback;
	userCallback_ = _userCallback;
	obbColRes_ = NULL;
	nbColls_ = 0;
	obb_ = _obb;
	collideWithBox(*root_);
}



// SPHERE

bool AABBTreePoly::isCollideWithSphere(const Sphere &_sphere)
{
	sphereColRes_ = NULL;
	nbColls_ = 0;
	sphere_ = _sphere;
	return isCollideWithSphere(*root_);
}

void AABBTreePoly::collideWithSphere(const Sphere &_sphere,
									 AABBCDPoly_callback *_callback,
									 void *_userCallback)
{
	if (!_callback)
		return;
	sphereColRes_ = NULL;
	callback_ = _callback;
	userCallback_ = _userCallback;
	nbColls_ = 0;
	sphere_ = _sphere;
	collideWithSphere(*root_);
}

void AABBTreePoly::collideWithSphere(const Sphere &_sphere, SphereColResult &_cr)
{
	if (bUseTemporalCoherence_ == true) {
		if (_sphere.isCollide(_cr.sphereQuery_)) {
			nbColls_ = _cr.polys_.size();
			return;
		}

		// Too bad, will do normal query with an inflated volume
		sphere_ = _sphere;
		sphere_.radius *= coefVolInflater_;
	}
	else {
		sphere_ = _sphere;
	}

	_cr.sphereQuery_ = sphere_;
	callback_ = NULL;
	sphereColRes_ = &_cr;
	_cr.polys_.resize(0);
	nbColls_ = 0;

	collideWithSphere(*root_);
}


// ELLIPSOID

bool AABBTreePoly::isCollideWithEllipsoid(const Ellipsoid &_ellip)
{
	ellipColRes_ = NULL;
	nbColls_ = 0;
	ellip_ = _ellip;
	return isCollideWithEllipsoid(*root_);
}

void AABBTreePoly::collideWithEllipsoid(const Ellipsoid &_ellip,
										AABBCDPoly_callback *_callback,
										void *_userCallback)
{
	if (!_callback)
		return;
	ellipColRes_ = NULL;
	callback_ = _callback;
	userCallback_ = _userCallback;
	nbColls_ = 0;
	ellip_ = _ellip;
	collideWithEllipsoid(*root_);
}

void AABBTreePoly::collideWithEllipsoid(const Ellipsoid &_ellip, EllipsoidColResult &_cr)
{
//	if (bUseTemporalCoherence_ == OZTRUE) {
//		if (sphere.isCollide(cr.sphereQuery_)) {
//			nbColls_ = cr.polys_.size();
//			return;
//		}

		// Too bad, will do normal query with an inflated volume
//		sphere_ = sphere;
//		sphere_.radius *= coefVolInflater_;
//	}
//	else {
		ellip_ = _ellip;
//		sphere_.center = ellip.pos;
//		sphere_.radius = ellip.radii.x;
//	}

//	invRadii_.x = 1.0f / ellip.radii.x;
//	invRadii_.y = 1.0f / ellip.radii.y;
//	invRadii_.z = 1.0f / ellip.radii.z;

	_cr.ellipsoidQuery_ = ellip_;
	callback_ = NULL;
	ellipColRes_ = &_cr;
	_cr.polys_.resize(0);
	nbColls_ = 0;

	collideWithEllipsoid(*root_);
}


// SEGMENT

bool AABBTreePoly::isCollideWithSegment(const Vec3f &_seg_pt0,
										  const Vec3f &_seg_pt1)
{
	nbColls_ = 0;
	seg_pt0_ = _seg_pt0;
	seg_pt1_ = _seg_pt1;
	segmentColRes_ = NULL;
	return isCollideWithSegment(*root_);
}

bool AABBTreePoly::isCollideWithSegment(const Vec3f &_seg_pt0, const Vec3f &_seg_pt1,
										  SegmentColResult &_cr)
{
	nbColls_ = 0;
	seg_pt0_ = _seg_pt0;
	seg_pt1_ = _seg_pt1;

	segmentColRes_ = &_cr;
	segmentColRes_->segmentPt0_ = _seg_pt0;
	segmentColRes_->segmentPt1_ = _seg_pt1;
	segmentColRes_->polys_.resize(0);
	return isCollideWithSegment(*root_);
}

void AABBTreePoly::collideWithSegment(const Vec3f &seg_pt0,
									  const Vec3f &seg_pt1,
									  AABBCDPoly_callback *callback,
									  void *userCallback)
{
	if (!callback)
		return;
	segmentColRes_ = NULL;
	callback_ = callback;
	userCallback_ = userCallback;
	nbColls_ = 0;
	seg_pt0_ = seg_pt0;
	seg_pt1_ = seg_pt1;
	collideWithSegment(*root_);
}

void AABBTreePoly::collideWithSegment(const Vec3f &seg_pt0,
									  const Vec3f &seg_pt1,
									  SegmentColResult &cr)
{
	cr.segmentPt0_ = seg_pt0;
	cr.segmentPt1_ = seg_pt1;
	seg_pt0_ = seg_pt0;
	seg_pt1_ = seg_pt1;
	callback_ = NULL;
	segmentColRes_ = &cr;
	cr.polys_.resize(0);
	nbColls_ = 0;
	collideWithSegment(*root_);
}

//

int AABBTreePoly::getNbCollidedPrimitives() const
{
	return nbColls_;
}

//
//
// BOX

bool AABBTreePoly::isCollideWithBox(const AABBTreeNode &_node)
{
	if (_node.aabb.isOverlap(box_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				bool res = testIntersectionTriBox(*pol, points_, box_);
				if (res) {
					nbColls_++;
					if (boxColRes_) {
						int user = 0;
						if (pl.users)
							user = pl.users[i];
						boxColRes_->polys_.add( pol );
						boxColRes_->users_.add( user );
					}
					return res;
				}
			}
		}
		else {
			if (_node.left) {
				if (isCollideWithBox(*_node.left) == true)
					return true;
			}
			if (_node.right) {
				if (isCollideWithBox(*_node.right) == true)
					return true;
			}
		}
	}
	return false;
}

void AABBTreePoly::collideWithBox(const AABBTreeNode &_node)
{
	if (_node.aabb.isOverlap(box_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int user = 0;
				if (pl.users)
					user = pl.users[i];
				bool res = testIntersectionTriBox(*pol, points_, box_);
				if (res == true) {
					nbColls_++;
					if (callback_)
						callback_(*this, *pol, user, _node.aabb, userCallback_);
					else {
						boxColRes_->polys_.add(pol);
						boxColRes_->users_.add(user);
					}
				}
			}
		}
		else {
			if (_node.left)
				collideWithBox(*_node.left);
			if (_node.right)
				collideWithBox(*_node.right);
		}
	}
}



//
//
// OBB

bool AABBTreePoly::isCollideWithOBB(const AABBTreeNode &_node)
{
	if (testIntersectionAABB_OBB(_node.aabb, obb_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				bool res = testIntersectionTriOBB(*pol, points_, obb_);
				if (res) {
					nbColls_++;

					if (obbColRes_) {
						int user = 0;
						if (pl.users)
							user = pl.users[i];

						obbColRes_->polys_.add( pol );
						obbColRes_->users_.add( user );
					}
					return res;
				}
			}
		}
		else {
			if (_node.left) {
				if (isCollideWithOBB(*_node.left) == true)
					return true;
			}
			if (_node.right) {
				if (isCollideWithOBB(*_node.right) == true)
					return true;
			}
		}
	}
	return false;
}

void AABBTreePoly::collideWithOBB(const AABBTreeNode &_node)
{
	if (testIntersectionAABB_OBB(_node.aabb, obb_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int user = 0;
				if (user)
					user = pl.users[i];
				bool res = testIntersectionTriOBB(*pol, points_, obb_);
				if (res == true) {
					nbColls_++;
					if (callback_)
						callback_(*this, *pol, user, _node.aabb, userCallback_);
					else {
						obbColRes_->polys_.add(pol);
						obbColRes_->users_.add(user);
					}
				}
			}
		}
		else {
			if (_node.left)
				collideWithOBB(*_node.left);
			if (_node.right)
				collideWithOBB(*_node.right);
		}
	}
}

// SPHERE

bool AABBTreePoly::isCollideWithSphere(const AABBTreeNode &_node)
{
	if (testIntersectionSphereBox(sphere_, _node.aabb) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int i0 = pol->getIndex(0);
				int i1 = pol->getIndex(1);
				int i2 = pol->getIndex(2);
				bool res = magic_testIntersectionSphereTriangle(sphere_.center, sphere_.radius,
															points_[i0], points_[i1], points_[i2]);
				if (res) {
					if (sphereColRes_) {
						int user = 0;
						if (pl.users)
							user = pl.users[i];

						sphereColRes_->polys_.add( pol );
						sphereColRes_->users_.add( user );
					}
					nbColls_++;
					return res;
				}
			}
		}
		else {
			if (_node.left) {
				if (isCollideWithSphere(*_node.left) == true)
					return true;
			}
			if (_node.right) {
				if (isCollideWithSphere(*_node.right) == true)
					return true;
			}
		}
	}
	return false;
}

void AABBTreePoly::collideWithSphere(const AABBTreeNode &_node)
{
	if (testIntersectionSphereBox(sphere_, _node.aabb) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int user = 0;
				if (user)
					user = pl.users[i];
				int i0 = pol->getIndex(0);
				int i1 = pol->getIndex(1);
				int i2 = pol->getIndex(2);
				bool res = magic_testIntersectionSphereTriangle(	sphere_.center, sphere_.radius,
																	points_[i0], points_[i1], points_[i2]);
				if (res) {
					nbColls_++;
					if (callback_)
						callback_(*this, *pol, user, _node.aabb, userCallback_);
					else {
						sphereColRes_->polys_.add(pol);
						sphereColRes_->users_.add(user);
					}
				}
			}
		}
		else {
			if (_node.left)
				collideWithSphere(*_node.left);
			if (_node.right)
				collideWithSphere(*_node.right);
		}
	}
}


// ELLIPSOID

bool AABBTreePoly::isCollideWithEllipsoid(const AABBTreeNode &_node)
{
	if (testIntersectionEllipsoidBox(ellip_, _node.aabb) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int i0 = pol->getIndex(0);
				int i1 = pol->getIndex(1);
				int i2 = pol->getIndex(2);
				Vec3f pt1 = points_[i0] * ellip_.getInvRadii();
				Vec3f pt2 = points_[i1] * ellip_.getInvRadii();
				Vec3f pt3 = points_[i2] * ellip_.getInvRadii();
				Vec3f center = ellip_.getCenter() * ellip_.getInvRadii();
				bool res = magic_testIntersectionSphereTriangle(center, 1, pt1, pt2, pt3);
				if (res) {
					if (ellipColRes_) {
						int user = 0;
						if (pl.users)
							user = pl.users[i];

						ellipColRes_->polys_.add( pol );
						ellipColRes_->users_.add( user );
					}
					nbColls_++;
					return res;
				}
			}
		}
		else {
			if (_node.left) {
				if (isCollideWithEllipsoid(*_node.left) == true)
					return true;
			}
			if (_node.right) {
				if (isCollideWithEllipsoid(*_node.right) == true)
					return true;
			}
		}
	}
	return false;
}

void AABBTreePoly::collideWithEllipsoid(const AABBTreeNode &_node)
{
	if (testIntersectionEllipsoidBox(ellip_, _node.aabb) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int user = 0;
				if (user)
					user = pl.users[i];

				int i0 = pol->getIndex(0);
				int i1 = pol->getIndex(1);
				int i2 = pol->getIndex(2);
				Vec3f pt1 = points_[i0] * ellip_.getInvRadii();
				Vec3f pt2 = points_[i1] * ellip_.getInvRadii();
				Vec3f pt3 = points_[i2] * ellip_.getInvRadii();
				Vec3f center = ellip_.getCenter() * ellip_.getInvRadii();
				bool res = magic_testIntersectionSphereTriangle(center, 1, pt1, pt2, pt3);
				if (res) {
					nbColls_++;

					if (callback_)
						callback_(*this, *pol, user, _node.aabb, userCallback_);
					else {
						ellipColRes_->polys_.add( pol );
						ellipColRes_->users_.add( user );
					}
				}
			}
		}
		else {
			if (_node.left)
				collideWithEllipsoid(*_node.left);
			if (_node.right)
				collideWithEllipsoid(*_node.right);
		}
	}
}

// SEGMENT

bool AABBTreePoly::isCollideWithSegment(const AABBTreeNode &_node)
{
	if (testIntersectionSegmentBox(seg_pt0_, seg_pt1_, _node.aabb) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int i0 = pol->getIndex(0);
				int i1 = pol->getIndex(1);
				int i2 = pol->getIndex(2);
				bool res = testIntersectionSegmentTri(seg_pt0_, seg_pt1_,
														points_[i0], points_[i1], points_[i2]);
				if (res) {
					nbColls_++;
					if (segmentColRes_) {
						int user = 0;
						if (pl.users)
							user = pl.users[i];

						segmentColRes_->polys_.add( pol );
						segmentColRes_->users_.add( user );
					}
					return res;
				}
			}
		}
		else {
			if (_node.left) {
				if (isCollideWithSegment(*_node.left) == true)
					return true;
			}
			if (_node.right) {
				if (isCollideWithSegment(*_node.right) == true)
					return true;
			}
		}
	}
	return false;
}

void AABBTreePoly::collideWithSegment(const AABBTreeNode &_node)
{
	if (testIntersectionSegmentBox(seg_pt0_, seg_pt1_, _node.aabb) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreePolygonLeaf &pl = (AABBTreePolygonLeaf&) _node;
			int nbPols = pl.nbPolys;
			for (int i = 0; i < nbPols; i++) {
				const Polygon *pol = &pl.polys[i];
				int user = 0;
				if (pl.users)
					user = pl.users[i];
				int i0 = pol->getIndex(0);
				int i1 = pol->getIndex(1);
				int i2 = pol->getIndex(2);
				bool res = testIntersectionSegmentTri(seg_pt0_, seg_pt1_,
														points_[i0], points_[i1], points_[i2]);
				if (res) {
					nbColls_++;

					if (callback_)
						callback_(*this, *pol, user, _node.aabb, userCallback_);
					else {
						segmentColRes_->polys_.add(pol);
						segmentColRes_->users_.add(user);
					}
				}
			}
		}
		else {
			if (_node.left)
				collideWithSegment(*_node.left);
			if (_node.right)
				collideWithSegment(*_node.right);
		}
	}
}

//

void AABBTreePoly::scale(float _scale)
{
	int i;
	int nbPoints = nbPoints_;
	for (i = 0; i < nbPoints; i++)
		points_[i] *= _scale;

	for (i = 0; i < nbNodes_; i++) {
		AABBTreeNode *node = &root_[i];
		node->aabb.center *= _scale;
		node->aabb.extent *= _scale;
	}

	for (i = 0; i < nbLeafs_; i++) {
		AABBTreePolygonLeaf *leaf = &leafs_[i];
		leaf->aabb.center *= _scale;
		leaf->aabb.extent *= _scale;
	}
}

LEAVE_NAMESPACE
