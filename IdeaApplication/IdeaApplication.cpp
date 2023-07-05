#include "IdeaApplication.h"
#include "GraphNode.h"
#include "GraphScene.h"
#include "GraphLink.h"

IdeaApplication::IdeaApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    auto pScene = new GraphScene();
    ui.graphicsView->setScene(pScene);
    auto node = new GraphNode();
    node->setBKColor(QColor(200, 0, 0));
    node->setColor(QColor(255, 255, 255));
    node->addInput("Input 0");
    node->addInput("Input 1");
    node->addInput("Input 2");
    node->addInput("Input 3");
    node->addOutput("Output 0");
    node->addOutput("Output 1");
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
}

IdeaApplication::~IdeaApplication()
{}
