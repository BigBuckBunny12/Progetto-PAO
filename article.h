#ifndef ARTICLE_H
#define ARTICLE_H

#include "IMedia.h"
#include "mediavisitor.h"
#include <QtGlobal>

class Article : public IMedia {
private:
    QString source;
    bool isScientificPaper;
    QString doi;
    quint16 issueNumber;

public:
    Article();
    Article(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid, const QString& source, const QString& doi, quint16 issueNumber, bool isScientificPaper = false);
    IMedia* clone() const override;
    QList<MediaParam> getMediaParams() const override;
    void accept(MediaVisitor& visitor) override {
        visitor.visit(*this);
    }

    QString getTitle() const;
    int getPublicationYear() const;
    QString getSource() const;
    QString getDoi() const;
    int getIssueNumber() const;
    bool getIsScientificPaper() const;
    QString getCoverImageUrl() const;

    void setTitle(const QString& t);
    void setPublicationYear(int y);
    void setSource(const QString& s);
    void setDoi(const QString& d);
    void setIssueNumber(int n);
    void setIsScientificPaper(bool b);
    void setCoverImageUrl(const QString& url);
};

#endif // ARTICLE_H
