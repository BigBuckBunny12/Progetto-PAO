#ifndef MOVIE_H
#define MOVIE_H

#include "IMedia.h"
#include <QtGlobal>

class Movie : public IMedia {
private:
    quint16 duration;
    QString producer;

public:
    Movie(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid, quint16 duration, const QString& producer);
    QList<MediaParam> getMediaParams() const override;
};
#endif // MOVIE_H
