#ifndef MODEL_EVENT_SENSOR_H
#define MODEL_EVENT_SENSOR_H
#include "Sensor.h"
#include <QList>
namespace model
{
    class EventSensor : public Sensor
    {
    private:
        QList<QDateTime> event_list;
        unsigned __int8 sim_period;
        void addEvent(QDateTime event);

    public:
        EventSensor(const QString &identifier, const QDateTime &created);
        EventSensor(const QString &identifier,
                    const QDateTime &created,
                    const QList<QDateTime> &events);
        QList<QDateTime>::const_iterator getEventsConstIterator() const;
    };
}
#endif