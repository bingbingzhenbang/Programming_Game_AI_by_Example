#include "MinerWife.h"
#include "StateMachnine.h"
#include <cassert>

MinerWife::MinerWife(int id)
: BaseGameEntity(id),
m_Location(Location_Shack),
m_bCooking(false)
{
	m_pStateMachine = new StateMachine<MinerWife>(this);
}

MinerWife::~MinerWife()
{
	delete m_pStateMachine;
}

StateMachine<MinerWife>* MinerWife::GetFSM() const
{
	return m_pStateMachine;
}

void MinerWife::Update()
{
	m_pStateMachine->Update();
}

bool MinerWife::HandleMessage(const Telegram &msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

LocationType MinerWife::Location() const
{
	return m_Location;
}

void MinerWife::ChangeLocation(LocationType location)
{
	m_Location = location;
}

bool MinerWife::Cooking() const
{
	return m_bCooking;
}

void MinerWife::SetCooking(bool val)
{
	m_bCooking = val;
}