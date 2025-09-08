#ifndef CREATEMEDIAMODEL_H
#define CREATEMEDIAMODEL_H

#include <QObject>
#include "imedia.h"
#include "getuserinputvisitor.h"

enum MediaCreationBehaviour {
    CREATE,
    EDIT
};

class CreateMediaModel : public QObject {
    Q_OBJECT

public:
    CreateMediaModel(MediaCreationBehaviour behaviour) : currentBehaviour(behaviour) {}
    IMedia* setPendingMedia(MediaType type);
    IMedia* getPendingMedia() const;
    void setBehaviour(MediaCreationBehaviour behaviour, IMedia* media = nullptr);
    IMedia* getEditingMedia() const;
    MediaCreationBehaviour getBehaviour() const;
    void createMedia(IMedia* mediaToCreate);
    void editMedia(IMedia* mediaToEdit, IMedia* editedMedia);
    bool processInput(const MediaInput& input);

private:
    IMedia* editingMedia;
    IMedia* pendingMedia;
    MediaCreationBehaviour currentBehaviour;

signals:
    void mediaUpdated(IMedia* media);
};

#endif // CREATEMEDIAMODEL_H
