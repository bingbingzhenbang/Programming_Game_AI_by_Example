#ifndef SIMPLESOCCERRENDER_H
#define SIMPLESOCCERRENDER_H

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

#endif // SIMPLESOCCERRENDER_H