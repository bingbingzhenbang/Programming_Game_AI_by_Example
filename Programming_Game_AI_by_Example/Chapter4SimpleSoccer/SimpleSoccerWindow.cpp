#include "SimpleSoccerWindow.h"
#include <QGraphicsView>


SimpleSoccerWindow::SimpleSoccerWindow(QWidget *parent)
:QMainWindow(parent)
{
	m_pScene = new QGraphicsScene();
	m_pView = new QGraphicsView(m_pScene);
	setCentralWidget(m_pView);
}

SimpleSoccerWindow::~SimpleSoccerWindow()
{

}