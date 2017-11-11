#include "QuenchThirst.h"
#include "EnterMineAndDigForNugget.h"
#include "EntityNames.h"
#include <iostream>

QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner *pMiner)
{
	if (pMiner->Location() != Location_Saloon)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Walk into saloon";
		pMiner->ChangeLocation(Location_Saloon);
	}
}

void QuenchThirst::Execute(Miner *pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Drink";
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}

void QuenchThirst::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave saloon";
}