#include "savemediavisitor.h"
#include <QJsonValue>
#include <QPixmap>

SaveMediaVisitor::SaveMediaVisitor(): mediaArray(QJsonArray()) {}

void SaveMediaVisitor::visit(Book& book) {
    QJsonObject obj;
    obj["type"] = "Book";
    obj["title"] = book.getTitle();
    obj["year"] = book.getPublicationYear();
    obj["author"] = book.getAuthor();
    obj["pages"] = book.getTotalPages();
    obj["publisher"] = book.getPublisher();
    obj["coverImageUrl"] = book.getCoverImageUrl();
    mediaArray.append(obj);
}

void SaveMediaVisitor::visit(Movie& movie) {
    QJsonObject obj;
    obj["type"] = "Movie";
    obj["title"] = movie.getTitle();
    obj["year"] = movie.getPublicationYear();
    obj["duration"] = movie.getDuration();
    obj["producer"] = movie.getProducer();
    obj["coverImageUrl"] = movie.getCoverImageUrl();
    mediaArray.append(obj);
}

void SaveMediaVisitor::visit(Article& article) {
    QJsonObject obj;
    obj["type"] = "Article";
    obj["title"] = article.getTitle();
    obj["year"] = article.getPublicationYear();
    obj["source"] = article.getSource();
    obj["doi"] = article.getDoi();
    obj["issueNumber"] = article.getIssueNumber();
    obj["isScientificPaper"] = article.getIsScientificPaper();
    obj["coverImageUrl"] = article.getCoverImageUrl();
    mediaArray.append(obj);
}

QJsonObject SaveMediaVisitor::getResult() const {
    QJsonObject root;
    root["mediaList"] = mediaArray;
    return root;
}

void SaveMediaVisitor::reset() {
    mediaArray = QJsonArray();
}
