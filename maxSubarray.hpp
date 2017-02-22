/*********************************************************************
** Author: Will Wagner
** Date: 2/12/17
** Description: A struct containing the start and end values of a
**              maximum subarray
*********************************************************************/

#ifndef CPPALGS_MAXSUBARRAY_H
#define CPPALGS_MAXSUBARRAY_H

struct maxSubarray
{
    maxSubarray(int, int, int);
    int min;
    int max;
    int sum;
};

#endif // CPPALGS_MAXSUBARRAY_H