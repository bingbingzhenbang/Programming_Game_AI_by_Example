#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

#include <QVector2D>

struct Telegram;

class BaseGameEntity
{
private:
	static int m_iNextValidID;
public:
	static int GetNextValidID();
private:
	int m_ID;
	int m_iType;
	bool m_bTag;
	double m_dBoundingRadius;
	void SetID(int val);
protected:
	QVector2D m_vPosition;
	BaseGameEntity(int id);
public:
	virtual ~BaseGameEntity(){}
	int ID() const;
	int EntityType() const;
	void SetEntityType(int type);
	bool IsTagged() const;
	void Tag();
	void UnTag();
	double BRadius() const;
	void SetBRadius(double radius);
	QVector2D Position() const;
	void SetPosition(const QVector2D &pos);
	virtual void Update() = 0;
	virtual bool HandleMessage(const Telegram &msg) = 0;
	virtual void Render() = 0;
};

#endif // BASEGAMEENTITY_H