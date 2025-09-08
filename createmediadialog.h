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
    explicit CreateMediaDialog(QStackedWidget* container, CreateMediaModel* model, QWidget *parent = nullptr);
    ~CreateMediaDialog();

    QWidget* findWidgetByTag(const QString& tag) const;
    void setBehaviour(MediaCreationBehaviour behaviour, IMedia* mediaToEdit = nullptr);


private slots:
    void on_mediaDropdown_currentIndexChanged(const int index);

    void on_ConfirmButton_clicked();

    void on_CancelButton_clicked();

signals:
    void mediaCreated(IMedia* media);
    void confirmPressed(const MediaInput& input);

private:
    QStackedWidget* dialogContainer;
    CreateMediaModel* model;
    Ui::CreateMediaDialog *ui;
    void createMedia(IMedia*);
    void close();
    void updateFormToCreateMedia(const MediaType);
    void updateFormToEditMedia(IMedia*);
    void updateForm(IMedia*);
    void openMediaImageSelection(QLabel* imageViewer);
    bool areInputsValid() const;
    QList<QVariant> collectUserInput(QFormLayout* layout) const;
    IMedia* pendingMedia;
};

#endif // CREATEMEDIADIALOG_H
