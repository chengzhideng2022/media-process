/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *gameview;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *easybutton;
    QPushButton *mediumbutton;
    QPushButton *hardButton_3;
    QProgressBar *HPBar;
    QProgressBar *energyBar_2;
    QLabel *HPlabel;
    QLabel *Energylabel;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1322, 668);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gameview = new QGraphicsView(centralwidget);
        gameview->setObjectName("gameview");
        gameview->setGeometry(QRect(10, 70, 1231, 591));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(7);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gameview->sizePolicy().hasHeightForWidth());
        gameview->setSizePolicy(sizePolicy1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1250, 110, 82, 89));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        easybutton = new QPushButton(layoutWidget);
        easybutton->setObjectName("easybutton");

        verticalLayout->addWidget(easybutton);

        mediumbutton = new QPushButton(layoutWidget);
        mediumbutton->setObjectName("mediumbutton");

        verticalLayout->addWidget(mediumbutton);

        hardButton_3 = new QPushButton(layoutWidget);
        hardButton_3->setObjectName("hardButton_3");

        verticalLayout->addWidget(hardButton_3);

        HPBar = new QProgressBar(centralwidget);
        HPBar->setObjectName("HPBar");
        HPBar->setGeometry(QRect(70, 30, 1001, 23));
        HPBar->setValue(24);
        energyBar_2 = new QProgressBar(centralwidget);
        energyBar_2->setObjectName("energyBar_2");
        energyBar_2->setGeometry(QRect(70, 0, 1001, 23));
        energyBar_2->setValue(24);
        HPlabel = new QLabel(centralwidget);
        HPlabel->setObjectName("HPlabel");
        HPlabel->setGeometry(QRect(10, 0, 41, 17));
        QFont font;
        font.setPointSize(14);
        HPlabel->setFont(font);
        Energylabel = new QLabel(centralwidget);
        Energylabel->setObjectName("Energylabel");
        Energylabel->setGeometry(QRect(10, 30, 54, 17));
        Energylabel->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1322, 23));
        menubar->setDefaultUp(true);
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        easybutton->setText(QCoreApplication::translate("MainWindow", "easy", nullptr));
        mediumbutton->setText(QCoreApplication::translate("MainWindow", "medium", nullptr));
        hardButton_3->setText(QCoreApplication::translate("MainWindow", "hard", nullptr));
        HPlabel->setText(QCoreApplication::translate("MainWindow", "HP    :", nullptr));
        Energylabel->setText(QCoreApplication::translate("MainWindow", "Energy:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
