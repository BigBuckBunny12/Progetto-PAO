#ifndef MEDIATYPES_H
#define MEDIATYPES_H
#include <QString>
#include <qvariant.h>

enum class MediaParamType {
    String,
    Int,
    Image,
    Bool,
};

enum class MediaType {
    Book,
    Movie,
    Article
};

struct MediaParam {
    QString label;
    MediaParamType type;
    QVariant value;

    MediaParam(const QString& label, MediaParamType type, const QVariant& value)
        : label(label), type(type), value(value) {}
};

struct MediaDefinition {
    QString label;
    std::function<class IMedia*()> factory;
};

#endif // MEDIATYPES_H
