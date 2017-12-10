#include "SimpleSoccerGame.h"
#include "SimpleSoccerRenderer.h"

SimpleSoccerGame::GamePtr SimpleSoccerGame::m_pInstance = 0;

SimpleSoccerGame::SimpleSoccerGame()
{
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