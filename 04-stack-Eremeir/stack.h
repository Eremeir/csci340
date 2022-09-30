#ifndef STACK_H
#define STACK_H
#include <queue>

/*
    Matt Borek (z1951125)
    Assignment 04
    02/15/2022
    I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Emulated Stack data structure.
 * 
 * This class impliments an emulated version of the standard Stack data structure by using two queues, an active production queue and a temporary holding queue
 * to achieve the function of a regular stack.
 * 
 * @tparam The stack is implimented to accept multiple different datatypes through templatization.
 */
template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements 
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};

// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.

// Place your Stack class member implementations here.

/**
 * @brief Check if the emulated Stack is empty.
 * 
 * Checks if the the active production queue is empty and reports up to emulate a stack's standard .empty() function.
 * 
 * @tparam Templatized input allowing for verious datatypes.
 * 
 * @return Returns true if the active production queue is empty.
 * @return Returns false if the active production queue is not empty.
 */
template<typename T>
bool Stack<T>::empty() const
{
    if(q1.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Check the size of the emulated Stack.
 * 
 * Checks if the size of the active production queue reports up to emulate a stack's standard .size() function.
 * 
 * @tparam Templatized input allowing for verious datatypes. 
 * 
 * @return Returns the number of elements in the stack.
 */
template<typename T>
int Stack<T>::size() const
{
    return  q1.size();
}

/**
 * @brief Access the top element of the stack.
 * 
 * After checking that the active production queue is not empty, this returns a reference to the top element of the emulated stack.
 * If the stack is empty, the program will terminate to prevent undefined behavior.
 * 
 * @tparam Templatized input allowing for verious datatypes. 
 * @return Returns a constant reference to the top element of the stack, which is actually the front element of the active production queue.
 * 
 * @warning Should not be used when the stack is empty, will result in undefined behavior. This is instead coded to output to cerr and terminate the program in such a case.
 */
template<typename T>
const T& Stack<T>::top() 
{
    if(q1.size() > 0)
    {
        return q1.front();
    } 
    else
    {
        std::cerr << "Undefined behavior: requesting reference to empty stack.";
        exit (EXIT_FAILURE);
    }
}

/**
 * @brief Add a new element to the emulated stack.
 * 
 * This function is the most extensive part of the implimentation. When the stack is empty, it pushes the passed in value to the temporary holding queue, then swaps the contents
 * of the active production queue and temporary holding queue. When the stack is not empty, after pushing a value to the temporary queue, values are pushed in fron the front of
 * the production queue to the back of the temporary queue. This effectively reorders the elements so the newest element is at the front of the queue. Elements are then removed
 * from the active production queue and the conents of both queues are swapped. This is so that elements already in the stack can be properly reordered.
 * 
 * @tparam Templatized input allowing for verious datatypes. 
 * @param val Value passed in to be added as an element to the emuilated stack.
 */
template<typename T>
void Stack<T>::push(const T &val)
{
    q2.push(val);
    
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    
    std::swap(q1, q2); 
}

/**
 * @brief Remove an new element from the emulated stack.
 * 
 * This first checks if the emulated stack has any elements, then if so, removes the most recent element of the active queue which emulates the top of the emulated stack.
 * 
 * @tparam Templatized input allowing for verious datatypes.  
 */
template<typename T>
void Stack<T>::pop()
{
    if(q1.size() > 0)
    {
        q1.pop();
    }
}

#endif // STACK_H
