#pragma once

////////////////////////////////////////////////////////////////////////////////////
//
//  File:              BST.h
//  Description:       Declarations for Generic Binary Search Tree
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        BSTNode
//  Description:       Node structure for Binary Search Tree
//
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class BSTNode
{
public:
    T data;
    BSTNode<T> *lchild;
    BSTNode<T> *rchild;

    BSTNode(T value);
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name:        BST
//  Description:       Binary Search Tree with Insert/Traversal/Search/Count ops
//
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class BST
{
private:
    BSTNode<T> *root;

    // Private recursive helpers
    void Insert(BSTNode<T>* &node, T value);
    void Inorder(BSTNode<T>* node);
    void Preorder(BSTNode<T>* node);
    void Postorder(BSTNode<T>* node);
    bool Search(BSTNode<T>* node, T value);
    int  CountNodes(BSTNode<T>* node);
    int  CountParents(BSTNode<T>* node);
    int  CountLeafs(BSTNode<T>* node);

public:
    BST();
    void Insert(T value);
    void Inorder();
    void Preorder();
    void Postorder();
    bool Search(T value);
    int  CountNodes();
    int  CountParents();
    int  CountLeafs();
};

#include "BST.tpp"
