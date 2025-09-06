#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "createmediadialog.h"
#include "mainwindowmodel.h"
#include "viewmediadialog.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(MainWindowModel* windowModel, QWidget *parent = nullptr);
    ~MainWindow();
    void createMedia(IMedia* media) const;
    void viewMedia(IMedia* media) const;
    void editMedia(IMedia* media) const;

private slots:
    void on_newMediaButton_clicked();
    void onMediaCreated(IMedia* media) const;
    void onMediaRemoved(IMedia* media) const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MainWindow *ui;
    MainWindowModel* model;
    CreateMediaDialog* createMediaDialog;
    ViewMediaDialog* viewMediaDialog;
    void reflowMediaGrid() const;
};
#endif // MAINWINDOW_H
