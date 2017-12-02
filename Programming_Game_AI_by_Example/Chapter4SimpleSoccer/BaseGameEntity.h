#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

struct Telegram;

class BaseGameEntity
{
private:
	static int m_iNextValidID;
	int m_ID;
	int m_iType;
	void SetID(int val);
protected:
	BaseGameEntity(int id);
public:
	static int GetNextValidID();
public:
	virtual ~BaseGameEntity(){}
	int ID() const;
	virtual void Update() = 0;
	virtual bool HandleMessage(const Telegram &msg) = 0;
};

#endif // BASEGAMEENTITY_H