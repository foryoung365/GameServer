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
#include <ozcollide/aabbtreeaabb_builder.h>
#include <ozcollide/monitor.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

AABBTreeAABB_Builder::AABBTreeAABB_Builder()
{
}

AABBTreeAABB_Builder::~AABBTreeAABB_Builder()
{
}

AABBTreeAABB* AABBTreeAABB_Builder::buildFromList(int _nbBoxes,
												  const Box *_boxes,
												  int _leafDepth,
												  Monitor *_moni)
{
	int i, j;

	tree_ = new AABBTreeAABB(_leafDepth);

	// Build the root node

	WorkingItem *item = new WorkingItem();

	if (_moni)
		_moni->write("Building the root node");

	for (i = 0; i < _nbBoxes; i++)
		item->boxes.add(_boxes[i]);

	item->left = -1;
	item->right = -1;

	items_.add(item);

	int off = 0;
	while(true) {
		WorkingItem &it = *items_[off];
		workOnItem(it, _leafDepth);
		off++;
		int size = items_.size();
		if (off == size)
			break;
	}

	// Now we have a bastard working tree, let's build the final clean one...

	int *ln = new int[items_.size()];
	int nbNodes = 0;
	int nbLeafs = 0;
	for (i = 0; i < items_.size(); i++) {
		WorkingItem &it = *items_[i];
		if (it.left == -1 && it.right == -1)
			ln[i] = nbLeafs++;
		else
			ln[i] = nbNodes++;
	}
	tree_->root_ = new AABBTreeNode[nbNodes];
	tree_->leafs_ = new AABBTreeAABBLeaf[nbLeafs];
	tree_->nbNodes_ = nbNodes;
	tree_->nbLeafs_ = nbLeafs;

	if (_moni)
		_moni->write("Building the final clean tree");

	for (i = 0; i < items_.size(); i++) {
		if (_moni)
			_moni->setProgress(i, items_.size());

		WorkingItem &it = *items_[i];
		if (it.left == -1 && it.right == -1) {
			int indexLeaf = ln[i];
			AABBTreeAABBLeaf *bl = (AABBTreeAABBLeaf*) tree_->leafs_;
			bl += indexLeaf;
			bl->aabb = it.aabb;
			bl->left = NULL;
			bl->right = NULL;
			int nbBoxes = it.boxes.size();
			bl->nbBoxes = nbBoxes;
			bl->boxes = new Box[nbBoxes];
			for (j = 0; j < nbBoxes; j++) {
				Box *b = (Box*) &bl->boxes[j];
				*b = it.boxes[j];
			}
		}
		else {
			int nodeIndex = ln[i];
			AABBTreeNode *node = &tree_->root_[nodeIndex];
			node->aabb = it.aabb;

			if (it.left != -1) {
				WorkingItem *item = items_[it.left];
				if (item->left == -1 && item->right == -1) {
					AABBTreeAABBLeaf *leaf = (AABBTreeAABBLeaf*) tree_->leafs_;
					node->left = leaf + ln[it.left];
				}
				else {
					node->left = tree_->root_ + ln[it.left];
				}
			}
			else
				node->left = NULL;

			if (it.right != -1) {
				WorkingItem *item = items_[it.right];
				if (item->left == -1 && item->right == -1) {
					AABBTreeAABBLeaf *leaf = (AABBTreeAABBLeaf*) tree_->leafs_;
					node->right = leaf + ln[it.right];
				}
				else {
					node->right = tree_->root_ + ln[it.right];
				}
			}
			else
				node->right = NULL;
		}
	}

	if (_moni)
		_moni->write("Freeing temporary buffer");

	delete [] ln;

	delete item;
	items_.clear();

	if (_moni)
		_moni->write("Done.");

	return tree_;
}

