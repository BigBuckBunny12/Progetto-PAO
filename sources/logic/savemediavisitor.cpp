#include "savemediavisitor.h"
#include <QJsonValue>
#include <QPixmap>

SaveMediaVisitor::SaveMediaVisitor(): mediaArray(QJsonArray()) {}

void SaveMediaVisitor::visit(const Book& book) {
    QJsonObject obj;
    obj["type"] = "Book";
    obj["title"] = book.getTitle();
    obj["year"] = book.getPublicationYear();
    obj["author"] = book.getAuthor();
    obj["pages"] = book.getTotalPages();
    obj["publisher"] = book.getPublisher();
    obj["coverImagePath"] = book.getCoverImagePath();
    obj["genre"] = Book::genreKeys().at(book.getGenre());
    mediaArray.append(obj);
}

void SaveMediaVisitor::visit(const Movie& movie) {
    QJsonObject obj;
    obj["type"] = "Movie";
    obj["title"] = movie.getTitle();
    obj["year"] = movie.getPublicationYear();
    obj["duration"] = movie.getDuration();
    obj["producer"] = movie.getProducer();
    obj["coverImagePath"] = movie.getCoverImagePath();
    mediaArray.append(obj);
}

void SaveMediaVisitor::visit(const Article& article) {
    QJsonObject obj;
    obj["type"] = "Article";
    obj["title"] = article.getTitle();
    obj["year"] = article.getPublicationYear();
    obj["source"] = article.getSource();
    obj["doi"] = article.getDoi();
    obj["issueNumber"] = article.getIssueNumber();
    obj["isScientificPaper"] = article.getIsScientificPaper();
    obj["coverImagePath"] = article.getCoverImagePath();
    mediaArray.append(obj);
}

// Ritorna il JSON completo e resetta il visitor allo stato originale per ulteriori salvataggi
QJsonObject SaveMediaVisitor::getResult() {
    QJsonObject root;
    root["mediaList"] = mediaArray;
    reset();
    return root;
}

void SaveMediaVisitor::reset() {
    mediaArray = QJsonArray();
}
