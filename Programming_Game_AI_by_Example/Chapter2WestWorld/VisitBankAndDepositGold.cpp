#include "VisitBankAndDepositGold.h"
#include "EnterMineAndDigForNugget.h"
#include "GoHomeAndSleepTilRested.h"
#include "EntityNames.h"
#include <iostream>

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
	if (pMiner->Location() != Location_Bank)
	{
		std::cout <<"\n"<< GetNameOfEntity(pMiner->ID()) << " : Walk into the bank";
		pMiner->ChangeLocation(Location_Bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
	pMiner->AddToWealth(pMiner->GoldCarried());
	pMiner->SetGoldCarried(0);
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Depositing gold. Total savings now: " << pMiner->Wealth();
	if (pMiner->Wealth() >= ComfortLevel)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Rich enough for now";
		pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave the bank";
}