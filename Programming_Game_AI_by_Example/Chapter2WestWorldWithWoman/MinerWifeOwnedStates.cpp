#include "MinerWifeOwnedStates.h"
#include "StateMachnine.h"
#include "EntityNames.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "MessageTimer.h"
#include "Random.h"
#include <iostream>

MinerWifeGlobalState* MinerWifeGlobalState::Instance()
{
	static MinerWifeGlobalState instance;
	return &instance;
}

void MinerWifeGlobalState::Enter(MinerWife *pMinerWife)
{

}

void MinerWifeGlobalState::Execute(MinerWife *pMinerWife)
{
	if (RandomDouble() < 0.1 && !pMinerWife->GetFSM()->IsInState(*VisitBathroom::Instance()))
	{
		pMinerWife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}

void MinerWifeGlobalState::Exit(MinerWife *pMinerWife)
{

}

bool MinerWifeGlobalState::OnMessage(MinerWife *pMinerWife, const Telegram &msg)
{
	if (msg.m_Msg == Message_HiHoneyImHome)
	{
		std::cout << "\nMessage handled by " << GetNameOfEntity(pMinerWife->ID()) << " at time " << MessageTimer::Instance()->GetCurrentTime();
		std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Cook stew";
		pMinerWife->GetFSM()->ChangeState(CookStew::Instance());
		return true;
	}
	return false;
}

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;
	return &instance;
}

void DoHouseWork::Enter(MinerWife *pMinerWife)
{

}

void DoHouseWork::Execute(MinerWife *pMinerWife)
{
	std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Do house work";
}

void DoHouseWork::Exit(MinerWife *pMinerWife)
{

}

bool DoHouseWork::OnMessage(MinerWife *pMinerWife, const Telegram &msg)
{
	return false;
}

VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;
	return &instance;
}

void VisitBathroom::Enter(MinerWife *pMinerWife)
{
	std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Walk into bathroom";
}

void VisitBathroom::Execute(MinerWife *pMinerWife)
{
	std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Relief";
	pMinerWife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinerWife *pMinerWife)
{
	std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Leave bathroom";
}

bool VisitBathroom::OnMessage(MinerWife *pMinerWife, const Telegram &msg)
{
	return false;
}

CookStew* CookStew::Instance()
{
	static CookStew instance;
	return &instance;
}

void CookStew::Enter(MinerWife *pMinerWife)
{
	if (!pMinerWife->Cooking())
	{
		std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Begin cooking";
		MessageDispatcher::Instance()->DispatchMessage(1.5, pMinerWife->ID(), pMinerWife->ID(), Message_StewReady, NO_ADDITIONAL_INFO);
		pMinerWife->SetCooking(true);
	}
}

void CookStew::Execute(MinerWife *pMinerWife)
{
	std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Cooking";
}

void CookStew::Exit(MinerWife *pMinerWife)
{
	std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Put stew on table";
}

bool CookStew::OnMessage(MinerWife *pMinerWife, const Telegram &msg)
{
	if (msg.m_Msg == Message_StewReady)
	{
		std::cout << "\nMessage handled by " << GetNameOfEntity(pMinerWife->ID()) << " at time " << MessageTimer::Instance()->GetCurrentTime();
		std::cout << "\n" << GetNameOfEntity(pMinerWife->ID()) << " : Stew ready";
		MessageDispatcher::Instance()->DispatchMessage(SEND_MSG_IMMEDIATELY, pMinerWife->ID(), Entity_Miner_Bob, Message_StewReady, NO_ADDITIONAL_INFO);
		pMinerWife->SetCooking(false);
		pMinerWife->GetFSM()->ChangeState(DoHouseWork::Instance());
		return true;
	}
	return false;
}