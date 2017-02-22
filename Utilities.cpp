/*********************************************************************
** Author: Will Wagner
** Date: 2/22/17
** Description:
*********************************************************************/

#include <iostream>
#include <cmath>
#include "Utilities.hpp"
#include "heap.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Description: Prints all the values of an array, by default 15 to a line
*********************************************************************/
void Utilities::printArray(int array[], int length, int lineLength)
{
    for (int i = 0; i < length ; i++)
    {
        cout << array[i] << ", ";
        if ( (i + 1) % lineLength == 0)
            cout << endl;
    }
    cout << endl;
}

/*********************************************************************
** Description: Prints all the values of a heap in their correct row position.
 *              No attempt is made at vertical alignment
*********************************************************************/
void Utilities::printHeap(struct heap heap)
{
    int countPrinted = 0;
    for (int i = 0;pow(2, i)< heap.heapSize; i++)
    {
        for (int j = 0; j < pow(2, i) && countPrinted < heap.heapSize; j++)
        {
            std::cout << heap.array[countPrinted] << ", ";
            countPrinted++;
        }
        std::cout << std::endl;
    }
}

/*********************************************************************
** Description: Calculates the minimum power of 2 larger than the given int
*********************************************************************/
int Utilities::minPowerOf2(int value)
{
    int max = 1;
    while (max < value)
    {
        max *= 2;
    }

    return max;
}