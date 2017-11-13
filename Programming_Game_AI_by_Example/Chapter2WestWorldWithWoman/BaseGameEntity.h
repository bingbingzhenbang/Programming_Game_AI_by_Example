#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

struct Telegram;

class BaseGameEntity
{
private:
	int m_ID;
	static int m_iNextValidID;
	void SetID(int val);
public:
	BaseGameEntity(int id);
	virtual ~BaseGameEntity(){}
	int ID() const;
	virtual void Update() = 0;
	virtual bool HandleMessage(const Telegram &msg) = 0;
};

#endif // BASEGAMEENTITY_H