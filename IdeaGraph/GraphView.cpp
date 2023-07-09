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
    //scale(a_pEvent->angleDelta().x(), a_pEvent->angleDelta().x());
	//
}

void GraphView::mouseMoveEvent(QMouseEvent* a_pEvent)
{
	QGraphicsView::mouseMoveEvent(a_pEvent);
    //
}

void GraphView::mousePressEvent(QMouseEvent* a_pEvent)
{
	QGraphicsView::mousePressEvent(a_pEvent);
    //
}

void GraphView::mouseReleaseEvent(QMouseEvent* a_pEvent)
{
	QGraphicsView::mouseReleaseEvent(a_pEvent);
	//
}
