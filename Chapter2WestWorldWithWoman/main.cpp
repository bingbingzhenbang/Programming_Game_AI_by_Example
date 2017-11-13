#include "Miner.h"
#include "EntityNames.h"
#include "MessageDispatcher.h"
#include <iostream>

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		MessageDispatcher::Instance()->DispatchDelayMessage();
	}
	std::cout << "\n";
	return 0;
}