#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "btree.h"

/*
Matt Borek (z1951125)
Assignment 09
04/11/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Binary Search Tree Template Class
 * 
 * Class to facilitate creating and using a binary search tree of nodes.
 * 
 * @tparam T for templatized input allowing multiple data types.
 */
template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    ~BinarySearchTree();           //Destructor
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

/**
 * @brief Deconstruct the binary search tree.
 * 
 * Call recursive deletion on the binary search tree and its nodes.
 * 
 * @tparam T for templatized input allowing multiple data types.
 */
template <typename T> 
BinarySearchTree<T>::~BinarySearchTree()
{
    delete this->root; //Delete the root node, which will call the node destructor.
}

/**
 * @brief Insert public method.
 * 
 * Call the insert private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param x Value to be inserted to the tree. 
 */
template <typename T>
void BinarySearchTree<T>::Insert(const T &x)
{
    _Insert(this->root, x);
}

/**
 * @brief Search public method.
 * 
 * Call the Search private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param x Value to be searched for within the tree. 
 * @return Returns true if the search private method returns true.
 * @return Returns false if the search private method returns false.
 */
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const
{
    return _Search(this->root, x);
}

/**
 * @brief Remove public method.
 * 
 * Call the search public method, if it returns true, call the remove private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param x Value to be removed from the tree. 
 * @return Returns true if the search public method returns true.
 * @return Returns false if the search public method returns false.
 */
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    if(Search(x) == true) //If the value is a leaf node and is contained in the tree.
    {
        _Remove(this->root, x); //Remove the value from the tree.
        return true;
    }
    else //The value was not a leaf node or was not contained in the tree.
    {
        return false;
    }
}

/**
 * @brief Insert a node into the tree.
 * 
 * Insert a node into the tree by traversing the tree and comparing datavalues until the correct spot is located.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary search tree node the method will act on.
 * @param value Value to be added to the tree. 
 */
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &value)
{
    if(node != NULL) //If the current node is not empty.
    {
        if(node->data > value)
        {
            _Insert(node->left, value); //If the insertion value is less than the node's value, call insertion recusively to the left.
        }
        else if(node->data < value)
        {   
            _Insert(node->right, value); //If the insertion value is more than the node's value, call insertion recusively to the right.
        }
    }
    else //If the current node is empty.
    {
        node = new Node<T>(value); //Create a new node.
    }
}

/**
 * @brief Search the tree for a node.
 * 
 * Call the _Leaf() function to check whether a node is a leaf and the key value. If not found, look to the left and right of the node.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary search tree node the method will act on.
 * @param value Value to be searched for within the tree.
 * @return Returns true if the node has been found in the tree and is a leaf node.
 * @return Returns false if the node has not been found in the tree or is not a leaf node.
 */
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T &value) const
{
    if(node != NULL) //If the current node is not empty.
    {
        if(_Leaf(node) && node->data == value) //Test if the node is a leaf and the key value.
        {
            return true;
        }
        else
        {
            if(node->data > value)
            {
                return _Search(node->left, value); //If the search value is less than the node's value, call search recusively to the left.
            }
            else
            {   
                return _Search(node->right, value); //If the search value is more than the node's value, call search recusively to the right.
            }
        }
    }
    else //The node is empty, and the value cannot be found.
    {
        return false;
    }
}

/**
 * @brief Remove a node from the tree.
 * 
 * Check if the node is a leaf node and the correct key value, if so, delete the node. Otherwise, check to the left and right of the node
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary search tree node the method will act on.
 * @param value Value to be removed from the tree.
 */
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &value)
{
   if(_Leaf(node) && node->data == value) //Test if the node is a leaf and the key value.
   {
       delete node;
       node = NULL; //Update pointers to forget this node.
   }
   else //The current node is not the intended node, another nodes must be checked.
   {
       if(node->data > value) 
            {
                _Remove(node->left, value); //If the search value is less than the node's value, call search recusively to the left.
            }
            else
            {   
                _Remove(node->right, value); //If the search value is more than the node's value, call search recusively to the right.
            }
   }
}

/**
 * @brief Test if a node is a leaf node.
 * 
 * Check if the node is a leaf node by testing for valid children.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary search tree node the method will act on.
 * @return Returns true if the node does not have a valid left or right pointer.
 * @return Returns false if the node does have a valid left or right pointer.
 */
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
    if(node->left == NULL && node->right == NULL) //If both the left and right pointers are NULL.
    {
        return true;
    }
    else //The left or right pointer exists and a child node exists.
    {
        return false;
    }
}

#endif // End of BINARYSEARCHTREE_H_
