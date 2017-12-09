#ifndef SIMPLESOCCERWINDOW_H
#define SIMPLESOCCERWINDOW_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;

class SimpleSoccerWindow : public QMainWindow
{
	Q_OBJECT
public:
	SimpleSoccerWindow(QWidget *parent = 0);
	~SimpleSoccerWindow();


private:
	QGraphicsScene *m_pScene;
	QGraphicsView *m_pView;
};

#endif // SIMPLESOCCERWINDOW_H