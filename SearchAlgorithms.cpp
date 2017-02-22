/*********************************************************************
** Author: Will Wagner
** Date: 1/30/17
** Description: A selection of search algorithms
*********************************************************************/

#include "SearchAlgorithms.hpp"
#include <limits>
#include <iostream>

int MIN_INT = std::numeric_limits<int>::min();

/*********************************************************************
** Description: A basic linear such function
*********************************************************************/
int SearchAlgorithms::linearSearch(int target, int array[], int length)
{
    // starting at beginning of array, iterate through whole array until
    // target int is found
    for (int i = 0; i < length; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }
    // if it's not found, return impossible value
    return -1;
}

/*********************************************************************
** Description: A maximum subarray search for integers
*********************************************************************/
maxSubarray SearchAlgorithms::findMaxSubarray(int *array, int low, int high)
{
    if (high <= low)
        return maxSubarray(high, low, array[low]); // base case, only one element
    else
    {
        int mid = low + (high - low) / 2; // automatically floors because of int division
        maxSubarray leftSubarray = findMaxSubarray(array, low, mid);
        maxSubarray rightSubarray = findMaxSubarray(array, mid + 1, high);
        maxSubarray crossingSubarray = findMaxCrossingSubarray(array, low, mid, high);

        if (leftSubarray.sum >= rightSubarray.sum && leftSubarray.sum >= crossingSubarray.sum)
            return leftSubarray;
        else if (rightSubarray.sum >= leftSubarray.sum && rightSubarray.sum >= crossingSubarray.sum)
            return rightSubarray;
        else
            return crossingSubarray;
    }
}

maxSubarray SearchAlgorithms::findMaxCrossingSubarray(int *array, int low, int mid, int high)
{
    int maxLeft = mid;
    int maxRight = mid;

    int leftSum = MIN_INT;
    int rightSum = MIN_INT;

    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += array[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += array[j];
        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = j;
        }
    }

    return maxSubarray(maxLeft, maxRight, leftSum + rightSum);
}