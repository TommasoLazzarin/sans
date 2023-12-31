#include "Sensor.h"
model::Sensor::Sensor(const QString& n, const QDateTime& date) : name(n), created_at(date) {}

QDateTime model::Sensor::getCreatedAt() const { return created_at; }

QString model::Sensor::getCreatedAtString() const
{
    return created_at.toString("dd/MM/yyyy hh:mm");
}

model::Sensor::~Sensor(){}

QString model::Sensor::getName() const { return name; }

void model::Sensor::setName(const QString& new_name) { name=new_name; }