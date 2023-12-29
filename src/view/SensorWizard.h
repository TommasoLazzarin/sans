#ifndef VIEW_SENSOR_WIZARD_H
#define VIEW_SENSOR_WIZARD_H
#include <QWizard>
#include <QWizardPage>
#include <QLineEdit>
#include <QLabel>
#include "model/db/Database.h"
namespace view{
    //Classe che si occupa di gestire la creazione di un nuovo sensore e di inserirlo nel database
    class SensorWizard : public QWizard
    {
        Q_OBJECT
    private:
        model::db::Database* db;
    };
}
#endif