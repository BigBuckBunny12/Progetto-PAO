#ifndef MEDIAREGISTRY_H
#define MEDIAREGISTRY_H
#include <QMap>

enum class MediaType {
    Book,
    Movie,
    Article
};

struct MediaDefinition {
    QString label;
    std::function<class IMedia*()> factory;
};

extern const QMap<MediaType, MediaDefinition> mediaRegistry;

#endif // MEDIAREGISTRY_H
