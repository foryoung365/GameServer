////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/15
// Describe:
////////////////////////////////////////////////////////////////////////
#ifndef _OCTREE_H_
#define _OCTREE_H_

#include <list>
#include <set>
#include <vector>
#include <stdint.h>
#include "ozcollide/box.h"
#include "SceneObject.h"

using namespace ozcollide;

typedef std::set<COctree*> OCTREE_SET;
typedef std::vector<COctree*> OCTREE_VEC;

typedef std::list<CSceneObject*> NodeList;

class COctreeIndex
{
public:
	COctreeIndex() { x = y = z = 0; }
	COctreeIndex(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
public:
	int x;
	int y;
	int z;
};

class COctree
{
protected:
	COctree();
	~COctree();
public:
	static COctree* CreateNew() { return new COctree; }
	//生成一棵满八叉树,nMaxDepth和LeafBoundBox作为边界条件会同时生效
	//BoundBox:八叉树的空间范围
	//nMaxDepth:八叉树的最大深度
	//LeafBoundBox:叶节点的范围
	static COctree* CreateFullOctree(const Box& BoundBox, const int nMaxDepth, const Box& LeafBoundBox);
	static void DestroyOctree(COctree* pOctree);
	bool Create(COctree* pParent, const Box& Box, const COctreeIndex& Index);
	void Release() { delete this; }
public:

	/** Determines if this octree is twice as big as the given box.
	@remarks
	This method is used by the OctreeSceneManager to determine if the given
	box will fit into a child of this octree.
	*/
	bool IsTwiceSize(const Box &Box) const;

	/**  Returns the appropriate indexes for the child of this octree into which the box will fit.
	@remarks
	This is used by the OctreeSceneManager to determine which child to traverse next when
	finding the appropriate octree to insert the box.  Since it is a loose octree, only the
	center of the box is checked to determine the octant.
	*/
	void GetChildIndexes(const Box& Box, int *x, int *y, int *z) const;
	
	COctree* GetChild(const Box& Box);

	/** Creates the AxisAlignedBox used for culling this octree.
	@remarks
	Since it's a loose octree, the culling bounds can be different than the actual bounds of the octree.
	*/
	void GetCullBounds(Box* Box) const;

	void GetActualBounds(Box* Box) const;

	int GetDepth() { return m_nDepth; }

	COctree* GetChildByIndex(int x, int y, int z);

	void SetChildByIndex(COctree* pOctree, int x, int y, int z);
	
	COctree* GetParent() { return m_pParent; }

	const OCTREE_SET& GetNeighborSet() const;

	bool IsLeaf();

	const COctreeIndex& GetIndex();

	COctree* GetOctreeByBox(const Box& Box);
	COctree* GetOctreeByPoint(const Point3f& ptPosition);

	//边长
	float GetEdgeLength();
protected:
	static COctree* CreateFullOctreeImpl(COctree* pParent, const Box& BoundBox, const COctreeIndex& Index, const int nMaxDepth, const Box& LeafBoundBox);

protected:
	///parent octree
	COctree* m_pParent;
	/** The bounding box of the octree
	@remarks
	This is used for octant index determination and rendering, but not culling
	*/
	Box m_Box;


	/** Vector containing the dimensions of this octree / 2
	*/
	Vec3f m_HalfSize;

	/** 3D array of children of this octree.
	@remarks
	Children are dynamically created as needed when nodes are inserted in the Octree.
	If, later, all the nodes are removed from the child, it is still kept around.
	*/
	COctree* m_Children[2][2][2];

	int m_nDepth;

	COctreeIndex m_Index;
};

#endif	//end of define _OCTREE_H_