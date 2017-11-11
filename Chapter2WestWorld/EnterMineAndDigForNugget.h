#ifndef ENTERMINEANDDIGFORNUGGET_H
#define ENTERMINEANDDIGFORNUGGET_H

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

#endif // ENTERMINEANDDIGFORNUGGET_H