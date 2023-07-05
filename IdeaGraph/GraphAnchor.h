#pragma once
#include <qgraphicsitem.h>

class GraphLink;

class GraphAnchor : public QGraphicsItem
{
private:
	QColor m_circleColor;
	bool m_bHover = false;
	GraphLink* m_pLink = nullptr;

public:
	GraphAnchor(QGraphicsItem* parent = nullptr);
	virtual ~GraphAnchor() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	QColor color()const;
	void setColor(const QColor& a_color);
	QRectF boundingRect()const final;
	void setLink(GraphLink* const a_pLink);
	void updatePosition();

protected:
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
};
