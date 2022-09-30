#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

/*
Matt Borek (z1951125)
Assignment 09
04/11/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

using namespace std;

#ifndef H_BST
#define H_BST

#define SEED 1      // seed for RNG
#define N 100       // num of rand ints

#define NO_ITEMS 16 // max num of elems printed in line
#define ITEM_W 3    // size of each elem in print

unsigned sz;        // size of vector/binTree

// macro to print size
#define COUT_SZ cout << "size = " << setw ( ITEM_W ) << sz << " :"

/**
 * @brief Class to generate random ints.
 * 
 */
class RND {
private:
    int seed;   
public:
    RND ( const int& s = SEED ) : seed ( s ) { srand ( seed ); }
    int operator ( ) ( ) { return rand ( ) % N + 1; }
};

/**
 * @brief Print elements.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param x Curent value to be printed. 
 */
template < typename T > void print ( const T& x )
{
    static unsigned cnt = 0;
    const string sp ( 12, ' ' );

    cout << setw ( ITEM_W ) << x << ' '; cnt++;
    if ( cnt % NO_ITEMS == 0 || cnt == sz ) cout << endl << sp;
    if ( cnt == sz ) cnt = 0;
}

#endif // End of BST_H_
