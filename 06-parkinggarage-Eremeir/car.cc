/*
Matt Borek (z1951125)
Assignment 06
03/10/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#include "car.h"

/**
 * @brief Increment car movement total.
 * 
 *  Increment the number of times the car has been moved. This is called when a car departs, and any time is is moved to temporary parking.
 * 
 */
void car::move() /// Call 
{
    ++num_moves;
}

/**
 * @brief Return car movement toal.
 * 
 * Return the total number of times the car has been moved. This is called as part of vehicle departure.
 * 
 * @return num_moves, the number of times the car has been moved.
 */
int car::get_num_moves() const /// 
{
    return num_moves;
}

/**
 * @brief Return car license plate.
 * 
 * @return License, the license plate information for the car.
 */
const std::string& car::get_license() const /// @return A reference to the license for this car.
{
    return license;
}
