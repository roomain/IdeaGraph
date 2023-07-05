#include "GraphAnchor.h"
#include <QPainter>
#include <QPainterPath>
#include "GraphZValues.h"

GraphAnchor::GraphAnchor(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setFlags(QGraphicsItem::ItemIsSelectable |
		QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemAcceptsInputMethod);
	setAcceptHoverEvents(true);
	setZValue(GRAPH_ANCHOR_Z_VALUE);
}

void GraphAnchor::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->save();

	QPainterPath path;
	path.addEllipse(boundingRect());
	painter->fillPath(path, QColor(255, 255, 255));

	painter->setPen(QPen(m_bHover ? QColor(0, 0, 255) : m_circleColor, 3));
	painter->drawEllipse(boundingRect());

	painter->restore();
}


QColor GraphAnchor::color()const
{
	return m_circleColor;
}

void GraphAnchor::setColor(const QColor& a_color)
{
	m_circleColor = a_color;
}

QRectF GraphAnchor::boundingRect()const
{
	return QRectF(0, 0, 15, 15);
}

void GraphAnchor::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	QGraphicsItem::hoverEnterEvent(event);
	m_bHover = true;
}

void GraphAnchor::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	QGraphicsItem::hoverLeaveEvent(event);
	m_bHover = false;
}