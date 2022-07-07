/*
 * Scott Hockaday
 * Intro to GUI 2022: Assignment 4
 * Due: 6/30/2022
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
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include "QPainter"
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPalette *pal = new QPalette;
    QPushButton *submit = new QPushButton("Run Simulation");
    QPushButton *quit = new QPushButton("Quit");
    QPushButton *drawHist = new QPushButton("Draw Histogram");
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

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu = new QMenu;
    QMenu *quitMenu = new QMenu;
    QMenu *helpMenu = new QMenu;
    QMenu *editMenu = new QMenu;
    QAction *openAct = new QAction;
    QAction *exitAct = new QAction;
    QAction *aboutAct = new QAction;
    QAction *aboutQtAct = new QAction;
    void createMenus();

private slots:
    void submitButton();
    void drawButton();
    void open();
    void exit();
    void about();

protected:
    void paintEvent(QPaintEvent *event);

};
#endif // MAINWINDOW_H

