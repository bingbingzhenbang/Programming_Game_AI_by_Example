#include "SimpleSoccerRenderer.h"
#include "SimpleSoccerWindow.h"
#include <QGraphicsScene>
#include <QVector2D>

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

int SimpleSoccerRenderer::Start()
{
	m_Window.show();
	return 0;
}

void SimpleSoccerRenderer::AddLine(const QVector2D &from, const QVector2D &to)
{
	m_Window.GetScene()->addLine(QLineF(from.toPointF(), to.toPointF()));
}