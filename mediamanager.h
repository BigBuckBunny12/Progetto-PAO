#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <vector>
#include "IMedia.h"

class MediaManager
{
private:
    std::vector<IMedia*> mediaList;
    static int currentUid;

public:
    MediaManager();
    ~MediaManager();

    void addMedia(IMedia* media);
    void deleteMedia(IMedia* media);
    void loadMediaList(const std::vector<IMedia*>& mediaVector);
};

#endif // MEDIAMANAGER_H
