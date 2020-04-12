#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};


int main()
{
    // create thread
    // std::thread t0(Vehicle()); // C++'s most vexing parse
    // Which is it?
    // 1. a variable definition for variable t of class std::thread, initialized with an anonymous instance of class Vehicle or
    // 2. a function declaration for a function t that returns an object of type std::thread and has a single (unnamed) parameter that is a pointer to function returning an object of type Vehicle

    std::thread t1( (Vehicle()) ); // Add an extra pair of parantheses

    std::thread t2 = std::thread( Vehicle() ); // Use copy initialization

    std::thread t3{ Vehicle() };// Use uniform initialization with braces

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    // t0.join();
    t1.join();
    t2.join();
    t3.join();

    return 0;
}