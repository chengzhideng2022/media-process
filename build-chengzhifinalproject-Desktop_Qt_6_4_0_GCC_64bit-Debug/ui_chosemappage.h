/********************************************************************************
** Form generated from reading UI file 'chosemappage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOSEMAPPAGE_H
#define UI_CHOSEMAPPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choseMapPage
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *mapbutton1;
    QPushButton *mapbutton2;
    QPushButton *mapbutton3;
    QPushButton *mapbutton4;
    QPushButton *mapbutton5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *choseMapPage)
    {
        if (choseMapPage->objectName().isEmpty())
            choseMapPage->setObjectName("choseMapPage");
        choseMapPage->resize(800, 600);
        centralwidget = new QWidget(choseMapPage);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 60, 689, 378));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mapbutton1 = new QPushButton(widget);
        mapbutton1->setObjectName("mapbutton1");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mapbutton1->sizePolicy().hasHeightForWidth());
        mapbutton1->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/worldmap.png"), QSize(), QIcon::Normal, QIcon::Off);
        mapbutton1->setIcon(icon);
        mapbutton1->setIconSize(QSize(213, 179));

        gridLayout->addWidget(mapbutton1, 0, 0, 1, 1);

        mapbutton2 = new QPushButton(widget);
        mapbutton2->setObjectName("mapbutton2");
        sizePolicy.setHeightForWidth(mapbutton2->sizePolicy().hasHeightForWidth());
        mapbutton2->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/worldmap4.png"), QSize(), QIcon::Normal, QIcon::Off);
        mapbutton2->setIcon(icon1);
        mapbutton2->setIconSize(QSize(213, 179));

        gridLayout->addWidget(mapbutton2, 0, 1, 1, 1);

        mapbutton3 = new QPushButton(widget);
        mapbutton3->setObjectName("mapbutton3");
        sizePolicy.setHeightForWidth(mapbutton3->sizePolicy().hasHeightForWidth());
        mapbutton3->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/maze3.png"), QSize(), QIcon::Normal, QIcon::Off);
        mapbutton3->setIcon(icon2);
        mapbutton3->setIconSize(QSize(213, 179));

        gridLayout->addWidget(mapbutton3, 0, 2, 1, 1);

        mapbutton4 = new QPushButton(widget);
        mapbutton4->setObjectName("mapbutton4");
        sizePolicy.setHeightForWidth(mapbutton4->sizePolicy().hasHeightForWidth());
        mapbutton4->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/maze2.png"), QSize(), QIcon::Normal, QIcon::Off);
        mapbutton4->setIcon(icon3);
        mapbutton4->setIconSize(QSize(213, 179));

        gridLayout->addWidget(mapbutton4, 1, 0, 1, 1);

        mapbutton5 = new QPushButton(widget);
        mapbutton5->setObjectName("mapbutton5");
        sizePolicy.setHeightForWidth(mapbutton5->sizePolicy().hasHeightForWidth());
        mapbutton5->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/maze1.png"), QSize(), QIcon::Normal, QIcon::Off);
        mapbutton5->setIcon(icon4);
        mapbutton5->setIconSize(QSize(213, 179));

        gridLayout->addWidget(mapbutton5, 1, 1, 1, 1);

        choseMapPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(choseMapPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        choseMapPage->setMenuBar(menubar);
        statusbar = new QStatusBar(choseMapPage);
        statusbar->setObjectName("statusbar");
        choseMapPage->setStatusBar(statusbar);

        retranslateUi(choseMapPage);

        QMetaObject::connectSlotsByName(choseMapPage);
    } // setupUi

    void retranslateUi(QMainWindow *choseMapPage)
    {
        choseMapPage->setWindowTitle(QCoreApplication::translate("choseMapPage", "MainWindow", nullptr));
        mapbutton1->setText(QString());
        mapbutton2->setText(QString());
        mapbutton3->setText(QString());
        mapbutton4->setText(QString());
        mapbutton5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class choseMapPage: public Ui_choseMapPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOSEMAPPAGE_H
