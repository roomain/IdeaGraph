#include "GraphWidget.h"
#include "ui_GraphWidget.h"

GraphWidget::GraphWidget(QWidget *parent)
	: QMainWindow(parent), ui{ new Ui::GraphWidgetClass }
{
	ui->setupUi(this);	
}

GraphWidget::~GraphWidget()
{
	delete ui;
}
