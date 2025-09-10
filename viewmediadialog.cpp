#include "viewmediadialog.h"
#include "ui_viewmediadialog.h"
#include <QDebug>

ViewMediaDialog::ViewMediaDialog(QStackedWidget* container, ViewMediaModel* viewModel, QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewMediaDialog), model(viewModel), dialogContainer(container)
{
    ui->setupUi(this);
    ui->mediaInfo->layout()->setAlignment(Qt::AlignTop);
}

ViewMediaDialog::~ViewMediaDialog()
{
    delete ui;
}

void ViewMediaDialog::displayMedia(IMedia* media) {
    qDebug() << "IMedia* (displayMedia): " << media;

    QLayoutItem* item;
    while ((item = ui->mediaInfo->layout()->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    ViewMediaCreationVisitor mediaContentViewGenerator(ui->mediaInfo->layout(), this);
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

