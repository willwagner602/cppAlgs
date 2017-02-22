/*********************************************************************
** Author: Will Wagner
** Date: 2/12/17
** Description: A struct containing the start and end values of a
**              maximum subarray
*********************************************************************/

#include "maxSubarray.hpp"

maxSubarray::maxSubarray(int minIn, int maxIn, int sumIn)
{
    min = minIn;
    max = maxIn;
    sum = sumIn;
}