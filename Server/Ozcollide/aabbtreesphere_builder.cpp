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
#include <ozcollide/aabbtreesphere_builder.h>
#include <ozcollide/aabbtree_sphere.h>
#include <ozcollide/monitor.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

AABBTreeSphere_Builder::AABBTreeSphere_Builder()
{
}

AABBTreeSphere_Builder::~AABBTreeSphere_Builder()
{
}

AABBTreeSphere* AABBTreeSphere_Builder::build(int nbSpheres,
											  const Sphere *spheres,
											  int leafDepth,
											  Monitor *moni)
{
	int i, j;

	tree_ = new AABBTreeSphere(leafDepth);

	// Build the root node

	WorkingItem *item = new WorkingItem();

	for (i = 0; i < nbSpheres; i++)
		item->spheres.add( spheres[i] );

	item->left = -1;
	item->right = -1;

	items_.add(item);

	int off = 0;
	while(true) {
		WorkingItem &it = *items_[off];
		workOnItem(it, leafDepth);
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
	tree_->leafs_ = new AABBTreeSphereLeaf[nbLeafs];
	tree_->nbNodes_ = nbNodes;
	tree_->nbLeafs_ = nbLeafs;

	if (moni)
		moni->write("Building the final clean tree");

	for (i = 0; i < items_.size(); i++) {
		if (moni)
			moni->setProgress(i, items_.size());

		WorkingItem &it = *items_[i];
		if (it.left == -1 && it.right == -1) {
			int indexLeaf = ln[i];
			AABBTreeSphereLeaf *sl = (AABBTreeSphereLeaf*) tree_->leafs_;
			sl += indexLeaf;
			sl->aabb = it.aabb;
			sl->left = NULL;
			sl->right = NULL;
			int nbSpheres = it.spheres.size();
			sl->nbSpheres = nbSpheres;
			sl->spheres = new Sphere[nbSpheres];
			for (j = 0; j < nbSpheres; j++) {
				Sphere *sp = (Sphere*) &sl->spheres[j];
				*sp = it.spheres[j];
			}
		}
		else {
			int nodeIndex = ln[i];
			AABBTreeNode *node = &tree_->root_[nodeIndex];
			node->aabb = it.aabb;

			if (it.left != -1) {
				WorkingItem *item = items_[it.left];
				if (item->left == -1 && item->right == -1) {
					AABBTreeSphereLeaf *leaf = (AABBTreeSphereLeaf*) tree_->leafs_;
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
					AABBTreeSphereLeaf *leaf = (AABBTreeSphereLeaf*) tree_->leafs_;
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

	if (moni)
		moni->write("Freeing temporary buffer");

	delete [] ln;

	delete item;
	items_.clear();

	if (moni)
		moni->write("Done.");

	return tree_;
}


void AABBTreeSphere_Builder::workOnItem(WorkingItem &item, int leafDepth)
{
	int i;

	int size = item.spheres.size();
	if (size <= leafDepth) {
		item.left = -1;
		item.right = -1;
		return;
	}

	int axis;
	float middle;

	int nbSpheres = item.spheres.size();

	Vec3f min, max;
	min = Vec3f(FLT_MAX, FLT_MAX, FLT_MAX);
	max = -min;

	for (i = 0; i < nbSpheres; i++) {
		Sphere &sphere = item.spheres[i];
		float r = sphere.radius;
		Vec3f topLeft = sphere.center - Vec3f(r, r, r);
		Vec3f bottomRight = sphere.center + Vec3f(r, r, r);
		if (topLeft.x < min.x) min.x = topLeft.x;
		if (topLeft.y < min.y) min.y = topLeft.y;
		if (topLeft.z < min.z) min.z = topLeft.z;

		if (bottomRight.x > max.x) max.x = bottomRight.x;
		if (bottomRight.y > max.y) max.y = bottomRight.y;
		if (bottomRight.z > max.z) max.z = bottomRight.z;
	}

	item.aabb.center = (min + max) / 2;
	item.aabb.extent = (max - min) / 2;

	const Vec3f &center = item.aabb.center;
	const Vec3f &ext = item.aabb.extent;

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

	for (i = 0; i < nbSpheres; i++) {
		const Sphere &sphere = item.spheres[i];

		float min, max;
		int res = classifySphere(sphere, axis, middle);
		if (axis == 0) {
			min = sphere.center.x - sphere.radius;
			max = sphere.center.x + sphere.radius;
		}
		else if (axis == 1) {
			min = sphere.center.y - sphere.radius;
			max = sphere.center.y + sphere.radius;
		}
		else {
			min = sphere.center.z - sphere.radius;
			max = sphere.center.z + sphere.radius;
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
			left->spheres.add(sphere);
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
			right->spheres.add(sphere);
		}
	}


	if ((left && !right) || (!left && right)) {
		if (left && !right) {
			right = new WorkingItem();
			right->aabb = left->aabb;
			int nbSpheres = left->spheres.size();
			int le = nbSpheres / 2;
			int start = nbSpheres - le;
			for (i = start; i < nbSpheres; i++) {
				Sphere s = left->spheres[i];
				right->spheres.add(s);
			}
			left->spheres.grow(-le);
		}
		else if (!left && right) {
			left = new WorkingItem();
			left->aabb = right->aabb;
			int nbSpheres = right->spheres.size();
			int le = nbSpheres / 2;
			int start = nbSpheres - le;
			for (i = start; i < nbSpheres; i++) {
				Sphere s = right->spheres[i];
				left->spheres.add(s);
			}
			right->spheres.grow(-le);
		}
	}

	if (left) {
		item.left = items_.size();
		items_.add(left);
	}
	else
		item.left = -1;

	if (right) {
		item.right = items_.size();
		items_.add(right);
	}
	else
		item.right = -1;
}

int AABBTreeSphere_Builder::classifySphere(const Sphere &sphere, int axis, float middle)
{
	if ((sphere.center.x <= middle && axis == 0) ||
		(sphere.center.y <= middle && axis == 1) ||
		(sphere.center.z <= middle && axis == 2) )
		return 0;
	else
		return 1;
}

LEAVE_NAMESPACE
