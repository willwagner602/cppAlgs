/*********************************************************************
** Author: Will Wagner
** Date: 2/22/17
** Description: tests for algorithms
*********************************************************************/

#include "catch.hpp"
#include "SearchAlgorithms.hpp"
#include "SortAlgorithms.hpp"
#include "Utilities.hpp"
#include <iostream>

using std::cout;
using std::endl;

SearchAlgorithms search = SearchAlgorithms();
SortAlgorithms sort = SortAlgorithms();

const int length = 100;
int testVals[length] = {
        8661, -22345, -31557, -22213, 11852, -13914, -17491, 18370, 30381, -31439, 15413, -1278, -19079,
        -7457, 31067, -25552, 10519, 27118, 28254, 934, -23623, 17375, -12449, 27817, -27437, -25998,
        16675, -861, -18694, -23428, -25818, 16120, 24028, 10450, -30052, 6200, -12086, 29651, -1577,
        20240, -24437, 13898, -16980, -21218, -13496, -23156, 14168, -10327, 14284, -9276, -8978, 25956,
        -3284, 13187, -9220, 7746, 3525, -9444, 13322, 5374, 23258, -13029, 20698, 14288, -9584, 11985,
        -102, 24557, -3426, 11545, 17138, -10272, 30170, 18561, 28307, 5238, -5147, -17016, -383, -13659,
        -28072, 17228, -8349, -14905, 28689, -11458, 19832, 25715, 23377, 20625, 10474, -27003, 22487,
        -30254, 8555, 5611, 5409, -25634, -12081, -30298};

TEST_CASE("Maximum subarray is computed. ", "[maxSubarray]") {

    int maxArrayShort[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    maxSubarray answer = maxSubarray(7, 10, 43);
    maxSubarray result = search.findMaxSubarray(maxArrayShort, 0, 15);
    REQUIRE( result.max == answer.max );
    REQUIRE( result.min == answer.min );
    REQUIRE( result.sum == answer.sum );
}

TEST_CASE("Array is sorted correctly by insertion sort.", "[insertionSort") {

    sort.insertionSort(testVals, length);
    for (int i = 1; i < length; i++)
    {
        REQUIRE( testVals[i] >= testVals[i - 1] );
    }
}

TEST_CASE("Array is sorted correctly by merge sort.", "[mergeSort]"){

    sort.mergeSort(testVals, 0, length - 1);
    for (int i = 1; i < length; i++)
    {
        REQUIRE( testVals[i] >= testVals[i - 1] );
    }
}

TEST_CASE("Array is sorted correctly by heap sort.", "[heapSort]") {

    sort.heapSort(testVals, length);
    for (int i = 1; i < length; i++)
    {
        REQUIRE( testVals[i] >= testVals[i - 1] );
    }
}