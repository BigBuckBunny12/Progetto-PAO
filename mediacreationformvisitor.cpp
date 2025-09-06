#include "MediaCreationFormVisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QPixmap>

// I seguenti metodi sono usati per facilitare la creazione del form evitando ripetizioni nel codice
QLineEdit* MediaCreationFormVisitor::addLineEdit(const QString& label, const QString& tag, const QString& startText, bool numeric) {
    QLineEdit* lineWidget = new QLineEdit(parent);
    if (numeric) {
        lineWidget->setValidator(new QIntValidator(lineWidget));
    }
    if(model->getBehaviour() == EDIT) {
        lineWidget->setText(startText);
    }
    addRow(label, lineWidget, tag);
    return lineWidget;
}

QCheckBox* MediaCreationFormVisitor::addCheckBox(const QString& label, const QString& tag, const bool& startValue) {
    QCheckBox* check = new QCheckBox(parent);
    if(model->getBehaviour() == EDIT) {
        check->setChecked(startValue);
    }
    addRow(label, check, tag);
    return check;
}

QPushButton* MediaCreationFormVisitor::addImageSelector(const QString& label, const QString& tag, const QString& startText) {
    QPushButton* btn = new QPushButton("Seleziona immagine", parent);
    QLabel* imageViewer = new QLabel(parent);
    imageViewer->setFixedSize(100, 100);
    imageViewer->setScaledContents(true);

    addRow(label, btn, tag + "_button");
    addRow(QString(), imageViewer, tag);
    QObject::connect(btn, &QPushButton::clicked, btn, [imageViewer, parent = this->parent]() {
        QString imagePath = QFileDialog::getOpenFileName(
            parent,
            "Seleziona immagine",
            QString(),
            "Immagini (*.png *.jpg *.jpeg *.bmp)"
            );
        if (!imagePath.isEmpty()) {
            QPixmap pixmap(imagePath);
            if (!pixmap.isNull()) {
                imageViewer->setPixmap(pixmap.scaled(QSize(100,100), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageViewer->setProperty("selectedImagePath", imagePath);
            } else {
                imageViewer->setText("Errore nel caricamento");
            }
        }
    });

    return btn;
}

void MediaCreationFormVisitor::addRow(const QString& label, QWidget* widget, const QString& tag) {
    widget->setProperty("tag", tag);
    layout->addRow(label, widget);
}

// Visitor pattern
void MediaCreationFormVisitor::visit(Book& book) {
    Book* editingMedia = &book;
    if(model->getBehaviour() == EDIT) {
        editingMedia = static_cast<Book*>(model->getEditingMedia());
    }
    addLineEdit("Titolo", "title", editingMedia->getTitle(), false);
    addLineEdit("Anno di pubblicazione", "year", QString::number(editingMedia->getPublicationYear()), true);
    addLineEdit("Autore", "author", editingMedia->getAuthor(), false);
    addLineEdit("Numero pagine", "pages", QString::number(editingMedia->getTotalPages()), true);
    addLineEdit("Editore", "publisher", editingMedia->getPublisher(), false);
    addImageSelector("Copertina", "cover", editingMedia->getCoverImageUrl());
}

void MediaCreationFormVisitor::visit(Movie& movie) {
    Movie* editingMedia = &movie;
    if(model->getBehaviour() == EDIT) {
        editingMedia = static_cast<Movie*>(model->getEditingMedia());
    }
    addLineEdit("Titolo", "title", editingMedia->getTitle(), false);
    addLineEdit("Anno di pubblicazione", "year", QString::number(editingMedia->getPublicationYear()), true);
    addLineEdit("Durata (minuti)", "duration", QString::number(editingMedia->getDuration()), true);
    addLineEdit("Produttore", "producer", editingMedia->getProducer(), false);
    addImageSelector("Copertina", "cover", editingMedia->getCoverImageUrl());
}

void MediaCreationFormVisitor::visit(Article& article) {
    Article* editingMedia = &article;
    if(model->getBehaviour() == EDIT) {
        editingMedia = static_cast<Article*>(model->getEditingMedia());
    }
    addLineEdit("Titolo", "title", editingMedia->getTitle(), false);
    addLineEdit("Anno di pubblicazione", "year", QString::number(editingMedia->getPublicationYear()), true);
    addLineEdit("Fonte", "source", editingMedia->getSource(), false);
    addLineEdit("DOI", "doi", editingMedia->getDoi(), false);
    addLineEdit("Numero fascicolo", "issueNumber", QString::number(editingMedia->getIssueNumber()), true);
    addCheckBox("Articolo scientifico", "isScientificPaper", editingMedia->getIsScientificPaper());
    addImageSelector("Copertina", "cover", editingMedia->getCoverImageUrl());
}
