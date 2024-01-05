#include "view/SensorsList.h"

view::SensorsList::SensorsList(model::db::Database *database, fa::QtAwesome *fa, QWidget *parent) : db(database), awesome(fa), QListWidget(parent)
{
}

void view::SensorsList::updateSensorsList()
{
    // prende l'iteratore dal db e inserisce i QListWidgetItem nella lista
    QListWidgetItem *item;
    model::Sensor* s = *(db->begin());
    item = new QListWidgetItem(s->getName() + " | " + s->getCreatedAtString(), this);
    item->setIcon(awesome->icon(fa::fa_solid, fa::fa_thermometer)); //da fare con il visitor
    addItem(item);
    setCurrentRow(0);//seleziona in automatico il primo elemento
}
