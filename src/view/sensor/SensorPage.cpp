#include "SensorPage.h"

view::sensor::SensorPage::SensorPage(QWidget *parent)
{
    layout = new QVBoxLayout(this);
    setLayout(layout);
    controlPanel=new view::sensor::ControlPanel("Example", QDateTime::currentDateTime());
    layout->addWidget(controlPanel);
}

