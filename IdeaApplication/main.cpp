#include "IdeaApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IdeaApplication w;
    w.show();
    return a.exec();
}
