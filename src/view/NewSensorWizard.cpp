#include <QLabel>
#include <QVBoxLayout>

#include "view/NewSensorWizard.h"

view::NewSensorWizard::NewSensorWizard(){
    QWizardPage *page = new QWizardPage;
    page->setTitle("Sensor creation");

    QLabel *label = new QLabel("This wizard will help you choose the right type of sensor you want to create.");
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout);
}