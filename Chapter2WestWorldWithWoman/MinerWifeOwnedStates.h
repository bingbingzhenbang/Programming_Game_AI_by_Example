#ifndef MINERWIFEOWNEDSTATES_H
#define MINERWIFEOWNEDSTATES_H

#include "State.h"
#include "MinerWife.h"

class WifeGlobalState : public State<MinerWife>
{
private:
	WifeGlobalState(){}
public:
	static WifeGlobalState* Instance();
	virtual void Enter(MinerWife *pMinerWife);
	virtual void Execute(MinerWife *pMinerWife);
	virtual void Exit(MinerWife *pMinerWife);
	virtual bool OnMessage(MinerWife *pMinerWife, const Telegram &msg);
};

#endif // MINERWIFEOWNEDSTATES_H