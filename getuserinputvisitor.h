#ifndef GETUSERINPUTVISITOR_H
#define GETUSERINPUTVISITOR_H

#include "MediaVisitor.h"
#include <QFormLayout>
#include <QVariant>
#include <QString>
#include <QList>

using MediaInput = QMap<QString, QVariant>;

class GetUserInputVisitor : public MediaVisitor {
private:
    QFormLayout* layout;
    MediaInput input;

    QWidget* findWidgetByTag(const QString& tag) const;
    void collectLineEdit(const QString& tag);
    void collectCheckBox(const QString& tag);
    void collectImage(const QString& tag);

public:
    GetUserInputVisitor(QFormLayout* layout) : layout(layout) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

    const MediaInput& getCollectedInput() const;
};

#endif // GETUSERINPUTVISITOR_H
