#include "matrix.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;    // This is OK here because it concerns the namespace of this file only

/*
    Matt Borek (z1951125)
    Assignment 02
    02/1/2022
    I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Checl whether the datafile is valid for use.
 * 
 * This method attempts to open a passed in file and will catch error exceptions (if any) and abort the program if necessary.
 * 
 * @param fname A reference to the datafile's filename.
 * 
 * @return Returns a filestream object comprised of the file's data for later conversion and reading.
 */
ifstream safeopen(const string &fname)
{
    ifstream f;
    try {
        f.open(fname, std::ifstream::in);
    } catch (const std::ios_base::failure &e) {
        cerr << e.code().message() << endl;
        exit(1);        // nonzero here means to the O/S that the application has failed
    }
    return f;
}
/**
 * @brief Main program execution
 * 
 * This program opens two data files for reading. If either file can't
 * be opened, it prints an error message on stderr and aborts the
 * program. It generates two input matrices from the data in data
 * files, then generates a new matrix by multiplying the numbers in
 * two input matrices. Finally, it prints all three matrices on
 * stdout.
 * 
 * The program is executed alongside several command line arguments and will abort without all four.
 * Intended command line usage: matmul file1 file2 colwidth.
 * matmul being main itself, file1 and file 2 being the filename of the first and second datafiles respectively, and the intended column width for the output file.
 * 
 * @param argc Argument Count for the total number of passed in command line arguments.
 * @param argv Argument Vector for the listing of all passed in command line arguments.
 * 
 * @return Returns 0 to close the function scope, close opened files, and end the program after compeltion.
 * 
 * @note This main has not been modified in any way except for added documentation. Some preprovided comments have been reformatted.
 */
int main(int argc, char **argv)
{
    ifstream is1;
    ifstream is2;
    int col_width;

    if (argc != 4)      // make sure we have 4 command line args
    {
        cerr << "Usage: matmul file1 file2 colwidth" << endl;
        exit(1);
    }
        
    is1 = safeopen(argv[1]);
    is2 = safeopen(argv[2]);

    istringstream iss(argv[3]);     // convert the C string to an istringstream
    iss >> col_width;               //    ...so we can do this to convert it into an int

    matrix a;
    matrix b;
    matrix c;

    a.load(is1);        // resize & deserialize
    b.load(is2);        // resize & deserialize

    c = a*b;            // the memberwise copy of std::vector in here will deep-copy themselves!

    // print contents of all matrices on stdout
    cout << "\nMatrix1: ";
    a.print(col_width);
    cout << "\nMatrix2: ";
    b.print(col_width);
    cout << "\nMatrix3: ";
    c.print(col_width);
    cout << endl;


    // Note: is1 and is2 are closed here when they go out of scope
    return 0;   // zero here tells the O/S that the application has succeeded
}
