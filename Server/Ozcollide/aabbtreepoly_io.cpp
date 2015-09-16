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

ENTER_NAMESPACE_OZCOLLIDE

ERR AABBTreePoly::loadBinary(const char *_filename,
							 AABBTreePoly **_tree)
{
	DataIn file;
	ERR err;

	if (file.open(_filename))
		return ERR_CANNOT_OPEN;

	err  = loadBinary(file, _tree);
	if (err)
		return err;

	file.close();
	return NOERR;
}

ERR AABBTreePoly::loadBinary(DataIn &_file,
							 AABBTreePoly **_tree)
{
	int chunkSize;

	char id[4];
	_file.read(id, 4);
	int chunk = MID(id[0], id[1], id[2], id[3]);
	if (chunk != MID('A', 'A', 'B', 'B'))
		return ERR_INVALID_FORMAT;
	
	chunkSize = _file.readDword();

	char leafType = _file.readByte();

	if (leafType != 0)
		return ERR_INVALID_FORMAT;

	AABBTreePoly *t;
	char leafDepth = _file.readByte();
	t = new AABBTreePoly(leafDepth);
	t->nbNodes_ = _file.readDword();
	t->nbLeafs_ = _file.readDword();

	t->leafs_ = new AABBTreePolygonLeaf[t->nbLeafs_];
	t->root_ = new AABBTreeNode[t->nbNodes_];

	while(chunkSize > 8) {
		char id[4];
		_file.read(id, 4);
		int sc = MID(id[0], id[1], id[2], id[3]);

		int scSize = _file.readDword();
		int pos0 = _file.tell();

		if (sc == MID('N','P','O','L')) {
			int nbPols = _file.readDword();
			t->bufPols_ = new Polygon[nbPols];
		}
		else if (sc == MID('N','E','D','G')) {
			int nbEdges = _file.readDword();
			t->bufEdges_ = new int[nbEdges];
		}
		else if (sc == MID('P','N','T','S'))
			t->readPNTSchunk(_file, scSize);
		else if (sc == MID('N','O','D','S'))
			t->readNODSchunk(_file, scSize, t->nbNodes_);
		else if (sc == MID('L','E','F','S'))
			t->readLEFSchunk(_file, scSize, t->nbLeafs_);
		else
			_file.advance(scSize);

		int pos1 = _file.tell();
		if (pos1 - pos0 != scSize)
			_file.seek(pos0 + scSize);
		chunkSize -= scSize + 8;
	}

	*_tree = t;

	t->final();

	return NOERR;
}

void AABBTreePoly::readPNTSchunk(DataIn &_file, int _chunkSize)
{
	int i;

	nbPoints_ = _chunkSize / 12;
	SAFE_FREE(points_);
	points_ = new Vec3f[nbPoints_];
	for (i = 0; i < nbPoints_; i++) {
		Vec3f &pt = points_[i];
		pt.x = _file.readFloat();
		pt.y = _file.readFloat();
		pt.z = _file.readFloat();
	}
}

void AABBTreePoly::readNODSchunk(DataIn &_file,
								 int _chunkSize,
								 int _nbNodes)
{
	int i;

	for (i = 0; i < _nbNodes; i++) {
		AABBTreeNode &node = root_[i];

		node.aabb.center.x = _file.readFloat();
		node.aabb.center.y = _file.readFloat();
		node.aabb.center.z = _file.readFloat();
		node.aabb.extent.x = _file.readFloat();
		node.aabb.extent.y = _file.readFloat();
		node.aabb.extent.z = _file.readFloat();

		int leftID = _file.readDword();
		int rightID = _file.readDword();

		if (leftID == -1)
			node.left = NULL;
		else {
			int isLeaf = leftID >> 31;
			int index = leftID & 0x7fffffff;
			if (isLeaf)
				node.left = &leafs_[index];
			else
				node.left = &root_[index];
		}

		if (rightID == -1)
			node.right = NULL;
		else {
			int isLeaf = rightID >> 31;
			int index = rightID & 0x7fffffff;
			if (isLeaf)
					node.right = &leafs_[index];
			else
				node.right = &root_[index];
		}
	}
}

