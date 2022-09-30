#ifndef H_MATRIX_MULTIPLY
#define H_MATRIX_MULTIPLY

#include <istream>
#include <vector>

// NOTE: Do not pollute every #includer's namespace by putting 'using' statements in header files!

/*
    Matt Borek (z1951125)
    Assignment 02
    02/1/2022
    I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief This class is built to create a two-dimentional matrix of vectors and perform matrix multiplication.
 * 
 * The matrix class reads input data from two .dat files and loads each file's contents into a seperate matrix.
 * Each matrix is automatically resized correctly based on the first line of the .dat file which contains the intended matrix dimentions and is then populated
 * row by column into the matrix. The program then checks each input matrix to verify they are compatible for matrix multiplication and if valid, creates, resizes, 
 * and populates a third matrix with the result of this calculation.
 * After all matrixes are filled, the program will print out each matrix in a readable format to an output file.
 * 
 * @note This class has not been modified in any way except for added documentation. Some preprovided comments have been reformatted.
 * 
 * @note Some methods have been defined in a seperate file (matrix.cc) and will be further documented there to prevent redundency.
 * 
 */

class matrix
{
public:
    matrix(unsigned int rows=0, unsigned int cols=0);
    void resize(unsigned int rows, unsigned int cols);
    void load(std::istream &is);
    void print(int colWidth) const;


    // Implement both a const and non-const version of at() so can use in 
    // different contexts such as an rvalue or lvalue.

    /**
     * @brief Overloaded constant at() to read vector data.
     * 
     * This method is an overloaded version of std:at() to properly allow the function to work with a two-dimentional matrix by allowing input in a format similar to coordinates.
     * This additionally helps disconnect functions from directly accessing the mat vector values when not necessary.
     * This function has two variants, and this first one is written as constant to allow const functions to use it within their code without accidentally altering data.
     * 
     * @param row A value to hold the row (horizontal) position within the vector. This is the "outside" portion of the vector logic.
     * @param col A value to hold the column (vertical) position within the vector.
     * 
     * @return Returns a constant reference to the value held at the intersection of the passed in arguments.
     * 
     * @note note that mat[row] returns a reference to the col vector
     */
    const int & at(unsigned int row, unsigned int col) const
    {
        return mat[row][col];
    }

    /**
     * @brief Overloaded at() to read and write vector data.
     * 
     * This method is an overloaded version of std:at() to properly allow the function to work with a two-dimentional matrix by allowing input in a format similar to coordinates.
     * This additionally helps disconnect functions from directly accessing the mat vector values when not necessary.
     * This function has two variants, and this second one is written normally to allow functions which use it to alter the mat vector values.
     * 
     * @param row A value to hold the row (horizontal) position within the vector. This is the "outside" portion of the vector logic.
     * @param col A value to hold the column (vertical) position within the vector.
     * 
     * @return Returns a reference to the value held at the intersection of the passed in arguments.
     * 
     * @note note that mat[row] returns a reference to the col vector
     */
    int & at(unsigned int row, unsigned int col)
    {
        return mat[row][col];
    }

    matrix operator*(const matrix&) const;  // see CSCI 241 rational.cpp example

    
    /**
     * @brief Get the Rows value.
     * 
     * This is a standard getter method to check the size of the outer rows vector. This makes it convenient to work around the dimentions of each matrix without
     * needing direct access to the mat vector or having passed in copies of the row and col values.
     * 
     * @return Returns the size of the outer row vector.
     * 
     * @note the number of roiws is the number of column vectors! (sic)
     */
    unsigned int getRows() const { return mat.size(); }

    /**
     * @brief Get the Cols value.
     * 
     * This is a standard getter method to check the size of the inner columns vector. This makes it convenient to work around the dimentions of each matrix without
     * needing direct access to the mat vector or having passed in copies of the row and col values. There is added error avoidance by skipping this check if there
     * are no rows to hold columns.
     * 
     * @return Returns the size of the inner row vector.
     * 
     * @note Note that if have 0 rows then we have no col vectors to ask about their size!
     */
    unsigned int getCols() const { return (getRows()==0? 0 : mat[0].size()); }

private:

    // can't use vector<vector<int> > A(nrows, vector<int>(ncols)) notation because might 
    // not know the dimension when constructed.
    /**
     * @brief Two-dimentional vector matrix "mat".
     * 
     * The vector is built two dimentionally by creating an "outer" vector which contains another inner vector.
     */
    std::vector<std::vector<int>> mat;      // rows is the outer vector. be careful with the >>
};

#endif
