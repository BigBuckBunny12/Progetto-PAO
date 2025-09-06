#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "media.h"
#include "createmediadialog.h"
#include "mediawidgetvisitor.h"
#include <QDebug>
#include <qstackedwidget.h>


MainWindow::MainWindow(MainWindowModel* windowModel, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), model(windowModel)
{
    ui->setupUi(this);
    // Setup delle pagine nel dialog container
    CreateMediaModel* createMediaModel = new CreateMediaModel(CREATE);
    createMediaDialog = new CreateMediaDialog(ui->dialogContainer , createMediaModel);
    QVBoxLayout *createMediaLayout = new QVBoxLayout(ui->createMediaPage);
    ui->createMediaPage->setLayout(createMediaLayout);
    ui->createMediaPage->layout()->addWidget(createMediaDialog);

    ViewMediaModel* viewMediaModel = new ViewMediaModel;
    viewMediaDialog = new ViewMediaDialog(ui->dialogContainer , viewMediaModel);
    QVBoxLayout *viewMediaLayout = new QVBoxLayout(ui->viewMediaPage);
    ui->viewMediaPage->setLayout(viewMediaLayout);
    ui->viewMediaPage->layout()->addWidget(viewMediaDialog);

    // setup connessioni
    connect(createMediaModel, &CreateMediaModel::mediaCreated,
            this, &MainWindow::onMediaCreated);

    connect(&MediaManager::instance(), &MediaManager::mediaRemoved,
                     this, &MainWindow::onMediaRemoved);

    connect(viewMediaDialog, &ViewMediaDialog::editMediaRequested,
            this, &MainWindow::editMedia);


    ui->dialogContainer->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newMediaButton_clicked()
{
    ui->dialogContainer->show();
    ui->dialogContainer->setCurrentWidget(ui->createMediaPage);
    // qui sotto vengono creati i widget dei media
    // qDebug() << this->width();

    // const int MAX_COLUMNS = 5;
    // Media* media = new Media();
    // const int column = ui->mediaGrid->count() % MAX_COLUMNS;
    // const int row = ui->mediaGrid->count() / MAX_COLUMNS;
    // ui->mediaGrid->addWidget(media , row , column);
    // ui->gridLayoutWidget->setFixedWidth(this->width());
    // //ui->mediaGrid->setColumnStretch(column , 1);
    // //ui->mediaGrid->setRowStretch(row , 1);
    // const int mediaWidth = (this->width() - ui->mediaGrid->horizontalSpacing()) / static_cast<float>(MAX_COLUMNS) - ui->mediaGrid->horizontalSpacing();
    // const int mediaHeight = mediaWidth / Media::aspectRatio;
    // qDebug() << "mediaWidth:" << mediaWidth;
    // qDebug() << "mediaHeight:" << mediaHeight;

    // media->setFixedSize(mediaWidth, mediaHeight);
    // const int spacing = ui->mediaGrid->verticalSpacing();
    // const int totalHeight = (row + 1) * (media->height() + spacing);

    // QWidget* contentWidget = ui->scrollArea->widget();
    // contentWidget->setMinimumHeight(totalHeight);
    // qDebug() << "grid count:" << ui->mediaGrid->count();

}

void MainWindow::viewMedia(IMedia* media) const {
    qDebug() << "IMedia*: " << media;
    ui->dialogContainer->show();
    ui->dialogContainer->setCurrentWidget(ui->viewMediaPage);
    viewMediaDialog->displayMedia(media);
}

void MainWindow::onMediaCreated(IMedia* media) const {
    const int MAX_COLUMNS = 5;
    const int column = ui->mediaGrid->count() % MAX_COLUMNS;
    const int row = ui->mediaGrid->count() / MAX_COLUMNS;
    Media* mediaWidget = new Media(media);
    MediaWidgetVisitor mediaCustomizer(*mediaWidget);
    media->accept(mediaCustomizer);
    ui->mediaGrid->addWidget(mediaWidget , row , column);
    reflowMediaGrid();
    connect(mediaWidget, &Media::clicked, this, [this](Media* media){
        qDebug() << "Media* (connect): " << media;
        viewMedia(model->getAssociatedMediaObject(media));
    });
    model->mapMediaToWidget(media, mediaWidget);
}

void MainWindow::onMediaRemoved(IMedia* media) const {
    Media* mediaWidget = model->getAssociatedMediaWidget(media);
    ui->mediaGrid->removeWidget(mediaWidget);
    model->unmapMediaFromWidget(media, mediaWidget);
    delete mediaWidget;
    reflowMediaGrid();
}

void MainWindow::reflowMediaGrid() const
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

void MainWindow::editMedia(IMedia* mediaToEdit) const {
    ui->dialogContainer->show();
    ui->dialogContainer->setCurrentWidget(ui->createMediaPage);
    createMediaDialog->setBehaviour(EDIT , mediaToEdit);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    reflowMediaGrid();
}

