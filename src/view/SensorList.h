#ifndef VIEW_SENSOR_LIST
#define VIEW_SENSOR_LIST
#include <QListWidget>
namespace view{
    class SensorList:public QListWidget{
        Q_OBJECT
        public SensorList():{}
    };
}

#endif