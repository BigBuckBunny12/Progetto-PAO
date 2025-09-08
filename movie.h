#ifndef MOVIE_H
#define MOVIE_H

#include "mediavisitor.h"
#include "IMedia.h"
#include <QtGlobal>

class Movie : public IMedia {
private:
    int duration;
    QString producer;

public:
    Movie();
    Movie(const QString& coverImageUrl, const QString& title, const int publicationYear, const int uid, const int duration, const QString& producer);
    QList<MediaParam> getMediaParams() const override;
    void accept(MediaVisitor& visitor) override {
        visitor.visit(*this);
    }
    IMedia* clone() const override;

    QString getTitle() const;
    int getPublicationYear() const;
    int getDuration() const;
    QString getProducer() const;
    QString getCoverImageUrl() const;

    void setTitle(const QString& t);
    void setPublicationYear(int y);
    void setDuration(int d);
    void setProducer(const QString& p);
    void setCoverImageUrl(const QString& url);
};
#endif // MOVIE_H
