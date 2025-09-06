#include "viewmediacreationvisitor.h"

void ViewMediaCreationVisitor::addStringField(const QString& label, const QString& value) {
    list->addItem(label + ": " + value);
}

void ViewMediaCreationVisitor::addImageField(const QString &label, const QString &imagePath) {
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(imagePath));
    item->setText(label);
    list->addItem(item);
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

