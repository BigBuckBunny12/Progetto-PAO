#include "IMedia.h"

IMedia::IMedia(const QString& coverImageUrl, const QString& title, int publicationYear):
    coverImageUrl(coverImageUrl),
    title(title),
    publicationYear(publicationYear)
    {}

QString IMedia::getTitle() const {
    return title;
}

QString IMedia::getCoverImageUrl() const {
    return coverImageUrl;
}

int IMedia::getPublicationYear() const {
    return publicationYear;
}

int IMedia::getUid() const {
    return uid;
}

void IMedia::setUid(int newUid) {
    uid = newUid;
}
