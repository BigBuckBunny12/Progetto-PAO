#include "mediamanager.h"

MediaManager::~MediaManager() {
    for (IMedia* media : mediaList) {
        delete media;
    }
    mediaList.clear();
}

MediaManager& MediaManager::instance() {
    static MediaManager singletonInstance;
    return singletonInstance;
}

// aggiunge un media all'elenco dei media
void MediaManager::addMedia(IMedia* media) {
    if(!media) return;
    media->setUid(currentUid);
    mediaList.push_back(media);
    currentUid++;
}

void MediaManager::deleteMedia(IMedia* media) {

}
