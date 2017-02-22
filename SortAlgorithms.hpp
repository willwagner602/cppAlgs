/*********************************************************************
** Author: Will Wagner
** Date: 2/1/17
** Description: Various sorting algorithms
*********************************************************************/
#include "heap.hpp"

#ifndef CPPALGS_SORTALGS_H
#define CPPALGS_SORTALGS_H


class SortAlgorithms {
private:

public:
    void insertionSort(int [], int);
    void mergeSort(int [], int, int);
    void mergeSort(int [], int, int, int);
    // various heap procedures
    int heapParent(int index);
    int heapParent(int [], int);
    int heapLeftChild(int index);
    int heapLeftChild(int [], int);
    int heapRightChild(int index);
    int heapRightChild(int [], int);
    void maxHeapify(heap heap, int index);
    struct heap buildMaxHeap(int array[], int length);
    struct heap heapSort(int array[], int length);
};


#endif //CPPALGS_SORTALGS_H
