#include "GraphAnchor.h"
#include <QPainter>
#include <QPainterPath>
#include "GraphZValues.h"
#include "GraphLink.h"

GraphAnchor::GraphAnchor(const Type a_type, QGraphicsItem* parent) : QGraphicsItem(parent), m_type{ a_type },
m_shape{ AnchorShape::Circle }
{
	setFlags(QGraphicsItem::ItemIsSelectable |
		QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemAcceptsInputMethod);
	setAcceptHoverEvents(true);
	setZValue(GRAPH_ANCHOR_Z_VALUE);
}

void GraphAnchor::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);

	QPainterPath path;
	auto fillColor = m_pLink ? QColor(0, 0, 0) : QColor(255, 255, 255);
	auto penColor = m_bHover ? QColor(0, 0, 255) : m_circleColor;
	painter->setPen(QPen(penColor, 3));
	switch (m_shape)
	{
	case AnchorShape::Circle:
		path.addEllipse(boundingRect());
		painter->fillPath(path, fillColor);
		painter->drawEllipse(boundingRect());
		break;

	case AnchorShape::Square:
		painter->fillRect(boundingRect(), fillColor);
		painter->drawRect(boundingRect());
		break;

	case AnchorShape::LeftTriangle:
	{
		float width = boundingRect().width();
		float height = boundingRect().height();
		QPolygonF triangle;
		triangle.append(QPoint(0, height / 2.0f));
		triangle.append(QPoint(width, height));
		triangle.append(QPoint(width, 0));
		triangle.append(QPoint(0, height / 2.0f));
		path.addPolygon(triangle);
		painter->fillPath(path, fillColor);
		painter->drawPath(path);
		break;
	}

	case AnchorShape::RightTriangle:
	{
		float width = boundingRect().width();
		float height = boundingRect().height();
		QPolygonF triangle;
		triangle.append(QPoint(width, height / 2.0f));
		triangle.append(QPoint(0, 0));
		triangle.append(QPoint(0, height));
		triangle.append(QPoint(width, height / 2.0f));
		path.addPolygon(triangle);
		painter->fillPath(path, fillColor);
		painter->drawPath(path);
		break;
	}
	default:
		break;
	}

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

void GraphAnchor::setLink(GraphLink* const a_pLink)
{
	m_pLink = a_pLink;
}

void GraphAnchor::eraseLink() 
{ 
	delete m_pLink; 
}

void GraphAnchor::updatePosition()
{
	if (m_pLink)
		m_pLink->updateLink(this);
}
