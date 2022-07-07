A. (Assignment 2 with some modifications)

1) Develop a QT program that has widgets ready to be used with the CSMASim program 
you developed in assignment 1. The program is referred to as CSMASim. 

2) The widgets are input widgets e.g., a slider or a Nob-controller. However, each input 
widget should be connected to an LCD-display output widget.

3) Place the widgets on a grid layout and use different widgets for each input.

4) The required inputs are:

  a. The length of the cable odd number [7-99]. 

  b. The maximal length of a message [5].

  c. The probability of generating a massage (specified in percent) [10% - 50%]

  d. The minimal and maximal number of ticks for carrier sensing [0, 5]

  e. The total number of ticks for the entire simulation >= 3000.

B.

5) Develop a fully working version of CSMASim as defined in assignment-1. You do not 
have to add any functionality to CSMASim. You do need to integrate it into Qt.

C.
1) Connect every widget from part A. to the CSMASim version of part B. and use the 
widgets set-values as the actual input to CSMASim. This might necessitate a logical 
change in your CSMASim program

2) Include only three stations, S1, S2, and S3, in the simulation.

3) Implement only the CSMA part that generates messages. In other words, you do not 
have to implement the CD part (marked with a line-through text in assignment-1).

4) Produce the C++ code for the pseudo code Included in the background section of 
assignment-1.

D.

1) Execute your program for at least 3000 ticks.
