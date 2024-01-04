#include "SensorViewer.h"

view::sensor::SensorViewer::SensorViewer(QWidget *parent)
{
    layout = new QVBoxLayout(this);
    setLayout(layout);
    controlPanel=new view::sensor::ControlPanel("Example", QDateTime::currentDateTime());
    layout->addWidget(controlPanel);
}

