#include "GUI/mainwindow.hpp"
#include <QApplication>
#include <QStandardItemModel>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow _main;

    _main.show();
    return a.exec();
}
