#include "createmediadialog.h"
#include "applyuserinputvisitor.h"
#include "checkuserinputvisitor.h"
#include "mediacreationformvisitor.h"
#include "getuserinputvisitor.h"
#include "mediamanager.h"
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

// void CreateMediaDialog::addParamWidgetToLayout(MediaParam parameter , QFormLayout* layout) {
//     QWidget* inputWidget = nullptr;
//     QLabel* imageViewer = nullptr;
//     switch(parameter.type) {
//         QLineEdit* lineEdit;
//     case MediaParamType::Int:
//         lineEdit = new QLineEdit();
//         lineEdit->setValidator(new QIntValidator(lineEdit));
//         inputWidget = lineEdit;
//         break;
//     case MediaParamType::String:
//         inputWidget = new QLineEdit();
//         break;
//     case MediaParamType::Bool:
//         inputWidget = new QCheckBox();
//         break;
//     case MediaParamType::Image:
//         QPushButton* btn = new QPushButton("Seleziona immagine");
//         imageViewer = new QLabel();
//         QObject::connect(btn, &QPushButton::clicked, this, [this, imageViewer]() {
//             openMediaImageSelection(imageViewer);
//         });
//         layout->addRow(parameter.label, btn);
//         break;
//     }

//     if (inputWidget) {
//         inputWidget->setProperty("associatedParamType" , static_cast<int>(parameter.type));
//         layout->addRow(parameter.label, inputWidget);
//     }

//     if(imageViewer) {
//         imageViewer->setProperty("associatedParamType" , static_cast<int>(parameter.type));
//         layout->addRow(QString() , imageViewer);
//     }
// }

void CreateMediaDialog::updateMediaCreationForm(const MediaType mediaType) {
    QLayoutItem *child;
    while ((child = ui->mediaInfoLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    if(pendingMedia) delete pendingMedia;
    pendingMedia = mediaRegistry[mediaType].factory();
    MediaCreationFormVisitor visitor(ui->mediaInfoLayout, this);
    pendingMedia->accept(visitor);
    // QList<MediaParam> mediaParams = pendingMedia->getMediaParams();
    // auto it = mediaParams.begin();
    // while (it != mediaParams.end()) {
    //     addParamWidgetToLayout(*it , ui->mediaInfoLayout);
    //     ++it;
    // }
}

void CreateMediaDialog::on_mediaDropdown_currentIndexChanged(const int index) {
    QVariant data = ui->mediaDropdown->itemData(index);
    if (!data.isValid()) return;

    MediaType type = static_cast<MediaType>(data.toInt());

    updateMediaCreationForm(type);
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
            imageViewer->setProperty("selectedImagePath" , imagePath);
            imageViewer->setPixmap(pixmap.scaled(QSize(imageViewer->width() , imageViewer->width()), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            imageViewer->setText("Errore nel caricare l'immagine");
        }
    }
}

QList<QVariant> CreateMediaDialog::collectUserInput(QFormLayout* layout) const {
    QList<QVariant> userInput;

    const int rowCount = layout->rowCount();
    for(int i = 0; i < rowCount; i++) {
        if(layout->itemAt(i, QFormLayout::FieldRole) == nullptr) continue;
        QWidget* field = layout->itemAt(i, QFormLayout::FieldRole)->widget();
        if(field->property("associatedParamType").isNull()) continue;

        int typeInt = field->property("associatedParamType").toInt();
        MediaParamType paramType = static_cast<MediaParamType>(typeInt);

        QVariant value;
        switch (paramType) {
        case MediaParamType::Int: {
            QLineEdit* edit = qobject_cast<QLineEdit*>(field);
            if (edit) value = edit->text().toInt();
            break;
        }
        case MediaParamType::String: {
            QLineEdit* edit = qobject_cast<QLineEdit*>(field);
            if (edit) value = edit->text();
            break;
        }
        case MediaParamType::Bool: {
            QCheckBox* check = qobject_cast<QCheckBox*>(field);
            if (check) value = check->isChecked();
            break;
        }
        case MediaParamType::Image: {
            QString path = field->property("selectedImagePath").toString();
            value = path;
            break;
        }
        case MediaParamType::Duration:
            break;
        }

        if (value.isValid()) {
            userInput.append(value);
        }
    }
    return userInput;
}

bool CreateMediaDialog::areInputsValid() const {
    QList<QVariant> userInput = collectUserInput(ui->mediaInfoLayout);
    QList<MediaParam> mediaParams = pendingMedia->getMediaParams();
    if(userInput.length() != mediaParams.length()) {
        return false;
    }
    return true;
}

void CreateMediaDialog::setUpdateMode(const CreateMediaDialog::updateModes mode) {
    updateMode = mode;
    if(updateMode == CreateMediaDialog::updateModes::UPDATE) {
        ui->ConfirmButton->setText("Applica modifiche");
    } else {
        ui->ConfirmButton->setText("Crea");
    }
}

void logUserInput(const QMap<QString, QVariant>& inputMap) {
    qDebug() << "----- User Input -----";
    for (auto it = inputMap.constBegin(); it != inputMap.constEnd(); ++it) {
        const QString& key = it.key();
        const QVariant& value = it.value();
        qDebug() << key << ":" << value.toString();
    }
    qDebug() << "----------------------";
}


void CreateMediaDialog::on_ConfirmButton_clicked() {
    GetUserInputVisitor inputCollector(ui->mediaInfoLayout);
    pendingMedia->accept(inputCollector);
    MediaInput userInput = inputCollector.getCollectedInput();
    CheckUserInputVisitor inputChecker(userInput);
    pendingMedia->accept(inputChecker);
    if(inputChecker.getResult()) {
        qDebug() << "Input utente valido";
        logUserInput(userInput);
        ApplyUserInputVisitor inputToMediaSetter(userInput);
        pendingMedia->accept(inputToMediaSetter);
        MediaManager::instance().addMedia(pendingMedia);
        emit mediaCreated(pendingMedia);
    } else {
        qDebug() << "Input utente NON valido";
    }
}

QWidget* CreateMediaDialog::findWidgetByTag(const QString& tag) const {
    const int rowCount = ui->mediaInfoLayout->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QWidget* w = ui->mediaInfoLayout->itemAt(i, QFormLayout::FieldRole)
        ? ui->mediaInfoLayout->itemAt(i, QFormLayout::FieldRole)->widget()
        : nullptr;
        if (!w) continue;

        QVariant wTag = w->property("tag");
        if (wTag.isValid() && wTag.toString() == tag) {
            return w;
        }
    }
    return nullptr;
}



