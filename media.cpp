#include "media.h"
#include "ui_media.h"

Media::Media(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Media)
{
    ui->setupUi(this);
}

Media::~Media()
{
    delete ui;
}

float Media::aspectRatio = 311.0 / 500.0;
