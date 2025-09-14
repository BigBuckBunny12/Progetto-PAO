#ifndef IMEDIA_H
#define IMEDIA_H
#include "mediavisitor.h"
#include "mediaconstvisitor.h"
#include "mediaregistry.h"
#include <QString>
#include <qvariant.h>

class IMedia {
protected:
    QString coverImagePath;
    QString title;
    int publicationYear;
    int uid = 0;

public:
    IMedia(const QString& coverImagePath, const QString& title, const int publicationYear);
    virtual ~IMedia() = default;
    virtual IMedia* clone() const = 0;

    QString getTitle() const;
    QString getCoverImagePath() const;
    int getPublicationYear() const;
    int getUid() const;

    void setTitle(const QString& t);
    void setPublicationYear(int y);
    void setCoverImagePath(const QString& path);
    void setUid(int);
    virtual void accept(MediaVisitor& visitor) = 0;
    virtual void accept(MediaConstVisitor& visitor) const = 0;
};

#endif // IMEDIA_H
