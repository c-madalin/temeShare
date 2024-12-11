#include <QApplication>
#include <iostream>
#include "myview.h"
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyView view;
    view.run();
    return a.exec();
}


