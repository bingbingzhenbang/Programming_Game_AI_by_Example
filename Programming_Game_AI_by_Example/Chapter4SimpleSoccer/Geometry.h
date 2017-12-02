#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QVector2D>

inline QVector2D GetNormalVector(const QVector2D &start, const QVector2D &end)
{
	QVector2D temp = end - start;
	temp.normalize();
	QVector2D ret(-temp.y(), temp.x());
	return ret;
}


#endif // GEOMETRY_H