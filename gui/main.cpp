#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTGui/QTreeWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     MainWindow w;
    w.show();

    return a.exec();
}
