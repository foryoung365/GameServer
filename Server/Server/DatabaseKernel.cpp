////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:
////////////////////////////////////////////////////////////////////////
#include "DatabaseKernel.h"
#include "INIReader.h"
#include "GameServerDef.h"
#include "GameServer.h"
#include "MsgNetwork.pb.h"

#define DB_KERNEL_THREAD_POOL_SIZE		4	//4个线程

juce_ImplementSingleton_SingleThreaded(CDatabaseKernel);


CDatabaseKernel::CDatabaseKernel() : IKernel(THREAD_INDEX_DATABASE), m_objThreadPool(DB_KERNEL_THREAD_POOL_SIZE)
{
	
}

CDatabaseKernel::~CDatabaseKernel()
{
	m_objThreadPool.removeAllJobs(true, -1);
	for (int i = 0; i < m_vecJobs.size(); ++i)
	{
		CDbJob* pDbJob = m_vecJobs.at(i);
		if (pDbJob == NULL)
		{
			continue;
		}

		SAFE_DELETE(pDbJob);
	}

	CDatabaseKernel::clearSingletonInstance();
}

bool CDatabaseKernel::Create()
{
	bool bSucc = IKernel::Create();
	CHECK_RETURN(bSucc, false);
	
	DbConfig_t stDbConfig;
	CHECK_RETURN(CGameServer::getInstance()->GetGameDbConfig(stDbConfig), false);
	
	for (int i = 0; i < DB_KERNEL_THREAD_POOL_SIZE; ++i)
	{
		CDbJob* pDbJob = new CDbJob(&stDbConfig, i);
		IF_NOT(pDbJob && pDbJob->IsInitOK())
		{
			SAFE_DELETE(pDbJob);
			return false;
		}
		m_vecJobs.push_back(pDbJob);
	}

	return true;
}

void CDatabaseKernel::OnRun()
{
DEBUG_TRY
	this->RecvPipeMessage();

	//检查是否有已完成的任务
	for (int i = 0; i < m_vecJobs.size(); ++i)
	{
		CDbJob* pDbJob = m_vecJobs.at(i);
		if (pDbJob == NULL)
		{
			continue;
		}

		const UserParm_t& rParm = pDbJob->GetUserParm();
		if (rParm.idUser == ID_NONE || m_objThreadPool.contains(pDbJob))
		{
			continue;
		}

		LOADED_USER_DATA_MAP* pMap = pDbJob->GetLoadedUserMap();
		if (pMap != NULL)
		{
			CMsgNetwork msgNetwork;
			CMsgInproc* pMsgInproc = msgNetwork.mutable_msginproc();
			if (pMsgInproc == NULL)
			{
				continue;
			}
			pMsgInproc->set_naction(INPROCACT_GAME_LOAD_USER_FINISHED);
			pMsgInproc->set_idrole(rParm.idUser);
			pMsgInproc->add_u64data(uint64_t(pMap));
			pMsgInproc->add_u64data(rParm.idAccount);
			pMsgInproc->add_u64data(rParm.idPeer);
			pMsgInproc->add_strdata(rParm.strIP);
			this->SendPipeMessage(THREAD_INDEX_GAME, &msgNetwork);
		}

		pDbJob->Reset();
	}

	//分配加载任务
	if (!m_lstLoginUserParms.empty())
	{
		const UserParm_t& rParm = m_lstLoginUserParms.front();
		for (int i = 0; i < m_vecJobs.size(); ++i)
		{
			CDbJob* pDbJob = m_vecJobs.at(i);
			if (pDbJob == NULL)
			{
				continue;
			}

			if (pDbJob->GetUserParm().idUser != ID_NONE ||  m_objThreadPool.contains(pDbJob))
			{
				continue;
			}

			pDbJob->StartToLoadUserData(rParm, m_objThreadPool);
			m_lstLoginUserParms.pop_front();
			break;
		}
	}
DEBUG_CATCH
}

void CDatabaseKernel::OnTimer()
{

}

void CDatabaseKernel::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

void CDatabaseKernel::Release()
{
	CDatabaseKernel::deleteInstance();
}

void CDatabaseKernel::AddLoadUserParm(const UserParm_t& rParm)
{
	m_lstLoginUserParms.push_back(rParm);
}
