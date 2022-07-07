In this QT assignment, you have to extend assignment 3 in the following ways:

A. CSMASim

1) keep all the widgets from assignment 3, with their specifications and connection to
CSMASim and to LCD displays.

2) Make sure that you have (or add) a Quit button that can stop the execution of your 
program

3) Place the widgets from assignment 3 on the edges of a dock widget as in the example:
https://doc.qt.io/qt-6/qtwidgets-mainwindows-mainwindow-example.html, which is 
available in the QT Demos and examples.

4) Add a menu item to your dock widgets. You can use the dock widgets example or
https://doc.qt.io/qt-6/qtwidgets-mainwindows-dockwidgets-example.html, or, 
https://doc.qt.io/qt-6/qtwidgets-mainwindows-menus-example.html.

5) The menu should include “Fie ➔ Open” item for opening a .CSV file for read, a 
“Quit➔ Stop Execution” item that terminates the program, and a “Help➔About” 
item that includes the phrase “Developed by” along with you name. 

6) Generate a graphics window (widget) in the center of the dock widgets.

7) Use a fully working version of CSMASim as defined in assignment-3. You can use 
assignment 3 version, or develop, modify, improve your assignment 3 version. 
Eventually, if your grade for this part of assignment 4, is better than the grade for this 
part of assignment 3, it will take over your assignment 3 grade of this part. If your 
grade for this part of assignment 4, is better than the grade for this part of assignment 
1, it will take over your assignment 1 grade of this part.

8) Implement only the CSMA part that generates messages. In other words, you do not 
have to implement the CD part (marked with a line-through text in assignment-1).

9) Execute your program for at least 3000 ticks.

B. Graphics

1) Use the “Fie ➔ Open” menu item to open the enclosed CSV file ‘GPDF001.csv. Note 
that the file has 10,000 integers in the range [1, 826].

2) Produce the data structure for visualizing the histogram of the data stored in the 
CSV file ‘GPDF001.csv. Your data structure should consists of only bins of size 20 and 
include only the bins from 1 to 400. A histogram generate by excel is depicted in 
figure 1.

3) Use QPainter to draw the data from the data structure of section B.2 as a histogram 
(i.e., bar-chart), where the bars are rectangular-shapes in blue color. You do not 
have to produce axis data.

4) Use QPainter to draw the data from the histogram data structure of section B.2 as 
y=f(n), where n is a bin number The Plot should be in red color and appear on top of 
the histogram specified in section B.3.
