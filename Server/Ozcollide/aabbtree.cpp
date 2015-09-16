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
#include <ozcollide/aabbtree.h>
#include <ozcollide/aabbtree_aabb.h>
#include <ozcollide/aabbtree_poly.h>
#include <ozcollide/aabbtree_sphere.h>
#include <ozcollide/dataio.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

AABBTree::AABBTree(AABBTREE_LEAFTYPE _leafType, int _leafDepth)
{
	leafType_ = _leafType;
	leafDepth_ = _leafDepth;
	nbNodes_ = 0;
	nbLeafs_ = 0;
	userDataType_ = 0;
	bUseTemporalCoherence_ = false;
	coefVolInflater_ = 1.5f;
}

AABBTree::~AABBTree()
{
}

void AABBTree::destroy()
{
	delete this;
}

ERR AABBTree::loadBinary(const char *_filename, AABBTree **_tree)
{
	DataIn file;
	int chunk;
	int chunkSize;
	AABBTree *tr;

	if (!file.open(_filename))
		return ERR_CANNOT_OPEN;

	chunk = file.readDword();
	if (chunk != MID('A', 'A', 'B', 'B'))
		return ERR_INVALID_FORMAT;

	chunkSize = file.readDword();

	char leafType = file.readByte();
	file.close();

	if (leafType == 0) {
		AABBTreePoly *tp;
		ERR err = AABBTreePoly::loadBinary(_filename, &tp);
		if (err)
			return err;
		tr = tp;
	}
	else if (leafType == 1) {
		AABBTreeSphere *ts;
		ERR err = AABBTreeSphere::loadBinary(_filename, &ts);
		if (err)
			return err;
		tr = ts;
	}
	else if (leafType == 2) {
		AABBTreeAABB *tb;
		ERR err = AABBTreeAABB::loadBinary(_filename, &tb);
		if (err)
			return err;
		tr = tb;
	}
	else
		return ERR_INVALID_FORMAT;

	*_tree = tr;

	return NOERR;
}

LEAVE_NAMESPACE
