#include "GoHomeAndSleepTilRested.h"
#include "EnterMineAndDigForNugget.h"
#include "EntityNames.h"
#include <iostream>

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != Location_Shack)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Walk into home";
		pMiner->ChangeLocation(Location_Shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
	if (!pMiner->Fatigued())
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Rested";
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Sleeping";
		pMiner->DecreaseFatigue();
	}
}

void GoHomeAndSleepTilRested::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave home";
}