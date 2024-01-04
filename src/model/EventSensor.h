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
        //unsigned __int8 sim_period;//??
        
    protected:
    void addEvent(QDateTime event);
    public:
        EventSensor(const QString &n, const QDateTime &date);
        EventSensor(const QString &n,
                    const QDateTime &date,
                    const QList<QDateTime> &events);
        virtual ~EventSensor();
        QList<QDateTime>::const_iterator getEventsConstIterator() const;
        virtual void simulate();
    };
}
#endif