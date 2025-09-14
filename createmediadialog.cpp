#include "createmediadialog.h"
#include "applyuserinputvisitor.h"
#include "checkuserinputvisitor.h"
#include "createmediamodel.h"
#include "mediacreationformvisitor.h"
#include "getuserinputvisitor.h"
#include "mediamanager.h"
#include "mediaregistry.h"
#include "qabstractitemview.h"
#include "ui_createmediadialog.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QFileDialog>

CreateMediaDialog::CreateMediaDialog(CreateMediaModel* viewModel, QWidget *parent)
    : QWidget(parent), model(viewModel)
    , ui(new Ui::CreateMediaDialog)
{
    ui->setupUi(this);

    // Setup del menu a tendina per la selezione del tipo di media
    auto it = mediaRegistry.begin();
    while (it != mediaRegistry.end()) {
        ui->mediaDropdown->addItem(it->label , static_cast<int>(it.key()));
        ++it;
    }
    ui->mediaDropdown->setCurrentIndex(0);
    ui->mediaDropdown->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
}

CreateMediaDialog::~CreateMediaDialog()
{
    delete ui;
    delete model;
}

// Imposta il dialog in modalità creazione o modifica.
// La modalità EDIT (modifica) richiede il passaggio del media da modificare come argomento
void CreateMediaDialog::setBehaviour(const MediaCreationBehaviour targetBehaviour, IMedia* mediaToEdit) {
    model->setBehaviour(targetBehaviour, mediaToEdit);

    if(targetBehaviour == CREATE) {
        ui->dialogTitle->setText("Crea un nuovo media");
        ui->mediaDropdown->show();
        ui->ConfirmButton->setText("Crea");
        ui->mediaDropdown->setCurrentIndex(0);
        updateForm(model->getPendingMedia());
        return;
    }

    if (targetBehaviour == EDIT) {
        if(mediaToEdit == nullptr) {
            setBehaviour(CREATE);
            return;
        }

        ui->dialogTitle->setText("Modifica " + mediaToEdit->getTitle());
        ui->ConfirmButton->setText("Conferma");
        ui->mediaDropdown->hide();
        updateForm(mediaToEdit);
    }
}

void CreateMediaDialog::updateForm(IMedia* mediaToShow) {
    QLayoutItem *child;
    while ((child = ui->mediaInfoLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    MediaCreationFormVisitor formGenerator(ui->mediaInfoLayout, model, this);
    mediaToShow->accept(formGenerator);
    clearErrorMessages();
}

void CreateMediaDialog::on_mediaDropdown_currentIndexChanged(const int index) {
    QVariant data = ui->mediaDropdown->itemData(index);
    if (!data.isValid()) return;
    MediaType type = static_cast<MediaType>(data.toInt());
    updateForm(model->setPendingMedia(type));
}

void CreateMediaDialog::on_ConfirmButton_clicked() {
    GetUserInputVisitor inputCollector(ui->mediaInfoLayout);
    model->getPendingMedia()->accept(inputCollector);
    MediaInput input = inputCollector.getCollectedInput();
    bool success = model->processInput(input);
    displayErrorMessages(model->getErrorMessages());
    if(model->getBehaviour() == EDIT && success) {
        emit dialogClosed();
    }
}

void CreateMediaDialog::displayErrorMessages(const std::vector<QString>& messages) {
    clearErrorMessages();

    for (const QString& msg : messages) {
        QLabel* label = new QLabel(msg, this);
        label->setStyleSheet("color: red;");
        label->setWordWrap(true);
        ui->errorMessagesLayout->addWidget(label);
    }

    ui->errorMessagesLayout->addStretch();
}

void CreateMediaDialog::clearErrorMessages() {
    QLayoutItem* item;
    while ((item = ui->errorMessagesLayout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
}

void CreateMediaDialog::on_CancelButton_clicked()
{
    emit dialogClosed();
}

