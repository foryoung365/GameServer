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
#include <ozcollide/aabbtreepoly_builder.h>
#include <ozcollide/aabbtree_poly.h>
#include <ozcollide/monitor.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

AABBTreePolyBuilder::AABBTreePolyBuilder()
{
}

AABBTreePolyBuilder::~AABBTreePolyBuilder()
{
}

AABBTreePoly* AABBTreePolyBuilder::buildFromPolys(const Polygon *_pols,
												  int _nbPolys,
												  const Vec3f *_points,
												  int _nbPoints,
												  int _leafDepth,
												  Monitor *_moni)
{
	int i;

	tree_ = new AABBTreePoly(_leafDepth);

	tree_->points_ = new Vec3f[_nbPoints];
	tree_->nbPoints_ = _nbPoints;
	for (i = 0; i < _nbPoints; i++)
		tree_->points_[i] = _points[i];

	WorkingItem *item = new WorkingItem();
	for (i = 0; i < _nbPolys; i++)
		item->pols.add( (Polygon*) &_pols[i]);

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

	build(_moni);

	delete item;

	return tree_;
}

void AABBTreePolyBuilder::build(Monitor *_moni)
{
	int i, j;

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
	tree_->leafs_ = new AABBTreePolygonLeaf[nbLeafs];
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
			AABBTreePolygonLeaf *pl = (AABBTreePolygonLeaf*) tree_->leafs_;
			pl += indexLeaf;
			pl->aabb = it.aabb;
			pl->left = NULL;
			pl->right = NULL;
			int nbPols = it.pols.size();
			pl->nbPolys = nbPols;
			pl->polys = new Polygon[nbPols];
			for (j = 0; j < nbPols; j++) {
				Polygon *pol = (Polygon*) &pl->polys[j];
				it.pols[j]->copyTo(*pol);
			}
		}
		else {
			int nodeIndex = ln[i];
			AABBTreeNode *pn = &tree_->root_[nodeIndex];
			pn->aabb = it.aabb;

			if (it.left != -1) {
				WorkingItem *item = items_[it.left];
				if (item->left == -1 && item->right == -1) {
					AABBTreePolygonLeaf *pl = (AABBTreePolygonLeaf*) tree_->leafs_;
					pn->left = pl + ln[it.left];
				}
				else {
					pn->left = tree_->root_ + ln[it.left];
				}
			}
			else
				pn->left = NULL;

			if (it.right != -1) {
				WorkingItem *item = items_[it.right];
				if (item->left == -1 && item->right == -1) {
					AABBTreePolygonLeaf *pl = (AABBTreePolygonLeaf*) tree_->leafs_;
					pn->right = pl + ln[it.right];
				}
				else {
					pn->right = tree_->root_ + ln[it.right];
				}
			}
			else
				pn->right = NULL;
		}
	}

	if (_moni)
		_moni->write("Freeing temporary buffer");

	delete [] ln;

	items_.clear();

	if (_moni)
		_moni->write("Done.");
}

