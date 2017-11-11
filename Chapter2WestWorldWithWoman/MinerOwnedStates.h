#ifndef MINEROWNEDSTATES_H
#define MINEROWNEDSTATES_H

#include "State.h"
#include "Miner.h"

class EnterMineAndDigForNugget : public State<Miner>
{
private:
	EnterMineAndDigForNugget(){}
public:
	static EnterMineAndDigForNugget* Instance();
	virtual void Enter(Miner *pMiner);
	virtual void Execute(Miner *pMiner);
	virtual void Exit(Miner *pMiner);
};

class VisitBankAndDepositGold : public State<Miner>
{
private:
	VisitBankAndDepositGold(){}
public:
	static VisitBankAndDepositGold* Instance();
	virtual void Enter(Miner *pMiner);
	virtual void Execute(Miner *pMiner);
	virtual void Exit(Miner *pMiner);
};

class GoHomeAndSleepTilRested : public State<Miner>
{
private:
	GoHomeAndSleepTilRested(){}
public:
	static GoHomeAndSleepTilRested* Instance();
	virtual void Enter(Miner *pMiner);
	virtual void Execute(Miner *pMiner);
	virtual void Exit(Miner *pMiner);
};

class QuenchThirst : public State<Miner>
{
private:
	QuenchThirst(){}
public:
	static QuenchThirst* Instance();
	virtual void Enter(Miner *pMiner);
	virtual void Execute(Miner *pMiner);
	virtual void Exit(Miner *pMiner);
};

#endif // MINEROWNEDSTATES_H