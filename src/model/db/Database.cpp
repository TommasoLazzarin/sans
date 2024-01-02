#include "Database.h"

model::db::Database::Database() {}

void model::db::Database::add(Sensor *s)
{
    if (s != nullptr)
        sensors_db.prepend(s);
}

void model::db::Database::remove(const Sensor *s)
{
    if (s != nullptr)
        sensors_db.removeOne(s);
}

void model::db::Database::addEmptyQuantitySensor(const QString &name, const int max)
{
    if (name != nullptr)
        sensors_db.prepend(new QuantitySensor(name, QDateTime::currentDateTime(), max));
}

void model::db::Database::addEmptyEventSensor(const QString &name)
{
    //if (name != nullptr)
        //sensors_db.prepend(new EventSensor(name, QDateTime::currentDateTime()));
}

void model::db::Database::addEmptyTimedValueSensor(const QString &name)
{
    //if (name != nullptr)
        //sensors_db.prepend(new TimedValueSensor(name, QDateTime::currentDateTime()));
}
