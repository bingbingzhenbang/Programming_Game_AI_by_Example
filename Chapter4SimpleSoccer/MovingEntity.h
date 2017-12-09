#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "BaseGameEntity.h"

class MovingEntity : public BaseGameEntity
{
protected:
	double m_dMass;
	double m_dMaxSpeed;
	double m_dMaxForce;
	double m_dMaxTurnRate;
	QVector2D m_vVelocity;
	QVector2D m_vHeading;
	QVector2D m_vSide;
public:
	MovingEntity(double radius, const QVector2D &pos,
		double mass, double max_speed, double max_force, double max_turn_rate, const QVector2D &velocity, const QVector2D &heading);
	virtual ~MovingEntity(){}
	double Mass() const;
	double MaxSpeed() const;
	void SetMaxSpeed(double max_speed);
	double MaxForce() const;
	void SetMaxForce(double max_force);
	double MaxTurnRate() const;
	void SetMaxTurnRate(double max_turn_rate);
	double Speed() const;
	double SpeedSquared() const;
	QVector2D Velocity() const;
	QVector2D Heading() const;
	void SetHeading(const QVector2D &heading);
	QVector2D Side() const;
};

#endif // MOVINGENTITY_H