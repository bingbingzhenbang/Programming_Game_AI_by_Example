#include "Miner.h"
#include "EntityNames.h"
#include <iostream>

int main()
{
	Miner miner(Entity_Miner_Bob);
	for (int i = 0; i < 100; ++i)
	{
		miner.Update();
	}
	std::cout << "\n";
	return 0;
}