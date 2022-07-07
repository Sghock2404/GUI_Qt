/*
 * Scott Hockaday
 * Intro to GUI 2022: Assignment 3
 * Due: 6/24/2022
 * Changes from Assignment 1 (if necessary): Added more ticks
*/

#include "mainwindow.h"
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>
#include <QGridLayout>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    pal->setColor(QPalette::Window, Qt::black);
    cable_Length->setStyleSheet("border: 1px solid black;");
    message_Length->setStyleSheet("border: 1px solid black;");
    message_Probability->setStyleSheet("border: 1px solid black;");
    max_Ticks->setStyleSheet("border: 1px solid black;");
    total_Ticks->setStyleSheet("border: 1px solid black;");

    cable_Length_LCD->setAutoFillBackground(true);
    cable_Length_LCD->setPalette(*pal);

    msg_Length_LCD->setAutoFillBackground(true);
    msg_Length_LCD->setPalette(*pal);

    msg_Prob_LCD->setAutoFillBackground(true);
    msg_Prob_LCD->setPalette(*pal);

    max_Ticks_LCD->setAutoFillBackground(true);
    max_Ticks_LCD->setPalette(*pal);

    total_Ticks_LCD->setAutoFillBackground(true);
    total_Ticks_LCD->setPalette(*pal);

    cable_Length_Spinbox->setRange(7, 99);

    cable_Length_Spinbox->setSingleStep(2);

    msg_Prob_Dial->setRange(10, 50);
    msg_Prob_Dial->setNotchesVisible(true);

    max_Ticks_Slider->setRange(1, 5);
    max_Ticks_Slider->setTickInterval(1);
    max_Ticks_Slider->setTickPosition(QSlider::TicksLeft);

    total_Ticks_Slider->setRange(3000, 10000);
    total_Ticks_Slider->setTickInterval(1000);
    total_Ticks_Slider->setTickPosition(QSlider::TicksBelow);

    msg_Length_Combo->insertItem(1, "Length");
    msg_Length_Combo->insertItem(2, "1");
    msg_Length_Combo->insertItem(3, "2");
    msg_Length_Combo->insertItem(4, "3");
    msg_Length_Combo->insertItem(5, "4");
    msg_Length_Combo->insertItem(6, "5");

    cable_Length_Spinbox->setValue(7);
    msg_Prob_Dial->setValue(10);
    max_Ticks_Slider->setValue(0);
    total_Ticks_Slider->setValue(3000);

    QObject::connect(cable_Length_Spinbox, SIGNAL(valueChanged(int)), cable_Length_LCD, SLOT(display(int)));
    QObject::connect(msg_Length_Combo, SIGNAL(activated(int)), msg_Length_LCD, SLOT(display(int)));
    QObject::connect(msg_Prob_Dial, SIGNAL(valueChanged(int)), msg_Prob_LCD, SLOT(display(int)));
    QObject::connect(max_Ticks_Slider, SIGNAL(valueChanged(int)), max_Ticks_LCD, SLOT(display(int)));
    QObject::connect(total_Ticks_Slider, SIGNAL(valueChanged(int)), total_Ticks_LCD, SLOT(display(int)));
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(actionButton()));
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(button, 500, 500);
    layout->setAlignment(button, Qt::AlignBottom);
    layout->addWidget(quit, 500, 600);
    layout->setAlignment(quit, Qt::AlignBottom);

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


    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
}

struct station
{
    int station_Number; // station location
    int message_Status; // checks the status of the message
    int message_Length; // length of the message being sent
    int target; // target location of where to send the message
    int idle; // checks if station is idle
    bool message_Transmit; // shows whether message is being transmitted
    bool used; // if station is being used
} S1, S2, S3; // stations

