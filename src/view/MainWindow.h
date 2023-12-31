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
#include "view/sensor/SensorViewer.h"
#include "view/NewSensorWidget.h"
#include "view/NoSensorAvailableWidget.h"
namespace view
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    private:
        fa::QtAwesome* awesome;
        model::db::Database* db;
        view::BrowserWidget* browser;
        view::sensor::SensorViewer* sensorViewer;
        QSplitter* splitter;
        view::NewSensorWidget* newSensorWidget;
        view::NoSensorAvailableWidget* noSensorAvailableWidget;
    public:
        explicit MainWindow(model::db::Database* database, fa::QtAwesome* icons,QWidget *parent = 0);
    public slots:
        void close();
        void createEmptySensor();
        //non posso passare direttamente l'indice int, devo passare dal database a prendere il Sensor
        void setSensorInViewer(int index);
    signals:
        //Nasconde il NoSensorAvailableWidget se presente, 
        //dice al browser di aggiornare la lista e alla view/sensor di selezionarlo.
        void newSensorAdded();
        void sensorSelectedChanged(model::Sensor* sensor);
    };
}
#endif