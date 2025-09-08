/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *window;
    QVBoxLayout *verticalLayout_3;
    QWidget *topBar;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *newMediaButton;
    QLineEdit *searchMediaField;
    QSpacerItem *horizontalSpacer;
    QFrame *contentFrame;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *dialogContainer;
    QWidget *createMediaPage;
    QWidget *viewMediaPage;
    QWidget *savePage;
    QWidget *loadPage;
    QScrollArea *scrollArea;
    QWidget *gridLayoutWidget;
    QGridLayout *mediaGrid;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        window = new QWidget(MainWindow);
        window->setObjectName("window");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(window->sizePolicy().hasHeightForWidth());
        window->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(window);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        topBar = new QWidget(window);
        topBar->setObjectName("topBar");
        topBar->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy1);
        topBar->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 178, 245);"));
        horizontalLayout_2 = new QHBoxLayout(topBar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        saveButton = new QPushButton(topBar);
        saveButton->setObjectName("saveButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);
        saveButton->setMinimumSize(QSize(24, 24));
        saveButton->setMaximumSize(QSize(24, 24));
        saveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(saveButton);

        loadButton = new QPushButton(topBar);
        loadButton->setObjectName("loadButton");
        sizePolicy2.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy2);
        loadButton->setMinimumSize(QSize(24, 24));
        loadButton->setMaximumSize(QSize(24, 24));
        loadButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(loadButton);

        newMediaButton = new QPushButton(topBar);
        newMediaButton->setObjectName("newMediaButton");
        newMediaButton->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(newMediaButton->sizePolicy().hasHeightForWidth());
        newMediaButton->setSizePolicy(sizePolicy3);
        newMediaButton->setMinimumSize(QSize(24, 24));
        newMediaButton->setMaximumSize(QSize(24, 24));
        newMediaButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(newMediaButton);

        searchMediaField = new QLineEdit(topBar);
        searchMediaField->setObjectName("searchMediaField");
        sizePolicy3.setHeightForWidth(searchMediaField->sizePolicy().hasHeightForWidth());
        searchMediaField->setSizePolicy(sizePolicy3);
        searchMediaField->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(searchMediaField);

        horizontalSpacer = new QSpacerItem(450, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout_3->addWidget(topBar);

        contentFrame = new QFrame(window);
        contentFrame->setObjectName("contentFrame");
        contentFrame->setFrameShape(QFrame::Shape::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Shadow::Raised);
        contentFrame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(contentFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dialogContainer = new QStackedWidget(contentFrame);
        dialogContainer->setObjectName("dialogContainer");
        createMediaPage = new QWidget();
        createMediaPage->setObjectName("createMediaPage");
        dialogContainer->addWidget(createMediaPage);
        viewMediaPage = new QWidget();
        viewMediaPage->setObjectName("viewMediaPage");
        dialogContainer->addWidget(viewMediaPage);
        savePage = new QWidget();
        savePage->setObjectName("savePage");
        dialogContainer->addWidget(savePage);
        loadPage = new QWidget();
        loadPage->setObjectName("loadPage");
        dialogContainer->addWidget(loadPage);

        horizontalLayout->addWidget(dialogContainer);

        scrollArea = new QScrollArea(contentFrame);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        gridLayoutWidget = new QWidget();
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 397, 554));
        sizePolicy4.setHeightForWidth(gridLayoutWidget->sizePolicy().hasHeightForWidth());
        gridLayoutWidget->setSizePolicy(sizePolicy4);
        gridLayoutWidget->setAutoFillBackground(true);
        gridLayoutWidget->setStyleSheet(QString::fromUtf8(""));
        mediaGrid = new QGridLayout(gridLayoutWidget);
        mediaGrid->setObjectName("mediaGrid");
        mediaGrid->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        mediaGrid->setContentsMargins(12, 12, 12, 12);
        scrollArea->setWidget(gridLayoutWidget);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout_3->addWidget(contentFrame);

        verticalLayout_3->setStretch(1, 756);
        MainWindow->setCentralWidget(window);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        newMediaButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(statustip)
        gridLayoutWidget->setStatusTip(QCoreApplication::translate("MainWindow", "TESTO", nullptr));
#endif // QT_CONFIG(statustip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
