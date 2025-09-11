/********************************************************************************
** Form generated from reading UI file 'media.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIA_H
#define UI_MEDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Media
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *container;
    QVBoxLayout *verticalLayout_2;
    QLabel *mediaImage;
    QLabel *mediaTitle;

    void setupUi(QWidget *Media)
    {
        if (Media->objectName().isEmpty())
            Media->setObjectName("Media");
        Media->resize(311, 540);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Media->sizePolicy().hasHeightForWidth());
        Media->setSizePolicy(sizePolicy);
        Media->setAutoFillBackground(false);
        Media->setStyleSheet(QString::fromUtf8("background-color: none;"));
        verticalLayout = new QVBoxLayout(Media);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        container = new QWidget(Media);
        container->setObjectName("container");
        verticalLayout_2 = new QVBoxLayout(container);
        verticalLayout_2->setObjectName("verticalLayout_2");
        mediaImage = new QLabel(container);
        mediaImage->setObjectName("mediaImage");
        mediaImage->setTextFormat(Qt::TextFormat::RichText);
        mediaImage->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/test.jpg")));
        mediaImage->setScaledContents(true);

        verticalLayout_2->addWidget(mediaImage);

        mediaTitle = new QLabel(container);
        mediaTitle->setObjectName("mediaTitle");

        verticalLayout_2->addWidget(mediaTitle);


        verticalLayout->addWidget(container);


        retranslateUi(Media);

        QMetaObject::connectSlotsByName(Media);
    } // setupUi

    void retranslateUi(QWidget *Media)
    {
        Media->setWindowTitle(QCoreApplication::translate("Media", "Form", nullptr));
        mediaImage->setText(QString());
        mediaTitle->setText(QCoreApplication::translate("Media", "<html><head/><body><p align=\"center\">Il conte di Montecristo</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Media: public Ui_Media {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIA_H
