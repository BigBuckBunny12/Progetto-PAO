#include "editmediadialog.h"
#include "ui_editmediadialog.h"

EditMediaDialog::EditMediaDialog(EditMediaModel* viewModel, QWidget *parent)
    : QWidget(parent), ui(new Ui::EditMediaDialog), model(viewModel)
{
    ui->setupUi(this);
}

EditMediaDialog::~EditMediaDialog()
{
    delete ui;
}
