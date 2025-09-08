#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <vector>
#include "IMedia.h"

class MediaManager : public QObject
{
    Q_OBJECT
private:
    MediaManager() = default;
    ~MediaManager();
    MediaManager(const MediaManager&) = delete;
    MediaManager& operator=(const MediaManager&) = delete;

    std::vector<IMedia*> mediaList;
    int currentUid = 1;
    int findMediaIndexByUid(int uid) const;

public:
    static MediaManager& instance();
    void updateMedia(IMedia* oldMedia, IMedia* newMedia);
    void addMedia(IMedia* media);
    void deleteMedia(IMedia* media);
    void loadMediaList(const std::vector<IMedia*>& mediaVector);
    std::vector<IMedia*> getMediaList() const;
    std::vector<IMedia*> getMediaMatchingString(const QString& str) const;

signals:
    void mediaCreated(IMedia* media);
    void mediaRemoved(IMedia* media);
};

#endif // MEDIAMANAGER_H
