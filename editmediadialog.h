#ifndef EDITMEDIADIALOG_H
#define EDITMEDIADIALOG_H

#include "IMedia.h"
#include "editmediamodel.h"
#include <QWidget>

namespace Ui {
class EditMediaDialog;
}

class EditMediaDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditMediaDialog(EditMediaModel* viewModel, QWidget *parent = nullptr);
    ~EditMediaDialog();
    void startEditingMedia(IMedia* media);

private:
    Ui::EditMediaDialog *ui;
    EditMediaModel* model;
};

#endif // EDITMEDIADIALOG_H
