#ifndef MODEL_DB_DATABASE_H
#define MODEL_DB_DATABASE_H
#include <QList>
#include "model/Sensor.h"
namespace model{
    namespace db{
        class Database
        {
        private:
            QList<Sensor*> sensors_db;
        
        public:
            Database();
            //Database(QList<Sensor*> db);
            void add(Sensor* s);
            void remove(const Sensor* s);
        };
    }
}

#endif