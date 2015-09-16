////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:
////////////////////////////////////////////////////////////////////////
#include "LoginKernel.h"
#include "GameServerDef.h"
#include "INIReader.h"
#include "GameServer.h"
#include "DbTableDef.h"
#include "GameConfig.h"

#define LOGIN_KERNEL_CLIENT_CLEAN_PERIOD		10

juce_ImplementSingleton_SingleThreaded(CLoginKernel);

CLoginKernel::CLoginKernel() : IKernel(THREAD_INDEX_LOGIN)
{
	m_pDb = NULL;
	m_u32OpenTime = 0;
}

CLoginKernel::~CLoginKernel()
{
	SAFE_RELEASE(m_pDb);
	CLoginKernel::clearSingletonInstance();
}

void CLoginKernel::OnTimer()
{
	if (m_tClientTimeOut.IsTimeEnd())
	{
		std::vector<OBJID64> vecClientIds;
		for (CLIENT_INFO_DKMAP::CIterator it = m_mapClients.Begin(); it != m_mapClients.End(); ++it)
		{
			if ((*it) == NULL)
			{
				continue;
			}

			ClientInfo_t* pInfo = (*it)->pObject;
			if (pInfo == NULL)
			{
				continue;
			}

			if (pInfo->IsTimeOut())
			{
				vecClientIds.push_back(pInfo->idAccount);
			}
		}

		for (int i = 0; i < vecClientIds.size(); ++i)
		{
			this->DeleteClientInfoByPeerID(vecClientIds.at(i));
		}
	}
}

bool CLoginKernel::Create()
{
	bool bSucc = IKernel::Create();
	CHECK_RETURN(bSucc, false);

	INIReader objIni(CONFIG_FILE_NAME);
	DbConfig_t stDbConfig;
	CHECK_RETURN(GameServer()->GetGameDbConfig(stDbConfig), false);

	m_pDb = CGameDatabase::CreateGameDatabase(stDbConfig.strServer.c_str(), stDbConfig.strUser.c_str(), stDbConfig.strPassword.c_str(), stDbConfig.strDatabase.c_str());
	CHECK_RETURN(m_pDb, false);

	m_tClientTimeOut.StartTimer();

	return true;
}

void CLoginKernel::OnRun()
{
DEBUG_TRY
	this->RecvPipeMessage();
DEBUG_CATCH
}

void CLoginKernel::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

void CLoginKernel::Release()
{
	CLoginKernel::deleteInstance();
}

CGameDatabase* CLoginKernel::GetDatabasePriv()
{
	CHECK_RETURN(m_pDb, NULL);

	return m_pDb;
}

CGameDatabase* CLoginKernel::GetDatabase()
{
	return CLoginKernel::getInstance()->GetDatabasePriv();
}

bool CLoginKernel::CreateConfig()
{
	CHECK_RETURN(m_pDb, false);

	SQLBUF strSQL;
	strSQL << "SELECT * FROM " << TBL_CONFIG;

	const CGameRecordset& rRes = m_pDb->Select(strSQL);
	for (int i = 0; i < rRes.size(); ++i)
	{
		const CGameRecordRow& rRow = rRes.at(i);
		int nType = rRow[CONFIGDATA_TYPE];
		switch (nType)
		{
		case GAME_CFGTYPE_OPEN_TIME:
		{
			m_u32OpenTime = rRow[CONFIGDATA_DATA1];
		}
			break;
		default:
			break;
		}
	}

	return true;
}

bool CLoginKernel::AddClientInfo(ClientInfo_t* pInfo)
{
	return m_mapClients.AddObject(pInfo->idAccount, pInfo->idPeer, pInfo);
}

ClientInfo_t* CLoginKernel::QueryClientInfo(OBJID64 idAccount)
{
	return m_mapClients.GetObjectByKey1(idAccount);
}

void CLoginKernel::DeleteClientInfo(OBJID64 idAccount)
{
	ClientInfo_t* pInfo = this->QueryClientInfo(idAccount);
	if (pInfo == NULL)
	{
		return;
	}
	SAFE_DELETE(pInfo);
	m_mapClients.DelObjectByKey1(idAccount);
}

void CLoginKernel::SendRoleInfo(ClientInfo_t* pInfo)
{
	CHECK(pInfo);
	CHECK(pInfo->bVerified);

	//获取账号下人物列表并下发
	CGameDatabase* pDb = CLoginKernel::GetDatabase();
	SQLBUF strSQL;
	strSQL << "SELECT id,name,role_type,level FROM " << TBL_USER << " WHERE account_id=" << pInfo->idAccount << " LIMIT " << ACCOUNT_USER_AMOUNT_LIMIT;
	const CGameRecordset& rRes = pDb->Select(strSQL);

	CMsgNetwork msgNetwork;
	msgNetwork.add_idpeer(pInfo->idPeer);
	CMsgRoleSelect* pMsgRoleSelect = msgNetwork.mutable_msgroleselect();
	CHECK(pMsgRoleSelect);
	pMsgRoleSelect->set_idroleselected(ID_NONE);
	for (int i = 0; i < rRes.size(); ++i)
	{
		const CGameRecordRow& rRow = rRes.at(i);
		CRoleSummary* pRole = pMsgRoleSelect->add_roles();
		pRole->set_idrole(rRow["id"]);
		pRole->set_szname(rRow["name"]);
		pRole->set_idroletype(rRow["role_type"]);
		pRole->set_nlevel(rRow["level"]);
		pInfo->setRoleIds.insert(rRow["id"]);
	}

	CLoginKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, &msgNetwork);
}

ClientInfo_t* CLoginKernel::QueryClientInfoByPeerID(OBJID64 idPeer)
{
	return m_mapClients.GetObjectByKey2(idPeer);
}

void CLoginKernel::SendErrorMsg(OBJID64 idPeer, uint32_t nAction, const char* szReason, uint32_t nErrorCode /*= 0*/)
{
	CHECK(idPeer);
	CHECK(nAction != ERRACT_NONE);

	CMsgNetwork msg;
	msg.add_idpeer(idPeer);
	CMsgError* pMsgError = msg.mutable_msgerror();
	CHECK(pMsgError);
	pMsgError->set_naction(nAction);
	pMsgError->set_strreason(szReason);
	if (nErrorCode != 0)
	{
		pMsgError->set_nerrorcode(nErrorCode);
	}

	this->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, &msg);
}

void CLoginKernel::DeleteClientInfoByPeerID(OBJID64 idPeer)
{
	ClientInfo_t* pInfo = this->QueryClientInfoByPeerID(idPeer);
	if (pInfo == NULL)
	{
		return;
	}
	SAFE_DELETE(pInfo);
	m_mapClients.DelObjectByKey2(idPeer);
}
