// include Qt
#include <QMenu>
#include <QMenuBar>
#include <QApplication>

// include custom
#include "MainWindow.h"
#include "SensorsList.h"
#include "SensorWizard.h"

namespace view
{
    MainWindow::MainWindow(model::db::Database* database,fa::QtAwesome* icons, QWidget *parent) :db(database), awesome(icons), QMainWindow(parent)
    {
        // actions
        QAction *close = new QAction(awesome->icon(fa::fa_solid, fa::fa_xmark), "Close");
        QAction *emptySensor = new QAction(awesome->icon(fa::fa_solid, fa::fa_arrow_up_right_from_square), "Create empty");
        QAction *importSensor = new QAction(awesome->icon(fa::fa_solid, fa::fa_file_import), "Import from file");
        // imposta menu bar
        QMenu *menu = menuBar()->addMenu("File");
        QMenu *newSensorMenu = menu->addMenu(awesome->icon(fa::fa_solid, fa::fa_plus), "Add sensor");
        newSensorMenu->addAction(emptySensor);
        newSensorMenu->addAction(importSensor);
        menu->addMenu(newSensorMenu);
        menu->addSeparator();
        menu->addAction(close);

        // imposta layout
        splitter = new QSplitter(this);
        setCentralWidget(splitter);
        browser=new view::BrowserWidget(db, this);
        browser->setMinimumWidth(200);
        browser->setMinimumHeight(500);
        sensorPage=new view::sensor::SensorPage(this);
        splitter->addWidget(browser);
        splitter->addWidget(sensorPage);
        splitter->setSizes(QList<int>()<<500<<1000);
        splitter->setChildrenCollapsible(false);
        // connect
        connect(close, &QAction::triggered, this, &MainWindow::close);
        connect(emptySensor, &QAction::triggered, this, &MainWindow::showSensorWizard);
    }

    void MainWindow::close()
    {
        QApplication::quit();
    }

    void MainWindow::showSensorWizard()
    {
        view::SensorWizard* wizard=new view::SensorWizard(db,this);
        wizard->show();
    }
}