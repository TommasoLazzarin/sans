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
        //inizializza il 
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
        connect(close, &QAction::triggered, this, &MainWindow::close); //chiude l'applicazione
        connect(emptySensor, &QAction::triggered, newSensorWidget, &NewSensorWidget::createNewSensor); //avvvia la procedura di creazione di un sensore vuoto
        connect(newSensorWidget, &NewSensorWidget::newSensorDataReady, this, &MainWindow::createEmptySensor); //quando i dati sono pronti creo un sensore vuoto
        connect(this, &MainWindow::newSensorAdded, browser, &BrowserWidget::updateSensorsList); //quando aggiungo un sensore aggiorno la lista
        connect(this, &MainWindow::newSensorAdded, sensorViewer, &view::sensor::SensorViewer::sensorChanged); //quando aggiungo un sensore lo seleziono nella view
        //connect(browser, &BrowserWidget::sensorSelected, sensorPage, &view::setSensorInViewer); //quando seleziono un sensore lo mostro nella view
    }

    void MainWindow::close()
    {
        QApplication::quit();
    }

    void MainWindow::createEmptySensor() // si occupa di comunicare al db di creare un'istanza di sensore vuoto
    {
        db->addEmptySensor(newSensorWidget->getNewSensorName(), newSensorWidget->getNewSensorType());
        //se non 
        if(noSensorAvailableWidget->isVisible())
        {
            noSensorAvailableWidget->hide();
            sensorViewer = new view::sensor::SensorViewer(this);
            splitter->addWidget(sensorViewer);
            splitter->setSizes(QList<int>() << 500 << 500);
        }
        emit newSensorAdded(); // emette il segnale per il refresh della lista e lo seleziona nella vista principale
        emit sensorSelectedChanged(db->last());
    }
}