#ifndef SIMPLESOCCERRENDERER_H
#define SIMPLESOCCERRENDERER_H

#include "SimpleSoccerWindow.h"

class SimpleSoccerRenderer
{
private:
	SimpleSoccerWindow m_Window;
	SimpleSoccerRenderer();
public:
	~SimpleSoccerRenderer();
	static SimpleSoccerRenderer* Instance();
	int Start();
	void AddLine(const QVector2D &from, const QVector2D &to);
};

#endif // SIMPLESOCCERRENDERER_H