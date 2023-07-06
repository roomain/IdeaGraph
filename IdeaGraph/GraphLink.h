#pragma once
#include "ideagraph_global.h"
#include <qgraphicsitem.h>

class GraphAnchor;

class IDEAGRAPH_EXPORT GraphLink : public QGraphicsItem
{
public:
	GraphLink(QGraphicsItem* parent = nullptr);
	virtual ~GraphLink();

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	QRectF boundingRect()const final;
	void setStart(const QPointF& a_ptStart);
	void setEnd(const QPointF& a_ptEnd);

	void setStart(GraphAnchor* const a_lnk);
	void setEnd(GraphAnchor* const a_lnk);
	void updateLink(const GraphAnchor* a_lnk);
	const GraphAnchor* startAnchor()const noexcept { return m_pStartLink; }
	const GraphAnchor* endAnchor()const noexcept { return m_pEndLink; }

	void setColor(const QColor& a_color);

private:
	QColor m_color;
	GraphAnchor* m_pStartLink = nullptr;
	GraphAnchor* m_pEndLink = nullptr;
	QPointF m_ptStart;
	QPointF m_ptEnd;
};

