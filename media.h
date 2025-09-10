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
    void setSelected(bool selected);
    IMedia* getMediaObject() const;

    static float aspectRatio;
signals:
    void clicked(Media* self);

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    Ui::Media *ui;
    IMedia* mediaObject;
    const QString deselectedStyle =
        "QWidget#container {"
        "border-radius: 5px;"
        "border: none;"
        "background-color: rgb(240, 240, 240);"
        "}";

    const QString selectedStyle =
        "QWidget#container {"
        "border-radius: 5px;"
        "border: 2px solid rgb(0, 120, 215);"
        "background-color: rgb(220, 235, 255);"
        "}";
};

#endif // MEDIA_H
