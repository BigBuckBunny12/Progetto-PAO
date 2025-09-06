#ifndef IMEDIA_H
#define IMEDIA_H
#include "mediatypes.h"
#include "mediavisitor.h"
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
    QString getCoverImageUrl() const;
    int getPublicationYear() const;
    int getUid() const;
    void setUid(int);
    virtual QList<MediaParam> getMediaParams() const = 0;
    virtual void accept(MediaVisitor& visitor) = 0;
};

#endif // IMEDIA_H
