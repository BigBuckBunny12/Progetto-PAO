#ifndef BOOK_H
#define BOOK_H
#include "imedia.h"
#include <QtGlobal>

class Book : public IMedia {
public:
    enum Genre {
        ACTION,
        COMEDY,
        MYSTERY,
        HORROR,
        SCIENCE_FICTION,
        FANTASY,
        ROMANCE,
        BIOGRAPHY,
        POETRY,
        OTHER
    };

private:
    QString author;
    int totalPages;
    QString publisher;
    Genre genre;

public:
    Book();
    Book(const QString& coverImagePath, const QString& title, const int publicationYear, const QString& author, int totalPages, const QString& publisher, const Genre g);
    IMedia* clone() const override;
    void accept(MediaVisitor& visitor) override {
        visitor.visit(*this);
    }
    void accept(MediaConstVisitor& visitor) const override {
        visitor.visit(*this);
    }

    QString getAuthor() const;
    int getTotalPages() const;
    QString getPublisher() const;
    Genre getGenre() const;

    void setAuthor(const QString& a);
    void setTotalPages(int p);
    void setPublisher(const QString& p);
    void setGenre(const Genre g);

    static const std::map<Genre, QString>& genreKeys();
    static const std::map<Genre, QString>& genreLabels();
    static Genre keyToGenre(const QString& key);
};

#endif // BOOK_H
