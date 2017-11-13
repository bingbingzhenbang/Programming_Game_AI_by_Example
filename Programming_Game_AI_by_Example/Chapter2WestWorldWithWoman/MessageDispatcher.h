#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H

#include <set>
#include "Telegram.h"

class BaseGameEntity;

class MessageDispatcher
{
private:
	std::set<Telegram> m_MessageQueue;
	MessageDispatcher(){}
	void Discharge(BaseGameEntity *pReceiver, const Telegram &msg);
public:
	static MessageDispatcher* Instance();
	void DispatchMessage(double delay, int sender, int receiver, int msg, void *info);
	void DispatchDelayMessage();
};

#endif // MESSAGEDISPATCHER_H