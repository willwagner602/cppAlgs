/*********************************************************************
** Author: Will Wagner
** Date: 2/15/17
** Description: General algorithms for anything other than searching and sorting
*********************************************************************/

#ifndef CPPALGS_MISCALGORITHMS_H
#define CPPALGS_MISCALGORITHMS_H

#include "matrix.hpp"

class miscAlgorithms {
public:
    matrix strassenMatrixMultiplication(matrix, matrix);
    bool hireAssistant(int);
};


#endif //CPPALGS_MISCALGORITHMS_H
