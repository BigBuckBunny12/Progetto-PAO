#ifndef MOVIE_H
#define MOVIE_H

#include "imedia.h"
#include <QtGlobal>

class Movie : public IMedia {
private:
    int duration;
    QString producer;

public:
    Movie();
    Movie(const QString& coverImageUrl, const QString& title, const int publicationYear, const int duration, const QString& producer);
    void accept(MediaVisitor& visitor) override {
        visitor.visit(*this);
    }
    void accept(MediaConstVisitor& visitor) const override {
        visitor.visit(*this);
    }
    IMedia* clone() const override;

    int getDuration() const;
    QString getProducer() const;

    void setDuration(int d);
    void setProducer(const QString& p);
};
#endif // MOVIE_H