void AABBTreeAABB_Builder::workOnItem(WorkingItem &_item, int _leafDepth)
{
	int i;

	int size = _item.boxes.size();
	if (size <= _leafDepth) {
		_item.left = -1;
		_item.right = -1;
		return;
	}

	int axis;
	float middle;

	int nbBoxes = _item.boxes.size();

	Vec3f min, max;
	min = Vec3f(FLT_MAX, FLT_MAX, FLT_MAX);
	max = -min;

	for (i = 0; i < nbBoxes; i++) {
		const Box &box = _item.boxes[i];
		Vec3f bLeft = box.center - box.extent;
		Vec3f tRight = box.center + box.extent;
		if (bLeft.x < min.x) min.x = bLeft.x;
		if (bLeft.y < min.y) min.y = bLeft.y;
		if (bLeft.z < min.z) min.z = bLeft.z;

		if (tRight.x > max.x) max.x = tRight.x;
		if (tRight.y > max.y) max.y = tRight.y;
		if (tRight.z > max.z) max.z = tRight.z;
	}

	_item.aabb.center = (min + max) / 2;
	_item.aabb.extent = (max - min) / 2;

	const Vec3f &center = _item.aabb.center;
	const Vec3f &ext = _item.aabb.extent;

	if (ext.x > ext.y && ext.x > ext.z) {
		axis = 0;
		middle = center.x;
	}
	else {
		if (ext.y > ext.z) {
			axis = 1;
			middle = center.y;
		}
		else {
			axis = 2;
			middle = center.z;
		}
	}

	Vec3f bboxMin = center - ext;
	Vec3f bboxMax = center + ext;

	WorkingItem *left = NULL;
	WorkingItem *right = NULL;

	for (i = 0; i < nbBoxes; i++) {
		const Box &bx = _item.boxes[i];

		float min, max;
		int res = classifyAABB(bx, axis, middle);
		if (axis == 0) {
			min = bx.center.x - bx.extent.x;
			max = bx.center.x + bx.extent.x;
		}
		else if (axis == 1) {
			min = bx.center.y - bx.extent.y;
			max = bx.center.y + bx.extent.y;
		}
		else {
			min = bx.center.z - bx.extent.z;
			max = bx.center.z + bx.extent.z;
		}

		if (res == 0) {
			if (!left) {
				left = new WorkingItem();
				Box &box = left->aabb;
				if (axis == 0)
					box.setFromPoints(bboxMin, Vec3f((bboxMin.x + bboxMax.x) / 2.0f, bboxMax.y, bboxMax.z));
				else if (axis == 1)
					box.setFromPoints(bboxMin, Vec3f(bboxMax.x, (bboxMin.y + bboxMax.y) / 2.0f, bboxMax.z));
				else if (axis == 2)
					box.setFromPoints(bboxMin, Vec3f(bboxMax.x, bboxMax.y, (bboxMin.z + bboxMax.z) / 2.0f));
			}
			Box &box = left->aabb;
			if (axis == 0 && max > (box.center.x + box.extent.x) )
				box.setFromPoints(bboxMin, Vec3f(max, bboxMax.y, bboxMax.z));
			else if (axis == 1 && max > (box.center.y + box.extent.y) )
				box.setFromPoints(bboxMin, Vec3f(bboxMax.x, max, bboxMax.z));
			else if (axis == 2 && max > (box.center.z + box.extent.z) )
				box.setFromPoints(bboxMin, Vec3f(bboxMax.x, bboxMax.y, max));
			left->boxes.add(bx);
		}
		else {
			// res = 1
			if (!right) {
				right = new WorkingItem();
				Box &box = right->aabb;
				if (axis == 0)
					box.setFromPoints(Vec3f((bboxMin.x + bboxMax.x) / 2.0f, bboxMin.y, bboxMin.z), bboxMax);
				else if (axis == 1)
					box.setFromPoints(Vec3f(bboxMin.x, (bboxMin.y + bboxMax.y) / 2.0f, bboxMin.z), bboxMax);
				else if (axis == 2)
					box.setFromPoints(Vec3f(bboxMin.x, bboxMin.y, (bboxMin.z + bboxMax.z) / 2.0f), bboxMax);
			}
			Box &box = right->aabb;
			if (axis == 0 && min < (box.center.x - box.extent.x) )
				box.setFromPoints(Vec3f(min, bboxMin.y, bboxMin.z), bboxMax);
			else if (axis == 1 && min < (box.center.y - box.extent.y) )
				box.setFromPoints(Vec3f(bboxMin.x, min, bboxMin.z), bboxMax);
			else if (axis == 2 && min < (box.center.z - box.extent.z) )
				box.setFromPoints(Vec3f(bboxMin.x, bboxMin.y, min), bboxMax);
			right->boxes.add(bx);
		}
	}

	if ((left && !right) || (!left && right)) {
		if (left && !right) {
			right = new WorkingItem();
			right->aabb = left->aabb;
			int nbBoxes = left->boxes.size();
			int le = nbBoxes / 2;
			int start = nbBoxes - le;
			for (i = start; i < nbBoxes; i++) {
				Box b = left->boxes[i];
				right->boxes.add(b);
			}
			left->boxes.grow(-le);
		}
		else if (!left && right) {
			left = new WorkingItem();
			left->aabb = right->aabb;
			int nbBoxes = right->boxes.size();
			int le = nbBoxes / 2;
			int start = nbBoxes - le;
			for (i = start; i < nbBoxes; i++) {
				Box b = right->boxes[i];
				left->boxes.add(b);
			}
			right->boxes.grow(-le);
		}
	}

	if (left) {
		_item.left = items_.size();
		items_.add(left);
	}
	else
		_item.left = -1;

	if (right) {
		_item.right = items_.size();
		items_.add(right);
	}
	else
		_item.right = -1;
}

int AABBTreeAABB_Builder::classifyAABB(const Box &_box, int _axis, float _middle)
{
	if ((_box.center.x <= _middle && _axis == 0) ||
		(_box.center.y <= _middle && _axis == 1) ||
		(_box.center.z <= _middle && _axis == 2) )
		return 0;
	else
		return 1;
}

LEAVE_NAMESPACE
