#include "BrowserWidget.h"

view::BrowserWidget::BrowserWidget(model::db::Database* database, QWidget *parent) : db(database), QWidget(parent) {
    layout = new QVBoxLayout(this);
    setLayout(layout);
    searchBox=new QLineEdit();
    searchBox->setPlaceholderText("Search sensor");
    layout->addWidget(searchBox);
    sensorsList=new view::SensorsList();
    layout->addWidget(sensorsList);
}
