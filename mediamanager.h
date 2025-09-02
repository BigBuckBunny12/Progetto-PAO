#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <vector>
#include "IMedia.h"

class MediaManager
{
private:
    MediaManager() = default;
    ~MediaManager();
    MediaManager(const MediaManager&) = delete;
    MediaManager& operator=(const MediaManager&) = delete;

    std::vector<IMedia*> mediaList;
    int currentUid = 1;

public:
    static MediaManager& instance();
    void addMedia(IMedia* media);
    void deleteMedia(IMedia* media);
    void loadMediaList(const std::vector<IMedia*>& mediaVector);
};

#endif // MEDIAMANAGER_H
