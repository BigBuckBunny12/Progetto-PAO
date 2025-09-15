#ifndef ARTICLE_H
#define ARTICLE_H

#include "imedia.h"
#include <QtGlobal>

class Article : public IMedia {
private:
    QString source;
    bool isScientificPaper;
    QString doi;
    int issueNumber;

public:
    Article();
    Article(const QString& coverImageUrl, const QString& title, const int publicationYear, const QString& source, const QString& doi, int issueNumber, bool isScientificPaper = false);
    IMedia* clone() const override;
    void accept(MediaVisitor& visitor) override {
        visitor.visit(*this);
    }
    void accept(MediaConstVisitor& visitor) const override {
        visitor.visit(*this);
    }

    QString getSource() const;
    QString getDoi() const;
    int getIssueNumber() const;
    bool getIsScientificPaper() const;

    void setSource(const QString& s);
    void setDoi(const QString& d);
    void setIssueNumber(int n);
    void setIsScientificPaper(bool b);
};

#endif // ARTICLE_H
