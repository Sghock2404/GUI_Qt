/*
 * Scott Hockaday
 * Intro to GUI 2022: Assignment 3
 * Due: 6/24/2022
 * Changes from Assignment 1 (if necessary): Added more ticks
*/

#include "mainwindow.h"
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
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
