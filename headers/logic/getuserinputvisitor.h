#ifndef GETUSERINPUTVISITOR_H
#define GETUSERINPUTVISITOR_H

#include "MediaConstVisitor.h"
#include <QFormLayout>
#include <QVariant>
#include <QString>
#include <QList>

using MediaInput = QMap<QString, QVariant>;

class GetUserInputVisitor : public MediaConstVisitor {
private:
    QFormLayout* layout;
    MediaInput input;

    QWidget* findWidgetByTag(const QString& tag) const;
    void collectLineEdit(const QString& tag);
    void collectCheckBox(const QString& tag);
    void collectImage(const QString& tag);
    void collectSpinBox(const QString& tag);
    void collectComboBox(const QString& tag);
    void collectTimeEdit(const QString& tag);

public:
    GetUserInputVisitor(QFormLayout* layout) : layout(layout) {}

    void visit(const Book& book) override;
    void visit(const Movie& movie) override;
    void visit(const Article& article) override;

    const MediaInput& getCollectedInput() const;
};

#endif // GETUSERINPUTVISITOR_H
