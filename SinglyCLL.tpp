////////////////////////////////////////////////////////////////////////////////////
//
//  File:              SinglyCLL.tpp
//  Description:       Template definitions for Singly Circular Linked List
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by SinglyCLL.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// SinglyCLLnode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLLnode<T>::SinglyCLLnode(T no)
{
    this->data = no;
    this->next = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     SinglyCLL (Constructor)
//  Description:       Initialises first/last to NULL and count to 0
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout << "Object of SinglyCLL gets created.\n";
    this->first  = NULL;
    this->last   = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertFirst
//  Input:             Data of new node
//  Description:       Inserts a node at the first position, maintains circular link
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL || this->last == NULL)   // Empty list
    {
        this->first = newn;
        this->last  = newn;
    }
    else
    {
        newn->next  = this->first;
        this->first = newn;
    }
    this->last->next = this->first;     // Maintain circular link
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertLast
//  Input:             Data of new node
//  Description:       Inserts a node at the last position, maintains circular link
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   // Empty list
    {
        this->first = newn;
        this->last  = newn;
    }
    else
    {
        this->last->next = newn;
        this->last       = newn;
    }
    this->last->next = this->first;     // Maintain circular link
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
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount + 1)
        InsertLast(no);
    else
    {
        SinglyCLLnode<T> *newn = new SinglyCLLnode<T>(no);
        SinglyCLLnode<T> *temp = first;

        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next  = temp->next;
        temp->next  = newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteFirst
//  Description:       Deletes the first node, maintains circular link
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout << "Linked List is Empty\n";
        return;
    }

    if(this->first == this->last)       // Only one node
    {
        free(this->first);
        this->first = NULL;
        this->last  = NULL;
    }
    else
    {
        SinglyCLLnode<T> *temp = this->first;
        this->first      = this->first->next;
        this->last->next = this->first;     // Maintain circular link
        free(temp);
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteLast
//  Description:       Deletes the last node, maintains circular link
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout << "Linked List is Empty\n";
        return;
    }

    if(this->first == this->last)       // Only one node
    {
        free(this->first);
        this->first = NULL;
        this->last  = NULL;
    }
    else
    {
        SinglyCLLnode<T> *temp = this->first;
        while(temp->next != this->last)
            temp = temp->next;

        free(this->last);
        this->last       = temp;
        this->last->next = this->first;     // Maintain circular link
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
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        SinglyCLLnode<T> *temp = first;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        SinglyCLLnode<T> *target = temp->next;
        temp->next = target->next;
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
void SinglyCLL<T>::Display()
{
    if(first == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    SinglyCLLnode<T> *temp = first;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while(temp != first);
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Count
//  Output:            Number of nodes in the list
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}
