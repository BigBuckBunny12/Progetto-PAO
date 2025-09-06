#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel() {}

void MainWindowModel::unmapMediaFromWidget(IMedia* media, Media* widget) {
    if (mediaWidgetMap.contains(media) && mediaWidgetMap[media] == widget) {
        mediaWidgetMap.remove(media);
    }
    if (widgetMediaMap.contains(widget) && widgetMediaMap[widget] == media) {
        widgetMediaMap.remove(widget);
    }
}

void MainWindowModel::mapMediaToWidget(IMedia* media, Media* widget) {
    mediaWidgetMap.insert(media , widget);
    widgetMediaMap.insert(widget, media);
}

Media* MainWindowModel::getAssociatedMediaWidget(IMedia* media) const {
    return mediaWidgetMap[media];
}

IMedia* MainWindowModel::getAssociatedMediaObject(Media* widget) const {
    return widgetMediaMap[widget];
}
