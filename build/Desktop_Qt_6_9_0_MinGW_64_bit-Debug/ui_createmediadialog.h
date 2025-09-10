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
        CreateMediaDialog->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
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
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        dialogTitle->setFont(font);
        dialogTitle->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        dialogTitle->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        dialogTitle->setTextFormat(Qt::TextFormat::PlainText);
        dialogTitle->setIndent(0);

        horizontalLayout->addWidget(dialogTitle);


        verticalLayout->addLayout(horizontalLayout);

        mediaDropdown = new QComboBox(CreateMediaDialog);
        mediaDropdown->setObjectName("mediaDropdown");
        mediaDropdown->setStyleSheet(QString::fromUtf8("/* QComboBox base */\n"
"QComboBox {\n"
"    color: rgb(0, 0, 0);\n"
"    background-color: transparent;\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgb(233, 238, 246);\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"/* Hover */\n"
"QComboBox:hover {\n"
"    border: 2px solid rgb(220, 220, 220);\n"
"    background-color: rgb(250, 250, 250);\n"
"}\n"
"\n"
"/* Premuto (quando apro il menu) */\n"
"QComboBox:pressed,\n"
"QComboBox::drop-down:pressed {\n"
"    border: 2px solid rgb(150, 150, 150);\n"
"    background-color: transparent;\n"
"    border-bottom-left-radius: 0px;\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox:on,\n"
"QComboBox:!editable:on {\n"
"    background-color: transparent;\n"
"	border-bottom-left-radius: 0px;\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"/* Focus */\n"
"QComboBox:focus {\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Drop-down (freccia) */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    wid"
                        "th: 20px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resources/img/dropdown_arrow.png); /* tua icona */\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin-right: 12px;\n"
"}\n"
"\n"
"/* Popup del QComboBox */\n"
"QComboBox QAbstractItemView,\n"
"QComboBox QListView {\n"
"    border: 1px solid rgb(220, 220, 220);\n"
"    border-bottom-left-radius: 5px;\n"
"    border-bottom-right-radius: 5px;\n"
"    background-color: rgb(255, 255, 255); /* stesso colore del parent */\n"
"    outline: 0;\n"
"}\n"
"\n"
"/* Singoli item nel menu */\n"
"QComboBox QAbstractItemView::item,\n"
"QComboBox QListView::item {\n"
"    padding: 6px 10px;\n"
"}\n"
"\n"
"/* Item selezionato (hover o selezione) */\n"
"QComboBox QAbstractItemView::item:selected,\n"
"QComboBox QListView::item:selected {\n"
"    background: rgb(233, 238, 246);\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
""));
        mediaDropdown->setMaxVisibleItems(10);

        verticalLayout->addWidget(mediaDropdown);

        mediaInfoLayout = new QFormLayout();
        mediaInfoLayout->setObjectName("mediaInfoLayout");
        label_2 = new QLabel(CreateMediaDialog);
        label_2->setObjectName("label_2");

        mediaInfoLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        lineEdit = new QLineEdit(CreateMediaDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius: 5px"));

        mediaInfoLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);


        verticalLayout->addLayout(mediaInfoLayout);

        actionButtonsLayout = new QHBoxLayout();
        actionButtonsLayout->setObjectName("actionButtonsLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionButtonsLayout->addItem(horizontalSpacer);

        CancelButton = new QPushButton(CreateMediaDialog);
        CancelButton->setObjectName("CancelButton");
        CancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        actionButtonsLayout->addWidget(CancelButton);

        ConfirmButton = new QPushButton(CreateMediaDialog);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
