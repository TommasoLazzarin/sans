#ifndef VIEW_NEW_SENSOR_WIDGET_H
#define VIEW_NEW_SENSOR_WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QButtonGroup>
#include <QRadioButton>
#include <QList>
#include <QPushButton>
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
        QList<QRadioButton*> sensorTypesButtonsList;
        QPushButton* confirmButton;
        QPushButton* cancelButton;
        

    public:
        NewSensorWidget(fa::QtAwesome* fa, QWidget* parent = nullptr);
        QString getNewSensorName();
        int getNewSensorType();
        void clean();
        
    signals:
        void newSensorCreated();
    public slots:
        void createNewSensor();
    };
}
#endif