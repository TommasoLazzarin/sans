#ifndef MODEL_DB_DATABASE_H
#define MODEL_DB_DATABASE_H
#include <QList>
#include "model/Sensor.h"
#include "model/QuantitySensor.h"
#include "model/EventSensor.h"
#include "model/TimedValueSensor.h"
namespace model{
    namespace db{
        class Database
        {
        private:
            QList<Sensor*> sensors_db;
            void addEmptyQuantitySensor(const QString& name, const int max);
            void addEmptyEventSensor(const QString& name);
            void addEmptyTimedValueSensor(const QString& name);
        public:
            Database();
            //Database(QList<Sensor*> db);
            void add(Sensor* s);
            void remove(const Sensor* s);
            void addEmptySensor(const QString& name, const int type);
            model::Sensor* last();
        };
    }
}

#endif