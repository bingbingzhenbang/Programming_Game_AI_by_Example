#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <iostream>
#include <cmath>

struct Telegram
{
	int m_Sender;
	int m_Receiver;
	int m_Msg;
	double m_DispatchTime;
	void *m_ExtraInfo;
};


#endif // TELEGRAM_H