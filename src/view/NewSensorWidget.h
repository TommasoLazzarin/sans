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
#include <QMessageBox>
#include "lib/QtAwesome/QtAwesome.h"
namespace view
{
    class NewSensorWidget : public QWidget
    {
        Q_OBJECT
    private:
        fa::QtAwesome *awesome;
        QMessageBox *error;
        QVBoxLayout *layout;
        QLineEdit *newSensorName;
        QButtonGroup *sensorTypeGroup;
        QList<QRadioButton *> sensorTypesButtonsList;
        QPushButton *confirmButton;
        QPushButton *cancelButton;
        void clean();

    public:
        NewSensorWidget(fa::QtAwesome *fa, QWidget *parent = nullptr);
        QString getNewSensorName();
        int getNewSensorType();

    signals:
        void newSensorDataReady(); // avvisa (la mainwindow) che è stato creato un nuovo sensore
    public slots:
        void createNewSensor(); // svuota i campi e mostra la finestra se non è già visibile (altrimenti non fa nulla)
    private slots:
        void checkSensorData(); // controlla che i dati inseriti siano validi (stringa>0, tipo selezionato)
    };
}
#endif