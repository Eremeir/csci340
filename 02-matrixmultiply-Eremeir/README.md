### CSCI 340 - Data Structures and Algorithm Analysis

Data Structure: Vector 
Programming Focus: Use of STL vector and review of C++

# Matrix Multiplication

For this computer assignment, you are to write and implement a C++ program to implement the matrix multiplication on randomly generated integers stored in data files.

Put the implementations of your matrix methods (described below) in a source file **matrix.cc**. 
**NOTE:** You will need to create this file and you will need to do a `git add matrix.cc`, after you create 
it in order to add it to your local repository. (It will later be added to your GitHub repostority after you 
do a `git commit` and `git push`.)
**NOTE:** Initially, the repository will not compile to an executable because of the missing methods that you are to implement.

- `matrix::matrix(unsigned int rows, unsigned int cols)`

  Initialize the matrix class as needed and use `resize()` to initialize the matrix size using `rows` and `cols`.

- `void matrix::resize(unsigned int rows, unsigned int cols)`

  Resize the `mat` vector to have `rows` elements and then resize each of those elements (which are vectors themselves) to have `cols` elements.

- `void matrix::load(istream &is)`

  Read the input values from the given input stream `is` and store them into the two-dimensional matrix `mat` by using the `matrix::at()` accessor. The number of rows and columns are the pair of values given at the beginning of the data file.  This will use the `resize()` method to dimension the matrix with the proper number of rows and columns and then set the values of the matrix one at-a-time by using the extraction operator `>>` and the `matrix::at()` accessor.

- `void matrix::print(int colWidth) const`

  Print the heading as seen in the reference output, a properly sized header line, the values of the matrix elements with vertical lines between each one, and a properly sized footer line.  Note that there is one space added after each value thus making the width of the inside of each of the value boxes in the printed table a total of `colWidth+1` characters wide.

  The number of values printed on each line is the number of columns in the matrix.  The number of rows of values in the output is the number of rows in the matrix.

- `matrix matrix::operator*(const matrix &rhs) const`

  Implement matrix multiplication using an overloaded operator. Recall that in the expression `x = y * z;` that the `x` is the value returned from this function, `y` is the object instance whose `operator*()` method has been called, and `z` is the `rhs` (right-hand-side of the operator.)  You will need to create a local `matrix` variable to use while calculating the product and return it by value.

  Use `assert()` to make certain that the two matrices have compatible dimensions for multiplication.

  Only use the `at(x,y)` accessor to get and set the elements of the `mat` member variable.  For example, given an instance of `matrix` called `M`, use `M.at(i,j)` to refer to the element on row `i` and column `j` where `i = 0, 1, ..., M.getRows()-1` and `j = 0, 1, ..., M.getCols()-1`.

  Multiplication of two matrices ` C = A * b` can therefore be described as performing the following for each `i` and `j`:
  
    If `C.at(i, j)` is the value of `C` in row `i` and column `j` of `C`, then `C.at(i, j) += A.at(i, k) * B.at(k, j)` for all index values of `k`.

  See (https://en.wikipedia.org/wiki/Matrix_multiplication) for a discussion on how to multiply two matrices and the need for compatible dimensions.
  

**Programming Notes:**

- Never directly access the `mat` vector values in any of the methods (other than those in the `at()` accessor methods.)

  Read and write the values of `mat` by using `at(x,y)` where `x` is the row and `y` is the column.

- Do not change any existing code implementation in `main.cc` or `matrix.h`. But you need to fully document them.

- Correct output is found in `matrix.refout-11` and `matrix.refout-6` based the matrix values in data files `matrix01.dat` and `matrix02.dat` and when running with the `colWidth` value set to `6` and `11` respectively. These are just examples. They can be changed, so do not design your program for the specific values in the data files. Your program is supposed to work for any matrix dimensions and values in those files (provided that the two are dimensionally compatible for multiplication.)

- You are not allowed to use any I/O functions from the C library, such as `scanf` or `printf`. Instead, use the I/O functions from the C++ library, such as `cin` or `cout`.

- Add documentation to the appropriate your source files as discussed in lecture.

- We have included a `Makefile` for your reference, in future assignments you will need to build your own. To compile your code just type `make` in the project directory. 

  The reference output has been generated as follows:

```
    ./matrix matrix01.dat matrix02.dat 6 > matrix.refout-6
    ./matrix matrix01.dat matrix02.dat 11 > matrix.refout-11
```

  To test your program, execute `./matrix matrix01.dat matrix02.dat 6 &> mymatrix6.out`, which will put the output (including any error messages) in file `mymatrix6.out`. You can find the correct output of this program in file `matrix.refout-6`. You can compare the two files by using `diff` on turing or hopper, `diff matrix.refout-6 mymatrix6.out`. If the files are exactly the same then there will be no output from `diff`.

When your program is ready for grading, ***commit*** and ***push*** your local repository to your remote git classroom repository and follow the _**Assignment Submission Instructions**_.
