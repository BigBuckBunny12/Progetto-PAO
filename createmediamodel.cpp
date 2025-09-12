#include "createmediamodel.h"
#include "checkuserinputvisitor.h"
#include "applyuserinputvisitor.h"
#include "mediamanager.h"
#include "mediaregistry.h"
#include <QDebug>

IMedia* CreateMediaModel::setPendingMedia(MediaType type) {
    //if(pendingMedia) delete pendingMedia;
    pendingMedia = mediaRegistry[type].factory();
    return pendingMedia;
}

IMedia* CreateMediaModel::getPendingMedia() const {
    return pendingMedia;
}

void CreateMediaModel::setBehaviour(MediaCreationBehaviour behaviour, IMedia* media) {
    currentBehaviour = behaviour;
    editingMedia = media;
}

MediaCreationBehaviour CreateMediaModel::getBehaviour() const {
    return currentBehaviour;
}

IMedia* CreateMediaModel::getEditingMedia() const {
    return editingMedia;
}

void CreateMediaModel::createMedia(IMedia* media) {
    MediaManager::instance().addMedia(media);
}

bool CreateMediaModel::processInput(const MediaInput& userInput) {
    CheckUserInputVisitor inputChecker(userInput);
    pendingMedia->accept(inputChecker);
    errorMessages = inputChecker.getErrorFeedback();
    if(inputChecker.getResult()) {
        qDebug() << "Input utente valido";
        ApplyUserInputVisitor inputToMediaSetter(userInput);
        if(currentBehaviour == CREATE) {
            pendingMedia->accept(inputToMediaSetter);
            createMedia(pendingMedia->clone());
            return true;
        }
        if(currentBehaviour == EDIT) {
            editingMedia->accept(inputToMediaSetter);
            emit mediaUpdated(editingMedia);
            return true;
        }
    }

    qDebug() << "Input utente NON valido";
    return false;
}

std::vector<QString> CreateMediaModel::getErrorMessages() const {
    return errorMessages;
}
