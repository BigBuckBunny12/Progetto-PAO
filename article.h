#ifndef ARTICLE_H
#define ARTICLE_H

#include "IMedia.h"
#include <QtGlobal>

class Article : public IMedia {
private:
    QString source;
    bool isScientificPaper;
    QString doi;
    quint16 issueNumber;

public:
    Article(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid, const QString& source, const QString& doi, quint16 issueNumber, bool isScientificPaper = false);
    QList<MediaParam> getMediaParams() const override;
};

#endif // ARTICLE_H
