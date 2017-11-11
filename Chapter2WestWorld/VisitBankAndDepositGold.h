#ifndef VISITBANKANDDEPOSITGOLD_H
#define VISITBANKANDDEPOSITGOLD_H

#include "State.h"
#include "Miner.h"

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

#endif // VISITBANKANDDEPOSITGOLD_H