#ifndef VIEW_SENSORS_LIST_H
#define VIEW_SENSORS_LIST_H
#include <QListWidget>
#include <QLabel>
#include "model/db/Database.h"
#include "model/Sensor.h"
#include "lib/QtAwesome/QtAwesome.h"

namespace view{
    class SensorsList:public QListWidget{
        Q_OBJECT
        private:
            fa::QtAwesome* awesome;
        public:
            explicit SensorsList(model::db::Database* database, fa::QtAwesome* fa, QWidget* parent = 0);
            model::db::Database* db;
        public slots:
            void updateSensorsList();
    };
}
#endif