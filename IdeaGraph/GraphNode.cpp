#include "GraphNode.h"
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>

GraphAnchor::GraphAnchor(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	//
}

void GraphAnchor::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->save();

	QPainterPath path;
	path.addEllipse(boundingRect());
	painter->fillPath(path, QColor(255, 255, 255));

	painter->setPen(QPen(m_circleColor, 3));
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

//---------------------------------------------------------------------------------------------------------------------


GraphNode::GraphNode(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
	//
}

void GraphNode::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->save();
		
	QPainterPath path;
	path.addRoundedRect(boundingRect(), 10, 10);
	painter->fillPath(path, m_backgroundColor);

	painter->setBrush(m_foregroundColor);
	painter->setFont(m_font);
	painter->setPen(m_foregroundColor);
	QTextOption opt;
	opt.setAlignment(Qt::AlignCenter);
	painter->drawText(boundingRect(), m_title, opt);

	if (m_bHover || m_bSelected)
	{
		painter->setBrush(QColor(0, 0, 0, 0));
		painter->setPen(QPen(QColor(100, 100, 100),4));
		painter->drawRoundedRect(boundingRect(), 10, 10);
	}

	painter->restore();
}


QString GraphNode::title()const
{
	return m_title;
}

void GraphNode::setTitle(const QString& a_title)
{
	m_title = a_title;
}

QColor GraphNode::bkcolor()const
{
	return m_backgroundColor;
}

void GraphNode::setBKColor(const QColor& a_color)
{
	m_backgroundColor = a_color;
}

QColor GraphNode::color()const
{
	return m_foregroundColor;
}

void GraphNode::setColor(const QColor& a_color)
{
	m_foregroundColor = a_color;
}


QFont GraphNode::font()const
{
	return m_font;
}

void GraphNode::setFont(const QFont& a_font)
{
	m_font = a_font;
}

QRectF GraphNode::boundingRect()const
{
	QFontMetricsF metric(m_font);
	QTextOption opt;
	opt.setAlignment(Qt::AlignCenter);
	QRectF rect = metric.boundingRect(m_title, opt);
	if (rect.height() == 0)
	{
		rect.setHeight(50);
		rect.setWidth(50);
	}
	QRectF bounding(QPointF(0,0), QSizeF(rect.width() + metric.boundingRect("L").width() * 6, rect.height() + metric.boundingRect("L").height() * 2));
	return bounding;
	rect.setHeight(rect.height() + metric.boundingRect("L").height() * 2);
	rect.setWidth(rect.width() + metric.boundingRect("L").width() * 6);
	return rect;
}

void GraphNode::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	QGraphicsItem::hoverEnterEvent(event);
	m_bHover = true;
}

void GraphNode::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	QGraphicsItem::hoverLeaveEvent(event);
	m_bHover = false;
}

void GraphNode::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mouseMoveEvent(event);
	//
}

void GraphNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mouseDoubleClickEvent(event);
	//
}

void GraphNode::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mouseReleaseEvent(event);
	m_bSelected = !m_bSelected;
	update();
}