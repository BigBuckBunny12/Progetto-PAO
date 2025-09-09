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
    void onMediaCreated(IMedia* media);
    void onMediaRemoved(IMedia* media);
    void onMediaUpdated(IMedia* media);

    void on_searchMediaField_textChanged(const QString &arg1);

    void on_saveButton_clicked();

    void on_loadButton_clicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MainWindow *ui;
    MainWindowModel* model;
    CreateMediaDialog* createMediaDialog;
    ViewMediaDialog* viewMediaDialog;
    const int GRID_MAX_COLUMNS = 5;
    void reflowMediaGrid();
    void refreshMediaGrid(const QString mediaFilter = "");
    void displayMediaList(std::vector<IMedia*> list);
    void clearMediaGrid();
};
#endif // MAINWINDOW_H
