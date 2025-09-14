#include "viewmediadialog.h"
#include "ui_viewmediadialog.h"
#include <QDebug>

ViewMediaDialog::ViewMediaDialog(ViewMediaModel* viewModel, QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewMediaDialog), model(viewModel)
{
    ui->setupUi(this);
    ui->mediaInfo->layout()->setAlignment(Qt::AlignTop);
    ui->topLayout->setAlignment(Qt::AlignVCenter);
}

ViewMediaDialog::~ViewMediaDialog()
{
    delete ui;
}

void ViewMediaDialog::displayMedia(IMedia* media) {
    if(!media) return;
    QLayoutItem* item;
    while ((item = ui->mediaInfo->layout()->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    ui->mediaTitle->setText(media->getTitle());
    ViewMediaCreationVisitor mediaContentViewGenerator(ui->mediaInfo->layout(), ui->mediaIcon, this);
    media->accept(mediaContentViewGenerator);
    model->setMediaInView(media);
}


void ViewMediaDialog::on_deleteButton_clicked()
{
    model->deleteMedia(model->getMediaInView());
    emit dialogClosed();
}


void ViewMediaDialog::on_editButton_clicked()
{
    if(model->getMediaInView()) {
        emit editMediaRequested(model->getMediaInView());
    }
}


void ViewMediaDialog::on_exitButton_clicked()
{
    emit dialogClosed();
}

