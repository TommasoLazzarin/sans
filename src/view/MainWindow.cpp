// include Qt
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QChar>

// include custom
#include "MainWindow.h"
#include "SensorsList.h"

namespace view
{
    MainWindow::MainWindow(model::db::Database *database, fa::QtAwesome *icons, QWidget *parent) : db(database), awesome(icons), QMainWindow(parent)
    {
        setWindowIcon(awesome->icon("fa-solid fa-gauge"));
        // inizializza il NewSensorWidget
        newSensorWidget = new view::NewSensorWidget(awesome, this);

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
        browser = new view::BrowserWidget(db, awesome, this);
        browser->setMinimumWidth(200);
        browser->setMinimumHeight(500);
        sensorViewer = 0;//verrà allocato quando verrà aggiunto un sensore alla lista. Verrà deallocato quando non ci saranno più sensori.
        noSensorAvailableWidget = new view::NoSensorAvailableWidget(this);
        splitter->addWidget(browser);
        splitter->addWidget(noSensorAvailableWidget);
        splitter->setSizes(QList<int>() << 500 << 1000);
        splitter->setChildrenCollapsible(false);
        // connect
        connect(close, &QAction::triggered, this, &MainWindow::close);
        connect(emptySensor, &QAction::triggered, newSensorWidget, &NewSensorWidget::createNewSensor);
        connect(newSensorWidget, &NewSensorWidget::newSensorDataReady, this, &MainWindow::createEmptySensor);
        connect(this, &MainWindow::newSensorAdded, browser, &BrowserWidget::updateSensorsList);
        //connect(browser, &BrowserWidget::sensorSelected, sensorPage, &view::sensor::SensorPage::setSensor);
    }

    void MainWindow::close()
    {
        QApplication::quit();
    }

    void MainWindow::createEmptySensor() // si occupa di comunicare al db di creare un'istanza di sensore vuoto
    {
        if(noSensorAvailableWidget->isVisible())
        {
            noSensorAvailableWidget->hide();
            // sensorViewer = new view::sensor::SensorViewer(db, this);
            // splitter->addWidget(sensorViewer);
            // splitter->setSizes(QList<int>() << 500 << 500);
        }
        db->addEmptySensor(newSensorWidget->getNewSensorName(), newSensorWidget->getNewSensorType());
        emit newSensorAdded(); // emette il segnale per il refresh della lista e lo seleziona nella vista principale
        
    }
}