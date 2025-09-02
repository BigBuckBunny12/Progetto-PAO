#include "mediawidgetvisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"


void MediaWidgetVisitor::visit(Book& book) {
    mediaWidget.setLabel(book.getTitle());
    mediaWidget.setImage(book.getCoverImageUrl());
}
void MediaWidgetVisitor::visit(Movie& movie) {
    mediaWidget.setLabel(movie.getTitle());
    mediaWidget.setImage(movie.getCoverImageUrl());
}
void MediaWidgetVisitor::visit(Article& article) {
    mediaWidget.setLabel(article.getTitle());
    mediaWidget.setImage(article.getCoverImageUrl());
}
