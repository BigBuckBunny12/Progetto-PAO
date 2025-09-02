#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>

namespace Ui {
class Media;
}

class Media : public QWidget
{
    Q_OBJECT

public:
    explicit Media(QWidget *parent = nullptr);
    ~Media();
    void setLabel(QString str);
    void setImage(QString path);

    static float aspectRatio;

private:
    Ui::Media *ui;
};

#endif // MEDIA_H
