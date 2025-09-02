#ifndef APPLYUSERINPUTVISITOR_H
#define APPLYUSERINPUTVISITOR_H

#include "mediavisitor.h"
#include "getuserinputvisitor.h"
#include <QMap>
#include <QString>
#include <QVariant>

class ApplyUserInputVisitor : public MediaVisitor
{
public:
    ApplyUserInputVisitor(const MediaInput& inputMap) : inputMap(inputMap) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

private:
    MediaInput inputMap;
    QVariant getValue(const QString& tag) const;
};

#endif // APPLYUSERINPUTVISITOR_H
