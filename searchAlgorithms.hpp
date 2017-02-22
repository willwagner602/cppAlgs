/*********************************************************************
** Author: Will Wagner
** Date: 1/30/17
** Description: A collection of search algorithms
*********************************************************************/

#ifndef CPPALGS_ALGORITHMS_H
#define CPPALGS_ALGORITHMS_H

#include "maxSubarray.hpp"

/*********************************************************************
** Description: Various search algorithms
*********************************************************************/
class searchAlgorithms {
private:

public:
    int linearSearch(int target, int array[], int length);
    maxSubarray findMaxSubarray(int *array, int low, int high);
    maxSubarray findMaxCrossingSubarray(int array[], int low, int mid, int high);
};

#endif //CPPALGS_ALGORITHMS_H
