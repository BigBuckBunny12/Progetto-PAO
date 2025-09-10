/********************************************************************************
** Form generated from reading UI file 'viewmediadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMEDIADIALOG_H
#define UI_VIEWMEDIADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewMediaDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *mediaTitle;
    QVBoxLayout *infoContainer;
    QScrollArea *scrollArea;
    QWidget *mediaInfo;
    QVBoxLayout *infoLayout;
    QHBoxLayout *actionButtonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *exitButton;

    void setupUi(QWidget *ViewMediaDialog)
    {
        if (ViewMediaDialog->objectName().isEmpty())
            ViewMediaDialog->setObjectName("ViewMediaDialog");
        ViewMediaDialog->resize(400, 453);
        ViewMediaDialog->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        verticalLayout = new QVBoxLayout(ViewMediaDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        mediaTitle = new QLabel(ViewMediaDialog);
        mediaTitle->setObjectName("mediaTitle");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mediaTitle->sizePolicy().hasHeightForWidth());
        mediaTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setStrikeOut(false);
        font.setKerning(true);
        mediaTitle->setFont(font);
        mediaTitle->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        mediaTitle->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        mediaTitle->setTextFormat(Qt::TextFormat::PlainText);
        mediaTitle->setIndent(0);

        horizontalLayout->addWidget(mediaTitle);


        verticalLayout->addLayout(horizontalLayout);

        infoContainer = new QVBoxLayout();
        infoContainer->setObjectName("infoContainer");
        scrollArea = new QScrollArea(ViewMediaDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        mediaInfo = new QWidget();
        mediaInfo->setObjectName("mediaInfo");
        mediaInfo->setGeometry(QRect(0, 0, 378, 358));
        infoLayout = new QVBoxLayout(mediaInfo);
        infoLayout->setObjectName("infoLayout");
        scrollArea->setWidget(mediaInfo);

        infoContainer->addWidget(scrollArea);


        verticalLayout->addLayout(infoContainer);

        actionButtonsLayout = new QHBoxLayout();
        actionButtonsLayout->setObjectName("actionButtonsLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionButtonsLayout->addItem(horizontalSpacer);

        editButton = new QPushButton(ViewMediaDialog);
        editButton->setObjectName("editButton");
        editButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: rgb(233, 238, 246);\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgb(233, 238, 246);\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid rgb(220, 220, 220);\n"
"    background-color: rgb(250, 250, 250);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid rgb(150, 150, 150);\n"
"    background-color: rgb(230, 230, 230);\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"}\n"
""));

        actionButtonsLayout->addWidget(editButton);

        deleteButton = new QPushButton(ViewMediaDialog);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: rgb(233, 238, 246);\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgb(233, 238, 246);\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid rgb(220, 220, 220);\n"
"    background-color: rgb(250, 250, 250);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid rgb(150, 150, 150);\n"
"    background-color: rgb(230, 230, 230);\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"}\n"
""));

        actionButtonsLayout->addWidget(deleteButton);

        exitButton = new QPushButton(ViewMediaDialog);
        exitButton->setObjectName("exitButton");
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: rgb(233, 238, 246);\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgb(233, 238, 246);\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid rgb(220, 220, 220);\n"
"    background-color: rgb(250, 250, 250);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid rgb(150, 150, 150);\n"
"    background-color: rgb(230, 230, 230);\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"}\n"
""));

        actionButtonsLayout->addWidget(exitButton);


        verticalLayout->addLayout(actionButtonsLayout);


        retranslateUi(ViewMediaDialog);

        QMetaObject::connectSlotsByName(ViewMediaDialog);
    } // setupUi

    void retranslateUi(QWidget *ViewMediaDialog)
    {
        ViewMediaDialog->setWindowTitle(QCoreApplication::translate("ViewMediaDialog", "Form", nullptr));
        mediaTitle->setText(QCoreApplication::translate("ViewMediaDialog", "media", nullptr));
        editButton->setText(QCoreApplication::translate("ViewMediaDialog", "Modifica", nullptr));
        deleteButton->setText(QCoreApplication::translate("ViewMediaDialog", "Elimina", nullptr));
        exitButton->setText(QCoreApplication::translate("ViewMediaDialog", "Annulla", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewMediaDialog: public Ui_ViewMediaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMEDIADIALOG_H
