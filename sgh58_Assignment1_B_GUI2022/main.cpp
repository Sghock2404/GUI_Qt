/*
Scott Hockaday
GUI Assignment 1
Due: 06/07/22
*/

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>

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

int main()
{
    std::ofstream Outputfile;
    Outputfile.open("Simulation_Results.csv");
    Outputfile << "Tick, Source Station, Destination Station, Message Length" << std::endl;

    int M[7] = {1, 2, 3, 4, 5, 6, 7}; // length of cable (distance units)
    int N = 3;                        // # of stations

    station S1;
    S1.station_Number = M[0];
    S1.message_Status = 1;
    S1.message_Length = 0;
    S1.target = 0;
    S1.idle = 0;
    S1.message_Transmit = false;
    S1.used = false;

    station S2;
    S2.station_Number = M[3];
    S2.message_Status = 4;
    S2.message_Length = 0;
    S2.target = 0;
    S2.idle = 0;
    S2.message_Transmit = false;
    S2.used = false;

    station S3;
    S3.station_Number = M[6];
    S3.message_Status = 7;
    S3.message_Length = 0;
    S3.target = 0;
    S3.idle = 0;
    S3.message_Transmit = false;
    S3.used = false;

    int ticks = 0;
    bool carrierUsed = false;

    srand(time(0));

    float random_Float1;
    float random_Float2;
    float random_Float3;

    while (ticks < 400)
    {
        ticks++;

        // random floats to get a probability between 0.0 and 1.0
        random_Float1 = (float)rand() / RAND_MAX;
        random_Float2 = (float)rand() / RAND_MAX;
        random_Float3 = (float)rand() / RAND_MAX;

        // if the probability is 0.1, events occur
        if (random_Float1 <= 0.1 && S1.used == false &&
                S1.idle == 0)
        {
            S1.used = true;
            S1.message_Length =
                rand() % 3 +
                1; // message length is a random # between 1 and 3 to another station
            random_Float1 = (float)rand() / RAND_MAX;
            if (random_Float1 < 0.5)   // if the float is instead half, it gets to set to another value of the target location
            {
                S1.target = 4;
            }
            else
            {
                S1.target = 7;
            }
        }
        if (S1.idle != 0)
        {
            S1.idle--;
        }

        if (random_Float2 <= 0.1 && S2.used == false && S2.idle == 0)
        {
            S2.used = true;
            S2.message_Length = rand() % 3 + 1;
            random_Float2 = (float)rand() / RAND_MAX;
            if (random_Float2 < 0.5)
            {
                S2.target = 1;
            }
            else
            {
                S2.target = 7;
            }
        }
        if (S2.idle != 0)
        {
            S2.idle--;
        }

        if (random_Float3 <= 0.1 && S3.used == false && S3.idle == 0)
        {
            S3.used = true;
            S3.message_Length = rand() % 3 + 1;
            random_Float3 = (float)rand() / RAND_MAX;
            if (random_Float3 < 0.5)
            {
                S3.target = 1;
            }
            else
            {
                S3.target = 4;
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
                    S1.message_Status = 1;
                    if (S1.target == 4)
                    {
                        Outputfile << ticks << ", S" << "1" << ", S" << "2, " << S1.message_Length << std::endl;
                    }
                    else
                    {
                        Outputfile << ticks << ", S" << "1" << ", S" << "3, " << S1.message_Length << std::endl;
                    }
                }
            }
            if (S2.message_Transmit == true)
            {
                if (S2.target == 7)
                {
                    S2.message_Status++;

                    if ((S2.message_Status - S2.message_Length + 1) == S2.target)
                    {
                        S2.message_Transmit = false;
                        S2.used = false;
                        S2.message_Status = 4;
                        Outputfile << ticks << ", S" << "2" << ", S" << "3, " << S2.message_Length << std::endl;
                    }
                }
                else
                {
                    S2.message_Status--;

                    if ((S2.message_Status + S2.message_Length - 1) == S2.target)
                    {
                        S2.message_Transmit = false;
                        S2.used = false;
                        S2.message_Status = 4;
                        Outputfile << ticks << ", S" << "2" << ", S" << "1, " << S2.message_Length << std::endl;
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
                    S3.message_Status = 7;
                    if (S3.target == 4)
                    {
                        Outputfile << ticks << ", S" << "3" << ", S" << "2, " << S3.message_Length << std::endl;
                    }
                    else
                    {
                        Outputfile << ticks << ", S" << "3" << ", S" << "1, " << S3.message_Length << std::endl;
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
            // this determines the random number between 1 and 4
            if (carrierUsed == true)
            {
                if (S1.message_Transmit == false && S1.used == true && S1.idle == 0)
                {
                    S1.idle = rand() % 4 + 1;
                }
                if (S2.message_Transmit == false && S2.used == true && S2.idle == 0)
                {
                    S2.idle = rand() % 4 + 1;
                }
                if (S3.message_Transmit == false && S3.used == true && S3.idle == 0)
                {
                    S3.idle = rand() % 4 + 1;
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
        if (ticks > 400)
        {
            break;
        }
    }
    //close file and exit
    Outputfile.close();
    return 0;
}
