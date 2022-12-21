#include "mainwindow.h"
#include "chosemappage.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "chengzhifinalproject_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    choseMapPage c;
    c.show();
  //  MainWindow w;
   /*
    connect(c.getui()->mapbutton1,&QPushButton::clicked,[=](){
        c.hide();
        w.show();
    });
    */

    //MainWindow w;
   // w.show();
    return a.exec();
}
