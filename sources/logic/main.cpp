#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("MediaLibrary");
    app.setWindowIcon(QIcon(":/resources/img/app_icon.png"));
    MainWindowModel windowModel;
    MainWindow window(&windowModel);
    window.setWindowTitle(app.applicationName());
    window.show();

    return app.exec();
}
