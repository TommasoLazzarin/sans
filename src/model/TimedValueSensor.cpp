#include "model/TimedValueSensor.h"

model::TimedValueSensor::TimedValueSensor(const QString &n, const QDateTime &date): Sensor(n, date){
    values_list = QList<float>();
}
