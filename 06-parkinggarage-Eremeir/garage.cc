/*
Matt Borek (z1951125)
Assignment 06
03/10/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#include "garage.h"
#include <algorithm>
#include <stack>

/**
 * @brief Add a new car to the garage.
 * 
 * Announces that a new car has arrived, and if there is room in the garage, adds it to the back of the line.
 * 
 * @param license The license plate of the arriving car. Used for printing arrival information.
 */
void garage::arrival(const std::string &license)
{
    car arrivingCar(next_car_id, license); //Create a new car object
    std::cout << arrivingCar << " has arrived." << std::endl;

    if(parking_lot.size() != parking_lot_limit) //If there is room in the garage
    {
        parking_lot.push_back(arrivingCar); //Add the car to the garage deque
        ++next_car_id; //Increase the next card ID so the next arriving car will have a unique ID.
    }
    else
    {
        std::cout << "    But the garage is full!" << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Remove a car from the garage.
 * 
 * First, find whether the input license plate corresponds to a car currently in the garage, then if the car is present, find its position in the garage and move each car
 * ahead of it to a temporary parking space to allow the departing car to exit the garage. Then, print departure information, including how many times the departing car
 * had to be moved around in the garage.
 * 
 * @param license The license plate of the departing car. Used to identify cars for movement and printing departure information.
 */
void garage::departure(const std::string &license)
{
    auto carSpot = std::find_if(parking_lot.begin(), parking_lot.end(), [license](car checkCar){return (checkCar.get_license() == license);});
    //Return an iterator to the position of the car if a license plate has been found in the garage that matches the input license information.

    if(carSpot != parking_lot.end()) //If carSpot is not at the end of the parkingLot deque, that means a valid car was found and is found at carSpot.
    {
        std::stack<car> tempParking; //Temporary parking space implimented as a stack to retain original car order as cars returned to the main parking lot.
        car departingCar = *carSpot; //A reference to the departing car to be used for member function calls.

        if (carSpot == parking_lot.begin()) //If the located carSpot is already at the front of the garage, simply have the car leave without moving other vehicles.
        {
            parking_lot.pop_front();
        }
        else
        {
            car frontCar = parking_lot.front();
            while(departingCar.get_license() != frontCar.get_license()) //While the car at the front of the garage is not the departing vehicle, keep moving cars to the
            {                                                           //temporary parking space to be backed from later.
                frontCar.move(); //Increase the movement count of the front car, as it is moved to temporary parking.
                tempParking.push(frontCar);
                parking_lot.pop_front();
                frontCar = parking_lot.front();
            }

            parking_lot.pop_front(); //Remove the departure car from the garage now that it is at the front of the lot.

            while(!tempParking.empty()) //While the temporary parking space still has cars in it, back them into the main parking lot in original order.
            {
                parking_lot.push_front(tempParking.top());
                tempParking.pop();
            }
        }

        departingCar.move(); //Increase the movement count as the departure car leaves the garage.
        std::cout << departingCar << " has departed," << std::endl;
        if(departingCar.get_num_moves() == 1) //Output appropriatly formatted information on the car's stay at the garage, including number of times moved.
        {
            std::cout << "    car was moved 1 time in the garage." << std::endl;
        }
        else
        {
            std::cout << "    car was moved " << departingCar.get_num_moves() << " times in the garage." << std::endl;
        }

    }
    else //If the carSpot iterator got to the end of the lot, this means the requested license plate was not found in the garage.
    {
        std::cout << "No car with license plate \"" << license << "\" is in the garage." << std::endl;
    }

    std::cout << std::endl;
}
