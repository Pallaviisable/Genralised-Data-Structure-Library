////////////////////////////////////////////////////////////////////////////////////
//
//  File:              Queue.tpp
//  Description:       Template definitions for Generic Queue
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by Queue.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// QueueNode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
QueueNode<T>::QueueNode(T value)
{
    data = value;
    next = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Queue (Constructor)
//  Description:       Initialises an empty queue
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
Queue<T>::Queue()
{
    first  = nullptr;
    last   = nullptr;
    iCount = 0;
    cout << "Queue created successfully\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     enqueue
//  Input:             Value to insert
//  Description:       Inserts element at the rear of the queue
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Queue<T>::enqueue(T value)
{
    QueueNode<T> *newNode = new QueueNode<T>(value);

    if(first == nullptr)    // Empty queue
    {
        first = last = newNode;
    }
    else
    {
        last->next = newNode;
        last       = newNode;
    }
    iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     dequeue
//  Output:            Value removed from the front of the queue
//  Description:       Removes and returns the front element; returns T() if empty
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
T Queue<T>::dequeue()
{
    if(first == nullptr)
    {
        cout << "Queue is empty\n";
        return T();     // Default value for generic type
    }

    QueueNode<T> *temp = first;
    T value            = first->data;
    first              = first->next;

    if(first == nullptr)    // Queue became empty after removal
        last = nullptr;

    delete temp;
    iCount--;
    return value;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Display
//  Description:       Displays all elements from front to rear
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Queue<T>::Display()
{
    if(first == nullptr)
    {
        cout << "Queue is empty\n";
        return;
    }

    QueueNode<T> *temp = first;
    while(temp != nullptr)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Count
//  Output:            Number of elements currently in the queue
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
int Queue<T>::Count()
{
    return iCount;
}
