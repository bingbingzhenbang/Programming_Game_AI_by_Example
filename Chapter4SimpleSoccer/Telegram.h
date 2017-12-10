#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <cmath>

const double SmallestDelay = 0.25;

struct Telegram
{
	double m_DispatchTime;
	int m_Sender;
	int m_Receiver;
	int m_Msg;
	void *m_ExtraInfo;
	Telegram() :
		m_DispatchTime(-1),
		m_Sender(-1),
		m_Receiver(-1),
		m_Msg(-1),
		m_ExtraInfo(0)
	{}
	Telegram(double delay, int sender, int receiver, int msg, void *info) :
		m_DispatchTime(delay),
		m_Sender(sender),
		m_Receiver(receiver),
		m_Msg(msg),
		m_ExtraInfo(info)
	{}
};

inline bool operator==(const Telegram &t1, const Telegram &t2)
{
	return (fabs(t1.m_DispatchTime - t2.m_DispatchTime) < SmallestDelay)
		&& (t1.m_Sender == t2.m_Sender)
		&& (t1.m_Receiver == t2.m_Receiver)
		&& (t1.m_Msg == t2.m_Msg);
}

inline bool operator<(const Telegram &t1, const Telegram &t2)
{
	if (t1 == t2)
		return false;
	else
		return t1.m_DispatchTime < t2.m_DispatchTime;
}

#endif // TELEGRAM_H