#pragma once
#include <qgraphicsitem.h>

class GraphAnchor : public QGraphicsItem
{
	Q_OBJECT
public:
	GraphAnchor(QGraphicsItem* parent = nullptr);
	virtual ~GraphAnchor() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
};

class GraphNode : public QGraphicsItem
{
	Q_OBJECT
private:

public:
	GraphNode(QGraphicsItem* parent = nullptr);
	virtual ~GraphNode() = default;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
};

