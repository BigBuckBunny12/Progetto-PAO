/********************************************************************************
** Form generated from reading UI file 'editmediadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMEDIADIALOG_H
#define UI_EDITMEDIADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditMediaDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *mediaTitle;
    QFormLayout *formLayout;
    QHBoxLayout *actionButtonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *applyButton;

    void setupUi(QWidget *EditMediaDialog)
    {
        if (EditMediaDialog->objectName().isEmpty())
            EditMediaDialog->setObjectName("EditMediaDialog");
        EditMediaDialog->resize(371, 534);
        verticalLayout = new QVBoxLayout(EditMediaDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        mediaTitle = new QLabel(EditMediaDialog);
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

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");

        verticalLayout->addLayout(formLayout);

        actionButtonsLayout = new QHBoxLayout();
        actionButtonsLayout->setObjectName("actionButtonsLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionButtonsLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(EditMediaDialog);
        cancelButton->setObjectName("cancelButton");

        actionButtonsLayout->addWidget(cancelButton);

        applyButton = new QPushButton(EditMediaDialog);
        applyButton->setObjectName("applyButton");

        actionButtonsLayout->addWidget(applyButton);


        verticalLayout->addLayout(actionButtonsLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 91);

        retranslateUi(EditMediaDialog);

        QMetaObject::connectSlotsByName(EditMediaDialog);
    } // setupUi

    void retranslateUi(QWidget *EditMediaDialog)
    {
        EditMediaDialog->setWindowTitle(QCoreApplication::translate("EditMediaDialog", "Form", nullptr));
        mediaTitle->setText(QCoreApplication::translate("EditMediaDialog", "media", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditMediaDialog", "Annulla", nullptr));
        applyButton->setText(QCoreApplication::translate("EditMediaDialog", "Applica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditMediaDialog: public Ui_EditMediaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMEDIADIALOG_H
