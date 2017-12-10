#ifndef WALL2D_H
#define WALL2D_H

#include <QVector2D>

class Wall2D
{
private:
	QVector2D m_From;
	QVector2D m_To;
	QVector2D m_Norm;
public:
	Wall2D(const QVector2D &a, const QVector2D &b);
	QVector2D From() const;
	void SetFrom(const QVector2D &a);
	QVector2D To() const;
	void SetTo(const QVector2D &b);
	QVector2D Normal() const;
	QVector2D Center() const;
	void Render(bool render_normal = false);
};

#endif // WALL2D_H