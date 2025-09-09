#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel() {
    displayMediaList = MediaManager::instance().getMediaList();
}

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

void MainWindowModel::clearMappings() {
    mediaWidgetMap.clear();
    widgetMediaMap.clear();
}

std::vector<IMedia*> MainWindowModel::getMediaFromSearch(const QString& query) const {
    if(query.trimmed().isEmpty()) return MediaManager::instance().getMediaList();
    return MediaManager::instance().getMediaMatchingString(query);
}
