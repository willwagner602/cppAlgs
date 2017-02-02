/*********************************************************************
** Author: Will Wagner
** Date: 1/30/17
** Description:
*********************************************************************/

#include "searchAlgs.hpp"

int searchAlgorithms::linearSearch(int target, int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }
    return -1;
}