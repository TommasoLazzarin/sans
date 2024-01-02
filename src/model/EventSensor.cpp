#include "model/EventSensor.h"

model::EventSensor::EventSensor(const QString& n, const QDateTime& date): Sensor(n, date){
    event_list = QList<QDateTime>();
}