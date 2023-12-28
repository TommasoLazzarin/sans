#include <QApplication>
#include "view/MainWindow.h"
#include "lib/QtAwesome/QtAwesome.h"
#include <iostream>
#include <QDebug>
#include "model/db/Database.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    fa::QtAwesome* awesome = new fa::QtAwesome();
    awesome->initFontAwesome();
    app.setWindowIcon(awesome->icon("fa-solid fa-gauge"));
    model::db::Database* db = new model::db::Database();
    view::MainWindow window(db, awesome);
    window.resize(1024,576);
    window.show();
    return app.exec();
}
