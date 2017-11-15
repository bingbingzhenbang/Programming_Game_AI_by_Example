#include "MinerOwnedStates.h"
#include "StateMachnine.h"
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
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if (pMiner->Thirsty())
	{
		pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave gold mine";
}

bool EnterMineAndDigForNugget::OnMessage(Miner *pMiner, const Telegram &msg)
{
	return false;
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
	if (pMiner->Location() != Location_Bank)
	{
		std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Walk into the bank";
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
		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave the bank";
}

bool VisitBankAndDepositGold::OnMessage(Miner *pMiner, const Telegram &msg)
{
	return false;
}

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
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
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

bool GoHomeAndSleepTilRested::OnMessage(Miner *pMiner, const Telegram &msg)
{
	return false;
}

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
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}

void QuenchThirst::Exit(Miner *pMiner)
{
	std::cout << "\n" << GetNameOfEntity(pMiner->ID()) << " : Leave saloon";
}

bool QuenchThirst::OnMessage(Miner *pMiner, const Telegram &msg)
{
	return false;
}

EatStew* EatStew::Instance()
{
	static EatStew instance;
	return &instance;
}

void EatStew::Enter(Miner *pMiner)
{

}

void EatStew::Execute(Miner *pMiner)
{

}

void EatStew::Exit(Miner *pMiner)
{

}

bool EatStew::OnMessage(Miner *pMiner, const Telegram &msg)
{
	return false;
}