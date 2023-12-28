#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QHBoxLayout>
#include "lib/QtAwesome/QtAwesome.h"
#include "model/QuantitySensor.h"
#include "model/db/Database.h"
#include "view/BrowserWidget.h"
namespace view
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    private:
        fa::QtAwesome* awesome;
        model::db::Database* db;
        view::BrowserWidget* browser;
        //QHBoxLayout* layout;
    public:
        explicit MainWindow(model::db::Database* database, fa::QtAwesome* icons,QWidget *parent = 0);
    public slots:
        void close();
    };
}
#endif