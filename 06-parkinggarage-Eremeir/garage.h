#ifndef H_GARAGE
#define H_GARAGE

#include <string>
#include <queue>
#include "car.h"

/*
Matt Borek (z1951125)
Assignment 06
03/10/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Car object class
 * 
 * Facilitates a garage object which has a maximum capacity and keeps track of the number of arrivals.
 * It also passes information to car objects to indicate their ID.
 * 
 */
class garage
{
public:
        /**
         * @brief Construct a new garage object.
         * 
         * @param limit The total capacity of the garage.
         */
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.                                                           
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.                                                          
        void departure(const std::string &license);

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};

#endif
