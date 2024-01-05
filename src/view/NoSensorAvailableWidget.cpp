#include "view/NoSensorAvailableWidget.h"

view::NoSensorAvailableWidget::NoSensorAvailableWidget(QWidget *parent)
{
    layout = new QVBoxLayout(this);
    noSensorAvailableLabel = new QLabel(this);
    noSensorAvailableLabel->setTextFormat(Qt::RichText);
    noSensorAvailableLabel->setText("<h1>There are no sensors available!</h1><br>You can: <ul><li>Create a new sensor</li><li>Import a single sensor</li><li>Import multiple sensors</li></ul>");
    layout->addStretch();
    layout->addWidget(noSensorAvailableLabel);
    layout->addStretch();
    setLayout(layout);
}