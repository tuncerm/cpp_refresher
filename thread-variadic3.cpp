#include <iostream>
#include <thread>

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }

private:
    int _id;
};

int main()
{
    // create thread
    std::shared_ptr<Vehicle> v0(new Vehicle);
    Vehicle v1, v2;
    std::thread t0 = std::thread(&Vehicle::addID, v0, 3);
    std::thread t1 = std::thread(&Vehicle::addID, v1, 1); // call member function on object v
    std::thread t2 = std::thread(&Vehicle::addID, &v2, 2); // call member function on object v

    // wait for thread to finish
    t0.join();
    t1.join();
    t2.join();

    // print Vehicle id
    v0->printID();  // shared pointer.
    v1.printID();
    v2.printID();

    return 0;
}