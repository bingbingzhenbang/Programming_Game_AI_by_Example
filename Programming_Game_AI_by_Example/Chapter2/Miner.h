#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"
#include "LocationTypes.h"

template <class EntityType>
class State;

class Miner : public BaseGameEntity
{
private:
	State<Miner> *m_pCurrentState;
	LocationType m_Location;
	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst;
	int m_iFatigue;
public:
	Miner(int id);
	virtual void Update();
	void ChangeState(State<Miner> *pNewState);
	LocationType Location() const;
	void ChangeLocation(LocationType location);
};

#endif // MINER_H