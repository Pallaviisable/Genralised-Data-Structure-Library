////////////////////////////////////////////////////////////////////////////////////
//
//  File:              SinglyLL.tpp
//  Description:       Template definitions for Singly Linear Linked List
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by SinglyLL.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// SinglyLLLnode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLLLnode<T>::SinglyLLLnode(T no)
{
    this->data = no;
    this->next = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     SinglyLLL (Constructor)
//  Description:       Initialises first pointer to NULL and count to 0
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Object of SinglyLLL gets created.\n";
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
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = new SinglyLLLnode<T>(no);
    newn->next   = this->first;
    this->first  = newn;
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
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = new SinglyLLLnode<T>(no);
    SinglyLLLnode<T> *temp = NULL;

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
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
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        SinglyLLLnode<T> *newn = new SinglyLLLnode<T>(no);
        SinglyLLLnode<T> *temp = this->first;

        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
            temp = temp->next;

        newn->next  = temp->next;
        temp->next  = newn;
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
void SinglyLLL<T>::DeleteFirst()
{
    if(this->first == NULL)
        return;

    SinglyLLLnode<T> *temp = this->first;

    if(this->first->next == NULL)   // Only one node
    {
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
    }

    delete temp;
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     DeleteLast
//  Description:       Deletes the node at the last position
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if(this->first == NULL)
        return;

    if(this->first->next == NULL)   // Only one node
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        SinglyLLLnode<T> *temp = this->first;
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
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        SinglyLLLnode<T> *temp = this->first;
        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
            temp = temp->next;

        SinglyLLLnode<T> *target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Display
//  Description:       Prints all nodes from first to last
//
/////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = this->first;
    for(int iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "|" << temp->data << "|->";
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
int SinglyLLL<T>::Count()
{
    return this->iCount;
}
