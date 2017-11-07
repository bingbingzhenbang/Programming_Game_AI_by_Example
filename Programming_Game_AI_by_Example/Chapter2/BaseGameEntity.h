#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

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
};

#endif // BASEGAMEENTITY_H