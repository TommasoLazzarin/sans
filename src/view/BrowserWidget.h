#ifndef VIEW_BROWSER_WIDGET_H
#define VIEW_BROWSER_WIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "model/db/Database.h"
#include "model/Sensor.h"
#include "view/SensorsList.h"
#include "lib/QtAwesome/QtAwesome.h"
namespace view
{
    class BrowserWidget : public QWidget
    {
        Q_OBJECT
    private:
        QLineEdit *searchBox;
        view::SensorsList *sensorsList;
        QVBoxLayout *layout;
        model::db::Database *db;
        fa::QtAwesome* awesome;
    public:
        explicit BrowserWidget(model::db::Database *database, fa::QtAwesome *fa,QWidget *parent = 0);

    public slots:
        void updateSensorsList(); // segnale che arriva dalla MainWindow
    signals:
    //     // void sensorSelected(model::Sensor*);
        void browserWidgetReloaded(); // segnale da passare alla sensorList
    };
}
#endif