
#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>

/*
Matt Borek (z1951125)
Assignment 05
03/1/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/


/**
 * @brief Print a dynamically sized underlined string.
 * 
 * Checks the length of the passed in string message and prints a string of dashes of the same length.
 * 
 * @param message A string message to be measured.
 */
void print_underlined_string(const std::string &message)
{
    std::string dashUnderline(message.length(), '-'); //Creates a string object composed of dashes a total of message.length() times.
    std::cout << message << std::endl << dashUnderline << std::endl;   
}

/**
 * @brief Print out the elimination results.
 * 
 * Prints out a dynamically indented list of all remaining people in the elimination round.
 * 
 * @param collection The collection of people in the elimination group.
 * @param eliminations The total number of people eliminated thusfar.
 * @param num_cols The intended column spacing for the printout.
 */
void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols)
{
    unsigned indentCount = 0;

    if(eliminations == 0)
    {
        print_underlined_string("Initial group of people");
    }
    else
    {
        std::cout << std::endl;
        print_underlined_string("After eliminating " + std::to_string(eliminations) + " people"); //Converts eliminations to a string and concatenates 
    }                                                                                             //the strings together to be passed in as a single string message.

    for(auto &survivor : collection)
    {
        indentCount++;
        std::cout << survivor;

        if(indentCount % num_cols == 0 || indentCount == collection.size())
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << ", ";
        }
    }
}

/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}

/**
* Create a std::list of prople with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line

    std::list<std::string> circularGroup;
    std::generate_n(std::back_inserter(circularGroup), num_people, SEQ(num_people));

    print_list(circularGroup, 0, num_cols);
    
    auto groupIndex = circularGroup.begin();

    unsigned eliminations = 0;
    int eliminationRound = 0;
    while(num_people > 1) //While there is more than one living member
    {
        ++eliminationRound;
        if(eliminationRound % modulus == 0) //Eliminates someone every modulus rounds
        {
            --num_people;
            ++eliminations;

            if(groupIndex == std::prev(circularGroup.end())) //Checks if the index is the last element in the list
            {
                circularGroup.erase(groupIndex); //Erases the contents of the current index
                groupIndex = circularGroup.begin(); //Sets the index back to the start of the list
            }
            else
            {
                groupIndex = circularGroup.erase(groupIndex); //Erases the contents of the current index and sets the index to the index after the current index
            }

            if(eliminations % print_frequency == 0) //Prints out the eliminations every print_frequency rounds
            {
                print_list(circularGroup, eliminations, num_cols);
            }
        }
        else
        {
            if(groupIndex == std::prev(circularGroup.end())) //Checks if the index is the last element in the list
            {
                groupIndex = circularGroup.begin(); //Sets the index back to the start of the list
            }
            else
            {
                ++groupIndex;
            }
        }
    }

    std::cout << std::endl << "Eliminations Completed";
    print_list(circularGroup, eliminations, num_cols);

  return 0;
}
