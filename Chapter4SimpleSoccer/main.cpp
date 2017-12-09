#include <QtWidgets/QApplication>
#include "SimpleSoccerRenderer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SimpleSoccerRenderer::Instance()->Run();
	return a.exec();
}