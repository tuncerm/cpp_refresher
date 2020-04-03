#include <assert.h>
#include <string>
#include <iostream>

class Animal {
public:
    virtual std::string Talk() const = 0;
};

// TODO: Declare a class Dog that inherits from Animal
class Dog : Animal{
public:
    std::string Talk() const {
        return "Woof";
    }
};

class Cat { // Here, Cat does not derive from a base class
public:
    std::string Talk() const { return std::string("Meow"); }
};

class Lion : public Cat {
public:
    std::string Talk() const { return std::string("Roar"); } // Hides parent Talk
};

int main() {
    Dog dog;
    assert(dog.Talk() == "Woof");

    Lion leo;
    std::cout << leo.Talk() << "\n";
}