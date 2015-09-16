////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/21
// Describe:
////////////////////////////////////////////////////////////////////////
#include "BaseDefine.h"
#include "MsgLoginStepHandler.h"
#include "MsgNetwork.pb.h"
#include "User.h"
#include "UserMgr.h"

CMsgLoginStepHandler CMsgLoginStepHandler::s_Handler;

CMsgLoginStepHandler::CMsgLoginStepHandler() : IMsgHandler(CMsgNetwork::kMsgLoginStep)
{

}

void CMsgLoginStepHandler::Process(CMsgNetwork* pMsgNetwork)
{
	DEBUG_TRY
		CHECK(pMsgNetwork);
		CHECK(pMsgNetwork->has_msgloginstep());

		CUser* pUser = CUserMgr::getInstance()->QueryOnlineUserByPeerId(pMsgNetwork->idpeer(0));
		CHECK(pUser);

		const CMsgLoginStep& msgLoginStep = pMsgNetwork->msgloginstep();

		switch (msgLoginStep.naction())
		{
		case LOGINSTEPACT_ENTER_SCENE:
		{
			pUser->EnterScene();
			CMsgNetwork msgEnterScene;
			CMsgLoginStep* pMsgLoginStep = msgEnterScene.mutable_msgloginstep();
			CHECK(pMsgLoginStep);

			pMsgLoginStep->set_naction(LOGINSTEPACT_ENTER_SCENE);

			pUser->SendMsg(&msgEnterScene);
		}
		break;
		case LOGINSTEPACT_LOGIN_OK:
		{
			pUser->LoginOK();
		}
		break;
		default:
			break;
		}
	DEBUG_CATCH
}


