#ifndef NODE_H_
#define NODE_H_

/*
Matt Borek (z1951125)
Assignment 09
04/11/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

// definition of node in bin tree

template <typename T>
class BinaryTree;  // forward declaration

template <typename T>
class BinarySearchTree;  // forward declaration

/**
* @brief Node Template Class
* 
* Facilitates a node that can hold templatized data and point to two other nodes.
* 
* @tparam T for templatized input allowing multiple data types.
*/
template <typename T>
class Node {
    friend class BinaryTree<T>;   // binTree is friend
    friend class BinarySearchTree<T>;  // binSTree is friend

public:
    Node(const T& = T(), Node<T>* = nullptr,
    Node<T>* = nullptr);  // default constructor
    ~Node(); //destructor

private:
    T				data;  // data component
    Node<T>*left, *right;  // left and right links
};

/**
* @brief Construct a new Node object.
* 
* Create a new node with supplied or default values.
* 
* @tparam T for templatized input allowing multiple data types.
* @param x Data value for the node.
* @param l Pointer to left node.
* @param r Pointer to right node.
*/
template <typename T>
Node<T>::Node(const T& x, Node<T>* l, Node<T>* r) : data(x), left(l), right(r) {}

/**
* @brief Destroy the Node object.
* 
* Delete a node and each child node, freeing up memory.
* 
* @tparam T for templatized input allowing multiple data types.
*/
template <typename T>
Node<T>::~Node()
{
    delete right; //Delete the left node, calling its destructor.
    delete left; //Delete the right node, calling its destructor.
}

#endif  // End of NODE_H_
