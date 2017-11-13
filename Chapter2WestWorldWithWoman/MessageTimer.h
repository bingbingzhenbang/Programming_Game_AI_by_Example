#ifndef MESSAGETIMER_H
#define MESSAGETIMER_H

#include <chrono>

class MessageTimer
{
private:
	std::chrono::system_clock::time_point m_StartTime;
	MessageTimer()
	{
		m_StartTime = std::chrono::high_resolution_clock::now();
	}
public:
	static MessageTimer* Instance()
	{
		static MessageTimer instance;
		return &instance;
	}
	double GetCurrentTime()
	{
		return 0.001 * std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - m_StartTime).count();
	}
};

#endif // MESSAGETIMER_H