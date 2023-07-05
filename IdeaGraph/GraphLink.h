#pragma once
#include "ideagraph_global.h"
#include <qgraphicsitem.h>

class IDEAGRAPH_EXPORT GraphLink : public QGraphicsItem
{
public:
	GraphLink(QGraphicsItem* parent = nullptr);
	virtual ~GraphLink() = default;

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	QRectF boundingRect()const final;
	void setStart(const QPointF& a_ptStart);
	void setEnd(const QPointF& a_ptEnd);

private:
	QPointF m_ptStart;
	QPointF m_ptEnd;
};

