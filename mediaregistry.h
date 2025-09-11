#ifndef MEDIAREGISTRY_H
#define MEDIAREGISTRY_H
#include "mediatypes.h"
#include "article.h"
#include "book.h"
#include "movie.h"
#include <QString>
#include <qvariant.h>

const QMap<MediaType, MediaDefinition> mediaRegistry = {
    { MediaType::Book, {
                          "Libro",
                          []() { return new Book("", "", 2024, -1, "", 100, "", Book::OTHER); }
                      }},
    { MediaType::Movie, {
                           "Film",
                           []() { return new Movie("", "", 2024, -1, 120, ""); }
                       }},
    { MediaType::Article, {
                             "Articolo",
                             []() { return new Article("", "", 2024, -1, "", "", 1, false); }
                         }}
};

#endif // MEDIAREGISTRY_H