void MainWindow::actionButton()
{
    int lcd_Variable1 = cable_Length_LCD->intValue();
    int lcd_Variable2 = msg_Length_LCD->intValue();
    int lcd_Variable3 = msg_Prob_LCD->intValue();
    int lcd_Variable4 = max_Ticks_LCD->intValue();
    int lcd_Variable5 = total_Ticks_LCD->intValue();

    std::ofstream Outputfile;
    Outputfile.open("Simulation_Results.csv");
    Outputfile << "Tick, Source Station, Destination Station, Message Length" << std::endl;

    int cable_Length = lcd_Variable1; // length of cable (distance units)
    int msg_Length = lcd_Variable2;
    float probability = lcd_Variable3;
    int max_Idle_Ticks = lcd_Variable4;
    int total_Ticks = lcd_Variable5;

    station S1;
    S1.station_Number = 1;
    S1.message_Status = 1;
    S1.message_Length = 0;
    S1.target = 0;
    S1.idle = 0;
    S1.message_Transmit = false;
    S1.used = false;

    station S2;
    S2.station_Number = cable_Length / 2 + 1;
    S2.message_Status = 2;
    S2.message_Length = 0;
    S2.target = 0;
    S2.idle = 0;
    S2.message_Transmit = false;
    S2.used = false;

    station S3;
    S3.station_Number = cable_Length;
    S3.message_Status = 3;
    S3.message_Length = 0;
    S3.target = 0;
    S3.idle = 0;
    S3.message_Transmit = false;
    S3.used = false;

    bool carrierUsed = false;

    srand(time(0));

    float random_Float1;
    float random_Float2;
    float random_Float3;
    int ticks = 0;

    while (ticks < total_Ticks)
    {
        ticks++;
        // random floats to get a probability between 0.0 and 1.0
        random_Float1 = (float)rand() / RAND_MAX;
        random_Float2 = (float)rand() / RAND_MAX;
        random_Float3 = (float)rand() / RAND_MAX;

        // if the probability is 0.1, events occur
        if (random_Float1 <= (probability / 100) && S1.used == false && S1.idle == 0)
        {
            S1.used = true;
            S1.message_Length = rand() % msg_Length + 1; // message length is a random # between 1 and 3 to another station
            random_Float1 = (float)rand() / RAND_MAX;
            if (random_Float1 <= 0.5)   // if the float is instead half, it gets to set to another value of the target location
            {
                S1.target = S2.station_Number;
            }
            else
            {
                S1.target = S3.station_Number;
            }
        }
        if (S1.idle != 0)
        {
            S1.idle--;
        }

        if (random_Float2 <= (probability / 100) && S2.used == false && S2.idle == 0)
        {
            S2.used = true;
            S2.message_Length = rand() % msg_Length + 1;
            random_Float2 = (float)rand() / RAND_MAX;
            if (random_Float2 <= 0.5)
            {
                S2.target = S1.station_Number;
            }
            else
            {
                S2.target = S3.station_Number;
            }
        }
        if (S2.idle != 0)
        {
            S2.idle--;
        }

        if (random_Float3 <= (probability / 100) && S3.used == false && S3.idle == 0)
        {
            S3.used = true;
            S3.message_Length = rand() % msg_Length + 1;
            random_Float3 = (float)rand() / RAND_MAX;
            if (random_Float3 <= 0.5)
            {
                S3.target = S1.station_Number;
            }
            else
            {
                S3.target = S2.station_Number;
            }
        }
        if (S3.idle != 0)
        {
            S3.idle--;
        }

        if (carrierUsed == true)
        {
            // if the message transmit from that station is true (sent), the status of
            // the message and station update
            if (S1.message_Transmit == true)
            {
                S1.message_Status++;

                if ((S1.message_Status - S1.message_Length + 1) == S1.target)
                {
                    S1.message_Transmit = false;
                    S1.used = false;
                    S1.message_Status = S1.station_Number;
                    if (S1.target == S2.station_Number)
                    {
                        Outputfile << ticks << ", S1, S2, " << S1.message_Length << std::endl;
                    }
                    else
                    {
                        Outputfile << ticks << ", S1, S3, " << S1.message_Length << std::endl;
                    }
                }
            }
            if (S2.message_Transmit == true)
            {
                if (S2.target == S3.station_Number)
                {
                    S2.message_Status++;

                    if ((S2.message_Status - S2.message_Length + 1) == S2.target)
                    {
                        S2.message_Transmit = false;
                        S2.used = false;
                        S2.message_Status = S2.station_Number;
                        Outputfile << ticks << ", S2, S3, " << S2.message_Length << std::endl;
                    }
                }
                else
                {
                    S2.message_Status--;

                    if ((S2.message_Status + S2.message_Length - 1) == S2.target)
                    {
                        S2.message_Transmit = false;
                        S2.used = false;
                        S2.message_Status = S2.station_Number;
                        Outputfile << ticks << ", S2, S1, " << S2.message_Length << std::endl;
                    }
                }
            }
            if (S3.message_Transmit == true)
            {
                S3.message_Status--;

                if ((S3.message_Status + S3.message_Length - 1) == S3.target)
                {
                    S3.message_Transmit = false;
                    S3.used = false;
                    S3.message_Status = S3.station_Number;
                    if (S3.target == S2.station_Number)
                    {
                        Outputfile << ticks << ", S3, S2, " << S3.message_Length << std::endl;
                    }
                    else
                    {
                        Outputfile << ticks << ", S3, S1, " << S3.message_Length << std::endl;
                    }
                }
            }
            // if the message(s) from the station(s) are all false, then the carrier
            // is not used
            if (S1.message_Transmit == false && S2.message_Transmit == false &&
                    S3.message_Transmit == false)
            {
                carrierUsed = false;
            }

            if (carrierUsed == true)
            {
                if (S1.message_Transmit == false && S1.used == true && S1.idle == 0)
                {
                    S1.idle = rand() % (max_Idle_Ticks + 1);
                }
                if (S2.message_Transmit == false && S2.used == true && S2.idle == 0)
                {
                    S2.idle = rand() % (max_Idle_Ticks + 1);
                }
                if (S3.message_Transmit == false && S3.used == true && S3.idle == 0)
                {
                    S3.idle = rand() % (max_Idle_Ticks + 1);
                }
            }
        }
        else     // if the station is being used, the message from the station can
        {
            // transmit and the carrier is used
            if (S1.used == true)
            {
                S1.message_Transmit = true;
                carrierUsed = true;
            }
            else if (S2.used == true)
            {
                S2.message_Transmit = true;
                carrierUsed = true;
            }
            else if (S3.used == true)
            {
                S3.message_Transmit = true;
                carrierUsed = true;
            }
        }
        // termination condition
        if (ticks > total_Ticks)
        {
            break;
        }
    }
    //close file and exit
    Outputfile.close();
}
