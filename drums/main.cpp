#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
//    QGuiApplication app(argc, argv);
    QApplication a(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) return -1;

    MainWindow w;
    w.show();

    return a.exec();
}
