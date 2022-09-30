//***************************************************************************
//
//  rational.cc
//  CSCI 241 Operator Overloading Example
//
//  Created by Kurt McMahon (t90kjm1)
//
// See: http://faculty.cs.niu.edu/~winans/CS501/#operator_overloading
//
//***************************************************************************

#include <iostream>
#include <sstream>
#include <iomanip>
#include "rational.h"

using std::cout;
using std::fixed;
using std::istream;
using std::ostream;
using std::setprecision;

/**
 * Constructor; initializes numerator and denominator
 * data members to arguments.
 *
 * @param numerator An integer numerator.
 * @param denominator An integer denominator.
 *
 * @note Reduces rational number to its lowest terms.
 ********************************************************************************/
Rational::Rational(int numerator, int denominator)
{
    int gcd = find_gcd(numerator, denominator);

    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
}

/**
 * Displays rational number as a floating-point value.
 ********************************************************************************/
void Rational::display_float() const
{
    cout << fixed << setprecision(5)
         << (double) numerator / denominator;
}

/**
 * Numerator accessor function.
 *
 * @return The integer numerator of the rational number.
 ********************************************************************************/
int Rational::get_numerator() const
{
    return numerator;
}
   
/**
 * Denominator accessor function.
 *
 * @return The integer denominator of the rational number.
 ********************************************************************************/
int Rational::get_denominator() const
{
    return denominator;
}
   
/**
 * Denominator mutator function.
 *
 * @param denominator New denominator for the rational number.
 ********************************************************************************/
void Rational::set_denominator(int denominator)
{
    int gcd = find_gcd(this->numerator, denominator);
 
    this->numerator /= gcd;
    this->denominator = denominator / gcd;
}
   
/**
 * Numerator mutator function.
 *
 * @param numerator New numerator for the rational number.
 ********************************************************************************/
void Rational::set_numerator(int numerator)
{
    int gcd = find_gcd(numerator, this->denominator);
 
    this->numerator = numerator / gcd;
    this->denominator /= gcd;
}

/**
 * Mutator function to change both numerator and denominator.
 *
 * @param numerator New numerator for the rational number.
 * @param denominator New numerator for the rational number.
 ********************************************************************************/
void Rational::set_rational(int numerator, int denominator)
{
    int gcd = find_gcd(numerator, denominator);
 
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
}

/**
 * Finds the greatest common divisor of two integer numbers.
 *
 * @param m First number.
 * @param n Second number.
 *
 * @return The greatest common divisor of m and n.
 ********************************************************************************/
int Rational::find_gcd(int m, int n) const
{
    int rem;
   
    while (n > 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }
      
    return m;
}

/**
 * Finds the least common multiplier of two integer numbers.
 *
 * @param m First number.
 * @param n Second number.
 *
 * @return The least common multiplier of m and n.
 ********************************************************************************/
int Rational::find_lcm(int m, int n) const
{
    return ((m * n) / find_gcd(m, n));
}

/**
 * Adds two rational numbers to produce a rational number result.
 *
 * @param rhs Right-hand side operand of the addition.
 *
 * @return The result of the addition.
 *
 * @note The result is reduced to its lowest terms.
 ********************************************************************************/
Rational Rational::operator+(const Rational& rhs) const
{
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    Rational result = *this;
   
    // Convert the rational numbers to a common denominator
    int lcm = find_lcm(result.denominator, rhs.denominator);

    result.numerator *= lcm / result.denominator;
    result.denominator = lcm;
   
    // Perform the addition      
    result.numerator += rhs.numerator * lcm / rhs.denominator;
 
    // Reduce the result to its lowest terms
    int gcd = find_gcd(result.numerator, result.denominator);
 
    result.numerator /= gcd;
    result.denominator /= gcd;
 
    // Return the result  
    return result;   
}

/**
 * Subtracts two rational numbers to produce a rational number result.
 *
 * @param rhs Right-hand side operand of the subtraction.
 *
 * @return The result of the subtraction.
 *
 * @note The result is reduced to its lowest terms.
 ********************************************************************************/
Rational Rational::operator-(const Rational& rhs) const
{
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    Rational result = *this;
   
    // Convert the rational numbers to a common denominator
    int lcm = find_lcm(result.denominator, rhs.denominator);
   
    result.numerator *= lcm / result.denominator;
    result.denominator = lcm;
   
    // Perform the subtraction
    result.numerator -= rhs.numerator * lcm / rhs.denominator;
 
    // Reduce the result to its lowest terms
    int gcd = find_gcd(result.numerator, result.denominator);
 
    result.numerator /= gcd;
    result.denominator /= gcd;
   
    // Return the result  
    return result;   
}

/**
 * Multiplies two rational numbers to produce a rational number result.
 *
 * @param rhs Right-hand side operand of the multiplication.
 *
 * @return The result of the multiplication.
 *
 * @note The result is reduced to its lowest terms.
 ********************************************************************************/
Rational Rational::operator*(const Rational& rhs) const
{
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    Rational result = *this;

    // Multiply the left operand by the right operand   
    result.numerator *= rhs.numerator;
    result.denominator *= rhs.denominator;
 
    // Reduce the result to its lowest terms
    int gcd = find_gcd(result.numerator, result.denominator);
 
    result.numerator /= gcd;
    result.denominator /= gcd;
   
    // Return the result  
    return result;   
}
   
/**
 * Divides two rational numbers to produce a rational number result.
 *
 * @param rhs Right-hand side operand of the division.
 *
 * @return The result of the division.
 *
 * @note The result is reduced to its lowest terms.
 ********************************************************************************/
