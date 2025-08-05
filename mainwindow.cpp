#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "media.h"
#include "createmediadialog.h"
#include <QDebug>
#include <qstackedwidget.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateMediaDialog* updateMediaDialog = new CreateMediaDialog();
    QVBoxLayout *updateMediaLayout = new QVBoxLayout(ui->updateMediaDialog);
    ui->updateMediaDialog->setLayout(updateMediaLayout);
    ui->updateMediaDialog->layout()->addWidget(updateMediaDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newMediaButton_clicked()
{
    // qui sotto vengono creati i widget dei media
    qDebug() << this->width();

    const int MAX_COLUMNS = 5;
    Media* media = new Media();
    const int column = ui->mediaGrid->count() % MAX_COLUMNS;
    const int row = ui->mediaGrid->count() / MAX_COLUMNS;
    ui->mediaGrid->addWidget(media , row , column);
    ui->gridLayoutWidget->setFixedWidth(this->width());
    //ui->mediaGrid->setColumnStretch(column , 1);
    //ui->mediaGrid->setRowStretch(row , 1);
    const int mediaWidth = (this->width() - ui->mediaGrid->horizontalSpacing()) / static_cast<float>(MAX_COLUMNS) - ui->mediaGrid->horizontalSpacing();
    const int mediaHeight = mediaWidth / Media::aspectRatio;
    qDebug() << "mediaWidth:" << mediaWidth;
    qDebug() << "mediaHeight:" << mediaHeight;

    media->setFixedSize(mediaWidth, mediaHeight);
    const int spacing = ui->mediaGrid->verticalSpacing();
    const int totalHeight = (row + 1) * (media->height() + spacing);

    QWidget* contentWidget = ui->scrollArea->widget();
    contentWidget->setMinimumHeight(totalHeight);
    qDebug() << "grid count:" << ui->mediaGrid->count();

}

void MainWindow::reflowMediaGrid()
{
    ui->gridLayoutWidget->setFixedWidth(this->width());
    const int MAX_COLUMNS = 5;
    int areaWidth = ui->scrollArea->viewport()->width();
    const int spacing = ui->mediaGrid->horizontalSpacing();
    int mediaWidth = (areaWidth - (MAX_COLUMNS + 1) * spacing) / MAX_COLUMNS;
    int mediaHeight = mediaWidth / Media::aspectRatio;

    for (int i = 0; i < ui->mediaGrid->count(); ++i) {
        QWidget* widget = ui->mediaGrid->itemAt(i)->widget();
        if (widget) {
            widget->setFixedSize(mediaWidth, mediaHeight);
        }
    }

    int rowCount = (ui->mediaGrid->count() + MAX_COLUMNS - 1) / MAX_COLUMNS;
    int totalHeight = rowCount * (mediaHeight + ui->mediaGrid->verticalSpacing());
    QWidget* contentWidget = ui->scrollArea->widget();
    contentWidget->setMinimumHeight(totalHeight);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    reflowMediaGrid();
}

