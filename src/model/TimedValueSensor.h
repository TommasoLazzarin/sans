#ifndef MODEL_TIMED_VALUE_SENSOR_H
#define MODEL_TIMED_VALUE_SENSOR_H
#include "Sensor.h"
#include <QList>
namespace model
{
    class TimedValue : public Sensor
    {
    private:
        QList<float> values_list;
        void addValue(QDateTime timestamp, float value);
    public:
        TimedValue(QString identifier, QDateTime created);
        TimedValue(QString identifier, QDateTime created, QList<QDateTime> events, QList<float> values);
        QList<float>::const_iterator getValuesConstIterator();
    };
}
#endif