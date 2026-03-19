////////////////////////////////////////////////////////////////////////////////////
//
//  File:              BST.tpp
//  Description:       Template definitions for Generic Binary Search Tree
//  Author:            Pallavi Sable
//  Date:              06/01/2026
//
//  Note:              Included directly by BST.h — do not compile separately
//
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// BSTNode Constructor
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
BSTNode<T>::BSTNode(T value)
{
    data   = value;
    lchild = nullptr;
    rchild = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////
// BST Constructor
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
BST<T>::BST()
{
    root = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Insert (private recursive helper)
//  Input:             Reference to current node, value to insert
//  Description:       Recursively finds correct position and inserts new node
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BST<T>::Insert(BSTNode<T>* &node, T value)
{
    if(node == nullptr)
    {
        node = new BSTNode<T>(value);
        return;
    }
    if(value < node->data)
        Insert(node->lchild, value);
    else if(value > node->data)
        Insert(node->rchild, value);
    else
        cout << "Unable to insert " << value << ", already present\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Inorder (private recursive helper)
//  Description:       Left -> Root -> Right traversal
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BST<T>::Inorder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        Inorder(node->lchild);
        cout << node->data << " ";
        Inorder(node->rchild);
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Preorder (private recursive helper)
//  Description:       Root -> Left -> Right traversal
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BST<T>::Preorder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        cout << node->data << " ";
        Preorder(node->lchild);
        Preorder(node->rchild);
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Postorder (private recursive helper)
//  Description:       Left -> Right -> Root traversal
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BST<T>::Postorder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        Postorder(node->lchild);
        Postorder(node->rchild);
        cout << node->data << " ";
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     Search (private recursive helper)
//  Output:            true if value found, false otherwise
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool BST<T>::Search(BSTNode<T>* node, T value)
{
    if(node == nullptr) return false;
    if(value < node->data)  return Search(node->lchild, value);
    if(value > node->data)  return Search(node->rchild, value);
    return true;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     CountNodes (private recursive helper)
//  Output:            Total number of nodes in the subtree
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BST<T>::CountNodes(BSTNode<T>* node)
{
    if(node == nullptr) return 0;
    return 1 + CountNodes(node->lchild) + CountNodes(node->rchild);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     CountParents (private recursive helper)
//  Output:            Number of internal (non-leaf) nodes in the subtree
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BST<T>::CountParents(BSTNode<T>* node)
{
    if(node == nullptr) return 0;
    int count = (node->lchild != nullptr || node->rchild != nullptr) ? 1 : 0;
    return count + CountParents(node->lchild) + CountParents(node->rchild);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:     CountLeafs (private recursive helper)
//  Output:            Number of leaf nodes in the subtree
//
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BST<T>::CountLeafs(BSTNode<T>* node)
{
    if(node == nullptr) return 0;
    if(node->lchild == nullptr && node->rchild == nullptr) return 1;
    return CountLeafs(node->lchild) + CountLeafs(node->rchild);
}

// Public interface wrappers
template <typename T> void BST<T>::Insert(T value)   { Insert(root, value); }
template <typename T> void BST<T>::Inorder()         { Inorder(root);   cout << "\n"; }
template <typename T> void BST<T>::Preorder()        { Preorder(root);  cout << "\n"; }
template <typename T> void BST<T>::Postorder()       { Postorder(root); cout << "\n"; }
template <typename T> bool BST<T>::Search(T value)   { return Search(root, value); }
template <typename T> int  BST<T>::CountNodes()      { return CountNodes(root); }
template <typename T> int  BST<T>::CountParents()    { return CountParents(root); }
template <typename T> int  BST<T>::CountLeafs()      { return CountLeafs(root); }
