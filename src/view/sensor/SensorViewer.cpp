#include "SensorViewer.h"

view::sensor::SensorViewer::SensorViewer(QWidget *parent)
{
    layout = new QVBoxLayout(this);
    setLayout(layout);
    controlPanel=new view::sensor::ControlPanel(this);
    layout->addWidget(controlPanel);
    connect(this, &view::sensor::SensorViewer::sensorChanged, controlPanel, &view::sensor::ControlPanel::sensorChanged);
}

void view::sensor::SensorViewer::sensorChanged(model::Sensor* sensor)
{
    this->sensor=sensor;
    emit controlPanel->sensorChanged(sensor->getName(), sensor->getCreatedAt());
}

