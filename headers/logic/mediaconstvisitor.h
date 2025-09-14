#ifndef MEDIACONSTVISITOR_H
#define MEDIACONSTVISITOR_H

class Book;
class Movie;
class Article;

class MediaConstVisitor {
public:
    virtual ~MediaConstVisitor() = default;

    virtual void visit(const Book& book) = 0;
    virtual void visit(const Movie& movie) = 0;
    virtual void visit(const Article& article) = 0;
};

#endif // MEDIACONSTVISITOR_H
