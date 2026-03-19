////////////////////////////////////////////////////////////////////////////////////
//
//  File:              main.cpp
//  Description:       Driver / demo for the Generalised Data Structure Library
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Compile:           g++ -std=c++17 main.cpp -o DSLibrary
//
////////////////////////////////////////////////////////////////////////////////////

#include "SinglyLL.h"
#include "SinglyCLL.h"
#include "DoublyLL.h"
#include "DoublyCLL.h"
#include "BST.h"
#include "Queue.h"
#include "Stack.h"
#include "ArrayX.h"

int main()
{
    ////////////////////////////////////////////////////////////////////////////
    // Singly Linear Linked List
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Singly Linear Linked List ===\n";
    SinglyLLL<int> sll;

    sll.InsertFirst(30);
    sll.InsertFirst(20);
    sll.InsertFirst(10);
    sll.InsertLast(40);
    sll.InsertAtPos(25, 3);     // Insert 25 at position 3

    cout << "Linked List: ";
    sll.Display();
    cout << "Count: " << sll.Count() << "\n";

    sll.DeleteFirst();
    sll.DeleteLast();
    sll.DeleteAtPos(2);

    cout << "After Deletions: ";
    sll.Display();
    cout << "Count: " << sll.Count() << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Singly Circular Linked List
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Singly Circular Linked List ===\n";
    SinglyCLL<int> scll;

    scll.InsertFirst(30);
    scll.InsertFirst(20);
    scll.InsertFirst(10);
    scll.InsertLast(40);
    scll.InsertAtPos(25, 3);

    cout << "Circular Linked List: ";
    scll.Display();
    cout << "Count: " << scll.Count() << "\n";

    scll.DeleteFirst();
    scll.DeleteLast();
    scll.DeleteAtPos(2);

    cout << "After Deletions: ";
    scll.Display();
    cout << "Count: " << scll.Count() << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Doubly Linear Linked List
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Doubly Linear Linked List ===\n";
    DoublyLLL<int> dll;

    dll.InsertFirst(30);
    dll.InsertFirst(20);
    dll.InsertFirst(10);
    dll.InsertLast(40);
    dll.InsertAtPos(25, 3);

    cout << "Doubly Linked List: ";
    dll.Display();
    cout << "Count: " << dll.Count() << "\n";

    dll.DeleteFirst();
    dll.DeleteLast();
    dll.DeleteAtPos(2);

    cout << "After Deletions: ";
    dll.Display();
    cout << "Count: " << dll.Count() << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Doubly Circular Linked List
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Doubly Circular Linked List ===\n";
    DOUBLYCLL<int> dcll;

    dcll.InsertFirst(30);
    dcll.InsertFirst(20);
    dcll.InsertFirst(10);
    dcll.InsertLast(40);
    dcll.InsertAtPos(25, 3);

    cout << "Doubly Circular List: ";
    dcll.Display();
    cout << "Count: " << dcll.Count() << "\n";

    dcll.DeleteFirst();
    dcll.DeleteLast();
    dcll.DeleteAtPos(2);

    cout << "After Deletions: ";
    dcll.Display();
    cout << "Count: " << dcll.Count() << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Binary Search Tree
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Binary Search Tree ===\n";
    BST<int> tree;

    tree.Insert(21);
    tree.Insert(11);
    tree.Insert(51);
    tree.Insert(67);
    tree.Insert(40);
    tree.Insert(10);
    tree.Insert(13);
    tree.Insert(38);

    cout << "Inorder Traversal:  ";
    tree.Inorder();

    cout << "Preorder Traversal: ";
    tree.Preorder();

    cout << "Postorder Traversal:";
    tree.Postorder();

    int searchVal = 38;
    if(tree.Search(searchVal))
        cout << "Element " << searchVal << " is present\n";
    else
        cout << "Element " << searchVal << " is not present\n";

    cout << "Total Nodes:  " << tree.CountNodes()   << "\n";
    cout << "Parent Nodes: " << tree.CountParents() << "\n";
    cout << "Leaf Nodes:   " << tree.CountLeafs()   << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Queue
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Queue ===\n";
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.Display();

    int removed = q.dequeue();
    cout << "Removed element: " << removed << "\n";

    cout << "Queue after dequeue: ";
    q.Display();
    cout << "Total elements: " << q.Count() << "\n";

    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue after adding more elements: ";
    q.Display();
    cout << "Total elements now: " << q.Count() << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Stack
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Stack ===\n";
    Stack<char> s;

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');

    cout << "Stack elements:\n";
    s.Display();
    cout << "Number of elements: " << s.Count() << "\n";

    cout << "Top element (peep): " << s.peep() << "\n";

    cout << "Popped element: " << s.pop() << "\n";
    s.Display();
    cout << "Number of elements: " << s.Count() << "\n";

    s.push('E');
    cout << "Stack after pushing 'E':\n";
    s.Display();
    cout << "Number of elements: " << s.Count() << "\n\n";

    ////////////////////////////////////////////////////////////////////////////
    // Sorting (ArrayX)
    ////////////////////////////////////////////////////////////////////////////
    cout << "=== Sorting ===\n";

    int iValue = 0;
    cout << "Enter the Number of Elements: ";
    cin >> iValue;

    ArrayX<int> aobj(iValue);

    aobj.Accept();
    cout << "Data before Sorting\n";
    aobj.Display();

    if(aobj.CheckSorted())
        cout << "Array is already sorted\n";
    else
        cout << "Array is not sorted\n";

    // Uncomment one sort method as needed:
    // aobj.bubbleSort();
    // aobj.bubbleSortEfficient();
    // aobj.bubbleSortEfficientX(DEC_ORDER);
    // aobj.SelectionSort();
    aobj.InsertionSort();

    cout << "Data after Sorting\n";
    aobj.Display();

    return 0;
}
