#include "IdeaApplication.h"

IdeaApplication::IdeaApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.centralWidget->hide();
}

IdeaApplication::~IdeaApplication()
{}
