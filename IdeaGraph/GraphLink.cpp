#include "GraphLink.h"
#include "GraphZValues.h"
#include <QPainter>
#include <QPainterPath>


GraphLink::GraphLink(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
	setAcceptHoverEvents(true);
	setZValue(GRAPH_LINK_Z_VALUE);
}

void GraphLink::setStart(const QPointF& a_ptStart)
{
	m_ptStart = a_ptStart;
	setPos(m_ptStart);
	update();
}

void GraphLink::setEnd(const QPointF& a_ptEnd)
{
	m_ptEnd = a_ptEnd;

	QPointF topLeft(std::min(m_ptStart.x(), m_ptEnd.x()), std::min(m_ptStart.y(), m_ptEnd.y()));
	setPos(topLeft);
	update();
}

void GraphLink::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	
	QPainterPath path;
	path.moveTo(m_ptStart - pos());
	QPointF crtl2(m_ptStart.x(), m_ptEnd.y());
	QPointF crtl1(m_ptEnd.x(), m_ptStart.y());
	path.cubicTo(crtl1 - pos(), crtl2 - pos(), m_ptEnd - pos());
	painter->setPen(QPen(QColor(0, 0, 0), 3));
	painter->drawPath(path);
	painter->restore();
}

QRectF GraphLink::boundingRect()const
{
	return QRectF(0,0, std::abs(m_ptEnd.x() - m_ptStart.x()), std::abs(m_ptEnd.y() - m_ptStart.y()));
}