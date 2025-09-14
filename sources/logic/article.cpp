#include "article.h"

Article::Article(): IMedia("", "", 0) {}

Article::Article(const QString& coverImageUrl, const QString& title, const int publicationYear,
                 const QString& source, const QString& doi, int issueNumber, bool isScientificPaper):
                 IMedia(coverImageUrl, title, publicationYear),
                 source(source),
                 isScientificPaper(isScientificPaper),
                 doi(doi),
                 issueNumber(issueNumber) {}

IMedia* Article::clone() const {
    return new Article(
        getCoverImagePath(),
        getTitle(),
        getPublicationYear(),
        getSource(),
        getDoi(),
        getIssueNumber(),
        getIsScientificPaper()
    );
}

QString Article::getSource() const { return source; }
QString Article::getDoi() const { return doi; }
int Article::getIssueNumber() const { return issueNumber; }
bool Article::getIsScientificPaper() const { return isScientificPaper; }

void Article::setSource(const QString& s) { source = s; }
void Article::setDoi(const QString& d) { doi = d; }
void Article::setIssueNumber(int n) { issueNumber = n; }
void Article::setIsScientificPaper(bool b) { isScientificPaper = b; }
