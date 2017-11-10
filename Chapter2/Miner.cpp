#include "Miner.h"
#include "State.h"
#include <cassert>

Miner::Miner(int id)
:BaseGameEntity(id),
m_pCurrentState(0),
m_iGoldCarried(0),
m_iMoneyInBank(0),
m_iThirst(0),
m_iFatigue(0)
{

}

void Miner::Update()
{
	++m_iThirst;
	if (m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}

void Miner::ChangeState(State<Miner> *pNewState)
{
	assert(m_pCurrentState && pNewState);
	m_pCurrentState->Exit(this);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(this);
}

LocationType Miner::Location() const
{
	return m_Location;
}

void Miner::ChangeLocation(LocationType location)
{
	m_Location = location;
}