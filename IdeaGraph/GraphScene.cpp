#include "GraphScene.h"
#include <QGraphicsSceneMouseEvent>
#include <qgraphicsitem.h>
#include "GraphZValues.h"
#include "GraphNode.h"
#include "GraphAnchor.h"

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent)
{
	//
}

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);
	auto itemList = items(event->scenePos());

	QGraphicsItem* pSelectItem = nullptr;
	if (!itemList.isEmpty())
	{
		pSelectItem = itemList[0];
	}

	// TODO
	
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);
	//
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseReleaseEvent(event);
	//
}