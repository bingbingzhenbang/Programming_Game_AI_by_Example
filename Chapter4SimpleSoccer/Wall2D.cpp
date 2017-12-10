#include "Wall2D.h"
#include "Geometry.h"
#include "SimpleSoccerRenderer.h"

Wall2D::Wall2D(const QVector2D &a, const QVector2D &b)
: m_From(a),
m_To(b)
{
	m_Norm = GetNormalVector(m_From, m_To);
}

QVector2D Wall2D::From() const
{
	return m_From;
}

void Wall2D::SetFrom(const QVector2D &a)
{
	m_From = a;
	m_Norm = GetNormalVector(m_From, m_To);
}

QVector2D Wall2D::To() const
{
	return m_To;
}

void Wall2D::SetTo(const QVector2D &b)
{
	m_To = b;
	m_Norm = GetNormalVector(m_From, m_To);
}

QVector2D Wall2D::Normal() const
{
	return m_Norm;
}

QVector2D Wall2D::Center() const
{
	return (m_From + m_To) / 2.0;
}

void Wall2D::Render(bool render_normal)
{
	SimpleSoccerRenderer::Instance()->AddLine(m_From, m_To);
	if (render_normal)
	{
		QVector2D center = Center();
		SimpleSoccerRenderer::Instance()->AddLine(center, center + 5 * m_Norm);
	}
}