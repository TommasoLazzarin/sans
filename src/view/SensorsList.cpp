#include "view/SensorsList.h"

view::SensorsList::SensorsList(model::db::Database *database, fa::QtAwesome *fa, QWidget *parent) : db(database), awesome(fa), QListWidget(parent)
{
}

void view::SensorsList::updateSensorsList()
{
    // prende l'iteratore dal db e inserisce i QListWidgetItem nella lista
    QListWidgetItem *item;
    item=new QListWidgetItem("Ciao", this);
    // item = new QListWidgetItem(db->last()->getName() + " | " + db->last()->getCreatedAtString(), this);
    // item->setIcon(awesome->icon(fa::fa_solid, fa::fa_thermometer));
    addItem(item);
}
