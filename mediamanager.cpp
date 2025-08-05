#include "mediamanager.h"

int MediaManager::currentUid = 1;

MediaManager::MediaManager() {}

MediaManager::~MediaManager() {}

// aggiunge un media all'elenco dei media
void MediaManager::addMedia(IMedia* media) {
    media->setUid(currentUid);
    mediaList.push_back(media);
    currentUid++;
}

void MediaManager::deleteMedia(IMedia* media) {

}
