#include "IMedia.h"

IMedia::IMedia(const QString& coverImageUrl, const QString& title, int publicationYear):
    coverImageUrl(coverImageUrl),
    title(title),
    publicationYear(publicationYear)
    {}

int IMedia::getUid() const {
    return uid;
}

void IMedia::setUid(int newUid) {
    uid = newUid;
}
