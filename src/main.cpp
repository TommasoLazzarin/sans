#include <QApplication>
#include "view/MainWindow.h"
#include "lib/QtAwesome/QtAwesome.h"
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    fa::QtAwesome* awesome = new fa::QtAwesome();
    awesome->initFontAwesome();
    app.setWindowIcon(awesome->icon("fa-solit fa-gauge"));
    view::MainWindow window(awesome);
    window.resize(1024,576);
    window.show();
    return app.exec();
}
