### CSCI 340 - Data Structures and Algorithm Analysis

**Data Structure:** Stack <BR>
**Programming Focus:** Templates, STL, Queue

# Stack

For this computer assignment, you are to complete a Stack template class using STL queues. 
All relevant files are located within this GitHub repository. 

*stack.h* contains a declaration of the Stack class. 
It is given here to facilitate the following description:

```c++
template<typename T>
class Stack
{
private:
    std::queue<T> q1;   // These queues are where the stack's elements 
    std::queue<T> q2;   // are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};
```
You are required to implement the member functions of the `Stack` class. Recall that *template* member function definitions go in the `.h` file along with the class declaration.
A main function is already provided in *main.cc* and does not need to be modified, you can test your program with *stack.in* and check that it matches *stack.out*.

In the implementation of the class, you must use queues `q1` and `q2` to store the elements in your stack.
It is suggested to keep all elements in either one of the queues and use the other queue for temporary storage.
    
The member functions of the `Stack` template class must perform the following operations:
    
* `empty()` Returns true if the stack has no elements in it.  

* `size()` Returns the number of elements in the stack.

* `top()` This method returns a reference to the newest element. 

* `push()` Add the element to your stack.

* `pop()` This method removes the newest element. 

**Programming Notes:**

Specific tasks, function prototypes, assignment specific components
  
- Note that you are implementing the methods for the `Stack` template class, creating a `Makefile` and,
if necessary, a `.gitignore` file.  Template methods belong in the `.h` file.  *Do not* create a `stack.cc` file!

- Prepare your Makefile (you need to create and add `Makefile` to your repo) so that the TA only needs to invoke the command `make` to compile your source file and produce the executable file `stack`. You must use exactly the same file names specified here, i.e. `stack`, in your `Makefile`, otherwise your **submission will get 0 points**.

- Don't forget to create a proper `.gitignore` file that lists any *generated* files (from `make`) that should not be added to your repo!

- Note that an implementation of a solution to a *similar problem* (that might provide some useful hints) can be found
here: (https://www.geeksforgeeks.org/implement-stack-using-queue/)

- Note that the `Rational` class is has been copied from the handouts for CSCI 241/501.  
It is included here to be used for testing your `Stack` template class and requires no alterations.
See (http://faculty.cs.niu.edu/~winans/CS501/#operator_overloading) for more information.

**Assignment Notes:**

- Include any necessary headers and add necessary global constants.

- You are not allowed to use any I/O functions from the C library, such as scanf or printf. Instead, use the I/O functions from the C++ library, such as cin or cout.

- Add documentation to the appropriate source files as discussed in your class.

When your program is ready for grading, ***commit*** and ***push*** your local repository to remote git classroom repository and follow the _**Assignment Submission Instructions**_.
