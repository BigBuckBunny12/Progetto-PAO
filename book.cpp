#include "book.h"
#include <qpixmap.h>
#include <unordered_map>


Book::Book(): IMedia("", "", 0) {}

Book::Book(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid,
           const QString& author, int totalPages, const QString& publisher, const Genre g):
           IMedia(coverImageUrl, title, publicationYear),
           author(author),
           totalPages(totalPages),
           publisher(publisher),
           genre(g){}

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
    copy->setGenre(this->getGenre());
    return copy;
}

QString Book::getTitle() const { return title; }
int Book::getPublicationYear() const { return publicationYear; }
QString Book::getAuthor() const { return author; }
int Book::getTotalPages() const { return totalPages; }
QString Book::getPublisher() const { return publisher; }
QString Book::getCoverImageUrl() const { return coverImageUrl; }
Book::Genre Book::getGenre() const { return genre; }
void Book::setTitle(const QString& t) { title = t; }
void Book::setPublicationYear(int y) { publicationYear = y; }
void Book::setAuthor(const QString& a) { author = a; }
void Book::setTotalPages(int p) { totalPages = p; }
void Book::setPublisher(const QString& p) { publisher = p; }
void Book::setCoverImageUrl(const QString& url) { coverImageUrl = url; }
void Book::setGenre(const Genre g) { genre = g;}

const std::map<Book::Genre, QString>& Book::genreKeys() {
    static const std::map<Book::Genre, QString> keys = {
        { ACTION, "Action" },
        { COMEDY, "Comedy" },
        { MYSTERY, "Mystery" },
        { HORROR, "Horror" },
        { SCIENCE_FICTION, "Science_Fiction" },
        { FANTASY, "Fantasy" },
        { ROMANCE, "Romance" },
        { BIOGRAPHY, "Biography" },
        { POETRY, "Poetry" },
        { OTHER, "Other" }
    };
    return keys;
}

const std::map<Book::Genre, QString>& Book::genreLabels() {
    static const std::map<Book::Genre, QString> labels = {
        { ACTION, "Azione" },
        { COMEDY, "Commedia" },
        { MYSTERY, "Giallo" },
        { HORROR, "Horror" },
        { SCIENCE_FICTION, "Fantascienza" },
        { FANTASY, "Fantasy" },
        { ROMANCE, "Romantico" },
        { BIOGRAPHY, "Biografia" },
        { POETRY, "Poesia" },
        { OTHER, "Altro" }
    };
    return labels;
}

Book::Genre Book::keyToGenre(const QString& key) {
    for (const auto& [genre, k] : genreKeys()) {
        if (k == key)
            return static_cast<Book::Genre>(genre);
    }
    return OTHER;
}
