#include "book.h"
#include <qpixmap.h>

Book::Book(): IMedia("", "", 0) {}

Book::Book(const QString& coverImageUrl, const QString& title, const int publicationYear,
           const QString& author, int totalPages, const QString& publisher, const Genre g):
           IMedia(coverImageUrl, title, publicationYear),
           author(author),
           totalPages(totalPages),
           publisher(publisher),
           genre(g){}

IMedia* Book::clone() const {
    return new Book(
        getCoverImagePath(),
        getTitle(),
        getPublicationYear(),
        getAuthor(),
        getTotalPages(),
        getPublisher(),
        getGenre()
    );
}

QString Book::getAuthor() const { return author; }
int Book::getTotalPages() const { return totalPages; }
QString Book::getPublisher() const { return publisher; }
Book::Genre Book::getGenre() const { return genre; }

void Book::setAuthor(const QString& a) { author = a; }
void Book::setTotalPages(int p) { totalPages = p; }
void Book::setPublisher(const QString& p) { publisher = p; }
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
