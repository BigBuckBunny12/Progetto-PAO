#include "IMedia.h"

IMedia::IMedia(const QString& path, const QString& title, int publicationYear):
    coverImagePath(path),
    title(title),
    publicationYear(publicationYear)
    {}

QString IMedia::getTitle() const {
    return title;
}

QString IMedia::getCoverImagePath() const {
    return coverImagePath;
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

void IMedia::setCoverImagePath(const QString& path) {
    coverImagePath = path;
}

void IMedia::setUid(int newUid) {
    uid = newUid;
}
