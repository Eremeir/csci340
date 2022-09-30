#ifndef H_BTREE
#define H_BTREE

#include <algorithm>
#include "node.h"

/*
Matt Borek (z1951125)
Assignment 08
04/7/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Typedef enumeration SIDE
 * 
 * Randomly picks between left_side and right_side, returning one.
 * 
 */
typedef enum {left_side, right_side } SIDE;

SIDE rnd(){ 
    return rand()%2 ? right_side : left_side;
}// End of rnd()

/**
 * @brief Binary Tree Template Class
 * 
 * Class to facilitate creating and using a binary tree of nodes.
 * 
 * @tparam T for templatized input allowing multiple data types.
 */
template <typename T> class BinaryTree
{
public:
    BinaryTree();                                      // default constructor
    ~BinaryTree();                                     // deconstructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

/**
 * @brief Construct a new Binary Tree object.
 * 
 * Create a new templatized binary tree and set root to NULL.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 */
template <typename T> 
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

/**
 * @brief Deconstruct the binary tree.
 * 
 * Call recursive deletion.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 */
template <typename T> 
BinaryTree<T>::~BinaryTree()
{
    delete root; //Telete the root node, which will call the node destructor.
}

/**
 * @brief Get Size public method.
 * 
 * Call the Get Size private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @return unsigned integer for the total number of nodes in the tree. 
 */
template <typename T> 
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

/**
 * @brief Get Height public method.
 * 
 * Call the Get Height private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @return unsigned integer of the max height of any subtree.
 */
template <typename T> 
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);
}

/**
 * @brief Insert private method.
 * 
 * Call the Insert private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param value Value to be inserted.
 */
template <typename T> 
void BinaryTree<T>::Insert(const T &value)
{
    _Insert(root, value);
}

/**
 * @brief Inorder public method.
 * 
 * Call the Inorder private method.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param function Function to be passed in for execution.
 */
template <typename T> 
void BinaryTree<T>::Inorder(void (*function)(const T &value))
{
    _Inorder(root, function);
}

/**
 * @brief Get Size private method
 * 
 * Checks the left and right subtrees and counts the total number of nodes in the tree.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary tree node the method will act on.
 * @return unsigned integer for the total size of the tree.
 */
template <typename T> 
unsigned BinaryTree<T>::_getSize(Node<T> *node) const
{
    if(node != NULL) //If the current node is not empty.
    {
        return(_getSize(node->left) + _getSize(node->right)) + 1; //Return the sum of the recusrion of the left and right subtrees plus 1 for the root.
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Get Height private method
 * 
 * Checks the left and right subtrees and counts up the maximum height of any subtree.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary tree node the method will act on.
 * @return unsigned integer for the max height of any subtree.
 */
template <typename T> 
unsigned BinaryTree<T>::_getHeight(Node<T> *node) const
{
    if(node != NULL) //If the current node is not empty.
    {
        return max(_getHeight(node->left), _getHeight(node->right)) + 1; //Return the maximum value between the recursion of height checks on the left and right subtrees
    }                                                                    // plus 1 for height specifications.
    else
    {
        return 0; //If the node is empty, this node does not count for height.
    }
}

/**
 * @brief Insert private method
 * 
 * Randomly selects a side to insert new nodes to and adds them to the tree.
 * 
 * @tparam T for templatized input allowing multiple data types. 
 * @param node Current binary tree node the method will act on.
 * @param value Value to be inserted to the tree.
 */
template <typename T> 
void BinaryTree<T>::_Insert(Node<T> *&node, const T &value)
{
    if(node != NULL) //If the current node is not empty.
    {
        SIDE insertSide = rnd(); //Randomly select a side.
        if(insertSide == left_side)
        {
            _Insert(node->left, value); //If the side selected is left, call insert recursively to the left.
        }
        else if(insertSide == right_side)
        {   
            _Insert(node->right, value); //If the side selected is right, call insert recursively to the right.
        }
    }
    else //If the current node is empty.
    {
        node = new Node<T>(value); //Create a new node.
    }
}

/**
 * @brief Iorder private method
 * 
 * Executes a passeed in function in inorder traversal through the binary tree.
 * 
 * @tparam T for templatized input allowing multiple data types.
 * @param node Current binary tree node the method will act on.
 * @param function Passed in function to be executed.
 */
template <typename T> 
void BinaryTree<T>::_Inorder(Node<T> *node, void (*function)(const T &value))
{
    if(node != NULL) //If the current node is not empty.
    {
        _Inorder(node-> left, function); //Recursively call this function on the node to the left.
        function(node->data); //Execute the passed in function on the current node's data.
        _Inorder(node-> right, function); //Recursively call this function on the node to the right.
    }
}

#endif // End of H_BTREE