void AABBTreePoly::readLEFSchunk(DataIn &_file,
								 int _chunkSize,
								 int _nbLeafs)
{
	int i, j, k;

	for (i = 0; i < _nbLeafs; i++) {
		AABBTreePolygonLeaf &leaf = leafs_[i];

		leaf.aabb.center.x = _file.readFloat();
		leaf.aabb.center.y = _file.readFloat();
		leaf.aabb.center.z = _file.readFloat();
		leaf.aabb.extent.x = _file.readFloat();
		leaf.aabb.extent.y = _file.readFloat();
		leaf.aabb.extent.z = _file.readFloat();

		leaf.left = NULL;
		leaf.right = NULL;

		int nbPols = _file.readDword();
		leaf.nbPolys = nbPols;
		if (!bufPols_)
			leaf.polys = new Polygon[nbPols];
		else {
			leaf.polys = &bufPols_[offBufPols_];
			offBufPols_ += nbPols;
		}
		for (j = 0; j < nbPols; j++) {
			int nbVerts = _file.readDword();
			Polygon *pol = (Polygon*) &leaf.polys[j];
			if (!bufEdges_)
				pol->setNbIndices(nbVerts);
			else {
				pol->setIndicesMemory(nbVerts, bufEdges_);
				bufEdges_ += nbVerts;
			}
			for (k = 0; k < nbVerts; k++) {
				int vert = _file.readDword();
				pol->setIndex(k, vert);
			}
		}
	}
}

ERR AABBTreePoly::saveBinary(const char *_filename)
{
	DataOut file;
	ERR err;

	if (!file.open(_filename))
		return ERR_CANNOT_OPEN;

	err = saveBinary(file);
	if (err)
		return err;

	file.close();
	return NOERR;
}

ERR AABBTreePoly::saveBinary(DataOut &_file)
{
	int i, j, k;
	int pos;

	_file.writeStr("AABB");
	int posBBT = _file.tell();
	_file.advance(4);

	_file.writeByte(0);

	int nbNodes = getNbNodes();
	int nbLeafs = getNbLeafs();

	_file.writeByte(leafDepth_);
	_file.writeDword(nbNodes);
	_file.writeDword(nbLeafs);

	int nbPolys = 0;
	int nbEdges = 0;
	for (i = 0; i < nbLeafs; i++) {
		int nb = leafs_[i].nbPolys;
		nbPolys += nb;
		for (j = 0; j < nb; j++) {
			const Polygon *pol = &leafs_[i].polys[j];
			nbEdges += pol->getNbIndices();
		}
	}

	_file.writeStr("NPOL");
	_file.writeDword(4);
	_file.writeDword(nbPolys);

	_file.writeStr("NEDG");
	_file.writeDword(4);
	_file.writeDword(nbEdges);

	_file.writeStr("PNTS");
	_file.writeDword(nbPoints_ * 12);
	for (i = 0; i < nbPoints_; i++) {
		_file.writeFloat(points_[i].x);
		_file.writeFloat(points_[i].y);
		_file.writeFloat(points_[i].z);
	}

	_file.writeStr("NODS");
	_file.writeDword((24 + 8) * nbNodes);
	for (i = 0; i < nbNodes; i++) {
		AABBTreeNode *node = &root_[i];
		_file.writeFloat(node->aabb.center.x);
		_file.writeFloat(node->aabb.center.y);
		_file.writeFloat(node->aabb.center.z);
		_file.writeFloat(node->aabb.extent.x);
		_file.writeFloat(node->aabb.extent.y);
		_file.writeFloat(node->aabb.extent.z);

		const AABBTreeNode *left = node->left;
		const AABBTreeNode *right = node->right;

		if (left) {
			int diff = left - root_;
			if (diff < 0 || diff >= nbNodes) {
				diff = ((AABBTreePolygonLeaf*) left) - leafs_;
				diff |= 0x80000000;
			}
			_file.writeDword(diff);
		}
		else
			_file.writeDword(-1);

		if (right) {
			int diff = right - root_;
			if (diff < 0 || diff >= nbNodes) {
				diff = ((AABBTreePolygonLeaf*) right) - leafs_;
				diff |= 0x80000000;
			}
			_file.writeDword(diff);
		}
		else
			_file.writeDword(-1);
	}

	_file.writeStr("LEFS");
	int posLEFS = _file.tell();
	_file.advance(4);
	for (i = 0; i < nbLeafs; i++) {
		AABBTreePolygonLeaf *leaf = &leafs_[i];

		_file.writeFloat(leaf->aabb.center.x);
		_file.writeFloat(leaf->aabb.center.y);
		_file.writeFloat(leaf->aabb.center.z);
		_file.writeFloat(leaf->aabb.extent.x);
		_file.writeFloat(leaf->aabb.extent.y);
		_file.writeFloat(leaf->aabb.extent.z);

		_file.writeDword(leaf->nbPolys);

		for (j = 0; j < leaf->nbPolys; j++) {
			const Polygon &pol = leaf->polys[j];
			int nbVerts = pol.getNbIndices();
			_file.writeDword(nbVerts);
			for (k = 0; k < nbVerts; k++)
				_file.writeDword(pol.getIndex(k));
		}
	}
	pos = _file.tell();
	_file.seek(posLEFS);
	_file.writeDword(pos - posLEFS - 4);
	_file.seek(pos);

	pos = _file.tell();
	_file.seek(posBBT);
	_file.writeDword(pos - posBBT - 4);
	_file.seek(pos);

	return NOERR;
}

LEAVE_NAMESPACE
