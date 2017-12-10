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
	int Run();
};

#endif // SIMPLESOCCERRENDERER_H