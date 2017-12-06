#include "MovingEntity.h"
#include "Geometry.h"

MovingEntity::MovingEntity(double radius, const QVector2D &pos,
	double mass, double max_speed, double max_force, double max_turn_rate, const QVector2D &velocity, const QVector2D &heading)
	:BaseGameEntity(GetNextValidID(), radius, pos),
	m_dMass(mass),
	m_dMaxSpeed(max_speed),
	m_dMaxForce(max_force),
	m_dMaxTurnRate(max_turn_rate),
	m_vVelocity(velocity),
	m_vHeading(heading),
	m_vSide(GetPerpendicularVector(heading))
{
}

double MovingEntity::Mass() const
{
	return m_dMass;
}

double MovingEntity::MaxSpeed() const
{
	return m_dMaxSpeed;
}

void MovingEntity::SetMaxSpeed(double max_speed)
{
	m_dMaxSpeed = max_speed;
}

double MovingEntity::MaxForce() const
{
	return m_dMaxForce;
}

void MovingEntity::SetMaxForce(double max_force)
{
	m_dMaxForce = max_force;
}

double MovingEntity::MaxTurnRate() const
{
	return m_dMaxTurnRate;
}

void MovingEntity::SetMaxTurnRate(double max_turn_rate)
{
	m_dMaxTurnRate = max_turn_rate;
}

double MovingEntity::Speed() const
{
	return m_vVelocity.length();
}

double MovingEntity::SpeedSquared() const
{
	return m_vVelocity.lengthSquared();
}

QVector2D MovingEntity::Heading() const
{
	return m_vHeading;
}

void MovingEntity::SetHeading(const QVector2D &heading)
{
	m_vHeading = heading;
	m_vSide = GetPerpendicularVector(m_vHeading);
}