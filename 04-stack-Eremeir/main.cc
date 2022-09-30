#include <iostream>
#include <iomanip>
#include <string>

#include "stack.h"
#include "rational.h"


/**
* Create a stack and test the push(), pop(), empty(), 
* and size() members.
*
* This will read operations from stdin until either a the 
* token 'END' is read or EOF is encountered.
***************************************************************************/
template<typename T>
int test()
{
    T val;
    Stack<T> s;

    std::string op;

	std::cout << " operation   size    top" << std::endl;
	std::cout << "------------ ---- -------" << std::endl;

    while (std::cin >> op)
    {
        if (op == "push")
        {
            std::cin >> val;
            s.push(val);
            std::cout << std::setw(5) << op << std::setw(6) << val << "  ";
        }
        else if (op == "pop")
        {
            s.pop();
            std::cout << std::setw(5) << op << std::setw(6) << " " << "  ";
        }
		else if (op == "END")
		{
            std::cout << op << std::endl;
			break;
		}
        else
        {
            std::cerr << "Error input: " << op << std::endl;
            return 1;
        }
        std::cout << std::setw(4) << s.size() << std::setw(8) << s.top() << std::endl;
    }
    std::cout << "End   -- size of Stack is: " << s.size() << std::endl;

    while (!s.empty())
        s.pop();

    std::cout << "Empty -- size of Stack is: " << s.size() << std::endl;

    return 0;
}

/**
* Test Stack<int> and Stack<Rational>
* @return 0
***************************************************************************/
int main()
{
	std::cout << "**** testing Stack<int> *************************************" << std::endl;
	test<int>();

	std::cout << std::endl << "**** testing Stack<Rational> ********************************" << std::endl;
	test<Rational>();

	return 0;
}
