////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/13
// Describe:玩家类
////////////////////////////////////////////////////////////////////////
#ifndef _USER_H_
#define _USER_H_

#include <set>
#include <string>
#include <bitset>
#include "BaseDefine.h"
#include "Role.h"
#include "UserData.h"
#include "BasicTypeDef.h"
#include "MsgNetwork.pb.h"

using std::bitset;

using juce::WeakReference;

class CUser : public CRole
{
protected:
	CUser();
	virtual ~CUser();
public:
	static CUser* CreateNew() { return new CUser; }
	virtual bool Create(const UserParm_t& rUserParm);
	virtual OBJID GetID();
	
	virtual const char* GetName();
	virtual float GetLength();
	virtual float GetWidth();
	virtual float GetHeight();
	virtual uint32_t GetFace();
	virtual uint32_t GetHair();
	virtual int GetLife();
	virtual int GetMaxLife();
	virtual int GetMana();
	virtual int GetMaxMana();
	virtual float GetMaxSpeed();
	virtual int GetLevel();
	virtual int64_t GetExp();
	virtual void SetLife(int nLife);
	virtual void AddLife(int nAddLife);
	virtual void SetMana(int nMana);
	virtual void AddMana(int nAddMana);
	virtual void SetLevel(int nLevel);
	virtual void UpLevel();
	virtual void SetExp(int64_t nExp);
	virtual void AwardExp(int64_t nExp);
	virtual bool IsInvulnerable();
	virtual bool IsBeAttackedEnable();
	virtual void OnEnterScene();
	virtual void OnLeaveScene();
	virtual void OnTimer();
public:
	static bool IsNameValid(juce::String strName);
	OBJID32 GetSceneID();
	OBJID64 GetPeerID();
	void SetPeerID(OBJID64 idPeer);
	const char* GetIP() { return m_strIP.c_str(); }
	void SetIP(std::string strIP) { m_strIP = strIP; }
	OBJID32 GetRecordSceneID();
	void SaveInfo();
	//玩家创建之后，客户端开始登录步骤之前调用，各种管理器初始化玩家相关数据请在这里执行
	//在这个函数之后，所有这个玩家的内存数据库集合都会被删除
	void CreateOK();
	//客户端登录步骤完成
	void LoginOK();

	void SendUserInfo();
	OBJID64 GetAccountID();
	virtual void SendShow(CUser* pUser);
	virtual void SendShow(const USER_SET& setUsers);
	virtual void SendMsg(CMsgNetwork* pMsgNetwork);
	void SetDirtyMask(CUserData_enum eDirtyField);
	void ClearSyncDirtyMask();
	void ClearUpdateDirtyMask();
public:
	virtual bool ClientMoveTo(MoveActionInfo_t* pMoveInfo);
private:
	bool FillMsgRoleInfo(CMsgRoleInfo* pMsgRoleInfo, int nAction);

private:
	CUserData m_objUserData;
	OBJID64 m_idPeer;
	std::string m_strIP;
	typedef bitset<USERDATA_NULL> USER_DIRTY_MASK;
	USER_DIRTY_MASK m_bsSyncDirtyMask;
	USER_DIRTY_MASK m_bsUpdateDirtyMask;
	WeakReference<CUser>::Master masterReference;
	friend class WeakReference<CUser>;
};

#endif	//end of define _USER_H_