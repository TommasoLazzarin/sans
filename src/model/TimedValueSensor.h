#ifndef MODEL_TIMED_VALUE_SENSOR_H
#define MODEL_TIMED_VALUE_SENSOR_H
#include "Sensor.h"
#include <QList>
namespace model
{
    class TimedValueSensor : public Sensor
    {
    private:
        QList<float> values_list;
        void addValue(const QDateTime &timestamp, const float value);

    public:
        TimedValueSensor(const QString &n, const QDateTime &date);
        TimedValueSensor(const QString &n,
                   const QDateTime &date,
                   const QList<QDateTime> &events,
                   const QList<float> &values);
        QList<float>::const_iterator getValuesConstIterator() const;
        void simulate();
    };
}
#endif