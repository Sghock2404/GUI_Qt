Initial system definitions:

•	The length of the cable is M distance units (M is an odd parameter of your choice). 
•	There are N stations for now N = 3. So, three stations S1 to S3. 
•	S1 and S3 are on the two ends of the cable, S2 is in the middle.
•	A message propagates at a rate of one distance unit per tick.
•	At each time-tick, with a probability of p=0.1, an idle station Si might initiate a message of length  K ticks (K is a random number between 1 and 3) to another station Sj (j is selected randomly). 
•	At any time-tick, each station is sensing the carrier, it can only sense the distance unit of its location.
•	Prior to sending a message to station ‘B,’ Station ‘A’ senses the carrier.
  If the carrier is free, then ‘A’ starts transmitting the message. 
	If the carrier is busy, then ‘A’ stops sensing and randomly selects one of the next T ticks (T is a random number between 1 and 4)  for CS. 
•	On collision, the message gets distorted.
•	On collision the initiating stations stop the transmission and delays the attempt for retransmission (CS) by a random amount of ticks.
	For this assignment, we will assume that the ‘A’ delays the next transmission of the collided message (i.e., the next CS) by ‘l’ ticks, where ‘l’ is a random number in the range [1, ... , R]
•	The simulation program checks for termination condition (a relatively large number of ticks) 
•	The program evaluates and records (in a CVS file) statistics including 
The number of messages initiated and the number of successful transmissions. 
