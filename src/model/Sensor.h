#ifndef MODEL_SENSOR_H
#define MODEL_SENSOR_H
#include <QString>
#include <QDateTime>
namespace model
{
    class Sensor
    {
    private:
        QDateTime created_at;
        QString name;
    protected:
        Sensor(QString n, QDateTime date);

    public:
        QString getName() const;
        void setName(const QString&);
        QDateTime getCreatedAt() const;
    };
}
#endif