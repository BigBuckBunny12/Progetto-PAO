#include "viewmediamodel.h"

ViewMediaModel::ViewMediaModel() {}

void ViewMediaModel::setMediaInView(IMedia* media) {
    mediaInView = media;
}

IMedia* ViewMediaModel::getMediaInView() const {
    return mediaInView;
}


void ViewMediaModel::deleteMedia(IMedia* media) const {
    MediaManager::instance().deleteMedia(media);
}
