#include "mediaregistry.h"
#include "book.h"
#include "movie.h"
#include "article.h"

const QMap<MediaType, MediaDefinition> mediaRegistry = {
    { MediaType::Book, {
                          "Libro",
                          []() { return new Book("", "", 2024, "", 100, "", Book::OTHER); }
                      }},
    { MediaType::Movie, {
                           "Film",
                           []() { return new Movie("", "", 2024, 120, ""); }
                       }},
    { MediaType::Article, {
                             "Articolo",
                             []() { return new Article("", "", 2024, "", "", 1, false); }
                         }}
};
