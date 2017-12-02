#include "BaseGameEntity.h"
#include <cassert>

int BaseGameEntity::m_iNextValidID = 0;

int BaseGameEntity::GetNextValidID()
{
	return m_iNextValidID;
}

void BaseGameEntity::SetID(int val)
{
	assert(val >= m_iNextValidID);
	m_ID = val;
	m_iNextValidID = m_ID + 1;
}

BaseGameEntity::BaseGameEntity(int id)
{
	SetID(id);
}

int BaseGameEntity::ID() const
{
	return m_ID;
}