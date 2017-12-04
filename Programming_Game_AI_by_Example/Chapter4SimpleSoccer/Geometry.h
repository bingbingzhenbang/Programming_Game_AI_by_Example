#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QVector2D>

inline QVector2D GetPerpendicularVector(const QVector2D &a)
{
	QVector2D ret(-a.y(), a.x());
	return ret;
}

inline QVector2D GetNormalVector(const QVector2D &start, const QVector2D &end)
{
	QVector2D temp = end - start;
	temp.normalize();
	return GetPerpendicularVector(temp);
}


#endif // GEOMETRY_H