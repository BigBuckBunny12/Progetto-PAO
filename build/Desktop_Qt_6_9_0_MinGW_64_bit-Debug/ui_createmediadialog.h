/********************************************************************************
** Form generated from reading UI file 'createmediadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEMEDIADIALOG_H
#define UI_CREATEMEDIADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateMediaDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *dialogTitle;
    QComboBox *mediaDropdown;
    QFormLayout *mediaInfoLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *actionButtonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelButton;
    QPushButton *ConfirmButton;

    void setupUi(QWidget *CreateMediaDialog)
    {
        if (CreateMediaDialog->objectName().isEmpty())
            CreateMediaDialog->setObjectName("CreateMediaDialog");
        CreateMediaDialog->resize(376, 579);
        CreateMediaDialog->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout = new QVBoxLayout(CreateMediaDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        dialogTitle = new QLabel(CreateMediaDialog);
        dialogTitle->setObjectName("dialogTitle");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dialogTitle->sizePolicy().hasHeightForWidth());
        dialogTitle->setSizePolicy(sizePolicy);
        dialogTitle->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        dialogTitle->setTextFormat(Qt::TextFormat::PlainText);
        dialogTitle->setIndent(0);

        horizontalLayout->addWidget(dialogTitle);


        verticalLayout->addLayout(horizontalLayout);

        mediaDropdown = new QComboBox(CreateMediaDialog);
        mediaDropdown->setObjectName("mediaDropdown");
        mediaDropdown->setMaxVisibleItems(10);

        verticalLayout->addWidget(mediaDropdown);

        mediaInfoLayout = new QFormLayout();
        mediaInfoLayout->setObjectName("mediaInfoLayout");
        label_2 = new QLabel(CreateMediaDialog);
        label_2->setObjectName("label_2");

        mediaInfoLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        lineEdit = new QLineEdit(CreateMediaDialog);
        lineEdit->setObjectName("lineEdit");

        mediaInfoLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);


        verticalLayout->addLayout(mediaInfoLayout);

        actionButtonsLayout = new QHBoxLayout();
        actionButtonsLayout->setObjectName("actionButtonsLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionButtonsLayout->addItem(horizontalSpacer);

        CancelButton = new QPushButton(CreateMediaDialog);
        CancelButton->setObjectName("CancelButton");

        actionButtonsLayout->addWidget(CancelButton);

        ConfirmButton = new QPushButton(CreateMediaDialog);
        ConfirmButton->setObjectName("ConfirmButton");

        actionButtonsLayout->addWidget(ConfirmButton);


        verticalLayout->addLayout(actionButtonsLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 15);
        verticalLayout->setStretch(3, 2);

        retranslateUi(CreateMediaDialog);

        QMetaObject::connectSlotsByName(CreateMediaDialog);
    } // setupUi

    void retranslateUi(QWidget *CreateMediaDialog)
    {
        CreateMediaDialog->setWindowTitle(QCoreApplication::translate("CreateMediaDialog", "Form", nullptr));
        dialogTitle->setText(QCoreApplication::translate("CreateMediaDialog", "Crea un nuovo media", nullptr));
        mediaDropdown->setPlaceholderText(QCoreApplication::translate("CreateMediaDialog", "Seleziona la tipologia di media da creare", nullptr));
        label_2->setText(QCoreApplication::translate("CreateMediaDialog", "Numero di pagine: ", nullptr));
        CancelButton->setText(QCoreApplication::translate("CreateMediaDialog", "Annulla", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("CreateMediaDialog", "Crea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateMediaDialog: public Ui_CreateMediaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMEDIADIALOG_H