void AABBTreePolyBuilder::workOnItem(WorkingItem &_item, int _leafDepth)
{
	int i, j;

	int size = _item.pols.size();
	if (size <= _leafDepth) {
		_item.left = -1;
		_item.right = -1;
		return;
	}

	int axis;
	float middle;

	int nbPols = _item.pols.size();

	Vec3f min, max;
	min = Vec3f(FLT_MAX, FLT_MAX, FLT_MAX);
	max = -min;
	for (i = 0; i < nbPols; i++) {
		Polygon &pol = *_item.pols[i];
		int nbVerts = pol.getNbIndices();
		for (j = 0; j < nbVerts; j++) {
			int index = pol.getIndex(j);
			Vec3f &pt = tree_->points_[index];
			if (pt.x < min.x) min.x = pt.x;
			if (pt.y < min.y) min.y = pt.y;
			if (pt.z < min.z) min.z = pt.z;
			if (pt.x > max.x) max.x = pt.x;
			if (pt.y > max.y) max.y = pt.y;
			if (pt.z > max.z) max.z = pt.z;
		}
	}
	_item.aabb.center = (min + max) / 2;
	_item.aabb.extent = (max - min) / 2;

	const Vec3f &center = _item.aabb.center;
	const Vec3f &ext = _item.aabb.extent;

	if (ext.x > ext.y && ext.x > ext.z)
		axis = 0;
	else {
		if (ext.y > ext.z)
			axis = 1;
		else
			axis = 2;
	}

	middle = calculAvgPoint(_item, axis);

	Vec3f bboxMin = center - ext;
	Vec3f bboxMax = center + ext;

	WorkingItem *left = NULL;
	WorkingItem *right = NULL;

	for (i = 0; i < nbPols; i++) {
		Polygon *pol = _item.pols[i];
		float min, max;
		int res = classifyPol(*pol, axis, middle, min, max);
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
			left->pols.add(pol);
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
			right->pols.add(pol);
		}
	}

	if ((left && !right) || (!left && right)) {
		if (left && !right) {
			right = new WorkingItem();
			right->aabb = left->aabb;
			int nbPols = left->pols.size();
			int le = nbPols / 2;
			int start = nbPols - le;
			for (i = start; i < nbPols; i++) {
				Polygon *p = left->pols[i];
				right->pols.add(p);
			}
			left->pols.grow(-le);
		}
		else if (!left && right) {
			left = new WorkingItem();
			left->aabb = right->aabb;
			int nbPols = right->pols.size();
			int le = nbPols / 2;
			int start = nbPols - le;
			for (i = start; i < nbPols; i++) {
				Polygon *p = right->pols[i];
				left->pols.add(p);
			}
			right->pols.grow(-le);
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

int AABBTreePolyBuilder::classifyPol(const Polygon &_pol, int _axis, float _middle, float &_min, float &_max)
{
	int i;

	takeMinMax(_pol, _axis, _min, _max);
	int nbVerts = _pol.getNbIndices();
	float m = 0.0f;
	for (i = 0; i < nbVerts; i++) {
		int index = _pol.getIndex(i);
		Vec3f &pt = tree_->points_[index];
		if (_axis == 0)
			m += pt.x;
		else if (_axis == 1)
			m += pt.y;
		else if (_axis == 2)
			m += pt.z;
	}
	m /= nbVerts;
	if (m < _middle)
		return 0;
	return 1;
}

void AABBTreePolyBuilder::takeMinMax(const Polygon &_pol, int _axis, float &_min, float &_max)
{
	int i;
	int nbVerts = _pol.getNbIndices();
	_min = FLT_MAX;
	_max = -FLT_MAX;
	for (i = 0; i < nbVerts; i++) {
		int index = _pol.getIndex(i);
		Vec3f &pt = tree_->points_[index];

		if (_axis == 0 && pt.x < _min)
			_min = pt.x;
		else if (_axis == 1 && pt.y < _min)
			_min = pt.y;
		else if (_axis == 2 && pt.z < _min)
			_min = pt.z;

		if (_axis == 0 && pt.x > _max)
			_max = pt.x;
		else if (_axis == 1 && pt.y > _max)
			_max = pt.y;
		else if (_axis == 2 && pt.z > _max)
			_max = pt.z;
	}
}

float AABBTreePolyBuilder::calculAvgPoint(WorkingItem &_item, int _axis)
{
	int i, j;

	int nb = 0;
	int nbPols = _item.pols.size();

	float m = 0;
	if (_axis == 0) {
		for (i = 0; i < nbPols; i++) {
			Polygon &pol = *_item.pols[i];
			int nbVerts = pol.getNbIndices();
			nb += nbVerts;
			for (j = 0; j < nbVerts; j++) {
				int index = pol.getIndex(j);
				m += tree_->points_[index].x;
			}
			
		}
	}
	else if (_axis == 1) {
		for (i = 0; i < nbPols; i++) {
			Polygon &pol = *_item.pols[i];
			int nbVerts = pol.getNbIndices();
			nb += nbVerts;
			for (j = 0; j < nbVerts; j++) {
				int index = pol.getIndex(j);
				m += tree_->points_[index].y;
			}
			
		}
	}
	else if (_axis == 2) {
		for (i = 0; i < nbPols; i++) {
			Polygon &pol = *_item.pols[i];
			int nbVerts = pol.getNbIndices();
			nb += nbVerts;
			for (j = 0; j < nbVerts; j++) {
				int index = pol.getIndex(j);
				m += tree_->points_[index].z;
			}
			
		}
	}
	return m / float(nb);
}

LEAVE_NAMESPACE
