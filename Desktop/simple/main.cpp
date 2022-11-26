#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<MainWindow> w = std::make_shared<MainWindow>();
    w->showMaximized();
    return a.exec();
}
