#pragma once
#include "ideagraph_global.h"
#include <qgraphicsitem.h>
#include <qfont.h>

class IDEAGRAPH_EXPORT GraphAnchor : public QGraphicsItem
{
private:
	QColor m_circleColor;

public:
	GraphAnchor(QGraphicsItem* parent = nullptr);
	virtual ~GraphAnchor() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	QColor color()const;
	void setColor(const QColor& a_color);
};

class IDEAGRAPH_EXPORT GraphNode : public QGraphicsItem
{
private:
	QColor m_backgroundColor;
	QColor m_foregroundColor;
	QString m_title;
	QFont m_font;
	bool m_bHover = false;
	bool m_bSelected = false;

public:
	GraphNode(QGraphicsItem* parent = nullptr);
	virtual ~GraphNode() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
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
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};

