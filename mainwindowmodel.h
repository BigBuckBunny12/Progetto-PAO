#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include "IMedia.h"
#include "media.h"
#include "mediamanager.h"
class MainWindowModel
{
public:
    MainWindowModel();
    void mapMediaToWidget(IMedia* media , Media* widget);
    void unmapMediaFromWidget(IMedia* media , Media* widget);
    Media* getAssociatedMediaWidget(IMedia* media) const;
    IMedia* getAssociatedMediaObject(Media* widget) const;
    std::vector<IMedia*> getMediaFromSearch(const QString& query) const;
private:
    std::vector<IMedia*> displayMediaList;
    QMap<IMedia*, Media*> mediaWidgetMap;
    QMap<Media*, IMedia*> widgetMediaMap;
};

#endif // MAINWINDOWMODEL_H
