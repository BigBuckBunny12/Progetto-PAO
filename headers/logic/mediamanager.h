#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <vector>
#include "imedia.h"

class MediaManager : public QObject
{
    Q_OBJECT
private:
    MediaManager(QObject* parent = nullptr) : QObject(parent) {}
    ~MediaManager();
    MediaManager(const MediaManager&) = delete;
    MediaManager& operator=(const MediaManager&) = delete;

    std::vector<IMedia*> mediaList;
    int currentUid = 1;
    int findMediaIndexByUid(int uid) const;

public:
    static MediaManager& instance();
    void addMedia(IMedia* media);
    void deleteMedia(IMedia* media);
    void clearMediaList();
    const std::vector<IMedia*>& getMediaList() const;

signals:
    void mediaCreated(IMedia* media);
    void mediaRemoved(IMedia* media);
};

#endif // MEDIAMANAGER_H
