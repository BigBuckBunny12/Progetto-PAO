#include "GetUserInputVisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>

const MediaInput& GetUserInputVisitor::getCollectedInput() const {
    return input;
}

QWidget* GetUserInputVisitor::findWidgetByTag(const QString& tag) const {
    const int rowCount = layout->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QWidget* w = layout->itemAt(i, QFormLayout::FieldRole)
        ? layout->itemAt(i, QFormLayout::FieldRole)->widget()
        : nullptr;
        if (!w) continue;

        QVariant wTag = w->property("tag");
        if (wTag.isValid() && wTag.toString() == tag) {
            return w;
        }
    }
    return nullptr;
}

void GetUserInputVisitor::collectLineEdit(const QString& tag) {
    if (QWidget* w = findWidgetByTag(tag)) {
        if (QLineEdit* edit = qobject_cast<QLineEdit*>(w)) {
            input.insert(tag, edit->text());
        }
    }
}

void GetUserInputVisitor::collectCheckBox(const QString& tag) {
    if (QWidget* w = findWidgetByTag(tag)) {
        if (QCheckBox* check = qobject_cast<QCheckBox*>(w)) {
            input.insert(tag, check->isChecked());
        }
    }
}

void GetUserInputVisitor::collectImage(const QString& tag) {
    if (QWidget* w = findWidgetByTag(tag)) {
        if (QLabel* lbl = qobject_cast<QLabel*>(w)) {
            input.insert(tag, lbl->property("selectedImagePath"));
        }
    }
}

// Visitor implementations
void GetUserInputVisitor::visit(Book& book) {
    collectLineEdit("title");
    collectLineEdit("year");
    collectLineEdit("author");
    collectLineEdit("pages");
    collectLineEdit("publisher");
    collectImage("cover");
}

void GetUserInputVisitor::visit(Movie& movie) {
    collectLineEdit("title");
    collectLineEdit("year");
    collectLineEdit("duration");
    collectLineEdit("producer");
    collectImage("cover");
}

void GetUserInputVisitor::visit(Article& article) {
    collectLineEdit("title");
    collectLineEdit("year");
    collectLineEdit("source");
    collectLineEdit("doi");
    collectLineEdit("issueNumber");
    collectCheckBox("isScientificPaper");
    collectImage("cover");
}
