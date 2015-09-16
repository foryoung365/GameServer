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
#include <ozcollide/aabbtree_aabb.h>
#include <ozcollide/dataio.h>
#endif

#include "aabbtreeaabb_io.cpp"

ENTER_NAMESPACE_OZCOLLIDE

AABBTreeAABB::AABBTreeAABB(int _leafDepth) : AABBTree(AABBTREE_LEAFTYPE_AABB, _leafDepth)
{
}

AABBTreeAABB::~AABBTreeAABB()
{
}

int AABBTreeAABB::getMemoryConsumption() const
{
	int size = 0;
	size += getNbNodes() * sizeof(AABBTreeNode);
	size += getNbLeafs() * sizeof(AABBTreeAABBLeaf);

	size += sizeof *this;

	return size;
}

// BOX

bool AABBTreeAABB::isCollideWithBox(const Box &_box)
{
	nbColls_ = 0;
	box_ = _box;
	colRes_ = NULL;
	return isCollideWithBox(*root_);
}

bool AABBTreeAABB::isCollideWithBox(const Box &_box, BoxColResult &_cr)
{
	if (bUseTemporalCoherence_ && _cr.boxes_.size() != 0) {
		if (_box.isOverlap(*_cr.boxes_[0])) {
			nbColls_ = 1;
			return true;
		}
	}

	colRes_ = &_cr;
	colRes_->boxQuery_ = _box;
	colRes_->boxes_.resize(0);
	return isCollideWithBox(*root_);
}

void AABBTreeAABB::collideWithBox(const Box &_box, BoxColResult &_cr)
{
	if (bUseTemporalCoherence_ == true) {
		if (_box.isInside(_cr.boxQuery_)) {
			nbColls_ = _cr.boxes_.size();
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
	colRes_ = &_cr;
	_cr.boxes_.resize(0);
	nbColls_ = 0;

	collideWithBox(*root_);
}

void AABBTreeAABB::collideWithBox(const Box &_box, AABBCDAABB_callback *_callback, void *_userCallback)
{
	if (!_callback)
		return;
	callback_ = _callback;
	userCallback_ = _userCallback;
	colRes_ = NULL;
	nbColls_ = 0;
	box_ = _box;
	collideWithBox(*root_);
}

// BOX

bool AABBTreeAABB::isCollideWithBox(const AABBTreeNode &_node)
{
	if (_node.aabb.isOverlap(box_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreeAABBLeaf &bl = (AABBTreeAABBLeaf&) _node;
			int nbBoxes = bl.nbBoxes;
			for (int i = 0; i < nbBoxes; i++) {
				const Box &b = bl.boxes[i];
				bool res = box_.isOverlap(b);
				if (res == true) {
					nbColls_++;
					if (colRes_)
						colRes_->boxes_.add(&b);
				}
				return res;
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

void AABBTreeAABB::collideWithBox(const AABBTreeNode &_node)
{
	if (_node.aabb.isOverlap(box_) == true) {
		if (!_node.left && !_node.right) {
			// reach a leaf
			const AABBTreeAABBLeaf &bl = (AABBTreeAABBLeaf&) _node;
			int nbBoxes = bl.nbBoxes;
			for (int i = 0; i < nbBoxes; i++) {
				const Box &b = bl.boxes[i];
				bool res = box_.isOverlap(b);
				if (res == true) {
					nbColls_++;
					if (callback_)
						callback_(*this, b, _node.aabb, userCallback_);
					else
						colRes_->boxes_.add(&b);
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

void AABBTreeAABB::scale(float _scale)
{
	int i, j;

	for (i = 0; i < nbNodes_; i++) {
		AABBTreeNode *node = &root_[i];
		node->aabb.center *= _scale;
		node->aabb.extent *= _scale;
	}
	
	for (i = 0; i < nbLeafs_; i++) {
		AABBTreeAABBLeaf *leaf = &leafs_[i];
		leaf->aabb.center *= _scale;
		leaf->aabb.extent *= _scale;
		for (j = 0; j < leaf->nbBoxes; j++) {
			((Vec3f) leaf->boxes[j].center) *= _scale;
			((Vec3f) leaf->boxes[j].extent) *= _scale;
		}
	}
}

AABBTreeAABBLeaf::AABBTreeAABBLeaf()
{
	nbBoxes = 0;
	boxes = NULL;
	users = 0;
}

LEAVE_NAMESPACE
