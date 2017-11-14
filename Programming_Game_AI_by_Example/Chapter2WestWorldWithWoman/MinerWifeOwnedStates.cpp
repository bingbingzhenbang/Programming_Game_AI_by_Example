#include "MinerWifeOwnedStates.h"
#include "StateMachnine.h"
#include "EntityNames.h"
#include <iostream>

WifeGlobalState* WifeGlobalState::Instance()
{
	static WifeGlobalState instance;
	return &instance;
}

void WifeGlobalState::Enter(MinerWife *pMinerWife)
{

}

void WifeGlobalState::Execute(MinerWife *pMinerWife)
{

}

void WifeGlobalState::Exit(MinerWife *pMinerWife)
{

}

bool WifeGlobalState::OnMessage(MinerWife *pMinerWife, const Telegram &msg)
{
	return false;
}