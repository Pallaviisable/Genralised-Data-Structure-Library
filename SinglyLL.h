#pragma once

////////////////////////////////////////////////////////////////////////////////////
//
//  File:              SinglyLL.h
//  Description:       Declarations for Singly Linear Linked List (generic)
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        SinglyLLLnode
//  Description:       Node structure for Singly Linear Linked List
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no);
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        SinglyLLL
//  Description:       Singly Linear Linked List with Insert/Delete/Display ops
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T> *first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int  Count();
};

// Include template definitions
#include "SinglyLL.tpp"
