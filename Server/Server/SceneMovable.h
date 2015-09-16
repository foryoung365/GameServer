////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/03
// Describe:场景中可移动物体
////////////////////////////////////////////////////////////////////////
#include "SceneObject.h"
#include "MoveList.h"

using namespace ozcollide;

class CSceneMovable : public CSceneObject
{
protected:
	CSceneMovable(OBJECT_TYPE eType);
	virtual ~CSceneMovable();
public:
	virtual bool Create(CScene* pScene, const Point3f& ptPos);

	virtual bool IsMovable();
	virtual bool IsTeleportable();

	virtual const Point3f& GetPosition();

	virtual const Vec3f& GetMoveDirection() { return m_v3MoveDirection; }
	virtual void SetMoveDirection(const Vec3f& v3Direction);

	virtual const Vec3f& GetFaceDirection() { return m_v3FaceDirection; }
	virtual void SetFaceDirection(const Vec3f& v3Direction) { m_v3FaceDirection = v3Direction; m_v3FaceDirection.normalize(); }

	virtual bool MoveTo(const Point3f& ptTargetPos, float fVelocity);
	virtual bool MoveTo(MoveActionInfo_t* pMoveInfo);

	virtual float GetMaxSpeed() = 0;
	
	virtual void OnTimer();
	virtual bool SyncRegion();	
	virtual void BroadcastMoveMsg(int nAction, MoveActionInfo_t* pMoveInfo);

	virtual void OnEnterScene();
	virtual void OnLeaveScene();
protected:
	Vec3f m_v3MoveDirection;	//移动方向（单位向量）
	Vec3f m_v3FaceDirection;	//面朝方向（单位向量）
	CMoveList* m_pMoveList;
};