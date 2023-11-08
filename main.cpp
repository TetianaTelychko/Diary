#include "mainwindow.h"
#include "datamodel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataModel dm;
    MainWindow w(dm);
    w.show();
    return a.exec();
}
