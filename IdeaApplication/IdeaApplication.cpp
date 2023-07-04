#include "IdeaApplication.h"
#include "GraphNode.h"

IdeaApplication::IdeaApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    auto pScene = new QGraphicsScene();
    ui.graphicsView->setScene(pScene);
    auto node = new GraphNode();
    node->setBKColor(QColor(200, 0, 0));
    node->setColor(QColor(255, 255, 255));
    QFont font;
    font.setBold(true);
    node->setFont(font);
    node->setTitle("TEST GRAPH NODE");
    pScene->addItem(node);
}

IdeaApplication::~IdeaApplication()
{}
