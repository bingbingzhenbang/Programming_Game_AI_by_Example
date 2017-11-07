#include "Miner.h"

Miner::Miner(int id)
:BaseGameEntity(id), m_pCurrentState(0)
{

}

void Miner::Update()
{
	++m_iThirst;
}