#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <cassert>

template <class EntityType>
class StateMachine
{
private:
	EntityType *m_pOwner;
	State<EntityType> *m_pGlobalState;
	State<EntityType> *m_pCurrentState;
	State<EntityType> *m_pPreviousState;
public:
	StateMachine(EntityType *owner)
		:m_pOwner(owner),
		 m_pGlobalState(0),
		 m_pCurrentState(0),
		 m_pPreviousState(0)
	{}
	State<EntityType>* GlobalState() const
	{
		return m_pGlobalState;
	}
	State<EntityType>* CurrentState() const
	{
		return m_pCurrentState;
	}
	State<EntityType>* PreviousState() const
	{
		return m_pPreviousState;
	}
	void SetGlobalState(State<EntityType> *s)
	{
		m_pGlobalState = s;
	}
	void SetCurrentState(State<EntityType> *s)
	{
		m_pCurrentState = s;
	}
	void SetPreviousState(State<EntityType> *s)
	{
		m_pPreviousState = s;
	}
	void Update()
	{
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}
	void ChangeState(State<EntityType> *pNewState)
	{
		assert(pNewState);
		m_pPreviousState = m_pCurrentState;
		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
	bool IsInState(const State<EntityType> &s) const
	{
		return typeid(*m_pCurrentState) == typeid(s);
	}
};

#endif // STATEMACHINE_H