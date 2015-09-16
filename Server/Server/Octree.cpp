////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/15
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Octree.h"
#include "BaseDefine.h"

COctree::COctree()
	: m_HalfSize(0, 0, 0)
{
	//initialize all children to null.
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				m_Children[i][j][k] = NULL;
			}
		}
	}

	m_pParent = NULL;
}

COctree::~COctree()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (m_Children[i][j][k] != NULL)
				{
					delete m_Children[i][j][k];
				}
			}
		}
	}

	m_pParent = NULL;
}

bool COctree::Create(COctree* pParent, const Box& Box, const COctreeIndex& Index)
{
	CHECK_RETURN(Index.x >= 0 && Index.x <= 1 && Index.y >= 0 && Index.y <= 1 && Index.z >= 0 && Index.z <= 1, false);

	m_pParent = pParent;
	m_nDepth = (pParent == NULL)? 0 : (pParent->GetDepth() + 1);
	m_Box = Box;
	m_HalfSize = m_Box.center - m_Box.getMin();

	if (pParent)
	{
		m_Index = pParent->GetIndex();
		m_Index.x = m_Index.x << 1 | Index.x;
		m_Index.y = m_Index.y << 1 | Index.y;
		m_Index.z = m_Index.z << 1 | Index.z;
	}
	else
	{
		m_Index = Index;
	}

	return true;
}

bool COctree::IsTwiceSize(const Box &Box) const
{
	Vec3f halfMBoxSize = m_Box.center - m_Box.getMin();
	Vec3f boxSize = Box.getMax() - Box.getMin();

	return ((boxSize.x <= halfMBoxSize.x) && (boxSize.y <= halfMBoxSize.y) && (boxSize.z <= halfMBoxSize.z));
}

void COctree::GetChildIndexes(const Box& Box, int *x, int *y, int *z) const
{
	const Vec3f& center = m_Box.center;

	const Vec3f& ncenter = Box.center;

	if (ncenter.x > center.x)
		* x = 1;
	else
		*x = 0;

	if (ncenter.y > center.y)
		* y = 1;
	else
		*y = 0;

	if (ncenter.z > center.z)
		* z = 1;
	else
		*z = 0;
}

void COctree::GetCullBounds(Box* Box) const
{
	CHECK(Box);

	Box->setFromPoints(m_Box.getMin() - m_HalfSize, m_Box.getMax() + m_HalfSize);
}

COctree* COctree::GetChildByIndex(int x, int y, int z)
{
	CHECK_RETURN(x >= 0 && x <= 1 && y >= 0 && y <= 1 && z >= 0 && z <= 1, NULL);

	return m_Children[x][y][z];
}

void COctree::GetActualBounds(Box* Box) const
{
	CHECK(Box);

	Box->setFromPoints(m_Box.getMin(), m_Box.getMax());
}

bool COctree::IsLeaf()
{
	return (m_Children[0][0][0] == NULL);
}

const COctreeIndex& COctree::GetIndex()
{
	return m_Index;
}

COctree* COctree::CreateFullOctree(const Box& BoundBox, const int nMaxDepth, const Box& LeafBoundBox)
{
	return CreateFullOctreeImpl(NULL, BoundBox, COctreeIndex(0, 0, 0), nMaxDepth, LeafBoundBox);
}

COctree* COctree::CreateFullOctreeImpl(COctree* pParent, const Box& BoundBox, const COctreeIndex& Index, const int nMaxDepth, const Box& LeafBoundBox)
{
	CHECK_RETURN(nMaxDepth >= 0, NULL);

	COctree* pOctree = COctree::CreateNew();
	IF_NOT (pOctree && pOctree->Create(pParent, BoundBox, Index))
	{
		SAFE_RELEASE(pOctree);
		return NULL;
	}

	if (pOctree->GetDepth() >= nMaxDepth || !pOctree->IsTwiceSize(LeafBoundBox))
	{
		return pOctree;
	}
	
	Point3f ChildMin;
	Point3f ChildMax;
	for (int x = 0; x < 2; ++x)
	{
		for (int y = 0; y < 2; ++y)
		{
			for (int z = 0; z < 2; ++z)
			{
				if (x == 0)
				{
					ChildMin.x = BoundBox.getMin().x;
					ChildMax.x = BoundBox.center.x;
				}
				else
				{
					ChildMin.x = BoundBox.center.x;
					ChildMax.x = BoundBox.getMax().x;
				}

				if (y == 0)
				{
					ChildMin.y = BoundBox.getMin().y;
					ChildMax.y = BoundBox.center.y;
				}
				else
				{
					ChildMin.y = BoundBox.center.y;
					ChildMax.y = BoundBox.getMax().y;
				}

				if (z == 0)
				{
					ChildMin.z = BoundBox.getMin().z;
					ChildMax.z = BoundBox.center.z;
				}
				else
				{
					ChildMin.z = BoundBox.center.z;
					ChildMax.z = BoundBox.getMax().z;
				}

				Box ChildBox;
				ChildBox.setFromPoints(ChildMin, ChildMax);
				COctree* pChild = CreateFullOctreeImpl(pOctree, ChildBox, COctreeIndex(x, y, z), nMaxDepth, LeafBoundBox);
				pOctree->SetChildByIndex(pChild, x, y, z);
			}
		}
	}

	return pOctree;
}

void COctree::SetChildByIndex(COctree* pOctree, int x, int y, int z)
{
	CHECK(x >= 0 && x <= 1 && y >= 0 && y <= 1 && z >= 0 && z <= 1);

	m_Children[x][y][z] = pOctree;
}

void COctree::DestroyOctree(COctree* pOctree)
{
	CHECK(pOctree);

	for (int x = 0; x < 2; ++x)
	{
		for (int y = 0; y < 2; ++y)
		{
			for (int z = 0; z < 2; ++z)
			{
				COctree* pChild = pOctree->GetChildByIndex(x, y, z);
				if (pChild == NULL)
				{
					continue;
				}
				COctree::DestroyOctree(pChild);
				pOctree->SetChildByIndex(NULL, x, y, z);
			}
		}
	}

	SAFE_RELEASE(pOctree);
}

COctree* COctree::GetChild(const Box& Box)
{
	int x = 0;
	int y = 0;
	int z = 0;
	this->GetChildIndexes(Box, &x, &y, &z);

	return this->GetChildByIndex(x, y, z);
}

COctree* COctree::GetOctreeByBox(const Box& Box)
{
	if (!this->IsTwiceSize(Box))
	{
		return this;
	}

	COctree* pChild = this->GetChild(Box);
	if (pChild == NULL)
	{
		return this;
	}

	return pChild->GetOctreeByBox(Box);
}

COctree* COctree::GetOctreeByPoint(const Point3f& ptPosition)
{
	Box BoxPos(ptPosition, ZEROVEC3F);

	return this->GetOctreeByBox(BoxPos);
}

float COctree::GetEdgeLength()
{
	BoxEdge objEdge = m_Box.getEdge(0);

	return (objEdge.p1 - objEdge.p0).len();
}

