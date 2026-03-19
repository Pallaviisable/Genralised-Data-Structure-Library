////////////////////////////////////////////////////////////////////////////////////
//
//  File:              ArrayX.tpp
//  Description:       Template definitions for Generic Array with Sorting
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by ArrayX.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     ArrayX (Constructor)
//  Input:             Size of array
//  Description:       Allocates array of given size; assumes input will be sorted
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
ArrayX<T>::ArrayX(int no)
{
    cout << "Inside Constructor\n";
    iSize  = no;
    Arr    = new T[iSize];
    Sorted = true;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     ~ArrayX (Destructor)
//  Description:       Releases dynamically allocated array memory
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
ArrayX<T>::~ArrayX()
{
    cout << "Inside destructor\n";
    delete[] Arr;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Accept
//  Description:       Reads iSize elements from stdin; sets Sorted = false if
//                     any adjacent pair is out of ascending order
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::Accept()
{
    cout << "Enter the Elements\n";
    cin >> Arr[0];
    for(int iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];
        if(Arr[iCnt - 1] > Arr[iCnt])
            Sorted = false;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Display
//  Description:       Prints all array elements separated by tabs
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::Display()
{
    cout << "Elements of Array are:\n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
        cout << Arr[iCnt] << "\t";
    cout << "\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     CheckSorted
//  Output:            true if array is in ascending order, false otherwise
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ArrayX<T>::CheckSorted()
{
    for(int iCnt = 0; iCnt < iSize - 1; iCnt++)
    {
        if(Arr[iCnt] > Arr[iCnt + 1])
            return false;
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     bubbleSort
//  Description:       Standard Bubble Sort (ascending). Skips if already sorted.
//                     Prints array state after each pass.
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::bubbleSort()
{
    if(Sorted == true)
        return;

    int Pass = 0, Time = 1;
    T   temp;

    for(int i = 0; i < iSize - 1; i++, Pass++)
    {
        for(int j = 0; j < iSize - 1 - i; j++, Time++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp       = Arr[j];
                Arr[j]     = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
        cout << "\n\nData after pass : " << i + 1 << "\n\n";
        Display();
    }

    cout << "Number of passes for bubble sort : " << Pass << "\n";
    cout << "Total number of iterations : "       << Time << "\n";
    Sorted = true;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     bubbleSortEfficient
//  Description:       Bubble Sort with early-exit flag. Stops when no swap
//                     occurs in a pass (array already sorted). Prints each pass.
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::bubbleSortEfficient()
{
    T    temp;
    bool bFlag = true;
    int  i;

    for(i = 0; (i < iSize - 1) && bFlag; i++)
    {
        bFlag = false;
        for(int j = 0; j < iSize - 1 - i; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp       = Arr[j];
                Arr[j]     = Arr[j + 1];
                Arr[j + 1] = temp;
                bFlag      = true;
            }
        }
        cout << "\n\nData after pass : " << i + 1 << "\n\n";
        Display();
    }

    cout << "Number of passes for bubble sort : " << i << "\n";
    Sorted = true;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     bubbleSortEfficientX
//  Input:             iOption — INC_ORDER (1) for ascending, DEC_ORDER (2) for descending
//  Description:       Efficient Bubble Sort with direction control and early exit.
//                     Prints array after each pass.
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::bubbleSortEfficientX(int iOption)
{
    if(iOption < INC_ORDER || iOption > DEC_ORDER)
    {
        cout << "Invalid Option for Sorting\n1:Increasing\n2:Decreasing\n";
        return;
    }

    T    temp;
    bool bFlag = true;
    int  i;

    for(i = 0; (i < iSize - 1) && bFlag; i++)
    {
        bFlag = false;
        for(int j = 0; j < iSize - 1 - i; j++)
        {
            bool shouldSwap = (iOption == INC_ORDER) ? (Arr[j] > Arr[j + 1])
                                                     : (Arr[j] < Arr[j + 1]);
            if(shouldSwap)
            {
                temp       = Arr[j];
                Arr[j]     = Arr[j + 1];
                Arr[j + 1] = temp;
                bFlag      = true;
            }
        }
        cout << "\n\nData after pass : " << i + 1 << "\n\n";
        Display();
    }

    cout << "Number of passes for bubble sort : " << i << "\n";
    Sorted = true;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     SelectionSort
//  Description:       Sorts array ascending by repeatedly finding the minimum
//                     element and placing it at the current position
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::SelectionSort()
{
    T temp;
    for(int i = 0; i < iSize - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
                min_index = j;
        }
        if(i != min_index)
        {
            temp             = Arr[i];
            Arr[i]           = Arr[min_index];
            Arr[min_index]   = temp;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     InsertionSort
//  Description:       Sorts array ascending by picking each element and
//                     inserting it at its correct position in the sorted prefix
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>::InsertionSort()
{
    T   selected;
    int j;

    for(int i = 1; i < iSize; i++)
    {
        selected = Arr[i];
        for(j = i - 1; j >= 0 && Arr[j] > selected; j--)
            Arr[j + 1] = Arr[j];
        Arr[j + 1] = selected;
    }
}
