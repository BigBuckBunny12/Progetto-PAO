#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include "IMedia.h"
#include "media.h"
class MainWindowModel
{
public:
    MainWindowModel();
    void mapMediaToWidget(IMedia* media , Media* widget);
    void unmapMediaFromWidget(IMedia* media , Media* widget);
    Media* getAssociatedMediaWidget(IMedia* media) const;
    IMedia* getAssociatedMediaObject(Media* widget) const;
private:
    QMap<IMedia*, Media*> mediaWidgetMap;
    QMap<Media*, IMedia*> widgetMediaMap;
};

#endif // MAINWINDOWMODEL_H
