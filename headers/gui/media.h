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
    void setLabel(const QString& str);
    void setImage(const QString& path);
    void setIcon(const QString& path);
    void setSelected(const bool selected);
    IMedia* getMediaObject() const;
    static const float aspectRatio;

signals:
    void clicked(Media* self);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::Media *ui;
    IMedia* mediaObject;
    QPixmap image;
    void updateImageSize();
    const int ICON_HEIGHT = 32;
    const QString deselectedStyle =
        "QWidget#container {"
        "    border-radius: 5px;"
        "    border: none;"
        "    background-color: rgb(255, 255, 255);"
        "}"
        "QWidget#container:hover {"
        "    border: 2px solid rgb(197, 208, 224);"
        "}";

    const QString selectedStyle =
        "QWidget#container {"
        "    border-radius: 5px;"
        "    border: 2px solid rgb(0, 120, 215);"
        "    background-color: rgb(220, 235, 255);"
        "}";
};

#endif // MEDIA_H
