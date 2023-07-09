#include "GraphScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <qgraphicsitem.h>
#include "GraphZValues.h"
#include "GraphNode.h"
#include "GraphAnchor.h"
#include "GraphLink.h"

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent)
{
	//
}

void GraphScene::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	QGraphicsScene::wheelEvent(event);
	auto sRect = sceneRect();
	auto ptCenter = event->scenePos();
	float deltaX = sRect.center().x() - ptCenter.x();
	float deltaY = sRect.center().y() - ptCenter.y();
	
	// TODO
	update();
}

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);
	m_lastMousePos = event->scenePos();
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);
	auto ptMousePos = event->scenePos();
	if (m_pCurrentLink)
		m_pCurrentLink->setEnd(ptMousePos);

	if (event->buttons() == Qt::MiddleButton)
	{
		auto trans =  m_lastMousePos - ptMousePos;
		auto rect = sceneRect();
		rect.translate(trans.x(), trans.y());
		setSceneRect(rect);
		m_lastMousePos = ptMousePos;
	}

	update();
}

bool GraphScene::connectLink(GraphAnchor* const a_pAnchor)
{
	bool bRet = false;
	if (m_pCurrentLink)
	{
		if (m_pCurrentLink->startAnchor() && (m_pCurrentLink->startAnchor()->anchorType() != a_pAnchor->anchorType()))
		{
			auto ptScenePos = a_pAnchor->mapToScene(a_pAnchor->boundingRect().center());
			m_pCurrentLink->setEnd(ptScenePos);
			m_pCurrentLink->setEnd(a_pAnchor);
			a_pAnchor->setLink(m_pCurrentLink);
			m_pOld = m_pCurrentLink;
			m_pCurrentLink = nullptr;
			bRet = true;
		}
	}
	else
	{
		auto ptScenePos = a_pAnchor->mapToScene(a_pAnchor->boundingRect().center());
		m_pCurrentLink = new GraphLink();
		m_pCurrentLink->setStart(ptScenePos);
		m_pCurrentLink->setStart(a_pAnchor);
		a_pAnchor->setLink(m_pCurrentLink);
		m_pCurrentLink->setEnd(ptScenePos);
		addItem(m_pCurrentLink);
		bRet = true;
	}
	return bRet;
}

bool GraphScene::onPressItem(QGraphicsSceneMouseEvent* event, GraphAnchor* const a_pAnchor)
{
	if (event->modifiers() == Qt::KeyboardModifier::ControlModifier)
	{
		a_pAnchor->eraseLink();
	}
	else if(!a_pAnchor->hasLink())
	{
		connectLink(a_pAnchor);
	}
	return true;
}

bool GraphScene::onPressItem(QGraphicsSceneMouseEvent* event, GraphNode* const a_pNode)
{
	return true;
}

void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseReleaseEvent(event);
	if (event->button() == Qt::LeftButton)
	{
		auto itemList = items(event->scenePos());
		if (!itemList.isEmpty())
		{
			for (auto pSelectItem : itemList)
			{
				auto pAnchor = dynamic_cast<GraphAnchor*>(pSelectItem);
				if (pAnchor && onPressItem(event, pAnchor))
					break;

				auto pNode = dynamic_cast<GraphNode*>(pSelectItem);
				if (pNode && onPressItem(event, pNode))
					break;
			}

		}
	}
	else if (event->buttons() == Qt::MiddleButton)
	{
		m_lastMousePos = event->scenePos();
	}
}