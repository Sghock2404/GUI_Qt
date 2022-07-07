/*
 Scott Hockaday
 CS 4353.501: Intro to GUI
 Due: 06/14
*/

#include "Simulation.h"
#include <QApplication>
#include <QGridLayout>
#include <QLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QDial>
#include <QLCDNumber>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget *window = new QWidget;
    window->setWindowTitle("GUI Assignment 2");

    QLabel *cable_Length = new QLabel("Cable Length");
    cable_Length->setStyleSheet("border: 1px solid black;");

    QLabel *message_Length = new QLabel("Message Length");
    message_Length->setStyleSheet("border: 1px solid black;");

    QLabel *message_Probability = new QLabel("Message Probability (in %)");
    message_Probability->setStyleSheet("border: 1px solid black;");

    QLabel *max_Ticks = new QLabel("Max Ticks (Carrier Sensing)");
    max_Ticks->setStyleSheet("border: 1px solid black;");

    QLabel *total_Ticks = new QLabel("Total Ticks");
    total_Ticks->setStyleSheet("border: 1px solid black;");

    QPalette *pal = new QPalette;
    pal->setColor(QPalette::Window, Qt::black);

    QSpinBox *cable_Length_Spinbox = new QSpinBox;
    QComboBox *msg_Length_Combo = new QComboBox;
    QDial *msg_Prob_Dial = new QDial;
    QSlider *max_Ticks_Slider = new QSlider(Qt::Vertical);
    QSlider *total_Ticks_Slider = new QSlider(Qt::Horizontal);

    QLCDNumber *cable_Length_LCD = new QLCDNumber;
    QLCDNumber *msg_Length_LCD = new QLCDNumber;
    QLCDNumber *msg_Prob_LCD = new QLCDNumber;
    QLCDNumber *max_Ticks_LCD = new QLCDNumber;
    QLCDNumber *total_Ticks_LCD = new QLCDNumber;

    cable_Length_Spinbox->setRange(7, 99);
    cable_Length_Spinbox->setSingleStep(2);
    cable_Length_LCD->setAutoFillBackground(true);
    cable_Length_LCD->setPalette(*pal);
    QObject::connect(cable_Length_Spinbox, SIGNAL(valueChanged(int)), cable_Length_LCD, SLOT(display(int)));

    msg_Length_Combo->insertItem(1, "Length");
    msg_Length_Combo->insertItem(2, "1");
    msg_Length_Combo->insertItem(3, "2");
    msg_Length_Combo->insertItem(4, "3");
    msg_Length_Combo->insertItem(5, "4");
    msg_Length_Combo->setItemData(0, false, Qt::UserRole - 1);

    msg_Length_LCD->setAutoFillBackground(true);
    msg_Length_LCD->setPalette(*pal);
    QObject::connect(msg_Length_Combo, SIGNAL(activated(int)), msg_Length_LCD, SLOT(display(int)));

    msg_Prob_Dial->setRange(0, 50);
    msg_Prob_Dial->setNotchesVisible(true);
    msg_Prob_LCD->setAutoFillBackground(true);
    msg_Prob_LCD->setPalette(*pal);
    QObject::connect(msg_Prob_Dial, SIGNAL(valueChanged(int)), msg_Prob_LCD, SLOT(display(int)));

    max_Ticks_Slider->setRange(1, 5);
    max_Ticks_Slider->setTickInterval(1);
    max_Ticks_Slider->setTickPosition(QSlider::TicksLeft);
    max_Ticks_LCD->setAutoFillBackground(true);
    max_Ticks_LCD->setPalette(*pal);
    QObject::connect(max_Ticks_Slider, SIGNAL(valueChanged(int)), max_Ticks_LCD, SLOT(display(int)));

    total_Ticks_Slider->setRange(0, 3000);
    total_Ticks_Slider->setTickInterval(1000);
    total_Ticks_Slider->setTickPosition(QSlider::TicksBelow);
    total_Ticks_LCD->setAutoFillBackground(true);
    total_Ticks_LCD->setPalette(*pal);
    QObject::connect(total_Ticks_Slider, SIGNAL(valueChanged(int)), total_Ticks_LCD, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout(window);
    layout->addWidget(cable_Length, 0, 0);
    layout->setAlignment(cable_Length_Spinbox, Qt::AlignTop);
    layout->addWidget(cable_Length_LCD, 1, 0);
    layout->setAlignment(cable_Length_Spinbox, Qt::AlignCenter);
    layout->addWidget(cable_Length_Spinbox, 60, 0);
    layout->setAlignment(cable_Length_Spinbox, Qt::AlignCenter);

    layout->addWidget(message_Length, 0, 60);
    layout->setAlignment(msg_Length_Combo, Qt::AlignTop);
    layout->addWidget(msg_Length_LCD, 1, 60);
    layout->setAlignment(msg_Length_Combo, Qt::AlignCenter);
    layout->addWidget(msg_Length_Combo, 60, 60);
    layout->setAlignment(msg_Length_Combo, Qt::AlignCenter);

    layout->addWidget(message_Probability, 0, 120);
    layout->setAlignment(msg_Prob_Dial, Qt::AlignTop);
    layout->addWidget(msg_Prob_LCD, 1, 120);
    layout->setAlignment(msg_Prob_Dial, Qt::AlignCenter);
    layout->addWidget(msg_Prob_Dial, 60, 120);
    layout->setAlignment(msg_Prob_Dial, Qt::AlignCenter);

    layout->addWidget(max_Ticks, 0, 180);
    layout->setAlignment(max_Ticks_Slider, Qt::AlignTop);
    layout->addWidget(max_Ticks_LCD, 1, 180);
    layout->setAlignment(max_Ticks_Slider, Qt::AlignCenter);
    layout->addWidget(max_Ticks_Slider, 60, 180);
    layout->setAlignment(max_Ticks_Slider, Qt::AlignCenter);

    layout->addWidget(total_Ticks, 0, 240);
    layout->setAlignment(total_Ticks_Slider, Qt::AlignTop);
    layout->addWidget(total_Ticks_LCD, 1, 240);
    layout->setAlignment(total_Ticks_Slider, Qt::AlignCenter);
    layout->addWidget(total_Ticks_Slider, 60, 240);
    layout->setAlignment(total_Ticks_Slider, Qt::AlignCenter);

    w.show();
    window->setLayout(layout);
    window->show();

    return a.exec();
}
