#include "GraphNode.h"
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>

GraphAnchor::GraphAnchor(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setFlags(QGraphicsItem::ItemIsSelectable |
		QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemAcceptsInputMethod);
	setAcceptHoverEvents(true);
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

//---------------------------------------------------------------------------------------------------------------------


GraphNode::GraphNode(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | 
		QGraphicsItem::ItemIsFocusable);
	setAcceptHoverEvents(true);
	//
}

void GraphNode::addInput(const QString& a_title)
{
	auto pAnchor = new GraphAnchor(this);
	pAnchor->setToolTip(a_title);
	m_inputAnchors.push_back(pAnchor);
}

void GraphNode::addOutput(const QString& a_title)
{
	auto pAnchor = new GraphAnchor(this);
	pAnchor->setToolTip(a_title);
	m_outputAnchors.push_back(pAnchor);
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
	auto size = metric.size(0, m_title);
	float fontH = size.height();
	float fontW = size.width();

	size = metric.size(0, "L");
	fontH = (fontH == 0 ? 50 : fontH) + size.height() * 2;
	fontW = (fontW == 0 ? 50 : fontW) + size.width() * 4;

	if (!m_inputAnchors.empty())
	{
		fontW += 30;
		int yOffset = 5;
		for (auto pAnchor : m_inputAnchors)
		{
			pAnchor->setPos(5, yOffset);
			yOffset += 20;
		}
	}

	if (!m_outputAnchors.empty())
	{
		fontW += 30;
		int yOffset = 5;
		for (auto pAnchor : m_outputAnchors)
		{
			pAnchor->setPos(fontW - 20, yOffset);
			yOffset += 20;
		}
	}

	float maxH = std::max(m_inputAnchors.size(), m_outputAnchors.size()) * 20 + 5;
	

	QRectF bounding(QPointF(0,0), QSizeF(fontW, std::max(fontH, maxH)));
	return bounding;
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