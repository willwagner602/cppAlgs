/*********************************************************************
** Author: Will Wagner
** Date: 2/15/17
** Description: A structure for holding a matrix of ints
*********************************************************************/

#ifndef CPPALGS_MATRIX_H
#define CPPALGS_MATRIX_H


struct matrix {
public:
    int matrixCols;
    int matrixRows;
    matrix(int rows); // square matrix
    matrix(int rows, int cols); //rectangular matrix
private:
    int *values; // when you instantiate, create the matrix with int *values = new int[matrixRows * matrixCols]
                 // http://stackoverflow.com/questions/256297/best-way-to-represent-a-2-d-array-in-c-with-size-determined-at-run-time
};


#endif //CPPALGS_MATRIX_H
