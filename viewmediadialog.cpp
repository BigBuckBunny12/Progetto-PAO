#include "viewmediadialog.h"
#include "ui_viewmediadialog.h"
#include <QDebug>

ViewMediaDialog::ViewMediaDialog(QStackedWidget* container, ViewMediaModel* viewModel, QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewMediaDialog), model(viewModel), dialogContainer(container)
{
    ui->setupUi(this);
}

ViewMediaDialog::~ViewMediaDialog()
{
    delete ui;
}

void ViewMediaDialog::displayMedia(IMedia* media) {
    qDebug() << "IMedia* (displayMedia): " << media;
    ui->listWidget->clear();
    ViewMediaCreationVisitor mediaContentViewGenerator(ui->listWidget);
    media->accept(mediaContentViewGenerator);
    model->setMediaInView(media);
}

void ViewMediaDialog::on_deleteButton_clicked()
{
    dialogContainer->hide();
    model->deleteMedia(model->getMediaInView());
}


void ViewMediaDialog::on_editButton_clicked()
{
    if(model->getMediaInView()) {
        emit editMediaRequested(model->getMediaInView());
    }
}


void ViewMediaDialog::on_exitButton_clicked()
{
    dialogContainer->hide();
}

