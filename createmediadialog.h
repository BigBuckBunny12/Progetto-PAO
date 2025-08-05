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

private slots:
    void on_mediaDropdown_currentIndexChanged(const int index);

private:
    Ui::CreateMediaDialog *ui;
    void addParamWidgetToLayout(const MediaParam parameter, QFormLayout* layout);
    void updateMediaCreationForm(const MediaType);
    void openMediaImageSelection(QLabel* imageViewer);
    IMedia* pendingMedia;
};

#endif // CREATEMEDIADIALOG_H
