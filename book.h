#ifndef BOOK_H
#define BOOK_H
#include "IMedia.h"
#include <QtGlobal>

class Book : public IMedia {
private:
    QString author;
    quint8 totalPages;
    QString publisher;

public:
    Book(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid, const QString& author, quint8 totalPages, const QString& publisher);
    QList<MediaParam> getMediaParams() const override;
};

#endif // BOOK_H
