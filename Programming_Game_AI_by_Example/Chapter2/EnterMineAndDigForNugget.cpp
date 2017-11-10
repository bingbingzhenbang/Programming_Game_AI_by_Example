#include "EnterMineAndDigForNugget.h"
#include "EntityNames.h"
#include <iostream>

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
	if (pMiner->Location() != Location_GoldMine)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": Walk into gold mine";
		pMiner->ChangeLocation(Location_GoldMine);
	}
}