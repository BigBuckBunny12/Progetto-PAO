#include "mediawidgetvisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"


void MediaWidgetVisitor::visit(Book& book) {
    mediaWidget.setLabel(book.getTitle());
    mediaWidget.setImage(book.getCoverImageUrl());
    mediaWidget.setIcon(":/resources/img/book_icon.png");
}
void MediaWidgetVisitor::visit(Movie& movie) {
    mediaWidget.setLabel(movie.getTitle());
    mediaWidget.setImage(movie.getCoverImageUrl());
    mediaWidget.setIcon(":/resources/img/movie_icon.png");
}
void MediaWidgetVisitor::visit(Article& article) {
    mediaWidget.setLabel(article.getTitle());
    mediaWidget.setImage(article.getCoverImageUrl());
    mediaWidget.setIcon(":/resources/img/article_icon.png");
}
