#include "Database.h"

model::db::Database::Database() {}

void model::db::Database::add(Sensor *s){
    if(s!=nullptr) sensors_db.prepend(s);
}

void model::db::Database::remove(const Sensor *s){
    if(s!=nullptr) sensors_db.removeOne(s);
}
