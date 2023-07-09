#pragma once
#include "ideagraph_global.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class GraphWidgetClass;
}
QT_END_NAMESPACE

class IDEAGRAPH_EXPORT GraphWidget : public QMainWindow
{
	Q_OBJECT

public:
	GraphWidget(QWidget *parent = nullptr);
	~GraphWidget();

private:
	Ui::GraphWidgetClass* ui;
};
