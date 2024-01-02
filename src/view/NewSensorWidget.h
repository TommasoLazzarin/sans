#ifndef VIEW_NEW_SENSOR_WIDGET_H
#define VIEW_NEW_SENSOR_WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QButtonGroup>
#include <QRadioButton>
#include <QList>
#include <QGroupBox>
#include "lib/QtAwesome/QtAwesome.h"
namespace view
{
    class NewSensorWidget : public QWidget
    {
        Q_OBJECT
    private:
    fa::QtAwesome* awesome;
        QVBoxLayout* layout;
        QLineEdit* newSensorName;
        QButtonGroup* sensorTypeGroup;
        QList<QRadioButton*> sensorTypeButtonsList;

    public:
        NewSensorWidget(fa::QtAwesome* fa, QWidget* parent = nullptr);
        QString getNewSensorName();
        QString getNewSensorType();
    signals:
        //void newSensorCreated();
    public slots:
        //void createNewSensor();
        //void clear(); //rimuove il testo e resetta i radio button
    };
}
#endif