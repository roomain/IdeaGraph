#pragma once

#include <QWidget>
#include "ui_GraphBox.h"

class GraphBox : public QWidget
{
	Q_OBJECT

public:
	GraphBox(QWidget *parent = nullptr);
	~GraphBox();

private:
	Ui::GraphBoxClass ui;
};
