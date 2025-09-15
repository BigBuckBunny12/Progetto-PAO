#include "createmediamodel.h"
#include "checkuserinputvisitor.h"
#include "applyuserinputvisitor.h"
#include "mediamanager.h"
#include "mediaregistry.h"
#include <QDebug>

CreateMediaModel::CreateMediaModel(MediaCreationBehaviour behaviour) : currentBehaviour(behaviour) {
    pendingMedia = nullptr;
    editingMedia = nullptr;
}

IMedia* CreateMediaModel::setPendingMedia(MediaType type) {
    delete pendingMedia;
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

void CreateMediaModel::createMedia(IMedia* media) const {
    MediaManager::instance().addMedia(media);
}

bool CreateMediaModel::processInput(const MediaInput& userInput) {
    IMedia* mediaToProcess = pendingMedia;
    if(currentBehaviour == EDIT) mediaToProcess = editingMedia;

    CheckUserInputVisitor inputChecker(userInput);
    mediaToProcess->accept(inputChecker);
    errorMessages = inputChecker.getErrorFeedback();
    if(inputChecker.getResult()) {
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

    return false;
}

std::vector<QString> CreateMediaModel::getErrorMessages() const {
    return errorMessages;
}
