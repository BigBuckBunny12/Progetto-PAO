#ifndef VIEWMEDIADIALOG_H
#define VIEWMEDIADIALOG_H

#include "imedia.h"
#include "qstackedwidget.h"
#include "viewmediamodel.h"
#include "viewmediacreationvisitor.h"
#include <QWidget>

namespace Ui {
class ViewMediaDialog;
}

class ViewMediaDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ViewMediaDialog(QStackedWidget* container, ViewMediaModel* viewModel, QWidget *parent = nullptr);
    ~ViewMediaDialog();
    void displayMedia(IMedia* media);

signals:
    void editMediaRequested(IMedia* media);

private slots:
    void on_deleteButton_clicked();
    void on_editButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::ViewMediaDialog *ui;
    ViewMediaModel* model;
    QStackedWidget* dialogContainer;
};

#endif // VIEWMEDIADIALOG_H
