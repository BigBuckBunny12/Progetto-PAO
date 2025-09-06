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

int MediaManager::findMediaIndexByUid(int uid) const {
    int left = 0;
    int right = mediaList.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midUid = mediaList[mid]->getUid();

        if (midUid == uid) {
            return mid;
        } else if (midUid < uid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void MediaManager::deleteMedia(IMedia* media) {
    int index = findMediaIndexByUid(media->getUid());
    if(index == -1) return;
    delete mediaList[index];
    mediaList.erase(mediaList.begin() + index);
    emit mediaRemoved(media);
}
