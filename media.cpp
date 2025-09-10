#include "media.h"
#include "ui_media.h"

Media::Media(IMedia* mediaObj, QWidget *parent): QWidget(parent), ui(new Ui::Media), mediaObject(mediaObj)
{
    ui->setupUi(this);
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
    if(pixmap.isNull()) return;
    ui->mediaImage->setPixmap(pixmap);
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
