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

// Aggiunge un media all'elenco dei media
void MediaManager::addMedia(IMedia* media) {
    if(!media) return;
    media->setUid(currentUid);
    mediaList.push_back(media);
    currentUid++;
    emit mediaCreated(media);
}

// Binary search per un media specifico dato l'UID.
// IMPORTANTE: in mediaList i media sono ordinati in ordine crescente di UID
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
    emit mediaRemoved(media);
    delete mediaList[index];
    mediaList.erase(mediaList.begin() + index);
}

void MediaManager::clearMediaList() {
    for (IMedia* media : mediaList) {
        delete media;
    }
    mediaList.clear();
}

const std::vector<IMedia*>& MediaManager::getMediaList() const {
    return mediaList;
}

std::vector<IMedia*> MediaManager::getMediaMatchingString(const QString& str) const {
    if(str.trimmed().isEmpty()) {
        return std::vector<IMedia*>();
    }
    std::vector<IMedia*> matches;
    for (IMedia* media : mediaList) {
        if(media->getTitle().startsWith(str, Qt::CaseInsensitive)) {
            matches.push_back(media);
        }
    }
    return matches;
}
