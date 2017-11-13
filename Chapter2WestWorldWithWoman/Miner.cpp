#include "Miner.h"
#include "StateMachnine.h"
#include "MinerOwnedStates.h"
#include <cassert>

Miner::Miner(int id)
:BaseGameEntity(id),
m_Location(Location_Shack),
m_iGoldCarried(0),
m_iMoneyInBank(0),
m_iThirst(0),
m_iFatigue(0)
{
	m_pStateMachine = new StateMachine<Miner>(this);
	m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());
}

Miner::~Miner()
{
	delete m_pStateMachine;
}

StateMachine<Miner>* Miner::GetFSM() const
{
	return m_pStateMachine;
}

void Miner::Update()
{
	++m_iThirst;
	m_pStateMachine->Update();
}

bool Miner::HandleMessage(const Telegram &msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

LocationType Miner::Location() const
{
	return m_Location;
}

void Miner::ChangeLocation(LocationType location)
{
	m_Location = location;
}

int Miner::GoldCarried() const
{
	return m_iGoldCarried;
}

void Miner::AddToGoldCarried(int val)
{
	assert(val >= 0);
	m_iGoldCarried += val;
}

void Miner::SetGoldCarried(int val)
{
	assert(val >= 0);
	m_iGoldCarried = val;
}

bool Miner::Fatigued() const
{
	return m_iFatigue > TirednessThreshold;
}

void Miner::IncreaseFatigue()
{
	++m_iFatigue;
}

void Miner::DecreaseFatigue()
{
	--m_iFatigue;
}

bool Miner::PocketsFull() const
{
	return m_iGoldCarried >= MaxNuggets;
}

bool Miner::Thirsty() const
{
	return m_iThirst >= ThirstLevel;
}

void Miner::BuyAndDrinkAWhiskey()
{
	m_iThirst = 0;
	m_iMoneyInBank -= 2;
}

int Miner::Wealth() const
{
	return m_iMoneyInBank;
}

void Miner::AddToWealth(int val)
{
	assert(val >= 0);
	m_iMoneyInBank += val;
}