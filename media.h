#ifndef MEDIA_H
#define MEDIA_H

#include "IMedia.h"
#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Media;
}

class Media : public QWidget
{
    Q_OBJECT

public:
    explicit Media(IMedia* mediaObject , QWidget *parent = nullptr);
    ~Media();
    void setLabel(QString str);
    void setImage(QString path);
    IMedia* getMediaObject() const;

    static float aspectRatio;
signals:
    void clicked(Media* self);

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    Ui::Media *ui;
    IMedia* mediaObject;
};

#endif // MEDIA_H
