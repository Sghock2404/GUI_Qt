/*
 * Scott Hockaday
 * Intro to GUI 2022: Assignment 4
 * Due: 6/30/2022
*/

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QGridLayout>

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QDockWidget>
#include "QPainter"
#include <QPen>
#include <QColor>
#include <QMatrix3x3>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>

#include "math.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

int csv[10000];
int bins[20];
int number;
int i = 0;

void getNumbers()
{
    std::string filename("GPDF001.csv");
    std::ifstream file(filename);
    while (file >> number)
    {
        csv[i] = number;
        i++;
    }
    file.close();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pal->setColor(QPalette::Window, Qt::black);

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


    QDockWidget *dock_Num1 = new QDockWidget(tr("Total Ticks"), this);
    dock_Num1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QWidget *dock1 = new QWidget();
    QGridLayout *layout1 = new QGridLayout();
    total_Ticks_LCD->setAutoFillBackground(true);
    total_Ticks_LCD->setPalette(*pal);
    layout1->addWidget(total_Ticks_Slider, 0, 2, Qt::AlignCenter);
    layout1->addWidget(total_Ticks_LCD, 0, 3, Qt::AlignCenter);
    dock1->setLayout(layout1);
    dock_Num1->setWidget(dock1);
    QObject::connect(total_Ticks_Slider, SIGNAL(valueChanged(int)), total_Ticks_LCD, SLOT(display(int)));
    dock_Num1->setFixedHeight(100);
    total_Ticks_LCD->setFixedSize(100, 30);
    addDockWidget(Qt::TopDockWidgetArea, dock_Num1);

    QDockWidget *dock_Num2 = new QDockWidget(tr("Cable Length"), this);
    dock_Num2->setAllowedAreas(Qt::LeftDockWidgetArea);
    QWidget *dock2 = new QWidget();
    QGridLayout *layout2 = new QGridLayout();
    cable_Length_LCD->setAutoFillBackground(true);
    cable_Length_LCD->setPalette(*pal);
    layout2->addWidget(cable_Length_Spinbox);
    layout2->addWidget(cable_Length_LCD);
    dock2->setLayout(layout2);
    dock_Num2->setWidget(dock2);
    QObject::connect(cable_Length_Spinbox, SIGNAL(valueChanged(int)), cable_Length_LCD, SLOT(display(int)));
    dock_Num2->setFixedSize(100, 200);
    cable_Length_LCD->setFixedSize(100, 30);
    addDockWidget(Qt::LeftDockWidgetArea, dock_Num2);

    QDockWidget *dock_Num3 = new QDockWidget(tr("Carrier Sense"), this);
    dock_Num3->setAllowedAreas(Qt::LeftDockWidgetArea);
    QWidget *dock3 = new QWidget();
    QGridLayout *layout3 = new QGridLayout();
    max_Ticks_LCD->setAutoFillBackground(true);
    max_Ticks_LCD->setPalette(*pal);
    layout3->addWidget(max_Ticks_Slider);
    layout3->addWidget(max_Ticks_LCD);
    dock3->setLayout(layout3);
    dock_Num3->setWidget(dock3);
    QObject::connect(max_Ticks_Slider, SIGNAL(valueChanged(int)), max_Ticks_LCD, SLOT(display(int)));
    dock_Num3->setFixedSize(100, 200);
    max_Ticks_LCD->setFixedSize(100, 30);
    addDockWidget(Qt::LeftDockWidgetArea, dock_Num3);

    QDockWidget *dock_Num4 = new QDockWidget(tr("Msg Length"), this);
    dock_Num4->setAllowedAreas(Qt::RightDockWidgetArea);
    QWidget *dock4 = new QWidget();
    QGridLayout *layout4 = new QGridLayout();
    msg_Length_LCD->setAutoFillBackground(true);
    msg_Length_LCD->setPalette(*pal);
    layout4->addWidget(msg_Length_Combo);
    layout4->addWidget(msg_Length_LCD);
    dock4->setLayout(layout4);
    dock_Num4->setWidget(dock4);
    QObject::connect(msg_Length_Combo, SIGNAL(activated(int)), msg_Length_LCD, SLOT(display(int)));
    dock_Num4->setFixedSize(100, 200);
    msg_Length_LCD->setFixedSize(100, 30);
    addDockWidget(Qt::RightDockWidgetArea, dock_Num4);

    QDockWidget *dock_Num5 = new QDockWidget(tr("Msg Prob %"), this);
    dock_Num5->setAllowedAreas(Qt::RightDockWidgetArea);
    QWidget *dock5 = new QWidget();
    QGridLayout *layout5 = new QGridLayout();
    msg_Prob_LCD->setAutoFillBackground(true);
    msg_Prob_LCD->setPalette(*pal);
    layout5->addWidget(msg_Prob_Dial);
    layout5->addWidget(msg_Prob_LCD);
    dock5->setLayout(layout5);
    dock_Num5->setWidget(dock5);
    QObject::connect(msg_Prob_Dial, SIGNAL(valueChanged(int)), msg_Prob_LCD, SLOT(display(int)));
    dock_Num5->setFixedSize(100, 200);
    msg_Prob_LCD->setFixedSize(100, 30);
    addDockWidget(Qt::RightDockWidgetArea, dock_Num5);

    QDockWidget *dock_Num6 = new QDockWidget(tr("RUN SIM"), this);
    dock_Num6->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QWidget *dock6 = new QWidget();
    QGridLayout *layout6 = new QGridLayout();
    msg_Prob_LCD->setAutoFillBackground(true);
    msg_Prob_LCD->setPalette(*pal);
    layout6->addWidget(submit, 6, 1, Qt::AlignCenter);
    layout6->addWidget(drawHist, 6, 2, Qt::AlignCenter);
    layout6->addWidget(quit, 6, 4, Qt::AlignCenter);
    dock6->setLayout(layout6);
    dock_Num6->setWidget(dock6);
    QObject::connect(submit, SIGNAL(clicked()), this, SLOT(submitButton()));
    QObject::connect(drawHist, SIGNAL(clicked()), this, SLOT(drawButton()));
    QObject::connect(drawHist, SIGNAL(clicked()), this, SLOT(paintEvent()));
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    dock_Num6->setFixedHeight(100);
    addDockWidget(Qt::BottomDockWidgetArea, dock_Num6);

    QGridLayout *layout = new QGridLayout();
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    createMenus();
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    openAct = fileMenu->addAction(tr("&Open"), this, &MainWindow::open);

    quitMenu = menuBar()->addMenu(tr("&Quit"));
    exitAct = quitMenu->addAction(tr("&Stop Execution"), this, &QWidget::close);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);

    aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
}

