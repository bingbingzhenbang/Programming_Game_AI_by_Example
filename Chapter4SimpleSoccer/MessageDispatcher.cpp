#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "BaseGameEntity.h"
#include "SimpleSoccerTimer.h"

void MessageDispatcher::Discharge(BaseGameEntity *pReceiver, const Telegram &msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
	}
}

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void *info)
{
	BaseGameEntity *pSender = EntityManager::Instance()->GetEntityFromID(sender);
	if (pSender == 0)
	{
		return;
	}
	BaseGameEntity *pReceiver = EntityManager::Instance()->GetEntityFromID(receiver);
	if (pReceiver == 0)
	{
		return;
	}
	Telegram telegram(0.0f, sender, receiver, msg, info);
	if (delay <= 0.0f)
	{
		Discharge(pReceiver, telegram);
	}
	else
	{
		telegram.m_DispatchTime = SimpleSoccerTimer::Instance()->GetCurrentTime() + delay;
		m_MessageQueue.insert(telegram);
	}
}

void MessageDispatcher::DispatchDelayMessage()
{
	double CurentTime = SimpleSoccerTimer::Instance()->GetCurrentTime();
	while (!m_MessageQueue.empty()
		&& m_MessageQueue.begin()->m_DispatchTime > 0
		&& m_MessageQueue.begin()->m_DispatchTime < CurentTime)
	{
		Telegram telegram = *m_MessageQueue.begin();
		BaseGameEntity *pReceiver = EntityManager::Instance()->GetEntityFromID(telegram.m_Receiver);
		Discharge(pReceiver, telegram);
		m_MessageQueue.erase(m_MessageQueue.begin());
	}
}