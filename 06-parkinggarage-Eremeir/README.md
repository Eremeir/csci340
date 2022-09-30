### CSCI 340 - Data Structures and Algorithm Analysis

**Data Structure:** Stack, Deque <BR>
**Programming Focus:** STL Stack, STL Deque

# Parking Garage

The _Scratchemup Parking Garage_ contains a single lane that holds up to ten cars. 
Cars arrive at the south end of the garage and leave from the north end. 
If a customer arrives to pick up a car that is not the northernmost, all cars to 
the north of the car moved out, the car is driven out, and the other cars are restored in the same original order.

Write a program in C++ (**parking.cc**) that reads a group of input lines. 
Each line contains an **A** for **arrival** or a **D** for **departure**, which is 
terminated by a **:**, and a **license plate number**, which is terminated by a **:**. 
The program should print a message each time a car arrives or departs. When a car arrives, 
the message should specify when the garage is full. If there is no room for a car, the 
car simply leaves. When a car departs, the message should include the number of times the 
car was moved within the garage, including the departure itself but not the arrival.

When a car arrives when the garage is not full, create an instance of the **car** class 
that contains an `id number` (*starts with 1*), the `license plate number`, and the 
`number of times the car was moved` within the garage (*with initial value 0*), and insert 
this object into an **STL deque** container. 

For a departure, you need to check if the car is in the garage. If it's not, print an error 
message and ignore the departure.  If it **is** in the garage then delete the corresponding 
`car` object from the deque while retaining the same order of all the other cars.

To save the original ordering of the cars that are moved out from the deque to open the way 
for a departing car, define a **STL stack** container to temporarily put the moved cars in 
the stack, and after the departing car is removed, retrieve all cars from the stack and put 
them back into the deque into their original positions.

**Programming Notes:**

- Write a `main()` to read the transaction records from `stdin`, parse them by calling
`get_input_vals()`, and process an arrival or departure based on the value of the
transaction code by calling the appropriate method on a `garage` object 
(that should be a variable in your `main()`.)  

- `void get_input_vals(const std::string &line, char &xact_type, std::string &license)`\
This is a helper function that extracts the individual components from the input line line, 
where `act` indicates if the line corresponds to *an arrival* or *a departure* event, and `license` 
is the *license plate number* of the arriving/departing car.  Put this in the `parking.cc` file
along with `main()`.

For hints on parsing strings, consider the ideas in this [Stack Overflow Article](https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c)

- To keep all necessary information for a car, define a class:

```c++
class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the number of times the car has been moved.
    void move();

    /// @return the number of times that the car has been moved.
    int get_num_moves() const;
	
    /// @return A reference to the license for this car.
    const std::string &get_license() const;

    /**
    * Overload the << so this can print itself as:
    *    Car X with license plate "Y"
    ******************************************************************/
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs);

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};
```

To manage the garage's parking lot, create a `garage` class:

```c++
class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.                                                           
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.                                                          
        void departure(const std::string &license);

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};
```

- void garage::arrival(const std::string &license)\
Create a `car` object and use it to print itself as part of a message announcing its arrival.
If the garage is already full of cars (as defined by `parking_lot_limit`) then print
a message so indicating that fact (see the reference output.)
If the garage is **not** already full then add the car to the `parking_lot` deque.

- void garage::departure(const std::string &license)\
Check each of the `car` elements in the `parking_lot` deque to see if any of them
have the given `license`.  If no such car is found then print a message stating that
"the garage is full" (see the reference output for specific formatting.)  
Otherwise (the `car` has been found), move the `car` elements that are in the way 
(that are closer to the exit) one at-a-time out of the deque and into a `std::stack<car>` 
(increasing the number of times each have been moved along the way) and then:
    - Remove the car with the given `license` from the `parking_lot` deque
    - Print the removed car's information and the fact that it has departed and the 
number of times it has been moved (plus 1 for the departure!... see reference output for formatting.)
	- Move all the cars in the stack back into the deque so that they remain in the same
order that they were before.

- Create a Makefile that builds an executable **parking**. To test your program, execute your program as `./parking < parking.in`.

- Save the output from your program into a file named **parking.out** and add it to your repository.

- You can find the correct output of this program in the file **parking.refout** in your repository. You can compare two output files by executing `diff parking.refout parking.out`.

**Assignment Notes:**

- Include any necessary headers.

- You are not allowed to use any I/O functions from the C library, such as `scanf` or `printf`. 
Instead, use the I/O functions from the C++ library, such as `cin` or `cout`.

- Do **not** use the `erase()` member function on the `deque` object.

- Do not create any global constants.

- Add documentation to the appropriate source files as discussed in your class.

- Prepare your Makefile (you need to construct and add Makefile) so that the TA only needs to 
invoke the command make to compile your source file and produce the executable file **parking**. 
Make sure you use exactly the same file names specified here, i.e. **parking.cc** and **parking**, 
in your Makefile, otherwise your **submission will get 0 points**.

When your program is ready for grading, ***commit*** and ***push*** your local repository to 
remote git classroom repository and follow the _**Assignment Submission Instructions**_.
