////////////////////////////////////////////////////////////////////////////////////
//
//  File:              DoublyCLL.tpp
//  Description:       Template definitions for Doubly Circular Linked List
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by DoublyCLL.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// DoublyCLLnode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLLnode<T>::DoublyCLLnode(T no)
{
    this->data = no;
    this->next = NULL;
    this->prev = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DOUBLYCLL (Constructor)
//  Description:       Initialises first/last to NULL and count to 0
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
DOUBLYCLL<T>::DOUBLYCLL()
{
    cout << "Object of DOUBLYCLL gets created.\n";
    this->first  = NULL;
    this->last   = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertFirst
//  Input:             Data of new node
//  Description:       Inserts a node at the first position, maintains circular links
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DOUBLYCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   // Empty list
    {
        this->first = newn;
        this->last  = newn;
    }
    else
    {
        newn->next        = this->first;
        this->first->prev = newn;
        this->first       = newn;
        this->last->next  = this->first;    // Maintain circular link
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertLast
//  Input:             Data of new node
//  Description:       Inserts a node at the last position, maintains circular links
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DOUBLYCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   // Empty list
    {
        this->first = newn;
        this->last  = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev       = this->last;
        this->last       = newn;
    }

    // Maintain circular links
    this->last->next  = this->first;
    this->first->prev = this->last;
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
void DOUBLYCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount + 1)
        InsertLast(no);
    else
    {
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);
        DoublyCLLnode<T> *temp = this->first;

        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
            temp = temp->next;

        newn->next       = temp->next;
        newn->next->prev = newn;
        temp->next       = newn;
        newn->prev       = temp;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteFirst
//  Description:       Deletes the first node, maintains circular links
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DOUBLYCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)   // Empty list
        return;

    if(this->first == this->last)   // Only one node
    {
        delete this->first;
        this->first = NULL;
        this->last  = NULL;
    }
    else
    {
        this->first       = this->first->next;
        delete this->first->prev;

        // Maintain circular links
        this->last->next  = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteLast
//  Description:       Deletes the last node, maintains circular links
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DOUBLYCLL<T>::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)   // Empty list
        return;

    if(this->first == this->last)   // Only one node
    {
        delete this->first;
        this->first = NULL;
        this->last  = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        // Maintain circular links
        this->last->next  = this->first;
        this->first->prev = this->last;
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
void DOUBLYCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        DoublyCLLnode<T> *temp = first;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        DoublyCLLnode<T> *target = temp->next;
        temp->next        = target->next;
        target->next->prev = temp;
        delete target;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Display
//  Description:       Prints all nodes traversing the circular list once
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void DOUBLYCLL<T>::Display()
{
    if(first == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    DoublyCLLnode<T> *temp = first;
    cout << " <=> ";
    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    } while(temp != first);
    cout << "\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Count
//  Output:            Number of nodes in the list
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
int DOUBLYCLL<T>::Count()
{
    return this->iCount;
}