Rational Rational::operator/(const Rational& rhs) const
{
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    Rational result = *this;
   
    // Multiply the left operand by the inverse of the right
    // operand   
    result.numerator *= rhs.denominator;
    result.denominator *= rhs.numerator;
 
    // Reduce the result to its lowest terms
    int gcd = find_gcd(result.numerator, result.denominator);
 
    result.numerator /= gcd;
    result.denominator /= gcd;
   
    // Return the result  
    return result;   
}

/**
 * Adds a rational number and an integer to produce a rational number result.
 *
 * @param rhs Right-hand side integer operand of the addition.
 *
 * @return The result of the addition.
 *
 * @note The result is reduced to its lowest terms.
 ********************************************************************************/
Rational Rational::operator+(int rhs) const
{
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    Rational result = *this;
   
    // Perform the addition
    result.numerator += rhs * result.denominator; 
 
    // Reduce the result to its lowest terms
    int gcd = find_gcd(result.numerator, result.denominator);
 
    result.numerator /= gcd;
    result.denominator /= gcd;
   
    // Return the result  
    return result;   
}

/**
 * Compares two rational numbers for equality.
 *
 * @param rhs Right-hand side operand of the comparison.
 *
 * @return true if the numbers are equal; otherwise, false.
 ********************************************************************************/
bool Rational::operator==(const Rational& rhs) const
{
    return (numerator == rhs.numerator && denominator == 
     rhs.denominator);
}

/**
 * Compares two rational numbers to see if one is less than the other.
 *
 * @param rhs Right-hand side operand of the comparison.
 *
 * @return true if the left-hand side operand is less than the right-hand side
 *         operand; otherwise, false.
 ********************************************************************************/
bool Rational::operator<(const Rational& rhs) const
{
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    Rational temp = *this;
   
    // Convert the rational numbers to a common denominator
    int lcm = find_lcm(temp.denominator, rhs.denominator);
   
    temp.numerator *= lcm / temp.denominator;
    temp.denominator = lcm;

    return (temp.numerator < (rhs.numerator * lcm / rhs.denominator));
}

/**
 * Compares two rational numbers to see if one is less than or equal to the
 * other.
 *
 * @param rhs Right-hand side operand of the comparison.
 *
 * @return true if the left-hand side operand is less than or equal to the
 *         right-hand side operand; otherwise, false.
 ********************************************************************************/
bool Rational::operator<=(const Rational& rhs) const
{
    if ((*this < rhs) || (*this == rhs))
        return true;
    else
        return false;
}

/**
 * Compares two rational numbers to see if one is greater than the other.
 *
 * @param rhs Right-hand side operand of the comparison.
 *
 * @return true if the left-hand side operand is greater than the right-hand side
 *         operand; otherwise, false.
 ********************************************************************************/
bool Rational::operator>(const Rational& rhs) const
{
    if (!(*this < rhs) && !(*this == rhs))
        return true;
    else
        return false;
}

/**
 * Compares two rational numbers to see if one is greater than or equal to the
 * other.
 *
 * @param rhs Right-hand side operand of the comparison.
 *
 * @return true if the left-hand side operand is greater than or equal to the
 *         right-hand side operand; otherwise, false.
 ********************************************************************************/
bool Rational::operator>=(const Rational& rhs) const
{
    if (!(*this < rhs))
        return true;
    else
        return false;
}

/**
 * Compares two rational numbers for inequality.
 *
 * @param rhs Right-hand-side operand of the comparison.
 *
 * @return true if the numbers are not equal; otherwise, false.
 ********************************************************************************/
bool Rational::operator!=(const Rational& rhs) const
{
    return !(*this == rhs);
}

/**
 * Inserts the numerator and denominator of a rational number into an output
 * stream.
 *
 * @param os The output stream.
 * @param r Rational object with the content to insert.
 *
 * @return The updated output stream object.
 *
 * @note Prints the numerator and denominator separated by a '/' character.
 ********************************************************************************/
ostream& operator<<(ostream& os, const Rational& r)
{
	std::ostringstream oss;		// render into a string first so not disrupt setw() etc.

    // Print the numerator and denominator   
    oss << r.numerator << '/' << r.denominator;
	os << oss.str();

    // Return the updated output stream object
    return os;
}

/**
 * Extracts two integers from an input stream and stores them into the numerator
 * and denominator members of a Rational object.
 *
 * @param os The input stream.
 * @param r Rational object where the extracted content is stored.
 *
 * @return The updated input stream object.
 *
 * @note The integers to extract must be separated by the character '/'.
 ********************************************************************************/
istream & operator>>(istream& is, Rational& r)
{
    char ch;
   
    // Read the numerator   
    is >> r.numerator;
   
    // Read and discard '/' character
    is.get(ch);
   
    // Read the denominator
    is >> r.denominator;
   
    // Return the updated input stream object
    return is;
}
   
/**
 * Adds an integer and a rational number to produce a rational number result.
 *
 * @param lhs Left-hand side integer operand of the addition.
 * @param rhs Right-hand side rational number operand of the addition.
 *
 * @return The result of the addition.
 *
 * @note The result is reduced to its lowest terms.
 ********************************************************************************/
Rational operator+(int lhs, const Rational& rhs)
{
    // Declare a temporary object to hold the result and set it
    // equal to the right operand
    Rational result = rhs;
   
    // Perform the addition
    result.numerator += lhs * result.denominator; 
 
    // Reduce the result to its lowest terms
    int gcd = result.find_gcd(result.numerator, result.denominator);
 
    result.numerator /= gcd;
    result.denominator /= gcd;
   
    // Return the result  
    return result;   
}

