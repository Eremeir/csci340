#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

/*
    Matt Borek (z1951125)
    Assignment 02
    02/1/2022
    I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Construct a new matrix::matrix object
 * 
 * This constructor takes in values for rows and columns and calls resize() to allocate capacity for the new two-dimentional vector matrix.
 * 
 * @param rows A value to hold the row (horizontal) position within the vector. This is the "outside" portion of the vector logic.
 * @param cols A value to hold the column (vertical) position within the vector. 
 * 
 * @note If no values are passed in, both rows and cols will be initilized as = 0.
 */
matrix::matrix(unsigned int rows, unsigned int cols)
{
    resize(rows, cols);
}

/**
 * @brief Resize the two-dimentional vector matrix.
 * 
 * This function takes in values for rows and columns and uses std::resize to allocate capacity for the two-dimentional vector matrix based on passed in values.
 * The loop resizes the outer vector to have as many rows as specified, and then resizes each of those rows, 
 * which are vectors, to each have capacity for as many columns as specified.
 * 
 * @param rows A value to hold the row (horizontal) position within the vector. This is the "outside" portion of the vector logic.
 * @param cols A value to hold the column (vertical) position within the vector. 
 * 
 * @note Alternate implimentation which forgoes for-loop: "mat.resize(rows, vector<int>(cols));"  Included for notes reference.
 */
void matrix::resize(unsigned int rows, unsigned int cols)
{
    mat.resize(rows);
    for(size_t i = 0; i < rows; i++)
    {
        mat[i].resize(cols);
    }
}

/**
 * @brief Load values from passed in datafile to the two-dimentional vector matrix.
 * 
 * This function takes in an istringstream object created from earlier processed datafiles and reads it in bit by bit to fill in each element of the matrix.
 * The first two times the file is read, values for the intended dimentions of the matrix are stored in two respective holding variables, maxRows and maxCols.
 * The loop uses i and j to indicate a sort of coordinate location and values are input at the intersection of these two values as they iterate until capacity.
 *
 * A temporary variable, temp, is used to hold the read value of the istringstream object to perserve function compatability when using matrix::at();
 * 
 * @param is istringstream object passed in by reference to be read element by element to construct the dimentions of the matrix and fill value places.
 * 
 * @note Alternate implimentation for direct access which forgoes for-loop: "mat.at(i).at(j) = temp" Included for notes reference.
 * 
 * @warning File loading requires the datafile formatting to specify the dimentions for the matrix in the first line of the file, separated by a space. 
 * Matrix values can then follow, separated by a space.
 */
void matrix::load(istream &is)
{
    int maxRows = 0;
    int maxCols = 0;
    int temp = 0;

    is >> maxRows;
    is >> maxCols;
    resize(maxRows, maxCols);

    for(int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            is >> temp;
            at(i,j) = temp;
        } 
    }
}

/**
 * @brief Print matrixes to output file.
 * 
 * This function prints out the two-dimentional matrix and correctly formats output to match provided reference formatting.
 * 
 * A loop is used to automatically adjust the length of headers and footers based on the passed in column width and the number of columns in the matrix,
 * as provided by matrix::getCols.
 * 
 * A second loop then uses i and j to indicate coordinate values for the matrix::at() function and values are printed from the intersection of these two values as they 
 * iterate until reaching maximun dimentions (based on the matrix's size), as provided by matrix::getRows and matrix::getCols.
 * 
 * @param colWidth Column Width, which is initially supplied as a command line argument and later stored in a variable which is finally passed in for this function.
 * Used to asjust the size of the output cout box by adding more spacing.
 */
void matrix::print(int colWidth) const
{   
    cout << getRows() << " x " << getCols() << endl;

    cout << "-";
    for(size_t h = 0; h < getCols(); h++)
    {
        string header(colWidth + 2, '-');
        cout << header;
    }
    
    cout << endl;
    for(size_t i = 0; i < getRows(); i++)
    {
        cout << "|";
        for(size_t j = 0; j < getCols(); j++)
        {
            cout << setw(colWidth) << at(i,j) << " |";;
        }
        cout << endl;
    }

    cout << "-";
    for(size_t k = 0; k < getCols(); k++)
    {
        string footer(colWidth + 2, '-');
        cout << footer;
    }
    cout << '\n';
}

/**
 * @brief Overloaded matrix multiplication operator.
 * 
 * This operator is overloaded to properly calculate the multiplication of two matricies. It multiplies one matrix, by the matrix to its right hand side, and returns the result.
 * cassert::assert() is used to ensure that multiplied matricies have the correct dimentions required to perform proper multiplication.
 * Proper dimentions neccesitate that the first matrix's rows are equal to the second matrix's columns.
 * A temporary matrix is initialized and resized according to the necessary size required to fit matrix multiplication dimentions. 
 * 
 * A loop then uses i,and j to populate the temporary matrix with values of 0, and then adds k to multiply both matrixes, intersection by intersection and add the result to
 * the temporary matrix's intersection, each iterating until full.
 * 
 * @param rhs The Right Hand side matrix is passed in by reference to be used in calculation.
 * @return Returns the temporary matrix's contents.
 */
matrix matrix::operator*(const matrix &rhs) const
{
    matrix temp;
    assert(getCols() == rhs.getRows());

    temp.resize(getRows(), rhs.getCols());

    for(size_t i = 0; i < getRows(); i++)
    {
        for(size_t j = 0; j < rhs.getCols(); j++)
        {
            temp.at(i,j) = 0;

            for(size_t k = 0; k < getCols(); k++)
            {
                temp.at(i, j) += at(i, k) * rhs.at(k, j);
            }
        }
    }

    return temp;
}