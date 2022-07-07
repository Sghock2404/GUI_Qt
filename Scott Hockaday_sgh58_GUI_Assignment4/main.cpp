/*
 * Scott Hockaday
 * Intro to GUI 2022: Assignment 4
 * Due: 6/30/2022
*/

#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("GUI Assignment4");
    w.show();
    return a.exec();
}
