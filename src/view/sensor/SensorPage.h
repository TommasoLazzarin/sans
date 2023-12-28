#ifndef VIEW_SENSORPAGE_H
#define VIEW_SENSORPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "view/sensor/ControlPanel.h"
#include "model/Sensor.h"
namespace view
{
    namespace sensor
    {
        // Pagina che contiene si occupa di mostrare un singolo sensore:
        // QVBoxLayout:
        //      ControlPanel: 
        //          - Nome : testo
        //          - Data creazione : QDateTime->testo
        //          - Modifica nome : Tasto che farà apparire un QLineEdit
        //          - Cancella
        //          - Simula
        //      SensorChart: da implementare col visitor pattern
        //          - QChartView: classe che permette di visualizzare un singolo grafico
        //          - QProgressBar: per implementare il QuantitySensor
        
        class SensorPage : public QWidget
        {
            Q_OBJECT

        private:
            QVBoxLayout *layout;
            view::sensor::ControlPanel *controlPanel;
            model::Sensor* sensor;
        public:
            explicit SensorPage(QWidget *parent = nullptr);
            void setSensor(model::Sensor* sensor);
        };

    }
}

#endif
