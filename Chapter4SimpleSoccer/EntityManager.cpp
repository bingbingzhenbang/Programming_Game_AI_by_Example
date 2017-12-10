#include "EntityManager.h"
#include "BaseGameEntity.h"

EntityManager* EntityManager::Instance()
{
	static EntityManager instance;
	return &instance;
}

void EntityManager::RegisterEntity(BaseGameEntity *pNewEntity)
{
	m_EntityMap.insert(std::pair<int, BaseGameEntity*>(pNewEntity->ID(), pNewEntity));
}

BaseGameEntity* EntityManager::GetEntityFromID(int id) const
{
	auto iter = m_EntityMap.find(id);
	if (iter == m_EntityMap.end())
		return 0;
	else
		return iter->second;
}

void EntityManager::RemoveEntity(BaseGameEntity *pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}