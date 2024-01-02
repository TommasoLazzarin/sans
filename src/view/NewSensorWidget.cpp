#include "view/NewSensorWidget.h"

view::NewSensorWidget::NewSensorWidget(fa::QtAwesome* fa, QWidget *parent):awesome(fa)
{
    setWindowTitle("Create new sensor");
    setMinimumWidth(300);
    setWindowIcon(awesome->icon(fa::fa_solid, fa::fa_arrow_up_right_from_square));
    layout = new QVBoxLayout(this);
    newSensorName = new QLineEdit(this);
    newSensorName->setPlaceholderText("Write here your new sensor name");
    layout->addWidget(newSensorName);
}