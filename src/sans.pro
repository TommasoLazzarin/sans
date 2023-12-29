######################################################################
# Automatically generated by qmake (3.1) Sun Dec 17 21:06:06 2023
######################################################################

TEMPLATE = app
TARGET = Sans
INCLUDEPATH += .
#Qt
QT+= core widgets

# Input
HEADERS += \
        view/MainWindow.h \
        view/SensorsList.h \
        view/NewSensorWizard.h \
        view/BrowserWidget.h \
        view/sensor/ControlPanel.h \
        view/sensor/SensorPage.h \
        model/Sensor.h \
        model/QuantitySensor.h \
        model/EventSensor.h \
        model/TimedValueSensor.h \
        model/db/Database.h \

SOURCES += \
        main.cpp \
        view/MainWindow.cpp \
        view/SensorsList.cpp \
        view/NewSensorWizard.cpp \
        view/BrowserWidget.cpp \
        view/sensor/ControlPanel.cpp \
        view/sensor/SensorPage.cpp \
        model/Sensor.cpp \
        model/QuantitySensor.cpp \
        model/EventSensor.cpp \
        model/TimedValueSensor.cpp \
        model/db/Database.cpp
#Fontawesome Icons
CONFIG+=fontAwesomeFree
include(lib/QtAwesome/QtAwesome.pri)
RC_ICONS = assets/sans-icon.ico