#ifndef CREATEMEDIADIALOG_H
#define CREATEMEDIADIALOG_H

#include "imedia.h"
#include <QWidget>
#include <qformlayout.h>
#include <qlabel.h>

namespace Ui {
class CreateMediaDialog;
}

class CreateMediaDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMediaDialog(QWidget *parent = nullptr);
    ~CreateMediaDialog();
    enum class updateModes {
        CREATE,
        UPDATE
    };
    void setUpdateMode(const CreateMediaDialog::updateModes);
    QWidget* findWidgetByTag(const QString& tag) const;

private slots:
    void on_mediaDropdown_currentIndexChanged(const int index);

    void on_ConfirmButton_clicked();

signals:
    void mediaCreated(IMedia* media);

private:
    Ui::CreateMediaDialog *ui;
    void updateMediaCreationForm(const MediaType);
    void openMediaImageSelection(QLabel* imageViewer);
    CreateMediaDialog::updateModes updateMode;
    bool areInputsValid() const;
    QList<QVariant> collectUserInput(QFormLayout* layout) const;
    IMedia* pendingMedia;
};

#endif // CREATEMEDIADIALOG_H
