#include "mediawidgetvisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"


void MediaWidgetVisitor::visit(const Book& book) {
    mediaWidget.setLabel(book.getTitle());
    mediaWidget.setImage(book.getCoverImagePath());
    mediaWidget.setIcon(":/resources/img/book_icon.png");
}
void MediaWidgetVisitor::visit(const Movie& movie) {
    mediaWidget.setLabel(movie.getTitle());
    mediaWidget.setImage(movie.getCoverImagePath());
    mediaWidget.setIcon(":/resources/img/movie_icon.png");
}
void MediaWidgetVisitor::visit(const Article& article) {
    mediaWidget.setLabel(article.getTitle());
    mediaWidget.setImage(article.getCoverImagePath());
    mediaWidget.setIcon(":/resources/img/article_icon.png");
}
