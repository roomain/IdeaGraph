#include "GraphLink.h"
#include "GraphZValues.h"
#include "GraphAnchor.h"
#include <QPainter>
#include <QPainterPath>


GraphLink::GraphLink(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	setZValue(GRAPH_LINK_Z_VALUE);
}

GraphLink::~GraphLink()
{
	if (m_pStartLink)
		m_pStartLink->setLink(nullptr);

	if (m_pEndLink)
		m_pEndLink->setLink(nullptr);
}

void GraphLink::setStart(const QPointF& a_ptStart)
{
	m_ptStart = a_ptStart;
	QPointF topLeft(std::min(m_ptStart.x(), m_ptEnd.x()), std::min(m_ptStart.y(), m_ptEnd.y()));
	setPos(topLeft);
	update();
}

void GraphLink::setEnd(const QPointF& a_ptEnd)
{
	m_ptEnd = a_ptEnd;
	QPointF topLeft(std::min(m_ptStart.x(), m_ptEnd.x()), std::min(m_ptStart.y(), m_ptEnd.y()));
	setPos(topLeft);
}


void GraphLink::setStart(GraphAnchor* const a_lnk)
{
	m_pStartLink = a_lnk;
}

void GraphLink::setEnd(GraphAnchor* const a_lnk)
{
	m_pEndLink = a_lnk;
	if (m_pEndLink && m_pStartLink)
	{
		if (m_pEndLink->parentItem() == m_pStartLink->parentItem())
		{
			//
		}
	}
}

void GraphLink::updateLink(const GraphAnchor* a_lnk)
{
	if(m_pStartLink == a_lnk)
		setStart(a_lnk->mapToScene(a_lnk->boundingRect().center()));

	if (m_pEndLink == a_lnk)
		setEnd(a_lnk->mapToScene(a_lnk->boundingRect().center()));
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
	painter->setPen(QPen(m_color, 3));
	painter->drawPath(path);

	painter->restore();
}

QRectF GraphLink::boundingRect()const
{
	QPointF topLeft(std::min(m_ptStart.x(), m_ptEnd.x()), std::min(m_ptStart.y(), m_ptEnd.y()));
	return QRectF(QPointF(0, 0), QSizeF(std::abs(m_ptEnd.x() - m_ptStart.x()), std::abs(m_ptEnd.y() - m_ptStart.y())));
}

void GraphLink::setColor(const QColor& a_color)
{
	m_color = a_color;
}