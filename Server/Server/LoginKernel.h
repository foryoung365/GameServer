////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:µÇÂ¼Ïß³Ì
////////////////////////////////////////////////////////////////////////
#ifndef _LOGINKERNEL_H_
#define _LOGINKERNEL_H_

#include "BaseDefine.h"
#include "Kernel.h"
#include "GameDatabase.h"
#include "BasicTypeDef.h"
#include "DKMap.h"
#include "Timer.h"

class CLoginKernel : public IKernel
{
private:
	CLoginKernel();
	~CLoginKernel();
public:
	juce_DeclareSingleton_SingleThreaded(CLoginKernel, true);
	virtual bool Create();
	virtual void Release();
	
public:
	static CGameDatabase* GetDatabase();
	bool AddClientInfo(ClientInfo_t* pInfo);
	ClientInfo_t* QueryClientInfo(OBJID64 idAccount);
	ClientInfo_t* QueryClientInfoByPeerID(OBJID64 idPeer);
	void DeleteClientInfo(OBJID64 idAccount);
	void DeleteClientInfoByPeerID(OBJID64 idPeer);
	void SendRoleInfo(ClientInfo_t* pInfo);
	uint32_t GetOpenTime() { return m_u32OpenTime; }
public:
	void SendErrorMsg(OBJID64 idPeer, uint32_t nAction, const char* szReason, uint32_t nErrorCode = 0);
protected:
	virtual void OnRun();
	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);
	CGameDatabase* GetDatabasePriv();
private:
	bool CreateConfig();
private:
	CGameDatabase* m_pDb;
	typedef CDKMap<OBJID64, OBJID64, ClientInfo_t> CLIENT_INFO_DKMAP;//idAccount,idPeer,ClientInfo_t*
	CLIENT_INFO_DKMAP m_mapClients;
	uint32_t m_u32OpenTime;
	CTimer m_tClientTimeOut;
};

#endif	//end of define _LOGINKERNEL_H_