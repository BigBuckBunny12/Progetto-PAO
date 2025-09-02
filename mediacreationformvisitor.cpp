#include "MediaCreationFormVisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QPixmap>

// I seguenti metodi sono usati per facilitare la creazione del form evitando ripetizioni nel codice
QLineEdit* MediaCreationFormVisitor::addLineEdit(const QString& label, const QString& tag, bool numeric) {
    QLineEdit* edit = new QLineEdit(parent);
    if (numeric) {
        edit->setValidator(new QIntValidator(edit));
    }
    addRow(label, edit, tag);
    return edit;
}

QCheckBox* MediaCreationFormVisitor::addCheckBox(const QString& label, const QString& tag) {
    QCheckBox* check = new QCheckBox(parent);
    addRow(label, check, tag);
    return check;
}

QPushButton* MediaCreationFormVisitor::addImageSelector(const QString& label, const QString& tag) {
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
    addLineEdit("Titolo", "title");
    addLineEdit("Anno di pubblicazione", "year", true);
    addLineEdit("Autore", "author");
    addLineEdit("Numero pagine", "pages", true);
    addLineEdit("Editore", "publisher");
    addImageSelector("Copertina", "cover");
}

void MediaCreationFormVisitor::visit(Movie& movie) {
    addLineEdit("Titolo", "title");
    addLineEdit("Anno di pubblicazione", "year", true);
    addLineEdit("Durata (minuti)", "duration", true);
    addLineEdit("Produttore", "producer");
    addImageSelector("Copertina", "cover");
}

void MediaCreationFormVisitor::visit(Article& article) {
    addLineEdit("Titolo", "title");
    addLineEdit("Anno di pubblicazione", "year", true);
    addLineEdit("Fonte", "source");
    addLineEdit("DOI", "doi");
    addLineEdit("Numero fascicolo", "issueNumber", true);
    addCheckBox("Articolo scientifico", "isScientificPaper");
    addImageSelector("Copertina", "cover");
}
