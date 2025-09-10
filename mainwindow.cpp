#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "media.h"
#include "createmediadialog.h"
#include "mediawidgetvisitor.h"
#include "jsonmanager.h"
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

    // Setup connessioni
    connect(&MediaManager::instance(), &MediaManager::mediaCreated, this, &MainWindow::onMediaCreated);
    connect(&MediaManager::instance(), &MediaManager::mediaRemoved, this, &MainWindow::onMediaRemoved);
    connect(createMediaModel, &CreateMediaModel::mediaUpdated, this, &MainWindow::onMediaUpdated);
    connect(viewMediaDialog, &ViewMediaDialog::editMediaRequested, this, &MainWindow::editMedia);

    // Chiusura dialog
    ui->dialogContainer->hide();

    // Setup degli elementi grafici
    float const ICON_SCALE = 0.6;
    ui->saveButton->setIcon(QIcon(":/resources/img/save_icon.png"));
    ui->saveButton->setIconSize(QSize(ui->saveButton->width() * ICON_SCALE,ui->saveButton->height() * ICON_SCALE));
    ui->loadButton->setIcon(QIcon(":/resources/img/load_icon.png"));
    ui->loadButton->setIconSize(QSize(ui->loadButton->width() * ICON_SCALE,ui->loadButton->height() * ICON_SCALE));
    ui->newMediaButton->setIcon(QIcon(":/resources/img/new_icon.png"));
    ui->newMediaButton->setIconSize(QSize(ui->newMediaButton->width() * ICON_SCALE,ui->newMediaButton->height() * ICON_SCALE));
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(80);
    shadow->setOffset(0, 10);
    shadow->setColor(QColor(0, 0, 0, 100));
    ui->topBar->setGraphicsEffect(shadow);

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
    Media* mediaWidget = model->getAssociatedMediaWidget(media);

    for (int i = 0; i < ui->mediaGrid->count(); ++i) {
        QWidget* widget = ui->mediaGrid->itemAt(i)->widget();
        if (widget) {
            Media* media = qobject_cast<Media*>(widget);
            if (media) {
                media->setSelected(false);
            }
        }
    }

    if(mediaWidget) {
        mediaWidget->setSelected(true);
    }
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
    if (model->isSearchQueryValid(mediaFilter) && queryResult.empty()) {
        ui->searchMediaField->setStyleSheet(searchMediaErrorStyle);
    } else {
        ui->searchMediaField->setStyleSheet(searchMediaValidStyle);
    }
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

void MainWindow::clearMediaGrid() {
    if(!ui->mediaGrid) return;
    QLayoutItem* item;
    while ((item = ui->mediaGrid->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void MainWindow::on_searchMediaField_textChanged(const QString& query)
{
    refreshMediaGrid(query);
}


void MainWindow::on_saveButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Salva media",
        QString(),
        "File JSON (*.json)"
        );

    if (filePath.isEmpty()) {
        return;
    }

    std::vector<IMedia*> mediaList = MediaManager::instance().getMediaList();
    JsonManager::instance().saveMediaData(mediaList, filePath);
}


void MainWindow::on_loadButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Carica media",
        QString(),
        "File JSON (*.json)"
        );

    if (filePath.isEmpty()) {
        return;
    }

    std::vector<IMedia*> mediaList = JsonManager::instance().loadMediaData(filePath);
    ui->searchMediaField->setText("");
    refreshMediaGrid();
}


