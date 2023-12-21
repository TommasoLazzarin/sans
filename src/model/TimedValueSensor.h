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
        void addValue(const QDateTime &timestamp, const float value);

    public:
        TimedValue(const QString &identifier, const QDateTime &created);
        TimedValue(const QString &identifier,
                   const QDateTime &created,
                   const QList<QDateTime> &events,
                   const QList<float> &values);
        QList<float>::const_iterator getValuesConstIterator() const;
    };
}
#endif