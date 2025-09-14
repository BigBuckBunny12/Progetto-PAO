#include "IMedia.h"

IMedia::IMedia(const QString& coverImageUrl, const QString& title, int publicationYear):
    coverImageUrl(coverImageUrl),
    title(title),
    publicationYear(publicationYear)
    {}

QString IMedia::getTitle() const {
    return title;
}

QString IMedia::getCoverImagePath() const {
    return coverImageUrl;
}

int IMedia::getPublicationYear() const {
    return publicationYear;
}

int IMedia::getUid() const {
    return uid;
}

void IMedia::setTitle(const QString& t) {
    title = t;
}

void IMedia::setPublicationYear(int y) {
    publicationYear = y;
}

void IMedia::setCoverImageUrl(const QString& url) {
    coverImageUrl = url;
}

void IMedia::setUid(int newUid) {
    uid = newUid;
}
