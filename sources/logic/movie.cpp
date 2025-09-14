#include "movie.h"
#include <qpixmap.h>

Movie::Movie() : IMedia("", "", 0) {}


Movie::Movie(const QString& coverImageUrl, const QString& title, const int publicationYear,
             const int duration, const QString& producer):
             IMedia(coverImageUrl, title, publicationYear),
             duration(duration),
             producer(producer) {}

IMedia* Movie::clone() const {
    return new Movie(
        getCoverImagePath(),
        getTitle(),
        getPublicationYear(),
        getDuration(),
        getProducer()
    );
}

int Movie::getDuration() const { return duration; }
QString Movie::getProducer() const { return producer; }

void Movie::setDuration(int d) { duration = d; }
void Movie::setProducer(const QString& p) { producer = p; }
