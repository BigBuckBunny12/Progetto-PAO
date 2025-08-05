#include "article.h"
#include <qpixmap.h>

Article::Article(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
                 const QString& source, const QString& doi, quint16 issueNumber, bool isScientificPaper):
                 IMedia(coverImageUrl, title, publicationYear),
                 source(source),
                 isScientificPaper(isScientificPaper),
                 doi(doi),
                 issueNumber(issueNumber) {}

QList<MediaParam> Article::getMediaParams() const {
    return {
        MediaParam{ "Titolo", MediaParamType::String, title },
        MediaParam{ "Anno di pubblicazione", MediaParamType::Int, publicationYear },
        MediaParam{ "Fonte", MediaParamType::String, source },
        MediaParam{ "DOI", MediaParamType::String, doi },
        MediaParam{ "Numero fascicolo", MediaParamType::Int, issueNumber },
        MediaParam{ "Articolo scientifico", MediaParamType::Bool, isScientificPaper},
        MediaParam{ "Copertina", MediaParamType::Image, QPixmap(coverImageUrl) }
    };
}
