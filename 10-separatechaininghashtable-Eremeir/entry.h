#ifndef H_ENTRY
#define H_ENTRY

#include <string>
using namespace std;

#define ID_SZ   3   // size of key
#define ITEM_SZ 24  // max size for item description
#define TBL_SZ  31  // default size for hash table

/*
Matt Borek (z1951125)
Assignment 10
04/18/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Entry structure.
 * 
 * Facilitates the creation and operation of an entry in the hashtable.
 * 
 */
struct Entry {
  string   key;   // key
  string   desc;  // description
  unsigned num;   // no of copies

  // constructor
  Entry(const string& k = "", const string& d = "", const unsigned& n = 0) : key(k), desc(d), num(n) {}
};

#endif
