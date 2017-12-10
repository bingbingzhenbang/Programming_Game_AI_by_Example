#ifndef SIMPLESOCCERTIMER_H
#define SIMPLESOCCERTIMER_H

#include <chrono>

class SimpleSoccerTimer
{
private:
	std::chrono::system_clock::time_point m_StartTime;
	SimpleSoccerTimer()
	{
		m_StartTime = std::chrono::high_resolution_clock::now();
	}
public:
	static SimpleSoccerTimer* Instance()
	{
		static SimpleSoccerTimer instance;
		return &instance;
	}
	double GetCurrentTime()
	{
		return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - m_StartTime).count();
	}
};

#endif // SIMPLESOCCERTIMER_H