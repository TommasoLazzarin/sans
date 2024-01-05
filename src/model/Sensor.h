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
        Sensor(const QString& n, const QDateTime& date);

    public:
        QString getName() const;
        void setName(const QString&);
        QDateTime getCreatedAt() const;
        QString getCreatedAtString() const;
        virtual void simulate()=0;
        virtual ~Sensor();
    };
}
#endif