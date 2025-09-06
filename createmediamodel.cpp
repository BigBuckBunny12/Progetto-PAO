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
    emit mediaCreated(media);
}

bool CreateMediaModel::processInput(const MediaInput& userInput) {
    CheckUserInputVisitor inputChecker(userInput);
    pendingMedia->accept(inputChecker);
    if(inputChecker.getResult()) {
        qDebug() << "Input utente valido";
        ApplyUserInputVisitor inputToMediaSetter(userInput);
        pendingMedia->accept(inputToMediaSetter);
        if(currentBehaviour == CREATE) {
            createMedia(pendingMedia->clone());
        } else {

        }
        return true;
    }

    qDebug() << "Input utente NON valido";
    return false;
}
