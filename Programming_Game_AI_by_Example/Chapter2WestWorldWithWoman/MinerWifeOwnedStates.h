#ifndef MINERWIFEOWNEDSTATES_H
#define MINERWIFEOWNEDSTATES_H

#include "State.h"
#include "MinerWife.h"

class MinerWifeGlobalState : public State<MinerWife>
{
private:
	MinerWifeGlobalState(){}
public:
	static MinerWifeGlobalState* Instance();
	virtual void Enter(MinerWife *pMinerWife);
	virtual void Execute(MinerWife *pMinerWife);
	virtual void Exit(MinerWife *pMinerWife);
	virtual bool OnMessage(MinerWife *pMinerWife, const Telegram &msg);
};

class DoHouseWork : public State<MinerWife>
{
private:
	DoHouseWork(){}
public:
	static DoHouseWork* Instance();
	virtual void Enter(MinerWife *pMinerWife);
	virtual void Execute(MinerWife *pMinerWife);
	virtual void Exit(MinerWife *pMinerWife);
	virtual bool OnMessage(MinerWife *pMinerWife, const Telegram &msg);
};

class VisitBathroom : public State<MinerWife>
{
private:
	VisitBathroom(){}
public:
	static VisitBathroom* Instance();
	virtual void Enter(MinerWife *pMinerWife);
	virtual void Execute(MinerWife *pMinerWife);
	virtual void Exit(MinerWife *pMinerWife);
	virtual bool OnMessage(MinerWife *pMinerWife, const Telegram &msg);
};

class CookStew : public State<MinerWife>
{
private:
	CookStew(){}
public:
	static CookStew* Instance();
	virtual void Enter(MinerWife *pMinerWife);
	virtual void Execute(MinerWife *pMinerWife);
	virtual void Exit(MinerWife *pMinerWife);
	virtual bool OnMessage(MinerWife *pMinerWife, const Telegram &msg);
};

#endif // MINERWIFEOWNEDSTATES_H