#include <QApplication>
#include "view/MainWindow.h"
#include "model/QuantitySensor.h"
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    view::MainWindow window;
    window.resize(1024,576);
    window.show();
    return app.exec();
}
