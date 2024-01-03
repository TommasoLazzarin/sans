#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QHBoxLayout>
#include <QSplitter>
#include "lib/QtAwesome/QtAwesome.h"
#include "model/QuantitySensor.h"
#include "model/db/Database.h"
#include "view/BrowserWidget.h"
#include "view/sensor/SensorPage.h"
#include "view/NewSensorWidget.h"
namespace view
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    private:
        fa::QtAwesome* awesome;
        model::db::Database* db;
        view::BrowserWidget* browser;
        view::sensor::SensorPage* sensorPage;
        QSplitter* splitter;
        view::NewSensorWidget* newSensorWidget;
    public:
        explicit MainWindow(model::db::Database* database, fa::QtAwesome* icons,QWidget *parent = 0);
    public slots:
        void close();
        void createNewSensor();
    signals:
        void newSensorAdded(model::Sensor*);//per il refresh
    };
}
#endif