void MainWindow::open()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this);
    std::string filepath = filename.toStdString();
    std::ifstream accessfile;
    accessfile.open(filepath.c_str());
    openAct = new QAction(tr("&Open"), this);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
}

void MainWindow::exit()
{
    exitAct = new QAction(tr("&Quit"), this);
    connect(exitAct, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::about()
{
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
    QMessageBox::information(this, "About",
                       "The Application was developed by Scott Hockaday");
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

void MainWindow::submitButton()
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

void MainWindow::drawButton()
{
    QGraphicsScene scene;
    scene.addText("Histogram");
    QGraphicsView view(&scene);
    view.show();
    getNumbers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int count = 0;
    int value1 = 1;
    int value2 = 21;

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10000; j++)
        {
            if(csv[j] == value1 || csv[j] == value2)
            {
                bins[i]++;
                if(csv[j] == 400)
                {
                    break;
                }
            }
        }
    value1 += 20;
    value2 += 20;
    }

    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));

    painter.drawRect(QRect(1000, 600, 20, -bins[19]));
    painter.drawRect(QRect(975, 600, 20, -bins[18]));
    painter.drawRect(QRect(950, 600, 20, -bins[17]));
    painter.drawRect(QRect(925, 600, 20, -bins[16]));
    painter.drawRect(QRect(900, 600, 20, -bins[15]));
    painter.drawRect(QRect(875, 600, 20, -bins[14]));
    painter.drawRect(QRect(850, 600, 20, -bins[13]));
    painter.drawRect(QRect(825, 600, 20, -bins[12]));
    painter.drawRect(QRect(800, 600, 20, -bins[11]));
    painter.drawRect(QRect(775, 600, 20, -bins[10]));
    painter.drawRect(QRect(750, 600, 20, -bins[9]));
    painter.drawRect(QRect(725, 600, 20, -bins[8]));
    painter.drawRect(QRect(700, 600, 20, -bins[7]));
    painter.drawRect(QRect(675, 600, 20, -bins[6]));
    painter.drawRect(QRect(650, 600, 20, -bins[5]));
    painter.drawRect(QRect(625, 600, 20, -bins[4]));
    painter.drawRect(QRect(600, 600, 20, -bins[3]));
    painter.drawRect(QRect(575, 600, 20, -bins[2]));
    painter.drawRect(QRect(550, 600, 20, -bins[1]));
    painter.drawRect(QRect(525, 600, 20, -bins[0]));

   painter.end();

}

