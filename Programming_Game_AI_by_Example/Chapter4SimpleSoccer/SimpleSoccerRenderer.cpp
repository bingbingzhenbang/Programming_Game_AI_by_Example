#include "SimpleSoccerRenderer.h"

SimpleSoccerRenderer::SimpleSoccerRenderer()
{

}

SimpleSoccerRenderer::~SimpleSoccerRenderer()
{

}

SimpleSoccerRenderer* SimpleSoccerRenderer::Instance()
{
	static SimpleSoccerRenderer instance;
	return &instance;
}

int SimpleSoccerRenderer::Run()
{
	m_Window.show();
	return 0;
}