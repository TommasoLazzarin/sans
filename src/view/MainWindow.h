#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QHboxLayout>
#include "lib/QtAwesome/QtAwesome.h"
#include "model/QuantitySensor.h"
namespace view
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    private:
        fa::QtAwesome* awesome;
        //QHBoxLayout* layout;
    public:
        explicit MainWindow(QWidget *parent = 0);
    public slots:
        void close();
    };
}
#endif