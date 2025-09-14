#include "mediafilter.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include "mediamanager.h"
#include <QRegularExpression>
#include <QDebug>
#include <algorithm>

MediaFilter& MediaFilter::instance() {
    static MediaFilter instance;
    return instance;
}

std::vector<IMedia*> MediaFilter::getMediaMatchingTitle(const QString& titleToMatch) const {
    if(titleToMatch.trimmed().isEmpty()) {
        return std::vector<IMedia*>();
    }
    std::vector<IMedia*> matches;
    for (IMedia* media : MediaManager::instance().getMediaList()) {
        if(media->getTitle().startsWith(titleToMatch, Qt::CaseInsensitive)) {
            matches.push_back(media);
        }
    }
    return matches;
}

std::vector<IMedia*> MediaFilter::getMediaMatchingQuery(const QString& query) const {
    std::vector<IMedia*> results = MediaManager::instance().getMediaList();
    // Sintassi query: <Chiave1:valore1 , Chiave2,valore2> (spazi opzionali)
    QRegularExpression regex("^<\\s*([^>]*)\\s*>$");
    QRegularExpressionMatch match = regex.match(query);

    if (!match.hasMatch()) {
        return getMediaMatchingTitle(query);
    }

    QString content = match.captured(1).trimmed();
    QStringList pairs = content.split(",", Qt::SkipEmptyParts); // {"tipo:libro","titolo:ciao",...}

    // Parametri estratti
    QString typeFilter = "";
    QString titleFilter = "";
    QString order = "";

    for (QString pairString : pairs) {
        pairString = pairString.trimmed();
        QStringList keyValue = pairString.split(":", Qt::SkipEmptyParts); // {"tipo","libro"}
        if(keyValue.count() < 2) continue;
        QString key = keyValue[0].trimmed().toLower();
        QString value = keyValue[1].trimmed();
        // Controllo che il filtro sia vuoto per invalidare doppi filtraggi
        if (key == "tipo" && typeFilter.isEmpty()) {
            typeFilter = value.toLower();
        }
        else if (key == "titolo" && titleFilter.isEmpty()) {
            titleFilter = value.toLower();
        }
        else if (key == "ordine" && order.isEmpty()) {
            order = value.toLower();
        }
    }

    if(!typeFilter.isEmpty() && typeFilter != "libro" && typeFilter != "film" && typeFilter != "articolo") return std::vector<IMedia*>();
    if(!order.isEmpty() && order != "alfabetico" && order != "anno") return std::vector<IMedia*>();

    // Si procede per sottrazione: ogni condizione positiva nel remove_if è sufficiente a invalidare il media corrente
    results.erase(
        std::remove_if(results.begin(), results.end(), [&](IMedia* media) {
            if (!typeFilter.isEmpty()) {
                if (typeFilter == "libro" && dynamic_cast<Book*>(media) == nullptr) return true;
                if (typeFilter == "film"  && dynamic_cast<Movie*>(media) == nullptr) return true;
                if (typeFilter == "articolo" && dynamic_cast<Article*>(media) == nullptr) return true;
            }
            if (!titleFilter.isEmpty() && !media->getTitle().toLower().startsWith(titleFilter)) {
                return true;
            }

            return false;
        }),
        results.end()
        );

    if (order == "alfabetico") {
        std::sort(results.begin(), results.end(), [](IMedia* a, IMedia* b) {
            return a->getTitle().toLower() < b->getTitle().toLower();
        });
    } else if (order == "anno") {
        std::sort(results.begin(), results.end(), [](IMedia* a, IMedia* b) {
            return a->getPublicationYear() < b->getPublicationYear();
        });
    }

    return results;
}
