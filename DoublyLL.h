#pragma once

////////////////////////////////////////////////////////////////////////////////////
//
//  File:              DoublyLL.h
//  Description:       Declarations for Doubly Linear Linked List (generic)
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        DoublyLLnode
//  Description:       Node structure for Doubly Linear Linked List
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLLnode
{
    public:
        T data;
        DoublyLLnode<T> *next;
        DoublyLLnode<T> *prev;

        DoublyLLnode(T no);
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        DoublyLLL
//  Description:       Doubly Linear Linked List with Insert/Delete/Display ops
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLLL
{
    private:
        DoublyLLnode<T> *first;
        int iCount;

    public:
        DoublyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int  Count();
};

#include "DoublyLL.tpp"
