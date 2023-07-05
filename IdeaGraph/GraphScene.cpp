#include "GraphScene.h"
#include <QGraphicsSceneMouseEvent>
#include <qgraphicsitem.h>
#include "GraphZValues.h"
#include "GraphNode.h"
#include "GraphAnchor.h"
#include "GraphLink.h"

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent)
{
	//
}

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);
	
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);
	if (m_pCurrentLink)
		m_pCurrentLink->setEnd(event->scenePos());
	update();
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseReleaseEvent(event);
	auto itemList = items(event->scenePos());

	QGraphicsItem* pSelectItem = nullptr;
	if (!itemList.isEmpty())
	{
		pSelectItem = itemList[0];
		auto pAnchor = dynamic_cast<GraphAnchor*>(pSelectItem);

		auto ptScene = event->scenePos();
		if (m_pCurrentLink)
		{
			if (pAnchor)
			{
				auto ptScenePos = pAnchor->mapToScene(pAnchor->boundingRect().center());
				m_pCurrentLink->setEnd(ptScenePos);
				m_pCurrentLink = nullptr;
			}
		}
		else if (pAnchor)
		{
			auto ptScenePos = pAnchor->mapToScene(pAnchor->boundingRect().center());
			m_pCurrentLink = new GraphLink();
			m_pCurrentLink->setStart(ptScenePos);
			m_pCurrentLink->setEnd(ptScenePos);
			addItem(m_pCurrentLink);
		}
	}
	//
}