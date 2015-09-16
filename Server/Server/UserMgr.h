////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/15
// Describe:Íæ¼Ò¹ÜÀíÆ÷
////////////////////////////////////////////////////////////////////////
#ifndef _USERMGR_H_
#define _USERMGR_H_

#include <string>
#include <map>
#include "BaseDefine.h"
#include "FKMap.h"
#include "User.h"
#include "BasicTypeDef.h"
#include "MsgNetwork.pb.h"

class CUserMgr
{
private:
	CUserMgr();
	~CUserMgr();
public:
	juce_DeclareSingleton_SingleThreaded(CUserMgr, true);
	bool Create();
	CUser* CreateUser(const UserParm_t& rUserParm);
	void ReadyToLoginUser(const UserParm_t& rUserParm);
	bool CreateNewUser(const UserParm_t& rParm);
	bool LoginUser(CUser* pUser);
	void OnTimer();
public:
	bool AddOnlineUser(CUser* pUser);
	CUser* QueryOnlineUser(OBJID idUser);
	CUser* QueryOnlineUserByName(std::string strName);
	CUser* QueryOnlineUserByAccountId(OBJID64 idAccount);
	CUser* QueryOnlineUserByPeerId(OBJID64 idPeer);
public:
	void AddOfflineUser(CUser* pUser);
	CUser* QueryOfflineUser(OBJID idUser);
	CUser* QueryOfflineUserByName(std::string strName);
	CUser* QueryOfflineUserByAccountId(OBJID64 idAccount);
	CUser* QueryOfflineUserByPeerId(OBJID64 idPeer);
	void DeleteOnlineUser(OBJID idUser);
	void DeleteOnlineUserByAccountId(OBJID idAccount);
	void DeleteOfflineUser(OBJID idUser);
public:
	void BroadcastMsg(CMsgNetwork* pMsgNetwork);
	void KickoutUser(OBJID idUser);
	void KickoutUserByPeerId(OBJID64 idPeer);
	void SendErrorMsg(OBJID idUser, uint32_t nAction, const char* szReason, uint32_t nErrorCode = 0);
	void SendErrorMsgByPeerId(OBJID64 idPeer, uint32_t nAction, const char* szReason, uint32_t nErrorCode = 0);
public:
	typedef CFKMap<OBJID, std::string, OBJID64, OBJID64, CUser> USER_FKMAP;//idUser,strName,idAccount,idPeer,CUser*
	USER_FKMAP m_mapOnlineUsers;
	USER_FKMAP m_mapOfflineUsers;
	typedef std::map<OBJID, UserParm_t> USER_PARM_MAP;
	USER_PARM_MAP m_mapUserParm;
};

#endif	//end of define _USERMGR_H_