#include "movie.h"
#include <qpixmap.h>

Movie::Movie(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
             quint16 duration, const QString& producer):
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
