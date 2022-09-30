#include "twosearch.h"

#include <getopt.h>

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

/*
    Matt Borek (z1951125)
    Assignment 03
    02/8/2022
    I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Usage argument error message
 * 
 * see:
 * https://en.wikipedia.org/wiki/Usage_message
 * https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
 * 
 * @param a0 The value of argv[0] (the name of the command) so that it can be printed.
 * 
 * @note This function will terminate the application via exit(1).
 */
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
 * @brief Initialize Vector Values
 * 
 * Takes in presupplied seeds and range values to randomly assign integers to each index of the vector.
 * 
 * @param vec Vector, passed by reference to be populated with random values.
 * @param seed Seed for srand() to base random number generation off of.
 * @param lo Low value to represent the lower bound in the rand() calculation.
 * @param hi High value to represent the upper bound in the rand() calculation.
 */
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
    srand(seed);
    for(auto &it : vec)
    {
        it = (rand()%(hi-lo+1)+lo); //Assign random value to index of iterator.
    }
}

/**
 * @brief Print Vector Values
 * 
 * This function prints out a readable indented representation of the vector to std::cout
 * The dimentions and format of the grid is adjusted by the print_cols and col_width arguments which determine the number of columns and spacing respectively.
 * 
 * A loop is used to automatically adjust the length of headers and footers based on the passed in column width and the number of columns in the vector,
 * as provided by col_width.
 * 
 * A second loop iterates through the vector adding elements to the cout. To present the one-dimentional vector on more than one line to increase readability,
 * indentCount increments and resets every print_cols number of elements. This allows the loop to dynamically adjust when lines will be indented based on passed
 * in arguments.
 * 
 * A third loop is used to add additional formatted boxes to balance out the grid if the number of elements did not form a perfect rectangle.
 * 
 * @param v Vector, passed by reference to be accsessed and printed.
 * @param print_cols Print Columns, to be used to asjust the dimentions of the grid.
 * @param col_width Column Width, to be used to adjust the spacing of the grid output.
 */
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
    int indentCount = 0;
    int gridSetCount = 0;

    std::cout << "-"; //Header loop
    for(int h = 0; h < print_cols; h++)
    {
        std::string header(col_width + 2, '-');
        std::cout << header;
    }
    std::cout << std::endl;

    std::cout << "|";
    for(auto &it : v)
    {
        std::cout << std::setw(col_width) << it << " |";
        gridSetCount++;
        if(indentCount == print_cols - 1) //Indents the cout every certain number of elements.
        {
            std::cout << '\n' << "|";
            indentCount = 0;
            gridSetCount = 0; //Keeps track of progress towards the next indent.
        }
        else
        {
            indentCount++;
        }
    }

    for(int j = (print_cols - gridSetCount); j > 0; j--) //Checks the indent progress against how large the grid should be.
    {
        std::cout << std::setw(col_width + 2) << " |"; //Adds remaining boxes to balance out the grid.
    }

    std::cout << std::endl << "-"; //Footer loop
    for(int f = 0; f < print_cols; f++)
    {
        std::string footer(col_width + 2, '-');
        std::cout << footer;
    }
    std::cout << std::endl;
}

/**
 * @brief Sort Vector Values (Accending Order)
 * 
 * This is a simple function to sort each value of the vector into accending order, using the standard sort() keyword.
 * 
 * @param v Vector, passed in by reference to have its index sorted.
 */
void sort_vector(std::vector<int> &v)
{
    sort(v.begin(), v.end());
}

/**
 * @brief Search Vector for Value
 * 
 * This function attempts to search for each value contained in one vector through the index of another vector and keeps track
 * of how many(if any) successful results are found.
 * 
 * It dynamically calls a passed in search function, and passes in vector 2 and iterates through values of vector 1 to check for.
 * 
 * @param v1 The first vector, passed in by reference, to be used and iterated through to find values to check for.
 * @param v2 The second vector, passed in by reference, to have its index checked against the first vector.
 * @param p Pointer to a passed in function call, to be swapped between different intended search algorithims.
 * @return Retruns an integer representing the number of successful search results found from checking vector 2.
 */
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
    int succSearches = 0;
    
    for(size_t i = 0; i < v1.size(); i++) //For each value of the first vector
    {                                     //Check the second vector for the [i] element of the first vector.
        if(p(v2, v1[i]) == true) //Call to passed in fuction.
        {
            succSearches++;
        }
    }
    return succSearches;
}

