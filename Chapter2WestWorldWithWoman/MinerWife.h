#ifndef MINERWIFE_H
#define MINERWIFE_H

#include "BaseGameEntity.h"
#include "LocationTypes.h"

template <class EntityType>
class StateMachine;

class MinerWife : public BaseGameEntity
{
private:
	StateMachine<MinerWife> *m_pStateMachine;
	LocationType m_Location;
	bool m_bCooking;
public:
	MinerWife(int id);
	virtual ~MinerWife();
	StateMachine<MinerWife>* GetFSM() const;
	virtual void Update();
	virtual bool HandleMessage(const Telegram &msg);
	LocationType Location() const;
	void ChangeLocation(LocationType location);
	bool Cooking() const;
	void SetCooking(bool val);
};

#endif // MINERWIFE_H