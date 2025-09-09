#ifndef SAVEMEDIAVISITOR_H
#define SAVEMEDIAVISITOR_H

#include "mediavisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QString>
#include <QJsonObject>
#include <QJsonArray>

class SaveMediaVisitor : public MediaVisitor {
public:
    SaveMediaVisitor();

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

    QJsonObject getResult() const;

private:
    QJsonArray mediaArray;
    void reset();
};

#endif // SAVEMEDIAVISITOR_H
