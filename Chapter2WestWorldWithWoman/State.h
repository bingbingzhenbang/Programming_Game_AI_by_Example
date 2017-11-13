#ifndef STATE_H
#define STATE_H

struct Telegram;

template <class EntityType>
class State
{
public:
	virtual ~State(){}
	virtual void Enter(EntityType*) = 0;
	virtual void Execute(EntityType*) = 0;
	virtual void Exit(EntityType*) = 0;
	virtual bool OnMessage(EntityType*, const Telegram&) = 0;
};

#endif // STATE_H