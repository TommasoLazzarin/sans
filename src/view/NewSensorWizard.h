#ifndef VIEW_NEW_SENSOR_WIZARD_H
#define VIEW_NEW_SENSOR_WIZARD_H
#include <QWizard>
#include "model/Sensor.h"
#include "model/EventSensor.h"
#include "model/QuantitySensor.h"
#include "model/TimedValueSensor.h"
namespace view
{
    class NewSensorWizard:public QWizard{
        private:
            model::Sensor* generatedSensor;
        public:
            model::Sensor* getGeneratedSensor();
    };
}

#endif