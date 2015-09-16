////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MsgMoveHandler.h"
#include "juce_core/juce_core.h"
#include "BaseDefine.h"
#include "MsgNetwork.pb.h"
#include "User.h"
#include "UserMgr.h"

CMsgMoveHanlder CMsgMoveHanlder::s_Handler;


CMsgMoveHanlder::CMsgMoveHanlder() : IMsgHandler(CMsgNetwork::kMsgMove)
{

}


void CMsgMoveHanlder::Process(CMsgNetwork* pMsgNetwork)
{
	DEBUG_TRY
		CHECK(pMsgNetwork && pMsgNetwork->has_msgmove());
		const CMsgMove& rMsgWalk = pMsgNetwork->msgmove();

		CUser* pUser = CUserMgr::getInstance()->QueryOnlineUserByPeerId(pMsgNetwork->idpeer(0));

		switch (rMsgWalk.naction())
		{
		case MOVEACT_WALK:
		{
			MoveActionInfo_t stInfo;
			stInfo.fStartX = rMsgWalk.fstartx();
			stInfo.fStartY = rMsgWalk.fstarty();
			stInfo.fStartZ = rMsgWalk.fstartz();
			stInfo.fEndX = rMsgWalk.fendx();
			stInfo.fEndY = rMsgWalk.fendy();
			stInfo.fEndZ = rMsgWalk.fendz();
			stInfo.fVelocity = rMsgWalk.fvelecity();
			stInfo.tStartTime = rMsgWalk.tstarttime();
			stInfo.tEndTime = rMsgWalk.tendtime();
			pUser->ClientMoveTo(&stInfo);
		}
		break;
		default:
			break;
		}
	DEBUG_CATCH
}
