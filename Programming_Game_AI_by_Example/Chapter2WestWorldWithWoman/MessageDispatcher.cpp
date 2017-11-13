#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "EntityNames.h"
#include "BaseGameEntity.h"
#include "MessageTimer.h"
#include "MessageTypes.h"
#include <iostream>

void MessageDispatcher::Discharge(BaseGameEntity *pReceiver, const Telegram &msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		std::cout << "\nMessage not handled";
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
		std::cout << "\nNo sender with ID : " << sender << " found";
	}
	BaseGameEntity *pReceiver = EntityManager::Instance()->GetEntityFromID(receiver);
	if (pReceiver == 0)
	{
		std::cout << "\nNo receiver with ID : " << receiver << " found";
	}
	Telegram telegram(0.0f, sender, receiver, msg, info);
	if (delay <= 0.0f)
	{
		std::cout << "\nInstant telegram dispatched at time : " << MessageTimer::Instance()->GetCurrentTime()
			<< " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID())
			<< ". Msg is " << MsgToStr(msg);
		Discharge(pReceiver, telegram);
	}
	else
	{
		telegram.m_DispatchTime = MessageTimer::Instance()->GetCurrentTime() + delay;
		m_MessageQueue.insert(telegram);
	}
}

void MessageDispatcher::DispatchDelayMessage()
{
	double CurentTime = MessageTimer::Instance()->GetCurrentTime();
	while (!m_MessageQueue.empty()
		&& m_MessageQueue.begin()->m_DispatchTime > 0
		&& m_MessageQueue.begin()->m_DispatchTime < CurentTime)
	{
		Telegram telegram = *m_MessageQueue.begin();
		BaseGameEntity *pReceiver = EntityManager::Instance()->GetEntityFromID(telegram.m_Receiver);
		std::cout << "\nQueued telegram ready for dispatch : Sent to "
			<< GetNameOfEntity(pReceiver->ID())
			<< ". Msg is " << MsgToStr(telegram.m_Msg);
		m_MessageQueue.erase(m_MessageQueue.begin());
	}
}