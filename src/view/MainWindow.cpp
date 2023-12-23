// include Qt
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QProgressBar>
// include custom

#include "MainWindow.h"

namespace view
{
    MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                              awesome(new fa::QtAwesome(this)),
                                              layout(new QHBoxLayout(this))
    {
        awesome->initFontAwesome();
        // actions
        QAction *close = new QAction(awesome->icon(fa::fa_solid, fa::fa_xmark), "Close");

        // imposta menu bar
        QMenu *menu = menuBar()->addMenu("File");
        menu->addSeparator();
        menu->addAction(close);

        // imposta layout
        setLayout(layout);

        // connect
        connect(close, &QAction::triggered, this, &MainWindow::close);
    }

    void MainWindow::close()
    {
        QApplication::quit();
    }
}