#include "Miner.h"
#include "MinerWife.h"
#include "EntityNames.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include <iostream>
#include <thread>

int main()
{
	Miner miner(Entity_Miner_Bob);
	MinerWife wife(Entity_Elsa);
	EntityManager::Instance()->RegisterEntity(&miner);
	EntityManager::Instance()->RegisterEntity(&wife);
	for (int i = 0; i < 100; ++i)
	{
		miner.Update();
		wife.Update();
		MessageDispatcher::Instance()->DispatchDelayMessage();
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
	std::cout << "\n";
	return 0;
}