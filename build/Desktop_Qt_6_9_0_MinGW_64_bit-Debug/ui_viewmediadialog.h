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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
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
    QVBoxLayout *infoLayout;
    QListWidget *listWidget;
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
        mediaTitle->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        mediaTitle->setTextFormat(Qt::TextFormat::PlainText);
        mediaTitle->setIndent(0);

        horizontalLayout->addWidget(mediaTitle);


        verticalLayout->addLayout(horizontalLayout);

        infoLayout = new QVBoxLayout();
        infoLayout->setObjectName("infoLayout");
        listWidget = new QListWidget(ViewMediaDialog);
        listWidget->setObjectName("listWidget");

        infoLayout->addWidget(listWidget);


        verticalLayout->addLayout(infoLayout);

        actionButtonsLayout = new QHBoxLayout();
        actionButtonsLayout->setObjectName("actionButtonsLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionButtonsLayout->addItem(horizontalSpacer);

        editButton = new QPushButton(ViewMediaDialog);
        editButton->setObjectName("editButton");

        actionButtonsLayout->addWidget(editButton);

        deleteButton = new QPushButton(ViewMediaDialog);
        deleteButton->setObjectName("deleteButton");

        actionButtonsLayout->addWidget(deleteButton);

        exitButton = new QPushButton(ViewMediaDialog);
        exitButton->setObjectName("exitButton");

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
