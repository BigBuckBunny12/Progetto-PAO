#include "movie.h"
#include <qpixmap.h>

Movie::Movie() : IMedia("", "", 0) {}


Movie::Movie(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
             const int duration, const QString& producer):
             IMedia(coverImageUrl, title, publicationYear),
             duration(duration),
             producer(producer) {}

QList<MediaParam> Movie::getMediaParams() const {
    return {
        MediaParam{ "Titolo", MediaParamType::String, title },
        MediaParam{ "Anno di pubblicazione", MediaParamType::Int, publicationYear },
        MediaParam{ "Durata (minuti)", MediaParamType::Int, duration },
        MediaParam{ "Produttore", MediaParamType::String, producer },
        MediaParam{ "Copertina", MediaParamType::Image, QPixmap(coverImageUrl) }
    };
}

IMedia* Movie::clone() const {
    Movie* copy = new Movie();
    copy->setTitle(this->getTitle());
    copy->setPublicationYear(this->getPublicationYear());
    copy->setDuration(this->getDuration());
    copy->setProducer(this->getProducer());
    copy->setCoverImageUrl(this->getCoverImageUrl());
    return copy;
}

QString Movie::getTitle() const { return title; }
int Movie::getPublicationYear() const { return publicationYear; }
int Movie::getDuration() const { return duration; }
QString Movie::getProducer() const { return producer; }
QString Movie::getCoverImageUrl() const { return coverImageUrl; }

void Movie::setTitle(const QString& t) { title = t; }
void Movie::setPublicationYear(int y) { publicationYear = y; }
void Movie::setDuration(int d) { duration = d; }
void Movie::setProducer(const QString& p) { producer = p; }
void Movie::setCoverImageUrl(const QString& url) { coverImageUrl = url; }
