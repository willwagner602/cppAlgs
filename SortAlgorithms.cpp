/*********************************************************************
** Author: Will Wagner
** Date: 2/1/17
** Description:
*********************************************************************/

#include "SortAlgorithms.hpp"
#include <limits>

// utility libs for printing
#include "Utilities.hpp"
#include <iostream>

using std::cout;
using std::endl;

int MAX_INT = std::numeric_limits<int>::max();

Utilities sortUtil = Utilities();

/*********************************************************************
** Description: Insertion sort for an array of integers
**********************************************************************/
void SortAlgorithms::insertionSort(int array[], int length)
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
void SortAlgorithms::mergeSort(int array[], int start, int end)
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
void SortAlgorithms::mergeSort(int array[], int start, int middle, int end)
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
int SortAlgorithms::heapParent(int heap[], int index)
{
    return heap[heapParent(index)];
}

int SortAlgorithms::heapParent(int index)
{
    return (index + 1) / 2 - 1;
}

/*********************************************************************
** Description: get left child node of node at index on the heap
**********************************************************************/
int SortAlgorithms::heapLeftChild(int heap[], int index)
{
    return heap[heapLeftChild(index)];
}

int SortAlgorithms::heapLeftChild(int index)
{
    return 2 * (index + 1) - 1;
}

/*********************************************************************
** Description: get right child node of node at index on the heap
**********************************************************************/
int SortAlgorithms::heapRightChild(int heap[], int index)
{
    return heap[heapRightChild(index)];
}

int SortAlgorithms::heapRightChild(int index)
{
    return 2 * (index + 1);
}

/*********************************************************************
** Description: Transforms given tree in array of ints to a max heap
**              Assumes that binary trees rooted at leftChild and
**              rightChild are maxHeaps, but array[index] might be
**              smaller than its children.
**********************************************************************/
void SortAlgorithms::maxHeapify(struct heap heap, int index)
{
    int leftChild = heapLeftChild(index);
    int rightChild = heapRightChild(index);
    int largest;

    // determine whether index is correct parent of both children
    if (leftChild < heap.heapSize && heap.array[leftChild] > heap.array[index])
        largest = leftChild;
    else
        largest = index;

    if (rightChild < heap.heapSize && heap.array[rightChild] > heap.array[largest])
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
** Description: Transforms a given integer array to a max heap in place
*********************************************************************/
struct heap SortAlgorithms::buildMaxHeap(int array[], int length)
{
    // transform the array to a heap
    int heapSize = length;
    int heapLength = sortUtil.minPowerOf2(length);
    heap heap = {array, heapLength, heapSize};

    for (int i = heapLength / 2; i >= 0; i--)
    {
        maxHeapify(heap, i);
    }

    return heap;
}

/*********************************************************************
** Description: Uses the other heap methods to sort a list
*********************************************************************/
struct heap SortAlgorithms::heapSort(int array[], int length)
{
    struct heap heap = buildMaxHeap(array, length);
    for (int i = heap.heapSize - 1; i > 0; i--)
    {
        int temp = heap.array[0];
        heap.array[0] = heap.array[i];
        heap.array[i] = temp;
        heap.heapSize -= 1;
        maxHeapify(heap, 0);
    }

    return heap;
}