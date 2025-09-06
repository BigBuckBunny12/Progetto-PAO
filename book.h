#ifndef BOOK_H
#define BOOK_H
#include "IMedia.h"
#include "mediavisitor.h"
#include <QtGlobal>

class Book : public IMedia {
private:
    QString author;
    quint8 totalPages;
    QString publisher;

public:
    Book();
    Book(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid, const QString& author, quint8 totalPages, const QString& publisher);
    IMedia* clone() const override;
    QList<MediaParam> getMediaParams() const override;
    void accept(MediaVisitor& visitor) override {
        visitor.visit(*this);
    }

    QString getTitle() const;
    int getPublicationYear() const;
    QString getAuthor() const;
    int getTotalPages() const;
    QString getPublisher() const;
    QString getCoverImageUrl() const;

    void setTitle(const QString& t);
    void setPublicationYear(int y);
    void setAuthor(const QString& a);
    void setTotalPages(quint8 p);
    void setPublisher(const QString& p);
    void setCoverImageUrl(const QString& url);
};

#endif // BOOK_H
