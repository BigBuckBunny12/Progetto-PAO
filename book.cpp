#include "book.h"
#include <qpixmap.h>

Book::Book(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
           const QString& author, quint8 totalPages, const QString& publisher):
           IMedia(coverImageUrl, title, publicationYear),
           author(author),
           totalPages(totalPages),
           publisher(publisher) {}

QList<MediaParam> Book::getMediaParams() const {
    return {
        MediaParam{ "Titolo", MediaParamType::String, title },
        MediaParam{ "Anno di pubblicazione", MediaParamType::Int, publicationYear },
        MediaParam{ "Autore", MediaParamType::String, author },
        MediaParam{ "Numero pagine", MediaParamType::Int, totalPages },
        MediaParam{ "Editore", MediaParamType::String, publisher },
        MediaParam{ "Copertina", MediaParamType::Image, QPixmap(coverImageUrl) }
    };
}
