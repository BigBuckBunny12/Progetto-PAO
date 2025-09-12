#include "media.h"
#include "ui_media.h"

Media::Media(IMedia* mediaObj, QWidget *parent): QWidget(parent), ui(new Ui::Media), mediaObject(mediaObj)
{
    ui->setupUi(this);
    ui->icon->setScaledContents(true);
    setSelected(false);
}

Media::~Media()
{
    delete ui;
}

float Media::aspectRatio = 311.0 / 500.0;

void Media::setLabel(QString str) {
    ui->mediaTitle->setText(str);
}

void Media::setImage(QString path) {
    QPixmap pixmap(path);
    image = pixmap;
    updateImageSize();
}

// ridimensionamento copertina: emula la funzionalità cover di CSS
void Media::updateImageSize() {
    if (image.isNull()) return;

    QPixmap scaled = image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    int xOffset = (scaled.width() - width()) / 2;
    int yOffset = (scaled.height() - height()) / 2;

    QPixmap cropped = scaled.copy(xOffset, yOffset, width(), height());
    ui->mediaImage->setPixmap(cropped);
    ui->mediaImage->setAlignment(Qt::AlignCenter);
}

void Media::resizeEvent(QResizeEvent* event) {
    updateImageSize();
    QWidget::resizeEvent(event);
}

void Media::setIcon(QString path) {
    QPixmap pixmap(path);
    QPixmap scaled = pixmap.scaledToHeight(ICON_HEIGHT, Qt::SmoothTransformation);
    ui->icon->setPixmap(scaled);
    ui->icon->setFixedSize(scaled.size());
    ui->icon->setAlignment(Qt::AlignCenter);
}

void Media::setSelected(bool selected) {
    if(selected) {
        ui->container->setStyleSheet(selectedStyle);
    } else {
        ui->container->setStyleSheet(deselectedStyle);
    }
}

void Media::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked(this);
    }
    QWidget::mousePressEvent(event);
}

IMedia* Media::getMediaObject() const {
    return mediaObject;
}
