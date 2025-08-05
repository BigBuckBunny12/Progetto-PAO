#include "createmediadialog.h"
#include "mediaregistry.h"
#include "ui_createmediadialog.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QFileDialog>

CreateMediaDialog::CreateMediaDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateMediaDialog)
{
    ui->setupUi(this);
    pendingMedia = nullptr;
    auto it = mediaRegistry.begin();
    while (it != mediaRegistry.end()) {
        ui->mediaDropdown->addItem(it->label , static_cast<int>(it.key()));
        ++it;
    }
}

CreateMediaDialog::~CreateMediaDialog()
{
    delete ui;
}

void CreateMediaDialog::addParamWidgetToLayout(MediaParam parameter , QFormLayout* layout) {
    QWidget* inputWidget = nullptr;
    QLabel* imageViewer = nullptr;
    switch(parameter.type) {
        QLineEdit* lineEdit;
    case MediaParamType::Int:
        lineEdit = new QLineEdit();
        lineEdit->setValidator(new QIntValidator(lineEdit));
        inputWidget = lineEdit;
        break;
    case MediaParamType::String:
        inputWidget = new QLineEdit();
        break;
    case MediaParamType::Bool:
        inputWidget = new QCheckBox();
        break;
    case MediaParamType::Image:
        QPushButton* btn = new QPushButton("Seleziona immagine");
        imageViewer = new QLabel();
        QObject::connect(btn, &QPushButton::clicked, this, [this, imageViewer]() {
            openMediaImageSelection(imageViewer);
        });
        inputWidget = btn;
        break;
    }

    if (inputWidget) {
        layout->addRow(parameter.label, inputWidget);
    }

    if(imageViewer) {
        layout->addRow(QString() , imageViewer);
    }
}

void CreateMediaDialog::updateMediaCreationForm(const MediaType mediaType) {
    QLayoutItem *child;
    while ((child = ui->mediaInfoLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    if(pendingMedia) delete pendingMedia;
    pendingMedia = mediaRegistry[mediaType].factory();

    QList<MediaParam> mediaParams = pendingMedia->getMediaParams();
    auto it = mediaParams.begin();
    while (it != mediaParams.end()) {
        addParamWidgetToLayout(*it , ui->mediaInfoLayout);
        ++it;
    }
}

void CreateMediaDialog::on_mediaDropdown_currentIndexChanged(const int index) {
    QVariant data = ui->mediaDropdown->itemData(index);
    if (!data.isValid()) return;

    MediaType type = static_cast<MediaType>(data.toInt());

    updateMediaCreationForm(type);  // molto più pulito e type-safe
}

void CreateMediaDialog::openMediaImageSelection(QLabel* imageViewer) {
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        "Seleziona immagine",
        QString(),
        "Immagini (*.png *.jpg *.jpeg *.bmp)"
        );

    if (!imagePath.isEmpty()) {
        QPixmap pixmap(imagePath);
        if (!pixmap.isNull()) {
            imageViewer->setPixmap(pixmap.scaled(QSize(imageViewer->width() , imageViewer->width()), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            imageViewer->setText("Errore nel caricare l'immagine");
        }
    }
}

