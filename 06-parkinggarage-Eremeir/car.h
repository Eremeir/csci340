#ifndef H_CAR
#define H_CAR

#include <string>
#include <iostream>

/*
Matt Borek (z1951125)
Assignment 06
03/10/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Car object class
 * 
 * Facilitates a car object which is identified by an ID, and a License.
 * It keeps track of how many times it's been moved in the garage through num_moves.
 */
class car
{
public:
    /**
     * @brief Construct a new car object.
     * 
     * @param id ID number to indicate the arrival order of a car, supplied by the garage.
     * @param license License plate string of the car to identify each vehicle.
     */
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the number of times the car has been moved.
    void move();

    /// @return the number of times that the car has been moved.
    int get_num_moves() const;
	
    /// @return A reference to the license for this car.
    const std::string &get_license() const;

    /**
     * @brief Overloaded outstream operator
     * 
     * Overload the ostream operator to allow car objects to be easily output to cout with appropriate formatting.
     * 
     * @param lhs Left-hand side paramater.
     * @param rhs Right-hand side parameter.
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream &lhs, const car &rhs)
    {
        lhs << "Car " << rhs.id << " with license plate \"" << rhs.license << "\"";
        return lhs;
    }

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};

#endif
