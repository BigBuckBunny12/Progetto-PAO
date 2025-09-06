#include "createmediadialog.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowModel windowModel;
    MainWindow window(&windowModel);
    window.show();

    return a.exec();
}
