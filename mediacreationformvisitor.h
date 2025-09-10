#ifndef MEDIACREATIONFORMVISITOR_H
#define MEDIACREATIONFORMVISITOR_H

#include "MediaVisitor.h"
#include "createmediamodel.h"
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
    CreateMediaModel* model;

public:
    MediaCreationFormVisitor(QFormLayout* layout, CreateMediaModel* referenceModel, QWidget* parent = nullptr)
        : layout(layout), parent(parent), model(referenceModel) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;

private:
    QLineEdit* addLineEdit(const QString& label, const QString& tag, const QString& startText = "", bool numeric = false);
    QCheckBox* addCheckBox(const QString& label, const QString& tag, const bool& startValue = false);
    QPushButton* addImageSelector(const QString& label,  const QString& tag, const QString& startText = "");
    void addRow(const QString& label, QWidget* widget, const QString& tag);

    const QString lineEditStyle =
        "QLineEdit {"
        "    color: rgb(0, 0, 0);"
        "    background-color: rgb(233, 238, 246);"
        "    border-radius: 7px;"
        "    border: 2px solid rgb(233, 238, 246);"
        "    padding: 5px 10px;"
        "    min-height: 14px;"
        "    max-height: 14px;"
        "}"
        "QLineEdit:hover {"
        "    border: 2px solid rgb(220, 220, 220);"
        "    background-color: rgb(250, 250, 250);"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(150, 150, 150);"
        "    background-color: rgb(230, 230, 230);"
        "}"
        "QLineEdit:disabled {"
        "    background-color: rgb(240, 240, 240);"
        "    color: rgb(150, 150, 150);"
        "}";
};

#endif // MEDIACREATIONFORMVISITOR_H
