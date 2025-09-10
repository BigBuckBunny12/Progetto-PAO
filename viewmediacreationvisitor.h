#ifndef VIEWMEDIACREATIONVISITOR_H
#define VIEWMEDIACREATIONVISITOR_H

#include "MediaVisitor.h"
#include "qlistwidget.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QIntValidator>
#include <QFileDialog>

class ViewMediaCreationVisitor : public MediaVisitor {
private:
    QLayout* infoLayout;
    QWidget* parent;

public:
    ViewMediaCreationVisitor(QLayout* layout, QWidget* parent = nullptr) : infoLayout(layout), parent(parent) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

private:
    void addStringField(const QString& label, const QString& value);
    void addImageField(const QString& label, const QString& imagePath);
};


#endif // VIEWMEDIACREATIONVISITOR_H
