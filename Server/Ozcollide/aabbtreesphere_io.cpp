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

ERR AABBTreeSphere::loadBinary(const char *_fileName, AABBTreeSphere **_tree)
{
	DataIn file;
	ERR err;
	
	if (!file.open(_fileName))
		return ERR_CANNOT_OPEN;

	err  = loadBinary(file, _tree);
	if (err != NOERR)
		return err;

	file.close();
	return NOERR;
}

ERR AABBTreeSphere::loadBinary(DataIn &_file, AABBTreeSphere **_tree)
{
	char chunk[4];
	int chunkSize;

	_file.read(chunk, 4);
	if (MID(chunk[0], chunk[1],chunk[2], chunk[3]) != MID('A', 'A', 'B', 'B'))
		return ERR_INVALID_FORMAT;
	
	chunkSize = _file.readDword();

	char leafType = _file.readByte();

	if (leafType != 1)
		return ERR_INVALID_FORMAT;

	AABBTreeSphere *t;
	char leafDepth = _file.readByte();
	t = new AABBTreeSphere(leafDepth);

	t->nbNodes_ = _file.readDword();
	t->nbLeafs_ = _file.readDword();

	t->leafs_ = new AABBTreeSphereLeaf[t->nbLeafs_];
	t->root_ = new AABBTreeNode[t->nbNodes_];

	while(chunkSize > 8) {
		char id[4];
		_file.read(id, 4);
		int sc = MID(id[0], id[1], id[2], id[3]);

		int scSize = _file.readDword();
		int pos0 = _file.tell();

		if (sc == MID('N','O','D','S'))
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

	return NOERR;
}

void AABBTreeSphere::readNODSchunk(DataIn &_file, int _chunkSize, int _nbNodes)
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

void AABBTreeSphere::readLEFSchunk(DataIn &_file, int _chunkSize, int _nbLeafs)
{
	int i, j;

	for (i = 0; i < _nbLeafs; i++) {
		AABBTreeSphereLeaf &leaf = leafs_[i];
	
		leaf.aabb.center.x = _file.readFloat();
		leaf.aabb.center.y = _file.readFloat();
		leaf.aabb.center.z = _file.readFloat();
		leaf.aabb.extent.x = _file.readFloat();
		leaf.aabb.extent.y = _file.readFloat();
		leaf.aabb.extent.z = _file.readFloat();
		
		leaf.left = NULL;
		leaf.right = NULL;
		
		int nbSpheres = _file.readDword();
		leaf.nbSpheres = nbSpheres;
		leaf.spheres = new Sphere[nbSpheres];
		for (j = 0; j < nbSpheres; j++) {
			Sphere &s = (Sphere &) leaf.spheres[j];
			s.center.x = _file.readFloat();
			s.center.y = _file.readFloat();
			s.center.z = _file.readFloat();
			s.radius = _file.readFloat();
		}
	}
}

ERR AABBTreeSphere::saveBinary(const char *_fname)
{
	DataOut file;
	ERR err;

	if (!file.open(_fname))
		return ERR_CANNOT_OPEN;

	err = saveBinary(file);
	if (err)
		return err;

	file.close();
	return NOERR;
}

ERR AABBTreeSphere::saveBinary(DataOut &_file)
{
	int i, j;

	_file.writeStr("AABB");
	int posBBT = _file.tell();
	_file.advance(4);

	int size = 0;

	size += _file.writeByte(1);

	int nbNodes = getNbNodes();
	int nbLeafs = getNbLeafs();

	size += _file.writeByte(leafDepth_);
	size += _file.writeDword(nbNodes);
	size += _file.writeDword(nbLeafs);

	size += _file.writeStr("NODS");
	size += _file.writeDword((24 + 8) * nbNodes);
	for (i = 0; i < nbNodes; i++) {
		AABBTreeNode *node = &root_[i];
		size += _file.writeFloat(node->aabb.center.x);
		size += _file.writeFloat(node->aabb.center.y);
		size += _file.writeFloat(node->aabb.center.z);
		size += _file.writeFloat(node->aabb.extent.x);
		size += _file.writeFloat(node->aabb.extent.y);
		size += _file.writeFloat(node->aabb.extent.z);

		const AABBTreeNode *left = node->left;
		const AABBTreeNode *right = node->right;

		if (left) {
			int diff = left - root_;
			if (diff < 0 || diff >= nbNodes) {
				diff = ((AABBTreeSphereLeaf*) left) - leafs_;
				diff |= 0x80000000;
			}
			size += _file.writeDword(diff);
		}
		else
			size += _file.writeDword(-1);

		if (right) {
			int diff = right - root_;
			if (diff < 0 || diff >= nbNodes) {
				diff = ((AABBTreeSphereLeaf*) right) - leafs_;
				diff |= 0x80000000;
			}
			size += _file.writeDword(diff);
		}
		else
			size += _file.writeDword(-1);
	}

	size += _file.writeStr("LEFS");
	int posLEFS = _file.tell();
	_file.advance(4);
	int sizeLEFS = 0;
	for (i = 0; i < nbLeafs; i++) {
		AABBTreeSphereLeaf *leaf = &leafs_[i];

		_file.writeFloat(leaf->aabb.center.x);
		_file.writeFloat(leaf->aabb.center.y);
		_file.writeFloat(leaf->aabb.center.z);
		_file.writeFloat(leaf->aabb.extent.x);
		_file.writeFloat(leaf->aabb.extent.y);
		_file.writeFloat(leaf->aabb.extent.z);
		size += 24;		sizeLEFS += 24;

		_file.writeDword(leaf->nbSpheres);
		size += 4;		sizeLEFS += 4;

		int nbSpheres = leaf->nbSpheres;
		for (j = 0; j < nbSpheres; j++) {
			const Sphere &s = leaf->spheres[j];
			_file.writeFloat(s.center.x);
			_file.writeFloat(s.center.y);
			_file.writeFloat(s.center.z);
			_file.writeFloat(s.radius);
		}
		size += nbSpheres * 16;
		sizeLEFS += nbSpheres * 16;
	}

	_file.seek(posLEFS);
	_file.writeDword(sizeLEFS);

	_file.seek(posBBT);
	_file.writeDword(size);

	return NOERR;
}

LEAVE_NAMESPACE
