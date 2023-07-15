#include "GraphWidget.h"
#include "ui_GraphWidget.h"
#include "EditPropertyModel.h"

#include "GraphNode.h"
#include "GraphScene.h"
#include "GraphLink.h"
#include "EditModelFactory.h"

GraphWidget::GraphWidget(QWidget *parent)
	: QMainWindow(parent), ui{ new Ui::GraphWidgetClass }
{
	ui->setupUi(this);
    ui->tvProperties->setModel(new EditPropertyModel);
    auto pScene = new GraphScene;


    QObject::connect(pScene, &GraphScene::sg_clearSelection,this, &GraphWidget::onClearSelection);
    QObject::connect(pScene, QOverload<GraphNode*>::of(&GraphScene::sg_selected),this, QOverload<GraphNode*>::of(&GraphWidget::onSelected));
    QObject::connect(pScene, QOverload<GraphAnchor*>::of(&GraphScene::sg_selected),this, QOverload<GraphAnchor*>::of(&GraphWidget::onSelected));
    //----------------------------------------------------------------------
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
    //------------------------------------------------------------

    ui->graphicsView->setScene(pScene);
}

GraphWidget::~GraphWidget()
{
	delete ui;
}


void GraphWidget::onClearSelection()
{
    EditPropertyModel* pModel = dynamic_cast<EditPropertyModel*>(ui->tvProperties->model());
    if (pModel)
    {
        pModel->clear();
    }
}

void GraphWidget::onSelected(GraphNode* a_pNode)
{
    EditPropertyModel* pModel = dynamic_cast<EditPropertyModel*>(ui->tvProperties->model());
    if (pModel)
    {
        pModel->setup(EditModelFactory::createEditTree(a_pNode));
        ui->tvProperties->expandAll();
    }
}

void GraphWidget::onSelected(GraphAnchor* a_pAnchor)
{
    EditPropertyModel* pModel = dynamic_cast<EditPropertyModel*>(ui->tvProperties->model());
    if (pModel)
    {
        pModel->setup(EditModelFactory::createEditTree(a_pAnchor));
        ui->tvProperties->expandAll();
    }
}
