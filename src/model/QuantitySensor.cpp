#include "./QuantitySensor.h"
#include "QuantitySensor.h"

model::QuantitySensor::QuantitySensor(const QString& identifier, const QDateTime& created, const int max, const int val) : Sensor(identifier, created), value(val), max_value(max){};

int model::QuantitySensor::getValue() const
{
    return value;
}

void model::QuantitySensor::setValue(const int new_val)
{
    if (value>max_value) value=max_value;
    else if (value<0) value=0;
    else value=new_val;
}

int model::QuantitySensor::getMaxValue() const
{
    return max_value;
}

void model::QuantitySensor::simulate(){
    value=std::rand()%max_value;
}