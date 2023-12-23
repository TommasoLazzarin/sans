#ifndef VIEW_SENSORS_LIST_H
#define VIEW_SENSORS_LIST_H
#include <QListWidget>

namespace view{
    class SensorsList:public QListWidget{
        Q_OBJECT
        public:
            explicit SensorsList(QWidget* parent = 0);
    };
}
#endif