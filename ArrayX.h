#pragma once

////////////////////////////////////////////////////////////////////////////////////
//
//  File:              ArrayX.h
//  Description:       Declarations for Generic Array class with Sorting algorithms
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#define INC_ORDER 1
#define DEC_ORDER 2

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        ArrayX
//  Description:       Generic array class supporting Bubble, Selection, and
//                     Insertion sort with ascending/descending options
//
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class ArrayX
{
public:
    T    *Arr;
    int   iSize;
    bool  Sorted;

    ArrayX(int no);
    ~ArrayX();

    void Accept();
    void Display();
    bool CheckSorted();

    void bubbleSort();
    void bubbleSortEfficient();
    void bubbleSortEfficientX(int iOption = INC_ORDER);

    void SelectionSort();
    void InsertionSort();
};

#include "ArrayX.tpp"
