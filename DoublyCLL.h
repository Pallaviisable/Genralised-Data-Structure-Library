#pragma once

////////////////////////////////////////////////////////////////////////////////////
//
//  File:              DoublyCLL.h
//  Description:       Declarations for Doubly Circular Linked List (generic)
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        DoublyCLLnode
//  Description:       Node structure for Doubly Circular Linked List
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no);
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        DOUBLYCLL
//  Description:       Doubly Circular Linked List with Insert/Delete/Display ops
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DOUBLYCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DOUBLYCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int  Count();
};

#include "DoublyCLL.tpp"
