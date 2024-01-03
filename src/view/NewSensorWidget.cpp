#include "view/NewSensorWidget.h"
#include "NewSensorWidget.h"

view::NewSensorWidget::NewSensorWidget(fa::QtAwesome *fa, QWidget *parent) : awesome(fa)
{
    setWindowTitle("Create new sensor");
    setFixedSize(300, 170);

    setWindowIcon(awesome->icon(fa::fa_solid, fa::fa_arrow_up_right_from_square));
    layout = new QVBoxLayout(this);
    setLayout(layout);
    QLabel *title = new QLabel("Create new sensor", this);
    title->setAlignment(Qt::AlignCenter);
    layout->addWidget(title);
    newSensorName = new QLineEdit(this);
    newSensorName->setPlaceholderText("Name");
    layout->addWidget(newSensorName);
    sensorTypesButtonsList = QList<QRadioButton *>();
    sensorTypesButtonsList.append(new QRadioButton("Value sensor (0-100 gauge)", this));
    sensorTypesButtonsList.append(new QRadioButton("Event sensor (bar chart)", this));
    sensorTypesButtonsList.append(new QRadioButton("Timed value sensor (line chart)", this));
    sensorTypesButtonsList[0]->setIcon(awesome->icon(fa::fa_solid, fa::fa_gauge));
    sensorTypesButtonsList[1]->setIcon(awesome->icon(fa::fa_solid, fa::fa_chart_simple));
    sensorTypesButtonsList[2]->setIcon(awesome->icon(fa::fa_solid, fa::fa_chart_line));
    QVBoxLayout *radioButtonsLayout = new QVBoxLayout(this);
    sensorTypeGroup = new QButtonGroup(this);
    for (int i = 0; i < sensorTypesButtonsList.size(); i++)
    {
        sensorTypeGroup->addButton(sensorTypesButtonsList[i]);
        radioButtonsLayout->addWidget(sensorTypesButtonsList[i]);
    }
    layout->addLayout(radioButtonsLayout);
    QHBoxLayout *buttonsLayout = new QHBoxLayout(this);
    confirmButton = new QPushButton("Create", this);
    confirmButton->setIcon(awesome->icon(fa::fa_solid, fa::fa_check));
    buttonsLayout->addWidget(confirmButton);
    cancelButton = new QPushButton("Cancel", this);
    cancelButton->setIcon(awesome->icon(fa::fa_solid, fa::fa_times));
    buttonsLayout->addWidget(cancelButton);
    layout->addLayout(buttonsLayout);
    connect(cancelButton, &QPushButton::clicked, this, &NewSensorWidget::hide);
    connect(confirmButton, &QPushButton::clicked, this, &NewSensorWidget::newSensorCreated);
}

void view::NewSensorWidget::clean()
{
    newSensorName->setText("");
    sensorTypeGroup->setExclusive(false); // fix
    for (int i = 0; i < sensorTypesButtonsList.size(); i++)
    {
        sensorTypesButtonsList[i]->setChecked(false);
    }
    sensorTypeGroup->setExclusive(true);
}

void view::NewSensorWidget::createNewSensor()
{
    if (isHidden())
    {
        clean();
        show();
    }
}

QString view::NewSensorWidget::getNewSensorName()
{
    return newSensorName->text();
}

int view::NewSensorWidget::getNewSensorType()
{
    return sensorTypeGroup->checkedId();
}