#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <map>

class BaseGameEntity;

class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;
	EntityMap m_EntityMap;
	EntityManager(){}
public:
	static EntityManager* Instance();
	void RegisterEntity(BaseGameEntity *pNewEntity);
	BaseGameEntity* GetEntityFromID(int id) const;
	void RemoveEntity(BaseGameEntity *pEntity);
};

#endif // ENTITYMANAGER_H