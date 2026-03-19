#pragma once

////////////////////////////////////////////////////////////////////////////////////
//
//  File:              SinglyCLL.h
//  Description:       Declarations for Singly Circular Linked List (generic)
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        SinglyCLLnode
//  Description:       Node structure for Singly Circular Linked List
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no);
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        SinglyCLL
//  Description:       Singly Circular Linked List with Insert/Delete/Display ops
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int  Count();
};

#include "SinglyCLL.tpp"
