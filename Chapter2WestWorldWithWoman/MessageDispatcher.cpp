#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "BaseGameEntity.h"
#include "EntityNames.h"
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

}