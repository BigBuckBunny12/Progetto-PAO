#include "viewmediacreationvisitor.h"

void ViewMediaCreationVisitor::addStringField(const QString& label, const QString& value) {
    QLabel* field = new QLabel(QString("<b>%1:</b> %2").arg(label, value), parent);
    infoLayout->addWidget(field);
}

void ViewMediaCreationVisitor::addImageField(const QString &label, const QString &imagePath) {
    QLabel* labelWidget = new QLabel(QString("<b>%1:</b>").arg(label), parent);
    infoLayout->addWidget(labelWidget);

    QLabel* imageLabel = new QLabel(parent);
    QPixmap pixmap(imagePath);
    const float IMAGE_SCALE = 0.66;
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(parent->width() * IMAGE_SCALE, pixmap.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("Nessuna immagine disponibile");
        imageLabel->setAlignment(Qt::AlignCenter);
    }
    infoLayout->addWidget(imageLabel);
}

void ViewMediaCreationVisitor::visit(Book& book) {
    addStringField("Titolo", book.getTitle());
    addStringField("Anno di pubblicazione", QString::number(book.getPublicationYear()));
    addStringField("Autore", book.getAuthor());
    addStringField("Numero pagine", QString::number(book.getTotalPages()));
    addStringField("Editore", book.getPublisher());
    addImageField("Copertina", book.getCoverImageUrl());
}

void ViewMediaCreationVisitor::visit(Movie& movie) {
    addStringField("Titolo", movie.getTitle());
    addStringField("Anno di pubblicazione", QString::number(movie.getPublicationYear()));
    addStringField("Durata (minuti)", QString::number(movie.getDuration()));
    addStringField("Produttore", movie.getProducer());
    addImageField("Copertina", movie.getCoverImageUrl());
}

void ViewMediaCreationVisitor::visit(Article& article) {
    addStringField("Titolo", article.getTitle());
    addStringField("Anno di pubblicazione", QString::number(article.getPublicationYear()));
    addStringField("Fonte", article.getSource());
    addStringField("DOI", article.getDoi());
    addStringField("Numero fascicolo", QString::number(article.getIssueNumber()));
    addStringField("Articolo scientifico", article.getIsScientificPaper() ? "Sì" : "No");
    addImageField("Copertina", article.getCoverImageUrl());
}
