#ifndef VIEW_NO_SENSOR_AVAILABLE_WIDGET_H
#define VIEW_NO_SENSOR_AVAILABLE_WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
namespace view
{
    class NoSensorAvailableWidget : public QWidget
    {
        Q_OBJECT
    private:
        QVBoxLayout *layout;
        QLabel *noSensorAvailableLabel;
    public:
        NoSensorAvailableWidget(QWidget *parent = nullptr);
    };
}
#endif