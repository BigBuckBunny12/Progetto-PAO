#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H

class Book;
class Movie;
class Article;

class MediaVisitor {
public:
    virtual ~MediaVisitor() = default;

    virtual void visit(Book& book) = 0;
    virtual void visit(Movie& movie) = 0;
    virtual void visit(Article& article) = 0;
};

#endif // MEDIAVISITOR_H
