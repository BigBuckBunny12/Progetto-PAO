#ifndef CREATEMEDIADIALOG_H
#define CREATEMEDIADIALOG_H

#include "GetUserInputVisitor.h"
#include "createmediamodel.h"
#include "imedia.h"
#include <QWidget>
#include <qformlayout.h>
#include <qlabel.h>
#include <qstackedwidget.h>

namespace Ui {
class CreateMediaDialog;
}

class CreateMediaDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMediaDialog(CreateMediaModel* model, QWidget *parent = nullptr);
    ~CreateMediaDialog();

    QWidget* findWidgetByTag(const QString& tag) const;
    void setBehaviour(const MediaCreationBehaviour behaviour, IMedia* mediaToEdit = nullptr);


private slots:
    void on_mediaDropdown_currentIndexChanged(const int index);
    void on_ConfirmButton_clicked();
    void on_CancelButton_clicked();

signals:
    void mediaCreated(IMedia* media);
    void confirmPressed(const MediaInput& input);
    void dialogClosed();

private:
    CreateMediaModel* model;
    Ui::CreateMediaDialog *ui;
    void updateForm(IMedia*);
    void displayErrorMessages(const std::vector<QString>& messages);
    void clearErrorMessages();
};

#endif // CREATEMEDIADIALOG_H
