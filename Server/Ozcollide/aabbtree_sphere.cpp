/*
OZCollide - Collision Detection Library
Copyright (C) 2006  Igor Kravtchenko

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
#include <ozcollide/aabbtree_sphere.h>
#include <ozcollide/intr_frustumsphere.h>
#include <ozcollide/intr_spherebox.h>
#include <ozcollide/dataio.h>
#endif

#include "aabbtreesphere_io.cpp"

ENTER_NAMESPACE_OZCOLLIDE

AABBTreeSphere::AABBTreeSphere(int _leafDepth) : AABBTree(AABBTREE_LEAFTYPE_SPHERE, _leafDepth)
{
}

AABBTreeSphere::~AABBTreeSphere()
{
}

int AABBTreeSphere::getMemoryConsumption() const
{
	int size = 0;
	size += getNbNodes() * sizeof(AABBTreeNode);
	size += getNbLeafs() * sizeof(AABBTreeSphereLeaf);
	size += sizeof *this;
	return size;
}

// FRUSTUM

void AABBTreeSphere::collideWithFrustum(const Frustum &_frustum,
										AABBCDSphere_callback *_callback,
										void *_userCallback)
{
	if (!_callback)
		return;
	callback_ = _callback;
	userCallback_ = _userCallback;
	nbColls_ = 0;
	frustum_ = _frustum;
	collideWithFrustum(*root_);
}

void AABBTreeSphere::collideWithFrustum(const AABBTreeNode &_node)
{
	float high = _node.aabb.getMaxExtent();
	Sphere s;
	s.center = _node.aabb.center;
	s.radius = high;
	if (testIntersectionFrustumSphere(frustum_, s) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreeSphereLeaf &sl = (AABBTreeSphereLeaf&) _node;
			int nbSpheres = sl.nbSpheres;
			for (int i = 0; i < nbSpheres; i++) {
				nbColls_++;
				const Sphere &s = sl.spheres[i];
				int user = 0; 
				if (sl.users)
					user = sl.users[i];

				bool res = testIntersectionFrustumSphere(frustum_, s);
				if (res == true) {
					if (callback_)
						callback_(*this, s, user, _node.aabb, userCallback_);
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


// BOX

bool AABBTreeSphere::isCollideWithBox(const Box &_box)
{
	nbColls_ = 0;
	box_ = _box;
	return isCollideWithBox(*root_);
}

void AABBTreeSphere::collideWithBox(const Box &_box, AABBCDSphere_callback *_callback, void *_userCallback)
{
	if (!_callback)
		return;
	callback_ = _callback;
	userCallback_ = _userCallback;
	nbColls_ = 0;
	box_ = _box;
	collideWithBox(*root_);
}

// BOX

bool AABBTreeSphere::isCollideWithBox(const AABBTreeNode &_node)
{
	if (_node.aabb.isOverlap(box_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreeSphereLeaf &pl = (AABBTreeSphereLeaf&) _node;
			int nbSpheres = pl.nbSpheres;
			for (int i = 0; i < nbSpheres; i++) {
				nbColls_++;
				const Sphere &s = pl.spheres[i];
				return testIntersectionSphereBox(s, box_);
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

void AABBTreeSphere::collideWithBox(const AABBTreeNode &_node)
{
	if (_node.aabb.isOverlap(box_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreeSphereLeaf &sl = (AABBTreeSphereLeaf&) _node;
			int nbSpheres = sl.nbSpheres;
			for (int i = 0; i < nbSpheres; i++) {
				nbColls_++;
				const Sphere &s = sl.spheres[i];
				int user = 0;
				if (sl.users[i])
					user = sl.users[i];
				bool res = testIntersectionSphereBox(s, box_);
				if (res == true)
					callback_(*this, s, user, _node.aabb, userCallback_);
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

void AABBTreeSphere::scale(float _scale)
{
	int i, j;

	for (i = 0; i < nbNodes_; i++) {
		AABBTreeNode *node = &root_[i];
		node->aabb.center *= _scale;
		node->aabb.extent *= _scale;
	}

	for (i = 0; i < nbLeafs_; i++) {
		AABBTreeSphereLeaf *leaf = &leafs_[i];
		for (j = 0; j < leaf->nbSpheres; j++) {
			Sphere *sphere = (Sphere*) &leaf->spheres[j];
			sphere->center *= _scale;
			sphere->radius *= _scale;
		}
	}
}

LEAVE_NAMESPACE
