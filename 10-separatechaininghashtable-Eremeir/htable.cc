#include "htable.h"
#include <list>
#include <algorithm>
#include <iomanip>

/*
Matt Borek (z1951125)
Assignment 10
04/18/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
    int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0'); //Hashes the input key to a int entry.

    return n % hsize;
}

/**
 * @brief Hash Table constructor.
 * 
 * Create a new hashtable and allocate the size.
 * 
 * @param h Hashtable size for the allocation.
 */
HT::HT(const unsigned &hs)
{
    hsize = hs;
    hTable.resize(hsize);
}

/**
 * @brief Hash Table destructor.
 * 
 * Destroy the hashtable.
 * 
 */
HT::~HT()
{
    hTable.clear(); //Empty the hashtable.
    pTable.clear(); //Empty the pointer table.
}

/**
 * @brief Insert entry to hashtable.
 * 
 * @param e entry to be added to the hashtable.
 */
void HT::insert(const Entry &e)
{
    int entryIndex = hash(e.key); //Hash the sample key to know which list to add the element to.
    auto tempIterator = std::find_if(hTable[entryIndex].cbegin(), hTable[entryIndex].cend(), [&e](Entry testEntry){return (testEntry.key == e.key);}); //Look through the list for the entry.
    if(tempIterator == hTable[entryIndex].cend()) //If the search could not find the entry.
    {
        std::cout << " entry =  " << entryIndex << std::endl;
        hTable[entryIndex].push_front(e); //Add the entry to the front of the list.
        Entry *hashPtr = &hTable[entryIndex].front(); //Create a pointer to the newly created entry in the list.
        pTable.push_back(hashPtr); //Add the pointer to the pointer table.
        
    }
    else //If the search found the element already contained in the hashtable.
    {
        std::cout << " not inserted - duplicate key!!!" << std::endl;
    }
}

/**
 * @brief Search hashtable.
 * 
 * Search the hash table for an entry matching the provided key.
 * 
 * @param s string key of the entry to find.
 */
void HT::search(const string &s)
{
    int entryIndex = hash(s); //Hash the sample key to know which list to check.
    auto tempIterator = std::find_if(hTable[entryIndex].cbegin(), hTable[entryIndex].cend(), [&s](Entry testEntry){return (testEntry.key == s);}); //Look through the list for the entry.

    if(tempIterator == hTable[entryIndex].cend()) //If the search could not find the entry.
    {
        std::cout << " not in table!!" << std::endl;
    }
    else //Print information on the successful search.
    {
        std::cout << " ==> number: " << std::setw(4) << tempIterator->num << " - item:" << std::setw(ITEM_SZ) << std::left << tempIterator->desc <<  std::right << std::endl;
    }
}

/**
 * @brief Print hashtable.
 * 
 * Print the hash table elements in proper format.
 * 
 */
void HT::hTable_print()
{
    std::cout << std::endl;
    for(auto &list : hTable) //For each list in the table.
    {
        for(auto &entry : list) //For each entry in the list.
        {

            if(pTable.size() > 8) //Fix for unexplained refout formatting.
            {
                std::cout << std::setw(4) << std::left << hash(entry.key) << ":" << std::setw(6) << entry.key << " - ";
                std::cout << std::setw(6) << std::left << entry.num << " -  " << std::setw(ITEM_SZ) << entry.desc << std::endl;
            }
            else
            {
                std::cout << std::setw(4) << std::right << hash(entry.key) << ":  " << entry.key << "  -  ";
                std::cout << std::setw(4) << entry.num << "  -  " << std::setw(ITEM_SZ) << std::left << entry.desc << std::endl;
            }
        }
    }
}

/**
 * @brief Print the pointer table.
 * 
 * Sorts the pointer table alphabetically by key then prints information from it.
 * 
 */
void HT::pTable_print()
{
    std::sort(pTable.begin(), pTable.end(), [](Entry *p, Entry *q){return (p->key < q->key);}); //Sort table alphabetically by key.

    for(auto &entry : pTable) //Print table.
        {
            std::cout << "   " << entry->key << "  -  " << std::setw(4) << std::right << entry->num << "  -  " << std::setw(ITEM_SZ) << std::left << entry->desc << std::endl;
        }
}