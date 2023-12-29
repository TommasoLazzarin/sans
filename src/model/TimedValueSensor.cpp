#include "TimedValueSensor.h"

model::TimedValue::TimedValue(const QString &n, const QDateTime &date): Sensor(n, date){
    values_list = QList<float>();
}
