#pragma once
#include <qgraphicsitem.h>

class GraphAnchor : public QGraphicsItem
{
	Q_OBJECT
private:
	QColor m_circleColor;

public:
	GraphAnchor(QGraphicsItem* parent = nullptr);
	virtual ~GraphAnchor() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	QColor color()const;
	void setColor(const QColor& a_color);
};

class GraphNode : public QGraphicsItem
{
	Q_OBJECT
private:
	QColor m_backgroundColor;
	QColor m_foregroundColor;
	QString m_title;

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
};

