/*
Matt Borek (z1951125)
Assignment 06
03/10/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#include <string>
#include <iostream>
#include "garage.h"

/**
 * @brief Parse input string
 * 
 * Parse given input string and assign the values to temp variables for use in creating car objects. 
 * 
 * @param line Given string line to be parsed into individual pieces.
 * @param xact_type Action type, denoted by a single character to be used in switch case for determining event type.
 * @param license License string to identify each car by name.
 */
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    xact_type = line.front(); //The first character should indicate the event type.
    license = line.substr(2, line.length()-3); //The string between these two ranges will contain the license plate.
}

/**
 * @brief Accept user input on arriving and departing cars.
 * 
 * Accept a properly input line by line, and parse that input to call appropriate arrival or departure functions.
 * 
 * @return int 0 to close program out of scope.
 */
int main()
{
    garage parking_lot;
    bool garageClosed = false;

    while(!garageClosed)
    {
        std::string userInput;
        std::string licenseTemp;
        char eventTemp;

        std::getline(std::cin, userInput); //Accept user input line by line and store in userInput.
        if(userInput.length() != 0)
        {
            get_input_vals(userInput, eventTemp, licenseTemp); //Pass input line to be parsed into individual variables.

            switch (eventTemp) //If the eventType char ia A, call arrival function, if D, call departure function, otherwise indicate an error.
            {
                case 'A':
                {
                    parking_lot.arrival(licenseTemp);
                    break;
                }

                case 'D':
                {
                    parking_lot.departure(licenseTemp);
                    break;
                }

                default:
                {
                    std::cout << "'" << eventTemp << "': invalid action!"<< std::endl << std::endl;
                }
            }
        }
        else
        {
            garageClosed = true; //Signals that there is no more input to process.
        }
    }
    return 0;
}
