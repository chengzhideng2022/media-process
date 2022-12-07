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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *HPBar;
    QProgressBar *EnergyBar_2;
    QLabel *label;
    QLabel *label_2;
    QGraphicsView *gameView;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_9;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *easyButton_6;
    QPushButton *mediumButton_7;
    QPushButton *hardButton_8;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pathfinderButton_5;
    QPushButton *graphicsButton_2;
    QPushButton *autoplayButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1128, 645);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        HPBar = new QProgressBar(centralwidget);
        HPBar->setObjectName("HPBar");
        HPBar->setGeometry(QRect(50, 0, 361, 23));
        HPBar->setValue(24);
        EnergyBar_2 = new QProgressBar(centralwidget);
        EnergyBar_2->setObjectName("EnergyBar_2");
        EnergyBar_2->setGeometry(QRect(50, 30, 361, 23));
        EnergyBar_2->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 21, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 30, 54, 17));
        gameView = new QGraphicsView(centralwidget);
        gameView->setObjectName("gameView");
        gameView->setGeometry(QRect(10, 70, 1091, 511));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(750, 0, 54, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(770, 40, 54, 17));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(730, 20, 80, 25));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(440, 10, 281, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        easyButton_6 = new QPushButton(layoutWidget);
        easyButton_6->setObjectName("easyButton_6");

        horizontalLayout->addWidget(easyButton_6);

        mediumButton_7 = new QPushButton(layoutWidget);
        mediumButton_7->setObjectName("mediumButton_7");

        horizontalLayout->addWidget(mediumButton_7);

        hardButton_8 = new QPushButton(layoutWidget);
        hardButton_8->setObjectName("hardButton_8");

        horizontalLayout->addWidget(hardButton_8);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(820, -10, 281, 93));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 2, 1, 1, 1);

        pathfinderButton_5 = new QPushButton(layoutWidget1);
        pathfinderButton_5->setObjectName("pathfinderButton_5");

        gridLayout->addWidget(pathfinderButton_5, 2, 0, 1, 1);

        graphicsButton_2 = new QPushButton(layoutWidget1);
        graphicsButton_2->setObjectName("graphicsButton_2");

        gridLayout->addWidget(graphicsButton_2, 0, 1, 1, 1);

        autoplayButton_3 = new QPushButton(layoutWidget1);
        autoplayButton_3->setObjectName("autoplayButton_3");

        gridLayout->addWidget(autoplayButton_3, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1128, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Combat Hero Adventures", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "HP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Energy", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "views", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "func", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        easyButton_6->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        mediumButton_7->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        hardButton_8->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "autoplay", nullptr));
        pathfinderButton_5->setText(QCoreApplication::translate("MainWindow", "pathfinder", nullptr));
        graphicsButton_2->setText(QCoreApplication::translate("MainWindow", "graphics", nullptr));
        autoplayButton_3->setText(QCoreApplication::translate("MainWindow", "text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
