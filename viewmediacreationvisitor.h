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
    QLabel* icon;
    QWidget* parent;

public:
    ViewMediaCreationVisitor(QLayout* layout, QLabel* labelIcon, QWidget* parent = nullptr) : infoLayout(layout), icon(labelIcon), parent(parent) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

private:
    void addStringField(const QString& label, const QString& value);
    void addImageField(const QString& label, const QString& imagePath);
    void setIcon(const QString& path);
    QString formatMinutes(const int minutes) const;
    const int ICON_SIZE = 32;
};


#endif // VIEWMEDIACREATIONVISITOR_H
