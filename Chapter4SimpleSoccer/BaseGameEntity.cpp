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
: m_bTag(false),
m_dBoundingRadius(0.0)
{
	SetID(id);
}

int BaseGameEntity::ID() const
{
	return m_ID;
}

int BaseGameEntity::EntityType() const
{
	return m_iType;
}

void BaseGameEntity::SetEntityType(int type)
{
	m_iType = type;
}

bool BaseGameEntity::IsTagged() const
{
	return m_bTag;
}

void BaseGameEntity::Tag()
{
	m_bTag = true;
}

void BaseGameEntity::UnTag()
{
	m_bTag = false;
}

double BaseGameEntity::BRadius() const
{
	return m_dBoundingRadius;
}

void BaseGameEntity::SetBRadius(double radius)
{
	m_dBoundingRadius = radius;
}

QVector2D BaseGameEntity::Position() const
{
	return m_vPosition;
}

void BaseGameEntity::SetPosition(const QVector2D &pos)
{
	m_vPosition = pos;
}