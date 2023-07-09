#pragma once
#include <qgraphicsitem.h>
#include "AnchorShape.h"
class GraphLink;

class GraphAnchor : public QGraphicsItem
{
public:
	enum class Type
	{
		None,
		Input,
		Output
	};


	GraphAnchor(const Type a_type, QGraphicsItem* parent = nullptr);
	virtual ~GraphAnchor() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	QColor color()const;
	void setColor(const QColor& a_color);
	QRectF boundingRect()const final;
	void setLink(GraphLink* const a_pLink);
	bool hasLink()const { return m_pLink != nullptr; }
	void eraseLink();
	void updatePosition();
	Type anchorType()const noexcept { return m_type; }
	AnchorShape anchorShape()const { return m_shape; }
	void setAnchorShape(const AnchorShape a_shape) { m_shape = a_shape; }

protected:
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
	QColor m_circleColor;
	bool m_bHover = false;
	GraphLink* m_pLink = nullptr;
	Type m_type;
	AnchorShape m_shape;
};
