#ifndef MODEL_TIMED_VALUE_SENSOR_H
#define MODEL_TIMED_VALUE_SENSOR_H
#include "model/EventSensor.h"
#include <QList>
namespace model
{
    class TimedValueSensor : public EventSensor
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
        virtual ~TimedValueSensor()=default;
        QList<float>::const_iterator getValuesConstIterator() const;
        virtual void simulate();
    };
}
#endif