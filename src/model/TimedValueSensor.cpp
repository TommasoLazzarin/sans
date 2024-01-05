#include "model/TimedValueSensor.h"

model::TimedValueSensor::TimedValueSensor(const QString &n, const QDateTime &date): EventSensor(n, date){
    values_list = QList<float>();
}

void model::TimedValueSensor::addValue(const QDateTime &timestamp, const float value){
    addEvent(timestamp); //richiama il metodo di EventSensor
    values_list.append(value);
}

QList<float>::const_iterator model::TimedValueSensor::getValuesConstIterator() const{
    return values_list.constBegin();
}

void model::TimedValueSensor::simulate(){
    model::EventSensor::simulate();
    //TODO
}