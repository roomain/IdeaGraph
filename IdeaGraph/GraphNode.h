#pragma once
#include "ideagraph_global.h"
#include <qgraphicsitem.h>
#include <qfont.h>

class GraphAnchor;

class IDEAGRAPH_EXPORT GraphNode : public QGraphicsItem
{
private:
	QColor m_backgroundColor;
	QColor m_foregroundColor;
	QString m_title;
	QFont m_font;
	bool m_bHover = false;
	bool m_bSelected = false;

	std::vector<GraphAnchor*> m_inputAnchors;
	std::vector<GraphAnchor*> m_outputAnchors;

public:
	GraphNode(QGraphicsItem* parent = nullptr);
	virtual ~GraphNode() = default;
	void addInput(const QString& a_title);
	void addOutput(const QString& a_title);
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	QString title()const;
	void setTitle(const QString& a_title);
	QColor bkcolor()const;
	void setBKColor(const QColor& a_color);
	QColor color()const;
	void setColor(const QColor& a_color);
	QFont font()const;
	void setFont(const QFont& a_font);
	QRectF boundingRect()const final;

protected:
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};

