#include <QtWidgets/QApplication>
#include "SimpleSoccerGame.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SimpleSoccerGame::Instance()->Run();
	return a.exec();
}