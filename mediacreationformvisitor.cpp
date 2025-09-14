#include "MediaCreationFormVisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include "qcombobox.h"
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
    lineWidget->setStyleSheet(lineEditStyle);
    return lineWidget;
}

QCheckBox* MediaCreationFormVisitor::addCheckBox(const QString& label, const QString& tag, const bool& startValue) {
    QCheckBox* check = new QCheckBox(parent);
    if(model->getBehaviour() == EDIT) {
        check->setChecked(startValue);
    }
    addRow(label, check, tag);
    check->setStyleSheet(checkBoxStyle);
    return check;
}

QSpinBox* MediaCreationFormVisitor::addSpinBox(const QString& label,  const QString& tag, const int startValue) {
    QSpinBox* spinBox = new QSpinBox(parent);
    spinBox->setMinimum(0);
    spinBox->setMaximum(999999);
    spinBox->setStyleSheet(spinBoxStyle);
    if(model->getBehaviour() == EDIT) {
        spinBox->setValue(startValue);
    }
    addRow(label, spinBox, tag);
    return spinBox;
}

// ComboBox generico pensato per mostrare qualsiasi enum a cui sia associata una mappatura key->label
template <typename EnumType>
QComboBox* MediaCreationFormVisitor::addComboBox(
    const QString& label,
    const QString& tag,
    const std::map<EnumType, QString>& valuesMap,
    EnumType startValue)
{
    QComboBox* combo = new QComboBox(parent);
    combo->setStyleSheet(comboBoxStyle);

    for (const auto& [enumValue, name] : valuesMap) {
        combo->addItem(name, static_cast<int>(enumValue));
    }

    if (model->getBehaviour() == EDIT) {
        combo->setCurrentIndex(static_cast<int>(startValue));
    }

    addRow(label, combo, tag);
    return combo;
}

QTimeEdit* MediaCreationFormVisitor::addTimeEdit(const QString& label,  const QString& tag, const int startValue) {
    QTimeEdit* timeEdit = new QTimeEdit(parent);
    timeEdit->setDisplayFormat("HH:mm");
    if(model->getBehaviour() == EDIT) {
        int hours = startValue / 60;
        int minutes = startValue % 60;
        QTime time(hours, minutes);
        if (time.isValid()) {
            timeEdit->setTime(time);
        } else {
            timeEdit->setTime(QTime(0, 0));
        }
    }
    addRow(label, timeEdit, tag);
    timeEdit->setStyleSheet(timeEditStyle);
    return timeEdit;
}

QPushButton* MediaCreationFormVisitor::addImageSelector(const QString& label, const QString& tag, const QString& startPath) {
    QPushButton* btn = new QPushButton("Seleziona immagine", parent);
    QLabel* imageViewer = new QLabel(parent);
    imageViewer->setFixedSize(100, 100);
    imageViewer->setScaledContents(true);
    btn->setStyleSheet(pushButtonStyle);

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

    if(model->getBehaviour() == EDIT && !startPath.isEmpty()) {
        QPixmap pixmap(startPath);
        if (!pixmap.isNull()) {
            imageViewer->setPixmap(pixmap.scaled(QSize(100,100), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            imageViewer->setProperty("selectedImagePath", startPath);
        } else {
            imageViewer->setText("Errore nel caricamento");
        }
    }

    return btn;
}

void MediaCreationFormVisitor::addRow(const QString& label, QWidget* widget, const QString& tag) {
    widget->setProperty("tag", tag);
    layout->addRow(label, widget);
}

// Visitor pattern
void MediaCreationFormVisitor::visit(Book& book) {
    Book* editingMedia = &book;
    addLineEdit("Titolo", "title", editingMedia->getTitle(), false);
    addLineEdit("Anno di pubblicazione", "year", QString::number(editingMedia->getPublicationYear()), true);
    addLineEdit("Autore", "author", editingMedia->getAuthor(), false);
    addSpinBox("Numero pagine", "pages", editingMedia->getTotalPages());
    addLineEdit("Editore", "publisher", editingMedia->getPublisher(), false);
    addComboBox<Book::Genre>("Genere", "genre", Book::genreLabels(), editingMedia->getGenre());
    addImageSelector("Copertina", "cover", editingMedia->getCoverImagePath());
}

void MediaCreationFormVisitor::visit(Movie& movie) {
    Movie* editingMedia = &movie;
    addLineEdit("Titolo", "title", editingMedia->getTitle(), false);
    addLineEdit("Anno di pubblicazione", "year", QString::number(editingMedia->getPublicationYear()), true);
    addTimeEdit("Durata", "duration", editingMedia->getDuration());
    addLineEdit("Regista", "producer", editingMedia->getProducer(), false);
    addImageSelector("Copertina", "cover", editingMedia->getCoverImagePath());
}

void MediaCreationFormVisitor::visit(Article& article) {
    Article* editingMedia = &article;
    addLineEdit("Titolo", "title", editingMedia->getTitle(), false);
    addLineEdit("Anno di pubblicazione", "year", QString::number(editingMedia->getPublicationYear()), true);
    addLineEdit("Fonte", "source", editingMedia->getSource(), false);
    addLineEdit("DOI", "doi", editingMedia->getDoi(), false);
    addLineEdit("Numero fascicolo", "issueNumber", QString::number(editingMedia->getIssueNumber()), true);
    addCheckBox("Articolo scientifico", "isScientificPaper", editingMedia->getIsScientificPaper());
    addImageSelector("Copertina", "cover", editingMedia->getCoverImagePath());
}
