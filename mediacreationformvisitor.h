#ifndef MEDIACREATIONFORMVISITOR_H
#define MEDIACREATIONFORMVISITOR_H

#include "MediaVisitor.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QIntValidator>
#include <QFileDialog>

class MediaCreationFormVisitor : public MediaVisitor {
private:
    QFormLayout* layout;
    QWidget* parent;

public:
    MediaCreationFormVisitor(QFormLayout* layout, QWidget* parent = nullptr)
        : layout(layout), parent(parent) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

private:
    QLineEdit* addLineEdit(const QString& label, const QString& tag, bool numeric = false);
    QCheckBox* addCheckBox(const QString& label, const QString& tag);
    QPushButton* addImageSelector(const QString& label,  const QString& tag);
    void addRow(const QString& label, QWidget* widget, const QString& tag);
};

#endif // MEDIACREATIONFORMVISITOR_H
