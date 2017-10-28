#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

class BaseEntity
{
private:
	int m_ID;
	static int m_iNextValidID;
	void SetID(int val);
public:
	BaseEntity(int id);
	virtual ~BaseEntity(){}

};

#endif // BASEGAMEENTITY_H