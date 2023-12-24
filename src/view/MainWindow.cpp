// include Qt
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QProgressBar>
#include <QSplitter>
// include custom

#include "MainWindow.h"
#include "SensorsList.h"

namespace view
{
    MainWindow::MainWindow(fa::QtAwesome* icons, QWidget *parent) : awesome(icons), QMainWindow(parent)
                                              //layout(new QHBoxLayout(this))
    {
        // actions
        QAction *close = new QAction(awesome->icon(fa::fa_solid, fa::fa_xmark), "Close");

        // imposta menu bar
        QMenu *menu = menuBar()->addMenu("File");
        menu->addSeparator();
        menu->addAction(close);

        // imposta layout
        //setLayout(layout);
        QSplitter* splitter = new QSplitter(this);
        setCentralWidget(splitter);
        SensorsList* sensorsList = new SensorsList();
        sensorsList->setMinimumWidth(200);
        sensorsList->setMinimumHeight(500);

        QProgressBar* b2 = new QProgressBar();
        b2->setValue(70);
        b2->setMinimumWidth(600);
        splitter->addWidget(sensorsList);
        splitter->addWidget(b2);
        splitter->setSizes(QList<int>()<<500<<1000);
        splitter->setChildrenCollapsible(false);
        // connect
        connect(close, &QAction::triggered, this, &MainWindow::close);
    }

    void MainWindow::close()
    {
        QApplication::quit();
    }
}