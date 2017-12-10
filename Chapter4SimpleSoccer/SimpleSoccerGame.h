#ifndef SIMPLESOCCERGAME_H
#define SIMPLESOCCERGAME_H

#include <memory>

class SoccerPitch;

class SimpleSoccerGame
{
public:
	typedef std::shared_ptr<SimpleSoccerGame> GamePtr;
private:
	static GamePtr m_pInstance;
	SoccerPitch *m_pSoccerPitch;
	SimpleSoccerGame();
public:
	~SimpleSoccerGame();
	static GamePtr Instance();
	void Run();
};

#endif // SIMPLESOCCERGAME_H