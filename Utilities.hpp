/*********************************************************************
** Author: Will Wagner
** Date: 2/22/17
** Description: A collection of useful utilities for introspecting
 *              and debugging algorithms
*********************************************************************/

#ifndef CPPALGS_UTILITIES_HPP
#define CPPALGS_UTILITIES_HPP

class Utilities {
public:
    void printArray(int array[], int length, int lineLength=15);
    void printHeap(struct heap);
    int minPowerOf2(int);
};


#endif //CPPALGS_UTILITIES_HPP
