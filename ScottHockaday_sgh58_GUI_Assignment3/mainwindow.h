/*
 * Scott Hockaday
 * Intro to GUI 2022: Assignment 3
 * Due: 6/24/2022
 * Changes from Assignment 1 (if necessary): Added more ticks
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QDial>
#include <QLCDNumber>
#include <QPalette>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void actionButton();

public:
    QPalette *pal = new QPalette;
    QPushButton *button = new QPushButton("Submit");
    QPushButton *quit = new QPushButton("Quit");
    QLabel *cable_Length = new QLabel("Cable Length");
    QLabel *message_Length = new QLabel("Message Length");
    QLabel *message_Probability = new QLabel("Message Probability (in %)");
    QLabel *max_Ticks = new QLabel("Max Ticks (Carrier Sensing)");
    QLabel *total_Ticks = new QLabel("Total Ticks");
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
};
#endif // MAINWINDOW_H
