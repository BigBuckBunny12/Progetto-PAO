#ifndef VIEWMEDIAMODEL_H
#define VIEWMEDIAMODEL_H

#include "IMedia.h"
#include "mediamanager.h"

class ViewMediaModel
{
public:
    ViewMediaModel();
    void deleteMedia(IMedia* media) const;
    void setMediaInView(IMedia* media);
    IMedia* getMediaInView() const;
private:
    IMedia* mediaInView;
};

#endif // VIEWMEDIAMODEL_H
