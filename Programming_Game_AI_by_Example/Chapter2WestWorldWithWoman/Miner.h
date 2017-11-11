#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"
#include "LocationTypes.h"

const int MaxNuggets = 5;
const int ThirstLevel = 10;
const int ComfortLevel = 30;
const int TirednessThreshold = 5;

template <class EntityType>
class StateMachine;

class Miner : public BaseGameEntity
{
private:
	StateMachine<Miner> *m_pStateMachine;
	LocationType m_Location;
	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst;
	int m_iFatigue;
public:
	Miner(int id);
	virtual ~Miner();
	StateMachine<Miner>* GetFSM() const;
	virtual void Update();
	LocationType Location() const;
	void ChangeLocation(LocationType location);
	int GoldCarried() const;
	void AddToGoldCarried(int val);
	void SetGoldCarried(int val);
	bool Fatigued() const;
	void IncreaseFatigue();
	void DecreaseFatigue();
	bool PocketsFull() const;
	bool Thirsty() const;
	void BuyAndDrinkAWhiskey();
	int Wealth() const;
	void AddToWealth(int val);
};

#endif // MINER_H