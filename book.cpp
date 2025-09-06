#include "book.h"
#include <qpixmap.h>

Book::Book(): IMedia("", "", 0) {}

Book::Book(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
           const QString& author, quint8 totalPages, const QString& publisher):
           IMedia(coverImageUrl, title, publicationYear),
           author(author),
           totalPages(totalPages),
           publisher(publisher) {}

QList<MediaParam> Book::getMediaParams() const {
    return {
        MediaParam{ "Titolo", MediaParamType::String, title },
        MediaParam{ "Anno di pubblicazione", MediaParamType::Int, publicationYear },
        MediaParam{ "Autore", MediaParamType::String, author },
        MediaParam{ "Numero pagine", MediaParamType::Int, totalPages },
        MediaParam{ "Editore", MediaParamType::String, publisher },
        MediaParam{ "Copertina", MediaParamType::Image, QPixmap(coverImageUrl) }
    };
}

IMedia* Book::clone() const {
    Book* copy = new Book();
    copy->setTitle(this->getTitle());
    copy->setAuthor(this->getAuthor());
    copy->setPublicationYear(this->getPublicationYear());
    copy->setPublisher(this->getPublisher());
    copy->setTotalPages(this->getTotalPages());
    copy->setCoverImageUrl(this->getCoverImageUrl());
    return copy;
}

QString Book::getTitle() const { return title; }
int Book::getPublicationYear() const { return publicationYear; }
QString Book::getAuthor() const { return author; }
int Book::getTotalPages() const { return totalPages; }
QString Book::getPublisher() const { return publisher; }
QString Book::getCoverImageUrl() const { return coverImageUrl; }

void Book::setTitle(const QString& t) { title = t; }
void Book::setPublicationYear(int y) { publicationYear = y; }
void Book::setAuthor(const QString& a) { author = a; }
void Book::setTotalPages(quint8 p) { totalPages = p; }
void Book::setPublisher(const QString& p) { publisher = p; }
void Book::setCoverImageUrl(const QString& url) { coverImageUrl = url; }