/**
 * @brief Print % of Successful Searches
 * 
 * This function takes in two integers, casts them into a float, and uses them to calculate the percentage of shared
 * values between vector 1 and vector 2, lastly printing the results to std::cout.
 * 
 * @param found Found results, this value is the returned result of search_vector(). It represents the number of times a value of vector 1 was found in vector 2.
 * @param total Total number of searches in the vector searched, which is simply just the size() of vector 1.
 */
void print_stat(int found, int total)
{
    double percentSuccSearches = (static_cast<double>(found) / static_cast<double>(total))*100; //Cast to float to keep decimals.
    std::cout << std::fixed << std::setprecision(2) << "Percent of Successful Searches = " << percentSuccSearches << "%" << std::endl; 
} //Sets precision to 2 and fixed to keep standard formatting.

/**
 * @brief Perform a Linear Search through vector for value.
 * 
 * This function, like binary_search() is called within search_vector() to iterate through the values of a vector checking each index for a supplied value.
 * This algorithim checks each element one by one using find(), in order until the specified value is found, or not and returns true or false depending.
 * 
 * @param v Vector 2, passed in by reference, to be iterated through looking for the specified value.
 * @param x Specified value X, to be compared against the vector checking whether it is comtained in the vector.
 * @return Returns true if the find() comparrison reports that the specified value was found in the vector.
 * @return Returns false if the find() comparrison fails to find the value within the vector by reaching the end of iteration.
 */
bool linear_search(const std::vector<int> &v, int x)
{   
    if(find(v.begin(), v.end(), x) != v.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** 
 * @brief Perform a Binary Search through vector for value.
 * 
 * This function, like linear_search() is called within search_vector() to iterate through the values of a vector checking each index for a supplied value.
 * This algorithim is intended to work on sorted elements, and compares the specified value agaisnt the middle element of the vector, cutting the remaining workload in half
 * until the value is found or the vector is exhausted of elements.
 * 
 * @param v Vector 2, passed in by reference, to be iterated through looking for the specified value.
 * @param x Specified value X, to be compared against the vector checking whether it is comtained in the vector.
 * @return Returns true if the binary search reports that the specified value was found in the vector.
 * @return Returns false if the binary search fails to find the value within the vector by reaching the end of iteration.
 */
bool binary_search(const std::vector<int> &v, int x)
{
    if(binary_search(v.begin(), v.end(), x))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** 
 * @brief main program execution
 * 
 * Parse the command-line args, create and sort vector A, create vector B,
 * search vector A for those elements appearing in vector B using both
 * a linear and binary search, and print the hit-rate (the percentage of 
 * items in B that have been located in A.)
 *
 * If an invalid command-line arg is encountered, print a Usage statement 
 * and terminte with an exit-status of 1.
 *
 * @return zero to signal end of program execution.
 ******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt =  getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1) //Switchcase parser for command-line arguments
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;
            
        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...

    std::vector<int> A(a_size); //Create A vector
    std::vector<int> B(b_size); //Create B vector
    init_vector(A, a_seed, rand_low, rand_high); //Seed A vector values
    init_vector(B, b_seed, rand_low, rand_high); //Seed B vector values

    std::cout << "A vector:" << std::endl;
    print_vector(A, print_cols, col_width); //Print A vector

    sort_vector(A); //Sort A vector
    std::cout << "A vector sorted:" << std::endl;
    print_vector(A, print_cols, col_width); //Print A vector sorted

    std::cout << "B vector:" << std::endl;
    print_vector(B, print_cols, col_width); //Print B vector

    std::cout << "Linear Search: "; //Perform Linear Search
    print_stat(search_vector(B, A, linear_search), B.size());

    std::cout << "Binary Search: "; //Perform Binary Search
    print_stat(search_vector(B, A, binary_search), B.size());

    return 0;

} // End of main()
