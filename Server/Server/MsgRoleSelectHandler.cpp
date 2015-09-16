////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MsgRoleSelectHandler.h"
#include "BaseDefine.h"
#include "juce_core/juce_core.h"
#include "MsgNetwork.pb.h"
#include "RoleTypeSet.h"
#include "StrDef.h"
#include "LoginKernel.h"
#include "User.h"

CMsgRoleSelectHandler CMsgRoleSelectHandler::s_Handler;

CMsgRoleSelectHandler::CMsgRoleSelectHandler() : IMsgHandler(CMsgNetwork::kMsgRoleSelect)
{

}

void CMsgRoleSelectHandler::Process(CMsgNetwork* pMsgNetwork)
{
	DEBUG_TRY
		CHECK(pMsgNetwork && pMsgNetwork->has_msgroleselect());
		const CMsgRoleSelect& rMsgRoleSelect = pMsgNetwork->msgroleselect();

		ClientInfo_t* pInfo = CLoginKernel::getInstance()->QueryClientInfoByPeerID(pMsgNetwork->idpeer(0));
		CHECK(pInfo);

		if (rMsgRoleSelect.roles_size() <= 0)
		{
			CHECK(rMsgRoleSelect.has_idroleselected());
			CHECK(pInfo->IsValidRoleId(rMsgRoleSelect.idroleselected()));
			pInfo->idUser = rMsgRoleSelect.idroleselected();
		}
		else
		{
			//检查是否还有空位
			if (pInfo->setRoleIds.size() >= ACCOUNT_USER_AMOUNT_LIMIT)
			{
				CLoginKernel::getInstance()->SendErrorMsg(pMsgNetwork->idpeer(0), ERRACT_REGISTER_FAILED, STRDEF_ROLE_FULL);
				return;
			}

			const CRoleSummary& rRole = rMsgRoleSelect.roles(0);
			//检查RoleType是否合法
			OBJID32 idRoleType = rRole.idroletype();
			CRoleTypeData* pRoleTypeData = CRoleTypeSet::getInstance()->QueryRoleType(idRoleType);
			if (pRoleTypeData == NULL)
			{
				CLoginKernel::getInstance()->SendErrorMsg(pMsgNetwork->idpeer(0), ERRACT_REGISTER_FAILED, STRDEF_BAD_ROLE_TYPE);
				return;
			}

			//检查name是否合法
			if (!CUser::IsNameValid(rRole.szname().c_str()))
			{
				CLoginKernel::getInstance()->SendErrorMsg(pMsgNetwork->idpeer(0), ERRACT_REGISTER_FAILED, STRDEF_NAME_INVALID);
				return;
			}

			SQLBUF strSQL;

			//TO-DO:RoleType和地图先写死，后面再支持配置.
			strSQL << "INSERT INTO " << TBL_USER << "(name, account_id, role_type, level, scene_id, pos_x, pos_y, pos_z, record_scene_id, record_x, record_y, record_z, life, mana) VALUES('" 
				<< rRole.szname().c_str() << "'," << pInfo->idAccount << "," << idRoleType << "," << pRoleTypeData->base_level << ","
				<< 1000 << "," << 100 << "," << 100 << "," << 100 << "," << 1000 << "," << 100 << "," << 100 << "," << 100 << "," 
				<< pRoleTypeData->base_life << "," << pRoleTypeData->base_mana << ")";


			pInfo->idUser = CLoginKernel::GetDatabase()->InsertBySQL(strSQL);

			if (pInfo->idUser == ID_NONE)
			{
				CLoginKernel::getInstance()->SendErrorMsg(pMsgNetwork->idpeer(0), ERRACT_REGISTER_FAILED, STRDEF_NAME_ALREADY_EXISTS);
				return;
			}
		}

		//通知ServerSocketKernel玩家已经登录到GameKernel了
		CMsgNetwork msgSS;
		CMsgInproc* pMsgInproc = msgSS.mutable_msginproc();
		CHECK(pMsgInproc);
		pMsgInproc->set_naction(INPROCACT_SS_USER_LOGIN_TO_GAME);
		pMsgInproc->set_idrole(pInfo->idUser);
		pMsgInproc->add_u64data(pInfo->idPeer);
		pMsgInproc->add_u64data(pInfo->idAccount);

		CLoginKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, &msgSS);

		CLoginKernel::getInstance()->DeleteClientInfo(pInfo->idAccount);

	DEBUG_CATCH
}
