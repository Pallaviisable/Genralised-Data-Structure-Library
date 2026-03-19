////////////////////////////////////////////////////////////////////////////////////
//
//  File:              DoublyLL.tpp
//  Description:       Template definitions for Doubly Linear Linked List
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by DoublyLL.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// DoublyLLnode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLnode<T>::DoublyLLnode(T no)
{
    this->data = no;
    this->next = NULL;
    this->prev = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DoublyLLL (Constructor)
//  Description:       Initialises first pointer to NULL and count to 0
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Object of DoublyLLL gets created.\n";
    this->first  = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertFirst
//  Input:             Data of new node
//  Description:       Inserts a node at the first position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLnode<T> *newn = new DoublyLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next        = this->first;
        this->first->prev = newn;
        this->first       = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertLast
//  Input:             Data of new node
//  Description:       Inserts a node at the last position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLnode<T> *newn = new DoublyLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        DoublyLLnode<T> *temp = this->first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next  = newn;
        newn->prev  = temp;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertAtPos
//  Input:             Data of new node, Position (1-based)
//  Description:       Inserts a node at the specified position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > this->iCount + 1)
    {
        cout << "Position is Invalid\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == this->iCount + 1)
        InsertLast(no);
    else
    {
        DoublyLLnode<T> *newn = new DoublyLLnode<T>(no);
        DoublyLLnode<T> *temp = this->first;

        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
            temp = temp->next;

        newn->next        = temp->next;
        temp->next->prev  = newn;
        temp->next        = newn;
        newn->prev        = temp;
        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteFirst
//  Description:       Deletes the node at the first position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(this->first == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    if(this->first->next == NULL)   // Only one node
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first       = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteLast
//  Description:       Deletes the node at the last position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    if(this->first == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    if(this->first->next == NULL)   // Only one node
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        DoublyLLnode<T> *temp = this->first;
        while(temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteAtPos
//  Input:             Position (1-based)
//  Description:       Deletes the node at the specified position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this->iCount)
    {
        cout << "Position is Invalid\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == this->iCount)
        DeleteLast();
    else
    {
        DoublyLLnode<T> *temp = this->first;
        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
            temp = temp->next;

        DoublyLLnode<T> *target = temp->next;
        temp->next        = target->next;
        target->next->prev = temp;
        delete target;
        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Display
//  Description:       Prints all nodes from first to last (bidirectional format)
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLnode<T> *temp = this->first;
    cout << "\nNULL<=>";
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Count
//  Output:            Number of nodes in the list
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}
