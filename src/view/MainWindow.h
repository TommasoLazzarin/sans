#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include "lib/QtAwesome/QtAwesome.h"
namespace view
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    private:
        fa::QtAwesome* awesome;
    public:
        explicit MainWindow(QWidget *parent = 0);
    public slots:
        void close();
    };
}
#endif