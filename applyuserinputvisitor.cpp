#include "applyuserinputvisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"

void ApplyUserInputVisitor::visit(Book& book) {
    book.setTitle(inputMap["title"].toString());
    book.setPublicationYear(inputMap["year"].toInt());
    book.setAuthor(inputMap["author"].toString());
    book.setTotalPages(inputMap["pages"].toInt());
    book.setPublisher(inputMap["publisher"].toString());
    book.setGenre(static_cast<Book::Genre>(inputMap["genre"].toInt()));
    book.setCoverImageUrl(inputMap["cover"].toString());
    qDebug() << "book genre: " << book.getGenre();
}

void ApplyUserInputVisitor::visit(Movie& movie) {
    movie.setTitle(inputMap["title"].toString());
    movie.setPublicationYear(inputMap["year"].toInt());
    movie.setDuration(inputMap["duration"].toInt());
    movie.setProducer(inputMap["producer"].toString());
    movie.setCoverImageUrl(inputMap["cover"].toString());
}

void ApplyUserInputVisitor::visit(Article& article) {
    article.setTitle(inputMap["title"].toString());
    article.setPublicationYear(inputMap["year"].toInt());
    article.setSource(inputMap["source"].toString());
    article.setDoi(inputMap["doi"].toString());
    article.setIssueNumber(inputMap["issueNumber"].toInt());
    article.setIsScientificPaper(inputMap["isScientificPaper"].toBool());
    article.setCoverImageUrl(inputMap["cover"].toString());
}
