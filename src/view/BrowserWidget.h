#ifndef VIEW_BROWSER_WIDGET_H
#define VIEW_BROWSER_WIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include "model/db/Database.h"
#include "SensorsList.h"
namespace view
{
    class BrowserWidget : public QWidget
    {
        Q_OBJECT
    private:
        QLineEdit *searchBox;
        view::SensorsList *sensorsList;
        QVBoxLayout *layout;
        model::db::Database* db;

    public:
        explicit BrowserWidget(model::db::Database* database,QWidget *parent = 0);

    };
}
#endif