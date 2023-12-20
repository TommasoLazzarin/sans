#ifndef MODEL_QUANTITY_SENSOR_H
#define MODEL_QUANTITY_SENSOR_H
#include "Sensor.h"
namespace model
{
    class QuantitySensor : public Sensor
    {
    private:
        int value;
        const int max_value;

    public:
        QuantitySensor(QString identifier, QDateTime created, int max);
        int getValue() const;
        void setValue(int);
        int getMaxValue() const;
    };
}

#endif