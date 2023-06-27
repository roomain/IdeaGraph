#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IdeaApplication.h"

class IdeaApplication : public QMainWindow
{
    Q_OBJECT

public:
    IdeaApplication(QWidget *parent = nullptr);
    ~IdeaApplication();

private:
    Ui::IdeaApplicationClass ui;
};
