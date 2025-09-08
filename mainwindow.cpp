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
    connect(&MediaManager::instance(), &MediaManager::mediaCreated,
            this, &MainWindow::onMediaCreated);

    connect(&MediaManager::instance(), &MediaManager::mediaRemoved,
                     this, &MainWindow::onMediaRemoved);

    connect(createMediaModel, &CreateMediaModel::mediaUpdated,
            this, &MainWindow::onMediaUpdated);

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
    createMediaDialog->setBehaviour(CREATE);
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

void MainWindow::onMediaCreated(IMedia* media) {
    Media* mediaWidget = new Media(media);
    MediaWidgetVisitor mediaCustomizer(*mediaWidget);
    media->accept(mediaCustomizer);
    connect(mediaWidget, &Media::clicked, this, [this](Media* media){
        qDebug() << "Media* (connect): " << media;
        viewMedia(model->getAssociatedMediaObject(media));
    });
    model->mapMediaToWidget(media, mediaWidget);
    refreshMediaGrid(ui->searchMediaField->displayText());
}

void MainWindow::onMediaRemoved(IMedia* media) {
    Media* mediaWidget = model->getAssociatedMediaWidget(media);
    ui->mediaGrid->removeWidget(mediaWidget);
    model->unmapMediaFromWidget(media, mediaWidget);
    delete mediaWidget;
    refreshMediaGrid(ui->searchMediaField->displayText());
}

void MainWindow::onMediaUpdated(IMedia* updatedMedia) {
    Media* mediaWidget = model->getAssociatedMediaWidget(updatedMedia);
    MediaWidgetVisitor mediaCustomizer(*mediaWidget);
    updatedMedia->accept(mediaCustomizer);
    refreshMediaGrid(ui->searchMediaField->displayText());
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

void MainWindow::editMedia(IMedia* mediaToEdit) const {
    qDebug() << "MediaToEdit: " << mediaToEdit->getTitle();
    ui->dialogContainer->show();
    ui->dialogContainer->setCurrentWidget(ui->createMediaPage);
    createMediaDialog->setBehaviour(EDIT , mediaToEdit);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    reflowMediaGrid();
}

void MainWindow::refreshMediaGrid(const QString mediaFilter) {
    std::vector<IMedia*> queryResult = model->getMediaFromSearch(mediaFilter);
    displayMediaList(queryResult);
    reflowMediaGrid();
}

void MainWindow::displayMediaList(std::vector<IMedia*> list) {
    QLayoutItem* item;
    while ((item = ui->mediaGrid->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->setParent(nullptr);
        }
        delete item;
    }

    int row = 0, col = 0;
    for(IMedia* media : list) {
        ui->mediaGrid->addWidget(model->getAssociatedMediaWidget(media), row, col);
        col++;
        if (col == GRID_MAX_COLUMNS) {
            col = 0;
            row++;
        }
    }
}

void MainWindow::on_searchMediaField_textChanged(const QString& query)
{
    refreshMediaGrid(query);
}

