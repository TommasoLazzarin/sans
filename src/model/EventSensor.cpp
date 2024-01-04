#include "model/EventSensor.h"

model::EventSensor::EventSensor(const QString& n, const QDateTime& date): Sensor(n, date){
    event_list = QList<QDateTime>();
}

void model::EventSensor::addEvent(QDateTime event){
    event_list.append(event);
}

void model::EventSensor::simulate(){
    //TODO
}