#ifndef MEDIAFILTER_H
#define MEDIAFILTER_H

#include "imedia.h"

class MediaFilter {
public:
    static MediaFilter& instance();

    std::vector<IMedia*> getMediaMatchingQuery(const QString& query) const;
    std::vector<IMedia*> getMediaMatchingTitle(const QString& titleToMatch) const;

private:
    MediaFilter() = default;
    MediaFilter(const MediaFilter&) = delete;
    MediaFilter& operator=(const MediaFilter&) = delete;
};

#endif // MEDIAFILTER_H
