#ifndef VIEW_SENSOR_CONTROLPANEL_H
#define VIEW_SENSOR_CONTROLPANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QDateTime>

namespace view
{
    namespace sensor
    {
        class ControlPanel : public QWidget
        {
            Q_OBJECT
        private:
            QLabel *sensorName;
            QLabel *creationDate;
            QPushButton *changeNameButton;
            QPushButton *deleteButton;
            QPushButton *simulateButton;
            QHBoxLayout *layout;

        public:
            ControlPanel(const QString& name, const QDateTime& creation, QWidget *parent = nullptr);
        };
    }
}

#endif
