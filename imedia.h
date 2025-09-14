#ifndef IMEDIA_H
#define IMEDIA_H
#include "mediavisitor.h"
#include "mediaregistry.h"
#include <QString>
#include <qvariant.h>

class IMedia {
protected:
    QString coverImageUrl;
    QString title;
    int publicationYear;
    int uid = 0;

public:
    IMedia(const QString& coverImageUrl, const QString& title, const int publicationYear);
    virtual ~IMedia() = default;
    virtual IMedia* clone() const = 0;

    QString getTitle() const;
    QString getCoverImagePath() const;
    int getPublicationYear() const;
    int getUid() const;

    void setTitle(const QString& t);
    void setPublicationYear(int y);
    void setCoverImageUrl(const QString& url);
    void setUid(int);
    virtual void accept(MediaVisitor& visitor) = 0;
};

#endif // IMEDIA_H
