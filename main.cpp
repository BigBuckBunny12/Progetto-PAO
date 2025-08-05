#include "createmediadialog.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    CreateMediaDialog dialog;
    dialog.show();

    return a.exec();
}
