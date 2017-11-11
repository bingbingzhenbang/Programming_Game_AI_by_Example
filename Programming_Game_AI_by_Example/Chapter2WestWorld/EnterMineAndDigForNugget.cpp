#include "EnterMineAndDigForNugget.h"
#include "VisitBankAndDepositGold.h"
#include "QuenchThirst.h"
#include "EntityNames.h"
#include <iostream>

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
	if (pMiner->Location() != Location_GoldMine)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Walk into gold mine";
		pMiner->ChangeLocation(Location_GoldMine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Pick up a nugget";
	if (pMiner->PocketsFull())
	{
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave gold mine";
}