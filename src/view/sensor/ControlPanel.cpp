#include "ControlPanel.h"


view::sensor::ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout(this);
    setLayout(layout);
    sensorName=new QLabel();
    layout->addWidget(sensorName);

    creationDate=new QLabel();
    layout->addWidget(creationDate);

    changeNameButton=new QPushButton("Change name");
    layout->addWidget(changeNameButton);

    deleteButton=new QPushButton("Delete");
    layout->addWidget(deleteButton);

    simulateButton=new QPushButton("Simulate");
    layout->addWidget(simulateButton);
    
    //connect
    connect(deleteButton, &QPushButton::clicked, this, &view::sensor::ControlPanel::deleteSensor);
    connect(changeNameButton, &QPushButton::clicked, this, &view::sensor::ControlPanel::renameSensor);
    connect(simulateButton, &QPushButton::clicked, this, &view::sensor::ControlPanel::simulateSensor);
}

void view::sensor::ControlPanel::sensorChanged(const QString& name, const QDateTime& creation) {
    sensorName->setText("Sensor name: "+name);
    creationDate->setText("Creation date: "+creation.toString());
}

