#include "SimpleSoccerGame.h"
#include "SimpleSoccerTimer.h"
#include "SimpleSoccerRenderer.h"

SimpleSoccerGame::GamePtr SimpleSoccerGame::m_pInstance = 0;

SimpleSoccerGame::SimpleSoccerGame()
{
	m_pTimer = SimpleSoccerTimer::Instance();
	SimpleSoccerRenderer::Instance()->Start();
}

SimpleSoccerGame::~SimpleSoccerGame()
{

}

SimpleSoccerGame::GamePtr SimpleSoccerGame::Instance()
{
	if (m_pInstance == 0)
	{
		m_pInstance.reset(new SimpleSoccerGame());
	}
	return m_pInstance;
}

void SimpleSoccerGame::Run()
{

}