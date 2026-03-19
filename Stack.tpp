////////////////////////////////////////////////////////////////////////////////////
//
//  File:              Stack.tpp
//  Description:       Template definitions for Generic Stack
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by Stack.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// StackNode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
StackNode<T>::StackNode(T value)
{
    data = value;
    next = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Stack (Constructor)
//  Description:       Initialises an empty stack
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
Stack<T>::Stack()
{
    top    = nullptr;
    iCount = 0;
    cout << "Stack created successfully\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     push
//  Input:             Value to push
//  Description:       Pushes element onto the top of the stack
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Stack<T>::push(T value)
{
    StackNode<T> *newNode = new StackNode<T>(value);
    newNode->next = top;
    top           = newNode;
    iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     pop
//  Output:            Value removed from the top
//  Description:       Removes and returns the top element; returns T() if empty
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
T Stack<T>::pop()
{
    if(top == nullptr)
    {
        cout << "Stack is empty\n";
        return T();     // Default value of type T
    }

    StackNode<T> *temp = top;
    T value            = top->data;
    top                = top->next;
    delete temp;
    iCount--;
    return value;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     peep
//  Output:            Value at the top (without removing it)
//  Description:       Returns the top element without modifying the stack
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
T Stack<T>::peep()
{
    if(top == nullptr)
    {
        cout << "Stack is empty\n";
        return T();     // Default value of type T
    }
    return top->data;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Display
//  Description:       Displays all stack elements from top to bottom
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Stack<T>::Display()
{
    if(top == nullptr)
    {
        cout << "Stack is empty\n";
        return;
    }

    StackNode<T> *temp = top;
    while(temp != nullptr)
    {
        cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Count
//  Output:            Number of elements currently in the stack
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
int Stack<T>::Count()
{
    return iCount;
}
