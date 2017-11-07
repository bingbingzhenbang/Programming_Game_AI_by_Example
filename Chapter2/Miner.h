#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"

class State;

class Miner : public BaseGameEntity
{
private:
	State *m_pCurrentState;
	 
	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst;
	int m_iFatigue;
public:
	Miner(int id);
	virtual void Update();
	void ChangeState(State *pNewState);
};

#endif // MINER_H