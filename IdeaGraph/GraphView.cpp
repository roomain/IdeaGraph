#include "GraphView.h"
#include "GraphScene.h"
#include <qevent.h>

#include "GraphNode.h"
#include "GraphScene.h"
#include "GraphLink.h"


GraphView::GraphView(QWidget* a_pParent) : QGraphicsView(a_pParent)
{
	auto pScene = new GraphScene;
    //-------------------------------------
    auto node = new GraphNode();
    node->setBKColor(QColor(200, 0, 0));
    node->setColor(QColor(255, 255, 255));
    node->addInput("Input 0", AnchorShape::Square);
    node->addInput("Input 1");
    node->addInput("Input 2", AnchorShape::LeftTriangle);
    node->addInput("Input 3");
    node->addOutput("Output 0", AnchorShape::RightTriangle);
    node->addOutput("Output 1", AnchorShape::RightTriangle);
    QFont font;
    font.setBold(true);
    node->setFont(font);
    node->setTitle("TEST GRAPH NODE");
    pScene->addItem(node);

    node = new GraphNode();
    node->setBKColor(QColor(0, 0, 200));
    node->setColor(QColor(255, 255, 255));
    node->addInput("Input 0");
    node->addInput("Input 1");
    node->addInput("Input 2");
    node->addInput("Input 3");
    node->addOutput("Output 0");
    node->addOutput("Output 1");
    node->setFont(font);
    node->setTitle("TEST GRAPH NODE 1");
    pScene->addItem(node);
    node->setPos(-200, 100);
    //-------------------------------------

	setScene(pScene);
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
