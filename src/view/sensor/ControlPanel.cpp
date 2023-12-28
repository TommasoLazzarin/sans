#include "ControlPanel.h"


view::sensor::ControlPanel::ControlPanel(const QString& name, const QDateTime& creation, QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout(this);
    setLayout(layout);
    sensorName=new QLabel("Sensor name: "+name);
    layout->addWidget(sensorName);

    creationDate=new QLabel("Creation date: "+creation.toString());
    layout->addWidget(creationDate);

    changeNameButton=new QPushButton("Change name");
    layout->addWidget(changeNameButton);

    deleteButton=new QPushButton("Delete");
    layout->addWidget(deleteButton);

    simulateButton=new QPushButton("Simulate");
    layout->addWidget(simulateButton);
}

