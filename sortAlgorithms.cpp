/*********************************************************************
** Author: Will Wagner
** Date: 2/1/17
** Description:
*********************************************************************/

#include "sortAlgorithms.hpp"
#include <limits>

// utility libs for printing
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

int MAX_INT = std::numeric_limits<int>::max();

void printArray(int array[], int length)
{
    for (int i = 0; i < length ; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

void printHeap(struct heap heap, int length)
{
    int countPrinted = 0;
    for (int i = 0;pow(2, i)< length; i++) // the number of items to be printed
    {
        for (int j = 0; j < pow(2, i) && countPrinted < length; j++)
        {
            std::cout << heap.array[countPrinted] << ", ";
            countPrinted++;
        }
        std::cout << std::endl;
    }
}

int minPowerOf2(int value)
{
    int max = 1;
    while (max < value)
    {
        max *= 2;
    }

    return max;
}

/*********************************************************************
** Description: Insertion sort for an array of integers
**********************************************************************/
void sortAlgorithms::insertionSort(int array[], int length)
{
    for (int j = 1; j < length; j++)
    {
        int key = array[j];
        int i = j - 1;
        while (i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i -= 1;
        }
        array[i + 1] = key;
    }
}


/*********************************************************************
** Description: Merge sort for an array of integers
**********************************************************************/
void sortAlgorithms::mergeSort(int array[], int start, int end)
{
    // identify the ends and midpoint of the array

    if (end - start > 0)
    {
        int middle = (start + end) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        mergeSort(array, start, middle, end);
    }
}

/*********************************************************************
** Description: The actual sort in merge sort
**********************************************************************/
void sortAlgorithms::mergeSort(int array[], int start, int middle, int end)
{
    // identify the lengths of the two zero-indexed subarrays to merge,
    // with an additional flag value at the end of each
    // number of elements is subEnd - subStart + 1
    int lengthSub1 = middle - start + 1; //
    int lengthSub2 = end - middle; //

    // declare and fill the two subarrays
    int firstHalf[lengthSub1];
    int secondHalf[lengthSub2];

    for (int i = 0; i < lengthSub1; i++)
    {
         firstHalf[i] = array[start + i];
    }
    for (int j = 0; j < lengthSub2; j++)
    {
        secondHalf[j] = array[start + j + lengthSub1];
    }

    // flag last item in each subarray
    firstHalf[lengthSub1] = MAX_INT; // number of elements because 0 indexed
    secondHalf[lengthSub2] = MAX_INT;

    // iterate over the full length of the array
    int firstHalfIndex = 0, secondHalfIndex = 0;
    for (int k = start; k <= end; k++)
    {
        int firstHalfValue = firstHalf[firstHalfIndex];
        int secondHalfValue = secondHalf[secondHalfIndex];

        if (firstHalfValue <= secondHalfValue)
        {
            array[k] = firstHalfValue;
            firstHalfIndex += 1;
        }
        else
        {
            array[k] = secondHalfValue;
            secondHalfIndex += 1;
        }
    }
}

/*********************************************************************
** Heap Functions: Providing an array and an index returns the value
**                 for the relative index. Just an index returns the
**                 relative index.
**********************************************************************/

/*********************************************************************
** Description: Get the parent node of node at index on the heap
**********************************************************************/
int sortAlgorithms::heapParent(int heap[], int index)
{
    return heap[heapParent(index)];
}

int sortAlgorithms::heapParent(int index)
{
    return (index + 1) / 2 - 1;
}

/*********************************************************************
** Description: get left child node of node at index on the heap
**********************************************************************/
int sortAlgorithms::heapLeftChild(int heap[], int index)
{
    return heap[heapLeftChild(index)];
}

int sortAlgorithms::heapLeftChild(int index)
{
    return 2 * (index + 1) - 1;
}

/*********************************************************************
** Description: get right child node of node at index on the heap
**********************************************************************/
int sortAlgorithms::heapRightChild(int heap[], int index)
{
    return heap[heapRightChild(index)];
}

int sortAlgorithms::heapRightChild(int index)
{
    return 2 * (index + 1);
}

/*********************************************************************
** Description: Transforms given tree in array of ints to a max heap
**              Assumes that binary trees rooted at leftChild and
**              rightChild are maxHeaps, but array[index] might be
**              smaller than its children.
**********************************************************************/
void sortAlgorithms::maxHeapify(struct heap heap, int index)
{
    int leftChild = heapLeftChild(index);
    int rightChild = heapRightChild(index);
    int largest;

    // determine whether index is correct parent of both children
    if (leftChild <= heap.heapSize && heap.array[leftChild] > heap.array[index])
        largest = leftChild;
    else
        largest = index;

    if (rightChild <= heap.heapSize && heap.array[rightChild] > heap.array[largest])
        largest = rightChild;

    // if either child is bigger, switch it and index and then
    if (largest != index)
    {
        int largestValue = heap.array[largest];
        heap.array[largest] = heap.array[index];
        heap.array[index] = largestValue;
        maxHeapify(heap, largest);
    }
}

/*********************************************************************
** Description: Transforms a given integer array to a max heap
*********************************************************************/
struct heap sortAlgorithms::buildMaxHeap(int array[], int length)
{
    // transform the array to a heap
    int heapSize = length;
    int heapLength = minPowerOf2(length);
    heap heap = {array, heapLength, heapSize};

    for (int i = heapLength / 2; i >= 0; i--)
    {
        std::cout << "Max heapifying " << i << std::endl;
        printArray(array, length);
        maxHeapify(heap, i);
    }

    return heap;
}