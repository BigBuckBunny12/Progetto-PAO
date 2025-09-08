#include "article.h"
#include <qpixmap.h>

Article::Article(): IMedia("", "", 0) {}

Article::Article(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
                 const QString& source, const QString& doi, int issueNumber, bool isScientificPaper):
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

IMedia* Article::clone() const {
    Article* copy = new Article();
    copy->setTitle(this->getTitle());
    copy->setPublicationYear(this->getPublicationYear());
    copy->setSource(this->getSource());
    copy->setDoi(this->getDoi());
    copy->setIssueNumber(this->getIssueNumber());
    copy->setIsScientificPaper(this->getIsScientificPaper());
    copy->setCoverImageUrl(this->getCoverImageUrl());
    return copy;
}

QString Article::getTitle() const { return title; }
int Article::getPublicationYear() const { return publicationYear; }
QString Article::getSource() const { return source; }
QString Article::getDoi() const { return doi; }
int Article::getIssueNumber() const { return issueNumber; }
bool Article::getIsScientificPaper() const { return isScientificPaper; }
QString Article::getCoverImageUrl() const { return coverImageUrl; }

void Article::setTitle(const QString& t) { title = t; }
void Article::setPublicationYear(int y) { publicationYear = y; }
void Article::setSource(const QString& s) { source = s; }
void Article::setDoi(const QString& d) { doi = d; }
void Article::setIssueNumber(int n) { issueNumber = n; }
void Article::setIsScientificPaper(bool b) { isScientificPaper = b; }
void Article::setCoverImageUrl(const QString& url) { coverImageUrl = url; }
