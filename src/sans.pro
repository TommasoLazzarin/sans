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
        model/Sensor.h \
        model/QuantitySensor.h \
        model/EventSensor.h \
        model/TimedValueSensor.h
SOURCES += \
        main.cpp view/MainWindow.cpp \
        model/Sensor.cpp \
        model/QuantitySensor.cpp \
        model/EventSensor.cpp \
        model/TimedValueSensor.cpp
#Fontawesome Icons
CONFIG+=fontAwesomeFree
include(lib/QtAwesome/QtAwesome.pri)
