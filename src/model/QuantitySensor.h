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
        QuantitySensor(const QString& identifier, const QDateTime& created, const int max);
        int getValue() const;
        void setValue(const int new_val);
        int getMaxValue() const;
    };
}

#endif