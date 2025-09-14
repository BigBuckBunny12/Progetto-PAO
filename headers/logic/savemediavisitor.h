#ifndef SAVEMEDIAVISITOR_H
#define SAVEMEDIAVISITOR_H

#include "mediaconstvisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QString>
#include <QJsonObject>
#include <QJsonArray>

class SaveMediaVisitor : public MediaConstVisitor {
public:
    SaveMediaVisitor();

    void visit(const Book& book) override;
    void visit(const Movie& movie) override;
    void visit(const Article& article) override;

    QJsonObject getResult();

private:
    QJsonArray mediaArray;
    void reset();
};

#endif // SAVEMEDIAVISITOR_H
