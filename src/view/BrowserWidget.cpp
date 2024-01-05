#include "BrowserWidget.h"

view::BrowserWidget::BrowserWidget(model::db::Database *database, fa::QtAwesome *fa,QWidget *parent) : db(database), awesome(fa), QWidget(parent) {
    layout = new QVBoxLayout(this);
    setLayout(layout);
    searchBox=new QLineEdit();
    searchBox->setPlaceholderText("Search sensor");
    layout->addWidget(searchBox);
    sensorsList=new view::SensorsList(db,awesome, this);
    layout->addWidget(sensorsList);
    connect(this, &BrowserWidget::updateSensorsList, this, &BrowserWidget::browserWidgetReloaded);
    connect(this, &BrowserWidget::browserWidgetReloaded, sensorsList, &view::SensorsList::updateSensorsList);
}

 void view::BrowserWidget::updateSensorsList() {
    emit browserWidgetReloaded();
}