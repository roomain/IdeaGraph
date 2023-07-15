#include "GraphView.h"
#include "GraphScene.h"
#include <qevent.h>

#include "GraphNode.h"
#include "GraphScene.h"
#include "GraphLink.h"


GraphView::GraphView(QWidget* a_pParent) : QGraphicsView(a_pParent)
{
	//
}


void GraphView::wheelEvent(QWheelEvent* a_pEvent)
{
	QGraphicsView::wheelEvent(a_pEvent);
    float delta = (a_pEvent->angleDelta().y() > 0) ? 1.2f : 1.0f / 1.2f;
    scale(delta, delta);
}

void GraphView::mouseMoveEvent(QMouseEvent* a_pEvent)
{
	QGraphicsView::mouseMoveEvent(a_pEvent);
    auto scenePos = a_pEvent->scenePosition();
    auto trans = m_lastMousePos - scenePos;
    if (a_pEvent->buttons() == Qt::MiddleButton)
    {
        auto rect = sceneRect();
        rect.translate(trans);
        setSceneRect(rect);
    }
    m_lastMousePos = scenePos;
}

void GraphView::mousePressEvent(QMouseEvent* a_pEvent)
{
	QGraphicsView::mousePressEvent(a_pEvent);
    m_lastMousePos = a_pEvent->scenePosition();
}

void GraphView::mouseReleaseEvent(QMouseEvent* a_pEvent)
{
	QGraphicsView::mouseReleaseEvent(a_pEvent);
	//
}

void GraphView::mouseDoubleClickEvent(QMouseEvent* event)
{
    QGraphicsView::mouseDoubleClickEvent(event);
    if (event->button() == Qt::MiddleButton && scene())
    {
        QRectF rect;
        for (auto pItem : scene()->items())
        {
            auto tempRect = pItem->mapRectToScene(pItem->boundingRect());
            if (rect.width() == 0)
            {
                rect = tempRect;
            }
            else
            {
                rect = rect.united(tempRect);
            }
        }
        setSceneRect(rect);
    }
}
